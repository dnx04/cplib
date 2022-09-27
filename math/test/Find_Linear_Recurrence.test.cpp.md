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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algo/math/berlekamp_massey.hpp:\
    \ line -1: no such header\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using ull = unsigned long long;\n\n#include \"algo/math/berlekamp_massey.hpp\"\
    \n#include \"algo/utility/static_modulo.hpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  using Fp = static_modulo<998244353>;\n\
    \  int n;\n  cin >> n;\n  vector<Fp> c(n);\n  for (auto &x : c) cin >> x;\n  auto\
    \ f = berlekamp_massey<Fp>(c);\n  cout << (int)f.size() - 1 << '\\n';\n  for (int\
    \ i = 1; i < (int)f.size(); ++i) cout << -f[i] << ' ';\n}"
  dependsOn: []
  isVerificationFile: true
  path: math/test/Find_Linear_Recurrence.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: math/test/Find_Linear_Recurrence.test.cpp
layout: document
redirect_from:
- /verify/math/test/Find_Linear_Recurrence.test.cpp
- /verify/math/test/Find_Linear_Recurrence.test.cpp.html
title: math/test/Find_Linear_Recurrence.test.cpp
---
