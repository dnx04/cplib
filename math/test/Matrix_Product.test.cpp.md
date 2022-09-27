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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n\n#include\
    \ <bits/extc++.h>\n\nusing namespace std;\n\n#include \"../algo/number-theory/modint.hpp\"\
    \n#include \"../matrix.hpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  using mint = Mod<998244353>;\n\
    \  int n, m, k;\n  cin >> n >> m >> k;\n  matrix<mint> a(n, m), b(m, k);\n  for\
    \ (int i = 0; i < n; ++i) {\n    for (int j = 0; j < m; ++j) {\n      cin >> a[i][j];\n\
    \    }\n  }\n  for (int i = 0; i < m; ++i) {\n    for (int j = 0; j < k; ++j)\
    \ {\n      cin >> b[i][j];\n    }\n  }\n  matrix<mint> c = a * b;\n  for (int\
    \ i = 0; i < n; ++i) {\n    for (int j = 0; j < k; ++j) {\n      cout << c[i][j]\
    \ << \" \\n\"[j == k - 1];\n    }\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: math/test/Matrix_Product.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: math/test/Matrix_Product.test.cpp
layout: document
redirect_from:
- /verify/math/test/Matrix_Product.test.cpp
- /verify/math/test/Matrix_Product.test.cpp.html
title: math/test/Matrix_Product.test.cpp
---
