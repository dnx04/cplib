---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data-structure/test/Static_RMQ.test.cpp
    title: data-structure/test/Static_RMQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/rmq.hpp\"\ntemplate <class T>\nstruct rmq\
    \ {\n  rmq() = default;\n  rmq(const vector<T>& v) : t{v}, n{(int)v.size()} {\n\
    \    for (int k = 1; (1 << k) <= n; ++k) {\n      t.emplace_back(n - (1 << k)\
    \ + 1);\n      for (int i = 0; i + (1 << k) <= n; ++i) {\n        t[k][i] = min(t[k\
    \ - 1][i], t[k - 1][i + (1 << (k - 1))]);\n      }\n    }\n  }\n\n  // get range\
    \ [l, r-1]\n  // doesn't work for empty range\n  T get(int l, int r) const {\n\
    \    assert(0 <= l && l < r && r <= n);\n    int k = __lg(r - l);\n    return\
    \ min(t[k][l], t[k][r - (1 << k)]);\n  }\n\n private:\n  vector<vector<T>> t;\n\
    \  int n;\n};\n"
  code: "template <class T>\nstruct rmq {\n  rmq() = default;\n  rmq(const vector<T>&\
    \ v) : t{v}, n{(int)v.size()} {\n    for (int k = 1; (1 << k) <= n; ++k) {\n \
    \     t.emplace_back(n - (1 << k) + 1);\n      for (int i = 0; i + (1 << k) <=\
    \ n; ++i) {\n        t[k][i] = min(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);\n\
    \      }\n    }\n  }\n\n  // get range [l, r-1]\n  // doesn't work for empty range\n\
    \  T get(int l, int r) const {\n    assert(0 <= l && l < r && r <= n);\n    int\
    \ k = __lg(r - l);\n    return min(t[k][l], t[k][r - (1 << k)]);\n  }\n\n private:\n\
    \  vector<vector<T>> t;\n  int n;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/rmq.hpp
  requiredBy: []
  timestamp: '2022-08-12 11:03:46+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data-structure/test/Static_RMQ.test.cpp
documentation_of: data-structure/rmq.hpp
layout: document
redirect_from:
- /library/data-structure/rmq.hpp
- /library/data-structure/rmq.hpp.html
title: data-structure/rmq.hpp
---
