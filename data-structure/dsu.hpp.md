---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data-structure/test/Unionfind.test.cpp
    title: data-structure/test/Unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/dsu.hpp\"\nstruct dsu {\n public:\n  dsu(int\
    \ _n) : n(_n), p(_n, -1) {}\n\n  int merge(int a, int b) {\n    assert(0 <= a\
    \ && a < n);\n    assert(0 <= b && b < n);\n    int x = head(a), y = head(b);\n\
    \    if (x == y) return x;\n    if (-p[x] < -p[y]) swap(x, y);\n    p[x] += p[y];\n\
    \    p[y] = x;\n    return x;\n  }\n\n  bool same(int a, int b) {\n    assert(0\
    \ <= a && a < n);\n    assert(0 <= b && b < n);\n    return head(a) == head(b);\n\
    \  }\n\n  int head(int a) {\n    assert(0 <= a && a < n);\n    if (p[a] < 0) return\
    \ a;\n    return p[a] = head(p[a]);\n  }\n\n  int size(int a) {\n    assert(0\
    \ <= a && a < n);\n    return -p[head(a)];\n  }\n\n  vector<vector<int>> groups()\
    \ {\n    vector<int> tmp(n), sz(n);\n    for (int i = 0; i < n; ++i) tmp[i] =\
    \ head(i), ++sz[tmp[i]];\n    vector<vector<int>> gr(n);\n    for (int i = 0;\
    \ i < n; ++i) gr[i].reserve(sz[i]);\n    for (int i = 0; i < n; ++i) gr[tmp[i]].push_back(i);\n\
    \    gr.erase(remove_if(begin(gr), end(gr),\n                       [&](const\
    \ vector<int>& v) { return v.empty(); }),\n             end(gr));\n    return\
    \ gr;\n  }\n\n private:\n  int n;\n  vector<int> p;\n};\n"
  code: "struct dsu {\n public:\n  dsu(int _n) : n(_n), p(_n, -1) {}\n\n  int merge(int\
    \ a, int b) {\n    assert(0 <= a && a < n);\n    assert(0 <= b && b < n);\n  \
    \  int x = head(a), y = head(b);\n    if (x == y) return x;\n    if (-p[x] < -p[y])\
    \ swap(x, y);\n    p[x] += p[y];\n    p[y] = x;\n    return x;\n  }\n\n  bool\
    \ same(int a, int b) {\n    assert(0 <= a && a < n);\n    assert(0 <= b && b <\
    \ n);\n    return head(a) == head(b);\n  }\n\n  int head(int a) {\n    assert(0\
    \ <= a && a < n);\n    if (p[a] < 0) return a;\n    return p[a] = head(p[a]);\n\
    \  }\n\n  int size(int a) {\n    assert(0 <= a && a < n);\n    return -p[head(a)];\n\
    \  }\n\n  vector<vector<int>> groups() {\n    vector<int> tmp(n), sz(n);\n   \
    \ for (int i = 0; i < n; ++i) tmp[i] = head(i), ++sz[tmp[i]];\n    vector<vector<int>>\
    \ gr(n);\n    for (int i = 0; i < n; ++i) gr[i].reserve(sz[i]);\n    for (int\
    \ i = 0; i < n; ++i) gr[tmp[i]].push_back(i);\n    gr.erase(remove_if(begin(gr),\
    \ end(gr),\n                       [&](const vector<int>& v) { return v.empty();\
    \ }),\n             end(gr));\n    return gr;\n  }\n\n private:\n  int n;\n  vector<int>\
    \ p;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dsu.hpp
  requiredBy: []
  timestamp: '2022-09-07 00:03:47+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data-structure/test/Unionfind.test.cpp
documentation_of: data-structure/dsu.hpp
layout: document
title: Disjoint Set Union (with Rank and Path Compression)
---
