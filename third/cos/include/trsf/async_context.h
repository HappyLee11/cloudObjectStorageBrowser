#pragma once
#include "response/object_resp.h"
#include "trsf/transfer_handler.h"
#include <memory>

namespace qcloud_cos {

class AsyncContext {
 public:
  AsyncContext(const SharedTransferHandler& handler) : m_handler(handler) {}

  /// @brief ????
  void Cancel() { return m_handler->Cancel(); }

  /// @brief ??????
  void WaitUntilFinish() { return m_handler->WaitUntilFinish(); }

  std::string GetBucketName() const { return m_handler->GetBucketName(); }

  std::string GetObjectName() const { return m_handler->GetObjectName(); }

  std::string GetLocalFilePath() const { return m_handler->GetLocalFilePath(); }

  /// @brief ??????
  CosResult GetResult() const { return m_handler->GetResult(); }

  /// @brief ?????????
  AsyncResp GetAsyncResp() const {
    return m_handler->GetAsyncResp();
  }

 private:
  SharedTransferHandler m_handler;
};

}  // namespace qcloud_cos
