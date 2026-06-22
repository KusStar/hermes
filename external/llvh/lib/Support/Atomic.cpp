//===- Atomic.cpp - Atomic Operations -------------------------------------===//
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "llvh/Support/Atomic.h"

#if defined(_MSC_VER)
#include <intrin.h>
#endif

namespace llvh {
namespace sys {

void MemoryFence() {
#if defined(_MSC_VER)
  _ReadWriteBarrier();
#else
  __sync_synchronize();
#endif
}

cas_flag CompareAndSwap(
    volatile cas_flag *ptr,
    cas_flag new_value,
    cas_flag old_value) {
#if defined(_MSC_VER)
  return _InterlockedCompareExchange(ptr, new_value, old_value);
#else
  return __sync_val_compare_and_swap(ptr, old_value, new_value);
#endif
}

} // namespace sys
} // namespace llvh
