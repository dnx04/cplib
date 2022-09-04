---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/2sat.hpp
    title: graph/2sat.hpp
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"graph/test/2_Sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    \n#line 2 \"graph/scc.hpp\"\n\nstruct scc {\n  vector<vector<int>> g;\n  int n;\n\
    \  vector<int> num, low, current, S;\n  int counter;\n  vector<int> id;\n  vector<vector<int>>\
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
    \ < id[i + n];\n    }\n    return {true, sol};\n  }\n};\n#line 10 \"graph/test/2_Sat.test.cpp\"\
    \n\nvoid solve(int ith) {\n  int n, m;\n  string rid;\n  cin >> rid >> rid >>\
    \ n >> m;\n  twosat ts(n);\n  for (int i = 0; i < m; ++i) {\n    int x, y;\n \
    \   cin >> x >> y >> rid;\n    ts.add_clause(x > 0, abs(x) - 1, y > 0, abs(y)\
    \ - 1);\n  }\n  auto res = ts.solve();\n  if (res.first) {\n    cout << \"s SATISFIABLE\\\
    n\";\n    cout << \"v \";\n    for (int i = 0; i < n; ++i) {\n      cout << (res.second[i]\
    \ ? i + 1 : -(i + 1)) << ' ';\n    }\n    cout << 0;\n  } else\n    cout << \"\
    s UNSATISFIABLE\";\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr),\
    \ cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >> tc;\n  for (int i =\
    \ 1; i <= tc; ++i) solve(i);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\n\n#include \"../2sat.hpp\"\n\n\
    void solve(int ith) {\n  int n, m;\n  string rid;\n  cin >> rid >> rid >> n >>\
    \ m;\n  twosat ts(n);\n  for (int i = 0; i < m; ++i) {\n    int x, y;\n    cin\
    \ >> x >> y >> rid;\n    ts.add_clause(x > 0, abs(x) - 1, y > 0, abs(y) - 1);\n\
    \  }\n  auto res = ts.solve();\n  if (res.first) {\n    cout << \"s SATISFIABLE\\\
    n\";\n    cout << \"v \";\n    for (int i = 0; i < n; ++i) {\n      cout << (res.second[i]\
    \ ? i + 1 : -(i + 1)) << ' ';\n    }\n    cout << 0;\n  } else\n    cout << \"\
    s UNSATISFIABLE\";\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr),\
    \ cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >> tc;\n  for (int i =\
    \ 1; i <= tc; ++i) solve(i);\n}"
  dependsOn:
  - graph/2sat.hpp
  - graph/scc.hpp
  isVerificationFile: true
  path: graph/test/2_Sat.test.cpp
  requiredBy: []
  timestamp: '2022-09-04 10:58:20+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/test/2_Sat.test.cpp
layout: document
redirect_from:
- /verify/graph/test/2_Sat.test.cpp
- /verify/graph/test/2_Sat.test.cpp.html
title: graph/test/2_Sat.test.cpp
---
