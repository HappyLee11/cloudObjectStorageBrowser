#ifndef UTIL_AUTHTOOl_H
#define UTIL_AUTHTOOl_H

#include <stdint.h>

#include <map>
#include <string>
#include <vector>
#include <unordered_set>
#include "request/base_req.h"
#include "util/noncopyable.h"

namespace qcloud_cos {

class AuthTool : private NonCopyable {
 public:
  /// \brief ???????????????(??CosSysConfig??, ??60s)??
  ///
  /// \param secret_id   ???????????? ID???????
  /// \param secret_key  ????????????
  /// \param http_method http??,?POST/GET/HEAD/PUT?, ????????
  /// \param in_uri      http uri
  /// \param headers     http header????
  /// \param params      http params????
  ///
  /// \return ?????????????????
  static std::string Sign(const std::string& secret_id,
                          const std::string& secret_key,
                          const std::string& http_method,
                          const std::string& in_uri,
                          const std::map<std::string, std::string>& headers,
                          const std::map<std::string, std::string>& params,
                          const std::unordered_set<std::string>& not_sign_headers);

  /// \brief ?????????????????
  ///
  /// \param secret_id   ???????????? ID???????
  /// \param secret_key  ????????????
  /// \param http_method http??,?POST/GET/HEAD/PUT?, ????????
  /// \param in_uri      http uri
  /// \param headers     http header????
  /// \param params      http params????
  ///
  /// \return ?????????????????
  static std::string Sign(const std::string& secret_id,
                          const std::string& secret_key,
                          const std::string& http_method,
                          const std::string& in_uri,
                          const std::map<std::string, std::string>& headers,
                          const std::map<std::string, std::string>& params,
                          uint64_t start_time_in_s, uint64_t end_time_in_s,
                          const std::unordered_set<std::string>& not_sign_headers);

  /// \brief get rtmp signature
  static std::string RtmpSign(const std::string& secret_id,
                              const std::string& secret_key,
                              const std::string& token,
                              const std::string& bucket,
                              const std::string& channel,
                              const std::map<std::string, std::string>& params,
                              uint64_t expire);

 private:
  /// \brief ?params???????????,key??param_list
  /// key=value?param_value_list \param params ?? \param key_encode
  /// key????uri?? \param value_encode value????uri?? \param
  /// value_lower value???? \param param_list ???????;?? \param
  /// param_value_list ???????,?&?? \retval     ?
  static void FillMap(const std::map<std::string, std::string>& params,
                      bool key_encode, bool value_encode, bool value_lower,
                      std::string* param_list, std::string* param_value_list);

  /// \brief ?????????????,??host conent-type ??x???????
  /// \param hedaers ???kv?
  /// \param filted_req_headers ???????
  /// \retval ?
  static void FilterAndSetSignHeader(
      const std::map<std::string, std::string>& headers,
      std::map<std::string, std::string>* filted_req_headers,
      const std::unordered_set<std::string>& not_sign_headers);
};

}  // namespace qcloud_cos

#endif  // AUTHTOOL_H
