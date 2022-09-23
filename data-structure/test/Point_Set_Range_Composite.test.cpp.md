---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree.hpp
    title: data-structure/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: number-theory/modint.hpp
    title: number-theory/modint.hpp
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
    };\n#line 2 \"number-theory/modint.hpp\"\n\nusing ll = long long;\n\ntemplate\
    \ <const ll m>\nstruct Mod {\n  ll v;\n\n  Mod() : v(0){};\n  Mod(ll v) : v((v\
    \ + m) % m){};\n  explicit operator ll() { return v; }\n  Mod inv() const {\n\
    \    ll a = v, b = m, ax = 1, bx = 0;\n    while (b) {\n      ll q = a / b, t\
    \ = a % b;\n      a = b, b = t, t = ax - bx * q, ax = bx, bx = t;\n    }\n   \
    \ assert(a == 1);\n    ax = (ax < 0 ? ax + m : ax);\n    return ax;\n  }\n  Mod&\
    \ operator+=(const Mod& that) {\n    v = (v + that.v >= m ? v + that.v - m : v\
    \ + that.v);\n    return *this;\n  }\n  Mod& operator-=(const Mod& that) {\n \
    \   v = (v >= that.v ? v - that.v : v + m - that.v);\n    return *this;\n  }\n\
    \  Mod& operator*=(const Mod& that) {\n    v = v * that.v % m;\n    return *this;\n\
    \  }\n  Mod& operator/=(const Mod& that) { return (*this) *= that.inv(); }\n \
    \ Mod operator^(ll y) {\n    if (!y) return Mod(1);\n    Mod r = *this ^ (y >>\
    \ 1);\n    r = r * r;\n    return y & 1 ? *this * r : r;\n  }\n  Mod operator+(const\
    \ Mod& that) const { return Mod(*this) += that; }\n  Mod operator-(const Mod&\
    \ that) const { return Mod(*this) -= that; }\n  Mod operator*(const Mod& that)\
    \ const { return Mod(*this) *= that; }\n  Mod operator/(const Mod& that) const\
    \ { return Mod(*this) /= that; }\n  bool operator==(const Mod& that) const { return\
    \ this->v == that.v; }\n  friend istream& operator>>(istream& in, Mod& that) {\n\
    \    ll val;\n    in >> val;\n    that = Mod(val);\n    return in;\n  }\n  friend\
    \ ostream& operator<<(ostream& out, const Mod& that) {\n    return out << that.v;\n\
    \  }\n};\n#line 12 \"data-structure/test/Point_Set_Range_Composite.test.cpp\"\n\
    \nusing Fp = Mod<998244353>;\n\nstruct S {\n  Fp a, b;\n};\n\nS op(S x, S y) {\
    \ return {x.a * y.a, x.b * y.a + y.b}; }\n\nS e() { return {1, 0}; }\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  int n, q;\n  cin >> n >> q;\n  vector<S> a(n);\n  for (int i = 0; i < n; i++)\
    \ cin >> a[i].a >> a[i].b;\n  segtree<S, op, e> seg(a);\n  while (q--) {\n   \
    \ int t;\n    cin >> t;\n    if (t == 0) {\n      int pos;\n      Fp c, d;\n \
    \     cin >> pos >> c >> d;\n      seg.set(pos, S{c, d});\n    } else {\n    \
    \  int l, r, x;\n      cin >> l >> r >> x;\n      auto [c, d] = seg.prod(l, r);\n\
    \      cout << c * x + d << '\\n';\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using ull = unsigned long long;\n\n#include \"data-structure/segtree.hpp\"\n#include\
    \ \"number-theory/modint.hpp\"\n\nusing Fp = Mod<998244353>;\n\nstruct S {\n \
    \ Fp a, b;\n};\n\nS op(S x, S y) { return {x.a * y.a, x.b * y.a + y.b}; }\n\n\
    S e() { return {1, 0}; }\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  int n, q;\n  cin >> n >>\
    \ q;\n  vector<S> a(n);\n  for (int i = 0; i < n; i++) cin >> a[i].a >> a[i].b;\n\
    \  segtree<S, op, e> seg(a);\n  while (q--) {\n    int t;\n    cin >> t;\n   \
    \ if (t == 0) {\n      int pos;\n      Fp c, d;\n      cin >> pos >> c >> d;\n\
    \      seg.set(pos, S{c, d});\n    } else {\n      int l, r, x;\n      cin >>\
    \ l >> r >> x;\n      auto [c, d] = seg.prod(l, r);\n      cout << c * x + d <<\
    \ '\\n';\n    }\n  }\n}"
  dependsOn:
  - data-structure/segtree.hpp
  - number-theory/modint.hpp
  isVerificationFile: true
  path: data-structure/test/Point_Set_Range_Composite.test.cpp
  requiredBy: []
  timestamp: '2022-09-23 09:58:37+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data-structure/test/Point_Set_Range_Composite.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/Point_Set_Range_Composite.test.cpp
- /verify/data-structure/test/Point_Set_Range_Composite.test.cpp.html
title: data-structure/test/Point_Set_Range_Composite.test.cpp
---
