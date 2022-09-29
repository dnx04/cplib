---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/rmq.hpp
    title: Range Minimum/Maximum Query (Sparse Table)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"data-structure/test/Static_RMQ.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <bits/stdc++.h>\n\n\
    using namespace std;\n\n#line 1 \"data-structure/rmq.hpp\"\n// RMQ using Sparse\
    \ Table\n// range_min for min, range_max for max\n\ntemplate <class T, T (*op)(T,\
    \ T)>\nstruct rmq {\n  rmq() = default;\n  rmq(const vector<T>& v) : t{v}, n{(int)v.size()}\
    \ {\n    for (int k = 1; (1 << k) <= n; ++k) {\n      t.emplace_back(n - (1 <<\
    \ k) + 1);\n      for (int i = 0; i + (1 << k) <= n; ++i) {\n        t[k][i] =\
    \ op(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);\n      }\n    }\n  }\n\n  //\
    \ get range [l, r-1]\n  // doesn't work for empty range\n  T get(int l, int r)\
    \ const {\n    assert(0 <= l && l < r && r <= n);\n    int k = __lg(r - l);\n\
    \    return op(t[k][l], t[k][r - (1 << k)]);\n  }\n\n private:\n  vector<vector<T>>\
    \ t;\n  int n;\n};\n\ntemplate <class T>\nT range_min(T a, T b) {\n  return b\
    \ < a ? b : a;\n}\ntemplate <class T>\nT range_max(T a, T b) {\n  return a < b\
    \ ? b : a;\n}\n#line 8 \"data-structure/test/Static_RMQ.test.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(0);\n  int n, q;\n  cin >> n >> q;\n\
    \  vector<int> a(n);\n  for (auto &x : a) cin >> x;\n  rmq<int, range_min> st(a);\n\
    \  while (q--) {\n    int l, r;\n    cin >> l >> r;\n    cout << st.get(l, r)\
    \ << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\n#include \"../rmq.hpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(0);\n  int n, q;\n  cin >>\
    \ n >> q;\n  vector<int> a(n);\n  for (auto &x : a) cin >> x;\n  rmq<int, range_min>\
    \ st(a);\n  while (q--) {\n    int l, r;\n    cin >> l >> r;\n    cout << st.get(l,\
    \ r) << '\\n';\n  }\n}"
  dependsOn:
  - data-structure/rmq.hpp
  isVerificationFile: true
  path: data-structure/test/Static_RMQ.test.cpp
  requiredBy: []
  timestamp: '2022-09-03 22:10:58+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data-structure/test/Static_RMQ.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/Static_RMQ.test.cpp
- /verify/data-structure/test/Static_RMQ.test.cpp.html
title: data-structure/test/Static_RMQ.test.cpp
---
