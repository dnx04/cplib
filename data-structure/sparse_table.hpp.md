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
  bundledCode: "#line 1 \"data-structure/sparse_table.hpp\"\ntemplate <typename T>\n\
    struct sparse_table {\n  int n, k;\n  vector<vector<T>> st;\n  T f(T x = 1e9,\
    \ T y = 1e9) { return min(x, y); }\n  sparse_table(const vector<T> &v)\n     \
    \ : n(v.size()), k(__lg(n) + 1), st(n, vector<T>(k)) {\n    for (int i = 0; i\
    \ < n; ++i) st[i][0] = f(v[i]);\n    for (int j = 1; j < k; j++)\n      for (int\
    \ i = 0; i + (1 << j) <= n; ++i)\n        st[i][j] = f(st[i][j - 1], st[i + (1\
    \ << (j - 1))][j - 1]);\n  };\n  T query(int l, int r) {\n    T sum = 1e9;\n \
    \   for (int j = k - 1; j >= 0; --j) {\n      if ((1 << j) <= r - l + 1) {\n \
    \       sum = f(sum, st[l][j]);\n        l += 1 << j;\n      }\n    }\n    return\
    \ sum;\n  }\n};\n"
  code: "template <typename T>\nstruct sparse_table {\n  int n, k;\n  vector<vector<T>>\
    \ st;\n  T f(T x = 1e9, T y = 1e9) { return min(x, y); }\n  sparse_table(const\
    \ vector<T> &v)\n      : n(v.size()), k(__lg(n) + 1), st(n, vector<T>(k)) {\n\
    \    for (int i = 0; i < n; ++i) st[i][0] = f(v[i]);\n    for (int j = 1; j <\
    \ k; j++)\n      for (int i = 0; i + (1 << j) <= n; ++i)\n        st[i][j] = f(st[i][j\
    \ - 1], st[i + (1 << (j - 1))][j - 1]);\n  };\n  T query(int l, int r) {\n   \
    \ T sum = 1e9;\n    for (int j = k - 1; j >= 0; --j) {\n      if ((1 << j) <=\
    \ r - l + 1) {\n        sum = f(sum, st[l][j]);\n        l += 1 << j;\n      }\n\
    \    }\n    return sum;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2022-06-18 21:51:03+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data-structure/test/Static_RMQ.test.cpp
documentation_of: data-structure/sparse_table.hpp
layout: document
redirect_from:
- /library/data-structure/sparse_table.hpp
- /library/data-structure/sparse_table.hpp.html
title: data-structure/sparse_table.hpp
---
