---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tree/test/Tree_Diameter.test.cpp
    title: tree/test/Tree_Diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/tree_diameter.hpp\"\npair<ll, vector<int>> get_diameter(const\
    \ vector<vector<pair<int, int>>>& g) {\n  int n = g.size();\n  vector<ll> dist(n);\n\
    \  vector<int> parent(n);\n\n  auto dfs = [&](auto self, int u, int fu, ll cur_dist)\
    \ -> void {\n    dist[u] = cur_dist;\n    parent[u] = fu;\n    for (auto [v, cost]\
    \ : g[u])\n      if (v != fu) {\n        self(self, v, u, cur_dist + cost);\n\
    \      }\n  };\n  dfs(dfs, 0, -1, 0);\n  // r = furthest node from root\n  int\
    \ r = max_element(dist.begin(), dist.end()) - dist.begin();\n  dfs(dfs, r, -1,\
    \ 0);\n  // r->s = longest path\n  int s = max_element(dist.begin(), dist.end())\
    \ - dist.begin();\n\n  vector<int> path;\n  for (int x = s; x >= 0; x = parent[x])\
    \ path.push_back(x);\n\n  return {dist[s], path};\n}\n"
  code: "pair<ll, vector<int>> get_diameter(const vector<vector<pair<int, int>>>&\
    \ g) {\n  int n = g.size();\n  vector<ll> dist(n);\n  vector<int> parent(n);\n\
    \n  auto dfs = [&](auto self, int u, int fu, ll cur_dist) -> void {\n    dist[u]\
    \ = cur_dist;\n    parent[u] = fu;\n    for (auto [v, cost] : g[u])\n      if\
    \ (v != fu) {\n        self(self, v, u, cur_dist + cost);\n      }\n  };\n  dfs(dfs,\
    \ 0, -1, 0);\n  // r = furthest node from root\n  int r = max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\n  dfs(dfs, r, -1, 0);\n  // r->s = longest path\n\
    \  int s = max_element(dist.begin(), dist.end()) - dist.begin();\n\n  vector<int>\
    \ path;\n  for (int x = s; x >= 0; x = parent[x]) path.push_back(x);\n\n  return\
    \ {dist[s], path};\n}"
  dependsOn: []
  isVerificationFile: false
  path: tree/tree_diameter.hpp
  requiredBy: []
  timestamp: '2023-07-25 00:50:50+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tree/test/Tree_Diameter.test.cpp
documentation_of: tree/tree_diameter.hpp
layout: document
title: Tree Diameter
---
