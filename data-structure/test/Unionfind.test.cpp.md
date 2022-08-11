---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union_find.hpp
    title: data-structure/union_find.hpp
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
  bundledCode: "#line 1 \"data-structure/test/Unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include <bits/extc++.h>\n\n\
    using namespace std;\n\n#line 1 \"data-structure/union_find.hpp\"\nstruct uf {\n\
    \ public:\n  uf(int _n) : n(_n), p(_n, -1) {}\n\n  int merge(int a, int b) {\n\
    \    assert(0 <= a && a < n);\n    assert(0 <= b && b < n);\n    int x = head(a),\
    \ y = head(b);\n    if (x == y) return x;\n    if (-p[x] < -p[y]) swap(x, y);\n\
    \    p[x] += p[y];\n    p[y] = x;\n    return x;\n  }\n\n  bool same(int a, int\
    \ b) {\n    assert(0 <= a && a < n);\n    assert(0 <= b && b < n);\n    return\
    \ head(a) == head(b);\n  }\n\n  int head(int a) {\n    assert(0 <= a && a < n);\n\
    \    if (p[a] < 0) return a;\n    return p[a] = head(p[a]);\n  }\n\n  int size(int\
    \ a) {\n    assert(0 <= a && a < n);\n    return -p[head(a)];\n  }\n\n  vector<vector<int>>\
    \ groups() {\n    vector<int> tmp(n), sz(n);\n    for (int i = 0; i < n; ++i)\
    \ tmp[i] = head(i), ++sz[tmp[i]];\n    vector<vector<int>> gr(n);\n    for (int\
    \ i = 0; i < n; ++i) gr[i].reserve(sz[i]);\n    for (int i = 0; i < n; ++i) gr[tmp[i]].push_back(i);\n\
    \    gr.erase(remove_if(begin(gr), end(gr),\n                       [&](const\
    \ vector<int>& v) { return v.empty(); }),\n             end(gr));\n    return\
    \ gr;\n  }\n\n private:\n  int n;\n  vector<int> p;\n};\n#line 8 \"data-structure/test/Unionfind.test.cpp\"\
    \n\nsigned main() {\n  int n, q;\n  cin >> n >> q;\n  uf dsu(n);\n  while (q--)\
    \ {\n    int t, x, y;\n    cin >> t >> x >> y;\n    if (t)\n      cout << dsu.same(x,\
    \ y) << '\\n';\n    else\n      dsu.merge(x, y);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/extc++.h>\n\nusing namespace std;\n\n#include \"../union_find.hpp\"\n\n\
    signed main() {\n  int n, q;\n  cin >> n >> q;\n  uf dsu(n);\n  while (q--) {\n\
    \    int t, x, y;\n    cin >> t >> x >> y;\n    if (t)\n      cout << dsu.same(x,\
    \ y) << '\\n';\n    else\n      dsu.merge(x, y);\n  }\n}"
  dependsOn:
  - data-structure/union_find.hpp
  isVerificationFile: true
  path: data-structure/test/Unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-08-11 20:11:38+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data-structure/test/Unionfind.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/Unionfind.test.cpp
- /verify/data-structure/test/Unionfind.test.cpp.html
title: data-structure/test/Unionfind.test.cpp
---
