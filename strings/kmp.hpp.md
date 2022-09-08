---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"strings/kmp.hpp\"\nvector<int> kmp(const string &s) {\n\
    \  int n = (int)s.length();\n  vector<int> pi(n);\n  for (int i = 1; i < n; i++)\
    \ {\n    int j = pi[i - 1];\n    while (j > 0 && s[i] != s[j]) j = pi[j - 1];\n\
    \    if (s[i] == s[j]) j++;\n    pi[i] = j;\n  }\n  return pi;\n}\n"
  code: "vector<int> kmp(const string &s) {\n  int n = (int)s.length();\n  vector<int>\
    \ pi(n);\n  for (int i = 1; i < n; i++) {\n    int j = pi[i - 1];\n    while (j\
    \ > 0 && s[i] != s[j]) j = pi[j - 1];\n    if (s[i] == s[j]) j++;\n    pi[i] =\
    \ j;\n  }\n  return pi;\n}"
  dependsOn: []
  isVerificationFile: false
  path: strings/kmp.hpp
  requiredBy: []
  timestamp: '2022-09-08 21:32:23+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/kmp.hpp
layout: document
redirect_from:
- /library/strings/kmp.hpp
- /library/strings/kmp.hpp.html
title: strings/kmp.hpp
---
