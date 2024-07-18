// Copyright (c) 2017, Tencent Inc.
// All rights reserved.
//
// Author: sevenyou <sevenyou@tencent.com>
// Created: 07/13/17
// Description:

#pragma once

#include "cos_sys_config.h"
#include "op/base_op.h"
#include "op/cos_result.h"
#include "request/bucket_req.h"
#include "request/data_process_req.h"
#include "request/auditing_req.h"
#include "response/bucket_resp.h"
#include "response/data_process_resp.h"
#include "response/auditing_resp.h"

namespace qcloud_cos {

/// \brief ???Bucket?????
class BucketOp : public BaseOp {
 public:
  /// \brief BucketOp????
  ///
  /// \param cos_conf Cos??
  explicit BucketOp(const SharedConfig& config) : BaseOp(config) {}

  /// \brief BucketOp????
  virtual ~BucketOp() {}

  /// \brief ??bucket????
  bool IsBucketExist(const std::string& bucket_name);

  /// \brief ??Bucket??Location
  std::string GetBucketLocation(const std::string& bucket_name);

  /// \brief ????Bucket
  ///        (??:https://www.qcloud.com/document/product/436/7738)
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

  /// \brief ??Bucket????????Object
  ///        (??:https://www.qcloud.com/document/product/436/7734)
  ///
  /// \param req  GetBucket??
  /// \param resp GetBucket??
  ///
  /// \return ?????????(?????)
  CosResult GetBucket(const GetBucketReq& req, GetBucketResp* resp);

  CosResult ListMultipartUpload(const ListMultipartUploadReq& req,
                                ListMultipartUploadResp* resp);
  /// \brief ??Bucket
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

  /// \brief ??Bucket????????Object(?????)
  ///
  /// \param req  GetBucketObjectVersions??
  /// \param resp GetBucketObjectVersions??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketObjectVersions(const GetBucketObjectVersionsReq& req,
                                    GetBucketObjectVersionsResp* resp);

  /// \brief ??Bucket??Location
  ///
  /// \param req  GetBucketLocation??
  /// \param resp GetBucketLocation??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketLocation(const GetBucketLocationReq& req,
                              GetBucketLocationResp* resp);
  // TODO(sevenyou)
  // std::string ListMultipartUploads();

  /// \brief ???????????
  /// \brief https://cloud.tencent.com/document/product/436/17054
  /// \param req  PutBucketLogging??
  /// \param resp PutBucketLogging??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketLogging(const PutBucketLoggingReq& req,
                             PutBucketLoggingResp* resp);

  /// \brief ???????????????
  /// \brief https://cloud.tencent.com/document/product/436/17053
  /// \param req  GetBucketLogging??
  /// \param resp GetBucketLogging??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketLogging(const GetBucketLoggingReq& req,
                             GetBucketLoggingResp* resp);

  /// \brief ????????????
  /// \brief
  /// \param req  PutBucketDomain??
  /// \param resp PutBucketDomain??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketDomain(const PutBucketDomainReq& req,
                            PutBucketDomainResp* resp);

  /// \brief ??????????????
  /// \brief
  /// \param req  GetBucketDomain??
  /// \param resp GetBucketDomain??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketDomain(const GetBucketDomainReq& req,
                            GetBucketDomainResp* resp);

  /// \brief ?????????????? XML
  /// ???????????????????64KB \brief
  /// https://cloud.tencent.com/document/product/436/31930 \param req
  /// PutBucketWebsite?? \param resp PutBucketWebsite??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketWebsite(const PutBucketWebsiteReq& req,
                             PutBucketWebsiteResp* resp);

  /// \brief ?????????????????.
  /// \brief https://cloud.tencent.com/document/product/436/31929
  /// \param req  GetBucketWebsite??
  /// \param resp GetBucketWebsite??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketWebsite(const GetBucketWebsiteReq& req,
                             GetBucketWebsiteResp* resp);

  /// \brief ?????????????.
  /// \brief https://cloud.tencent.com/document/product/436/31928
  /// \param req  DeleteBucketWebsite??
  /// \param resp DeleteBucketWebsite??
  ///
  /// \return ?????????(?????)
  CosResult DeleteBucketWebsite(const DeleteBucketWebsiteReq& req,
                                DeleteBucketWebsiteResp* resp);

  /// \brief ?????Bucket????.
  /// \brief https://cloud.tencent.com/document/product/436/34838
  /// \param req  PutBucketTagging??
  /// \param resp PutBucketTagging??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketTagging(const PutBucketTaggingReq& req,
                             PutBucketTaggingResp* resp);

  /// \brief ????????????????.
  /// \brief https://cloud.tencent.com/document/product/436/34837
  /// \param req  GetBucketTagging??
  /// \param resp GetBucketTagging??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketTagging(const GetBucketTaggingReq& req,
                             GetBucketTaggingResp* resp);

  /// \brief ????????????????.
  /// \brief https://cloud.tencent.com/document/product/436/34836
  /// \param req  DeleteBucketTagging??
  /// \param resp DeleteBucketTagging??
  ///
  /// \return ?????????(?????)
  CosResult DeleteBucketTagging(const DeleteBucketTaggingReq& req,
                                DeleteBucketTaggingResp* resp);

  /// \brief ?????????????.
  /// \brief https://cloud.tencent.com/document/product/436/33707
  /// \param req  PutBucketinventory??
  /// \param resp PutBucketinventory??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketInventory(const PutBucketInventoryReq& req,
                               PutBucketInventoryResp* resp);

  /// \brief ???????????????.
  /// \brief https://cloud.tencent.com/document/product/436/33705
  /// \param req  GetBucketinventory??
  /// \param resp GetBucketinventory??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketInventory(const GetBucketInventoryReq& req,
                               GetBucketInventoryResp* resp);

  /// \brief ?????????????????.
  /// \brief https://cloud.tencent.com/document/product/436/33706
  /// \param req  ListBucketInventoryConfigurations??
  /// \param resp ListBucketInventoryConfigurations??
  ///
  /// \return ?????????(?????)
  CosResult ListBucketInventoryConfigurations(
      const ListBucketInventoryConfigurationsReq& req,
      ListBucketInventoryConfigurationsResp* resp);

  /// \brief ???????????????.
  /// \brief https://cloud.tencent.com/document/product/436/33704
  /// \param req  DeleteBucketinventory??
  /// \param resp DeleteBucketinventory??
  ///
  /// \return ?????????(?????)
  CosResult DeleteBucketInventory(const DeleteBucketInventoryReq& req,
                                  DeleteBucketInventoryResp* resp);
  /// \brief ???????? Referer ????????.
  /// \brief https://cloud.tencent.com/document/product/436/32492
  /// \param req  PutBucketReferer??
  /// \param resp PutBucketReferer??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketReferer(const PutBucketRefererReq& req,
                             PutBucketRefererResp* resp);
  /// \brief ????? Referer ????????.
  /// \brief https://cloud.tencent.com/document/product/436/32493
  /// \param req  GetBucketReferer??
  /// \param resp GetBucketReferer??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketReferer(const GetBucketRefererReq& req,
                             GetBucketRefererResp* resp);
  /// \brief ??????
  /// \param req  ListLiveChannelReq??
  /// \param resp ListLiveChannelResp??
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
  CosResult PutBucketIntelligentTiering(
      const PutBucketIntelligentTieringReq& req,
      PutBucketIntelligentTieringResp* resp);

  /// \brief ???????????
  ///
  /// \param req  GetBucketIntelligentTiering??
  /// \param resp GetBucketIntelligentTiering??
  ///
  /// \return ?????????(?????)
  CosResult GetBucketIntelligentTiering(
      const GetBucketIntelligentTieringReq& req,
      GetBucketIntelligentTieringResp* resp);

  /// \brief ?????ci
  ///
  /// \param req  PutBucketToCIReq??
  /// \param resp PutBucketToCIResp??
  ///
  /// \return ?????????(?????)
  CosResult PutBucketToCI(const PutBucketToCIReq& req,
                             PutBucketToCIResp* resp);

  /// \brief ??????
  /// \param req  CreateDocBucket??
  /// \param resp CreateDocBucket??
  ///
  /// \return ?????????(?????)
  CosResult CreateDocBucket(const CreateDocBucketReq& req,
                          CreateDocBucketResp* resp);

  /// \brief ????????
  /// \brief https://cloud.tencent.com/document/product/436/54056
  /// \param req  CreateDocProcessJobs??
  /// \param resp CreateDocProcessJobs??
  ///
  /// \return ?????????(?????)
  CosResult CreateDocProcessJobs(const CreateDocProcessJobsReq& req,
                                 CreateDocProcessJobsResp* resp);

  /// \brief ???????????
  /// \brief https://cloud.tencent.com/document/product/436/54095
  /// \param req  DescribeDocProcessJob??
  /// \param resp DescribeDocProcessJob??
  ///
  /// \return ?????????(?????)
  CosResult DescribeDocProcessJob(const DescribeDocProcessJobReq& req,
                                  DescribeDocProcessJobResp* resp);

  /// \brief ??????????????
  /// \brief https://cloud.tencent.com/document/product/436/54096
  /// \param req  DescribeDocProcessJobs??
  /// \param resp DescribeDocProcessJobs??
  ///
  /// \return ?????????(?????)
  CosResult DescribeDocProcessJobs(const DescribeDocProcessJobsReq& req,
                                   DescribeDocProcessJobsResp* resp);

  /// \brief ????????
  /// \brief https://cloud.tencent.com/document/product/436/54055
  /// \param req  DescribeDocProcessQueues??
  /// \param resp DescribeDocProcessQueues??
  ///
  /// \return ?????????(?????)
  CosResult DescribeDocProcessQueues(const DescribeDocProcessQueuesReq& req,
                                     DescribeDocProcessQueuesResp* resp);
  /// \brief ????????
  /// \brief https://cloud.tencent.com/document/product/436/54094
  /// \param req  UpdateDocProcessQueue??
  /// \param resp UpdateDocProcessQueue??
  ///
  /// \return ?????????(?????)
  CosResult UpdateDocProcessQueue(const UpdateDocProcessQueueReq& req,
                                  UpdateDocProcessQueueResp* resp);

  /// \brief ??????????
  /// \brief https://cloud.tencent.com/document/product/436/48988
  /// \param req  DescribeMediaBuckets??
  /// \param resp DescribeMediaBuckets??
  ///
  /// \return ?????????(?????)
  CosResult DescribeMediaBuckets(const DescribeMediaBucketsReq& req,
                                 DescribeMediaBucketsResp* resp);

  /// \brief ??????
  /// \brief https://cloud.tencent.com/document/product/436/72824
  /// \param req  CreateMediaBucketReq??
  /// \param resp CreateMediaBucketResp??
  ///
  /// \return ?????????(?????)
  CosResult CreateMediaBucket(const CreateMediaBucketReq& req,
                          CreateMediaBucketResp* resp);
  /// \brief ????????
  /// \brief https://cloud.tencent.com/document/product/436/55672
  /// \param req  GetMediainfo??
  /// \param resp GetMediainfo??
  ///
  /// \return ?????????(?????)                                 
  CosResult GetMediainfo(const GetMediaInfoReq& req, GetMediaInfoResp* resp);

  /// \brief ??????
  /// \brief https://cloud.tencent.com/document/product/436/63593
  /// \param req  BatchImageAuditing??
  /// \param resp BatchImageAuditing??
  ///
  /// \return ?????????(?????)     
  CosResult BatchImageAuditing(const BatchImageAuditingReq& req,
                               BatchImageAuditingResp* resp);

  /// \brief ??????????
  /// \brief https://cloud.tencent.com/document/product/436/68904
  /// \param req  DescribeImageAuditingJob??
  /// \param resp DescribeImageAuditingJob??
  ///
  /// \return ?????????(?????)     
  CosResult DescribeImageAuditingJob(const DescribeImageAuditingJobReq& req,
                                     DescribeImageAuditingJobResp* resp);                               

  /// \brief ????????
  /// \brief https://cloud.tencent.com/document/product/436/47316
  /// \param req  DescribeVideoAuditingJob??
  /// \param resp DescribeVideoAuditingJob??
  ///
  /// \return ?????????(?????)     
  CosResult CreateVideoAuditingJob(const CreateVideoAuditingJobReq& req,
                                   CreateVideoAuditingJobResp* resp);   

  /// \brief ??????????
  /// \brief https://cloud.tencent.com/document/product/436/47317
  /// \param req  DescribeVideoAuditingJob??
  /// \param resp DescribeVideoAuditingJob??
  ///
  /// \return ?????????(?????)     
  CosResult DescribeVideoAuditingJob(const DescribeVideoAuditingJobReq& req,
                                     DescribeVideoAuditingJobResp* resp);    

  /// \brief ????????
  /// \brief https://cloud.tencent.com/document/product/436/54063
  /// \param req  DescribeAudioAuditingJob??
  /// \param resp DescribeAudioAuditingJob??
  ///
  /// \return ?????????(?????)     
  CosResult CreateAudioAuditingJob(const CreateAudioAuditingJobReq& req,
                                   CreateAudioAuditingJobResp* resp);   

  /// \brief ??????????
  /// \brief https://cloud.tencent.com/document/product/436/54064
  /// \param req  DescribeAudioAuditingJob??
  /// \param resp DescribeAudioAuditingJob??
  ///
  /// \return ?????????(?????)     
  CosResult DescribeAudioAuditingJob(const DescribeAudioAuditingJobReq& req,
                                     DescribeAudioAuditingJobResp* resp);

  /// \brief ????????
  /// \brief https://cloud.tencent.com/document/product/436/56289
  /// \param req  DescribeTextAuditingJob??
  /// \param resp DescribeTextAuditingJob??
  ///
  /// \return ?????????(?????)     
  CosResult CreateTextAuditingJob(const CreateTextAuditingJobReq& req,
                                  CreateTextAuditingJobResp* resp);   

  /// \brief ??????????
  /// \brief https://cloud.tencent.com/document/product/436/56288
  /// \param req  DescribeTextAuditingJob??
  /// \param resp DescribeTextAuditingJob??
  ///
  /// \return ?????????(?????)     
  CosResult DescribeTextAuditingJob(const DescribeTextAuditingJobReq& req,
                                    DescribeTextAuditingJobResp* resp);                                       

  /// \brief ????????
  /// \brief https://cloud.tencent.com/document/product/436/59381
  /// \param req  DescribeDocumentAuditingJob??
  /// \param resp DescribeDocumentAuditingJob??
  ///
  /// \return ?????????(?????)     
  CosResult CreateDocumentAuditingJob(const CreateDocumentAuditingJobReq& req,
                                      CreateDocumentAuditingJobResp* resp);   

  /// \brief ??????????
  /// \brief https://cloud.tencent.com/document/product/436/59382
  /// \param req  DescribeDocumentAuditingJob??
  /// \param resp DescribeDocumentAuditingJob??
  ///
  /// \return ?????????(?????)     
  CosResult DescribeDocumentAuditingJob(const DescribeDocumentAuditingJobReq& req,
                                        DescribeDocumentAuditingJobResp* resp);                                       

  /// \brief ????????
  /// \brief https://cloud.tencent.com/document/product/436/63958
  /// \param req  DescribeWebPageAuditingJob??
  /// \param resp DescribeWebPageAuditingJob??
  ///
  /// \return ?????????(?????)     
  CosResult CreateWebPageAuditingJob(const CreateWebPageAuditingJobReq& req,
                                      CreateWebPageAuditingJobResp* resp);   

  /// \brief ??????????
  /// \brief https://cloud.tencent.com/document/product/436/63959
  /// \param req  DescribeWebPageAuditingJob??
  /// \param resp DescribeWebPageAuditingJob??
  ///
  /// \return ?????????(?????)     
  CosResult DescribeWebPageAuditingJob(const DescribeWebPageAuditingJobReq& req,
                                        DescribeWebPageAuditingJobResp* resp);                                       



 private:
  /// \brief ??CI??
  CosResult ProcessReq(const BucketReq& req, BaseResp* resp,
                       bool is_ci_req = false);
};

}  // namespace qcloud_cos
