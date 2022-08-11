---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse_table.hpp
    title: data-structure/sparse_table.hpp
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
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <bits/extc++.h>\n\n\
    using namespace std;\n\n#line 1 \"data-structure/sparse_table.hpp\"\ntemplate\
    \ <typename T>\nstruct sparse_table {\n  int n, k;\n  vector<vector<T>> st;\n\
    \  T f(T x = 1e9, T y = 1e9) { return min(x, y); }\n  sparse_table(const vector<T>\
    \ &v)\n      : n(v.size()), k(__lg(n) + 1), st(n, vector<T>(k)) {\n    for (int\
    \ i = 0; i < n; ++i) st[i][0] = f(v[i]);\n    for (int j = 1; j < k; j++)\n  \
    \    for (int i = 0; i + (1 << j) <= n; ++i)\n        st[i][j] = f(st[i][j - 1],\
    \ st[i + (1 << (j - 1))][j - 1]);\n  };\n  T query(int l, int r) {\n    T sum\
    \ = 1e9;\n    for (int j = k - 1; j >= 0; --j) {\n      if ((1 << j) <= r - l\
    \ + 1) {\n        sum = f(sum, st[l][j]);\n        l += 1 << j;\n      }\n   \
    \ }\n    return sum;\n  }\n};\n#line 8 \"data-structure/test/Static_RMQ.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(0);\n  int n, q;\n\
    \  cin >> n >> q;\n  vector<int> a(n);\n  for (auto &x : a) cin >> x;\n  sparse_table<int>\
    \ st(a);\n  while (q--) {\n    int l, r;\n    cin >> l >> r;\n    cout << st.query(l,\
    \ r - 1) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <bits/extc++.h>\n\nusing namespace std;\n\n#include \"../sparse_table.hpp\"\n\
    \nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(0);\n  int n, q;\n \
    \ cin >> n >> q;\n  vector<int> a(n);\n  for (auto &x : a) cin >> x;\n  sparse_table<int>\
    \ st(a);\n  while (q--) {\n    int l, r;\n    cin >> l >> r;\n    cout << st.query(l,\
    \ r - 1) << '\\n';\n  }\n}"
  dependsOn:
  - data-structure/sparse_table.hpp
  isVerificationFile: true
  path: data-structure/test/Static_RMQ.test.cpp
  requiredBy: []
  timestamp: '2022-08-11 20:11:38+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data-structure/test/Static_RMQ.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/Static_RMQ.test.cpp
- /verify/data-structure/test/Static_RMQ.test.cpp.html
title: data-structure/test/Static_RMQ.test.cpp
---
