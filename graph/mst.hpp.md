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
  bundledCode: "#line 1 \"graph/mst.hpp\"\n// Kruskal algorithm for minimum spanning\
    \ tree\nauto mst = [](const vector<vector<pair<int, int>>>& g) -> ll {\n  using\
    \ edge = tuple<ll, int, int>;\n  int n = g.size();\n  dsu uf(n);\n  priority_queue<edge,\
    \ vector<edge>, greater<edge>> pq;\n  for (int i = 0; i < n; ++i) {\n    for (auto\
    \ [j, w] : g[i]) {\n      pq.emplace(w, i, j);\n    }\n  }\n  ll res = 0;\n  while\
    \ (!pq.empty()) {\n    auto [w, i, j] = pq.top();\n    pq.pop();\n    if (!uf.same(i,\
    \ j)) {\n      res += w;\n      uf.merge(i, j);\n    }\n  }\n  if (uf.groups().size()\
    \ >= 2) return -1;\n  return res;\n};\n"
  code: "// Kruskal algorithm for minimum spanning tree\nauto mst = [](const vector<vector<pair<int,\
    \ int>>>& g) -> ll {\n  using edge = tuple<ll, int, int>;\n  int n = g.size();\n\
    \  dsu uf(n);\n  priority_queue<edge, vector<edge>, greater<edge>> pq;\n  for\
    \ (int i = 0; i < n; ++i) {\n    for (auto [j, w] : g[i]) {\n      pq.emplace(w,\
    \ i, j);\n    }\n  }\n  ll res = 0;\n  while (!pq.empty()) {\n    auto [w, i,\
    \ j] = pq.top();\n    pq.pop();\n    if (!uf.same(i, j)) {\n      res += w;\n\
    \      uf.merge(i, j);\n    }\n  }\n  if (uf.groups().size() >= 2) return -1;\n\
    \  return res;\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/mst.hpp
  requiredBy: []
  timestamp: '2022-09-07 00:03:47+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/mst.hpp
layout: document
redirect_from:
- /library/graph/mst.hpp
- /library/graph/mst.hpp.html
title: graph/mst.hpp
---
