#ifndef CODEC_UTIL_H
#define CODEC_UTIL_H

#include <stdint.h>

#include <string>

namespace qcloud_cos {

class CodecUtil {
 public:
  /**
   * @brief ???x?????? (x??[0, 15])
   *
   * @param x
   *
   * @return ??????
   */
  static unsigned char ToHex(const unsigned char& x);

  /**
   * @brief ???????????? (x??[0, 15]),??????hex?????
   *
   * @param bin
   *
   * @param binLen
   *
   * @param hex ????????
   *
   * @return ?
   */
  static void BinToHex(const unsigned char* bin, unsigned int binLen,
                       char* hex);

  static std::string EncodeKey(const std::string& key);

  /**
   * @brief ??????URL??
   *
   * @param str   ???????
   *
   * @return  ??URL??????
   */
  static std::string UrlEncode(const std::string& str);

  /**
   * @brief ??????base64??
   *
   * @param plainText  ???????
   *
   * @return ???????
   */
  static std::string Base64Encode(const std::string& plainText);

  /**
   * @brief ??hmacSha1?
   *
   * @param plainText  ??
   * @param key        ??
   *
   * @return ???hmacsha1?
   */
  static std::string HmacSha1(const std::string& plainText,
                              const std::string& key);

  /**
   * @brief ??hmacSha1?16???
   *
   * @param plainText  ??
   * @param key        ??
   *
   * @return ???hmacsha1?16???
   */
  static std::string HmacSha1Hex(const std::string& plainText,
                                 const std::string& key);

  static std::string RawMd5(const std::string& plainText);

  static std::string RawMd51(const std::string& plainText);

  static std::string HexToBin(const std::string& strHex);
};

}  // namespace qcloud_cos
#endif
