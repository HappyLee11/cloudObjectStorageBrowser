// Copyright (c) 2017, Tencent Inc.
// All rights reserved.
//
// Author: sevenyou <sevenyou@tencent.com>
// Created: 07/21/17
// Description:

#ifndef OBJECT_RESP_H
#define OBJECT_RESP_H
#pragma once

#include <iostream>
#include <vector>

#include "cos_config.h"
#include "cos_params.h"
#include "response/base_resp.h"

namespace qcloud_cos {

class GetObjectResp : public BaseResp {
 public:
  /// \brief ??object type, ??object??????????????normal ??
  /// appendable
  std::string GetXCosObjectType() const { return m_x_cos_object_type; }
  void SetXCosObjectType(const std::string& x_cos_object_type) {
    m_x_cos_object_type = x_cos_object_type;
  }

  /// \brief ?????????
  std::map<std::string, std::string> GetXCosMetas() const {
    return m_x_cos_metas;
  }
  /// \brief ?????????
  std::string GetXCosMeta(const std::string& key) const {
    std::map<std::string, std::string>::const_iterator itr =
        m_x_cos_metas.find(key);
    if (itr != m_x_cos_metas.end()) {
      return itr->second;
    }
    return "";
  }
  void SetXCosMeta(const std::string& key, const std::string& value) {
    m_x_cos_metas[key] = value;
  }

  /// \brief Server????????
  std::string GetXCosServerSideEncryption() const {
    return GetHeader("x-cos-server-side-encryption");
  }

  void ParseFromHeaders(const std::map<std::string, std::string>& headers);

 protected:
  GetObjectResp() {}

  GetObjectResp(const GetObjectResp& rhs)
      : BaseResp(rhs),
        m_x_cos_object_type(rhs.m_x_cos_object_type),
        m_x_cos_metas(rhs.m_x_cos_metas) {}

  GetObjectResp& operator=(const GetObjectResp& rhs) {
    if (&rhs != this) {
      BaseResp::operator=(rhs);
      m_x_cos_object_type = rhs.m_x_cos_object_type;
      m_x_cos_metas = rhs.m_x_cos_metas;
    }
    return *this;
  }

  virtual ~GetObjectResp() {}

 private:
  std::string m_x_cos_object_type;
  std::map<std::string, std::string> m_x_cos_metas;
};

class GetObjectByStreamResp : public GetObjectResp {
 public:
  GetObjectByStreamResp() {}
  virtual ~GetObjectByStreamResp() {}
};

class GetObjectByFileResp : public GetObjectResp {
 public:
  GetObjectByFileResp() {}
  virtual ~GetObjectByFileResp() {}
};

class PutObjectResp : virtual public BaseResp {
 protected:
  PutObjectResp() {}
  virtual ~PutObjectResp() {}

 public:
  /// ??Object????, ??Bucket??????, ??????
  std::string GetVersionId() const { return GetHeader("x-cos-version-id"); }

  /// Server????????
  std::string GetXCosServerSideEncryption() const {
    return GetHeader("x-cos-server-side-encryption");
  }
};

class PutObjectByStreamResp : public PutObjectResp {
 public:
  PutObjectByStreamResp() {}
  virtual ~PutObjectByStreamResp() {}
};

class PutObjectByFileResp : public PutObjectResp {
 public:
  PutObjectByFileResp() {}
  virtual ~PutObjectByFileResp() {}
};

class DeleteObjectResp : public BaseResp {
 public:
  DeleteObjectResp() {}
  virtual ~DeleteObjectResp() {}
};

class DeleteObjectsResp : public BaseResp {
 public:
  DeleteObjectsResp() {}
  virtual ~DeleteObjectsResp() {}

  std::vector<DeletedInfo> GetDeletedInfos() const { return m_deleted_infos; }

  std::vector<ErrorInfo> GetErrorMsgs() const { return m_error_infos; }

  virtual bool ParseFromXmlString(const std::string& body);

 private:
  std::vector<DeletedInfo> m_deleted_infos;
  std::vector<ErrorInfo> m_error_infos;
};

class HeadObjectResp : public BaseResp {
 public:
  HeadObjectResp() {}
  virtual ~HeadObjectResp() {}

  /// \brief ??object type, ??object??????????????normal ??
  /// appendable
  std::string GetXCosObjectType() const { return m_x_cos_object_type; }
  void SetXCosObjectType(const std::string& x_cos_object_type) {
    m_x_cos_object_type = x_cos_object_type;
  }

  /// \brief ?????????
  std::map<std::string, std::string> GetXCosMetas() const {
    return m_x_cos_metas;
  }
  /// \brief ?????????
  std::string GetXCosMeta(const std::string& key) const {
    std::map<std::string, std::string>::const_iterator itr =
        m_x_cos_metas.find(key);
    if (itr != m_x_cos_metas.end()) {
      return itr->second;
    }
    return "";
  }
  void SetXCosMeta(const std::string& key, const std::string& value) {
    m_x_cos_metas[key] = value;
  }

  /// \brief ?? archive ???????????
  std::string GetXCosRestore() const { return GetHeader("x-cos-restore"); }

  /// \brief Server????????
  std::string GetXCosServerSideEncryption() const {
    return GetHeader("x-cos-server-side-encryption");
  }

  void ParseFromHeaders(const std::map<std::string, std::string>& headers);

 private:
  std::string m_x_cos_object_type;
  std::map<std::string, std::string> m_x_cos_metas;
};

class InitMultiUploadResp : public BaseResp {
 public:
  InitMultiUploadResp() {}
  virtual ~InitMultiUploadResp() {}

  virtual bool ParseFromXmlString(const std::string& body);

  /// \brief ??uploadId, ??????
  std::string GetUploadId() const { return m_upload_id; }

  /// \brief ??Object???
  std::string GetKey() const { return m_key; }

  /// \brief ???????Bucket
  std::string GetBucket() const { return m_bucket; }

  /// \brief Server????????
  std::string GetXCosServerSideEncryption() const {
    return GetHeader("x-cos-server-side-encryption");
  }

 private:
  std::string m_bucket;
  std::string m_key;  // object??
  std::string m_upload_id;
};

class UploadPartDataResp : public BaseResp {
 public:
  UploadPartDataResp() {}
  virtual ~UploadPartDataResp() {}

  /// \brief Server????????
  std::string GetXCosServerSideEncryption() const {
    return GetHeader("x-cos-server-side-encryption");
  }
};

class UploadPartCopyDataResp : public BaseResp {
 public:
  UploadPartCopyDataResp() {}
  virtual ~UploadPartCopyDataResp() {}

  virtual bool ParseFromXmlString(const std::string& body);

  /// \brief ???????MD5??????
  ///        ETag ???????? Object ??????????
  std::string GetEtag() const { return m_etag; }

  /// \brief ???????????GMT ??
  std::string GetLastModified() const { return m_last_modified; }

  /// \brief Server????????
  std::string GetXCosServerSideEncryption() const {
    return GetHeader("x-cos-server-side-encryption");
  }

 private:
  std::string m_etag;
  std::string m_last_modified;
};

class CompleteMultiUploadResp : public BaseResp {
 public:
  CompleteMultiUploadResp() {}
  virtual ~CompleteMultiUploadResp() {}

  virtual bool ParseFromXmlString(const std::string& body);

  std::string GetLocation() const { return m_location; }
  std::string GetKey() const { return m_key; }
  std::string GetBucket() const { return m_bucket; }
  std::string GetVersionId() const { return GetHeader("x-cos-version-id"); }

  /// \brief Server????????
  std::string GetXCosServerSideEncryption() const {
    return GetHeader("x-cos-server-side-encryption");
  }

 private:
  std::string m_location;  // Object???????
  std::string m_bucket;
  std::string m_key;
};

class AbortMultiUploadResp : public BaseResp {
 public:
  AbortMultiUploadResp() {}
  virtual ~AbortMultiUploadResp() {}
};

class ListPartsResp : public BaseResp {
 public:
  ListPartsResp()
      : m_bucket(""),
        m_encoding_type(""),
        m_key(""),
        m_upload_id(""),
        m_part_number_marker(0),
        m_parts(0),
        m_next_part_number_marker(0),
        m_storage_class(""),
        m_max_parts(1000),
        m_is_truncated(false) {}
  virtual ~ListPartsResp() {}

  virtual bool ParseFromXmlString(const std::string& body);

  std::string GetBucket() const { return m_bucket; }

  std::string GetEncodingType() const { return m_encoding_type; }

  std::string GetKey() const { return m_key; }

  std::string GetUploadId() const { return m_upload_id; }

  Initiator GetInitiator() const { return m_initiator; }

  Owner GetOwner() const { return m_owner; }

  uint64_t GetPartNumberMarker() const { return m_part_number_marker; }

  std::vector<Part> GetParts() const { return m_parts; }

  uint64_t GetNextPartNumberMarker() const { return m_next_part_number_marker; }

  std::string GetStorageClass() const { return m_storage_class; }

  uint64_t GetMaxParts() const { return m_max_parts; }

  bool IsTruncated() const { return m_is_truncated; }

 private:
  std::string m_bucket;
  std::string m_encoding_type;
  std::string m_key;
  std::string m_upload_id;
  Initiator m_initiator;
  Owner m_owner;
  uint64_t m_part_number_marker;
  std::vector<Part> m_parts;
  uint64_t m_next_part_number_marker;
  std::string m_storage_class;
  uint64_t m_max_parts;
  bool m_is_truncated;
};

class GetObjectACLResp : public BaseResp {
 public:
  GetObjectACLResp() {}
  virtual ~GetObjectACLResp() {}

  virtual bool ParseFromXmlString(const std::string& body);

  std::string GetOwnerID() const { return m_owner_id; }
  std::string GetOwnerDisplayName() const { return m_owner_display_name; }
  std::vector<Grant> GetAccessControlList() const { return m_acl; }

 private:
  std::string m_owner_id;
  std::string m_owner_display_name;
  std::vector<Grant> m_acl;
};

class PutObjectACLResp : public BaseResp {
 public:
  PutObjectACLResp() {}
  virtual ~PutObjectACLResp() {}
};

class PutObjectCopyResp : public BaseResp {
 public:
  PutObjectCopyResp() {}
  virtual ~PutObjectCopyResp() {}

  virtual bool ParseFromXmlString(const std::string& body);

  std::string GetEtag() const { return m_etag; }
  std::string GetLastModified() const { return m_last_modified; }
  std::string GetVersionId() const { return m_version_id; }
  std::string GetCrc64() const { return m_crc64; }

  /// Server????????
  std::string GetXCosServerSideEncryption() const {
    return GetHeader("x-cos-server-side-encryption");
  }

 private:
  std::string m_etag;
  std::string m_last_modified;
  std::string m_version_id;
  std::string m_crc64;
};

class CopyResp : public BaseResp {
 public:
  CopyResp()
      : m_location(""),
        m_bucket(""),
        m_key(""),
        m_etag(""),
        m_last_modified(""),
        m_version_id(""),
        m_resp_tag("") {}
  virtual ~CopyResp() {}

  void CopyFrom(const PutObjectCopyResp& resp);

  void CopyFrom(const CompleteMultiUploadResp& resp);

  void Clear() {
    m_location = "";
    m_bucket = "";
    m_key = "";
    m_etag = "";
    m_last_modified = "";
    m_version_id = "";
    m_resp_tag = "";
  }

  std::string GetLocation() const { return m_location; }
  std::string GetKey() const { return m_key; }
  std::string GetBucket() const { return m_bucket; }
  std::string GetEtag() const { return m_etag; }
  std::string GetLastModified() const { return m_last_modified; }
  std::string GetVersionId() const { return m_version_id; }
  std::string GetRespTag() { return m_resp_tag; }

 private:
  std::string m_location;  // Object???????
  std::string m_bucket;
  std::string m_key;
  std::string m_etag;
  std::string m_last_modified;
  std::string m_version_id;

  std::string m_resp_tag;  // ????????response
};

class PostObjectRestoreResp : public BaseResp {
 public:
  PostObjectRestoreResp() {}
  ~PostObjectRestoreResp() {}
};

class OptionsObjectResp : public BaseResp {
 public:
  OptionsObjectResp() {}
  ~OptionsObjectResp() {}

  /// \brief ???????????????????????????Header???
  std::string GetAccessControAllowOrigin() const {
    return GetHeader("Access-Control-Allow-Origin");
  }

  /// \brief ??????????? HTTP
  /// ????????????????Header???
  std::string GetAccessControlAllowMethods() const {
    return GetHeader("Access-Control-Allow-Methods");
  }

  /// \brief
  /// ???????????????????????????????Header????????
  std::string GetAccessControlAllowHeaders() const {
    return GetHeader("Access-Control-Allow-Headers");
  }

  /// \brief ??????????? HTTP
  /// ????????????????Header???
  std::string GetAccessControlExposeHeaders() const {
    return GetHeader("Access-Control-Expose-Headers");
  }

  /// \brief ??OPTIONS??????????
  std::string GetAccessControlMaxAge() const {
    return GetHeader("Access-Control-Max-Age");
  }
};

class SelectObjectContentResp : public BaseResp {
 public:
  SelectObjectContentResp() { resp_data.reserve(10); }
  ~SelectObjectContentResp() {}

  /// \brief ???????????
  int WriteResultToLocalFile(const std::string& file);

  bool ParseFromXmlString(const std::string& body);
  // bool ParseFromStringStream(const std::ostringstream& os);

  /// \brief ?????????
  void PrintResult() const;

 private:
  // void ParseStatsEvent(const std::string& stat_str);
  // void ParseProgressEvent(const std::string& prog_str);
  std::vector<SelectMessage> resp_data;
  std::string error_message;
  std::string error_code;
};

class AppendObjectResp : public PutObjectByStreamResp {
 public:
  AppendObjectResp() {}
  ~AppendObjectResp() {}

  /// \brief ???????????????????
  std::string GetNextPosition() const {
    return GetHeader(kRespHeaderXCosNextAppendPosition);
  }

  /// \brief ??????????append???md5
  std::string GetXCosContentSha1() const {
    return GetHeader(kRespHeaderXCosContentSha1);
  }
};

/// \brief: ?????????
class PutLiveChannelResp : public BaseResp {
 public:
  PutLiveChannelResp() {}
  virtual ~PutLiveChannelResp() {}

  virtual bool ParseFromXmlString(const std::string& body);

  const std::string GetPublishUrl() const { return m_publish_url; }

  std::string& GetPublishUrl() { return m_publish_url; }

  std::string GetPlayUrl() const { return m_play_url; }

 private:
  std::string m_publish_url;  // ??url
  std::string m_play_url;     // ??url
};

/// \brief: ?????????????
class PutLiveChannelSwitchResp : public BaseResp {
 public:
  PutLiveChannelSwitchResp() {}
  virtual ~PutLiveChannelSwitchResp() {}
};

/// \brief: ???????????
class GetLiveChannelResp : public BaseResp {
 public:
  GetLiveChannelResp() {}
  virtual ~GetLiveChannelResp() {}
  virtual bool ParseFromXmlString(const std::string& body);
  const LiveChannelConfiguration& GetLiveChannelConf() const {
    return m_chan_conf;
  }

 private:
  LiveChannelConfiguration m_chan_conf;
};

/// \brief: ?????????????
class GetLiveChannelHistoryResp : public BaseResp {
 public:
  GetLiveChannelHistoryResp() {}
  virtual ~GetLiveChannelHistoryResp() {}
  virtual bool ParseFromXmlString(const std::string& body);
  const std::vector<LiveRecord>& GetChanHistory() const { return m_history; }

 private:
  std::vector<LiveRecord> m_history;
};

/// \brief: ?????????????
class GetLiveChannelStatusResp : public BaseResp {
 public:
  GetLiveChannelStatusResp() {}
  virtual ~GetLiveChannelStatusResp() {}
  virtual bool ParseFromXmlString(const std::string& body);
  const LiveChannelStatus& GetLiveChannelStatus() const {
    return m_livechan_status;
  }

 private:
  LiveChannelStatus m_livechan_status;
};

/// \brief: ?????????
class DeleteLiveChannelResp : public BaseResp {
 public:
  DeleteLiveChannelResp() {}
  virtual ~DeleteLiveChannelResp() {}
};

/// \brief: ????????????????????????
class GetLiveChannelVodPlaylistResp : public BaseResp {
 public:
  GetLiveChannelVodPlaylistResp() {}
  virtual ~GetLiveChannelVodPlaylistResp() {}
  int WriteResultToFile(const std::string& file);
};

/// \brief: ???????????????????????
class PostLiveChannelVodPlaylistResp : public BaseResp {
 public:
  PostLiveChannelVodPlaylistResp() {}
  virtual ~PostLiveChannelVodPlaylistResp() {}
};

/* Multithread?? */

class MultiPutObjectResp : public BaseResp {
 public:
  MultiPutObjectResp() {}

  virtual ~MultiPutObjectResp() {}

  virtual bool ParseFromXmlString(const std::string& body);

  std::string GetRespTag() { return m_resp_tag; }

  std::string GetLocation() const { return m_location; }

  std::string GetKey() const { return m_key; }

  std::string GetBucket() const { return m_bucket; }

  void CopyFrom(const InitMultiUploadResp& resp);

  void CopyFrom(const UploadPartDataResp& resp);

  void CopyFrom(const CompleteMultiUploadResp& resp);

  /// \brief Server????????
  std::string GetXCosServerSideEncryption() const {
    return GetHeader("x-cos-server-side-encryption");
  }

 private:
  std::string m_location;  // Object???????
  std::string m_bucket;
  std::string m_key;
  std::string m_upload_id;

  // FIXME(sevenyou) ?????
  std::string m_resp_tag;  // ????????response
};

class MultiGetObjectResp  : public  GetObjectByFileResp {
  public:
  MultiGetObjectResp() {}
  ~MultiGetObjectResp() {}
};

/* Async?? */

//typedef PutObjectByFileResp PutObjectAsyncResp;

//typedef PutObjectByFileResp MultiPutObjectAsyncResp;

//typedef GetObjectByFileResp GetObjectAsyncResp;

//typedef GetObjectByFileResp MultiGetObjectAsyncResp;

class AsyncResp : public BaseResp {
 public:
  AsyncResp() {}
  virtual ~AsyncResp() {}
};

/* ????????? */
class PutObjectsByDirectoryResp {
 public:
  PutObjectsByDirectoryResp() {}
  virtual ~PutObjectsByDirectoryResp() {}

 public:
  class PutResp {
   public:
    PutResp() {}
    virtual ~PutResp() {}
    std::string m_file_name;    // ?????
    std::string m_object_name;  // ???
    BaseResp m_cos_resp;        // cos?????
  };
  // ???????
  std::vector<PutResp> m_succ_put_objs;
};

class PutDirectoryResp : public PutObjectResp {
 public:
  PutDirectoryResp() {}
  virtual ~PutDirectoryResp() {}
};

class MoveObjectResp {
 public:
  MoveObjectResp() {}
  virtual ~MoveObjectResp() {}
};

class DeleteObjectsByPrefixResp {
 public:
  DeleteObjectsByPrefixResp() {}
  virtual ~DeleteObjectsByPrefixResp() {}
  std::vector<std::string> m_succ_del_objs;  // ???????
};

}  // namespace qcloud_cos
#endif  // OBJECT_RESP_H
