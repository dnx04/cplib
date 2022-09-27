---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy_segtree.hpp
    title: Lazy Segment Tree
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
    #line 2 \"utility/static_modulo.hpp\"\n\ntemplate <int mod>\nstruct static_modulo\
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
    \ get_mod() { return mod; }\n};\n#line 9 \"data-structure/test/Range_Affine_Range_Sum.test.cpp\"\
    \n\nusing Fp = static_modulo<998244353>;\n\nstruct S {\n  Fp a;\n  int size;\n\
    };\nstruct F {\n  Fp a, b;\n};\nS op(S l, S r) { return S{l.a + r.a, l.size +\
    \ r.size}; }\nS e() { return S{0, 0}; }\nS mapping(F l, S r) { return S{r.a *\
    \ l.a + l.b * r.size, r.size}; }\nF composition(F l, F r) { return F{r.a * l.a,\
    \ r.b * l.a + l.b}; }\nF id() { return F{1, 0}; }\n\nint main() {\n  int n, q;\n\
    \  cin >> n >> q;\n  vector<S> a(n);\n  for (int i = 0; i < n; i++) {\n    int\
    \ x;\n    cin >> x;\n    a[i] = S{x, 1};\n  }\n  lazy_segtree<S, op, e, F, mapping,\
    \ composition, id> seg(a);\n  for (int i = 0; i < q; i++) {\n    int t;\n    cin\
    \ >> t;\n    if (t == 0) {\n      int l, r;\n      int c, d;\n      cin >> l >>\
    \ r >> c >> d;\n      seg.apply(l, r, F{c, d});\n    } else {\n      int l, r;\n\
    \      cin >> l >> r;\n      cout << seg.prod(l, r).a << '\\n';\n    }\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <bits/extc++.h>\n\nusing namespace std;\n\n#include \"data-structure/lazy_segtree.hpp\"\
    \n#include \"utility/static_modulo.hpp\"\n\nusing Fp = static_modulo<998244353>;\n\
    \nstruct S {\n  Fp a;\n  int size;\n};\nstruct F {\n  Fp a, b;\n};\nS op(S l,\
    \ S r) { return S{l.a + r.a, l.size + r.size}; }\nS e() { return S{0, 0}; }\n\
    S mapping(F l, S r) { return S{r.a * l.a + l.b * r.size, r.size}; }\nF composition(F\
    \ l, F r) { return F{r.a * l.a, r.b * l.a + l.b}; }\nF id() { return F{1, 0};\
    \ }\n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  vector<S> a(n);\n  for (int\
    \ i = 0; i < n; i++) {\n    int x;\n    cin >> x;\n    a[i] = S{x, 1};\n  }\n\
    \  lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);\n  for (int i =\
    \ 0; i < q; i++) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      int l,\
    \ r;\n      int c, d;\n      cin >> l >> r >> c >> d;\n      seg.apply(l, r, F{c,\
    \ d});\n    } else {\n      int l, r;\n      cin >> l >> r;\n      cout << seg.prod(l,\
    \ r).a << '\\n';\n    }\n  }\n}"
  dependsOn:
  - data-structure/lazy_segtree.hpp
  - utility/static_modulo.hpp
  isVerificationFile: true
  path: data-structure/test/Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2022-09-27 22:26:49+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data-structure/test/Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/Range_Affine_Range_Sum.test.cpp
- /verify/data-structure/test/Range_Affine_Range_Sum.test.cpp.html
title: data-structure/test/Range_Affine_Range_Sum.test.cpp
---
