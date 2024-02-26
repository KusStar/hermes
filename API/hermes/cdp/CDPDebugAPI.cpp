/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "CDPDebugAPI.h"

namespace facebook {
namespace hermes {
namespace cdp {

std::unique_ptr<CDPDebugAPI> CDPDebugAPI::create(
    HermesRuntime &runtime,
    size_t maxCachedMessages) {
  return std::unique_ptr<CDPDebugAPI>(
      new CDPDebugAPI(runtime, maxCachedMessages));
}

CDPDebugAPI::~CDPDebugAPI() = default;

CDPDebugAPI::CDPDebugAPI(HermesRuntime &runtime, size_t maxCachedMessages)
    : runtime_(runtime),
      asyncDebuggerAPI_(debugger::AsyncDebuggerAPI::create(runtime)),
      consoleMessageStorage_(maxCachedMessages) {}

} // namespace cdp
} // namespace hermes
} // namespace facebook