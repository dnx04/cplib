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
  bundledCode: "#line 2 \"data-structure/dsu_rollback.hpp\"\n\nstruct dsu_rollback\
    \ {\n  vector<int> data;\n  stack<pair<int, int>> history;\n  int inner_snap;\n\
    \n  dsu_rollback(int sz) : inner_snap(0) { data.assign(sz, -1); }\n\n  bool merge(int\
    \ x, int y) {\n    x = root(x), y = root(y);\n    history.emplace(x, data[x]);\n\
    \    history.emplace(y, data[y]);\n    if (x == y) return false;\n    if (data[x]\
    \ > data[y]) swap(x, y);\n    data[x] += data[y];\n    data[y] = x;\n    return\
    \ true;\n  }\n\n  int root(int k) {\n    if (data[k] < 0) return k;\n    return\
    \ root(data[k]);\n  }\n\n  int same(int x, int y) { return root(x) == root(y);\
    \ }\n\n  int size(int k) { return (-data[root(k)]); }\n\n  void undo() {\n   \
    \ data[history.top().first] = history.top().second;\n    history.pop();\n    data[history.top().first]\
    \ = history.top().second;\n    history.pop();\n  }\n\n  void snapshot() { inner_snap\
    \ = int(history.size() >> 1); }\n\n  int get_state() { return int(history.size()\
    \ >> 1); }\n\n  void rollback(int state = -1) {\n    if (state == -1) state =\
    \ inner_snap;\n    state <<= 1;\n    assert(state <= (int)history.size());\n \
    \   while (state < (int)history.size()) undo();\n  }\n};\n"
  code: "#pragma once\n\nstruct dsu_rollback {\n  vector<int> data;\n  stack<pair<int,\
    \ int>> history;\n  int inner_snap;\n\n  dsu_rollback(int sz) : inner_snap(0)\
    \ { data.assign(sz, -1); }\n\n  bool merge(int x, int y) {\n    x = root(x), y\
    \ = root(y);\n    history.emplace(x, data[x]);\n    history.emplace(y, data[y]);\n\
    \    if (x == y) return false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x]\
    \ += data[y];\n    data[y] = x;\n    return true;\n  }\n\n  int root(int k) {\n\
    \    if (data[k] < 0) return k;\n    return root(data[k]);\n  }\n\n  int same(int\
    \ x, int y) { return root(x) == root(y); }\n\n  int size(int k) { return (-data[root(k)]);\
    \ }\n\n  void undo() {\n    data[history.top().first] = history.top().second;\n\
    \    history.pop();\n    data[history.top().first] = history.top().second;\n \
    \   history.pop();\n  }\n\n  void snapshot() { inner_snap = int(history.size()\
    \ >> 1); }\n\n  int get_state() { return int(history.size() >> 1); }\n\n  void\
    \ rollback(int state = -1) {\n    if (state == -1) state = inner_snap;\n    state\
    \ <<= 1;\n    assert(state <= (int)history.size());\n    while (state < (int)history.size())\
    \ undo();\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dsu_rollback.hpp
  requiredBy: []
  timestamp: '2023-07-25 00:50:50+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/dsu_rollback.hpp
layout: document
title: Disjoint Set Union with Rollback
---
