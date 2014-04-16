# libcppjieba

## Introduction

extract source code from [CppJieba], make it easiest to understand and use.

## Feature

+ support utf-8 encoding.
+ only headers(hpp), in `include/` directory.

## Usage

```
make 
./demo
```

You can see details in `demo.cpp`

## Q & A

Q1: compiler complains can not find `tr1/unordered_map` or other stuff about `tr1`

A1: add compiler option `-std=c++0x` in Makefile. For example: `g++ -o demo -std=c++0x demo.cpp`.

Q2: how to set logger level.

A2: add compiler option `-DLOGGER_LEVEL=LL_WARN`.  and `LL_WARN` also can be `LL_DEBUG`, `LL_INFO`, `LL_ERROR`, `LL_FATAL`.


If you still have any questions, please issue it or contact me with email, thanks.

## Thanks

+ [CppJieba]
+ [Jieba]

## Contact

wuyanyi09@foxmail.com

[CppJieba]:https://github.com/aszxqw/cppjieba
[Jieba]:https://github.com/fxsjy/jieba
