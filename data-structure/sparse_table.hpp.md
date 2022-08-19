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
  bundledCode: "#line 1 \"data-structure/sparse_table.hpp\"\n// Static sequence sparse\
    \ table\n// Complexity: O(NlogN) for precalculation, O(1) per query\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()>\nstruct sparse_table {\n  int N, lgN;\n \
    \ vector<vector<S>> d;\n  vector<int> lgx_table;\n  sparse_table() {}\n  sparse_table(const\
    \ vector<S> &sequence) : N(sequence.size()) {\n    lgx_table.resize(N + 1);\n\
    \    for (int i = 2; i < N + 1; ++i) lgx_table[i] = lgx_table[i >> 1] + 1;\n \
    \   lgN = lgx_table[N] + 1;\n    d.assign(lgN, vector<S>(N, e()));\n    d[0] =\
    \ sequence;\n    for (int h = 1; h < lgN; ++h) {\n      for (int i = 0; i + (1\
    \ << h) <= N; ++i) {\n        d[h][i] = op(d[h - 1][i], d[h - 1][i + (1 << (h\
    \ - 1))]);\n      }\n    }\n  }\n  S prod(int l, int r) const {  // [l, r), 0-indexed\n\
    \    assert(l >= 0 and r <= N);\n    if (l >= r) return e();\n    int h = lgx_table[r\
    \ - l];\n    return op(d[h][l], d[h][r - (1 << h)]);\n  }\n};\n"
  code: "// Static sequence sparse table\n// Complexity: O(NlogN) for precalculation,\
    \ O(1) per query\ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct sparse_table\
    \ {\n  int N, lgN;\n  vector<vector<S>> d;\n  vector<int> lgx_table;\n  sparse_table()\
    \ {}\n  sparse_table(const vector<S> &sequence) : N(sequence.size()) {\n    lgx_table.resize(N\
    \ + 1);\n    for (int i = 2; i < N + 1; ++i) lgx_table[i] = lgx_table[i >> 1]\
    \ + 1;\n    lgN = lgx_table[N] + 1;\n    d.assign(lgN, vector<S>(N, e()));\n \
    \   d[0] = sequence;\n    for (int h = 1; h < lgN; ++h) {\n      for (int i =\
    \ 0; i + (1 << h) <= N; ++i) {\n        d[h][i] = op(d[h - 1][i], d[h - 1][i +\
    \ (1 << (h - 1))]);\n      }\n    }\n  }\n  S prod(int l, int r) const {  // [l,\
    \ r), 0-indexed\n    assert(l >= 0 and r <= N);\n    if (l >= r) return e();\n\
    \    int h = lgx_table[r - l];\n    return op(d[h][l], d[h][r - (1 << h)]);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2022-08-19 21:06:49+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/sparse_table.hpp
layout: document
redirect_from:
- /library/data-structure/sparse_table.hpp
- /library/data-structure/sparse_table.hpp.html
title: data-structure/sparse_table.hpp
---
