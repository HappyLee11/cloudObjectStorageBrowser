#pragma once

#include <inttypes.h>
#include <stdint.h>

#include <map>
#include <string>

#include "cos_config.h"
#include "op/cos_result.h"
#include "trsf/transfer_handler.h"

namespace qcloud_cos {

class BaseReq;
class BaseResp;

class BaseOp {
 public:
  /// \brief BaseOp????
  ///
  /// \param cos_conf Cos??
  explicit BaseOp(const SharedConfig& cos_conf) : m_config(cos_conf) {}

  BaseOp() {}

  /// \brief BaseOp????
  ~BaseOp() {}

  /// \brief ??Cos??
  CosConfig GetCosConfig() const;

  /// \brief ??AppID
  uint64_t GetAppId() const;

  /// \brief ??Region
  std::string GetRegion() const;

  /// \brief ??AccessKey
  std::string GetAccessKey() const;

  /// \brief ??SecretKey
  std::string GetSecretKey() const;

  /// \brief ??Token
  std::string GetTmpToken() const;

  std::string GetDestDomain() const;
  
  bool IsDomainSameToHost() const;

  /// \brief ???cos Service/Bucket/Object ?????????,
  ///        ???????????????????
  ///
  /// \param host     ????, ?http://??
  /// \param path     http path
  /// \param req      http??
  /// \param req_body http request?body
  /// \param resp     http??
  ///
  /// \return http????(????)
  CosResult NormalAction(const std::string& host, const std::string& path,
                         const BaseReq& req, const std::string& req_body,
                         bool check_body, BaseResp* resp);

  /// \brief ???cos Service/Bucket/Object?????????,
  ///        ???????????????????
  ///
  /// \param host     ????, ?http://??
  /// \param path     http path
  /// \param req      http??
  /// \param additional_headers http?????????header
  /// \param additional_params  http?????????params
  /// \param req_body http request?body
  /// \param resp     http??
  ///
  /// \return http????(????)
  CosResult NormalAction(
      const std::string& host, const std::string& path, const BaseReq& req,
      const std::map<std::string, std::string>& additional_headers,
      const std::map<std::string, std::string>& additional_params,
      const std::string& req_body, bool check_body, BaseResp* resp);

  /// \brief ??????????
  ///
  /// \param host     ????, ?http://??
  /// \param path     http path
  /// \param req      http??
  /// \param resp     http??
  /// \param os       ???
  ///
  /// \return http????(????)
  CosResult DownloadAction(const std::string& host, const std::string& path,
                           const BaseReq& req, BaseResp* resp, std::ostream& os,
                           const SharedTransferHandler& handler = nullptr);

  /// \brief ???stream????????
  ///
  /// \param host     ????, ?http://??
  /// \param path     http path
  /// \param req      http??
  /// \param additional_headers http?????????header
  /// \param additional_params  http?????????params
  /// \param is       http request?body
  /// \param resp     http??
  ///
  /// \return http????(????)
  CosResult UploadAction(
      const std::string& host, const std::string& path, const BaseReq& req,
      const std::map<std::string, std::string>& additional_headers,
      const std::map<std::string, std::string>& additional_params,
      std::istream& is, BaseResp* resp, const SharedTransferHandler& handler = nullptr);

  std::string GetRealUrl(const std::string& host, const std::string& path,
                         bool is_https);

 protected:
  bool CheckConfigValidation() const;
  SharedConfig m_config;
};

}  // namespace qcloud_cos
