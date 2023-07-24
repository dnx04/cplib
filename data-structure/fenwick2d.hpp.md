---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick.hpp
    title: Fenwick Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data-structure/test/The_Maximum_Number_of_Overlaps.test.cpp
    title: data-structure/test/The_Maximum_Number_of_Overlaps.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/fenwick.hpp\"\ntemplate <typename T>\nstruct\
    \ fenwick {\n  fenwick(int n) : n(n), f(n + 1) {}\n\n  // a[u] += val\n  void\
    \ add(int u, T val) {\n    assert(0 <= u && u < n);\n    ++u;\n    while (u <=\
    \ n) f[u] += val, u += u & -u;\n  }\n\n  // return the sum of [0, u)\n  T sum(int\
    \ u) const {\n    assert(0 <= u && u <= n);\n    T res = 0;\n    while (u) res\
    \ += f[u], u -= u & -u;\n    return res;\n  }\n\n  // return the sum of [l, r)\n\
    \  T sum(int l, int r) const {\n    assert(0 <= l && l <= r && r <= n);\n    if\
    \ (l == r) return 0;\n    return sum(r) - sum(l);\n  }\n\n  void reset() { fill(f.begin(),\
    \ f.end(), T(0)); }\n\n  int n;\n  vector<T> f;\n};\n#line 2 \"data-structure/fenwick2d.hpp\"\
    \n\ntemplate <class T>\nstruct fenwick2d {\n  int n, m;\n  vector<fenwick<T>>\
    \ f;\n  fenwick2d(int n, int m) : n(n), m(m), f(n + 1, fenwick<T>(m)) {}\n  void\
    \ add(int x, int y, T v) {\n    assert(0 <= x && x < n && 0 <= y && y < m);\n\
    \    ++x;\n    while (x <= n) f[x].add(y, v), x += x & -x;\n  }\n  // add v to\
    \ [x1, x2) x [y1, y2)\n  void add(int x1, int y1, int x2, int y2, T v) {\n   \
    \ add(x1, y1, v);\n    add(x1, y2, -v);\n    add(x2, y1, -v);\n    add(x2, y2,\
    \ v);\n  }\n  // sum of [0, x) * [0, y)\n  T sum(int x, int y) {\n    T res =\
    \ 0;\n    while(x) res += f[x].sum(y), x -= x & -x;\n    return res;\n  }\n  //\
    \ sum of [x1, x2) * [y1, y2)\n  T sum(int x1, int y1, int x2, int y2) {\n    return\
    \ sum(x2, y2) - sum(x1, y2) - sum(x2, y1) + sum(x1, y1);\n  }\n};\n"
  code: "#include \"data-structure/fenwick.hpp\"\n\ntemplate <class T>\nstruct fenwick2d\
    \ {\n  int n, m;\n  vector<fenwick<T>> f;\n  fenwick2d(int n, int m) : n(n), m(m),\
    \ f(n + 1, fenwick<T>(m)) {}\n  void add(int x, int y, T v) {\n    assert(0 <=\
    \ x && x < n && 0 <= y && y < m);\n    ++x;\n    while (x <= n) f[x].add(y, v),\
    \ x += x & -x;\n  }\n  // add v to [x1, x2) x [y1, y2)\n  void add(int x1, int\
    \ y1, int x2, int y2, T v) {\n    add(x1, y1, v);\n    add(x1, y2, -v);\n    add(x2,\
    \ y1, -v);\n    add(x2, y2, v);\n  }\n  // sum of [0, x) * [0, y)\n  T sum(int\
    \ x, int y) {\n    T res = 0;\n    while(x) res += f[x].sum(y), x -= x & -x;\n\
    \    return res;\n  }\n  // sum of [x1, x2) * [y1, y2)\n  T sum(int x1, int y1,\
    \ int x2, int y2) {\n    return sum(x2, y2) - sum(x1, y2) - sum(x2, y1) + sum(x1,\
    \ y1);\n  }\n};"
  dependsOn:
  - data-structure/fenwick.hpp
  isVerificationFile: false
  path: data-structure/fenwick2d.hpp
  requiredBy: []
  timestamp: '2023-07-25 00:50:50+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data-structure/test/The_Maximum_Number_of_Overlaps.test.cpp
documentation_of: data-structure/fenwick2d.hpp
layout: document
title: Fenwick Tree 2D
---
