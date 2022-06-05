---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/union_find.cpp\"\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nstruct uf {\n public:\n  uf() : _n(0) {}\n  explicit\
    \ uf(int n) : _n(n), p(n, -1) {}\n\n  int merge(int a, int b) {\n    int x = leader(a),\
    \ y = leader(b);\n    if (x == y) return x;\n    if (-p[x] < -p[y]) swap(x, y);\n\
    \    p[x] += p[y];\n    p[y] = x;\n    return x;\n  }\n\n  bool same(int a, int\
    \ b) { return leader(a) == leader(b); }\n\n  int leader(int a) {\n    if (p[a]\
    \ < 0) return a;\n    return p[a] = leader(p[a]);\n  }\n\n  int size(int a) {\n\
    \    assert(0 <= a && a < _n);\n    return -p[leader(a)];\n  }\n\n private:\n\
    \  int _n;\n  vector<int> p;\n};\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\nstruct uf {\n public:\n\
    \  uf() : _n(0) {}\n  explicit uf(int n) : _n(n), p(n, -1) {}\n\n  int merge(int\
    \ a, int b) {\n    int x = leader(a), y = leader(b);\n    if (x == y) return x;\n\
    \    if (-p[x] < -p[y]) swap(x, y);\n    p[x] += p[y];\n    p[y] = x;\n    return\
    \ x;\n  }\n\n  bool same(int a, int b) { return leader(a) == leader(b); }\n\n\
    \  int leader(int a) {\n    if (p[a] < 0) return a;\n    return p[a] = leader(p[a]);\n\
    \  }\n\n  int size(int a) {\n    assert(0 <= a && a < _n);\n    return -p[leader(a)];\n\
    \  }\n\n private:\n  int _n;\n  vector<int> p;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union_find.cpp
  requiredBy: []
  timestamp: '2022-06-05 19:58:30+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/union_find.cpp
layout: document
redirect_from:
- /library/data-structure/union_find.cpp
- /library/data-structure/union_find.cpp.html
title: data-structure/union_find.cpp
---
