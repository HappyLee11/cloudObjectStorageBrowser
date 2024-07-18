// Copyright (c) 2017, Tencent Inc.
// All rights reserved.
//
// Author: sevenyou <sevenyou@tencent.com>
// Created: 11/14/17
// Description:

#ifndef SERVICEOP_H
#define SERVICEOP_H
#pragma once

#include "cos_sys_config.h"
#include "op/base_op.h"
#include "op/cos_result.h"
#include "request/service_req.h"
#include "response/service_resp.h"

namespace qcloud_cos {

/// \brief ???Service?????
class ServiceOp : public BaseOp {
 public:
  /// \brief ServiceOp????
  ///
  /// \param cos_conf Cos??
  explicit ServiceOp(const SharedConfig& config) : BaseOp(config) {}

  /// \brief ServiceOp????
  virtual ~ServiceOp() {}

  /// \brief ????????????????Bucket list
  ///        (??:https://cloud.tencent.com/document/api/436/8291)
  ///
  /// \param req  GetService??
  /// \param resp GetService??
  ///
  /// \return ?????????(?????)
  CosResult GetService(const GetServiceReq& req, GetServiceResp* resp);
};

}  // namespace qcloud_cos
#endif  // SERVICEOP_H
