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
    if (!args[0]->IsNumber() || args[0].As<Number>()->Value() < 0) {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate,
                            "Wrong arguments",
                            NewStringType::kNormal).ToLocalChecked()));
    return;
    }

    // Perform the operation
    // Get current element and count next one
    int elem = args[0].As<Number>()->Value() + 1;
    int prev = 0;
    int next = 1;
    for (int i = 0; i < elem; i++){
        int temp = next;
        next += prev;
        prev = temp;
    }
    int value = prev;

    Local<Number> num = Number::New(isolate, value);

    // Set the return value (using the passed in FunctionCallbackInfo<Value>&)
    args.GetReturnValue().Set(num);
}

void Init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "get", Fib);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}
