---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algo/strings/suffix_array.hpp:\
    \ line -1: no such header\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    \n#include \"algo/strings/suffix_array.hpp\"\n\nvoid solve(int ith) {\n  string\
    \ s;\n  cin >> s;\n  int n = s.length();\n  auto lcp = lcp_array(s, suffix_array(s));\n\
    \  ll ans = n * (n + 1) / 2;\n  for(auto v: lcp) ans -= v;\n  cout << ans;\n}\n\
    \nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}"
  dependsOn: []
  isVerificationFile: true
  path: strings/test/Number_of_Substrings.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: strings/test/Number_of_Substrings.test.cpp
layout: document
redirect_from:
- /verify/strings/test/Number_of_Substrings.test.cpp
- /verify/strings/test/Number_of_Substrings.test.cpp.html
title: strings/test/Number_of_Substrings.test.cpp
---
