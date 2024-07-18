#pragma once

#include <sstream>
#include <string>
#include <vector>

#include "Poco/Dynamic/Struct.h"
#include "Poco/JSON/Object.h"
#include "request/bucket_req.h"
#include "request/object_req.h"

namespace qcloud_cos {

class Location {
 public:
  Location() : m_mask(0x00000000u) {}
  virtual ~Location() {}

  void SetX(const float x) {
    m_mask |= 0x00000001u;
    m_x = x;
  }

  void SetY(const float y) {
    m_mask |= 0x00000002u;
    m_y = y;
  }

  void SetWidth(const float width) {
    m_mask |= 0x00000004u;
    m_width = width;
  }

  void SetHeight(const float height) {
    m_mask |= 0x00000008u;
    m_height = height;
  }

  void SetRotate(const float rotate) {
    m_mask |= 0x00000010u;
    m_rotate = rotate;
  }

  float GetX() const { return m_x; }

  float GetY() const { return m_y; }

  float GetWidth() const { return m_width; }

  float GetHeight() const { return m_height; }

  float GetRotate() const { return m_rotate; }

  bool HasX() const { return (m_mask & 0x00000001u) != 0; }

  bool HasY() const { return (m_mask & 0x00000002u) != 0; }

  bool HasWidth() const { return (m_mask & 0x00000004u) != 0; }

  bool HasHeight() const { return (m_mask & 0x00000008u) != 0; }

  bool HasRotate() const { return (m_mask & 0x00000010u) != 0; }

  std::string to_string() const {
    std::stringstream ss;
    if (HasX()) { ss << " x: " << std::to_string(m_x); }
    if (HasY()) { ss << " y: " << std::to_string(m_y); }
    if (HasWidth()) { ss << " width: " << std::to_string(m_width); }
    if (HasHeight()) { ss << " height: " << std::to_string(m_height); }
    if (HasRotate()) { ss << " rotate: " << std::to_string(m_rotate); }
    return ss.str();
  }

 private:
  uint64_t m_mask;
  float m_x;                 // ????????????????????x?????????????????????????????
  float m_y;                 // ????????????????????y?????????????????????????????
  float m_width;             // ????????????????????? x ??????????????????????????????
  float m_height;            // ????????????????????? y ??????????????????????????????
  float m_rotate;            // ????????????????????? X ? Y ???????????????????????0-360??????????????

};

class OcrResult {
 public:
  OcrResult() : m_mask(0x00000000u) {}
  virtual ~OcrResult() {}

  void SetText(const std::string& text) {
    m_mask |= 0x00000001u;
    m_text = text;
  }

  void SetKeyWords(const std::vector<std::string>& key_words) {
    m_mask |= 0x00000002u;
    m_key_words = key_words;
  }

  void AddKeyWord(const std::string& key_word) {
    m_mask |= 0x00000002u;
    m_key_words.push_back(key_word);
  }

  void SetLocation(const Location& location) {
    m_mask |= 0x00000004u;
    m_location = location;
  }

  std::string GetText() const { return m_text; }

  std::vector<std::string> GetKeyWords() const { return m_key_words; }

  Location GetLocation() const { return m_location; }

  bool HasText() const { return (m_mask & 0x00000001u) != 0; }

  bool HasKeyWords() const { return (m_mask & 0x00000002u) != 0; }

  bool HasLocation() const { return (m_mask & 0x00000004u) != 0; }

  std::string to_string() const {
    std::stringstream ss;
    if (HasText()) {
      ss << " text: " << m_text;
    }
    if (HasKeyWords()) {
      for (std::vector<std::string>::const_iterator it = m_key_words.begin();
           it != m_key_words.end(); ++it) {
        if (it == m_key_words.begin()) {
          ss << " keywords: " << it->c_str();
          continue;
        }
        ss << "," << it->c_str();
      }
    }
    if (HasLocation()) {
      ss << " Location: " << m_location.to_string();
    }
    return ss.str();
  }

 private:
  uint64_t m_mask;
  std::string m_text;                   // ?? OCR ????????????
  std::vector<std::string> m_key_words; // ??????????????
  Location m_location;                  // ??????? OCR ?????????????? xy ????????????????????????????

};

class ObjectResults {
 public:
  ObjectResults() : m_mask(0x00000000u) {}
  virtual ~ObjectResults() {}

  void SetName(const std::string& name) {
    m_mask |= 0x00000001u;
    m_name = name;
  }

  void SetLocation(const Location& location) {
    m_mask |= 0x00000002u;
    m_location = location;
  }

  std::string GetName() const { return m_name; }

  Location GetLocation() const { return m_location; }

  bool HasName() const { return (m_mask & 0x00000001u) != 0; }
   
  bool HasLocation() const { return (m_mask & 0x00000002u) != 0; }

  std::string to_string() const { 
    std::stringstream ss;
    if (HasName()) {
      ss << " name: " << m_name;
    }
    if (HasLocation()) {
      ss << " location: " << m_location.to_string();
    }
    return ss.str();
  }
 private:
  uint64_t m_mask;
  std::string m_name;               // ????????
  Location m_location;              // ?????????????
};

class SceneResultInfo {
 public:
  SceneResultInfo() : m_mask(0x00000000u) {}
  virtual ~SceneResultInfo() {}

  void SetCode(const int code) {
    m_mask |= 0x00000001u;
    m_code = code;
  }

  void SetMsg(const std::string &msg) {
    m_mask |= 0x00000002u;
    m_msg = msg;
  }

  void SetHitFlag(const int hit_flag) {
    m_mask |= 0x00000004u;
    m_hit_flag = hit_flag;
  }

  void SetScore(const int score) {
    m_mask |= 0x00000008u;
    m_score = score;
  }

  void SetLabel(const std::string& label) {
    m_mask |= 0x00000010u;
    m_label = label;
  }

  void SetCategory(const std::string& category) {
    m_mask |= 0x00000020u;
    m_category = category;
  }

  void SetSubLabel(const std::string& sub_label) {
    m_mask |= 0x00000040u;
    m_sub_label = sub_label;
  }

  void SetCount(const int count) {
    m_mask |= 0x00000080u;
    m_count = count;
  }

  void SetOcrResults(const std::vector<OcrResult>& ocr_results) {
    m_mask |= 0x00000100u;
    m_ocr_results = ocr_results;
  }

  void AddOcrResults(const OcrResult& ocr_results) {
    m_mask |= 0x00000100u;
    m_ocr_results.push_back(ocr_results);
  }

  void SetObjectResults(const ObjectResults& object_results) {
    m_mask |= 0x00000200u;
    m_object_results = object_results;
  }

  void SetKeyWords(const std::vector<std::string>& key_words) {
    m_mask |= 0x00000400u;
    m_key_words = key_words;
  }

  void AddKeyWord(const std::string& key_word) {
    m_mask |= 0x00000400u;
    m_key_words.push_back(key_word);
  }

  int GetCode() const { return m_code; }

  int GetHitFlag() const { return m_hit_flag; }

  std::string GetMsg() const { return m_msg; }

  int GetScore() const { return m_score; }

  std::string GetLabel() const { return m_label; }

  std::string GetCategory() const { return m_category; }

  std::string GetSubLabel() const { return m_sub_label; }

  int GetCount() const { return m_count; }

  std::vector<OcrResult> GetOcrResults() const { return m_ocr_results; }

  ObjectResults GetObjectResults() const { return m_object_results; }

  std::vector<std::string> GetKeyWords() const { return m_key_words; }

  bool HasCode() const { return (m_mask & 0x00000001u) != 0; }

  bool HasMsg() const { return (m_mask & 0x00000002u) != 0; }

  bool HasHitFlag() const { return (m_mask & 0x00000004u) != 0; }

  bool HasScore() const { return (m_mask & 0x00000008u) != 0; }

  bool HasLabel() const { return (m_mask & 0x00000010u) != 0; }

  bool HasCategory() const { return (m_mask & 0x00000020u) != 0; }

  bool HasSubLabel() const { return (m_mask & 0x00000040u) != 0; }

  bool HasCount() const { return (m_mask & 0x00000080u) != 0; }

  bool HasOcrResults() const { return (m_mask & 0x00000100u) != 0; }

  bool HasObjectresults() const { return (m_mask & 0x00000200u) != 0; }

  bool HasKeyWords() const { return (m_mask & 0x00000400u) != 0; }

  std::string to_string() const {
    std::stringstream ss;
    if (HasCode()) { ss << " code: " << std::to_string(m_code); }
    if (HasMsg()) { ss << " msg: " << m_msg; }
    if (HasHitFlag()) { ss << " hit_flag: " << std::to_string(m_hit_flag); }
    if (HasScore()) { ss << " score: " << std::to_string(m_score); }
    if (HasLabel()) { ss << " label: " << m_label; }
    if (HasCategory()) { ss << " category: " << m_category; }
    if (HasSubLabel()) { ss << " sub_label: " << m_sub_label; }
    if (HasCount()) { ss << " count: " << m_count; }
    if (HasOcrResults()) {
      for (std::vector<OcrResult>::const_iterator it = m_ocr_results.begin();
           it != m_ocr_results.end(); ++it) {
        ss << " ocr_result: {" << it->to_string() << "}";
      }
    }
    if (HasObjectresults()) { ss << " object_result: {" << m_object_results.to_string() << "}"; }
    if (HasKeyWords()) {
      for (std::vector<std::string>::const_iterator it = m_key_words.begin();
           it != m_key_words.end(); ++it) {
        if (it == m_key_words.begin()) {
          ss << " keywords: " << it->c_str();
          continue;
        }
        ss << "," << it->c_str();
      }
    }
    return ss.str();
  }

 private:
  uint64_t m_mask;
  int m_code;                       // ???????????0?????????
  std::string m_msg;                // ???????????OK
  int m_hit_flag;                   // ??????????0??????1?????2????
  int m_score;                      // ?????????????????????????0???????-100?????????????????????????????
                                    // ??0 - 60????????61 - 90??????????91 - 100?????????
  std::string m_label;              // ??????????????????? SubLabel??????????
  std::string m_category;           // ????Label???????????????????? Sexy?????????????
  std::string m_sub_label;          // ???????????????????Porn ?? SexBehavior ???? ????????????
  int m_count;                      // ???????????
  std::vector<OcrResult> m_ocr_results;          // OCR ?????????????????????????????????????????
  ObjectResults m_object_results;   // ????????????????????????????
  std::vector<std::string> m_key_words; // ?????????????


};

class UserInfo {
 public:
  UserInfo(): m_mask(0x00000000u) {}
  virtual ~UserInfo() {}

  void SetTokenId(const std::string& token_id) {
    m_mask |= 0x00000001u;
    m_token_id = token_id;
  }

  void SetNickName(const std::string& nick_name) {
    m_mask |= 0x00000002u;
    m_nick_name = nick_name;
  }

  void SetDeviceId(const std::string& device_id) {
    m_mask |= 0x00000004u;
    m_device_id = device_id;
  }

  void SetAppId(const std::string& app_id) {
    m_mask |= 0x00000008u;
    m_app_id = app_id;
  }

  void SetRoom(const std::string& room) {
    m_mask |= 0x00000010u;
    m_room = room;
  }

  void SetIp(const std::string& ip) {
    m_mask |= 0x00000020u;
    m_ip = ip;
  }

  void SetType(const std::string& type) {
    m_mask |= 0x00000040u;
    m_type = type;
  }

  std::string GetTokenId() const { return m_token_id; }

  std::string GetNickName() const { return m_nick_name; }

  std::string GetDeviceId() const { return m_device_id; }

  std::string GetAppId() const { return m_app_id; }

  std::string GetRoom() const { return m_device_id; }

  std::string GetIp() const { return m_ip; }

  std::string GetType() const { return m_type; }

  bool HasTokenId() const { return (m_mask & 0x00000001u) != 0; }

  bool HasNickName() const { return (m_mask & 0x00000002u) != 0; }

  bool HasDeviceId() const { return (m_mask & 0x00000004u) != 0; }

  bool HasAppId() const { return (m_mask & 0x00000008u) != 0; }

  bool HasRoom() const { return (m_mask & 0x00000010u) != 0; }

  bool HasIp() const { return (m_mask & 0x00000020u) != 0; }

  bool HasType() const { return (m_mask & 0x00000040u) != 0; }

  std::string to_string() const {
    std::stringstream ss;
    if (HasTokenId()) { ss << " token_id: " << m_token_id; }
    if (HasNickName()) { ss << " nick_name: " << m_nick_name; }
    if (HasDeviceId()) { ss << " device_id: " << m_device_id; }
    if (HasAppId()) { ss << " app_id: " << m_app_id; }
    if (HasRoom()) { ss << " room: " << m_room; }
    if (HasIp()) { ss << " ip: " << m_ip; }
    if (HasType()) { ss << " type: " << m_type; }
    return ss.str();
  }

 private:
  uint64_t m_mask;
  std::string m_token_id;     // ???? TokenId??????128??
  std::string m_nick_name;    // ???? Nickname??????128??
  std::string m_device_id;    // ???? DeviceId??????128??
  std::string m_app_id;       // ???? AppId??????128??
  std::string m_room;         // ???? room??????128??
  std::string m_ip;           // ???? IP??????128??
  std::string m_type;         // ???? type??????128??

};

class SegmentResult {
 public:
  SegmentResult() : m_mask(0x00000000) {}
  virtual ~SegmentResult() {}

  void SetUrl(const std::string &url) {
    m_mask |= 0x00000001u;
    m_url = url;
  }

  void SetSnapShotTime(int snap_shot_time) {
    m_mask |= 0x00000002u;
    m_snap_shot_time = snap_shot_time;
  }

  void SetOffsetTime(int offset_time) {
    m_mask |= 0x00000004u;
    m_offset_time = offset_time;
  }

  void SetDuration(int duration) {
    m_mask |= 0x00000008u;
    m_duration = duration;
  }

  void SetText(const std::string& text) {
    m_mask |= 0x00000010u;
    m_text = text;
  }

  void SetLabel(const std::string& label) {
    m_mask |= 0x00000020u;
    m_label = label;
  }

  void SetResult(int result) {
    m_mask |= 0x00000040u;
    m_result = result;
  }

  void SetPornInfo(const SceneResultInfo& porn_info) {
    m_mask |= 0x00000080u;
    m_porn_info = porn_info;
  }

  void SetAdsInfo(const SceneResultInfo& ads_info) {
    m_mask |= 0x00000100u;
    m_ads_info = ads_info;
  }

  void SetIllegalInfo(const SceneResultInfo& illegal_info) {
    m_mask |= 0x00000200u;
    m_illegal_info = illegal_info;
  }

  void SetAbuseInfo(const SceneResultInfo& abuse_info) {
    m_mask |= 0x00000400u;
    m_abuse_info = abuse_info;
  }

  void SetPoliticsInfo(const SceneResultInfo& politics_info) {
    m_mask |= 0x00000800u;
    m_politics_info = politics_info;
  }

  void SetTerrorismInfo(const SceneResultInfo& terrorism_info) {
    m_mask |= 0x00001000u;
    m_terrorism_info = terrorism_info;
  }

  void SetStartByte(int start_byte) {
    m_mask |= 0x00002000u;
    m_start_byte = start_byte;
  }

  const std::string& GetUrl() const { return m_url; }

  int GetSnapShotTime() const { return m_snap_shot_time; }

  int GetOffsetTime() const { return m_offset_time; }

  int GetDuration() const { return m_duration; }

  const std::string& GetText() const { return m_text; }

  const std::string& GetLabel() const { return m_label; }

  int GetResult() const { return m_result; }

  const SceneResultInfo& GetPornInfo() const { return m_porn_info; }

  const SceneResultInfo& GetAdsInfo() const { return m_ads_info; }

  const SceneResultInfo& GetIllegalInfo() const { return m_illegal_info; }

  const SceneResultInfo& GetAbuseInfo() const { return m_abuse_info; }

  const SceneResultInfo& GetPoliticsInfo() const { return m_politics_info; }

  const SceneResultInfo& GetTerrorismInfo() const { return m_terrorism_info; }

  int GetStartByte() const { return m_start_byte; }

  bool HasUrl() const { return (m_mask & 0x00000001) != 0; }

  bool HasSnapShotTime() const { return (m_mask & 0x00000002) != 0; }

  bool HasOffsetTime() const { return (m_mask & 0x00000004) != 0; }

  bool HasDuration() const { return (m_mask & 0x00000008) != 0; }

  bool HasText() const { return (m_mask & 0x00000010) != 0; }

  bool HasLabel() const { return (m_mask & 0x00000020) != 0; }

  bool HasResult() const { return (m_mask & 0x00000040) != 0; }

  bool HasPornInfo() const { return (m_mask & 0x00000080) != 0; }

  bool HasAdsInfo() const { return (m_mask & 0x00000100) != 0; }

  bool HasIllegalInfo() const { return (m_mask & 0x00000200) != 0; }

  bool HasAbuseInfo() const { return (m_mask & 0x00000400) != 0; }

  bool HasPoliticsInfo() const { return (m_mask & 0x00000800) != 0; }

  bool HasTerrorismInfo() const { return (m_mask & 0x00001000) != 0; }

  bool HasStartByte() const { return (m_mask & 0x00002000) != 0; }

  std::string to_string() const {
    std::stringstream ss;
    if (HasUrl()) { ss << " url: " << m_url; }
    if (HasSnapShotTime()) { ss << " snap_shot_time: " << m_snap_shot_time; }
    if (HasOffsetTime()) { ss << " offset_time: " << std::to_string(m_offset_time); }
    if (HasDuration()) { ss << " duration: " << m_duration; }
    if (HasText()) { ss << " text: " << m_text; }
    if (HasLabel()) { ss << " label: " << m_label; }
    if (HasResult()) { ss << " result: " << m_result; }
    if (HasStartByte()) { ss << " start_type: " << std::to_string(m_start_byte); }
    if (HasPornInfo()) { ss << " porn_info: {" << m_porn_info.to_string() << "}";  }
    if (HasAdsInfo()) { ss << " ads_info: {" << m_ads_info.to_string() << "}"; }
    if (HasIllegalInfo()) { ss << " illegal_info: {" << m_illegal_info.to_string() << "}"; }
    if (HasAbuseInfo()) { ss << " abuse_info: {" << m_abuse_info.to_string() << "}"; }
    if (HasPoliticsInfo()) { ss << " politics_info: {" << m_politics_info.to_string() << "}"; }
    if (HasTerrorismInfo()) { ss << " terrorism_info: {" << m_terrorism_info.to_string() << "}"; }
    return ss.str();
  }

 private:
  uint64_t m_mask;
  std::string m_url;                  // ??/?????????
  int m_snap_shot_time;               // ???????????????
  int m_offset_time;                  // ????????????????????
  int m_duration;                     // ??????????????
  std::string m_text;                 // ??????
  std::string m_label;                // ???????????????
  int m_result;                       // ?????0???????1 ????????????2?????????????
  SceneResultInfo m_porn_info;        // ??????????????
  SceneResultInfo m_ads_info;         // ????????????????
  SceneResultInfo m_illegal_info;     // ??????????????
  SceneResultInfo m_abuse_info;       // ??????????????
  SceneResultInfo m_politics_info;    // ??????????????
  SceneResultInfo m_terrorism_info;   // ??????????????
  int m_start_byte;                   // ???????????????
};

class Labels {
 public:
  Labels() : m_mask(0x00000000) {}
  virtual ~Labels() {}

  void SetPornInfo(const SceneResultInfo& porn_info) {
    m_mask |= 0x00000001u;
    m_porn_info = porn_info;
  }

  void SetAdsInfo(const SceneResultInfo& ads_info) {
    m_mask |= 0x00000002u;
    m_ads_info = ads_info;
  }

  void SetIllegalInfo(const SceneResultInfo& illegal_info) {
    m_mask |= 0x00000004u;
    m_illegal_info = illegal_info;
  }

  void SetAbuseInfo(const SceneResultInfo& abuse_info) {
    m_mask |= 0x00000008u;
    m_abuse_info = abuse_info;
  }

  void SetPoliticsInfo(const SceneResultInfo& politics_info) {
    m_mask |= 0x00000010u;
    m_politics_info = politics_info;
  }

  void SetTerrorismInfo(const SceneResultInfo& terrorism_info) {
    m_mask |= 0x00000020u;
    m_terrorism_info = terrorism_info;
  }
  
  const SceneResultInfo& GetPornInfo() const { return m_porn_info; }
  
  const SceneResultInfo& GetAdsInfo() const { return m_ads_info; }

  const SceneResultInfo& GetIllegalInfo() const { return m_illegal_info; }

  const SceneResultInfo& GetAbuseInfo() const { return m_abuse_info; }

  const SceneResultInfo& GetPoliticsInfo() const { return m_politics_info; }

  const SceneResultInfo& GetTerrorismInfo() const { return m_terrorism_info; }
  
  bool HasPornInfo() const { return (m_mask & 0x00000001u) != 0; }
  
  bool HasAdsInfo() const { return (m_mask & 0x00000002u) != 0; }

  bool HasIllegalInfo() const { return (m_mask & 0x00000004u) != 0; }

  bool HasAbuseInfo() const { return (m_mask & 0x00000008u) != 0; }

  bool HasPoliticsInfo() const { return (m_mask & 0x00000010u) != 0; }

  bool HasTerrorismInfo() const { return (m_mask & 0x00000020u) != 0; }
  
  std::string to_string() const {
    std::stringstream ss;
    if (HasPornInfo()) { ss << " porn_info: {" << m_porn_info.to_string() << "}";  }
    if (HasAdsInfo()) { ss << " ads_info: {" << m_ads_info.to_string() << "}"; }
    if (HasIllegalInfo()) { ss << " illegal_info: {" << m_illegal_info.to_string() << "}"; }
    if (HasAbuseInfo()) { ss << " abuse_info: {" << m_abuse_info.to_string() << "}"; }
    if (HasPoliticsInfo()) { ss << " politics_info: {" << m_politics_info.to_string() << "}"; }
    if (HasTerrorismInfo()) { ss << " terrorism_info: {" << m_terrorism_info.to_string() << "}"; }
    return ss.str();
  }
  
  private:
  uint64_t m_mask;
  SceneResultInfo m_porn_info;        // ??????????????
  SceneResultInfo m_ads_info;         // ????????????????
  SceneResultInfo m_illegal_info;     // ??????????????
  SceneResultInfo m_abuse_info;       // ??????????????
  SceneResultInfo m_politics_info;    // ??????????????
  SceneResultInfo m_terrorism_info;   // ??????????????

};

class Result {
  public:
  Result() : m_mask(0x00000000) {}
  virtual ~Result() {}

  void SetUrl(const std::string& url) {
    m_mask |= 0x00000001u;
    m_url = url;
  }

  void SetPageNumber(const int page_number) {
    m_mask |= 0x00000002u;
    m_page_number = page_number;
  }

  void SetSheetNumber(const int sheet_number) {
    m_mask |= 0x00000004u;
    m_sheet_number = sheet_number;
  }
  
  void SetText(const std::string& text) {
    m_mask |= 0x00000008u;
    m_text = text;
  }
  
  void SetLabel(const std::string& label) {
    m_mask |= 0x00000010u;
    m_label = label;
  }
  
  void SetSuggestion(const int suggestion) {
    m_mask |= 0x00000020u;
    m_suggestion = suggestion;
  }

  void SetPornInfo(const SceneResultInfo& porn_info) {
    m_mask |= 0x00000040u;
    m_porn_info = porn_info;
  }
  
  void SetAdsInfo(const SceneResultInfo& ads_info) {
    m_mask |= 0x00000080u;
    m_ads_info = ads_info;
  }

  void SetIllegalInfo(const SceneResultInfo& illegal_info) {
    m_mask |= 0x00000100u;
    m_illegal_info = illegal_info;
  }

  void SetAbuseInfo(const SceneResultInfo& abuse_info) {
    m_mask |= 0x00000200u;
    m_abuse_info = abuse_info;
  }

  void SetPoliticsInfo(const SceneResultInfo& politics_info) {
    m_mask |= 0x00000400u;
    m_politics_info = politics_info;
  }

  void SetTerrorismInfo(const SceneResultInfo& terrorism_info) {
    m_mask |= 0x00000800u;
    m_terrorism_info = terrorism_info;
  }

  int SetPageNumber() const { return m_page_number; }

  int SetSheetNumber() const { return m_sheet_number; }
  
  const std::string& SetText() const { return m_text; }
  
  const std::string& SetLabel() const { return m_label; }
  
  int SetSuggestion() const { return m_suggestion; }

  const SceneResultInfo& GetPornInfo() const { return m_porn_info; }

  const SceneResultInfo& GetAdsInfo() const { return m_ads_info; }

  const SceneResultInfo& GetIllegalInfo() const { return m_illegal_info; }

  const SceneResultInfo& GetAbuseInfo() const { return m_abuse_info; }

  const SceneResultInfo& GetPoliticsInfo() const { return m_politics_info; }

  const SceneResultInfo& GetTerrorismInfo() const { return m_terrorism_info; }

  bool HasUrl() const { return (m_mask & 0x00000001u) != 0; }

  bool HasPageNumber() const { return (m_mask & 0x00000002u) != 0; }

  bool HasSheetNumber() const { return (m_mask & 0x00000004u) != 0; }

  bool HasText() const { return (m_mask & 0x00000008u) != 0; }

  bool HasLabel() const { return (m_mask & 0x00000010u) != 0; }

  bool HasSuggestion() const { return (m_mask & 0x00000020u) != 0; }

  bool HasPornInfo() const { return (m_mask & 0x00000040u) != 0; }

  bool HasAdsInfo() const { return (m_mask & 0x00000080u) != 0; }

  bool HasIllegalInfo() const { return (m_mask & 0x00000100u) != 0; }

  bool HasAbuseInfo() const { return (m_mask & 0x00000200u) != 0; }

  bool HasPoliticsInfo() const { return (m_mask & 0x00000400u) != 0; }

  bool HasTerrorismInfo() const { return (m_mask & 0x00000800u) != 0; }

  std::string to_string() const {
    std::stringstream ss;
    if (HasUrl()) { ss << "url: {" << m_url << "}" << std::endl; }
    if (HasPageNumber()) { ss << "page_number: " << std::to_string(m_page_number) << std::endl; }
    if (HasSheetNumber()) { ss << "sheet_number: " << std::to_string(m_sheet_number) << std::endl; }
    if (HasText()) { ss << "text: {" << m_text << "} " << std::endl; }
    if (HasLabel()) { ss << "label: " << m_label << std::endl; }
    if (HasSuggestion()) { ss << "suggestion: " << std::to_string(m_suggestion) << std::endl; }
    if (HasPornInfo()) { ss  << "porn_info: {" << m_porn_info.to_string() << "}" << std::endl;  }
    if (HasAdsInfo()) { ss << "ads_info: {" << m_ads_info.to_string() << "}" << std::endl; }
    if (HasIllegalInfo()) { ss << "illegal_info: {" << m_illegal_info.to_string() << "}" << std::endl; }
    if (HasAbuseInfo()) { ss << "abuse_info: {" << m_abuse_info.to_string() << "}" << std::endl; }
    if (HasPoliticsInfo()) { ss << "politics_info: {" << m_politics_info.to_string() << "}" << std::endl; }
    if (HasTerrorismInfo()) { ss << "terrorism_info: {" << m_terrorism_info.to_string() << "}" << std::endl; }
    return ss.str();
  }

  private:
  uint64_t m_mask;
  std::string m_url;                  // ??/?????????
  int m_page_number;                  // ???????????????
  int m_sheet_number;                 // ????????????????????
  std::string m_text;                 // ??????
  std::string m_label;                // ???????????????
  int m_suggestion;                   // ?????0???????1 ????????????2?????????????
  SceneResultInfo m_porn_info;        // ??????????????
  SceneResultInfo m_ads_info;         // ????????????????
  SceneResultInfo m_illegal_info;     // ??????????????
  SceneResultInfo m_abuse_info;       // ??????????????
  SceneResultInfo m_politics_info;    // ??????????????
  SceneResultInfo m_terrorism_info;   // ??????????????

};

class PageSegment {
 public:
  PageSegment() : m_mask(0x00000000u) {}
  virtual ~PageSegment() {}

  void SetResults(const std::vector<Result>& results) {
    m_mask |= 0x00000001u;
    m_results = results;
  }

  void AddResult(const Result& result) {
    m_mask |= 0x00000001u;
    m_results.push_back(result);
  }

  std::vector<Result> GetResults() const { return m_results; }

  bool HasResults() const { return (m_mask & 0x00000001u) != 0; }

  std::string to_string() const {
    std::stringstream ss;
    if (HasResults()) {
      for (std::vector<Result>::const_iterator it = m_results.begin();
           it != m_results.end(); ++it) {
        ss << "\nresults: {\n" << it->to_string() << "} ";
      }
    }
    return ss.str();
  }
  
 private:
  uint64_t m_mask;
  std::vector<Result> m_results;

};

class AuditingJobsDetail {
 public:
  AuditingJobsDetail() : m_mask(0x00000000u) {}
  virtual ~AuditingJobsDetail() {}

  void SetCode(const std::string& code) {
    m_mask |= 0x00000001u;
    m_code = code;
  }
  
  void SetMessage(const std::string& message) {
    m_mask |= 0x00000002u;
    m_message = message;
  }
  
  void SetDataId(const std::string& data_id) {
    m_mask |= 0x00000004u;
    m_data_id = data_id;
  }
  
  void SetJobId(const std::string& job_id) {
    m_mask |= 0x00000008u;
    m_job_id = job_id;
  }
  
  void SetState(const std::string& state) {
    m_mask |= 0x00000010u;
    m_state = state;
  }
  
  void SetCreationTime(const std::string& creation_time) {
    m_mask |= 0x00000020u;
    m_creation_time = creation_time;
  }
  
  void SetUserInfo(const UserInfo& user_info) {
    m_mask |= 0x00000040u;
    m_user_info = user_info;
  }

  std::string GetCode() const { return m_code; }

  std::string GetMessage() const { return m_message; }

  std::string GetDataId() const { return m_data_id; }

  std::string GetJobId() const { return m_job_id; }

  std::string GetState() const { return m_state; }

  std::string GetCreationTime() const { return m_creation_time; }

  UserInfo getUserInfo() const { return m_user_info; }
  
  bool HasCode() const { return (m_mask & 0x00000001u) != 0; }

  bool HasMessage() const { return (m_mask & 0x00000002u) != 0; }

  bool HasDataId() const { return (m_mask & 0x00000004u) != 0; }

  bool HasJobId() const { return (m_mask & 0x00000008u) != 0; }

  bool HasState() const { return (m_mask & 0x00000010u) != 0; }

  bool HasCreationTime() const { return (m_mask & 0x00000020u) != 0; }

  bool HasUserInfo() const { return (m_mask & 0x00000040u) != 0; }

  std::string to_string() const {
    std::stringstream ss;
    if (HasCode()) {
      ss << "code: " << m_code << std::endl;
    }
    if (HasMessage()) {
      ss << "message: " << m_message << std::endl;
    }
    if (HasDataId()) {
      ss << "data_id: " << m_data_id << std::endl;
    }
    if (HasJobId()) {
      ss << "job_id: " << m_job_id << std::endl;
    }
    if (HasState()) {
      ss << "state: " << m_state << std::endl;
    }
    if (HasCreationTime()) {
      ss << "creation_time: " << m_creation_time << std::endl;
    }
    if (HasUserInfo()) {
      ss << "user_info: {" << m_user_info.to_string() << "}" << std::endl;
    }
    return ss.str();
  }

 protected:
  uint64_t m_mask;
  std::string m_code;                               // ?????? State ? Failed ????
  std::string m_message;                            // ??????? State ? Failed ????
  std::string m_data_id;                            // ????????DataId??????????????????512??
  std::string m_job_id;                             // ?????? ID
  std::string m_state;                              // ??????? Submitted?Auditing?Success?Failed????
  std::string m_creation_time;                      // ???????
  UserInfo m_user_info;                               // ???????????????UserInfo?????
};



class ImageAuditingJobsDetail : public AuditingJobsDetail {
 public:
  ImageAuditingJobsDetail() : AuditingJobsDetail() {}
  virtual ~ImageAuditingJobsDetail() {
  }

  void SetObject(const std::string& object) {
    m_mask |= 0x00000080u;
    m_object = object;
  }

  void SetUrl(const std::string& url) {
    m_mask |= 0x00000100u;
    m_url = url;
  }

  void SetCompressionResult(int compression_result) {
    m_mask |= 0x00000200u;
    m_compression_result = compression_result;
  }

  void SetText(const std::string& text) {
    m_mask |= 0x00000400u;
    m_text = text;
  }

  void SetLabel(const std::string& label) {
    m_mask |= 0x00000800u;
    m_label = label;
  }

  void SetResult(int result) {
    m_mask |= 0x00001000u;
    m_result = result;
  }

  void SetCategory(const std::string& category) {
    m_mask |= 0x00002000u;
    m_category = category;
  }

  void SetSubLabel(const std::string& sub_label) {
    m_mask |= 0x00004000u;
    m_sub_label = sub_label;
  }

  void SetPornInfo(const SceneResultInfo& porn_info) {
    m_mask |= 0x00008000u;
    m_porn_info = porn_info;
  }

  void SetAdsInfo(const SceneResultInfo& ads_info) {
    m_mask |= 0x00010000u;
    m_ads_info = ads_info;
  }

  void SetIllegalInfo(const SceneResultInfo& illegal_info) {
    m_mask |= 0x00020000u;
    m_illegal_info = illegal_info;
  }

  void SetAbuseInfo(const SceneResultInfo& abuse_info) {
    m_mask |= 0x00040000u;
    m_abuse_info = abuse_info;
  }

  void SetPoliticsInfo(const SceneResultInfo& politics_info) {
    m_mask |= 0x00080000u;
    m_politics_info = politics_info;
  }

  void SetTerrorismInfo(const SceneResultInfo& terrorism_info) {
    m_mask |= 0x00100000u;
    m_terrorism_info = terrorism_info;
  }

  std::string GetObject() const { return m_object; }

  std::string GetUrl() const { return m_url; }

  int GetCompressionResult() const { return m_compression_result; }

  std::string GetText() const { return m_text; }

  std::string GetLabel() const { return m_label; }

  int GetResult() const { return m_result; }

  std::string GetCategory() const { return m_category; }

  std::string GetSubLabel() const { return m_sub_label; }

  SceneResultInfo GetPornInfo() const { return m_porn_info; }

  SceneResultInfo GetAdsInfo() const { return m_ads_info; }

  SceneResultInfo GetIllegalInfo() const { return m_illegal_info; }

  SceneResultInfo GetAbuseInfo() const { return m_abuse_info; }

  SceneResultInfo GetPoliticsInfo() const { return m_politics_info; }

  SceneResultInfo GetTerrorismInfo() const { return m_terrorism_info; }

  bool HasObject() const { return (m_mask & 0x00000080u) != 0; }

  bool HasUrl() const { return (m_mask & 0x00000100u) != 0; }

  bool HasCompressionResult() const { return (m_mask & 0x00000200u) != 0; }

  bool HasText() const { return (m_mask & 0x00000400u) != 0; }

  bool HasLabel() const { return (m_mask & 0x00000800u) != 0; }

  bool HasResult() const { return (m_mask & 0x00001000u) != 0; }

  bool HasCategory() const { return (m_mask & 0x00002000u) != 0; }

  bool HasSubLabel() const { return (m_mask & 0x00004000u) != 0; }

  bool HasPornInfo() const { return (m_mask & 0x00008000u) != 0; }

  bool HasAdsInfo() const { return (m_mask & 0x00010000u) != 0; }

  bool HasIllegalInfo() const { return (m_mask & 0x00020000u) != 0; }

  bool HasAbuseInfo() const { return (m_mask & 0x00040000u) != 0; }

  bool HasPoliticsInfo() const { return (m_mask & 0x00080000u) != 0; }

  bool HasTerrorismInfo() const { return (m_mask & 0x00100000u) != 0; }

  std::string to_string() const {
    std::stringstream ss;
    ss << AuditingJobsDetail::to_string();
    if (HasObject()) {
      ss << "object: " << m_object << std::endl;
    }
    if (HasUrl()) {
      ss << "url: " << m_url << std::endl;
    }
    if (HasCompressionResult()) {
      ss <<  "compression_result: " << std::to_string(m_compression_result) << std::endl;
    }
    if (HasText()) {
      ss << "text: " << m_text << std::endl;
    }
    if (HasLabel()) {
      ss << "label: " << m_label << std::endl;
    }
    if (HasResult()) {
      ss << "result: " << std::to_string(m_result) << std::endl;
    }
    if (HasCategory()) {
      ss << "category: " << m_category << std::endl;
    }
    if (HasSubLabel()) {
      ss << "sub_label: " << m_sub_label << std::endl;
    }
    if (HasPornInfo()) {
      ss << "porn_info: {" << m_porn_info.to_string() << "}" << std::endl;
    }
    if (HasAdsInfo()) {
      ss << "ads_info: {" << m_ads_info.to_string() << "}" << std::endl;
    }
    if (HasIllegalInfo()) {
      ss << "illegal_info: {" << m_illegal_info.to_string() << "}" << std::endl;
    }
    if (HasAbuseInfo()) {
      ss << "abuse_info: {" << m_abuse_info.to_string() << "}" << std::endl;
    }
    if (HasPoliticsInfo()) {
      ss << "politics_info: {" << m_politics_info.to_string() << "}" << std::endl;
    }
    if (HasTerrorismInfo()) {
      ss << "terrorism_info: {" << m_terrorism_info.to_string() << "}" << std::endl;
    }
    return ss.str();
  }

  private:
  std::string m_object;                             // ????????????????Object???
  std::string m_url;                                // ???????????????? Url ???
  int m_compression_result;                         // ???????????? 0??????1??????
  std::string m_text;                               // ???????????OCR??????????????????
  std::string m_label;                              // ????????????????????????Normal????Porn????Ads????
  int m_result;                                     // ?????????0???????1 ????????????2?????????????
  std::string m_category;                           // Label????????????????????? Sexy?????????????
  std::string m_sub_label;                          // ?????????
  SceneResultInfo m_porn_info;                      // ??????????????
  SceneResultInfo m_ads_info;                       // ????????????????
  SceneResultInfo m_illegal_info;                   // ??????????????
  SceneResultInfo m_abuse_info;                     // ??????????????
  SceneResultInfo m_politics_info;                  // ??????????????
  SceneResultInfo m_terrorism_info;                 // ??????????????

};

class VideoAuditingJobsDetail : public AuditingJobsDetail {
  public:
  VideoAuditingJobsDetail() : AuditingJobsDetail() {}
  virtual ~VideoAuditingJobsDetail() {}

  void SetObject(const std::string& object) {
    m_mask |= 0x00000080u;
    m_object = object;
  }

  void SetUrl(const std::string& url) {
    m_mask |= 0x00000100u;
    m_url = url;
  }

  void SetSnapShotCount(const std::string& snap_shot_count) {
    m_mask |= 0x00000200u;
    m_snap_shot_count = snap_shot_count;
  }

  void SetLabel(const std::string& label) {
    m_mask |= 0x00000400u;
    m_label = label;
  }

  void SetResult(int result) {
    m_mask |= 0x00000800u;
    m_result = result;
  }

  void SetSnapShot(const std::vector<SegmentResult>& snap_shot) {
    m_mask |= 0x00002000u;
    m_snap_shot = snap_shot;
  }

  void SetAudioSection(const std::vector<SegmentResult>& audio_section) {
    m_mask |= 0x00004000u;
    m_audio_section = audio_section;
  }

  void SetPornInfo(const SceneResultInfo& porn_info) {
    m_mask |= 0x00008000u;
    m_porn_info = porn_info;
  }

  void SetAdsInfo(const SceneResultInfo& ads_info) {
    m_mask |= 0x00010000u;
    m_ads_info = ads_info;
  }

  void SetIllegalInfo(const SceneResultInfo& illegal_info) {
    m_mask |= 0x00020000u;
    m_illegal_info = illegal_info;
  }

  void SetAbuseInfo(const SceneResultInfo& abuse_info) {
    m_mask |= 0x00040000u;
    m_abuse_info = abuse_info;
  }

  void SetPoliticsInfo(const SceneResultInfo& politics_info) {
    m_mask |= 0x00080000u;
    m_politics_info = politics_info;
  }

  void SetTerrorismInfo(const SceneResultInfo& terrorism_info) {
    m_mask |= 0x00100000u;
    m_terrorism_info = terrorism_info;
  }

  void AddSnapShot(const SegmentResult& snap_shot) {
    m_mask |= 0x00002000u;
    m_snap_shot.push_back(snap_shot);
  }

  void AddAudioSection(const SegmentResult audio_section) {
    m_mask |= 0x00004000u;
    m_audio_section.push_back(audio_section);
  }

  std::string GetObject() const { return m_object; }

  std::string GetUrl() const { return m_url; }

  std::string GetSnapShotCount() const { return m_snap_shot_count; }

  std::string GetLabel() const { return m_label; }

  int GetResult() const { return m_result; }

  std::vector<SegmentResult> GetSnapShot() const { return m_snap_shot; }

  std::vector<SegmentResult> GetAudioSection() const { return m_audio_section; }

  SceneResultInfo GetPornInfo() const { return m_porn_info; }

  SceneResultInfo GetAdsInfo() const { return m_ads_info; }

  SceneResultInfo GetIllegalInfo() const { return m_illegal_info; }

  SceneResultInfo GetAbuseInfo() const { return m_abuse_info; }

  SceneResultInfo GetPoliticsInfo() const { return m_politics_info; }

  SceneResultInfo GetTerrorismInfo() const { return m_terrorism_info; }

  bool HasObject() const { return (m_mask & 0x00000080u) != 0; }

  bool HasUrl() const { return (m_mask & 0x00000100u) != 0; }

  bool HasSnapShotCount() const { return (m_mask & 0x00000200u) != 0; }

  bool HasLabel() const { return (m_mask & 0x00000400u) != 0; }

  bool HasResult() const { return (m_mask & 0x00000800u) != 0; }

  bool HasSnapShot() const { return (m_mask & 0x00002000u) != 0; }

  bool HasAudioSection() const { return (m_mask & 0x00004000u) != 0; }

  bool HasPornInfo() const { return (m_mask & 0x00008000u) != 0; }

  bool HasAdsInfo() const { return (m_mask & 0x00010000u) != 0; }

  bool HasIllegalInfo() const { return (m_mask & 0x00020000u) != 0; }

  bool HasAbuseInfo() const { return (m_mask & 0x00040000u) != 0; }

  bool HasPoliticsInfo() const { return (m_mask & 0x00080000u) != 0; }

  bool HasTerrorismInfo() const { return (m_mask & 0x00100000u) != 0; }

  std::string to_string() const {
    std::stringstream ss;
    ss << AuditingJobsDetail::to_string();
    if (HasObject()) {
      ss << "object:" << m_object << std::endl;
    }
    if (HasUrl()) {
      ss << "url: " << m_url << std::endl;
    }
    if (HasSnapShotCount()) {
      ss <<  "SnapShotCount: " << m_snap_shot_count << std::endl;
    }
    if (HasLabel()) {
      ss << "label: " << m_label << std::endl;
    }
    if (HasResult()) {
      ss << "Result: " << std::to_string(m_result) << std::endl;
    }
    if (HasPornInfo()) {
      ss << "porn_info: {" << m_porn_info.to_string() << "}" << std::endl;
    }
    if (HasAdsInfo()) {
      ss << "ads_info: {" << m_ads_info.to_string() << "}" << std::endl;
    }
    if (HasIllegalInfo()) {
      ss << "illegal_info: {" << m_illegal_info.to_string() << "}" << std::endl;
    }
    if (HasAbuseInfo()) {
      ss << "abuse_info: {" << m_abuse_info.to_string() << "}" << std::endl;
    }
    if (HasPoliticsInfo()) {
      ss << "politics_info: {" << m_politics_info.to_string() << "}" << std::endl;
    }
    if (HasTerrorismInfo()) {
      ss << "terrorism_info: {" << m_terrorism_info.to_string() << "}" << std::endl;
    }
    if (HasSnapShot()) {
      for (std::vector<SegmentResult>::const_iterator it = m_snap_shot.begin();
           it != m_snap_shot.end(); ++it) {
        ss << "snap_shot: {" << it->to_string() << "}" << std::endl;
      }
    }
    if (HasAudioSection()) {
      for (std::vector<SegmentResult>::const_iterator it = m_audio_section.begin();
           it != m_audio_section.end(); ++it) {
        ss << "audio_section: " << it->to_string() << std::endl;
      }
    }
    return ss.str();
  }

  private:
  std::string m_object;                             // ????????????????Object???
  std::string m_url;                                // ???????????????? Url ???
  std::string m_snap_shot_count;                    // ???????
  std::string m_label;                              // ????????????????????????Normal????Porn????Ads????
  int m_result;                                     // ?????????0???????1 ????????????2?????????????
  SceneResultInfo m_porn_info;                      // ??????????????
  SceneResultInfo m_ads_info;                       // ????????????????
  SceneResultInfo m_illegal_info;                   // ??????????????
  SceneResultInfo m_abuse_info;                     // ??????????????
  SceneResultInfo m_politics_info;                  // ??????????????
  SceneResultInfo m_terrorism_info;                 // ??????????????
  std::vector<SegmentResult> m_snap_shot;           // ???????????
  std::vector<SegmentResult> m_audio_section;       // ??????????
};

class AudioAuditingJobsDetail : public AuditingJobsDetail {
 public:
  AudioAuditingJobsDetail() {}
  virtual ~AudioAuditingJobsDetail() {}

  void SetObject(const std::string& object) {
    m_mask |= 0x00000080u;
    m_object = object;
  }

  void SetUrl(const std::string& url) {
    m_mask |= 0x00000100u;
    m_url = url;
  }

  void SetLabel(const std::string& label) {
    m_mask |= 0x00000200u;
    m_label = label;
  }

  void SetResult(int result) {
    m_mask |= 0x00000400u;
    m_result = result;
  }

  void SetAudioText(const std::string& audio_text) {
    m_mask |= 0x00000800u;
    m_audio_text = audio_text;
  }

  void SetPornInfo(const SceneResultInfo& porn_info) {
    m_mask |= 0x00001000u;
    m_porn_info = porn_info;
  }

  void SetAdsInfo(const SceneResultInfo& ads_info) {
    m_mask |= 0x00002000u;
    m_ads_info = ads_info;
  }

  void SetIllegalInfo(const SceneResultInfo& illegal_info) {
    m_mask |= 0x00004000u;
    m_illegal_info = illegal_info;
  }

  void SetAbuseInfo(const SceneResultInfo& abuse_info) {
    m_mask |= 0x00008000u;
    m_abuse_info = abuse_info;
  }

  void SetPoliticsInfo(const SceneResultInfo& politics_info) {
    m_mask |= 0x00010000u;
    m_politics_info = politics_info;
  }

  void SetTerrorismInfo(const SceneResultInfo& terrorism_info) {
    m_mask |= 0x00020000u;
    m_terrorism_info = terrorism_info;
  }

  void SetSection(const std::vector<SegmentResult>& section) {
    m_mask |= 0x00040000u;
    m_section = section;
  }

  void AddSection(const SegmentResult& section) {
    m_mask |= 0x00040000u;
    m_section.push_back(section);
  }

  std::string GetObject() const { return m_object; }

  std::string GetUrl() const { return m_url; }

  std::string GetLabel() const { return m_label; }

  int GetResult() const { return m_result; }

  std::string GetAudioText() const { return m_audio_text; }

  SceneResultInfo GetPornInfo() const { return m_porn_info; }

  SceneResultInfo GetAdsInfo() const { return m_ads_info; }

  SceneResultInfo GetIllegalInfo() const { return m_illegal_info; }

  SceneResultInfo GetAbuseInfo() const { return m_abuse_info; }

  SceneResultInfo GetPoliticsInfo() const { return m_politics_info; }

  SceneResultInfo GetTerrorismInfo() const { return m_terrorism_info; }

  std::vector<SegmentResult> GetSection() const { return m_section; }

  bool HasObject() const { return (m_mask & 0x00000080u) != 0; }

  bool HasUrl() const { return (m_mask & 0x00000100u) != 0; }

  bool HasLabel() const { return (m_mask & 0x00000200u) != 0; }

  bool HasResult() const { return (m_mask & 0x00000400u) != 0; }

  bool HasAudioText() const { return (m_mask & 0x00000800u) != 0; }

  bool HasPornInfo() const { return (m_mask & 0x00001000u) != 0; }

  bool HasAdsInfo() const { return (m_mask & 0x00002000u) != 0; }

  bool HasIllegalInfo() const { return (m_mask & 0x00004000u) != 0; }

  bool HasAbuseInfo() const { return (m_mask & 0x00008000u) != 0; }

  bool HasPoliticsInfo() const { return (m_mask & 0x00010000u) != 0; }

  bool HasTerrorismInfo() const { return (m_mask & 0x00020000u) != 0; }

  bool HasSection() const { return (m_mask & 0x00040000u) != 0; }

  std::string to_string() const {
    std::stringstream ss;
    ss << AuditingJobsDetail::to_string();
    if (HasObject()) {
      ss << "object:" << m_object << std::endl;
    }
    if (HasUrl()) {
      ss << "url: " << m_url << std::endl;
    }
    if (HasLabel()) {
      ss << "label: " << m_label << std::endl;
    }
    if (HasResult()) {
      ss << "result: " << std::to_string(m_result) << std::endl;
    }
    if (HasAudioText()) {
      ss << "audio_text: " << m_audio_text << std::endl;
    }
    if (HasPornInfo()) {
      ss << "porn_info: {" << m_porn_info.to_string() << "}" << std::endl;
    }
    if (HasAdsInfo()) {
      ss << "ads_info: {" << m_ads_info.to_string() << "}" << std::endl;
    }
    if (HasIllegalInfo()) {
      ss << "illegal_info: {" << m_illegal_info.to_string() << "}" << std::endl;
    }
    if (HasAbuseInfo()) {
      ss << "abuse_info: {" << m_abuse_info.to_string() << "}" << std::endl;
    }
    if (HasPoliticsInfo()) {
      ss << "politics_info: {" << m_politics_info.to_string() << "}" << std::endl;
    }
    if (HasTerrorismInfo()) {
      ss << "terrorism_info: {" << m_terrorism_info.to_string() << "}" << std::endl;
    }
    if (HasSection()) {
      for (std::vector<SegmentResult>::const_iterator it = m_section.begin();
           it != m_section.end(); ++it) {
        ss << "section: {" << it->to_string() << "}" << std::endl;
      }
    }
    return ss.str();
  }

 private:
  std::string m_object;                             // ????????????????Object???
  std::string m_url;                                // ???????????????? Url ???
  std::string m_label;                              // ????????????????????????Normal????Porn????Ads????
  int m_result;                                     // ?????????0???????1 ????????????2?????????????
  std::string m_audio_text;                         // ???????????????
  SceneResultInfo m_porn_info;                      // ??????????????
  SceneResultInfo m_ads_info;                       // ????????????????
  SceneResultInfo m_illegal_info;                   // ??????????????
  SceneResultInfo m_abuse_info;                     // ??????????????
  SceneResultInfo m_politics_info;                  // ??????????????
  SceneResultInfo m_terrorism_info;                 // ??????????????
  std::vector<SegmentResult> m_section;             // ???????????????????????
};

class TextAuditingJobsDetail : public AuditingJobsDetail{
 public:
  TextAuditingJobsDetail() {}
  virtual ~TextAuditingJobsDetail() {}

  void SetObject(const std::string& object) {
    m_mask |= 0x00000080u;
    m_object = object;
  }

  void SetContent(const std::string& content) {
    m_mask |= 0x00000100u;
    m_content = content;
  }

  void SetSectionCount(const int section_count) {
    m_mask |= 0x00000200u;
    m_section_count = section_count;
  }

  void SetLabel(const std::string& label) {
    m_mask |= 0x00000400u;
    m_label = label;
  }

  void SetResult(int result) {
    m_mask |= 0x00000800u;
    m_result = result;
  }

  void SetPornInfo(const SceneResultInfo& porn_info) {
    m_mask |= 0x00001000u;
    m_porn_info = porn_info;
  }

  void SetAdsInfo(const SceneResultInfo& ads_info) {
    m_mask |= 0x00002000u;
    m_ads_info = ads_info;
  }

  void SetIllegalInfo(const SceneResultInfo& illegal_info) {
    m_mask |= 0x00004000u;
    m_illegal_info = illegal_info;
  }

  void SetAbuseInfo(const SceneResultInfo& abuse_info) {
    m_mask |= 0x00008000u;
    m_abuse_info = abuse_info;
  }

  void SetPoliticsInfo(const SceneResultInfo& politics_info) {
    m_mask |= 0x00010000u;
    m_politics_info = politics_info;
  }

  void SetTerrorismInfo(const SceneResultInfo& terrorism_info) {
    m_mask |= 0x00020000u;
    m_terrorism_info = terrorism_info;
  }

  void SetSection(const std::vector<SegmentResult>& section) {
    m_mask |= 0x00040000u;
    m_section = section;
  }

  void AddSection(const SegmentResult& section) {
    m_mask |= 0x00040000u;
    m_section.push_back(section);
  }

  std::string GetObject() const { return m_object; }

  std::string GetContent() const { return m_content; }

  int GetSectionContent() const { return m_section_count; }

  std::string GetLabel() const { return m_label; }

  int GetResult() const { return m_result; }

  SceneResultInfo GetPornInfo() const { return m_porn_info; }

  SceneResultInfo GetAdsInfo() const { return m_ads_info; }

  SceneResultInfo GetIllegalInfo() const { return m_illegal_info; }

  SceneResultInfo GetAbuseInfo() const { return m_abuse_info; }

  SceneResultInfo GetPoliticsInfo() const { return m_politics_info; }

  SceneResultInfo GetTerrorismInfo() const { return m_terrorism_info; }

  std::vector<SegmentResult> GetSection() const { return m_section; }

  bool HasObject() const { return (m_mask & 0x00000080u) != 0; }

  bool HasContent() const { return (m_mask & 0x00000100u) != 0; }

  bool HasSectionCount() const { return (m_mask & 0x00000200u) != 0; }

  bool HasLabel() const { return (m_mask & 0x00000400u) != 0; }

  bool HasResult() const { return (m_mask & 0x00000800u) != 0; }

  bool HasPornInfo() const { return (m_mask & 0x00001000u) != 0; }

  bool HasAdsInfo() const { return (m_mask & 0x00002000u) != 0; }

  bool HasIllegalInfo() const { return (m_mask & 0x00004000u) != 0; }

  bool HasAbuseInfo() const { return (m_mask & 0x00008000u) != 0; }

  bool HasPoliticsInfo() const { return (m_mask & 0x00010000u) != 0; }

  bool HasTerrorismInfo() const { return (m_mask & 0x00020000u) != 0; }

  bool HasSection() const { return (m_mask & 0x00040000u) != 0; }


  std::string to_string() const {
    std::stringstream ss;
    ss << AuditingJobsDetail::to_string();
    if (HasObject()) {
      ss << "object:" << m_object << std::endl;
    }
    if (HasContent()) {
      ss << "content: " << m_content << std::endl;
    }
    if (HasLabel()) {
      ss << "label: " << m_label << std::endl;
    }
    if (HasResult()) {
      ss << "result: " << std::to_string(m_result) << std::endl;
    }
    if (HasSectionCount()) {
      ss << "section_count: " << std::to_string(m_section_count) << std::endl;
    }
    if (HasPornInfo()) {
      ss << "porn_info: {" << m_porn_info.to_string() << "}" << std::endl;
    }
    if (HasAdsInfo()) {
      ss << "ads_info: {" << m_ads_info.to_string() << "}" << std::endl;
    }
    if (HasIllegalInfo()) {
      ss << "illegal_info: {" << m_illegal_info.to_string() << "}" << std::endl;
    }
    if (HasAbuseInfo()) {
      ss << "abuse_info: {" << m_abuse_info.to_string() << "}" << std::endl;
    }
    if (HasPoliticsInfo()) {
      ss << "politics_info: {" << m_politics_info.to_string() << "}" << std::endl;
    }
    if (HasTerrorismInfo()) {
      ss << "terrorism_info: {" << m_terrorism_info.to_string() << "}" << std::endl;
    }
    if (HasSection()) {
      for (std::vector<SegmentResult>::const_iterator it = m_section.begin();
           it != m_section.end(); ++it) {
        ss << "section: {" << it->to_string() << "}" << std::endl;
      }
    }
    return ss.str();
  }

 private:
  std::string m_object;                             // ????????????????Object???
  std::string m_content;                            // ?????Base64?????????Content???
  int m_section_count;                              // ????????????1
  std::string m_label;                              // ????????????????????????Normal????Porn????Ads????
  int m_result;                                     // ?????????0???????1 ????????????2?????????????
  SceneResultInfo m_porn_info;                      // ??????????????
  SceneResultInfo m_ads_info;                       // ????????????????
  SceneResultInfo m_illegal_info;                   // ??????????????
  SceneResultInfo m_abuse_info;                     // ??????????????
  SceneResultInfo m_politics_info;                  // ??????????????
  SceneResultInfo m_terrorism_info;                 // ??????????????
  std::vector<SegmentResult> m_section;             // ???????????????
};

class DocumentAuditingJobsDetail : public AuditingJobsDetail {
 public:
  DocumentAuditingJobsDetail() {}
  virtual ~DocumentAuditingJobsDetail() {}

  void SetObject(const std::string& object) {
    m_mask |= 0x00000080u;
    m_object = object;
  }

  void SetUrl(const std::string& url) {
    m_mask |= 0x00000100u;
    m_url = url;
  }

  void SetLabel(const std::string& label) {
    m_mask |= 0x00000200u;
    m_label = label;
  }

  void SetSuggestion(int suggestion) {
    m_mask |= 0x00000400u;
    m_suggestion = suggestion;
  }

  void SetPageCount(const int page_count) {
    m_mask |= 0x00000800u;
    m_page_count = page_count;
  }

  void SetLabels(const Labels& labels) {
    m_mask |= 0x00001000u;
    m_labels = labels;
  }

  void SetPageSegment(const PageSegment& page_segment) {
    m_mask |= 0x00002000u;
    m_page_segment = page_segment;
  }

  std::string GetObject() const { return m_object; }

  std::string GetUrl() const { return m_url; }

  std::string GetLabel() const { return m_label; }

  int GetSuggestion() const { return m_suggestion; }

  int GetPageCount() const { return m_page_count; }

  Labels GetLabels() const { return m_labels; }

  PageSegment GetPageSegment() const { return m_page_segment; }

  bool HasObject() const { return (m_mask & 0x00000080u) != 0; }

  bool HasUrl() const { return (m_mask & 0x00000100u) != 0; }

  bool HasLabel() const { return (m_mask & 0x00000200u) != 0; }

  bool HasSuggestion() const { return (m_mask & 0x00000400u) != 0; }

  bool HasPageCount() const { return (m_mask & 0x00000800u) != 0; }

  bool HasLabels() const { return (m_mask & 0x00001000u) != 0; }

  bool HasPageSegment() const { return (m_mask & 0x00002000u) != 0; }

  std::string to_string() const {
    std::stringstream ss;
    ss << AuditingJobsDetail::to_string();
    if (HasObject()) {
      ss << "object:" << m_object << std::endl;
    }
    if (HasUrl()) {
      ss << "url: " << m_url << std::endl;
    }
    if (HasLabel()) {
      ss << "label: " << m_label << std::endl;
    }
    if (HasSuggestion()) {
      ss << "suggestion: " << std::to_string(m_suggestion) << std::endl;
    }
    if (HasPageCount()) {
      ss << "page_count: " << std::to_string(m_page_count) << std::endl;
    }
    if (HasLabels()) {
      ss << "labels: {" << m_labels.to_string() << "}" << std::endl;
    }
    if (HasPageSegment()) {
      ss << "page_segment: {" << m_page_segment.to_string() << "}" << std::endl;
    }
    return ss.str();
  }

 private:
  std::string m_object;                             // ????????????????Object???
  std::string m_url;                                // ???????????????? Url ???
  std::string m_label;                              // ????????????????????????Normal????Porn????Ads????
  int m_suggestion;                                 // ??????????????0???????1 ????????????2?????????????
  int m_page_count;                                 // ????????????????????????????
  Labels m_labels;                                  // ?????????????
  PageSegment m_page_segment;                       // ??????????????????????
};

class WebPageAuditingJobsDetail : public AuditingJobsDetail{
 public:
  WebPageAuditingJobsDetail() {}
  virtual ~WebPageAuditingJobsDetail() {}

  void SetUrl(const std::string& url) {
    m_mask |= 0x00000080u;
    m_url = url;
  }

  void SetLabel(const std::string& label) {
    m_mask |= 0x00000100u;
    m_label = label;
  }

  void SetSuggestion(int suggestion) {
    m_mask |= 0x00000200u;
    m_suggestion = suggestion;
  }

  void SetPageCount(const int page_count) {
    m_mask |= 0x00000400u;
    m_page_count = page_count;
  }

  void SetImageResults(const PageSegment& image_results) {
    m_mask |= 0x00000800u;
    m_image_results = image_results;
  }

  void SetTextResults(const PageSegment& text_results) {
    m_mask |= 0x00001000u;
    m_text_results = text_results;
  }

  void SetHighLightHtml(const std::string& high_light_html) {
    m_mask |= 0x00002000u;
    m_high_light_html = high_light_html;
  }

  void SetLabels(const Labels& labels) {
    m_mask |= 0x00004000u;
    m_labels = labels;
  }

  std::string GetUrl() const { return m_url; }

  std::string GetLabel() const { return m_label; }

  int GetSuggestion() const { return m_suggestion; }

  int GetPageCount() const { return m_page_count; }

  Labels GetLabels() const { return m_labels; }

  PageSegment GetImageResults() const { return m_image_results; }

  PageSegment GetTextResults() const { return m_text_results; }

  std::string GetHighLightHtml() const { return m_high_light_html; }

  bool HasUrl() const { return (m_mask & 0x00000080u) != 0; }

  bool HasLabel() const { return (m_mask & 0x00000100u) != 0; }

  bool HasSuggestion() const { return (m_mask & 0x00000200u) != 0; }

  bool HasPageCount() const { return (m_mask & 0x00000400u) != 0; }

  bool HasImageResults() const { return (m_mask & 0x00000800u) != 0; }

  bool HasTextResults() const { return (m_mask & 0x00001000u) != 0; }

  bool HasHighLightHtml() const { return (m_mask & 0x00002000u) != 0; }

  bool HasLabels() const { return (m_mask & 0x00004000u) != 0; }


  std::string to_string() const {
    std::stringstream ss;
    ss << AuditingJobsDetail::to_string();
    if (HasUrl()) {
      ss << "url: " << m_url << std::endl;
    }
    if (HasLabel()) {
      ss << "label: " << m_label << std::endl;
    }
    if (HasSuggestion()) {
      ss << "suggestion: " << std::to_string(m_suggestion) << std::endl;
    }
    if (HasPageCount()) {
      ss << "page_count: " << std::to_string(m_page_count) << std::endl;
    }
    if (HasImageResults()) {
      ss << " image_results: {" << m_image_results.to_string() << "}" << std::endl;
    }
    if (HasTextResults()) {
      ss << " text_results: {" << m_text_results.to_string() << "}" << std::endl;
    }
    if (HasHighLightHtml()) {
      ss << " high_light_html: " << m_high_light_html << std::endl;
    }

    if (HasLabels()) {
      ss << "labels: {" << m_labels.to_string() << "}" << std::endl;
    }

    return ss.str();
  }


 private:
  std::string m_url;                                // ???????????????? Url ???
  std::string m_label;                              // ????????????????????????Normal????Porn????Ads????
  int m_suggestion;                                 // ??????????????0???????1 ????????????2?????????????
  int m_page_count;                                 // ???????????????????????????????????????
  PageSegment m_image_results;                      // ??????????
  PageSegment m_text_results;                       // ??????????
  std::string m_high_light_html;                    // ??????????? Html ??????????? ReturnHighlightHtml ???
  Labels m_labels;                                  // ?????????????
};


class AuditingInput {
 public:
  AuditingInput() : m_mask(0x00000000u) {}
  
  void SetObject(const std::string& object) { 
    m_mask |= 0x00000001u;
    m_object = object; 
  }

  void SetUrl(const std::string& url) { 
    m_mask |= 0x00000002u;
    m_url = url; 
  }

  void SetInterval(const int interval) {
    m_mask |= 0x00000004u;
    m_interval = interval; 
  }

  void SetMaxFrames(const int max_frames) {
    m_mask |= 0x00000008u;
    m_max_frames = max_frames; 
  }

  void SetDataId(const std::string& data_id) {
    m_mask |= 0x00000010u;
    m_data_id = data_id; 
  }

  void SetLargeImageDetect(const int large_image_detect) {
    m_mask |= 0x00000020u;
    m_large_image_detect = large_image_detect; 
  }

  void SetUserInfo(const UserInfo& user_info) {
    m_mask |= 0x00000040u;
    m_user_info = user_info; 
  }

  void SetContent(const std::string& content) { 
    m_mask |= 0x00000080u;
    m_content = content; 
  }

  void SetType(const std::string& type) {
    m_mask |= 0x00000100u;
    m_type = type; 
  }
  
  std::string GetObject() const { return m_object; }

  std::string GetUrl() const { return m_url; }

  int GetInterval() const { return m_interval; }

  int GetMaxFrames() const { return m_max_frames; }

  int GetLargeImageDetect() const { return m_large_image_detect; }

  std::string GetDataId() const { return m_data_id; }

  UserInfo GetUserInfo() const { return m_user_info; }

  std::string GetContent() const { return m_content; }

  std::string GetType() const { return m_type; }

  bool HasObject() const { return (m_mask & 0x00000001u) != 0; }

  bool HasUrl() const { return (m_mask & 0x00000002u) != 0; }

  bool HasInterval() const { return (m_mask & 0x00000004) != 0; }

  bool HasMaxFrames() const { return (m_mask & 0x00000008u) != 0;}

  bool HasDataId() const { return (m_mask & 0x00000010u) != 0; }

  bool HasLargeImageDetect() const { return (m_mask & 0x00000020u) != 0; }

  bool HasUserInfo() const { return (m_mask & 0x00000040u) != 0; }

  bool HasContent() const { return (m_mask & 0x00000080u) != 0; }

  bool HasType() const { return (m_mask & 0x00000100u) != 0; }


 private:
  uint64_t m_mask;
  std::string m_object;            // ??? COS ?????????
  std::string m_url;               // ???????? object ? url ????????
  int m_interval;                  // ?????GIF??????5?????1?????????5?????
  int m_max_frames;                // ???????GIF ??????????5?????? GIF ?5????????????0
  std::string m_data_id;           // ????????????????????????512??
  int m_large_image_detect;        // ?????????????????????????? 0??????1????????0
  UserInfo m_user_info;            // ??????
  std::string m_content;           // ?????????????
  std::string m_type;              // ???????????

};

class SnapShotConf {
 public:
  SnapShotConf() : m_mask(0x00000000u) {}

  void SetMode(const std::string& mode) {
    m_mask |= 0x00000001u;
    m_mode = mode;
  }

  void SetCount(const int count) {
    m_mask |= 0x00000002u;
    m_count = count;
  }

  void SetTimeIterval(const float time_interval) {
    m_mask = 0x00000004u;
    m_time_interval = time_interval;
  }

  std::string GetMode() const { return m_mode; }

  int GetCount() const { return m_count; }

  float GetTimeInterval() const { return m_time_interval; }

  bool HasMode() const { return (m_mask & 0x00000001u) != 0; }

  bool HasCount() const { return (m_mask & 0x00000002u) != 0; }

  bool HasTimeInterval() const { return (m_mask & 0x00000004u) != 0; }

  std::string to_string() const {
    std::stringstream ss;
    if (HasMode()) { ss << "mode: " << m_mode; }
    if (HasCount()) { ss << " count: " << std::to_string(m_count); }
    if (HasTimeInterval()) { ss << " time_interval: " << std::to_string(m_time_interval); }
    return ss.str();
  };
 private:
  uint64_t m_mask;
  std::string m_mode;                // ????, ???Interval????Interval?Average?Fps?// ??https://cloud.tencent.com/document/product/436/47316
  int m_count;                       // ??????
  float m_time_interval;             // ???????????????????
};

class Conf {
 public:
  Conf() : m_mask(0x00000000u) {}

  void SetBizType(const std::string& biz_type) { 
    m_mask |= 0x00000001u;
    m_biz_type = biz_type; 
  }

  void SetDetectType(const std::string& detect_type) {
    m_mask |= 0x00000002u;
    m_biz_type = detect_type;
  }

  void SetSnapShot(const SnapShotConf snap_shot) {
    m_mask |= 0x00000004u;
    m_snap_shot = snap_shot;
  }

  void SetCallBack(const std::string callback) {
    m_mask = m_mask | 0x00000008u;
    m_callback = callback;
  }

  void SetCallBackVersion(const std::string callbcak_version) {
    m_mask = m_mask | 0x00000010u;
    m_callback_version = callbcak_version;
  }

  void SetDetectContent(const int detect_content) {
    m_mask = m_mask | 0x00000020u;
    m_detect_content = detect_content;
  }

  void SetReturnHighlightHtml(const bool return_highlight_html) {
    m_mask = m_mask | 0x00000040u;
    m_return_highlight_html = return_highlight_html;
  }	

  std::string GetBizType() const { return m_biz_type;}

  std::string GetDetectType() const { return m_biz_type; }

  SnapShotConf GetSnapShot() const { return m_snap_shot; }

  std::string GetCallBack() const { return m_callback; }

  std::string GetCallBackVersion() const { return m_callback_version; }

  int GetDetectContent() const { return m_detect_content; }

  bool HasBizType() const { return (m_mask & 0x00000001u) != 0; }

  bool HasDetectType() const { return (m_mask & 0x00000002u) != 0;}

  bool HasSnapShot() const { return (m_mask & 0x00000004u) != 0; }

  bool HasCallback() const { return (m_mask & 0x00000008u) != 0; }

  bool HasCallbackVersion() const { return (m_mask & 0x00000010u) != 0; }

  bool HasDetectContent() const { return (m_mask & 0x00000020u) != 0; }

  bool HasReturnHighlightHtml() const { return (m_mask & 0x00000040u) != 0; }


  std::string to_string() const {
    std::stringstream ss;
    ss << "biz_type: " << m_biz_type
		   << ", detect_type: " << m_detect_type
       << ", snap_shot: " << m_snap_shot.to_string() 
       << ", callback: " << m_callback
       << ", callbcak_version: " << m_callback_version
       << ", detect_content: " << m_detect_content;
    return ss.str();
  }

 private:
  uint64_t m_mask;
  std::string m_biz_type;           // ?????????
  std::string m_detect_type;        // ??????? ????Porn?????Ads??????????????
  SnapShotConf m_snap_shot;         // ????????
  std::string m_callback;           // ????
  std::string m_callback_version;   // ???????????Simple?Detail???Simple
  int m_detect_content;             // ???????????0 ????????1 ?????????????0
  bool m_return_highlight_html;     // ????????????????????
};

class GetImageAuditingReq : public ObjectReq {
 public:
  GetImageAuditingReq(const std::string& bucket_name)
      : ObjectReq(bucket_name, "") {
    AddParam("ci-process", "sensitive-content-recognition");
    SetMethod("GET");
    SetHttps();
  }

  virtual ~GetImageAuditingReq() {}

  // COS ??????????????????????
  void SetObjectKey(const std::string& object_name) { 
    SetObjectName(object_name); 
  }

  // ????biz-type??????????????
  void SetBizType(const std::string& biz_type) { 
    AddParam("biz-type", biz_type); 
  }

  // ???????????porn?????ads????????????????????????
  void SetDetectType(const std::string& detect_type) { 
    AddParam("detect-type", detect_type); 
  }

  // ????Url??????????????
  // ???detect-url??????detect-url?????ObjectKey
  // ???detect-url??????ObjectKey
  void SetDetectUrl(const std::string& detect_url) { 
    AddParam("detect-url", detect_url); 
  }

  // ??GIF?????????????
  // ?????5??????1????????5?????????5
  void SetInterval(int interval) { 
    AddParam("interval", std::to_string(interval)); 
  }

  // ???????????????5
  void SetMaxFrames(int max_frames) { 
    AddParam("max-frames", std::to_string(max_frames)); 
  }

  // ?????????????????????????? 0??????1????????0?
  void SetLargeImageDetect(int large_image_detect) { 
    AddParam("large-image-detect", std::to_string(large_image_detect)); 
  }

  // ????????????????????512??
  void SetDataId(const std::string& data_id) { 
    AddParam("dataid", data_id); 
  }
};

class BatchImageAuditingReq : public BucketReq {
 public:
  BatchImageAuditingReq(const std::string& bucket_name)
      : BucketReq(bucket_name) {
    SetMethod("POST");
    SetPath("/image/auditing");
    SetHttps();
    AddHeader("Content-Type", "application/xml");
  }

  virtual ~BatchImageAuditingReq() {}

  void SetConf(const Conf& conf) { m_conf = conf; }
  void SetBizType(const std::string& biz_type) { m_conf.SetBizType(biz_type); }
  void SetDetectType(const std::string& detect_type) { m_conf.SetDetectType(detect_type); }
  void AddInput(const AuditingInput& input) { m_inputs.push_back(input); }
  void SetInputs(const std::vector<AuditingInput>& inputs) { m_inputs = inputs; }
  virtual bool GenerateRequestBody(std::string* body) const;

 private:
  std::vector<AuditingInput> m_inputs; // ????????????Input???????
  Conf m_conf;  // ????????
};

class DescribeAuditingJobReq : public BucketReq {
 public:
  DescribeAuditingJobReq(const std::string& bucket_name)
      : BucketReq(bucket_name) {
    SetMethod("GET");
    SetHttps();
  }
  virtual ~DescribeAuditingJobReq() {}

  void SetJobId(const std::string& job_id) { m_path += "/" + job_id; }
};

class DescribeImageAuditingJobReq : public DescribeAuditingJobReq {
 public:
  DescribeImageAuditingJobReq(const std::string& bucket_name)
      : DescribeAuditingJobReq(bucket_name) {
    SetPath("/image/auditing");
  } 
  virtual ~DescribeImageAuditingJobReq() {}
};

class CreateAuditingJobReq : public BucketReq {
 public:
  CreateAuditingJobReq(const std::string& bucket_name)
      : BucketReq(bucket_name) {
    SetMethod("POST");
    SetHttps();
    AddHeader("Content-Type", "application/xml");
  }
  virtual ~CreateAuditingJobReq() {}
  
  void SetInput(const AuditingInput& input) { m_input = input; }
  void SetConf(const Conf& conf) { m_conf = conf; }
  virtual bool GenerateRequestBody(std::string* body) const ;
 
 protected:
  AuditingInput m_input;       // ???????
  Conf m_conf;         // ??????
};

class CreateVideoAuditingJobReq : public CreateAuditingJobReq {
 public:
  CreateVideoAuditingJobReq(const std::string& bucket_name)
      : CreateAuditingJobReq(bucket_name) {
    SetPath("/video/auditing");
  }
  virtual ~CreateVideoAuditingJobReq() {}

  void SetBizType(const std::string& biz_type) { m_conf.SetBizType(biz_type); }
  void SetDetectType(const std::string& detect_type) { m_conf.SetDetectType(detect_type); }
  void SetSnapShot(const SnapShotConf& snap_shot) { m_conf.SetSnapShot(snap_shot); }
  void SetCallBack(const std::string& callback) { m_conf.SetCallBack(callback); }
  void SetCallBackVersion(const std::string& callback_version) { m_conf.SetCallBackVersion(callback_version); }
  void SetDetectContent(const int detect_content) { m_conf.SetDetectContent(detect_content); }

  void SetObject(const std::string& object) { m_input.SetObject(object); }
  void SetUrl(const std::string& url) { m_input.SetUrl(url); } 
  void SetDataId(const std::string& data_id) { m_input.SetDataId(data_id); }
  void SetUserInfo(const UserInfo& user_info) { m_input.SetUserInfo(user_info); }
};

class DescribeVideoAuditingJobReq : public DescribeAuditingJobReq {
 public:
  DescribeVideoAuditingJobReq(const std::string& bucket_name)
      : DescribeAuditingJobReq(bucket_name) {
    SetPath("/video/auditing");
  } 
  virtual ~DescribeVideoAuditingJobReq() {}
};

class CreateAudioAuditingJobReq : public CreateAuditingJobReq {
 public:
  CreateAudioAuditingJobReq(const std::string& bucket_name)
      : CreateAuditingJobReq(bucket_name) {
    SetPath("/audio/auditing");
  }
  virtual ~CreateAudioAuditingJobReq() {}


  void SetBizType(const std::string& biz_type) { m_conf.SetBizType(biz_type); }
  void SetDetectType(const std::string& detect_type) { m_conf.SetDetectType(detect_type); }
  void SetCallBack(const std::string& callback) { m_conf.SetCallBack(callback); }
  void SetCallBackVersion(const std::string& callback_version) { m_conf.SetCallBackVersion(callback_version); }

  void SetObject(const std::string& object) { m_input.SetObject(object); }
  void SetUrl(const std::string& url) { m_input.SetUrl(url); } 
  void SetDataId(const std::string& data_id) { m_input.SetDataId(data_id); }
  void SetUserInfo(const UserInfo& user_info) { m_input.SetUserInfo(user_info); }
};

class DescribeAudioAuditingJobReq : public DescribeAuditingJobReq {
 public:
  DescribeAudioAuditingJobReq(const std::string& bucket_name)
      : DescribeAuditingJobReq(bucket_name) {
    SetPath("/audio/auditing");
  } 
  virtual ~DescribeAudioAuditingJobReq() {}
};

class CreateTextAuditingJobReq : public CreateAuditingJobReq {
 public:
  CreateTextAuditingJobReq(const std::string& bucket_name)
      : CreateAuditingJobReq(bucket_name) {
    SetPath("/text/auditing");
  }
  virtual ~CreateTextAuditingJobReq() {}

  
  void SetBizType(const std::string& biz_type) { m_conf.SetBizType(biz_type); }
  void SetDetectType(const std::string& detect_type) { m_conf.SetDetectType(detect_type); }
  void SetCallBack(const std::string& callback) { m_conf.SetCallBack(callback); }
  void SetCallBackVersion(const std::string& callback_version) { m_conf.SetCallBackVersion(callback_version); }

  void SetObject(const std::string& object) { m_input.SetObject(object); }
  void SetUrl(const std::string& url) { m_input.SetUrl(url); } 
  void SetDataId(const std::string& data_id) { m_input.SetDataId(data_id); }
  void SetContent(const std::string& content) { m_input.SetContent(content); }
  void SetUserInfo(const UserInfo& user_info) { m_input.SetUserInfo(user_info); }
};

class DescribeTextAuditingJobReq : public DescribeAuditingJobReq {
 public:
  DescribeTextAuditingJobReq(const std::string& bucket_name)
      : DescribeAuditingJobReq(bucket_name) {
    SetPath("/text/auditing");
  } 
  virtual ~DescribeTextAuditingJobReq() {}
};

class CreateDocumentAuditingJobReq : public CreateAuditingJobReq {
 public:
  CreateDocumentAuditingJobReq(const std::string& bucket_name)
      : CreateAuditingJobReq(bucket_name) {
    SetPath("/document/auditing");
  }
  virtual ~CreateDocumentAuditingJobReq() {}

  void SetBizType(const std::string& biz_type) { m_conf.SetBizType(biz_type); }
  void SetDetectType(const std::string& detect_type) { m_conf.SetDetectType(detect_type); }
  void SetCallBack(const std::string& callback) { m_conf.SetCallBack(callback); }

  void SetObject(const std::string& object) { m_input.SetObject(object); }
  void SetUrl(const std::string& url) { m_input.SetUrl(url); } 
  void SetDataId(const std::string& data_id) { m_input.SetDataId(data_id); }
  void SetUserInfo(const UserInfo& user_info) { m_input.SetUserInfo(user_info); }
  void SetType(const std::string& type) { m_input.SetType(type); };
};

class DescribeDocumentAuditingJobReq : public DescribeAuditingJobReq {
 public:
  DescribeDocumentAuditingJobReq(const std::string& bucket_name)
      : DescribeAuditingJobReq(bucket_name) {
    SetPath("/document/auditing");
  } 
  virtual ~DescribeDocumentAuditingJobReq() {}
};

class CreateWebPageAuditingJobReq : public CreateAuditingJobReq {
 public:
  CreateWebPageAuditingJobReq(const std::string& bucket_name)
      : CreateAuditingJobReq(bucket_name) {
    SetPath("/webpage/auditing");
  }
  virtual ~CreateWebPageAuditingJobReq() {}


  void SetDetectType(const std::string& detect_type) { m_conf.SetDetectType(detect_type); }
  void SetCallBack(const std::string& callback) { m_conf.SetCallBack(callback); }
  void SetReturnHighligthHtml(const bool return_highlight_html) {
    m_conf.SetReturnHighlightHtml(return_highlight_html);
  }

  void SetObject(const std::string& object) { m_input.SetObject(object); }
  void SetDataId(const std::string& data_id) { m_input.SetDataId(data_id); }
  void SetUserInfo(const UserInfo& user_info) { m_input.SetUserInfo(user_info); }
  void SetUrl(const std::string& url) { m_input.SetUrl(url); }
};

class DescribeWebPageAuditingJobReq : public DescribeAuditingJobReq {
 public:
  DescribeWebPageAuditingJobReq(const std::string& bucket_name)
      : DescribeAuditingJobReq(bucket_name) {
    SetPath("/webpage/auditing");
  } 
  virtual ~DescribeWebPageAuditingJobReq() {}
};

}

