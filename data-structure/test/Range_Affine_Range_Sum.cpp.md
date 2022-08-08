---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/lazy_segtree.hpp
    title: data-structure/lazy_segtree.hpp
  - icon: ':heavy_check_mark:'
    path: number-theory/modint.hpp
    title: number-theory/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/extc++.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"bits/extc++.h\"\n\nusing namespace std;\n\n#include \"../algo/data-structure/lazy_segtree.hpp\"\
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
  isVerificationFile: false
  path: data-structure/test/Range_Affine_Range_Sum.cpp
  requiredBy: []
  timestamp: '2022-08-08 19:06:24+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/test/Range_Affine_Range_Sum.cpp
layout: document
redirect_from:
- /library/data-structure/test/Range_Affine_Range_Sum.cpp
- /library/data-structure/test/Range_Affine_Range_Sum.cpp.html
title: data-structure/test/Range_Affine_Range_Sum.cpp
---
