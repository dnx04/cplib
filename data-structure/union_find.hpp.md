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
  bundledCode: "#line 1 \"data-structure/union_find.hpp\"\nstruct uf {\n public:\n\
    \  uf(int _n) : n(_n), p(_n, -1) {}\n\n  int merge(int a, int b) {\n    int x\
    \ = head(a), y = head(b);\n    if (x == y) return x;\n    if (-p[x] < -p[y]) swap(x,\
    \ y);\n    p[x] += p[y];\n    p[y] = x;\n    return x;\n  }\n\n  bool same(int\
    \ a, int b) { return head(a) == head(b); }\n\n  int head(int a) {\n    if (p[a]\
    \ < 0) return a;\n    return p[a] = head(p[a]);\n  }\n\n  int size(int a) {\n\
    \    assert(0 <= a && a < n);\n    return -p[head(a)];\n  }\n\n private:\n  int\
    \ n;\n  vector<int> p;\n};\n"
  code: "struct uf {\n public:\n  uf(int _n) : n(_n), p(_n, -1) {}\n\n  int merge(int\
    \ a, int b) {\n    int x = head(a), y = head(b);\n    if (x == y) return x;\n\
    \    if (-p[x] < -p[y]) swap(x, y);\n    p[x] += p[y];\n    p[y] = x;\n    return\
    \ x;\n  }\n\n  bool same(int a, int b) { return head(a) == head(b); }\n\n  int\
    \ head(int a) {\n    if (p[a] < 0) return a;\n    return p[a] = head(p[a]);\n\
    \  }\n\n  int size(int a) {\n    assert(0 <= a && a < n);\n    return -p[head(a)];\n\
    \  }\n\n private:\n  int n;\n  vector<int> p;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union_find.hpp
  requiredBy: []
  timestamp: '2022-06-05 21:27:54+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/union_find.hpp
layout: document
redirect_from:
- /library/data-structure/union_find.hpp
- /library/data-structure/union_find.hpp.html
title: data-structure/union_find.hpp
---
