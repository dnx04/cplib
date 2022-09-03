---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy_segtree.hpp
    title: data-structure/lazy_segtree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"data-structure/test/Range_Affine_Range_Sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n\
    #include <bits/extc++.h>\n\nusing namespace std;\n\n#line 1 \"data-structure/lazy_segtree.hpp\"\
    \ntemplate <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\n \
    \         F (*composition)(F, F), F (*id)()>\nstruct lazy_segtree {\n public:\n\
    \  lazy_segtree() : lazy_segtree(0) {}\n  explicit lazy_segtree(int n) : lazy_segtree(vector<S>(n,\
    \ e())) {}\n  explicit lazy_segtree(const vector<S>& v) : n(int(v.size())) {\n\
    \    log = ceil(log2(double(n)));\n    size = 1 << log;\n    d = vector<S>(2 *\
    \ size, e());\n    lz = vector<F>(size, id());\n    for (int i = 0; i < n; i++)\
    \ d[size + i] = v[i];\n    for (int i = size - 1; i >= 1; i--) {\n      update(i);\n\
    \    }\n  }\n\n  void set(int p, S x) {\n    assert(0 <= p && p < n);\n    p +=\
    \ size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    d[p] = x;\n   \
    \ for (int i = 1; i <= log; i++) update(p >> i);\n  }\n\n  S get(int p) {\n  \
    \  assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n    return d[p];\n  }\n\n  S prod(int l, int r) {\n    assert(0\
    \ <= l && l <= r && r <= n);\n    if (l == r) return e();\n\n    l += size;\n\
    \    r += size;\n\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) <<\
    \ i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \    }\n\n    S sml = e(), smr = e();\n    while (l < r) {\n      if (l & 1) sml\
    \ = op(sml, d[l++]);\n      if (r & 1) smr = op(d[--r], smr);\n      l >>= 1;\n\
    \      r >>= 1;\n    }\n\n    return op(sml, smr);\n  }\n\n  S all_prod() { return\
    \ d[1]; }\n\n  void apply(int p, F f) {\n    assert(0 <= p && p < n);\n    p +=\
    \ size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    d[p] = mapping(f,\
    \ d[p]);\n    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n  void apply(int\
    \ l, int r, F f) {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n\
    \n    l += size;\n    r += size;\n\n    for (int i = log; i >= 1; i--) {\n   \
    \   if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n    }\n\n    {\n      int l2 = l, r2 = r;\n      while (l < r)\
    \ {\n        if (l & 1) all_apply(l++, f);\n        if (r & 1) all_apply(--r,\
    \ f);\n        l >>= 1;\n        r >>= 1;\n      }\n      l = l2;\n      r = r2;\n\
    \    }\n\n    for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l)\
    \ update(l >> i);\n      if (((r >> i) << i) != r) update((r - 1) >> i);\n   \
    \ }\n  }\n\n  template <bool (*g)(S)>\n  int max_right(int l) {\n    return max_right(l,\
    \ [](S x) { return g(x); });\n  }\n  template <class G>\n  int max_right(int l,\
    \ G g) {\n    assert(0 <= l && l <= n);\n    assert(g(e()));\n    if (l == n)\
    \ return n;\n    l += size;\n    for (int i = log; i >= 1; i--) push(l >> i);\n\
    \    S sm = e();\n    do {\n      while (l % 2 == 0) l >>= 1;\n      if (!g(op(sm,\
    \ d[l]))) {\n        while (l < size) {\n          push(l);\n          l = (2\
    \ * l);\n          if (g(op(sm, d[l]))) {\n            sm = op(sm, d[l]);\n  \
    \          l++;\n          }\n        }\n        return l - size;\n      }\n \
    \     sm = op(sm, d[l]);\n      l++;\n    } while ((l & -l) != l);\n    return\
    \ n;\n  }\n\n  template <bool (*g)(S)>\n  int min_left(int r) {\n    return min_left(r,\
    \ [](S x) { return g(x); });\n  }\n  template <class G>\n  int min_left(int r,\
    \ G g) {\n    assert(0 <= r && r <= n);\n    assert(g(e()));\n    if (r == 0)\
    \ return 0;\n    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >>\
    \ i);\n    S sm = e();\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r\
    \ >>= 1;\n      if (!g(op(d[r], sm))) {\n        while (r < size) {\n        \
    \  push(r);\n          r = (2 * r + 1);\n          if (g(op(d[r], sm))) {\n  \
    \          sm = op(d[r], sm);\n            r--;\n          }\n        }\n    \
    \    return r + 1 - size;\n      }\n      sm = op(d[r], sm);\n    } while ((r\
    \ & -r) != r);\n    return 0;\n  }\n\n private:\n  int n, size, log;\n  vector<S>\
    \ d;\n  vector<F> lz;\n\n  void update(int k) { d[k] = op(d[2 * k], d[2 * k +\
    \ 1]); }\n  void all_apply(int k, F f) {\n    d[k] = mapping(f, d[k]);\n    if\
    \ (k < size) lz[k] = composition(f, lz[k]);\n  }\n  void push(int k) {\n    all_apply(2\
    \ * k, lz[k]);\n    all_apply(2 * k + 1, lz[k]);\n    lz[k] = id();\n  }\n};\n\
    #line 1 \"number-theory/modint.hpp\"\nusing ll = long long;\n\ntemplate <const\
    \ ll m>\nstruct Mod {\n  ll v;\n\n  Mod() : v(0){};\n  Mod(ll _v) : v((_v + m)\
    \ % m){};\n  explicit operator ll() { return v; }\n  Mod inv() const {\n    ll\
    \ a = v, b = m, ax = 1, bx = 0;\n    while (b) {\n      ll q = a / b, t = a %\
    \ b;\n      a = b, b = t, t = ax - bx * q, ax = bx, bx = t;\n    }\n    assert(a\
    \ == 1);\n    ax = (ax < 0 ? ax + m : ax);\n    return ax;\n  }\n  Mod& operator+=(const\
    \ Mod& that) {\n    v = (v + that.v >= m ? v + that.v - m : v + that.v);\n   \
    \ return *this;\n  }\n  Mod& operator-=(const Mod& that) {\n    v = (v >= that.v\
    \ ? v - that.v : v + m - that.v);\n    return *this;\n  }\n  Mod& operator*=(const\
    \ Mod& that) {\n    v = v * that.v % m;\n    return *this;\n  }\n  Mod& operator/=(const\
    \ Mod& that) { return (*this) *= that.inv(); }\n  Mod operator^(ll y) {\n    if\
    \ (!y) return Mod(1);\n    Mod r = *this ^ (y >> 1);\n    r = r * r;\n    return\
    \ y & 1 ? *this * r : r;\n  }\n  Mod operator+(const Mod& that) const { return\
    \ Mod(*this) += that; }\n  Mod operator-(const Mod& that) const { return Mod(*this)\
    \ -= that; }\n  Mod operator*(const Mod& that) const { return Mod(*this) *= that;\
    \ }\n  Mod operator/(const Mod& that) const { return Mod(*this) /= that; }\n \
    \ bool operator==(const Mod& that) const { return this->v == that.v; }\n  friend\
    \ istream& operator>>(istream& in, Mod& that) {\n    ll val;\n    in >> val;\n\
    \    that = Mod(val);\n    return in;\n  }\n  friend ostream& operator<<(ostream&\
    \ out, const Mod& that) {\n    return out << that.v;\n  }\n};\n#line 9 \"data-structure/test/Range_Affine_Range_Sum.test.cpp\"\
    \n\nusing mint = Mod<998244353>;\n\nstruct S {\n  mint a;\n  int size;\n};\nstruct\
    \ F {\n  mint a, b;\n};\nS op(S l, S r) { return S{l.a + r.a, l.size + r.size};\
    \ }\nS e() { return S{0, 0}; }\nS mapping(F l, S r) { return S{r.a * l.a + l.b\
    \ * r.size, r.size}; }\nF composition(F l, F r) { return F{r.a * l.a, r.b * l.a\
    \ + l.b}; }\nF id() { return F{1, 0}; }\nint main() {\n  int n, q;\n  cin >> n\
    \ >> q;\n  vector<S> a(n);\n  for (int i = 0; i < n; i++) {\n    int x;\n    cin\
    \ >> x;\n    a[i] = S{x, 1};\n  }\n  lazy_segtree<S, op, e, F, mapping, composition,\
    \ id> seg(a);\n  for (int i = 0; i < q; i++) {\n    int t;\n    cin >> t;\n  \
    \  if (t == 0) {\n      int l, r;\n      int c, d;\n      cin >> l >> r >> c >>\
    \ d;\n      seg.apply(l, r, F{c, d});\n    } else {\n      int l, r;\n      cin\
    \ >> l >> r;\n      cout << seg.prod(l, r).a << '\\n';\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <bits/extc++.h>\n\nusing namespace std;\n\n#include \"../algo/data-structure/lazy_segtree.hpp\"\
    \n#include \"../algo/number-theory/modint.hpp\"\n\nusing mint = Mod<998244353>;\n\
    \nstruct S {\n  mint a;\n  int size;\n};\nstruct F {\n  mint a, b;\n};\nS op(S\
    \ l, S r) { return S{l.a + r.a, l.size + r.size}; }\nS e() { return S{0, 0}; }\n\
    S mapping(F l, S r) { return S{r.a * l.a + l.b * r.size, r.size}; }\nF composition(F\
    \ l, F r) { return F{r.a * l.a, r.b * l.a + l.b}; }\nF id() { return F{1, 0};\
    \ }\nint main() {\n  int n, q;\n  cin >> n >> q;\n  vector<S> a(n);\n  for (int\
    \ i = 0; i < n; i++) {\n    int x;\n    cin >> x;\n    a[i] = S{x, 1};\n  }\n\
    \  lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);\n  for (int i =\
    \ 0; i < q; i++) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      int l,\
    \ r;\n      int c, d;\n      cin >> l >> r >> c >> d;\n      seg.apply(l, r, F{c,\
    \ d});\n    } else {\n      int l, r;\n      cin >> l >> r;\n      cout << seg.prod(l,\
    \ r).a << '\\n';\n    }\n  }\n}"
  dependsOn:
  - data-structure/lazy_segtree.hpp
  - number-theory/modint.hpp
  isVerificationFile: true
  path: data-structure/test/Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2022-08-28 22:13:17+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data-structure/test/Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/Range_Affine_Range_Sum.test.cpp
- /verify/data-structure/test/Range_Affine_Range_Sum.test.cpp.html
title: data-structure/test/Range_Affine_Range_Sum.test.cpp
---
