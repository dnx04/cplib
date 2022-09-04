---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/2sat.hpp
    title: graph/2sat.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: graph/test/2_Sat.test.cpp
    title: graph/test/2_Sat.test.cpp
  - icon: ':x:'
    path: graph/test/Strongly_Connected_Components.test.cpp
    title: graph/test/Strongly_Connected_Components.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/scc.hpp\"\n\nstruct scc {\n  vector<vector<int>> g;\n\
    \  int n;\n  vector<int> num, low, current, S;\n  int counter;\n  vector<int>\
    \ id;\n  vector<vector<int>> scc_graph;\n\n  scc(int n)\n      : g(n),\n     \
    \   n(n),\n        num(n, -1),\n        low(n, 0),\n        current(n, 0),\n \
    \       counter(0),\n        id(n, -1) {}\n\n  void add_edge(int u, int v) { g[u].push_back(v);\
    \ }\n\n  void dfs(int u) {\n    low[u] = num[u] = counter++;\n    S.push_back(u);\n\
    \    current[u] = 1;\n    for (auto v : g[u]) {\n      if (num[v] == -1) dfs(v);\n\
    \      if (current[v]) low[u] = min(low[u], low[v]);\n    }\n    if (low[u] ==\
    \ num[u]) {\n      scc_graph.push_back(vector<int>());\n      while (1) {\n  \
    \      int v = S.back();\n        S.pop_back();\n        current[v] = 0;\n   \
    \     scc_graph.back().push_back(v);\n        id[v] = (int)scc_graph.size() -\
    \ 1;\n        if (u == v) break;\n      }\n    }\n  }\n\n  // build scc_graph\n\
    \  void build() {\n    for (int i = 0; i < n; i++) {\n      if (num[i] == -1)\
    \ dfs(i);\n    }\n  }\n\n  // build DAG of strongly connected components\n  //\
    \ Returns: adjacency list of DAG\n  vector<vector<int>> condense() {\n    vector<vector<int>>\
    \ dag(scc_graph.size());\n    for (int u = 0; u < n; ++u) {\n      int x = id[u];\n\
    \      for (int v : g[u]) {\n        int y = id[v];\n        if (x != y) {\n \
    \         dag[x].push_back(y);\n        }\n      }\n    }\n    return dag;\n \
    \ }\n};\n"
  code: "#pragma once\n\nstruct scc {\n  vector<vector<int>> g;\n  int n;\n  vector<int>\
    \ num, low, current, S;\n  int counter;\n  vector<int> id;\n  vector<vector<int>>\
    \ scc_graph;\n\n  scc(int n)\n      : g(n),\n        n(n),\n        num(n, -1),\n\
    \        low(n, 0),\n        current(n, 0),\n        counter(0),\n        id(n,\
    \ -1) {}\n\n  void add_edge(int u, int v) { g[u].push_back(v); }\n\n  void dfs(int\
    \ u) {\n    low[u] = num[u] = counter++;\n    S.push_back(u);\n    current[u]\
    \ = 1;\n    for (auto v : g[u]) {\n      if (num[v] == -1) dfs(v);\n      if (current[v])\
    \ low[u] = min(low[u], low[v]);\n    }\n    if (low[u] == num[u]) {\n      scc_graph.push_back(vector<int>());\n\
    \      while (1) {\n        int v = S.back();\n        S.pop_back();\n       \
    \ current[v] = 0;\n        scc_graph.back().push_back(v);\n        id[v] = (int)scc_graph.size()\
    \ - 1;\n        if (u == v) break;\n      }\n    }\n  }\n\n  // build scc_graph\n\
    \  void build() {\n    for (int i = 0; i < n; i++) {\n      if (num[i] == -1)\
    \ dfs(i);\n    }\n  }\n\n  // build DAG of strongly connected components\n  //\
    \ Returns: adjacency list of DAG\n  vector<vector<int>> condense() {\n    vector<vector<int>>\
    \ dag(scc_graph.size());\n    for (int u = 0; u < n; ++u) {\n      int x = id[u];\n\
    \      for (int v : g[u]) {\n        int y = id[v];\n        if (x != y) {\n \
    \         dag[x].push_back(y);\n        }\n      }\n    }\n    return dag;\n \
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy:
  - graph/2sat.hpp
  timestamp: '2022-09-04 10:50:22+07:00'
  verificationStatus: LIBRARY_ALL_WA
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
