---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: strings/zf.hpp
    title: strings/zf.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"strings/test/Z_Algorithm.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include <bits/extc++.h>\n\nusing\
    \ namespace std;\nusing namespace __gnu_cxx;\nusing namespace __gnu_pbds;\n\n\
    #line 1 \"strings/zf.hpp\"\nvector<int> zf(const string &s) {\n  int n = (int)s.length();\n\
    \  vector<int> z(n);\n  for (int i = 1, l = 0, r = 0; i < n; ++i) {\n    if (i\
    \ <= r) z[i] = min(r - i + 1, z[i - l]);\n    while (i + z[i] < n && s[z[i]] ==\
    \ s[i + z[i]]) ++z[i];\n    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;\n \
    \ }\n  return z;\n}\n#line 10 \"strings/test/Z_Algorithm.test.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  string s;\n  cin >> s;\n  auto z = zf(s);\n  z[0] = s.length();\n  for (auto\
    \ v : z) cout << v << ' ';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ <bits/extc++.h>\n\nusing namespace std;\nusing namespace __gnu_cxx;\nusing namespace\
    \ __gnu_pbds;\n\n#include \"../zf.hpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  string s;\n  cin >> s;\n\
    \  auto z = zf(s);\n  z[0] = s.length();\n  for (auto v : z) cout << v << ' ';\n\
    }"
  dependsOn:
  - strings/zf.hpp
  isVerificationFile: true
  path: strings/test/Z_Algorithm.test.cpp
  requiredBy: []
  timestamp: '2022-08-19 13:47:55+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: strings/test/Z_Algorithm.test.cpp
layout: document
redirect_from:
- /verify/strings/test/Z_Algorithm.test.cpp
- /verify/strings/test/Z_Algorithm.test.cpp.html
title: strings/test/Z_Algorithm.test.cpp
---
