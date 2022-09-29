---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick.hpp
    title: Fenwick Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"data-structure/test/Point_Add_Range_Sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#include\
    \ <bits/extc++.h>\n\nusing namespace std;\n\n#line 1 \"data-structure/fenwick.hpp\"\
    \ntemplate <typename T>\nstruct fenwick {\n  fenwick(int n) : n(n), f(n + 1) {}\n\
    \n  // a[u] += val\n  void add(int u, T val) {\n    assert(0 <= u && u < n);\n\
    \    ++u;\n    while (u <= n) f[u] += val, u += u & -u;\n  }\n\n  // return the\
    \ sum of [0, u)\n  T sum(int u) const {\n    assert(0 <= u && u <= n);\n    T\
    \ res = 0;\n    while (u) res += f[u], u -= u & -u;\n    return res;\n  }\n\n\
    \  // return the sum of [l, r)\n  T sum(int l, int r) const {\n    assert(0 <=\
    \ l && l <= r && r <= n);\n    if (l == r) return 0;\n    return sum(r) - sum(l);\n\
    \  }\n\n  void reset() { fill(f.begin(), f.end(), T(0)); }\n\n  int n;\n  vector<T>\
    \ f;\n};\n#line 8 \"data-structure/test/Point_Add_Range_Sum.test.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(0);\n  int n, q;\n  cin >>\
    \ n >> q;\n  fenwick<int64_t> fw(n);\n  for (int i = 0; i < n; ++i) {\n    int\
    \ x;\n    cin >> x;\n    fw.add(i, x);\n  }\n  while (q--) {\n    int t, l, r;\n\
    \    cin >> t >> l >> r;\n    if (t)\n      cout << fw.sum(l, r) << '\\n';\n \
    \   else\n      fw.add(l, r);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/extc++.h>\n\nusing namespace std;\n\n#include \"data-structure/fenwick.hpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(0);\n  int n, q;\n\
    \  cin >> n >> q;\n  fenwick<int64_t> fw(n);\n  for (int i = 0; i < n; ++i) {\n\
    \    int x;\n    cin >> x;\n    fw.add(i, x);\n  }\n  while (q--) {\n    int t,\
    \ l, r;\n    cin >> t >> l >> r;\n    if (t)\n      cout << fw.sum(l, r) << '\\\
    n';\n    else\n      fw.add(l, r);\n  }\n}"
  dependsOn:
  - data-structure/fenwick.hpp
  isVerificationFile: true
  path: data-structure/test/Point_Add_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2022-09-30 00:07:15+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data-structure/test/Point_Add_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/Point_Add_Range_Sum.test.cpp
- /verify/data-structure/test/Point_Add_Range_Sum.test.cpp.html
title: data-structure/test/Point_Add_Range_Sum.test.cpp
---
