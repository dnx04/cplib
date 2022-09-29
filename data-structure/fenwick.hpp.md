---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: data-structure/fenwick2d.hpp
    title: Fenwick Tree 2D
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data-structure/test/Point_Add_Range_Sum.test.cpp
    title: data-structure/test/Point_Add_Range_Sum.test.cpp
  - icon: ':x:'
    path: data-structure/test/The_Maximum_Number_of_Overlaps.test.cpp
    title: data-structure/test/The_Maximum_Number_of_Overlaps.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/fenwick.hpp\"\ntemplate <typename T>\nstruct\
    \ fenwick {\n  fenwick(int n) : n(n), f(n + 1) {}\n\n  // a[u] += val\n  void\
    \ add(int u, T val) {\n    assert(0 <= u && u < n);\n    ++u;\n    while (u <=\
    \ n) f[u] += val, u += u & -u;\n  }\n\n  // return the sum of [0, u)\n  T sum(int\
    \ u) const {\n    assert(0 <= u && u <= n);\n    T res = 0;\n    while (u) res\
    \ += f[u], u -= u & -u;\n    return res;\n  }\n\n  // return the sum of [l, r)\n\
    \  T sum(int l, int r) const {\n    assert(0 <= l && l <= r && r <= n);\n    if\
    \ (l == r) return 0;\n    return sum(r) - sum(l);\n  }\n\n  void reset() { fill(f.begin(),\
    \ f.end(), T(0)); }\n\n  int n;\n  vector<T> f;\n};\n"
  code: "template <typename T>\nstruct fenwick {\n  fenwick(int n) : n(n), f(n + 1)\
    \ {}\n\n  // a[u] += val\n  void add(int u, T val) {\n    assert(0 <= u && u <\
    \ n);\n    ++u;\n    while (u <= n) f[u] += val, u += u & -u;\n  }\n\n  // return\
    \ the sum of [0, u)\n  T sum(int u) const {\n    assert(0 <= u && u <= n);\n \
    \   T res = 0;\n    while (u) res += f[u], u -= u & -u;\n    return res;\n  }\n\
    \n  // return the sum of [l, r)\n  T sum(int l, int r) const {\n    assert(0 <=\
    \ l && l <= r && r <= n);\n    if (l == r) return 0;\n    return sum(r) - sum(l);\n\
    \  }\n\n  void reset() { fill(f.begin(), f.end(), T(0)); }\n\n  int n;\n  vector<T>\
    \ f;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/fenwick.hpp
  requiredBy:
  - data-structure/fenwick2d.hpp
  timestamp: '2022-09-29 23:49:51+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - data-structure/test/Point_Add_Range_Sum.test.cpp
  - data-structure/test/The_Maximum_Number_of_Overlaps.test.cpp
documentation_of: data-structure/fenwick.hpp
layout: document
title: Fenwick Tree
---
