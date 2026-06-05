[![CI](https://github.com/yanyiwu/libcppjieba/actions/workflows/ci.yml/badge.svg)](https://github.com/yanyiwu/libcppjieba/actions/workflows/ci.yml)
- - -

# libcppjieba

## 简介

从 [CppJieba] 项目里面抽取出来的源代码，单独抽出来成立项目，使得它更容易去理解和使用。  
如果你喜欢该项目，请 `star` [CppJieba] 而不是该项目，以助于 [CppJieba] 的传播和更好的后续改进。多谢。  

本项目目前定位为 `CppJieba` 旧版本抽出的轻量、头文件式兼容层。新的分词能力、测试和构建体系优先在 [CppJieba] 主项目中演进；本仓库后续维护会以保持旧接口可用、补齐基础测试、逐步向主项目实现靠拢为主。

## 特性

+ 源代码全是头文件(hpp)，全在 `include/` 目录里。只需要 `#include` 即可使用。 **没有链接，就没有伤害。**
+ 无需安装其他任何依赖库，没错，连 `boost` 也不需要，是不是很酷。
+ 支持 `utf-8` 编码。

## 用法

```
make 
./demo
```

详细示例代码请看 `demo.cpp`

## 测试

```
make test
```

测试会覆盖当前 `Application` 接口的主要分词模式、词性标注、关键词抽取，以及 `LocalVector` 的旧式裸指针范围构造兼容性。CI 会在 Linux/macOS 和多个 C++ 标准模式下运行这些检查。

## 常见问题

问题1：   
编译器报错 `can not find tr1/unordered_map` 或者其他关于 tr1 的错误。
解决：    
请使用支持 C++11 或更新标准的编译器，并添加编译选项 `-std=c++11` 或更新标准，比如 `make CXXSTD=-std=c++17`。

问题2：   
如何设置 logger 级别？  
解决：    
添加编译选项 `-DLOGGER_LEVEL=LL_WARN`  就是设置日志级别为 WARN 及 WARN 以上。
同理可得 `LL_DEBUG`, `LL_INFO`, `LL_ERROR`, `LL_FATAL` 。

## 鸣谢

+ [Jieba]
+ [CppJieba]

## 客服

```
i@yanyiwu.com
```

[CppJieba]:https://github.com/yanyiwu/cppjieba
[Jieba]:https://github.com/fxsjy/jieba
