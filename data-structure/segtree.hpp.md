---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data-structure/test/Point_Set_Range_Composite.test.cpp
    title: data-structure/test/Point_Set_Range_Composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/segtree.hpp\"\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()>\nstruct segtree {\n public:\n  segtree() : segtree(0) {}\n  explicit\
    \ segtree(int n) : segtree(vector<S>(n, e())) {}\n  explicit segtree(const vector<S>&\
    \ v) : n(int(v.size())) {\n    log = ceil(log2(double(n)));\n    size = 1 << log;\n\
    \    d = vector<S>(2 * size, e());\n    for (int i = 0; i < n; i++) d[size + i]\
    \ = v[i];\n    for (int i = size - 1; i >= 1; i--) {\n      update(i);\n    }\n\
    \  }\n\n  void set(int p, S x) {\n    assert(0 <= p && p < n);\n    p += size;\n\
    \    d[p] = x;\n    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n\n  S\
    \ get(int p) const {\n    assert(0 <= p && p < n);\n    return d[p + size];\n\
    \  }\n\n  S prod(int l, int r) const {\n    assert(0 <= l && l <= r && r <= n);\n\
    \    S sml = e(), smr = e();\n    l += size;\n    r += size;\n\n    while (l <\
    \ r) {\n      if (l & 1) sml = op(sml, d[l++]);\n      if (r & 1) smr = op(d[--r],\
    \ smr);\n      l >>= 1;\n      r >>= 1;\n    }\n    return op(sml, smr);\n  }\n\
    \n  S all_prod() const { return d[1]; }\n\n  template <bool (*f)(S)>\n  int max_right(int\
    \ l) const {\n    return max_right(l, [](S x) { return f(x); });\n  }\n  template\
    \ <class F>\n  int max_right(int l, F f) const {\n    assert(0 <= l && l <= n);\n\
    \    assert(f(e()));\n    if (l == n) return n;\n    l += size;\n    S sm = e();\n\
    \    do {\n      while (l % 2 == 0) l >>= 1;\n      if (!f(op(sm, d[l]))) {\n\
    \        while (l < size) {\n          l = (2 * l);\n          if (f(op(sm, d[l])))\
    \ {\n            sm = op(sm, d[l]);\n            l++;\n          }\n        }\n\
    \        return l - size;\n      }\n      sm = op(sm, d[l]);\n      l++;\n   \
    \ } while ((l & -l) != l);\n    return n;\n  }\n\n  template <bool (*f)(S)>\n\
    \  int min_left(int r) const {\n    return min_left(r, [](S x) { return f(x);\
    \ });\n  }\n  template <class F>\n  int min_left(int r, F f) const {\n    assert(0\
    \ <= r && r <= n);\n    assert(f(e()));\n    if (r == 0) return 0;\n    r += size;\n\
    \    S sm = e();\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n\
    \      if (!f(op(d[r], sm))) {\n        while (r < size) {\n          r = (2 *\
    \ r + 1);\n          if (f(op(d[r], sm))) {\n            sm = op(d[r], sm);\n\
    \            r--;\n          }\n        }\n        return r + 1 - size;\n    \
    \  }\n      sm = op(d[r], sm);\n    } while ((r & -r) != r);\n    return 0;\n\
    \  }\n\n private:\n  int n, size, log;\n  vector<S> d;\n\n  void update(int k)\
    \ { d[k] = op(d[2 * k], d[2 * k + 1]); }\n};\n"
  code: "template <class S, S (*op)(S, S), S (*e)()>\nstruct segtree {\n public:\n\
    \  segtree() : segtree(0) {}\n  explicit segtree(int n) : segtree(vector<S>(n,\
    \ e())) {}\n  explicit segtree(const vector<S>& v) : n(int(v.size())) {\n    log\
    \ = ceil(log2(double(n)));\n    size = 1 << log;\n    d = vector<S>(2 * size,\
    \ e());\n    for (int i = 0; i < n; i++) d[size + i] = v[i];\n    for (int i =\
    \ size - 1; i >= 1; i--) {\n      update(i);\n    }\n  }\n\n  void set(int p,\
    \ S x) {\n    assert(0 <= p && p < n);\n    p += size;\n    d[p] = x;\n    for\
    \ (int i = 1; i <= log; i++) update(p >> i);\n  }\n\n  S get(int p) const {\n\
    \    assert(0 <= p && p < n);\n    return d[p + size];\n  }\n\n  S prod(int l,\
    \ int r) const {\n    assert(0 <= l && l <= r && r <= n);\n    S sml = e(), smr\
    \ = e();\n    l += size;\n    r += size;\n\n    while (l < r) {\n      if (l &\
    \ 1) sml = op(sml, d[l++]);\n      if (r & 1) smr = op(d[--r], smr);\n      l\
    \ >>= 1;\n      r >>= 1;\n    }\n    return op(sml, smr);\n  }\n\n  S all_prod()\
    \ const { return d[1]; }\n\n  template <bool (*f)(S)>\n  int max_right(int l)\
    \ const {\n    return max_right(l, [](S x) { return f(x); });\n  }\n  template\
    \ <class F>\n  int max_right(int l, F f) const {\n    assert(0 <= l && l <= n);\n\
    \    assert(f(e()));\n    if (l == n) return n;\n    l += size;\n    S sm = e();\n\
    \    do {\n      while (l % 2 == 0) l >>= 1;\n      if (!f(op(sm, d[l]))) {\n\
    \        while (l < size) {\n          l = (2 * l);\n          if (f(op(sm, d[l])))\
    \ {\n            sm = op(sm, d[l]);\n            l++;\n          }\n        }\n\
    \        return l - size;\n      }\n      sm = op(sm, d[l]);\n      l++;\n   \
    \ } while ((l & -l) != l);\n    return n;\n  }\n\n  template <bool (*f)(S)>\n\
    \  int min_left(int r) const {\n    return min_left(r, [](S x) { return f(x);\
    \ });\n  }\n  template <class F>\n  int min_left(int r, F f) const {\n    assert(0\
    \ <= r && r <= n);\n    assert(f(e()));\n    if (r == 0) return 0;\n    r += size;\n\
    \    S sm = e();\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n\
    \      if (!f(op(d[r], sm))) {\n        while (r < size) {\n          r = (2 *\
    \ r + 1);\n          if (f(op(d[r], sm))) {\n            sm = op(d[r], sm);\n\
    \            r--;\n          }\n        }\n        return r + 1 - size;\n    \
    \  }\n      sm = op(d[r], sm);\n    } while ((r & -r) != r);\n    return 0;\n\
    \  }\n\n private:\n  int n, size, log;\n  vector<S> d;\n\n  void update(int k)\
    \ { d[k] = op(d[2 * k], d[2 * k + 1]); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree.hpp
  requiredBy: []
  timestamp: '2022-08-12 11:03:46+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data-structure/test/Point_Set_Range_Composite.test.cpp
documentation_of: data-structure/segtree.hpp
layout: document
title: Segment Tree
---
