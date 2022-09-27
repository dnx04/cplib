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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../number-theory/modint.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n\n#include <bits/extc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    \n#include \"../../number-theory/modint.hpp\"\n#include \"../hadamard.hpp\"\n\n\
    void solve(int ith) {\n  int n;\n  cin >> n;\n  vector<Mod<998244353>> a(1 <<\
    \ n), b(1 << n);\n  for (auto &x : a) cin >> x;\n  for (auto &x : b) cin >> x;\n\
    \  for (auto val : andconv(a, b)) cout << val << ' ';\n}\n\nsigned main() {\n\
    \  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}"
  dependsOn: []
  isVerificationFile: true
  path: convolution/test/Bitwise_And_Convolution.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: convolution/test/Bitwise_And_Convolution.test.cpp
layout: document
redirect_from:
- /verify/convolution/test/Bitwise_And_Convolution.test.cpp
- /verify/convolution/test/Bitwise_And_Convolution.test.cpp.html
title: convolution/test/Bitwise_And_Convolution.test.cpp
---
