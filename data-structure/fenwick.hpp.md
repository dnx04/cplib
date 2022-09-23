---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data-structure/test/Point_Add_Range_Sum.test.cpp
    title: data-structure/test/Point_Add_Range_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/fenwick.hpp\"\ntemplate <typename T>\nstruct\
    \ fenwick_tree {\n  fenwick_tree(int n) : n(n), f(n + 1) {}\n\n  // a[u] += val\n\
    \  void add(int u, T val) {\n    assert(0 <= u && u < n);\n    ++u;\n    while\
    \ (u <= n) {\n      f[u] += val;\n      u += u & -u;\n    }\n  }\n\n  // return\
    \ the sum of [0, u)\n  T sum(int u) const {\n    assert(0 <= u && u <= n);\n \
    \   T res = 0;\n    while (u) {\n      res += f[u];\n      u -= u & -u;\n    }\n\
    \    return res;\n  }\n\n  // return the sum of [l, r)\n  T sum(int l, int r)\
    \ const {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return 0;\n\
    \    return sum(r) - sum(l);\n  }\n\n  void reset() { fill(f.begin(), f.end(),\
    \ T(0)); }\n\n  int n;\n  vector<T> f;\n};\n"
  code: "template <typename T>\nstruct fenwick_tree {\n  fenwick_tree(int n) : n(n),\
    \ f(n + 1) {}\n\n  // a[u] += val\n  void add(int u, T val) {\n    assert(0 <=\
    \ u && u < n);\n    ++u;\n    while (u <= n) {\n      f[u] += val;\n      u +=\
    \ u & -u;\n    }\n  }\n\n  // return the sum of [0, u)\n  T sum(int u) const {\n\
    \    assert(0 <= u && u <= n);\n    T res = 0;\n    while (u) {\n      res +=\
    \ f[u];\n      u -= u & -u;\n    }\n    return res;\n  }\n\n  // return the sum\
    \ of [l, r)\n  T sum(int l, int r) const {\n    assert(0 <= l && l <= r && r <=\
    \ n);\n    if (l == r) return 0;\n    return sum(r) - sum(l);\n  }\n\n  void reset()\
    \ { fill(f.begin(), f.end(), T(0)); }\n\n  int n;\n  vector<T> f;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/fenwick.hpp
  requiredBy: []
  timestamp: '2022-09-23 09:40:42+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data-structure/test/Point_Add_Range_Sum.test.cpp
documentation_of: data-structure/fenwick.hpp
layout: document
redirect_from:
- /library/data-structure/fenwick.hpp
- /library/data-structure/fenwick.hpp.html
title: data-structure/fenwick.hpp
---
