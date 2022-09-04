---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/test/2_Sat.test.cpp
    title: graph/test/2_Sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ dfs(i);\n    }\n    reverse(begin(scc_graph), end(scc_graph));\n  }\n\n  //\
    \ build DAG of strongly connected components\n  // Returns: adjacency list of\
    \ DAG\n  vector<vector<int>> condense() {\n    vector<vector<int>> dag(scc_graph.size());\n\
    \    for (int u = 0; u < n; ++u) {\n      int x = id[u];\n      for (int v : g[u])\
    \ {\n        int y = id[v];\n        if (x != y) {\n          dag[x].push_back(y);\n\
    \        }\n      }\n    }\n    return dag;\n  }\n};\n#line 2 \"graph/2sat.hpp\"\
    \n\nstruct twosat : scc {\n  int n;\n  vector<int> sol;\n  twosat(int n) : n(n),\
    \ scc(2 * n), sol(n) {}\n\n  // add 2-SAT clause\n  void add_clause(bool is_x_true,\
    \ int x, bool is_y_true, int y) {\n    assert(x >= 0 && x < n);\n    assert(y\
    \ >= 0 && y < n);\n    if (!is_x_true) x += n;\n    if (!is_y_true) y += n;\n\
    \    // x || y\n    // !x -> y\n    // !y -> x\n    add_edge((x + n) % (2 * n),\
    \ y);\n    add_edge((y + n) % (2 * n), x);\n  }\n\n  // Returns:\n  // If no sol\
    \ -> returns {false, {}}\n  // If has sol -> returns {true, sol}\n  //    where\
    \ |sol| = n, sol = true / false\n  pair<bool, vector<bool>> solve() {\n    build();\n\
    \    vector<bool> sol(n);\n    for (int i = 0; i < n; i++) {\n      if (id[i]\
    \ == id[i + n]) {\n        return {false, {}};\n      }\n      sol[i] = id[i]\
    \ < id[i + n];\n    }\n    return {true, sol};\n  }\n};\n"
  code: "#include \"scc.hpp\"\n\nstruct twosat : scc {\n  int n;\n  vector<int> sol;\n\
    \  twosat(int n) : n(n), scc(2 * n), sol(n) {}\n\n  // add 2-SAT clause\n  void\
    \ add_clause(bool is_x_true, int x, bool is_y_true, int y) {\n    assert(x >=\
    \ 0 && x < n);\n    assert(y >= 0 && y < n);\n    if (!is_x_true) x += n;\n  \
    \  if (!is_y_true) y += n;\n    // x || y\n    // !x -> y\n    // !y -> x\n  \
    \  add_edge((x + n) % (2 * n), y);\n    add_edge((y + n) % (2 * n), x);\n  }\n\
    \n  // Returns:\n  // If no sol -> returns {false, {}}\n  // If has sol -> returns\
    \ {true, sol}\n  //    where |sol| = n, sol = true / false\n  pair<bool, vector<bool>>\
    \ solve() {\n    build();\n    vector<bool> sol(n);\n    for (int i = 0; i < n;\
    \ i++) {\n      if (id[i] == id[i + n]) {\n        return {false, {}};\n     \
    \ }\n      sol[i] = id[i] < id[i + n];\n    }\n    return {true, sol};\n  }\n\
    };"
  dependsOn:
  - graph/scc.hpp
  isVerificationFile: false
  path: graph/2sat.hpp
  requiredBy: []
  timestamp: '2022-09-04 10:58:20+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/test/2_Sat.test.cpp
documentation_of: graph/2sat.hpp
layout: document
redirect_from:
- /library/graph/2sat.hpp
- /library/graph/2sat.hpp.html
title: graph/2sat.hpp
---
