// Copyright & License details are available under JXCORE_LICENSE file

#ifndef SRC_JX_PROXY_MOZILLA_SPIDERHELPER_H_
#define SRC_JX_PROXY_MOZILLA_SPIDERHELPER_H_

#include "MozJS/MozJS.h"

namespace jxcore {

class MemoryScript {
  void *data_;
  size_t length_;

 public:
  MemoryScript() : data_(NULL), length_(0) {}
  MemoryScript(void *data, size_t length) : data_(data), length_(length) {}

  void set(void *data, size_t length) {
    data_ = data;
    length_ = length;
  }

  inline bool IsEmpty() { return length_ == 0; }

  inline void *data() { return data_; }
  inline size_t length() { return length_; }

  void Dispose() {
    if (length_ != 0) {
      free(data_);
    }
  }
};

MemoryScript GetScriptMemory(JSContext *ctx, JSScript *script);
JSScript *GetScript(JSContext *ctx, MemoryScript ms);

JSObject *NewGlobalObject(JSContext *ctx);
JSObject *NewContextGlobal(JSContext *ctx);
MozJS::Value getGlobal(const int threadId);
JSObject *getGlobalObject(const int threadId);
JSObject *NewTransplantObject(JSContext *ctx);
JSObject *CrossCompartmentCopy(JSContext *orig_context, JSContext *new_context,
                               MozJS::Value &source, bool global_object);

}  // namespace jxcore
#endif  // SRC_JX_PROXY_MOZILLA_SPIDERHELPER_H_
