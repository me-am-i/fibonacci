#include <node.h>

namespace fibonacci {

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::NewStringType;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;

// This is the implementation of the "add" method
// Input arguments are passed using the const FunctionCallbackInfo<Value>& args struct
void Fib(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  // Check the number of arguments passed.
  if (args.Length() != 1) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate,
                            "Wrong number of arguments",
                            NewStringType::kNormal).ToLocalChecked()));
    return;
  }

  // Check the argument types
  if (!args[0]->IsNumber() || args[0].As<Number>()->Value() <= 0) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate,
                            "Wrong arguments",
                            NewStringType::kNormal).ToLocalChecked()));
    return;
  }

  // Perform the operation
  int n = args[0].As<Number>()->Value();
  int a = 1;
  int b = 1;
  int i;
  for (i = 3; i <= n; i++) {
          int c = a + b;
          a = b;
          b = c;
        }
  int value = b;

  Local<Number> num = Number::New(isolate, value);

  // Set the return value (using the passed in FunctionCallbackInfo<Value>&)
  args.GetReturnValue().Set(num);
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "fib", Fib);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}
