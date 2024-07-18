#pragma once

#include <sstream>
#include <string>
#include <vector>

#include "Poco/Dynamic/Struct.h"
#include "Poco/JSON/Object.h"
#include "request/bucket_req.h"
#include "request/object_req.h"

namespace qcloud_cos {

struct Input {
  Input() : object("") {}

  std::string object;  // ??? COS ???????Bucket ? Host ??

  std::string to_string() const {
    std::stringstream ss;
    ss << "object: " << object;
    return ss.str();
  }
};

struct Output {
  Output() : region(""), bucket(""), object("") {}
  std::string region;  // ??????
  std::string bucket;  // ????????
  std::string object;  // ??????

  std::string to_string() const {
    std::stringstream ss;
    ss << "region: " << region << ", bucket: " << bucket
       << ", object: " << object;
    return ss.str();
  }
};

struct DocProcess {
  DocProcess()
      : src_type(""),
        tgt_type(""),
        sheet_id(1),
        start_page(1),
        end_page(-1),
        image_params(""),
        doc_passwd(""),
        comments(0),
        paper_direction(0),
        quality(100),
        zoom(100) {}
  std::string src_type;      // ????????
  std::string tgt_type;      // ??????????
  int sheet_id;              // ??????
  int start_page;            // ?? X ?????
  int end_page;              // ???? X ?
  int page_size;             //
  std::string image_params;  // ??????????
  std::string doc_passwd;    //  Office ???????
  int comments;              // ???????????????0
  int paper_direction;  // ???????????0????????0??????????0
  int quality;  // ??????????????? [1-100]????100?
                // ????100??????????100%
  int zoom;  // ?????????

  std::string to_string() const {
    std::stringstream ss;
    ss << "src_type: " << src_type << ", tgt_type: " << tgt_type
       << ", sheet_id: " << sheet_id << ", start_page: " << start_page
       << ", end_page: " << end_page << ", page_size: " << page_size
       << ", image_params: " << image_params << ", doc_passwd: " << doc_passwd
       << ", comments: " << comments << ", paper_direction: " << paper_direction
       << ", quality: " << quality << ", zoom: " << zoom;
    return ss.str();
  }
};

struct PageInfo {
  PageInfo()
      : page_no(0), tgt_uri(""), x_sheet_pics(0), pic_index(0), pic_num(0) {}
  int page_no;  // ??????,???? Excel ????? SheetId
  std::string tgt_uri;  // ??????? cos ???
  int x_sheet_pics;  // ?? Sheet ???????????? Excel ?????
  int pic_index;  // ????????????????????? Excel ?????
  int pic_num;  // ??????? Sheet ????????? Excel ?????

  std::string to_string() const {
    std::stringstream ss;
    ss << "page_no: " << page_no << ", tgt_uri: " << tgt_uri
       << ", x_sheet_pics: " << x_sheet_pics << ", pic_index: " << pic_index
       << ", pic_num: " << pic_num;
    return ss.str();
  }
};

struct DocProcessResult {
  DocProcessResult()
      : tgt_type(""),
        total_pageount(0),
        succ_pagecount(0),
        fail_pagecount(0),
        total_sheetcount(0) {}
  std::vector<PageInfo> page_infos;  // ????????
  std::string tgt_type;              // ????????
  std::string task_id;               //
  int total_pageount;                // ?????????
  int succ_pagecount;                // ??????????
  int fail_pagecount;                // ??????????
  int total_sheetcount;  // ????? Sheet ??????? Excel ?????

  std::string to_string() const {
    std::stringstream ss;
    for (auto& page_info : page_infos) {
      ss << ", page_info: " << page_info.to_string();
    }
    ss << ", tgt_type: " << tgt_type << ", task_id: " << task_id
       << ", total_pageount: " << total_pageount
       << ", succ_pagecount: " << succ_pagecount
       << ", fail_pagecount: " << fail_pagecount
       << ", total_sheetcount: " << total_sheetcount;
    return ss.str();
  }
};

struct Operation {
  Output output;  // ? Tag ? DocProcess ????????????
  DocProcess doc_process;  // ??????
  DocProcessResult
      doc_process_result;  // ? job ???? DocProcess ? job ??? success
                           // ??????????????

  std::string to_string() const {
    std::stringstream ss;
    ss << "output: " << output.to_string()
       << ", doc_process: " << doc_process.to_string()
       << ", doc_process_result: " << doc_process_result.to_string();
    return ss.str();
  }
};

struct CodeLocation {
  std::vector<std::string> points;  // ??????
  std::string to_string() const {
    std::stringstream ss;
    for (auto& point : points) {
      ss << ", point: " << point;
    }
    ss << std::endl;
    return ss.str();
  }
};

struct QRcodeInfo {
  std::string code_url;        // ?????????????
  CodeLocation code_location;  // ?????????????

  std::string to_string() const {
    std::stringstream ss;
    ss << "code_url: " << code_url
       << ", code_location: " << code_location.to_string() << std::endl;
    return ss.str();
  }
};

struct GetQRcodeResult {
  int code_status;  // ????????0??????????1????????
  std::vector<QRcodeInfo> qr_code_info;  // ?????????????
  std::string
      result_image;  // ?????? base64??????? cover ?1???

  std::string to_string() const {
    std::stringstream ss;
    ss << "code_status: " << code_status;
    for (auto& qr_code : qr_code_info) {
      ss << "qr_code: " << qr_code.to_string();
    }
    ss << "result_image: " << result_image << std::endl;
    return ss.str();
  }
};

struct Object {
  std::string key;       // ???
  std::string location;  // ????
  std::string format;    // ????
  int width;             // ????
  int height;            // ????
  int size;              // ????
  int quality;           // ????
  std::string etag;      // ????? ETag ??
  int code_status;  // ????????0??????????1????????
  int watermark_status;  // ? type
                         // ?2?????????????????????
                         //  ???0-100????75????????????60-75?????????60????????????
  std::vector<QRcodeInfo> qr_code_info;  // ?????????????
  std::string to_string() const {
    std::stringstream ss;
    ss << "key: " << key << ", location: " << location << ", format: " << format
       << ", width: " << width << ", heihth: " << height << ", size: " << size
       << ", quality: " << quality << ", etag: " << etag
       << ", watermark_status: " << watermark_status;
    for (auto& qr_code : qr_code_info) {
      ss << "qr_code: " << qr_code.to_string();
    }
    ss << std::endl;
    return ss.str();
  }
};

struct ProcessResults {
  std::vector<Object> objects;  // ???????
  std::string to_string() const {
    std::stringstream ss;
    for (auto& object : objects) {
      ss << "object: " << object.to_string();
    }
    ss << std::endl;
    return ss.str();
  }
};

struct ImageInfo {
  std::string format;  // ??
  int width;           // ????
  int height;          // ????
  int quality;         // ????
  std::string ave;     // ?????
  int orientation;     // ??????
  std::string to_string() const {
    std::stringstream ss;
    ss << "format: " << format << ", width: " << width << ", heihth: " << height
       << ", quality: " << quality << ", ave: " << ave
       << ", orientation: " << orientation << std::endl;
    return ss.str();
  }
};

struct OriginalInfo {
  std::string key;       // ?????
  std::string location;  // ????
  ImageInfo image_info;  // ??????
  std::string etag;      // ?? ETag ??
  std::string to_string() const {
    std::stringstream ss;
    ss << "key: " << key << ", location: " << location
       << ", image_info: " << image_info.to_string() << ", etag: " << etag
       << std::endl;
    return ss.str();
  }
};

struct UploadResult {
  OriginalInfo original_info;     // ????
  ProcessResults process_result;  // ??????
  std::string to_string() const {
    std::stringstream ss;
    ss << "original_info: " << original_info.to_string()
       << ", process_result: " << process_result.to_string() << std::endl;
    return ss.str();
  }
};

struct PicRules {
  std::string bucket;  // ????????????????
                       // BucketName-APPID??????????????????
  std::string
      fileid;  // ??????????????/????????????????????????????
  std::string
      rule;  // ???????????????
             // API????????????style/??????????????test??
             // rule ???style/test
};

class PicOperation {
 public:
  PicOperation() : is_pic_info(true) {}
  virtual ~PicOperation() {}

  std::vector<PicRules> GetRules() const { return rules; }

  void AddRule(const PicRules& rule) { rules.push_back(rule); }

  void TurnOffPicInfo() { is_pic_info = false; }

  std::string GenerateJsonString() const {
    Poco::JSON::Object::Ptr json_root = new Poco::JSON::Object();
    if (is_pic_info) {
      json_root->set("is_pic_info", 1);
    } else {
      json_root->set("is_pic_info", 0);
    }

    Poco::JSON::Array rules_array;
    for (auto& it : rules) {
      Poco::JSON::Object::Ptr rule = new Poco::JSON::Object();
      if (!it.bucket.empty()) {
        rule->set("bucket", it.bucket);
      }
      rule->set("fileid", it.fileid);
      rule->set("rule", it.rule);
      rules_array.add(rule);
    }

    json_root->set("rules", rules_array);
    std::ostringstream oss;
    Poco::JSON::Stringifier::stringify(json_root, oss);
    return oss.str();
  }

 private:
  bool
      is_pic_info;  // ?????????0????????1??????????0
  std::vector<PicRules>
      rules;  //??????????????????????????????????????
};

struct BucketInfo {
  std::string bucket_id;        // ??? ID
  std::string name;             // ??????? BucketId
  std::string region;           // ?????
  std::string create_time;      // ????
  std::string alias_bucket_id;  // ?????

  std::string to_string() const {
    std::stringstream ss;
    ss << "bucket_id: " << bucket_id << ", name: " << name
       << ", region: " << region << ", create_time: " << create_time
       << ", alias_bucket_id: " << alias_bucket_id;
    return ss.str();
  }
};

struct CreateDocBucketResult {
  std::string request_id;                 // ?????ID
  BucketInfo doc_bucket;                // ??Bucket
  std::string to_string() const {
    std::stringstream ss;
    ss << "request_id: " << request_id << std::endl;
    ss << doc_bucket.to_string() << std::endl;
    ss << std::endl;
    return ss.str();
  }
};

struct DocBucketResponse {
  std::string request_id;  // ????? ID
  int total_count;         // ???? Bucket ??
  int page_number;         // ?????????? pageNumber
  int page_size;           // ?????????? pageSize
  std::vector<BucketInfo> doc_bucket_list;  // ???? Bucket ??
  std::string to_string() const {
    std::stringstream ss;
    ss << "request_id: " << request_id << ", total_count: " << total_count
       << ", page_number: " << page_number << ", page_size: " << page_size;
    for (auto& bucket : doc_bucket_list) {
      ss << ", bucket: " << bucket.to_string();
    }
    ss << std::endl;
    return ss.str();
  }
};

struct JobsDetail {
  JobsDetail() {}
  std::string code;     // ?????? State ? Failed ????
  std::string message;  // ??????? State ? Failed ????
  std::string job_id;   // ?????? ID
  std::string tag;      // ?????? Tag?DocProcess
  std::string
      state;  // ???????
              // Submitted?Running?Success?Failed?Pause?Cancel ????
  std::string create_time;  // ???????
  std::string end_time;     //
  std::string queue_id;     // ??????? ID
  Input input;              // ??????????
  Operation operation;      // ??????
  std::string to_string() const {
    std::stringstream ss;
    ss << "code: " << code << ", message: " << message << ", job_id: " << job_id
       << ", tag: " << tag << ", state: " << state
       << ", create_time: " << create_time << ", end_time: " << end_time
       << ", queue_id: " << queue_id << ". input: " << input.to_string()
       << ", operation: " << operation.to_string();
    return ss.str();
  }
};

struct NotifyConfig {
  std::string url;    // ????
  std::string state;  // ?????On ?? Off
  std::string type;   // ?????Url
  std::string event;  // ???????
  std::string to_string() const {
    std::stringstream ss;
    ss << "url: " << url << ", state: " << state << ", type: " << type
       << ", event: " << event;
    return ss.str();
  }
};

struct NonExistPIDs {
  std::vector<std::string> queue_id;  // NonExistPIDs
  std::string to_string() const {
    std::stringstream ss;
    for (auto& q : queue_id) {
      ss << ", queue_id: " << q;
    }
    return ss.str();
  }
};

struct QueueList {
  std::string queue_id;        // ?? ID
  std::string name;            // ????
  std::string state;           // ?????Active ?? Paused
  NotifyConfig notify_config;  // ????
  int max_size;                // ??????
  int max_concurrent;          // ??????????????
  std::string update_time;     // ????
  std::string create_time;     // ????
  std::string bucket_id;       //
  std::string category;        //
  std::string to_string() const {
    std::stringstream ss;
    ss << "queue_id: " << queue_id << ", name: " << name << ", state: " << state
       << ", notify_config: " << notify_config.to_string()
       << ", max_size: " << max_size << ", max_concurrent: " << max_concurrent
       << ", update_time: " << update_time << ", create_time: " << create_time
       << ". bucket_id: " << bucket_id << ", category: " << category;
    return ss.str();
  }
};

struct DescribeMediaBucketsResult {
  std::string request_id;                     // ?????ID
  int total_count;                            // ??Bucket??
  int page_number;                            // ????
  int page_size;                              // ????
  std::vector<BucketInfo> media_bucket_list;  // ??Bucket??
  std::string to_string() const {
    std::stringstream ss;
    ss << "request_id: " << request_id << std::endl
       << "total_count: " << total_count << std::endl
       << "page_number: " << page_number << std::endl
       << "page_size: " << page_size << std::endl;
    for (auto& bucket : media_bucket_list) {
      ss << bucket.to_string() << std::endl;
    }
    ss << std::endl;
    return ss.str();
  }
};

struct CreateMediaBucketResult {
  std::string request_id;                 // ?????ID
  BucketInfo media_bucket;                // ??Bucket
  std::string to_string() const {
    std::stringstream ss;
    ss << "request_id: " << request_id << std::endl;
    ss << media_bucket.to_string() << std::endl;
    ss << std::endl;
    return ss.str();
  }
};
struct VideoInfo {
  int index;                     // ?????
  std::string codec_name;        // ???????
  std::string codec_long_name;   // ??????????
  std::string codec_time_base;   // ????
  std::string codec_tag_string;  // ?????
  std::string codec_tag;         // ????
  std::string profile;           // ??????
  int height;                    // ?????? px
  int width;                     // ?????? px
  int has_bframe;                // ???B??1????0???
  int ref_frames;                // ??????????
  std::string sar;               // ?????
  std::string dar;               // ?????
  std::string pix_format;        // ????
  std::string field_order;       // ????
  int level;                     // ??????
  int fps;                       // ????
  std::string avg_fps;           // ????
  std::string time_base;         // ??
  float start_time;              // ???????????
  float duration;                // ?????????
  float bitrate;                 // ??????? kbps
  int num_frames;                // ???
  std::string language;          // ??
  std::string to_string() const {
    std::stringstream ss;
    ss << "index: " << index << std::endl
       << "codec_name: " << codec_name << std::endl
       << "codec_long_name: " << codec_long_name << std::endl
       << "codec_time_base: " << codec_time_base << std::endl
       << "codec_tag_string: " << codec_tag_string << std::endl
       << "codec_tag: " << codec_tag << std::endl
       << "profile: " << profile << std::endl
       << "height: " << height << std::endl
       << "width: " << width << std::endl
       << "has_bframe: " << has_bframe << std::endl
       << "ref_frames: " << ref_frames << std::endl
       << "sar: " << sar << std::endl
       << "dar: " << dar << std::endl
       << "pix_format: " << pix_format << std::endl
       << "field_order: " << field_order << std::endl
       << "level: " << level << std::endl
       << "fps: " << fps << std::endl
       << "avg_fps: " << avg_fps << std::endl
       << "time_base: " << time_base << std::endl
       << "start_time: " << start_time << std::endl
       << "duration: " << duration << std::endl
       << "bitrate: " << bitrate << std::endl
       << "num_frames: " << num_frames << std::endl
       << "language: " << language << std::endl;
    return ss.str();
  }
};

struct AudioInfo {
  int index;                     // ?????
  std::string codec_name;        // ???????
  std::string codec_long_name;   // ??????????
  std::string codec_time_base;   // ????
  std::string codec_tag_string;  // ?????
  std::string codec_tag;         // ????
  std::string sample_fmt;        // ????
  int sample_rate;               // ???
  int channel;                   // ????
  std::string channel_layout;    // ????
  std::string time_base;         // ??
  float start_time;              // ??????????
  float duration;                // ????????
  float bitrate;                 // ??????? kbps
  std::string language;          // ??
  std::string to_string() const {
    std::stringstream ss;
    ss << "index: " << index << std::endl
       << "codec_name: " << codec_name << std::endl
       << "codec_long_name: " << codec_long_name << std::endl
       << "codec_time_base: " << codec_time_base << std::endl
       << "codec_tag_string: " << codec_tag_string << std::endl
       << "codec_tag: " << codec_tag << std::endl
       << "sample_fmt: " << sample_fmt << std::endl
       << "sample_rate: " << sample_rate << std::endl
       << "channel: " << channel << std::endl
       << "channel_layout: " << channel_layout << std::endl
       << "time_base: " << time_base << std::endl
       << "start_time: " << start_time << std::endl
       << "duration: " << duration << std::endl
       << "bitrate: " << bitrate << std::endl
       << "language: " << language << std::endl;
    return ss.str();
  }
};

struct SubtitleInfo {
  int index;             // ?????
  std::string language;  // ??
  std::string to_string() const {
    std::stringstream ss;
    ss << "index: " << index << std::endl
       << "language: " << language << std::endl;
    return ss.str();
  }
};

struct StreamInfo {
  VideoInfo video;        // ????
  AudioInfo audio;        // ????
  SubtitleInfo subtitle;  // ????
  std::string to_string() const {
    std::stringstream ss;
    ss << "video: " << video.to_string() << std::endl
       << "audio: " << audio.to_string() << std::endl
       << "subtitle: " << subtitle.to_string() << std::endl;
    return ss.str();
  }
};
struct FormatInfo {
  int num_stream;   // Stream??? Video?Audio?Subtitle????
  int num_program;  // ?????
  std::string format_name;       // ??????
  std::string format_long_name;  // ?????????
  float start_time;              //?????????
  float duration;                //???????
  float bitrate;                 //??????? kbps
  int size;                      //?????? Byte
  std::string to_string() const {
    std::stringstream ss;
    ss << "num_stream: " << num_stream << std::endl
       << "num_program: " << num_program << std::endl
       << "format_name: " << format_name << std::endl
       << "format_long_name: " << format_long_name << std::endl
       << "start_time: " << start_time << std::endl
       << "duration: " << duration << std::endl
       << "bitrate: " << bitrate << std::endl
       << "size: " << size << std::endl;
    return ss.str();
  }
};
struct MediaInfo {
  StreamInfo stream;  // ???
  FormatInfo format;  // ????

  std::string to_string() const {
    std::stringstream ss;
    ss << "stream: " << stream.to_string() << std::endl
       << "format: " << format.to_string() << std::endl;
    return ss.str();
  }
};

struct GetMediaInfoResult {
  MediaInfo media_info;  // ????
  std::string to_string() const {
    std::stringstream ss;
    ss << "media_info: " << media_info.to_string() << std::endl;
    return ss.str();
  }
};

class PutImageByFileReq : public PutObjectByFileReq {
 public:
  PutImageByFileReq(const std::string& bucket_name,
                    const std::string& object_name,
                    const std::string& local_image)
      : PutObjectByFileReq(bucket_name, object_name, local_image) {}

  virtual ~PutImageByFileReq() {}

  PicOperation GetPictureOperation() const { return m_pic_operation; }

  void SetPicOperation(const PicOperation& pic_operation) {
    m_pic_operation = pic_operation;
    AddHeader("Pic-Operations", m_pic_operation.GenerateJsonString());
  }

  // ???????????????????
  void CheckCoverOriginImage();  

 private:
  PicOperation m_pic_operation;
};

class CloudImageProcessReq : public ObjectReq {
 public:
  CloudImageProcessReq(const std::string& bucket_name,
                       const std::string& object_name)
      : ObjectReq(bucket_name, object_name) {
    m_method = "POST";
  }
  virtual ~CloudImageProcessReq() {}

  void SetPicOperation(const PicOperation& pic_operation) {
    m_pic_operation = pic_operation;
    AddHeader("Pic-Operations", m_pic_operation.GenerateJsonString());
    AddParam("image_process", "");
  }

 private:
  PicOperation m_pic_operation;
};

class GetQRcodeReq : public ObjectReq {
 public:
  GetQRcodeReq(const std::string& bucket_name, const std::string& object_name)
      : ObjectReq(bucket_name, object_name) {
    AddParam("ci-process", "QRcode");
    AddParam("cover", "0");

    m_method = "GET";
  }

  virtual ~GetQRcodeReq() {}

  // ???????????????????????????0?1?0???????????1?????????????0
  void EnableCover() { AddParam("cover", "1"); }
};

class CreateDocBucketReq : public BucketReq{
  public:
  CreateDocBucketReq(const std::string& bucket_name) : BucketReq(bucket_name) {
    m_method = "POST";
    m_path = "/docbucket";
    SetHttps();
  }

  virtual ~CreateDocBucketReq() {}
};

class DescribeDocProcessBucketsReq : public BaseReq {
 public:
  DescribeDocProcessBucketsReq() {
    m_method = "GET";

    m_path = "/docbucket";

    // ??????https
    SetHttps();
  }
  virtual ~DescribeDocProcessBucketsReq() {}

  void SetRegions(const std::string& regions) { AddParam("regions", regions); }

  void SetBucketNames(const std::string& bucket_names) {
    AddParam("bucketNames", bucket_names);
  }

  void SetBucketName(const std::string& bucket_name) {
    AddParam("bucketName", bucket_name);
  }

  void SetPageNumber(const std::string& page_number) {
    AddParam("pageNumber", page_number);
  }

  void SetPageSize(const std::string& page_size) {
    AddParam("PageSize", page_size);
  }
};

class DocPreviewReq : public GetObjectByFileReq {
 public:
  DocPreviewReq(const std::string& bucket_name, const std::string& object_name,
                const std::string& local_file)
      : GetObjectByFileReq(bucket_name, object_name, local_file) {
    AddParam("ci-process", "doc-preview");

    AddParam("page", "1");

    AddParam("sheet", "1");

    AddParam("dstType", "jpg");

    AddParam("comment", "0");

    AddParam("excelPaperDirection", "0");

    AddParam("quality", "100");

    AddParam("scale", "100");
  }

  virtual ~DocPreviewReq() {}

  // ????????????????? COS ????????????????
  // COS ???????????????
  void SetSrcType(const std::string& src_type) {
    AddParam("srcType", src_type);
  }

  // ????????????1?????????? page ?????? X ?
  // sheet ?? X ??
  void SetPage(const int page) { AddParam("page", std::to_string(page)); }
  // ????????????? ?????? ????????????????
  // ????? ?????????????????????????
  void SetImageParams(const std::string& image_param) {
    AddParam("ImageParams", image_param);
  }

  // ?????????? X ??????1
  void SetSheet(const int sheet) {
    AddParam("ImageParams", std::to_string(sheet));
  }

  // ??????????
  void SetDstType(const std::string& dst_type) {
    AddParam("dstType", dst_type);
  }

  // Office ???????????????????????????
  void SetPasswd(const std::string& passwd) { AddParam("password", passwd); }
  // ???????????????
  void SetComment(const int comment) {
    AddParam("comment", std::to_string(comment));
  }

  // ???????????0????????0??????????0
  void SetExcelPaperDirection(const int direction) {
    AddParam("excelPaperDirection", std::to_string(direction));
  }

  // ??????????????? [1-100]????100?
  // ????100??????????100%
  void SetQuality(const int quality) {
    AddParam("quality", std::to_string(quality));
  }

  // ??????????????[10-200]? ???100?
  // ????200??????????200% ?????
  void SetScale(const int scale) { AddParam("scale", std::to_string(scale)); }
};

class CreateDocProcessJobsReq : public BucketReq {
 public:
  CreateDocProcessJobsReq(const std::string& bucket_name)
      : BucketReq(bucket_name) {
    SetMethod("POST");
    SetPath("/doc_jobs");
    SetHttps();
    AddHeader("Content-Type", "application/xml");
    m_tag = "DocProcess";
  }

  virtual ~CreateDocProcessJobsReq() {}

  void SetTag(const std::string& tag) { m_tag = tag; }
  void SetOperation(const Operation& operation) { m_operation = operation; }
  void SetInput(const Input& input) { m_input = input; }
  void SetQueueId(const std::string& queue_id) { m_queue_id = queue_id; }
  bool GenerateRequestBody(std::string* body) const;

 private:
  std::string m_tag;       // ????? Tag???????DocProcess
  Input m_input;           // ????????
  Operation m_operation;   // ????
  std::string m_queue_id;  // ??????? ID
};

class DescribeDocProcessJobReq : public BucketReq {
 public:
  DescribeDocProcessJobReq(const std::string& bucket_name)
      : BucketReq(bucket_name) {
    SetMethod("GET");
    SetPath("/doc_jobs");
    SetHttps();
  }
  virtual ~DescribeDocProcessJobReq() {}
  void SetJobId(const std::string& job_id) { m_path += "/" + job_id; }
};

class DescribeDocProcessJobsReq : public BucketReq {
 public:
  DescribeDocProcessJobsReq(const std::string& bucket_name)
      : BucketReq(bucket_name) {
    SetMethod("GET");
    SetPath("/doc_jobs");
    SetHttps();
    AddParam("tag", "DocProcess");

    AddParam("orderByTime", "Desc");
    AddParam("size", "10");
    AddParam("states", "All");
  }
  virtual ~DescribeDocProcessJobsReq() {}
  void SetQueueId(const std::string& queue_id) {
    AddParam("queueId", queue_id);
  }
  void SetOrderByTime(const std::string& order) {
    AddParam("orderByTime", order);
  }

  void SetNextToken(const std::string& next_token) {
    AddParam("nextToken", next_token);
  }

  void SetSize(const int size) {
    AddParam("size", StringUtil::IntToString(size));
  }
  void SetStates(const std::string& states) { AddParam("states", states); }
  void SetStartCreationTime(const std::string& start_time) {
    AddParam("startCreationTime", start_time);
  }

  void SetEndCreationTime(const std::string& end_time) {
    AddParam("endCreationTime", end_time);
  }
};

class DescribeDocProcessQueuesReq : public BucketReq {
 public:
  DescribeDocProcessQueuesReq(const std::string& bucket_name)
      : BucketReq(bucket_name) {
    SetMethod("GET");
    SetPath("/docqueue");
    SetHttps();
  }
  virtual ~DescribeDocProcessQueuesReq() {}
  void SetQueueIds(const std::string& queue_ids) {
    AddParam("queueIds", queue_ids);
  }
  void SetState(const std::string& state) { AddParam("state", state); }
  void SetPageNumber(const std::string& page_number) {
    AddParam("pageNumber", page_number);
  }

  void SetPageSize(const std::string& page_size) {
    AddParam("pageSize", page_size);
  }
};

class UpdateDocProcessQueueReq : public BucketReq {
 public:
  UpdateDocProcessQueueReq(const std::string& bucket_name)
      : BucketReq(bucket_name) {
    SetMethod("PUT");
    SetPath("/docqueue");
    AddHeader("Content-Type", "application/xml");
    SetHttps();
  }
  virtual ~UpdateDocProcessQueueReq() {}
  void SetQueueId(const std::string& queue_id) {
    m_queue_id = queue_id;
    m_path.append("/" + queue_id);
  }

  void SetName(const std::string& name) { m_name = name; }
  void SetState(const std::string& state) { m_state = state; }
  void SetNotifyConfig(const NotifyConfig& notify_config) {
    m_notify_config = notify_config;
  }
  bool GenerateRequestBody(std::string* body) const;

 private:
  std::string m_name;            // ????
  std::string m_queue_id;        // ?? ID
  std::string m_state;           // ????
  NotifyConfig m_notify_config;  // ????
};

class DescribeMediaBucketsReq : public BucketReq {
 public:
  DescribeMediaBucketsReq() {
    m_method = "GET";

    m_path = "/mediabucket";

    // ??????https
    SetHttps();
  }
  virtual ~DescribeMediaBucketsReq() {}

  // ???????
  // ap-shanghai?ap-beijing??????????,???????????????
  void SetRegions(const std::string& regions) { AddParam("regions", regions); }

  // ????????,????????????????
  void SetBucketNames(const std::string& bucket_names) {
    AddParam("bucketNames", bucket_names);
  }

  // ????????????
  void SetBucketName(const std::string& bucket_name) {
    AddParam("bucketName", bucket_name);
  }

  // ???
  void SetPageNumber(const std::string& page_number) {
    AddParam("pageNumber", page_number);
  }

  // ????
  void SetPageSize(const std::string& page_size) {
    AddParam("PageSize", page_size);
  }
};

class GetSnapshotReq : public GetObjectByFileReq {
 public:
  GetSnapshotReq(const std::string& bucket_name, const std::string& object_name,
                 const std::string& local_file)
      : GetObjectByFileReq(bucket_name, object_name, local_file) {
    AddParam("ci-process", "snapshot");
    AddParam("time", "0");
  }

  virtual ~GetSnapshotReq() {}

  // ??????????????
  void SetTime(float time) { AddParam("time", std::to_string(time)); }

  // ????,???0,? width ? height
  // ??0?????????????????0???????????????????
  void SetWitdh(int width) { AddParam("width", std::to_string(width)); }

  // ????,???0,? width ? height
  // ??0?????????????????0???????????????????
  void SetHeight(int height) { AddParam("height", std::to_string(height)); }

  // ???????? jpg ? png??? jpg
  void SetFormat(const std::string& format) { AddParam("format", format); }

  // ??????
  // auto???????????????off????????? auto
  void SetRotate(const std::string& rotate) { AddParam("rotate", rotate); }

  // ????
  // keyframe????????????????????
  // exactframe??????????? ???? exactframe
  void SetMode(const std::string& mode) { AddParam("mode", mode); }
};

class PutBucketToCIReq : public BucketReq{
  public:
  PutBucketToCIReq(const std::string& bucket_name) : BucketReq(bucket_name) {
    m_method = "PUT";
  }

  virtual ~PutBucketToCIReq() {}
};

class CreateMediaBucketReq : public BucketReq{
  public:
  CreateMediaBucketReq(const std::string& bucket_name) : BucketReq(bucket_name) {
    m_method = "POST";
    m_path = "/mediabucket";
    SetHttps();
  }

  virtual ~CreateMediaBucketReq() {}
};

class GetMediaInfoReq : public ObjectReq {
 public:
  GetMediaInfoReq(const std::string& bucket_name,
                  const std::string& object_name)
      : ObjectReq(bucket_name, object_name) {
    AddParam("ci-process", "videoinfo");
    m_method = "GET";
  }

  virtual ~GetMediaInfoReq() {}
};
}  // namespace qcloud_cos
