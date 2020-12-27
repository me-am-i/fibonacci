#include <node.h>
#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
#include <sstream>
#include <string>
#include <cstdlib>
//using namespace std;

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
        int nextStep = intStep;
        // Update the environment variable
        char buf[16];
        int j = 12;
        sprintf(buf, "%d", j);
        std::string s = std::to_string(nextStep);
        char const *pchar = s.c_str();
        setenv("FIBKEY", pchar, 1);

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

void Init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "get", Fib);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}
