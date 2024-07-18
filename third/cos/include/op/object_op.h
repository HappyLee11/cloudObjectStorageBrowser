// Copyright (c) 2017, Tencent Inc.
// All rights reserved.
//
// Author: sevenyou <sevenyou@tencent.com>
// Created: 07/21/17
// Description:

#ifndef OBJECT_OP_H
#define OBJECT_OP_H

#include "op/base_op.h"
#include "op/cos_result.h"
#include "request/data_process_req.h"
#include "request/object_req.h"
#include "request/auditing_req.h"
#include "response/data_process_resp.h"
#include "response/object_resp.h"
#include "response/auditing_resp.h"


namespace qcloud_cos {

class FileUploadTask;
class FileCopyTask;

/// \brief ???Object?????
class ObjectOp : public BaseOp {
 public:
  /// \brief BucketOp????
  ///
  /// \param cos_conf Cos??
  explicit ObjectOp(const SharedConfig& config) : BaseOp(config) {}
  ObjectOp() {}

  /// \brief ObjectOP????
  virtual ~ObjectOp() {}

  /// \brief ??object????
  bool IsObjectExist(const std::string& bucket_name,
                     const std::string& object_name);

  std::string GetResumableUploadID(const std::string& bucket_name,
                                   const std::string& object_name);

  bool CheckUploadPart(const PutObjectByFileReq& req,
                       const std::string& bucket_name,
                       const std::string& object_name,
                       const std::string& uploadid,
                       std::vector<std::string>& already_exist);

  bool CheckSinglePart(const PutObjectByFileReq& req, uint64_t offset,
                       uint64_t local_part_size, uint64_t size,
                       const std::string& etag);

  /// \brief ????Object?meta????
  ///
  /// \param request   HeadObject??
  /// \param response  HeadObject??
  ///
  /// \return ??HTTP???????????
  CosResult HeadObject(const HeadObjectReq& req, HeadObjectResp* resp);

  /// \brief ??Bucket?????????
  ///
  /// \param request   GetObjectByStream??
  /// \param response  GetObjectByStream??
  ///
  /// \return ??HTTP???????????
  CosResult GetObject(const GetObjectByStreamReq& req,
                      GetObjectByStreamResp* resp);

  /// \brief ??Bucket?????????
  ///
  /// \param request   GetObjectByFile??
  /// \param response  GetObjectByFile??
  ///
  /// \return ??HTTP???????????
  CosResult GetObject(const GetObjectByFileReq& req, GetObjectByFileResp* resp,
                      const SharedTransferHandler& handler = nullptr);

  /// \brief ?????Bucket?????????
  ///
  /// \param request   MultiGetObject??
  /// \param response  MultiGetObject??
  ///
  /// \return ??HTTP???????????
  CosResult MultiGetObject(const GetObjectByFileReq& req,
                          GetObjectByFileResp* resp);

  /// \brief ???????????Bucket?
  ///
  /// \param request   PutObjectByFile??
  /// \param response  PutObjectByFile??
  ///
  /// \return ??HTTP???????????
  CosResult PutObject(const PutObjectByFileReq& req, PutObjectByFileResp* resp,
                      const SharedTransferHandler& handler = nullptr);

  /// \brief ?????????Bucket?
  ///
  /// \param request   PutObjectByStream??
  /// \param response  PutObjectByStream??
  ///
  /// \return ??HTTP???????????
  CosResult PutObject(const PutObjectByStreamReq& req,
                      PutObjectByStreamResp* resp, const SharedTransferHandler& handler=nullptr);

  /// \brief ??Object
  ///
  /// \param req  DeleteObject??
  /// \param resp DeleteObject??
  ///
  /// \return ?????????(?????)
  CosResult DeleteObject(const DeleteObjectReq& req, DeleteObjectResp* resp);

  /// \brief ????Object
  ///
  /// \param req  DeleteObjects??
  /// \param resp DeleteObjects??
  ///
  /// \return ?????????(?????)
  CosResult DeleteObjects(const DeleteObjectsReq& req, DeleteObjectsResp* resp);

  /// \brief
  /// ???????????,????????????UploadId?????Upload
  /// Part??
  ///
  /// \param request   InitMultiUpload??
  /// \param response  InitMultiUpload??
  ///
  /// \return ??HTTP???????????
  CosResult InitMultiUpload(const InitMultiUploadReq& req,
                            InitMultiUploadResp* resp);

  /// \brief ??????????,????????1?10000,?????1MB?5GB
  ///
  /// \param request   UploadPartData??
  /// \param response  UploadPartData??
  ///
  /// \return ??HTTP???????????
  CosResult UploadPartData(const UploadPartDataReq& req,
                           UploadPartDataResp* resp);

  /// \brief
  /// ???????????????????????????????????
  ///        ???? x-cos-copy-source ???????x-cos-copy-source-range
  ///        ??????? ???????? 5 MB - 5 GB?
  ///
  /// \param request   UploadPartCopyData??
  /// \param response  UploadPartCopyData??
  ///
  /// \return ??HTTP???????????
  CosResult UploadPartCopyData(const UploadPartCopyDataReq& req,
                               UploadPartCopyDataResp* resp);

  /// \brief ???????????? Upload Parts ?????????
  ///        ????? API ????????????
  ///
  /// \param request   CompleteMultiUpload??
  /// \param response  CompleteMultiUpload??
  ///
  /// \return ??HTTP???????????
  CosResult CompleteMultiUpload(const CompleteMultiUploadReq& req,
                                CompleteMultiUploadResp* resp);

  /// \brief ???????
  /// \param request   MultiUploadObject??
  /// \param response  MultiUploadObject??
  /// \param handler   TransferHandler
  ///
  /// \return result
  CosResult MultiUploadObject(const PutObjectByFileReq& req,
                              MultiPutObjectResp* resp,
                              const SharedTransferHandler& handler = nullptr);

  /// \brief ????????????????
  ///
  /// \param req  AbortMultiUpload??
  /// \param resp AbortMultiUpload??
  ///
  /// \return
  CosResult AbortMultiUpload(const AbortMultiUploadReq& req,
                             AbortMultiUploadResp* resp);

  /// \brief ???????????????
  ///
  /// \param req  ListParts??
  /// \param resp ListParts??
  ///
  /// \return result
  CosResult ListParts(const ListPartsReq& req, ListPartsResp* resp);

  /// \brief ??Object??ACL
  ///
  /// \param req  GetObjectACL??
  /// \param resp GetObjectACL??
  ///
  /// \return ?????????(?????)
  CosResult GetObjectACL(const GetObjectACLReq& req, GetObjectACLResp* resp);

  /// \brief ??/??Object??ACL, ????Header??Body??ACL??
  ///        ??Header ? Body ??????????????????
  ///
  /// \param req  PutObjectACL??
  /// \param resp PutObjectACL??
  ///
  /// \return ?????????(?????)
  CosResult PutObjectACL(const PutObjectACLReq& req, PutObjectACLResp* resp);

  /// \brief ??Object
  ///
  /// \param req  PutObjectCopy??
  /// \param resp PutObjectCopy??
  ///
  /// \return ?????????(?????)
  CosResult PutObjectCopy(const PutObjectCopyReq& req, PutObjectCopyResp* resp);

  /// \brief ?????????????????????????????
  ///        ???? x-cos-copy-source ???????x-cos-copy-source-range
  ///        ???????
  ///
  /// \param request   Copy??
  /// \param response  Copy??
  ///
  /// \return ??HTTP???????????
  CosResult Copy(const CopyReq& req, CopyResp* resp);

  /// \brief ????? COS ??? archive ?????????
  ///
  /// \param request   PostObjectRestore??
  /// \param response  PostObjectRestore??
  ///
  /// \return ??HTTP???????????
  CosResult PostObjectRestore(const PostObjectRestoreReq& req,
                              PostObjectRestoreResp* resp);

  std::string GeneratePresignedUrl(const GeneratePresignedUrlReq& req);

  CosResult OptionsObject(const OptionsObjectReq& req, OptionsObjectResp* resp);

  CosResult SelectObjectContent(const SelectObjectContentReq& req,
                                SelectObjectContentResp* resp);

  CosResult AppendObject(const AppendObjectReq& req, AppendObjectResp* resp);

  /// \brief ??????
  ///
  /// \param request   PutLiveChannelReq??
  /// \param response  PutLiveChannelResp??
  ///
  /// \return ??HTTP???????????
  CosResult PutLiveChannel(const PutLiveChannelReq& req,
                           PutLiveChannelResp* resp);

  /// \brief ???????
  ///
  /// \param request   PutLiveChannelSwitchReq??
  /// \param response  PutLiveChannelSwitchResp??
  ///
  /// \return ??HTTP???????????
  CosResult PutLiveChannelSwitch(const PutLiveChannelSwitchReq& req,
                                 PutLiveChannelSwitchResp* resp);

  /// \brief ????????
  ///
  /// \param request   GetLiveChannelReq??
  /// \param response  GetLiveChannelResp??
  ///
  /// \return ??HTTP???????????
  CosResult GetLiveChannel(const GetLiveChannelReq& req,
                           GetLiveChannelResp* resp);

  /// \brief ??????????
  ///
  /// \param request   GetLiveChannelHistoryReq??
  /// \param response  GetLiveChannelHistoryResp??
  ///
  /// \return ??HTTP???????????
  CosResult GetLiveChannelHistory(const GetLiveChannelHistoryReq& req,
                                  GetLiveChannelHistoryResp* resp);

  /// \brief ??????????
  ///
  /// \param request   GetLiveChannelStatusReq??
  /// \param response  GetLiveChannelStatusResp??
  ///
  /// \return ??HTTP???????????
  CosResult GetLiveChannelStatus(const GetLiveChannelStatusReq& req,
                                 GetLiveChannelStatusResp* resp);

  /// \brief ?????
  ///
  /// \param request   DeleteLiveChannelReq??
  /// \param response  DeleteLiveChannelResp??
  ///
  /// \return ??HTTP???????????
  CosResult DeleteLiveChannel(const DeleteLiveChannelReq& req,
                              DeleteLiveChannelResp* resp);

  /// \brief ?????????????????????
  ///
  /// \param request   GetLiveChannelVodPlaylistReq??
  /// \param response  GetLiveChannelVodPlaylistResp??
  ///
  /// \return ??HTTP???????????
  CosResult GetLiveChannelVodPlaylist(const GetLiveChannelVodPlaylistReq& req,
                                      GetLiveChannelVodPlaylistResp* resp);

  /// \brief ???????????????????
  ///
  /// \param request  PostLiveChannelVodPlaylistReq??
  /// \param response  GetLiveChannelVodPlaylistResp??
  ///
  /// \return ??HTTP???????????
  CosResult PostLiveChannelVodPlaylist(const PostLiveChannelVodPlaylistReq& req,
                                       PostLiveChannelVodPlaylistResp* resp);

  /// \brief ???????,handler????
  CosResult MultiThreadDownload(const GetObjectByFileReq& req,
                                GetObjectByFileResp* resp,
                                const SharedTransferHandler& handler = nullptr);

  /* Resumable?? */

  /// \brief ??????
  CosResult ResumableGetObject(const GetObjectByFileReq& req,
                               GetObjectByFileResp* resp,
                               const SharedTransferHandler& handler = nullptr);

  /*?????????*/
  CosResult PutObjects(const PutObjectsByDirectoryReq& req,
                       PutObjectsByDirectoryResp* resp);

  CosResult PutDirectory(const PutDirectoryReq& req, PutDirectoryResp* resp);

  CosResult MoveObject(const MoveObjectReq& req);

  /*??????*/

  /**??????**/

  /**???????**/

  /***?????***/
  CosResult PutImage(const PutImageByFileReq& req, PutImageByFileResp* resp);

  /***??????***/
  CosResult CloudImageProcess(const CloudImageProcessReq& req,
                              CloudImageProcessResp* resp);

  /***??????????***/
  CosResult GetQRcode(const GetQRcodeReq& req, GetQRcodeResp* resp);

  /*??????*/

  /***????????????? Bucket***/
  CosResult DescribeDocProcessBuckets(const DescribeDocProcessBucketsReq& req,
                                      DescribeDocProcessBucketsResp* resp);

  /***????***/
  CosResult DocPreview(const DocPreviewReq& req, DocPreviewResp* resp);

  /***?????????***/
  CosResult GetMediaInfo(const GetMediaInfoReq& req, GetMediaInfoResp* resp);

  CosResult GetImageAuditing(const GetImageAuditingReq& req, GetImageAuditingResp* resp);

 private:
  // ??request body???xml???
  bool GenerateCompleteMultiUploadReqBody(const CompleteMultiUploadReq& req,
                                          std::string* req_body);

  /// \brief ?????,handler????
  CosResult
  MultiThreadUpload(const PutObjectByFileReq& req, const std::string& upload_id,
                    const std::vector<std::string>& already_exist_parts,
                    bool resume_flag, std::vector<std::string>* etags_ptr,
                    std::vector<uint64_t>* part_numbers_ptr,
                    const SharedTransferHandler& handler = nullptr);

  /// \brief ??????, ????????
  // uint64_t GetContent(const std::string& src, std::string* file_content) const;

  void FillUploadTask(const std::string& upload_id, const std::string& host,
                      const std::string& path, unsigned char* file_content_buf,
                      uint64_t len, uint64_t part_number,
                      FileUploadTask* task_ptr, bool sign_header_host);

  void FillCopyTask(const std::string& upload_id, const std::string& host,
                    const std::string& path, uint64_t part_number,
                    const std::string& range,
                    const std::map<std::string, std::string>& headers,
                    const std::map<std::string, std::string>& params,
                    bool verify_cert,const std::string& ca_location, 
                    FileCopyTask* task, bool sign_header_host);

  /// \brief ???????????
  /// \param req  PutObjectByFile??
  /// \param head_resp  HeadObjectResp????
  /// \param last_offset ???????????
  /// \return true???????,false?????
  bool CheckResumableDownloadTask(
      const std::string& json_file,
      const std::map<std::string, std::string>& element_map,
      uint64_t* resume_offset);
  /// \brief ??????json??
  /// \param json_file  json???
  /// \param element_map  ???????
  /// \param last_offset ???????????
  /// \return true??????, ????
  void UpdateResumableDownloadTaskFile(
      const std::string& json_file,
      const std::map<std::string, std::string>& element_map,
      uint64_t resume_offset);
  void SetResultAndLogError(CosResult& result, const std::string& err_msg);
};

}  // namespace qcloud_cos
#endif  // OBJECT_OP_H
