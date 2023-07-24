---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/chash.hpp\"\nstruct custom_hash {\n  static uint64_t\
    \ splitmix64(uint64_t x) {\n    x += 0x9e3779b97f4a7c15;\n    x = (x ^ (x >> 30))\
    \ * 0xbf58476d1ce4e5b9;\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return\
    \ x ^ (x >> 31);\n  }\n\n  size_t operator()(uint64_t x) const {\n    static const\
    \ uint64_t FIXED_RANDOM =\n        chrono::steady_clock::now().time_since_epoch().count();\n\
    \    return splitmix64(x + FIXED_RANDOM);\n  }\n};\n"
  code: "struct custom_hash {\n  static uint64_t splitmix64(uint64_t x) {\n    x +=\
    \ 0x9e3779b97f4a7c15;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x =\
    \ (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return x ^ (x >> 31);\n  }\n\n  size_t\
    \ operator()(uint64_t x) const {\n    static const uint64_t FIXED_RANDOM =\n \
    \       chrono::steady_clock::now().time_since_epoch().count();\n    return splitmix64(x\
    \ + FIXED_RANDOM);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/chash.hpp
  requiredBy: []
  timestamp: '2023-07-25 00:50:50+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/chash.hpp
layout: document
redirect_from:
- /library/misc/chash.hpp
- /library/misc/chash.hpp.html
title: misc/chash.hpp
---
