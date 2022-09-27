---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree.hpp
    title: data-structure/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: utility/static_modulo.hpp
    title: utility/static_modulo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"data-structure/test/Point_Set_Range_Composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using ull = unsigned long long;\n\n#line 1 \"data-structure/segtree.hpp\"\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()>\nstruct segtree {\n public:\n  segtree()\
    \ : segtree(0) {}\n  explicit segtree(int n) : segtree(vector<S>(n, e())) {}\n\
    \  explicit segtree(const vector<S>& v) : n(int(v.size())) {\n    log = ceil(log2(double(n)));\n\
    \    size = 1 << log;\n    d = vector<S>(2 * size, e());\n    for (int i = 0;\
    \ i < n; i++) d[size + i] = v[i];\n    for (int i = size - 1; i >= 1; i--) {\n\
    \      update(i);\n    }\n  }\n\n  void set(int p, S x) {\n    assert(0 <= p &&\
    \ p < n);\n    p += size;\n    d[p] = x;\n    for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n  }\n\n  S get(int p) const {\n    assert(0 <= p && p < n);\n    return\
    \ d[p + size];\n  }\n\n  S prod(int l, int r) const {\n    assert(0 <= l && l\
    \ <= r && r <= n);\n    S sml = e(), smr = e();\n    l += size;\n    r += size;\n\
    \n    while (l < r) {\n      if (l & 1) sml = op(sml, d[l++]);\n      if (r &\
    \ 1) smr = op(d[--r], smr);\n      l >>= 1;\n      r >>= 1;\n    }\n    return\
    \ op(sml, smr);\n  }\n\n  S all_prod() const { return d[1]; }\n\n  template <bool\
    \ (*f)(S)>\n  int max_right(int l) const {\n    return max_right(l, [](S x) {\
    \ return f(x); });\n  }\n  template <class F>\n  int max_right(int l, F f) const\
    \ {\n    assert(0 <= l && l <= n);\n    assert(f(e()));\n    if (l == n) return\
    \ n;\n    l += size;\n    S sm = e();\n    do {\n      while (l % 2 == 0) l >>=\
    \ 1;\n      if (!f(op(sm, d[l]))) {\n        while (l < size) {\n          l =\
    \ (2 * l);\n          if (f(op(sm, d[l]))) {\n            sm = op(sm, d[l]);\n\
    \            l++;\n          }\n        }\n        return l - size;\n      }\n\
    \      sm = op(sm, d[l]);\n      l++;\n    } while ((l & -l) != l);\n    return\
    \ n;\n  }\n\n  template <bool (*f)(S)>\n  int min_left(int r) const {\n    return\
    \ min_left(r, [](S x) { return f(x); });\n  }\n  template <class F>\n  int min_left(int\
    \ r, F f) const {\n    assert(0 <= r && r <= n);\n    assert(f(e()));\n    if\
    \ (r == 0) return 0;\n    r += size;\n    S sm = e();\n    do {\n      r--;\n\
    \      while (r > 1 && (r % 2)) r >>= 1;\n      if (!f(op(d[r], sm))) {\n    \
    \    while (r < size) {\n          r = (2 * r + 1);\n          if (f(op(d[r],\
    \ sm))) {\n            sm = op(d[r], sm);\n            r--;\n          }\n   \
    \     }\n        return r + 1 - size;\n      }\n      sm = op(d[r], sm);\n   \
    \ } while ((r & -r) != r);\n    return 0;\n  }\n\n private:\n  int n, size, log;\n\
    \  vector<S> d;\n\n  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n\
    };\n#line 2 \"utility/static_modulo.hpp\"\n\ntemplate <int mod>\nstruct static_modulo\
    \ {\n  using Fp = static_modulo;\n\n private:\n  int x;\n\n public:\n  static_modulo()\
    \ : x(0) {}\n  static_modulo(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod)\
    \ % mod) {}\n  Fp &operator+=(const Fp &p) {\n    if ((x += p.x) >= mod) x -=\
    \ mod;\n    return *this;\n  }\n  Fp &operator-=(const Fp &p) {\n    if ((x +=\
    \ mod - p.x) >= mod) x -= mod;\n    return *this;\n  }\n  Fp &operator*=(const\
    \ Fp &p) {\n    x = (int)(1ll * x * p.x % mod);\n    return *this;\n  }\n  Fp\
    \ &operator/=(const Fp &p) {\n    *this *= p.inv();\n    return *this;\n  }\n\
    \  Fp operator-() const { return Fp(-x); }\n  Fp operator+(const Fp &p) const\
    \ { return Fp(*this) += p; }\n  Fp operator-(const Fp &p) const { return Fp(*this)\
    \ -= p; }\n  Fp operator*(const Fp &p) const { return Fp(*this) *= p; }\n  Fp\
    \ operator/(const Fp &p) const { return Fp(*this) /= p; }\n  bool operator==(const\
    \ Fp &p) const { return x == p.x; }\n  bool operator!=(const Fp &p) const { return\
    \ x != p.x; }\n  Fp inv() const {\n    int a = x, b = mod, u = 1, v = 0, t;\n\
    \    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b);\n      swap(u\
    \ -= t * v, v);\n    }\n    return Fp(u);\n  }\n  Fp pow(int64_t n) const {\n\
    \    Fp ret(1), mul(x);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n \
    \     mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n  friend ostream\
    \ &operator<<(ostream &os, const Fp &p) { return os << p.x; }\n  friend istream\
    \ &operator>>(istream &is, Fp &a) {\n    int64_t t;\n    is >> t;\n    a = static_modulo<mod>(t);\n\
    \    return (is);\n  }\n  int get() const { return x; }\n  static constexpr int\
    \ get_mod() { return mod; }\n};\n#line 12 \"data-structure/test/Point_Set_Range_Composite.test.cpp\"\
    \n\nusing Fp = static_modulo<998244353>;\n\nstruct S {\n  Fp a, b;\n};\n\nS op(S\
    \ x, S y) { return {x.a * y.a, x.b * y.a + y.b}; }\n\nS e() { return {1, 0}; }\n\
    \nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  int n, q;\n  cin >> n >> q;\n  vector<S> a(n);\n  for (int i = 0; i < n; i++)\
    \ cin >> a[i].a >> a[i].b;\n  segtree<S, op, e> seg(a);\n  while (q--) {\n   \
    \ int t;\n    cin >> t;\n    if (t == 0) {\n      int pos;\n      Fp c, d;\n \
    \     cin >> pos >> c >> d;\n      seg.set(pos, S{c, d});\n    } else {\n    \
    \  int l, r, x;\n      cin >> l >> r >> x;\n      auto [c, d] = seg.prod(l, r);\n\
    \      cout << c * x + d << '\\n';\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using ull = unsigned long long;\n\n#include \"data-structure/segtree.hpp\"\n#include\
    \ \"utility/static_modulo.hpp\"\n\nusing Fp = static_modulo<998244353>;\n\nstruct\
    \ S {\n  Fp a, b;\n};\n\nS op(S x, S y) { return {x.a * y.a, x.b * y.a + y.b};\
    \ }\n\nS e() { return {1, 0}; }\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  int n, q;\n  cin >> n >>\
    \ q;\n  vector<S> a(n);\n  for (int i = 0; i < n; i++) cin >> a[i].a >> a[i].b;\n\
    \  segtree<S, op, e> seg(a);\n  while (q--) {\n    int t;\n    cin >> t;\n   \
    \ if (t == 0) {\n      int pos;\n      Fp c, d;\n      cin >> pos >> c >> d;\n\
    \      seg.set(pos, S{c, d});\n    } else {\n      int l, r, x;\n      cin >>\
    \ l >> r >> x;\n      auto [c, d] = seg.prod(l, r);\n      cout << c * x + d <<\
    \ '\\n';\n    }\n  }\n}"
  dependsOn:
  - data-structure/segtree.hpp
  - utility/static_modulo.hpp
  isVerificationFile: true
  path: data-structure/test/Point_Set_Range_Composite.test.cpp
  requiredBy: []
  timestamp: '2022-09-27 22:26:49+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data-structure/test/Point_Set_Range_Composite.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/Point_Set_Range_Composite.test.cpp
- /verify/data-structure/test/Point_Set_Range_Composite.test.cpp.html
title: data-structure/test/Point_Set_Range_Composite.test.cpp
---
