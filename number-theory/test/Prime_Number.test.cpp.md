---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: number-theory/sieve.hpp
    title: number-theory/sieve.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/extc++.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009\"\
    \n\n#include \"bits/extc++.h\"\n\nusing namespace std;\nusing namespace __gnu_pbds;\n\
    using namespace __gnu_cxx;\n\n#include \"../algo/number-theory/sieve.hpp\"\n\n\
    #ifdef DEBUG\n#include \"tools/prettyprint.hpp\"\n#endif\n\nsigned main() {\n\
    \  ios::sync_with_stdio(false), cin.tie(0);\n  vector<int> primes = sieve(1e6);\n\
    \  for (int i = 1; i <= 1e6; ++i) {\n    primes[i] = (primes[i] == i && i >= 2)\
    \ + primes[i - 1];\n  }\n  int n;\n  while (cin >> n) {\n    cout << primes[n]\
    \ << '\\n';\n  }\n}"
  dependsOn:
  - number-theory/sieve.hpp
  isVerificationFile: true
  path: number-theory/test/Prime_Number.test.cpp
  requiredBy: []
  timestamp: '2022-08-08 19:58:01+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: number-theory/test/Prime_Number.test.cpp
layout: document
redirect_from:
- /verify/number-theory/test/Prime_Number.test.cpp
- /verify/number-theory/test/Prime_Number.test.cpp.html
title: number-theory/test/Prime_Number.test.cpp
---
