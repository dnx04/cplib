---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: strings/test/Enumerate_Palindromes.test.cpp
    title: strings/test/Enumerate_Palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"strings/manacher.hpp\"\nvector<int> manacher_odd(string\
    \ s) {\n  int n = s.size();\n  s = \"$\" + s + \"^\";\n  vector<int> p(n + 2);\n\
    \  int l = 1, r = 1;\n  for (int i = 1; i <= n; i++) {\n    p[i] = max(0, min(r\
    \ - i, p[l + (r - i)]));\n    while (s[i - p[i]] == s[i + p[i]]) {\n      p[i]++;\n\
    \    }\n    if (i + p[i] > r) {\n      l = i - p[i], r = i + p[i];\n    }\n  }\n\
    \  return vector<int>(begin(p) + 1, end(p) - 1);\n}\n\nvector<int> manacher(const\
    \ string &s) {\n  string t;\n  for (auto c : s) {\n    t += string(\"#\") + c;\n\
    \  }\n  auto res = manacher_odd(t + \"#\");\n  return vector<int>(begin(res) +\
    \ 1, end(res) - 1);\n}\n"
  code: "vector<int> manacher_odd(string s) {\n  int n = s.size();\n  s = \"$\" +\
    \ s + \"^\";\n  vector<int> p(n + 2);\n  int l = 1, r = 1;\n  for (int i = 1;\
    \ i <= n; i++) {\n    p[i] = max(0, min(r - i, p[l + (r - i)]));\n    while (s[i\
    \ - p[i]] == s[i + p[i]]) {\n      p[i]++;\n    }\n    if (i + p[i] > r) {\n \
    \     l = i - p[i], r = i + p[i];\n    }\n  }\n  return vector<int>(begin(p) +\
    \ 1, end(p) - 1);\n}\n\nvector<int> manacher(const string &s) {\n  string t;\n\
    \  for (auto c : s) {\n    t += string(\"#\") + c;\n  }\n  auto res = manacher_odd(t\
    \ + \"#\");\n  return vector<int>(begin(res) + 1, end(res) - 1);\n}"
  dependsOn: []
  isVerificationFile: false
  path: strings/manacher.hpp
  requiredBy: []
  timestamp: '2022-09-29 23:59:15+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - strings/test/Enumerate_Palindromes.test.cpp
documentation_of: strings/manacher.hpp
layout: document
redirect_from:
- /library/strings/manacher.hpp
- /library/strings/manacher.hpp.html
title: strings/manacher.hpp
---
