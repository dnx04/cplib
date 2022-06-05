---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data-structure/test/union_find.test.cpp
    title: data-structure/test/union_find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/union_find.hpp\"\nstruct uf {\n public:\n\
    \  uf(int _n) : n(_n), p(_n, -1) {}\n\n  int merge(int a, int b) {\n    assert(0\
    \ <= a && a < n);\n    assert(0 <= b && b < n);\n    int x = head(a), y = head(b);\n\
    \    if (x == y) return x;\n    if (-p[x] < -p[y]) swap(x, y);\n    p[x] += p[y];\n\
    \    p[y] = x;\n    return x;\n  }\n\n  bool same(int a, int b) {\n    assert(0\
    \ <= a && a < n);\n    assert(0 <= b && b < n);\n    return head(a) == head(b);\n\
    \  }\n\n  int head(int a) {\n    assert(0 <= a && a < n);\n    if (p[a] < 0) return\
    \ a;\n    return p[a] = head(p[a]);\n  }\n\n  int size(int a) {\n    assert(0\
    \ <= a && a < n);\n    return -p[head(a)];\n  }\n\n private:\n  int n;\n  vector<int>\
    \ p;\n};\n"
  code: "struct uf {\n public:\n  uf(int _n) : n(_n), p(_n, -1) {}\n\n  int merge(int\
    \ a, int b) {\n    assert(0 <= a && a < n);\n    assert(0 <= b && b < n);\n  \
    \  int x = head(a), y = head(b);\n    if (x == y) return x;\n    if (-p[x] < -p[y])\
    \ swap(x, y);\n    p[x] += p[y];\n    p[y] = x;\n    return x;\n  }\n\n  bool\
    \ same(int a, int b) {\n    assert(0 <= a && a < n);\n    assert(0 <= b && b <\
    \ n);\n    return head(a) == head(b);\n  }\n\n  int head(int a) {\n    assert(0\
    \ <= a && a < n);\n    if (p[a] < 0) return a;\n    return p[a] = head(p[a]);\n\
    \  }\n\n  int size(int a) {\n    assert(0 <= a && a < n);\n    return -p[head(a)];\n\
    \  }\n\n private:\n  int n;\n  vector<int> p;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union_find.hpp
  requiredBy: []
  timestamp: '2022-06-05 22:18:42+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data-structure/test/union_find.test.cpp
documentation_of: data-structure/union_find.hpp
layout: document
redirect_from:
- /library/data-structure/union_find.hpp
- /library/data-structure/union_find.hpp.html
title: data-structure/union_find.hpp
---
