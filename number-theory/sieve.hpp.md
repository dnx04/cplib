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
  bundledCode: "#line 1 \"number-theory/sieve.hpp\"\nauto sieve = [](int n) {\n  vector<int>\
    \ lpf(n + 1);\n  iota(begin(lpf), end(lpf), 0);\n  for (int i = 2; i <= n; ++i)\
    \ {\n    if (lpf[i] == i) {\n      for (int j = 1ll * i * i; j <= n; j += i) {\n\
    \        if (lpf[j] == j) lpf[j] = i;\n      }\n    }\n  }\n  return lpf;\n};\n"
  code: "auto sieve = [](int n) {\n  vector<int> lpf(n + 1);\n  iota(begin(lpf), end(lpf),\
    \ 0);\n  for (int i = 2; i <= n; ++i) {\n    if (lpf[i] == i) {\n      for (int\
    \ j = 1ll * i * i; j <= n; j += i) {\n        if (lpf[j] == j) lpf[j] = i;\n \
    \     }\n    }\n  }\n  return lpf;\n};"
  dependsOn: []
  isVerificationFile: false
  path: number-theory/sieve.hpp
  requiredBy: []
  timestamp: '2022-06-30 19:56:15+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number-theory/sieve.hpp
layout: document
redirect_from:
- /library/number-theory/sieve.hpp
- /library/number-theory/sieve.hpp.html
title: number-theory/sieve.hpp
---
