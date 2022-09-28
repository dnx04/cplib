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
  bundledCode: "#line 1 \"strings/lyndon.hpp\"\nvector<string> duval(string const&\
    \ s) {\n  int n = s.size();\n  int i = 0;\n  vector<string> factorization;\n \
    \ while (i < n) {\n    int j = i + 1, k = i;\n    while (j < n && s[k] <= s[j])\
    \ {\n      if (s[k] < s[j])\n        k = i;\n      else\n        k++;\n      j++;\n\
    \    }\n    while (i <= k) {\n      factorization.push_back(s.substr(i, j - k));\n\
    \      i += j - k;\n    }\n  }\n  return factorization;\n}\n\nstring min_cyclic_string(string\
    \ s) {\n  s += s;\n  int n = s.size();\n  int i = 0, ans = 0;\n  while (i < n\
    \ / 2) {\n    ans = i;\n    int j = i + 1, k = i;\n    while (j < n && s[k] <=\
    \ s[j]) {\n      if (s[k] < s[j])\n        k = i;\n      else\n        k++;\n\
    \      j++;\n    }\n    while (i <= k) i += j - k;\n  }\n  return s.substr(ans,\
    \ n / 2);\n}\n"
  code: "vector<string> duval(string const& s) {\n  int n = s.size();\n  int i = 0;\n\
    \  vector<string> factorization;\n  while (i < n) {\n    int j = i + 1, k = i;\n\
    \    while (j < n && s[k] <= s[j]) {\n      if (s[k] < s[j])\n        k = i;\n\
    \      else\n        k++;\n      j++;\n    }\n    while (i <= k) {\n      factorization.push_back(s.substr(i,\
    \ j - k));\n      i += j - k;\n    }\n  }\n  return factorization;\n}\n\nstring\
    \ min_cyclic_string(string s) {\n  s += s;\n  int n = s.size();\n  int i = 0,\
    \ ans = 0;\n  while (i < n / 2) {\n    ans = i;\n    int j = i + 1, k = i;\n \
    \   while (j < n && s[k] <= s[j]) {\n      if (s[k] < s[j])\n        k = i;\n\
    \      else\n        k++;\n      j++;\n    }\n    while (i <= k) i += j - k;\n\
    \  }\n  return s.substr(ans, n / 2);\n}"
  dependsOn: []
  isVerificationFile: false
  path: strings/lyndon.hpp
  requiredBy: []
  timestamp: '2022-09-09 15:49:45+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/lyndon.hpp
layout: document
title: Lyndon factorization
---
