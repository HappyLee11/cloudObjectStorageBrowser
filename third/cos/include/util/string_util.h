#ifndef STRING_UTIL_H
#define STRING_UTIL_H

#include <stdint.h>

#include <string>

#include "cos_defines.h"
#include "rapidxml/1.13/rapidxml.hpp"
#include "rapidxml/1.13/rapidxml_print.hpp"
#include "rapidxml/1.13/rapidxml_utils.hpp"

namespace qcloud_cos {

class StringUtil {
 public:
  /**
   * @brief ??string?????
   *
   * @param s: ?????????????????
   *
   * @return ???????????,?s
   */
  static std::string& Trim(std::string& s);

  /**
   * @brief ??string????????
   *
   * @param s: ??????????
   * @param trim_value: ??????
   *
   * @return ??Trim?????
   */
  static std::string Trim(const std::string& s, const std::string& trim_value);

  /**
   * @brief ?xml??string
   *
   * @param xmlObject ????xml??
   *
   * @return ??????string
   */
  static std::string XmlToString(const rapidxml::xml_document<>& xml_doc);

  /**
   * @brief ?string???xml
   *
   * @param xmlStr ????string??
   * @param doc    ????xml??[out]
   *
   * @return ??????true,????false
   */
  static bool StringToXml(char* xml_str, rapidxml::xml_document<>* doc);

  /**
   * @brief ?uint64_t???num???std::string,???8???
   *
   * @param num uint64_t??
   *
   * @return ????string
   */
  static std::string Uint64ToString(uint64_t num);

  /**
   * @brief ?int??string
   *
   * @param num int??
   *
   * @return ????string
   */
  static std::string IntToString(int num);

  /**
   * @brief ?float??string
   *
   * @param num float??
   *
   * @return ????string
   */
  static std::string FloatToString(float num);

  /**
   * @brief ??????????
   *
   * @param s ??string?????
   *
   * @return void
   */
  static void StringToUpper(std::string* s);

  /**
   * @brief ????????
   *
   * @param s string??????
   *
   * @return ??????
   */
  static std::string StringToUpper(const std::string& s);

  /**
   * @brief ??????????
   *
   * @param s ??string?????
   *
   * @return void
   */
  static void StringToLower(std::string* s);

  /**
   * @brief ????????
   *
   * @param s string??????
   *
   * @return ??????
   */
  static std::string StringToLower(const std::string& s);

  /**
   * @brief ?????
   *
   * @param str_vec ???vector
   * @param delimiter ???
   *
   * @return ???
   */
  static std::string JoinStrings(const std::vector<std::string>& str_vec,
                                 const std::string& delimiter);

  /**
   * @brief ?string??uint64_t
   *
   * @param str string??
   *
   * @return ????uint64_t
   */
  static uint64_t StringToUint64(const std::string& str);

  static unsigned StringToUint32(const std::string& str);

  /**
   * @brief ?string??int
   *
   * @param str string??
   *
   * @return ????int
   */
  static int StringToInt(const std::string& str);

  /**
   * @brief ?string??float
   *
   * @param str string??
   *
   * @return ????float
   */
  static float StringToFloat(const std::string& str);
  /**
   * @brief ??????????????
   *
   * @param str string??
   * @param prefix string??
   *
   * @return str????prefix,???true;??,??false
   */
  static bool StringStartsWith(const std::string& str,
                               const std::string& prefix);

  /**
   * @brief ??????????????(?????)
   *
   * @param str string??
   * @param prefix string??
   *
   * @return str????prefix,???true;??,??false
   */
  static bool StringStartsWithIgnoreCase(const std::string& str,
                                         const std::string& prefix);

  /**
   * @brief ????
   *
   * @param str string??
   * @param prefix string??
   *
   * @return ?????prefix??????
   */
  static std::string StringRemovePrefix(const std::string& str,
                                        const std::string& prefix);

  /**
   * @brief ??????????????
   *
   * @param str string??
   * @param suffix string??
   *
   * @return str????suffix,???true;??,??false
   */
  static bool StringEndsWith(const std::string& str, const std::string& suffix);

  /**
   * @brief ??????????????(?????)
   *
   * @param str string??
   * @param suffix string??
   *
   * @return str????suffix,???true;??,??false
   */
  static bool StringEndsWithIgnoreCase(const std::string& str,
                                       const std::string& suffix);

  /**
   * @brief ????
   *
   * @param str string??
   * @param suffix string??
   *
   * @return ?????suffix??????
   */
  static std::string StringRemoveSuffix(const std::string& str,
                                        const std::string& suffix);

  /**
   * @brief ?????
   *
   * @param str string??,??????
   * @param delim char??,???
   * @param vec std::vector??,????
   *
   * @return void
   */
  static void SplitString(const std::string& str, char delim,
                          std::vector<std::string>* vec);

  /**
   * @brief ?????
   *
   * @param str string??,??????
   * @param sep string??,?????
   * @param vec std::vector??,????
   *
   * @return void
   */
  static void SplitString(const std::string& str, const std::string& sep,
                          std::vector<std::string>* vec);

  /**
   * @brief ?HTTP_METHOD??????????
   *
   * @param method HTTP_METHOD
   *
   * @return string
   */
  static std::string HttpMethodToString(HTTP_METHOD method);

  static bool IsV4ETag(const std::string& etag);
  static bool IsMultipartUploadETag(const std::string& etag);

  /**
   * @brief ???????uint32??
   */
  static uint32_t GetUint32FromStrWithBigEndian(const char* str);

  /**
   * @brief ???????uint16??
   */
  static uint16_t GetUint16FromStrWithBigEndian(const char* str);
};
}  // namespace qcloud_cos

#endif
