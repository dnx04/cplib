---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/bipartite_matching.hpp\"\n// Max Bipartite matching.\n\
    // Index from 0\n// Assume 2 sides have same number of vertices\n//\n// Notes:\n\
    // - If TLE --> try shuffle edges\n//   REP(i,n) shuffle(ke[i].begin(), ke[i].end(),\
    \ rng)\n// - It should be quite fast, can AC 10^5 vertices\n\nstruct bipartite_matching\
    \ {\n  int n;\n  vector<vector<int> > ke;\n  vector<int> seen;\n  vector<int>\
    \ matchL, matchR;\n  int iteration;\n\n  bipartite_matching(int _n)\n      : n(_n),\n\
    \        ke(_n),\n        seen(_n, false),\n        matchL(_n, -1),\n        matchR(_n,\
    \ -1),\n        iteration{0} {}\n\n  void add_edge(int u, int v) { ke[u].push_back(v);\
    \ }\n\n  bool dfs(int u) {\n    seen[u] = iteration;\n    for (int v : ke[u])\
    \ {\n      if (matchR[v] < 0) {\n        matchR[v] = u;\n        matchL[u] = v;\n\
    \        return true;\n      }\n    }\n    for (int v : ke[u]) {\n      if (seen[matchR[v]]\
    \ != iteration && dfs(matchR[v])) {\n        matchR[v] = u;\n        matchL[u]\
    \ = v;\n        return true;\n      }\n    }\n    return false;\n  }\n\n  int\
    \ match() {\n    int res = 0;\n    int newMatches = 0;\n    do {\n      iteration++;\n\
    \      newMatches = 0;\n      for (int u = 0; u < n; u++) {\n        if (matchL[u]\
    \ < 0 && dfs(u)) ++newMatches;\n      }\n      res += newMatches;\n    } while\
    \ (newMatches > 0);\n    return res;\n  }\n};\n"
  code: "// Max Bipartite matching.\n// Index from 0\n// Assume 2 sides have same\
    \ number of vertices\n//\n// Notes:\n// - If TLE --> try shuffle edges\n//   REP(i,n)\
    \ shuffle(ke[i].begin(), ke[i].end(), rng)\n// - It should be quite fast, can\
    \ AC 10^5 vertices\n\nstruct bipartite_matching {\n  int n;\n  vector<vector<int>\
    \ > ke;\n  vector<int> seen;\n  vector<int> matchL, matchR;\n  int iteration;\n\
    \n  bipartite_matching(int _n)\n      : n(_n),\n        ke(_n),\n        seen(_n,\
    \ false),\n        matchL(_n, -1),\n        matchR(_n, -1),\n        iteration{0}\
    \ {}\n\n  void add_edge(int u, int v) { ke[u].push_back(v); }\n\n  bool dfs(int\
    \ u) {\n    seen[u] = iteration;\n    for (int v : ke[u]) {\n      if (matchR[v]\
    \ < 0) {\n        matchR[v] = u;\n        matchL[u] = v;\n        return true;\n\
    \      }\n    }\n    for (int v : ke[u]) {\n      if (seen[matchR[v]] != iteration\
    \ && dfs(matchR[v])) {\n        matchR[v] = u;\n        matchL[u] = v;\n     \
    \   return true;\n      }\n    }\n    return false;\n  }\n\n  int match() {\n\
    \    int res = 0;\n    int newMatches = 0;\n    do {\n      iteration++;\n   \
    \   newMatches = 0;\n      for (int u = 0; u < n; u++) {\n        if (matchL[u]\
    \ < 0 && dfs(u)) ++newMatches;\n      }\n      res += newMatches;\n    } while\
    \ (newMatches > 0);\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/bipartite_matching.hpp
  requiredBy: []
  timestamp: '2023-07-25 00:50:50+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bipartite_matching.hpp
layout: document
redirect_from:
- /library/graph/bipartite_matching.hpp
- /library/graph/bipartite_matching.hpp.html
title: graph/bipartite_matching.hpp
---
