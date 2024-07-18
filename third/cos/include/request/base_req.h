// Copyright (c) 2017, Tencent Inc.
// All rights reserved.
//
// Author: sevenyou <sevenyou@tencent.com>
// Created: 07/15/17
// Description:
#pragma once

#include <stdint.h>

#include <map>
#include <string>

#include "util/string_util.h"

namespace qcloud_cos {

/// \brief ??Http??
class BaseReq {
 public:
  typedef std::map<std::string, std::string> Str2StrMap;

 public:
  BaseReq();
  virtual ~BaseReq() {}

  /// \brief ??????
  void AddHeader(const std::string& key, const std::string& value);
  void AddHeaders(const Str2StrMap& user_headers);

  /// \brief ??????
  std::string GetHeader(const std::string& key) const;
  const Str2StrMap& GetHeaders() const { return m_headers_map; }

  /// \brief ??????
  void ClearHeaders() { m_headers_map.clear(); }

  /// \brief ??????
  void AddParam(const std::string& key, const std::string& value);
  void AddParams(const Str2StrMap& user_params);

  /// \brief ??????
  std::string GetParam(const std::string& key) const;
  const Str2StrMap& GetParams() const { return m_params_map; };

  /// \brief ??????
  void ClearParams() { m_params_map.clear(); }

  /// \brief ?????http??
  std::string GetMethod() const { return m_method; }

  /// \brief ?????http??
  void SetMethod(const std::string& method) {
    m_method = StringUtil::StringToUpper(method);
  }

  /// \brief ?????body
  std::string GetBody() const { return m_body; }

  /// \brief ?????body
  void SetBody(const std::string& body) { m_body = body; }

  /// \brief ??Path
  std::string GetPath() const { return m_path; }

  /// \brief ??Path
  void SetPath(const std::string& path) { m_path = path; }

  void SetConnTimeoutInms(uint64_t conn_timeout_in_ms) {
    m_conn_timeout_in_ms = conn_timeout_in_ms;
  }

  uint64_t GetConnTimeoutInms() const { return m_conn_timeout_in_ms; }

  void SetRecvTimeoutInms(uint64_t recv_timeout_in_ms) {
    m_recv_timeout_in_ms = recv_timeout_in_ms;
  }

  uint64_t GetRecvTimeoutInms() const { return m_recv_timeout_in_ms; }

  /// \brief ??????????https
  void SetHttps() { m_is_https = true; }
  bool IsHttps() const { return m_is_https; }

  /// \brief set whether check content md5 each request, used for close range
  /// download check
  void SetCheckMD5(bool check_md5) { mb_check_md5 = check_md5; }
  bool CheckMD5() const { return mb_check_md5; }

  void SetCheckCRC64(bool check_crc64) { mb_check_crc64 = check_crc64; }
  bool CheckCRC64() const { return mb_check_crc64; }

  void SetCaLocation(const std::string& ca_location) { m_ca_location = ca_location; }
  const std::string& GetCaLocation() const { return m_ca_location; }

  void SetVerifyCert(bool verify_cert) { mb_verify_cert = verify_cert; }
  bool GetVerifyCert() const { return mb_verify_cert; }

  /// \brief ?????header?param??
  std::string DebugString() const;

  /// \brief ?????header host
  /// ???host????????true??????????host?
  /// ??????????????
  void SetSignHeaderHost(bool sign_header_host) {
    m_sign_header_host = sign_header_host;
  }
  bool SignHeaderHost() const { return m_sign_header_host; }

 protected:
  // acl???????PutObjectACL?PutBucketACL??
  bool GenerateAclRequestBody(const Owner& owner, const std::vector<Grant>& acl,
                              std::string* body) const;

 protected:
  Str2StrMap m_headers_map;
  Str2StrMap m_params_map;
  std::string m_path;
  std::string m_method;
  std::string m_body;

  uint64_t m_conn_timeout_in_ms;
  uint64_t m_recv_timeout_in_ms;
  bool m_is_https;
  bool mb_check_md5;    // default is true
  bool mb_check_crc64;  // default is false

  bool mb_verify_cert;  // default is true
  bool m_sign_header_host;  // ???header host????
  std::string m_ca_location;
};

}  // namespace qcloud_cos
