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
  bundledCode: "#line 1 \"data-structure/fenwick.hpp\"\ntemplate <typename T>\nstruct\
    \ fenwick_tree {\n public:\n  fenwick_tree(int _n) : n(_n), fw(_n + 1) {}\n\n\
    \  void add(int p, T x) {\n    assert(0 <= p && p < n);\n    ++p;\n    while (p\
    \ <= n) {\n      fw[p - 1] += x;\n      p += p & -p;\n    }\n  }\n\n  // return\
    \ sum of [l, r)\n  T sum(int l, int r) {\n    assert(0 <= l && l <= r && r <=\
    \ n);\n    if (l == r) return 0;\n    return sum(r) - sum(l);\n  }\n\n  void reset()\
    \ { fill(begin(fw), end(fw), 0); }\n\n private:\n  int n;\n  vector<T> fw;\n\n\
    \  T sum(int r) {\n    T s = 0;\n    while (r > 0) {\n      s += fw[r - 1];\n\
    \      r -= r & -r;\n    }\n    return s;\n  }\n};\n"
  code: "template <typename T>\nstruct fenwick_tree {\n public:\n  fenwick_tree(int\
    \ _n) : n(_n), fw(_n + 1) {}\n\n  void add(int p, T x) {\n    assert(0 <= p &&\
    \ p < n);\n    ++p;\n    while (p <= n) {\n      fw[p - 1] += x;\n      p += p\
    \ & -p;\n    }\n  }\n\n  // return sum of [l, r)\n  T sum(int l, int r) {\n  \
    \  assert(0 <= l && l <= r && r <= n);\n    if (l == r) return 0;\n    return\
    \ sum(r) - sum(l);\n  }\n\n  void reset() { fill(begin(fw), end(fw), 0); }\n\n\
    \ private:\n  int n;\n  vector<T> fw;\n\n  T sum(int r) {\n    T s = 0;\n    while\
    \ (r > 0) {\n      s += fw[r - 1];\n      r -= r & -r;\n    }\n    return s;\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/fenwick.hpp
  requiredBy: []
  timestamp: '2022-06-05 21:27:54+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/fenwick.hpp
layout: document
redirect_from:
- /library/data-structure/fenwick.hpp
- /library/data-structure/fenwick.hpp.html
title: data-structure/fenwick.hpp
---
