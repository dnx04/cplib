---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/tree_diameter.hpp
    title: graph/tree_diameter.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"graph/test/Tree_Diameter.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include <bits/stdc++.h>\n\n\
    using namespace std;\n\nusing ll = long long;\n\n#line 1 \"graph/tree_diameter.hpp\"\
    \npair<ll, vector<int>> get_diameter(const vector<vector<pair<int, int>>>& g)\
    \ {\n  int n = g.size();\n  vector<ll> dist(n);\n  vector<int> parent(n);\n\n\
    \  auto dfs = [&](auto self, int u, int fu, ll cur_dist) -> void {\n    dist[u]\
    \ = cur_dist;\n    parent[u] = fu;\n    for (auto [v, cost] : g[u])\n      if\
    \ (v != fu) {\n        self(self, v, u, cur_dist + cost);\n      }\n  };\n  dfs(dfs,\
    \ 0, -1, 0);\n  // r = furthest node from root\n  int r = max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\n  dfs(dfs, r, -1, 0);\n  // r->s = longest path\n\
    \  int s = max_element(dist.begin(), dist.end()) - dist.begin();\n\n  vector<int>\
    \ path;\n  for (int x = s; x >= 0; x = parent[x]) path.push_back(x);\n\n  return\
    \ {dist[s], path};\n}\n#line 10 \"graph/test/Tree_Diameter.test.cpp\"\n\nvoid\
    \ solve(int ith) {\n  int n;\n  cin >> n;\n  vector<vector<pair<int, int>>> tree(n);\n\
    \  for(int i = 0; i < n - 1; ++i){\n    int u, v, w;\n    cin >> u >> v >> w;\n\
    \    tree[u].emplace_back(v, w);\n    tree[v].emplace_back(u, w);\n  }\n  auto\
    \ [diameter, path] = get_diameter(tree);\n  cout << diameter << ' ' << path.size()\
    \ << '\\n';\n  for(auto v: path) cout << v << ' ';\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >>\
    \ tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\n#include\
    \ \"../tree_diameter.hpp\"\n\nvoid solve(int ith) {\n  int n;\n  cin >> n;\n \
    \ vector<vector<pair<int, int>>> tree(n);\n  for(int i = 0; i < n - 1; ++i){\n\
    \    int u, v, w;\n    cin >> u >> v >> w;\n    tree[u].emplace_back(v, w);\n\
    \    tree[v].emplace_back(u, w);\n  }\n  auto [diameter, path] = get_diameter(tree);\n\
    \  cout << diameter << ' ' << path.size() << '\\n';\n  for(auto v: path) cout\
    \ << v << ' ';\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr),\
    \ cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >> tc;\n  for (int i =\
    \ 1; i <= tc; ++i) solve(i);\n}"
  dependsOn:
  - graph/tree_diameter.hpp
  isVerificationFile: true
  path: graph/test/Tree_Diameter.test.cpp
  requiredBy: []
  timestamp: '2022-09-04 19:05:25+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/test/Tree_Diameter.test.cpp
layout: document
redirect_from:
- /verify/graph/test/Tree_Diameter.test.cpp
- /verify/graph/test/Tree_Diameter.test.cpp.html
title: graph/test/Tree_Diameter.test.cpp
---
