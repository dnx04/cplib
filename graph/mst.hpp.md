---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/dsu.hpp
    title: Disjoint Set Union (with Rank and Path Compression)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: graph/test/Minimum_Spanning_Tree.test.cpp
    title: graph/test/Minimum_Spanning_Tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/mst.hpp\"\n// Kruskal algorithm for minimum spanning\
    \ tree\n#line 1 \"data-structure/dsu.hpp\"\nstruct dsu {\n public:\n  dsu(int\
    \ n) : n(n), p(n, -1) {}\n\n  int merge(int a, int b) {\n    assert(0 <= a &&\
    \ a < n);\n    assert(0 <= b && b < n);\n    int x = head(a), y = head(b);\n \
    \   if (x == y) return x;\n    if (-p[x] < -p[y]) swap(x, y);\n    p[x] += p[y];\n\
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
    \ gr;\n  }\n\n private:\n  int n;\n  vector<int> p;\n};\n#line 3 \"graph/mst.hpp\"\
    \n\nauto mst = [](const vector<vector<pair<int, int>>>& g) -> ll {\n  using edge\
    \ = tuple<ll, int, int>;\n  int n = g.size();\n  dsu uf(n);\n  priority_queue<edge,\
    \ vector<edge>, greater<edge>> pq;\n  for (int i = 0; i < n; ++i) {\n    for (auto\
    \ [j, w] : g[i]) {\n      pq.emplace(w, i, j);\n    }\n  }\n  ll res = 0;\n  while\
    \ (!pq.empty()) {\n    auto [w, i, j] = pq.top();\n    pq.pop();\n    if (!uf.same(i,\
    \ j)) {\n      res += w;\n      uf.merge(i, j);\n    }\n  }\n  return res;\n};\n"
  code: "// Kruskal algorithm for minimum spanning tree\n#include \"data-structure/dsu.hpp\"\
    \n\nauto mst = [](const vector<vector<pair<int, int>>>& g) -> ll {\n  using edge\
    \ = tuple<ll, int, int>;\n  int n = g.size();\n  dsu uf(n);\n  priority_queue<edge,\
    \ vector<edge>, greater<edge>> pq;\n  for (int i = 0; i < n; ++i) {\n    for (auto\
    \ [j, w] : g[i]) {\n      pq.emplace(w, i, j);\n    }\n  }\n  ll res = 0;\n  while\
    \ (!pq.empty()) {\n    auto [w, i, j] = pq.top();\n    pq.pop();\n    if (!uf.same(i,\
    \ j)) {\n      res += w;\n      uf.merge(i, j);\n    }\n  }\n  return res;\n};"
  dependsOn:
  - data-structure/dsu.hpp
  isVerificationFile: false
  path: graph/mst.hpp
  requiredBy: []
  timestamp: '2022-09-28 10:01:57+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - graph/test/Minimum_Spanning_Tree.test.cpp
documentation_of: graph/mst.hpp
layout: document
redirect_from:
- /library/graph/mst.hpp
- /library/graph/mst.hpp.html
title: graph/mst.hpp
---
