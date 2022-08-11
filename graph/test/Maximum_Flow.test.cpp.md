---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/maxflow.hpp
    title: graph/maxflow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"graph/test/Maximum_Flow.test.cpp\"\n#define PROBLEM \\\n\
    \  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\n\n#include\
    \ <bits/extc++.h>\n\nusing namespace std;\nusing namespace __gnu_cxx;\nusing namespace\
    \ __gnu_pbds;\n\n#line 1 \"graph/maxflow.hpp\"\ntemplate <class Cap>\nstruct mf_graph\
    \ {\n public:\n  mf_graph() : _n(0) {}\n  explicit mf_graph(int n) : _n(n), g(n)\
    \ {}\n\n  int add_edge(int from, int to, Cap cap) {\n    assert(0 <= from && from\
    \ < _n);\n    assert(0 <= to && to < _n);\n    assert(0 <= cap);\n    int m =\
    \ int(pos.size());\n    pos.push_back({from, int(g[from].size())});\n    int from_id\
    \ = int(g[from].size());\n    int to_id = int(g[to].size());\n    if (from ==\
    \ to) to_id++;\n    g[from].push_back(_edge{to, to_id, cap});\n    g[to].push_back(_edge{from,\
    \ from_id, 0});\n    return m;\n  }\n\n  struct edge {\n    int from, to;\n  \
    \  Cap cap, flow;\n  };\n\n  edge get_edge(int i) {\n    int m = int(pos.size());\n\
    \    assert(0 <= i && i < m);\n    auto _e = g[pos[i].first][pos[i].second];\n\
    \    auto _re = g[_e.to][_e.rev];\n    return edge{pos[i].first, _e.to, _e.cap\
    \ + _re.cap, _re.cap};\n  }\n  vector<edge> edges() {\n    int m = int(pos.size());\n\
    \    vector<edge> result;\n    for (int i = 0; i < m; i++) {\n      result.push_back(get_edge(i));\n\
    \    }\n    return result;\n  }\n  void change_edge(int i, Cap new_cap, Cap new_flow)\
    \ {\n    int m = int(pos.size());\n    assert(0 <= i && i < m);\n    assert(0\
    \ <= new_flow && new_flow <= new_cap);\n    auto& _e = g[pos[i].first][pos[i].second];\n\
    \    auto& _re = g[_e.to][_e.rev];\n    _e.cap = new_cap - new_flow;\n    _re.cap\
    \ = new_flow;\n  }\n\n  Cap flow(int s, int t) { return flow(s, t, numeric_limits<Cap>::max());\
    \ }\n  Cap flow(int s, int t, Cap flow_limit) {\n    assert(0 <= s && s < _n);\n\
    \    assert(0 <= t && t < _n);\n    assert(s != t);\n\n    vector<int> level(_n),\
    \ iter(_n);\n    queue<int> que;\n\n    auto bfs = [&]() {\n      fill(level.begin(),\
    \ level.end(), -1);\n      level[s] = 0;\n      while (!que.empty()) que.pop();\n\
    \      que.push(s);\n      while (!que.empty()) {\n        int v = que.front();\n\
    \        que.pop();\n        for (auto e : g[v]) {\n          if (e.cap == 0 ||\
    \ level[e.to] >= 0) continue;\n          level[e.to] = level[v] + 1;\n       \
    \   if (e.to == t) return;\n          que.push(e.to);\n        }\n      }\n  \
    \  };\n    auto dfs = [&](auto self, int v, Cap up) {\n      if (v == s) return\
    \ up;\n      Cap res = 0;\n      int level_v = level[v];\n      for (int& i =\
    \ iter[v]; i < int(g[v].size()); i++) {\n        _edge& e = g[v][i];\n       \
    \ if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;\n        Cap\
    \ d = self(self, e.to, min(up - res, g[e.to][e.rev].cap));\n        if (d <= 0)\
    \ continue;\n        g[v][i].cap += d;\n        g[e.to][e.rev].cap -= d;\n   \
    \     res += d;\n        if (res == up) return res;\n      }\n      level[v] =\
    \ _n;\n      return res;\n    };\n\n    Cap flow = 0;\n    while (flow < flow_limit)\
    \ {\n      bfs();\n      if (level[t] == -1) break;\n      fill(iter.begin(),\
    \ iter.end(), 0);\n      Cap f = dfs(dfs, t, flow_limit - flow);\n      if (!f)\
    \ break;\n      flow += f;\n    }\n    return flow;\n  }\n\n  vector<bool> min_cut(int\
    \ s) {\n    vector<bool> visited(_n);\n    queue<int> que;\n    que.push(s);\n\
    \    while (!que.empty()) {\n      int p = que.front();\n      que.pop();\n  \
    \    visited[p] = true;\n      for (auto e : g[p]) {\n        if (e.cap && !visited[e.to])\
    \ {\n          visited[e.to] = true;\n          que.push(e.to);\n        }\n \
    \     }\n    }\n    return visited;\n  }\n\n private:\n  int _n;\n  struct _edge\
    \ {\n    int to, rev;\n    Cap cap;\n  };\n  vector<pair<int, int>> pos;\n  vector<vector<_edge>>\
    \ g;\n};\n#line 11 \"graph/test/Maximum_Flow.test.cpp\"\n\nsigned main() {\n \
    \ int n, m;\n  cin >> n >> m;\n  mf_graph<int> g(n);\n  for (int i = 0; i < m;\
    \ ++i) {\n    int a, b, c;\n    cin >> a >> b >> c;\n    g.add_edge(a, b, c);\n\
    \  }\n  cout << g.flow(0, n - 1) << '\\n';\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include <bits/extc++.h>\n\nusing namespace std;\nusing namespace __gnu_cxx;\n\
    using namespace __gnu_pbds;\n\n#include \"../maxflow.hpp\"\n\nsigned main() {\n\
    \  int n, m;\n  cin >> n >> m;\n  mf_graph<int> g(n);\n  for (int i = 0; i < m;\
    \ ++i) {\n    int a, b, c;\n    cin >> a >> b >> c;\n    g.add_edge(a, b, c);\n\
    \  }\n  cout << g.flow(0, n - 1) << '\\n';\n}"
  dependsOn:
  - graph/maxflow.hpp
  isVerificationFile: true
  path: graph/test/Maximum_Flow.test.cpp
  requiredBy: []
  timestamp: '2022-08-11 20:11:38+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/test/Maximum_Flow.test.cpp
layout: document
redirect_from:
- /verify/graph/test/Maximum_Flow.test.cpp
- /verify/graph/test/Maximum_Flow.test.cpp.html
title: graph/test/Maximum_Flow.test.cpp
---
