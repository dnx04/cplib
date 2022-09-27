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
  dependsOn: []
  isVerificationFile: true
  path: data-structure/test/Point_Set_Range_Composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: data-structure/test/Point_Set_Range_Composite.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/Point_Set_Range_Composite.test.cpp
- /verify/data-structure/test/Point_Set_Range_Composite.test.cpp.html
title: data-structure/test/Point_Set_Range_Composite.test.cpp
---
