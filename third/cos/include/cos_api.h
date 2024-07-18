#ifndef COS_API_H
#define COS_API_H

#include "op/bucket_op.h"
#include "op/cos_result.h"
#include "op/object_op.h"
#include "op/service_op.h"
#include "util/auth_tool.h"
#include "util/codec_util.h"
#include "Poco/TaskManager.h"

namespace qcloud_cos {

class CosAPI {
 public:
  /// \brief CosAPI????
  ///
  /// \param config    cos??
  explicit CosAPI(CosConfig& config);

  ~CosAPI();

  /// \brief ????
  void SetCredentail(const std::string& ak, const std::string& sk,
                     const std::string& token);

  /// \brief ?? Bucket ???????
  std::string GetBucketLocation(const std::string& bucket_name);

  /// \brief ?????????
  std::string GeneratePresignedUrl(const GeneratePresignedUrlReq& req);

  /// \brief ?????????
  std::string GeneratePresignedUrl(const std::string& bucket_name,
                                   const std::string& object_name,
                                   uint64_t start_time_in_s,
                                   uint64_t end_time_in_s,
                                   HTTP_METHOD http_method);

  /// \brief ????????GET????
  std::string GeneratePresignedUrl(const std::string& bucket_name,
                                   const std::string& object_name,
                                   uint64_t start_time_in_s,
                                   uint64_t end_time_in_s);

  /// \brief ??Bucket????
  bool IsBucketExist(const std::string& bucket_name);

  /// \brief ??Object????
  bool IsObjectExist(const std::string& bucket_name,
                     const std::string& object_name);

  /// \brief List Buckets
  ///        ??: https://cloud.tencent.com/document/api/436/8291
  ///
  /// \param req  GetService??
  /// \param resp GetService??
  ///
  /// \return ?????????(?????)
  CosResult GetService(const GetServiceReq& req, GetServiceResp* resp);

  /// \brief ????Bucket
  ///        ??: https://www.qcloud.com/document/product/436/7738
  ///
  /// \param req  PutBucket??
  /// \param resp PutBucket??
  ///
  /// \return ?????????(?????)
  CosResult PutBucket(const PutBucketReq& req, PutBucketResp* resp);

  /// \brief ??Bucket????
  ///        (??:https://cloud.tencent.com/document/product/436/7735)
  ///
  /// \param req  HeadBucket??
  /// \param resp HeadBucket??
  ///
  /// \return ?????????(?????)
  CosResult HeadBucket(const HeadBucketReq& req, HeadBucketResp* resp);

  /// \brief ???Bucket????????Object, ???Bucket?Read ??
  ///        ??: https://www.qcloud.com/document/product/436/7734
  ///
  /// \param req   GetBucket??
  /// \param resp  GetBucket??
  ///
  /// \return ??HTTP???????????
  CosResult GetBucket(const GetBucketReq& req, GetBucketResp* resp);

  CosResult ListMultipartUpload(const ListMultipartUploadReq& req,
                                ListMultipartUploadResp* resp);

  /// \brief ??Bucket
  ///        ??: https://cloud.tencent.com/document/product/436/7732
  ///
  /// \param req  DeleteBucket??
  /// \param resp DeleteBucket??
  ///
  /// \return ?????????(?????)
  CosResult DeleteBucket(const DeleteBucketReq& req, DeleteBucketResp* resp);

  /// \brief ????????????
  ///        (??:https://cloud.tencent.com/document/product/436/8597)
  ///
  /// \param req  GetBucketVersioning??
  /// \param resp GetBucketVersioning??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketVersioning(const GetBucketVersioningReq& req,
                                GetBucketVersioningResp* resp);

  /// \brief ????????????????
  ///        (??:https://cloud.tencent.com/document/product/436/8591)
  ///
  /// \param req  PutBucketVersioning??
  /// \param resp PutBucketVersioning??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketVersioning(const PutBucketVersioningReq& req,
                                PutBucketVersioningResp* resp);

  /// \brief ??Bucket????????
  ///
  /// \param req  GetBucketReplication??
  /// \param resp GetBucketReplication??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketReplication(const GetBucketReplicationReq& req,
                                 GetBucketReplicationResp* resp);

  /// \brief ??/??Bucket????????
  ///
  /// \param req  PutBucketReplication??
  /// \param resp PutBucketReplication??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketReplication(const PutBucketReplicationReq& req,
                                 PutBucketReplicationResp* resp);

  /// \brief ??Bucket????????
  ///
  /// \param req  DeleteBucketReplication??
  /// \param resp DeleteBucketReplication??
  ///
  /// \return ?????????(?????)
  CosResult DeleteBucketReplication(const DeleteBucketReplicationReq& req,
                                    DeleteBucketReplicationResp* resp);

  /// \brief ??Bucket????????
  ///
  /// \param req  GetBucketLifecycle??
  /// \param resp GetBucketLifecycle??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketLifecycle(const GetBucketLifecycleReq& req,
                               GetBucketLifecycleResp* resp);

  /// \brief ??/??Bucket????????
  ///
  /// \param req  PutBucketLifecycle??
  /// \param resp PutBucketLifecycle??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketLifecycle(const PutBucketLifecycleReq& req,
                               PutBucketLifecycleResp* resp);

  /// \brief ??Bucket????????
  ///
  /// \param req  DeleteBucketLifecycle??
  /// \param resp DeleteBucketLifecycle??
  ///
  /// \return ?????????(?????)
  CosResult DeleteBucketLifecycle(const DeleteBucketLifecycleReq& req,
                                  DeleteBucketLifecycleResp* resp);

  /// \brief ??Bucket??ACL
  ///
  /// \param req  GetBucketACL??
  /// \param resp GetBucketACL??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketACL(const GetBucketACLReq& req, GetBucketACLResp* resp);

  /// \brief ??/??Bucket??ACL, ????Header??Body??ACL??
  ///        ??Header ? Body ??????????????????
  ///
  /// \param req  PutBucketACL??
  /// \param resp PutBucketACL??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketACL(const PutBucketACLReq& req, PutBucketACLResp* resp);

  /// \brief ??Bucket?????
  ///
  /// \param req  GetBucketPolicy??
  /// \param resp GetBucketPolicy??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketPolicy(const GetBucketPolicyReq& req, GetBucketPolicyResp* resp);

  /// \brief ??/??Bucket????????Body??
  ///
  /// \param req  PutBucketPolicy??
  /// \param resp PutBucketPolicy??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketPolicy(const PutBucketPolicyReq& req, PutBucketPolicyResp* resp);

  /// \brief ??Bucket?????
  ///
  /// \param req  DeleteBucketPolicy??
  /// \param resp DeleteBucketPolicy??
  ///
  /// \return ?????????(?????)
  CosResult DeleteBucketPolicy(const DeleteBucketPolicyReq& req, DeleteBucketPolicyResp* resp);

  /// \brief ??Bucket??CORS
  ///
  /// \param req  GetBucketCORS??
  /// \param resp GetBucketCORS??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketCORS(const GetBucketCORSReq& req, GetBucketCORSResp* resp);

  /// \brief ??/??Bucket??CORS
  ///
  /// \param req  PutBucketCORS??
  /// \param resp PutBucketCORS??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketCORS(const PutBucketCORSReq& req, PutBucketCORSResp* resp);

  /// \brief ??Bucket??CORS
  ///
  /// \param req  DeleteBucketCORS??
  /// \param resp DeleteBucketCORS??
  ///
  /// \return ?????????(?????)
  CosResult DeleteBucketCORS(const DeleteBucketCORSReq& req,
                             DeleteBucketCORSResp* resp);

  /// \brief ?????? Referer ????????
  ///
  /// \param req  PutBucketReferer??
  /// \param resp PutBucketReferer??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketReferer(const PutBucketRefererReq& req,
                             PutBucketRefererResp* resp);

  /// \brief ?????? Referer ????????
  ///
  /// \param req  GetBucketReferer??
  /// \param resp GetBucketReferer??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketReferer(const GetBucketRefererReq& req,
                             GetBucketRefererResp* resp);
  /// \brief ??????????????
  ///
  /// \param req  PutBucketLogging??
  /// \param resp PutBucketLogging??
  ///
  /// \return ?????????(?????)

  CosResult PutBucketLogging(const PutBucketLoggingReq& req,
                             PutBucketLoggingResp* resp);

  /// \brief ??????????????
  ///
  /// \param req  GetBucketLogging??
  /// \param resp GetBucketLogging??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketLogging(const GetBucketLoggingReq& req,
                             GetBucketLoggingResp* resp);

  /// \brief ???????????
  ///
  /// \param req  PutBucketDomain??
  /// \param resp PutBucketDomain??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketDomain(const PutBucketDomainReq& req,
                            PutBucketDomainResp* resp);

  /// \brief ???????????
  ///
  /// \param req  GetBucketDomain??
  /// \param resp GetBucketDomain??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketDomain(const GetBucketDomainReq& req,
                            GetBucketDomainResp* resp);

  /// \brief ??????????,?????? XML
  /// ???????????,???????64KB.
  ///
  /// \param req  PutBucketWebsite??
  /// \param resp PutBucketWebsite??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketWebsite(const PutBucketWebsiteReq& req,
                             PutBucketWebsiteResp* resp);

  /// \brief ?????????????????????.
  ///
  /// \param req  GetBucketWebsite??
  /// \param resp GetBucketWebsite??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketWebsite(const GetBucketWebsiteReq& req,
                             GetBucketWebsiteResp* resp);

  /// \brief ?????????????.
  ///
  /// \param req  DeleteBucketWebsite??
  /// \param resp DeleteBucketWebsite??
  ///
  /// \return ?????????(?????)
  CosResult DeleteBucketWebsite(const DeleteBucketWebsiteReq& req,
                                DeleteBucketWebsiteResp* resp);

  /// \brief ????Bucket????.
  ///
  /// \param req  PutBucketTagging??
  /// \param resp PutBucketTagging??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketTagging(const PutBucketTaggingReq& req,
                             PutBucketTaggingResp* resp);

  /// \brief ????????????????.
  ///
  /// \param req  GetBucketTagging??
  /// \param resp GetBucketTagging??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketTagging(const GetBucketTaggingReq& req,
                             GetBucketTaggingResp* resp);

  /// \brief ????????????????.
  ///
  /// \param req  DeleteBucketTagging??
  /// \param resp DeleteBucketTagging??
  ///
  /// \return ?????????(?????)
  CosResult DeleteBucketTagging(const DeleteBucketTaggingReq& req,
                                DeleteBucketTaggingResp* resp);

  /// \brief ???????????.
  ///
  /// \param req  PutBucketInventory??
  /// \param resp PutBucketInventory??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketInventory(const PutBucketInventoryReq& req,
                               PutBucketInventoryResp* resp);

  /// \brief ?????????????????.
  ///
  /// \param req  GetBucketInventory??
  /// \param resp GetBucketInventory??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketInventory(const GetBucketInventoryReq& req,
                               GetBucketInventoryResp* resp);

  /// \brief ???????????????????.
  ///
  /// \param req  ListBucketInventoryConfigurations??
  /// \param resp ListBucketInventoryConfigurations??
  ///
  /// \return ?????????(?????)
  CosResult ListBucketInventoryConfigurations(
      const ListBucketInventoryConfigurationsReq& req,
      ListBucketInventoryConfigurationsResp* resp);

  /// \brief ???????????????.
  ///
  /// \param req  DeleteBucketinventory??
  /// \param resp DeleteBucketinventory??
  ///
  /// \return ?????????(?????)
  CosResult DeleteBucketInventory(const DeleteBucketInventoryReq& req,
                                  DeleteBucketInventoryResp* resp);

  /// \brief ????Object?meta????
  ///        ??: https://www.qcloud.com/document/product/436/7745
  ///
  /// \param req   HeadObject??
  /// \param resp  HeadObject??
  ///
  /// \return ??HTTP???????????
  CosResult HeadObject(const HeadObjectReq& req, HeadObjectResp* resp);

  /// \brief ??Bucket?????????
  ///        ??: https://www.qcloud.com/document/product/436/7753
  ///
  /// \param req   GetObjectByStream??
  /// \param resp  GetObjectByStream??
  ///
  /// \return ??HTTP???????????
  CosResult GetObject(const GetObjectByStreamReq& req,
                      GetObjectByStreamResp* resp);

  /// \brief ??Bucket?????????
  ///        ??: https://www.qcloud.com/document/product/436/7753
  ///
  /// \param req   GetObjectByFile??
  /// \param resp  GetObjectByFile??
  ///
  /// \return ??HTTP???????????
  CosResult GetObject(const GetObjectByFileReq& req, GetObjectByFileResp* resp);

  /// \brief ?????URL
  ///
  /// \param bucket  ????
  /// \param object  ???
  /// \param https   ????https
  /// \param region  ???,?????????????
  ///
  /// \return ??HTTP???????????
  std::string GetObjectUrl(const std::string& bucket, const std::string& object,
                           bool https = true, const std::string& region = "");

  /// \brief ???????????Bucket?
  ///        ??: https://www.qcloud.com/document/product/436/7749
  ///
  /// \param req   PutObject??
  /// \param resp  PutObject??
  ///
  /// \return ??HTTP???????????
  CosResult PutObject(const PutObjectByFileReq& req, PutObjectByFileResp* resp);

  /// \brief ?????????Bucket?
  ///        ??: https://www.qcloud.com/document/product/436/7749
  ///
  /// \param req   PutObject??
  /// \param resp  PutObject??
  ///
  /// \return ??HTTP???????????
  CosResult PutObject(const PutObjectByStreamReq& req,
                      PutObjectByStreamResp* resp);

  /// \brief ??Object
  ///        ??: https://cloud.tencent.com/document/product/436/7743
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
  ///        ??: https://www.qcloud.com/document/product/436/7746
  ///
  /// \param req   InitMultiUpload??
  /// \param resp  InitMultiUpload??
  ///
  /// \return ??HTTP???????????
  CosResult InitMultiUpload(const InitMultiUploadReq& req,
                            InitMultiUploadResp* resp);

  /// \brief
  /// ??????????,?????????1?10000,?????1MB?5GB
  ///        ??: https://www.qcloud.com/document/product/436/7750
  ///
  /// \param req   UploadPartData??
  /// \param resp  UploadPartData??
  ///
  /// \return ??HTTP???????????
  CosResult UploadPartData(const UploadPartDataReq& req,
                           UploadPartDataResp* resp);

  /// \brief
  /// ????????????,????????1?10000,?????1MB?5GB
  ///        ??: https://cloud.tencent.com/document/product/436/8287
  ///
  /// \param req   UploadPartCopyData??
  /// \param resp  UploadPartCopyData??
  ///
  /// \return ??HTTP???????????
  CosResult UploadPartCopyData(const UploadPartCopyDataReq& req,
                               UploadPartCopyDataResp* resp);

  /// \brief ???????????? Upload Parts ?????????
  ///        ????? API ????????????
  ///        ??: https://www.qcloud.com/document/product/436/7742
  ///
  /// \param req   CompleteMultiUpload??
  /// \param resp  CompleteMultiUpload??
  ///
  /// \return ??HTTP???????????
  CosResult CompleteMultiUpload(const CompleteMultiUploadReq& req,
                                CompleteMultiUploadResp* resp);

  /// \brief ????????????????
  ///        ??: https://www.qcloud.com/document/product/436/7740
  ///
  /// \param req  AbortMultiUpload??
  /// \param resp AbortMultiUpload??
  ///
  /// \return ??HTTP???????????
  CosResult AbortMultiUpload(const AbortMultiUploadReq& req,
                             AbortMultiUploadResp* resp);

  /// \brief ???????????????
  ///
  /// \param req  ListParts??
  /// \param resp ListParts??
  ///
  /// \return
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

  /// \brief ??Object, ???????Object??5G
  ///
  /// \param req  PutObjectCopy??
  /// \param resp PutObjectCopy??
  ///
  /// \return ?????????(?????)
  CosResult PutObjectCopy(const PutObjectCopyReq& req, PutObjectCopyResp* resp);

  /// \brief ??Object,
  /// ?????Object??,??PutObjectCopy/UploadPartCopyData
  ///
  /// \param req  Copy??
  /// \param resp Copy??
  ///
  /// \return ?????????(?????)
  CosResult Copy(const CopyReq& req, CopyResp* resp);

  /// \brief ????? COS ??? archive ?????????
  ///
  /// \param req   PostObjectRestore??
  /// \param resp  PostObjectRestore??
  ///
  /// \return ??HTTP???????????
  CosResult PostObjectRestore(const PostObjectRestoreReq& req,
                              PostObjectRestoreResp* resp);

  /// \brief
  /// ??Object?????????????https://cloud.tencent.com/document/product/436/8288
  ///
  /// \param req  OptionsObjectReq ??
  /// \param resp OptionsObjectResp ??
  ///
  /// \return ?????????(?????)
  CosResult OptionsObject(const OptionsObjectReq& req, OptionsObjectResp* resp);

  /// \brief ??SELECT
  /// ?????https://cloud.tencent.com/document/product/436/37641
  CosResult SelectObjectContent(const SelectObjectContentReq& req,
                                SelectObjectContentResp* resp);

  /// \brief ????, ??https://cloud.tencent.com/document/product/436/7743
  ///
  /// \param req  AppendObject??
  /// \param resp AppendObject??
  ///
  /// \return ?????????(?????)
  CosResult AppendObject(const AppendObjectReq& req, AppendObjectResp* resp);

  /// \brief ??Bucket????????Object(?????)
  ///
  /// \param req  GetBucketObjectVersions??
  /// \param resp GetBucketObjectVersions??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketObjectVersions(const GetBucketObjectVersionsReq& req,
                                    GetBucketObjectVersionsResp* resp);

  /// \brief ??????
  ///
  /// \param req  PutLiveChannelReq??
  /// \param resp PutLiveChannelResp??
  ///
  /// \return ?????????(?????)
  CosResult PutLiveChannel(const PutLiveChannelReq& req,
                           PutLiveChannelResp* resp);

  /// \brief ????????????url
  ///
  /// \param bucket ?????
  /// \param channel ???
  /// \param expire ??????
  /// \param url_params url??
  ///
  /// \return ??????url
  std::string
  GetRtmpSignedPublishUrl(const std::string& bucket, const std::string& channel,
                          int expire,
                          const std::map<std::string, std::string> url_params);

  /// \brief ??????????
  ///
  /// \param req  PutLiveChannelSwitch??
  /// \param resp PutLiveChannelSwitch??
  ///
  /// \return ?????????(?????)
  CosResult PutLiveChannelSwitch(const PutLiveChannelSwitchReq& req,
                                 PutLiveChannelSwitchResp* resp);

  /// \brief ??????????
  ///
  /// \param req  GetLiveChannel??
  /// \param resp GetLiveChannel??
  ///
  /// \return ?????????(?????)
  CosResult GetLiveChannel(const GetLiveChannelReq& req,
                           GetLiveChannelResp* resp);

  /// \brief ??????????
  ///
  /// \param req  GetLiveChannelHistory??
  /// \param resp GetLiveChannelHistory??
  ///
  /// \return ?????????(?????)
  CosResult GetLiveChannelHistory(const GetLiveChannelHistoryReq& req,
                                  GetLiveChannelHistoryResp* resp);

  /// \brief ??????????
  ///
  /// \param req  GetLiveChannelStatus??
  /// \param resp GetLiveChannelStatus??
  ///
  /// \return ?????????(?????)
  CosResult GetLiveChannelStatus(const GetLiveChannelStatusReq& req,
                                 GetLiveChannelStatusResp* resp);

  /// \brief ??????
  ///
  /// \param req  GetLiveChannelStatus??
  /// \param resp GetLiveChannelStatus??
  ///
  /// \return ?????????(?????)
  CosResult DeleteLiveChannel(const DeleteLiveChannelReq& req,
                              DeleteLiveChannelResp* resp);

  /// \brief ?????????????????????
  ///
  /// \param req  GetLiveChannelVodPlaylist??
  /// \param resp GetLiveChannelVodPlaylist??
  ///
  /// \return ?????????(?????)
  CosResult GetLiveChannelVodPlaylist(const GetLiveChannelVodPlaylistReq& req,
                                      GetLiveChannelVodPlaylistResp* resp);

  /// \brief ???????????????????
  ///
  /// \param req  PostLiveChannelVodPlaylist??
  /// \param resp PostLiveChannelVodPlaylist??
  ///
  /// \return ?????????(?????)
  CosResult PostLiveChannelVodPlaylist(const PostLiveChannelVodPlaylistReq& req,
                                       PostLiveChannelVodPlaylistResp* resp);

  /// \brief ????
  ///
  /// \param req  PostLiveChannelVodPlaylist??
  /// \param resp PostLiveChannelVodPlaylist??
  ///
  /// \return ?????????(?????)
  CosResult ListLiveChannel(const ListLiveChannelReq& req,
                            ListLiveChannelResp* resp);

  /// \brief ?????????
  ///
  /// \param req  PutBucketIntelligentTiering??
  /// \param resp PutBucketIntelligentTiering??
  ///
  /// \return ?????????(?????)
  CosResult
  PutBucketIntelligentTiering(const PutBucketIntelligentTieringReq& req,
                              PutBucketIntelligentTieringResp* resp);

  /// \brief ???????????
  ///
  /// \param req  GetBucketIntelligentTiering??
  /// \param resp GetBucketIntelligentTiering??
  ///
  /// \return ?????????(?????)
  CosResult
  GetBucketIntelligentTiering(const GetBucketIntelligentTieringReq& req,
                              GetBucketIntelligentTieringResp* resp);

  /* Multithread?? */

  /// \brief ???????????????????????????????
  ///
  /// \param req   MultiPutObject??
  /// \param resp  MultiPutObject??
  ///
  /// \return ??HTTP???????????
  CosResult MultiPutObject(const MultiPutObjectReq& req,
                           MultiPutObjectResp* resp);

  /// \brief ???Range???????
  ///        ??: https://www.qcloud.com/document/product/436/7753
  ///
  /// \param req   MultiGetObject??
  /// \param resp  MultiGetObject??
  ///
  /// \return ??HTTP???????????
  CosResult MultiGetObject(const MultiGetObjectReq& req,
                           MultiGetObjectResp* resp);

  /* Resumable?? */

  /// \brief ???????????????????????????????
  // CosResult ResumablePutObject(const PutObjectByFile& req,
  // MultiPutObjectResp* resp);

  /// \brief ??????
  CosResult ResumableGetObject(const GetObjectByFileReq& req,
                               GetObjectByFileResp* resp);

  /* Async?? */

  /// \brief ??????????????????
  /// \param req  PutObjectAsync??
  /// \return ??context
  SharedAsyncContext AsyncPutObject(const AsyncPutObjectReq& req);
  SharedAsyncContext AsyncPutObject(const AsyncPutObjectReq& req, Poco::TaskManager*& taskManager);

  SharedAsyncContext AsyncPutObject(const AsyncPutObjectByStreamReq& req);
  SharedAsyncContext AsyncPutObject(const AsyncPutObjectByStreamReq& req, Poco::TaskManager*& taskManager);

  /// \brief
  /// ??????,???????????????????????????????
  /// \param req  MultiPutObjectAsync??
  /// \return ??context
  SharedAsyncContext AsyncMultiPutObject(const AsyncMultiPutObjectReq& req);
  SharedAsyncContext AsyncMultiPutObject(const AsyncMultiPutObjectReq& req, Poco::TaskManager*& taskManager);

  /// \brief ????????????
  /// \param req  GetObjectAsync??
  /// \return ??context
  SharedAsyncContext AsyncGetObject(const AsyncGetObjectReq& req);
  SharedAsyncContext AsyncGetObject(const AsyncGetObjectReq& req, Poco::TaskManager*& taskManager);

  /// \brief ???????????????????
  /// \param req  AsyncResumableGetObject
  /// \return ??context
  SharedAsyncContext AsyncResumableGetObject(const AsyncGetObjectReq& req);
  SharedAsyncContext AsyncResumableGetObject(const AsyncGetObjectReq& req, Poco::TaskManager*& taskManager);;

  /// \brief ????????????
  /// \param req   MultiGetObjectAsync??
  /// \return ??context
  SharedAsyncContext AsyncMultiGetObject(const AsyncMultiGetObjectReq& req);
  SharedAsyncContext AsyncMultiGetObject(const AsyncMultiGetObjectReq& req, Poco::TaskManager*& taskManager);

  /* ????????? */

  /// \brief ??????
  /// \param req   PutObjects??
  /// \param resp  PutObjects??
  /// \return ??????
  CosResult PutObjects(const PutObjectsByDirectoryReq& req,
                       PutObjectsByDirectoryResp* resp);

  /// \brief ????
  /// \param req   PutDirectory??
  /// \param resp  PutDirectory??
  /// \return ??????
  CosResult PutDirectory(const PutDirectoryReq& req, PutDirectoryResp* resp);

  /// \brief ????
  /// \param req   MoveObject??
  /// \return ??????
  CosResult MoveObject(const MoveObjectReq& req);

  /// \brief ?????Object
  /// \param req  DeleteObjectsByPrefix??
  /// \param resp DeleteObjectsByPrefix??
  /// \return ?????????(?????)
  CosResult DeleteObjects(const DeleteObjectsByPrefixReq& req,
                          DeleteObjectsByPrefixResp* resp);

  /* ?????? */

  /*** ????????? ***/
  CosResult PutBucketToCI(const PutBucketToCIReq& req,
                          PutBucketToCIResp* resp);

  /** ?????? **/

  /** ??????? **/

  /*** ????? ***/
  CosResult PutImage(PutImageByFileReq& req, PutImageByFileResp* resp);

  /*** ?????? ***/
  CosResult CloudImageProcess(const CloudImageProcessReq& req,
                              CloudImageProcessResp* resp);

  /*** ?????????? ***/
  CosResult GetQRcode(const GetQRcodeReq& req, GetQRcodeResp* resp);

  /** ?????? **/

  /*** ????????????? Bucket ***/
  // https://cloud.tencent.com/document/product/436/54057
  CosResult DescribeDocProcessBuckets(const DescribeDocProcessBucketsReq& req,
                                      DescribeDocProcessBucketsResp* resp);

  /*** ???? ***/
  // https://cloud.tencent.com/document/product/436/54058
  CosResult DocPreview(const DocPreviewReq& req, DocPreviewResp* resp);

  /*** ????????? ***/
  CosResult CreateDocBucket(const CreateDocBucketReq& req,
                          CreateDocBucketResp* resp);

  /*** ?????????? ***/
  // https://cloud.tencent.com/document/product/436/54056
  CosResult CreateDocProcessJobs(const CreateDocProcessJobsReq& req,
                                 CreateDocProcessJobsResp* resp);

  /*** ??????????? ***/
  // https://cloud.tencent.com/document/product/436/54095
  CosResult DescribeDocProcessJob(const DescribeDocProcessJobReq& req,
                                  DescribeDocProcessJobResp* resp);

  /*** ????????????? ***/
  // https://cloud.tencent.com/document/product/436/54096
  CosResult DescribeDocProcessJobs(const DescribeDocProcessJobsReq& req,
                                   DescribeDocProcessJobsResp* resp);

  /*** ???????? ***/
  // https://cloud.tencent.com/document/product/436/54055
  CosResult DescribeDocProcessQueues(const DescribeDocProcessQueuesReq& req,
                                     DescribeDocProcessQueuesResp* resp);

  /*** ???????? ***/
  // https://cloud.tencent.com/document/product/436/54094
  CosResult UpdateDocProcessQueue(const UpdateDocProcessQueueReq& req,
                                  UpdateDocProcessQueueResp* resp);

  /** ?????? **/

  /*** ???????????????? ***/
  // https://cloud.tencent.com/document/product/436/48988
  CosResult DescribeMediaBuckets(const DescribeMediaBucketsReq& req,
                                 DescribeMediaBucketsResp* resp);

  /*** ????????? ***/
  CosResult CreateMediaBucket(const CreateMediaBucketReq& req,
                          CreateMediaBucketResp* resp);

  /*** ????????????? ***/
  // https://cloud.tencent.com/document/product/436/55671
  CosResult GetSnapshot(const GetSnapshotReq& req, GetSnapshotResp* resp);

  /*** ????????? ***/
  // https://cloud.tencent.com/document/product/436/55672
  CosResult GetMediaInfo(const GetMediaInfoReq& req, GetMediaInfoResp* resp);

  /* ?????? */

  /** ???? **/

  /*** ?????? ***/
  // https://cloud.tencent.com/document/product/436/45434
  CosResult GetImageAuditing(const GetImageAuditingReq& req,
                             GetImageAuditingResp* resp);

  /*** ?????? ***/
  // https://cloud.tencent.com/document/product/436/63593
  CosResult BatchImageAuditing(const BatchImageAuditingReq& req,
                               BatchImageAuditingResp* resp);

  /*** ?????????? ***/
  // https://cloud.tencent.com/document/product/436/68904
  CosResult DescribeImageAuditingJob(const DescribeImageAuditingJobReq& req,
                                     DescribeImageAuditingJobResp* resp);

  /*** ???????? ***/
  // https://cloud.tencent.com/document/product/436/47316
  CosResult CreateVideoAuditingJob(const CreateVideoAuditingJobReq& req,
                                   CreateVideoAuditingJobResp* resp);

  /*** ?????????? ***/
  // https://cloud.tencent.com/document/product/436/47317
  CosResult DescribeVideoAuditingJob(const DescribeVideoAuditingJobReq& req,
                               DescribeVideoAuditingJobResp* resp);

  /*** ???????? ***/
  // https://cloud.tencent.com/document/product/436/54063
  CosResult CreateAudioAuditingJob(const CreateAudioAuditingJobReq& req,
                                   CreateAudioAuditingJobResp* resp);

  /*** ?????????? ***/
  // https://cloud.tencent.com/document/product/436/54064
  CosResult DescribeAudioAuditingJob(const DescribeAudioAuditingJobReq& req,
                               DescribeAudioAuditingJobResp* resp);

  /*** ???????? ***/
  // https://cloud.tencent.com/document/product/436/56289
  CosResult CreateTextAuditingJob(const CreateTextAuditingJobReq& req,
                                   CreateTextAuditingJobResp* resp);

  /*** ?????????? ***/
  // https://cloud.tencent.com/document/product/436/56288
  CosResult DescribeTextAuditingJob(const DescribeTextAuditingJobReq& req,
                               DescribeTextAuditingJobResp* resp);

  /*** ???????? ***/
  // https://cloud.tencent.com/document/product/436/59381
  CosResult CreateDocumentAuditingJob(const CreateDocumentAuditingJobReq& req,
                                   CreateDocumentAuditingJobResp* resp);

  /*** ?????????? ***/
  // https://cloud.tencent.com/document/product/436/59382
  CosResult DescribeDocumentAuditingJob(const DescribeDocumentAuditingJobReq& req,
                               DescribeDocumentAuditingJobResp* resp);

  /*** ???????? ***/
  // https://cloud.tencent.com/document/product/436/63958
  CosResult CreateWebPageAuditingJob(const CreateWebPageAuditingJobReq& req,
                                   CreateWebPageAuditingJobResp* resp);

  /*** ?????????? ***/
  // https://cloud.tencent.com/document/product/436/63959
  CosResult DescribeWebPageAuditingJob(const DescribeWebPageAuditingJobReq& req,
                               DescribeWebPageAuditingJobResp* resp);

 private:
  int CosInit();
  void CosUInit();

 private:
  // Be careful with the m_config order
  SharedConfig m_config;
  ObjectOp m_object_op;    // ????object?????
  BucketOp m_bucket_op;    // ????bucket?????
  ServiceOp m_service_op;  // ????service?????

  static bool s_init;
  static bool s_poco_init;
  static int s_cos_obj_num;
};

}  // namespace qcloud_cos
#endif
