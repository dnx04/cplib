---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/2sat.hpp
    title: graph/2sat.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/test/2_Sat.test.cpp
    title: graph/test/2_Sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/test/Strongly_Connected_Components.test.cpp
    title: graph/test/Strongly_Connected_Components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/scc.hpp\"\n\nstruct scc {\n  vector<vector<int>> g;\n\
    \  int n;\n  vector<int> num, low, current, S;\n  int counter;\n  vector<int>\
    \ id;\n  vector<vector<int>> scc_list;\n\n  scc(int n)\n      : g(n),\n      \
    \  n(n),\n        num(n, -1),\n        low(n, 0),\n        current(n, 0),\n  \
    \      counter(0),\n        id(n, -1) {}\n\n  void add_edge(int u, int v) { g[u].push_back(v);\
    \ }\n\n  void dfs(int u) {\n    low[u] = num[u] = counter++;\n    S.push_back(u);\n\
    \    current[u] = 1;\n    for (auto v : g[u]) {\n      if (num[v] == -1) dfs(v);\n\
    \      if (current[v]) low[u] = min(low[u], low[v]);\n    }\n    if (low[u] ==\
    \ num[u]) {\n      scc_list.push_back(vector<int>());\n      while (1) {\n   \
    \     int v = S.back();\n        S.pop_back();\n        current[v] = 0;\n    \
    \    scc_list.back().push_back(v);\n        id[v] = (int)scc_list.size() - 1;\n\
    \        if (u == v) break;\n      }\n    }\n  }\n\n  // build scc_list\n  void\
    \ build() {\n    for (int i = 0; i < n; i++) {\n      if (num[i] == -1) dfs(i);\n\
    \    }\n    reverse(begin(scc_list), end(scc_list));\n  }\n\n  // build DAG of\
    \ strongly connected components\n  // Returns: adjacency list of DAG, and root\
    \ vertices (in-degree\n  // = 0)\n  pair<vector<vector<int>>, vector<int>> condense()\
    \ {\n    vector<vector<int>> dag(scc_list.size());\n    vector<int> roots, in(scc_list.size());\n\
    \    for (int u = 0; u < n; ++u) {\n      int x = id[u];\n      for (int v : g[u])\
    \ {\n        int y = id[v];\n        if (x != y) {\n          dag[x].push_back(y);\n\
    \          ++in[y];\n        }\n      }\n    }\n    for (int u = 0; u < (int)dag.size();\
    \ ++u)\n      if (in[u] == 0) roots.push_back(u);\n    return {dag, roots};\n\
    \  }\n};\n"
  code: "#pragma once\n\nstruct scc {\n  vector<vector<int>> g;\n  int n;\n  vector<int>\
    \ num, low, current, S;\n  int counter;\n  vector<int> id;\n  vector<vector<int>>\
    \ scc_list;\n\n  scc(int n)\n      : g(n),\n        n(n),\n        num(n, -1),\n\
    \        low(n, 0),\n        current(n, 0),\n        counter(0),\n        id(n,\
    \ -1) {}\n\n  void add_edge(int u, int v) { g[u].push_back(v); }\n\n  void dfs(int\
    \ u) {\n    low[u] = num[u] = counter++;\n    S.push_back(u);\n    current[u]\
    \ = 1;\n    for (auto v : g[u]) {\n      if (num[v] == -1) dfs(v);\n      if (current[v])\
    \ low[u] = min(low[u], low[v]);\n    }\n    if (low[u] == num[u]) {\n      scc_list.push_back(vector<int>());\n\
    \      while (1) {\n        int v = S.back();\n        S.pop_back();\n       \
    \ current[v] = 0;\n        scc_list.back().push_back(v);\n        id[v] = (int)scc_list.size()\
    \ - 1;\n        if (u == v) break;\n      }\n    }\n  }\n\n  // build scc_list\n\
    \  void build() {\n    for (int i = 0; i < n; i++) {\n      if (num[i] == -1)\
    \ dfs(i);\n    }\n    reverse(begin(scc_list), end(scc_list));\n  }\n\n  // build\
    \ DAG of strongly connected components\n  // Returns: adjacency list of DAG, and\
    \ root vertices (in-degree\n  // = 0)\n  pair<vector<vector<int>>, vector<int>>\
    \ condense() {\n    vector<vector<int>> dag(scc_list.size());\n    vector<int>\
    \ roots, in(scc_list.size());\n    for (int u = 0; u < n; ++u) {\n      int x\
    \ = id[u];\n      for (int v : g[u]) {\n        int y = id[v];\n        if (x\
    \ != y) {\n          dag[x].push_back(y);\n          ++in[y];\n        }\n   \
    \   }\n    }\n    for (int u = 0; u < (int)dag.size(); ++u)\n      if (in[u] ==\
    \ 0) roots.push_back(u);\n    return {dag, roots};\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy:
  - graph/2sat.hpp
  timestamp: '2022-09-12 10:17:10+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/test/2_Sat.test.cpp
  - graph/test/Strongly_Connected_Components.test.cpp
documentation_of: graph/scc.hpp
layout: document
redirect_from:
- /library/graph/scc.hpp
- /library/graph/scc.hpp.html
title: graph/scc.hpp
---
