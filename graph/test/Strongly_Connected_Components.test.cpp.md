---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: Strongly Connected Component
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"graph/test/Strongly_Connected_Components.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\n\n#line 2 \"graph/scc.hpp\"\n\
    \nstruct scc {\n  vector<vector<int>> g;\n  int n;\n  vector<int> num, low, current,\
    \ S;\n  int counter;\n  vector<int> id;\n  vector<vector<int>> scc_list;\n\n \
    \ scc(int n)\n      : g(n),\n        n(n),\n        num(n, -1),\n        low(n,\
    \ 0),\n        current(n, 0),\n        counter(0),\n        id(n, -1) {}\n\n \
    \ void add_edge(int u, int v) { g[u].push_back(v); }\n\n  void dfs(int u) {\n\
    \    low[u] = num[u] = counter++;\n    S.push_back(u);\n    current[u] = 1;\n\
    \    for (auto v : g[u]) {\n      if (num[v] == -1) dfs(v);\n      if (current[v])\
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
    \ 0) roots.push_back(u);\n    return {dag, roots};\n  }\n};\n#line 10 \"graph/test/Strongly_Connected_Components.test.cpp\"\
    \n\nvoid solve(int ith) {\n  int n, m;\n  cin >> n >> m;\n  scc g(n);\n  for (int\
    \ i = 0; i < m; ++i) {\n    int u, v;\n    cin >> u >> v;\n    g.add_edge(u, v);\n\
    \  }\n  g.build();\n  auto comp = g.scc_list;\n  cout << comp.size() << '\\n';\n\
    \  for (auto c : comp) {\n    cout << c.size() << ' ';\n    for (auto v : c) cout\
    \ << v << ' ';\n    cout << '\\n';\n  }\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >>\
    \ tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\n\n#include \"../scc.hpp\"\n\n\
    void solve(int ith) {\n  int n, m;\n  cin >> n >> m;\n  scc g(n);\n  for (int\
    \ i = 0; i < m; ++i) {\n    int u, v;\n    cin >> u >> v;\n    g.add_edge(u, v);\n\
    \  }\n  g.build();\n  auto comp = g.scc_list;\n  cout << comp.size() << '\\n';\n\
    \  for (auto c : comp) {\n    cout << c.size() << ' ';\n    for (auto v : c) cout\
    \ << v << ' ';\n    cout << '\\n';\n  }\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >>\
    \ tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}"
  dependsOn:
  - graph/scc.hpp
  isVerificationFile: true
  path: graph/test/Strongly_Connected_Components.test.cpp
  requiredBy: []
  timestamp: '2022-09-12 10:17:10+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/test/Strongly_Connected_Components.test.cpp
layout: document
redirect_from:
- /verify/graph/test/Strongly_Connected_Components.test.cpp
- /verify/graph/test/Strongly_Connected_Components.test.cpp.html
title: graph/test/Strongly_Connected_Components.test.cpp
---
