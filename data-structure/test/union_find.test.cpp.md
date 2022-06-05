---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"data-structure/test/union_find.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include <bits/stdc++.h>\n\n\
    using namespace std;\n\nstruct uf {\n public:\n  uf(int _n) : n(_n), p(_n, -1)\
    \ {}\n\n  int merge(int a, int b) {\n    int x = head(a), y = head(b);\n    if\
    \ (x == y) return x;\n    if (-p[x] < -p[y]) swap(x, y);\n    p[x] += p[y];\n\
    \    p[y] = x;\n    return x;\n  }\n\n  bool same(int a, int b) { return head(a)\
    \ == head(b); }\n\n  int head(int a) {\n    if (p[a] < 0) return a;\n    return\
    \ p[a] = head(p[a]);\n  }\n\n  int size(int a) {\n    assert(0 <= a && a < n);\n\
    \    return -p[head(a)];\n  }\n\n private:\n  int n;\n  vector<int> p;\n};\n\n\
    signed main() {\n  int n, q;\n  cin >> n >> q;\n  uf dsu(n);\n  while (q--) {\n\
    \    int t, x, y;\n    cin >> t >> x >> y;\n    if (t)\n      cout << dsu.same(x,\
    \ y) << '\\n';\n    else\n      dsu.merge(x, y);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\nstruct uf {\n public:\n  uf(int _n)\
    \ : n(_n), p(_n, -1) {}\n\n  int merge(int a, int b) {\n    int x = head(a), y\
    \ = head(b);\n    if (x == y) return x;\n    if (-p[x] < -p[y]) swap(x, y);\n\
    \    p[x] += p[y];\n    p[y] = x;\n    return x;\n  }\n\n  bool same(int a, int\
    \ b) { return head(a) == head(b); }\n\n  int head(int a) {\n    if (p[a] < 0)\
    \ return a;\n    return p[a] = head(p[a]);\n  }\n\n  int size(int a) {\n    assert(0\
    \ <= a && a < n);\n    return -p[head(a)];\n  }\n\n private:\n  int n;\n  vector<int>\
    \ p;\n};\n\nsigned main() {\n  int n, q;\n  cin >> n >> q;\n  uf dsu(n);\n  while\
    \ (q--) {\n    int t, x, y;\n    cin >> t >> x >> y;\n    if (t)\n      cout <<\
    \ dsu.same(x, y) << '\\n';\n    else\n      dsu.merge(x, y);\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: data-structure/test/union_find.test.cpp
  requiredBy: []
  timestamp: '2022-06-05 21:30:41+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data-structure/test/union_find.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/union_find.test.cpp
- /verify/data-structure/test/union_find.test.cpp.html
title: data-structure/test/union_find.test.cpp
---
