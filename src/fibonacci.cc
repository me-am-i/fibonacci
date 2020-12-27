#include <node.h>
#include <string>
#include <cstdlib>

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

// This is the implementation of the "get" method
// Input arguments are passed using the const FunctionCallbackInfo<Value>& args struct
void Fib(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    int elem, prev, next, value;

    // Check or set the environment variable
    char *step;
    step = getenv("FIBKEY");
    if(!step) {
        setenv("FIBKEY", "0", 1);
    }
    else {
        int intStep = atoi(step) + 1;
        // Update the environment variable
        setenv("FIBKEY", std::to_string(intStep).c_str(), 1);

        // Perform the operation
        // Get current element and count next one
        elem = intStep;
        prev = 0;
        next = 1;
        for (int i = 0; i < elem; i++){
            int temp = next;
            next += prev;
            prev = temp;
        }
        value = prev;
    }

    Local<Number> num = Number::New(isolate, value);

    // Set the return value (using the passed in FunctionCallbackInfo<Value>&)
    args.GetReturnValue().Set(num);
}


void Clear(const FunctionCallbackInfo<Value>& args) {
    setenv("FIBKEY", "0", 1);
}


void InitAll(Local<Object> exports) {
    NODE_SET_METHOD(exports, "get", Fib);
    NODE_SET_METHOD(exports, "clear", Clear);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, InitAll)

}
