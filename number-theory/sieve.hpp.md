---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: number-theory/test/Prime_Number.test.cpp
    title: number-theory/test/Prime_Number.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"number-theory/sieve.hpp\"\nauto sieve = [](int n) {\n  vector<int>\
    \ lpf(n + 1);\n  iota(begin(lpf), end(lpf), 0);\n  for (int i = 2; i <= n; ++i)\
    \ {\n    if (lpf[i] == i) {\n      for (long long j = 1ll * i * i; j <= n; j +=\
    \ i) {\n        lpf[j] = i;\n      }\n    }\n  }\n  return lpf;\n};\n"
  code: "auto sieve = [](int n) {\n  vector<int> lpf(n + 1);\n  iota(begin(lpf), end(lpf),\
    \ 0);\n  for (int i = 2; i <= n; ++i) {\n    if (lpf[i] == i) {\n      for (long\
    \ long j = 1ll * i * i; j <= n; j += i) {\n        lpf[j] = i;\n      }\n    }\n\
    \  }\n  return lpf;\n};"
  dependsOn: []
  isVerificationFile: false
  path: number-theory/sieve.hpp
  requiredBy: []
  timestamp: '2022-08-08 19:51:59+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - number-theory/test/Prime_Number.test.cpp
documentation_of: number-theory/sieve.hpp
layout: document
redirect_from:
- /library/number-theory/sieve.hpp
- /library/number-theory/sieve.hpp.html
title: number-theory/sieve.hpp
---
