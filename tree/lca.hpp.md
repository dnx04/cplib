---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tree/test/Lowest_Common_Ancestor.test.cpp
    title: tree/test/Lowest_Common_Ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/lca.hpp\"\n\nstruct lca {\n  int n, l;\n  vector<int>\
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
    \ v)) u = up[u][i];\n    }\n    return up[u][0];\n  }\n};\n"
  code: "#pragma once\n\nstruct lca {\n  int n, l;\n  vector<int> in, out, depth;\n\
    \  vector<vector<int>> up;\n  lca(const vector<vector<int>> &g, int root)\n  \
    \    : n(g.size()),\n        l(__lg(n) + 1),\n        in(n),\n        out(n),\n\
    \        depth(n),\n        up(n, vector<int>(l)) {\n    int timer = 0;\n    auto\
    \ dfs = [&](auto dfs, int p, int u, int d = 0) -> void {\n      in[u] = timer++;\n\
    \      up[u][0] = p;\n      depth[u] = d;\n      for (int i = 1; i < l; ++i) {\n\
    \        up[u][i] = up[up[u][i - 1]][i - 1];\n      }\n      for (auto v : g[u])\n\
    \        if (v != p) dfs(dfs, u, v, d + 1);\n      out[u] = timer++;\n    };\n\
    \    dfs(dfs, root, root);\n  };\n  bool is_anc(int u, int v) const { return in[u]\
    \ <= in[v] && out[u] >= out[v]; }\n  int dist(int u, int v) const {\n    return\
    \ depth[u] + depth[v] - 2 * depth[get(u, v)];\n  }\n  int get(int u, int v) const\
    \ {\n    if (is_anc(u, v)) return u;\n    if (is_anc(v, u)) return v;\n    for\
    \ (int i = l - 1; i >= 0; --i) {\n      if (!is_anc(up[u][i], v)) u = up[u][i];\n\
    \    }\n    return up[u][0];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: tree/lca.hpp
  requiredBy: []
  timestamp: '2022-09-29 23:49:51+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tree/test/Lowest_Common_Ancestor.test.cpp
documentation_of: tree/lca.hpp
layout: document
title: Lowest Common Ancestor
---
