---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: number-theory/modint.hpp:\
    \ line -1: no such header\n"
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
  dependsOn: []
  isVerificationFile: true
  path: data-structure/test/Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: data-structure/test/Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/Range_Affine_Range_Sum.test.cpp
- /verify/data-structure/test/Range_Affine_Range_Sum.test.cpp.html
title: data-structure/test/Range_Affine_Range_Sum.test.cpp
---
