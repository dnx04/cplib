---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: strings/test/Z_Algorithm.test.cpp
    title: strings/test/Z_Algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"strings/zf.hpp\"\n\nvector<int> zf(const string &s) {\n\
    \  int n = (int)s.length();\n  vector<int> z(n);\n  for (int i = 1, l = 0, r =\
    \ 0; i < n; ++i) {\n    if (i <= r) z[i] = min(r - i + 1, z[i - l]);\n    while\
    \ (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];\n    if (i + z[i] - 1 > r)\
    \ l = i, r = i + z[i] - 1;\n  }\n  return z;\n}\n"
  code: "#pragma once\n\nvector<int> zf(const string &s) {\n  int n = (int)s.length();\n\
    \  vector<int> z(n);\n  for (int i = 1, l = 0, r = 0; i < n; ++i) {\n    if (i\
    \ <= r) z[i] = min(r - i + 1, z[i - l]);\n    while (i + z[i] < n && s[z[i]] ==\
    \ s[i + z[i]]) ++z[i];\n    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;\n \
    \ }\n  return z;\n}"
  dependsOn: []
  isVerificationFile: false
  path: strings/zf.hpp
  requiredBy: []
  timestamp: '2022-09-28 10:01:57+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - strings/test/Z_Algorithm.test.cpp
documentation_of: strings/zf.hpp
layout: document
redirect_from:
- /library/strings/zf.hpp
- /library/strings/zf.hpp.html
title: strings/zf.hpp
---
