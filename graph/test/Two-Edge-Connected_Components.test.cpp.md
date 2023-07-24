---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/lowlink.hpp
    title: graph/lowlink.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"graph/test/Two-Edge-Connected_Components.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n\n\
    #include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\n\
    #line 1 \"graph/lowlink.hpp\"\nstruct lowlink {\n  int V;  // # of vertices\n\
    \  int E;  // # of edges\n  int k;\n  vector<vector<pair<int, int>>> to;\n  vector<pair<int,\
    \ int>> edges;\n  vector<int> root_ids;  \n\n  vector<int> is_bridge;  // Whether\
    \ edge i is bridge or not, size = E\n  vector<int> is_articulation;  // whether\
    \ vertex i is articulation point\n                                     // or not,\
    \ size = V\n\n  // low_link\n  vector<int> order;            \n  vector<int> low_link;\
    \         \n  vector<int> is_dfstree_edge;  \n\n  int tecc_num;             \n\
    \  vector<int> tecc_id;  \n\n  int tvcc_num;              \n  vector<int> tvcc_id;\
    \  \n\n  lowlink(int V)\n      : V(V),\n        E(0),\n        k(0),\n       \
    \ to(V),\n        is_articulation(V, 0),\n        order(V, -1),\n        low_link(V,\
    \ -1),\n        tecc_num(0),\n        tvcc_num(0) {}\n\n  void add_edge(int v1,\
    \ int v2) {\n    assert(v1 >= 0 and v1 < V);\n    assert(v2 >= 0 and v2 < V);\n\
    \    to[v1].emplace_back(v2, E);\n    to[v2].emplace_back(v1, E);\n    edges.emplace_back(v1,\
    \ v2);\n    is_bridge.push_back(0);\n    is_dfstree_edge.push_back(0);\n    tvcc_id.push_back(-1);\n\
    \    E++;\n  }\n\n  vector<int> edge_stack;\n  int root_now;\n\n  // Build DFS\
    \ tree\n  // Complexity: O(V + E)\n  void dfs_lowlink(int now, int prv_eid = -1)\
    \ {\n    if (prv_eid < 0) root_now = k;\n    if (prv_eid == -1) root_ids.push_back(now);\n\
    \    order[now] = low_link[now] = k++;\n    for (const auto &nxt : to[now]) {\n\
    \      if (nxt.second == prv_eid) continue;\n      if (order[nxt.first] < order[now])\
    \ edge_stack.push_back(nxt.second);\n      if (order[nxt.first] >= 0) {\n    \
    \    low_link[now] = min(low_link[now], order[nxt.first]);\n      } else {\n \
    \       is_dfstree_edge[nxt.second] = 1;\n        dfs_lowlink(nxt.first, nxt.second);\n\
    \        low_link[now] = min(low_link[now], low_link[nxt.first]);\n\n        if\
    \ ((order[now] == root_now and order[nxt.first] != root_now + 1) or\n        \
    \    (order[now] != root_now and low_link[nxt.first] >= order[now])) {\n     \
    \     is_articulation[now] = 1;\n        }\n        if (low_link[nxt.first] >=\
    \ order[now]) {\n          while (true) {\n            int e = edge_stack.back();\n\
    \            tvcc_id[e] = tvcc_num;\n            edge_stack.pop_back();\n    \
    \        if (e == nxt.second) break;\n          }\n          tvcc_num++;\n   \
    \     }\n      }\n    }\n  }\n\n  void build() {\n    for (int v = 0; v < V; ++v)\
    \ {\n      if (order[v] < 0) dfs_lowlink(v);\n    }\n\n    // Find all bridges\n\
    \    // Complexity: O(V + E)\n    for (int i = 0; i < E; i++) {\n      int v1\
    \ = edges[i].first, v2 = edges[i].second;\n      if (order[v1] > order[v2]) swap(v1,\
    \ v2);\n      is_bridge[i] = order[v1] < low_link[v2];\n    }\n  }\n\n  // Find\
    \ two-edge-connected components and classify all vertices\n  // Complexity: O(V\
    \ + E)\n  vector<vector<int>> two_edge_connected_components() {\n    build();\n\
    \    tecc_num = 0;\n    tecc_id.assign(V, -1);\n\n    vector<int> st;\n    for\
    \ (int i = 0; i < V; i++) {\n      if (tecc_id[i] != -1) continue;\n      tecc_id[i]\
    \ = tecc_num;\n      st.push_back(i);\n      while (!st.empty()) {\n        int\
    \ now = st.back();\n        st.pop_back();\n        for (const auto &edge : to[now])\
    \ {\n          int nxt = edge.first;\n          if (tecc_id[nxt] >= 0 or is_bridge[edge.second])\
    \ continue;\n          tecc_id[nxt] = tecc_num;\n          st.push_back(nxt);\n\
    \        }\n      }\n      ++tecc_num;\n    }\n    vector<vector<int>> ret(tecc_num);\n\
    \    for (int i = 0; i < V; ++i) ret[tecc_id[i]].push_back(i);\n    return ret;\n\
    \  }\n\n  // Find biconnected components and enumerate vertices for each component.\n\
    \  // Complexity: O(V \\log V + E)\n  vector<vector<int>> biconnected_components_by_vertices()\
    \ {\n    build();\n    vector<vector<int>> ret(tvcc_num);\n    for (int i = 0;\
    \ i < E; ++i) {\n      ret[tvcc_id[i]].push_back(edges[i].first);\n      ret[tvcc_id[i]].push_back(edges[i].second);\n\
    \    }\n\n    for (auto &vec : ret) {\n      sort(vec.begin(), vec.end());\n \
    \     vec.erase(unique(vec.begin(), vec.end()), vec.end());\n    }\n\n    for\
    \ (int i = 0; i < V; ++i) {\n      if (to[i].empty()) ret.push_back({i});\n  \
    \  }\n\n    return ret;\n  }\n\n  // Find biconnected components and classify\
    \ all edges\n  // Complexity: O(V + E)\n  vector<vector<int>> biconnected_components_by_edges()\
    \ {\n    build();\n    vector<vector<int>> ret(tvcc_num);\n    for (int i = 0;\
    \ i < E; ++i) ret[tvcc_id[i]].push_back(i);\n    return ret;\n  }\n};\n#line 10\
    \ \"graph/test/Two-Edge-Connected_Components.test.cpp\"\n\nvoid solve(int ith)\
    \ {\n  int n, m;\n  cin >> n >> m;\n  lowlink t(n);\n  for (int i = 0; i < m;\
    \ ++i) {\n    int u, v;\n    cin >> u >> v;\n    t.add_edge(u, v);\n  }\n  auto\
    \ comps = t.two_edge_connected_components();\n  cout << comps.size() << '\\n';\n\
    \  for (auto c : comps) {\n    cout << c.size() << ' ';\n    for (auto v : c)\
    \ cout << v << ' ';\n    cout << '\\n';\n  }\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >>\
    \ tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    \n#include \"../lowlink.hpp\"\n\nvoid solve(int ith) {\n  int n, m;\n  cin >>\
    \ n >> m;\n  lowlink t(n);\n  for (int i = 0; i < m; ++i) {\n    int u, v;\n \
    \   cin >> u >> v;\n    t.add_edge(u, v);\n  }\n  auto comps = t.two_edge_connected_components();\n\
    \  cout << comps.size() << '\\n';\n  for (auto c : comps) {\n    cout << c.size()\
    \ << ' ';\n    for (auto v : c) cout << v << ' ';\n    cout << '\\n';\n  }\n}\n\
    \nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}"
  dependsOn:
  - graph/lowlink.hpp
  isVerificationFile: true
  path: graph/test/Two-Edge-Connected_Components.test.cpp
  requiredBy: []
  timestamp: '2023-07-25 00:50:50+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/test/Two-Edge-Connected_Components.test.cpp
layout: document
redirect_from:
- /verify/graph/test/Two-Edge-Connected_Components.test.cpp
- /verify/graph/test/Two-Edge-Connected_Components.test.cpp.html
title: graph/test/Two-Edge-Connected_Components.test.cpp
---
