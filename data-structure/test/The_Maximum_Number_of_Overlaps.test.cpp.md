---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick2d.hpp
    title: Fenwick Tree 2D
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
  bundledCode: "#line 1 \"data-structure/test/The_Maximum_Number_of_Overlaps.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using ull = unsigned long long;\n\n#line 1 \"data-structure/fenwick.hpp\"\ntemplate\
    \ <typename T>\nstruct fenwick {\n  fenwick(int n) : n(n), f(n + 1) {}\n\n  //\
    \ a[u] += val\n  void add(int u, T val) {\n    assert(0 <= u && u < n);\n    ++u;\n\
    \    while (u <= n) f[u] += val, u += u & -u;\n  }\n\n  // return the sum of [0,\
    \ u)\n  T sum(int u) const {\n    assert(0 <= u && u <= n);\n    T res = 0;\n\
    \    while (u) res += f[u], u -= u & -u;\n    return res;\n  }\n\n  // return\
    \ the sum of [l, r)\n  T sum(int l, int r) const {\n    assert(0 <= l && l <=\
    \ r && r <= n);\n    if (l == r) return 0;\n    return sum(r) - sum(l);\n  }\n\
    \n  void reset() { fill(f.begin(), f.end(), T(0)); }\n\n  int n;\n  vector<T>\
    \ f;\n};\n#line 2 \"data-structure/fenwick2d.hpp\"\n\ntemplate <class T>\nstruct\
    \ fenwick2d {\n  int n, m;\n  vector<fenwick<T>> f;\n  fenwick2d(int n, int m)\
    \ : n(n), m(m), f(n + 1, fenwick<T>(m)) {}\n  void add(int x, int y, T v) {\n\
    \    assert(0 <= x && x < n && 0 <= y && y < m);\n    ++x;\n    while (x <= n)\
    \ f[x].add(y, v), x += x & -x;\n  }\n  // add v to [x1, x2) x [y1, y2)\n  void\
    \ add(int x1, int y1, int x2, int y2, T v) {\n    add(x1, y1, v);\n    add(x1,\
    \ y2, -v);\n    add(x2, y1, -v);\n    add(x2, y2, v);\n  }\n  // sum of [0, x)\
    \ * [0, y)\n  T sum(int x, int y) {\n    T res = 0;\n    while(x) res += f[x].sum(y),\
    \ x -= x & -x;\n    return res;\n  }\n  // sum of [x1, x2) * [y1, y2)\n  T sum(int\
    \ x1, int y1, int x2, int y2) {\n    return sum(x2, y2) - sum(x1, y2) - sum(x2,\
    \ y1) + sum(x1, y1);\n  }\n};\n#line 12 \"data-structure/test/The_Maximum_Number_of_Overlaps.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  const int N = 1001;\n  int n;\n  cin >> n;\n  fenwick2d<int> f(N, N);\n  for\
    \ (int i = 0; i < n; ++i) {\n    int x1, y1, x2, y2;\n    cin >> x1 >> y1 >> x2\
    \ >> y2;\n    f.add(x1, y1, x2, y2, 1);\n  }\n  int ans = 0;\n  for (int i = 0;\
    \ i < N; ++i) {\n    for (int j = 0; j < N; ++j) {\n      ans = max(ans, f.sum(i\
    \ + 1, j + 1));\n    }\n  }\n  cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using ull = unsigned long long;\n\n#include \"data-structure/fenwick2d.hpp\"\n\
    \nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  const int N = 1001;\n  int n;\n  cin >> n;\n  fenwick2d<int> f(N, N);\n  for\
    \ (int i = 0; i < n; ++i) {\n    int x1, y1, x2, y2;\n    cin >> x1 >> y1 >> x2\
    \ >> y2;\n    f.add(x1, y1, x2, y2, 1);\n  }\n  int ans = 0;\n  for (int i = 0;\
    \ i < N; ++i) {\n    for (int j = 0; j < N; ++j) {\n      ans = max(ans, f.sum(i\
    \ + 1, j + 1));\n    }\n  }\n  cout << ans << '\\n';\n}"
  dependsOn:
  - data-structure/fenwick2d.hpp
  - data-structure/fenwick.hpp
  isVerificationFile: true
  path: data-structure/test/The_Maximum_Number_of_Overlaps.test.cpp
  requiredBy: []
  timestamp: '2022-09-30 00:44:43+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data-structure/test/The_Maximum_Number_of_Overlaps.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/The_Maximum_Number_of_Overlaps.test.cpp
- /verify/data-structure/test/The_Maximum_Number_of_Overlaps.test.cpp.html
title: data-structure/test/The_Maximum_Number_of_Overlaps.test.cpp
---
