---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/lca.hpp
    title: Lowest Common Ancestor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"tree/test/Lowest_Common_Ancestor.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\n#line 2 \"tree/lca.hpp\"\n\nstruct lca {\n  int n, l;\n  vector<int>\
    \ in, out, depth;\n  vector<vector<int>> up;\n  lca(const vector<vector<int>>\
    \ &g, int root)\n      : n(g.size()),\n        l(__lg(n) + 1),\n        in(n),\n\
    \        out(n),\n        depth(n),\n        up(n, vector<int>(l)) {\n    int\
    \ timer = 0;\n    auto dfs = [&](auto dfs, int p, int u, int d = 0) -> void {\n\
    \      in[u] = timer++;\n      up[u][0] = p;\n      depth[u] = d;\n      for (int\
    \ i = 1; i < l; ++i) {\n        up[u][i] = up[up[u][i - 1]][i - 1];\n      }\n\
    \      for (auto v : g[u])\n        if (v != p) dfs(dfs, u, v, d + 1);\n     \
    \ out[u] = timer++;\n    };\n    dfs(dfs, root, root);\n  };\n  bool is_anc(int\
    \ u, int v) const { return in[u] <= in[v] && out[u] >= out[v]; }\n  int dist(int\
    \ u, int v) const {\n    return depth[u] + depth[v] - 2 * depth[get(u, v)];\n\
    \  }\n  int get(int u, int v) const {\n    if (is_anc(u, v)) return u;\n    if\
    \ (is_anc(v, u)) return v;\n    for (int i = l - 1; i >= 0; --i) {\n      if (!is_anc(up[u][i],\
    \ v)) u = up[u][i];\n    }\n    return up[u][0];\n  }\n};\n#line 8 \"tree/test/Lowest_Common_Ancestor.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  int n, q;\n  cin >> n >> q;\n  vector<vector<int>> g(n);\n  for (int i = 1;\
    \ i < n; ++i) {\n    int p;\n    cin >> p;\n    g[p].push_back(i), g[i].push_back(p);\n\
    \  }\n  auto lca_tree = lca(g, 0);\n  while (q--) {\n    int u, v;\n    cin >>\
    \ u >> v;\n    cout << lca_tree.get(u, v) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n#include \"tree/lca.hpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  int n, q;\n  cin >> n >>\
    \ q;\n  vector<vector<int>> g(n);\n  for (int i = 1; i < n; ++i) {\n    int p;\n\
    \    cin >> p;\n    g[p].push_back(i), g[i].push_back(p);\n  }\n  auto lca_tree\
    \ = lca(g, 0);\n  while (q--) {\n    int u, v;\n    cin >> u >> v;\n    cout <<\
    \ lca_tree.get(u, v) << '\\n';\n  }\n}\n"
  dependsOn:
  - tree/lca.hpp
  isVerificationFile: true
  path: tree/test/Lowest_Common_Ancestor.test.cpp
  requiredBy: []
  timestamp: '2022-09-29 23:49:51+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tree/test/Lowest_Common_Ancestor.test.cpp
layout: document
redirect_from:
- /verify/tree/test/Lowest_Common_Ancestor.test.cpp
- /verify/tree/test/Lowest_Common_Ancestor.test.cpp.html
title: tree/test/Lowest_Common_Ancestor.test.cpp
---
