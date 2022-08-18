---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: strings/test/Enumerate_Palindromes.test.cpp
    title: strings/test/Enumerate_Palindromes.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ 1, end(res) - 1);\n}\n\nstring longest_palindrome(string s) {\n  auto p = manacher(s);\n\
    \  int mx_pos = max_element(begin(p), end(p)) - begin(p), len = p[mx_pos] - 1;\n\
    \  return s.substr(mx_pos / 2 - 1, len);\n}\n"
  code: "vector<int> manacher_odd(string s) {\n  int n = s.size();\n  s = \"$\" +\
    \ s + \"^\";\n  vector<int> p(n + 2);\n  int l = 1, r = 1;\n  for (int i = 1;\
    \ i <= n; i++) {\n    p[i] = max(0, min(r - i, p[l + (r - i)]));\n    while (s[i\
    \ - p[i]] == s[i + p[i]]) {\n      p[i]++;\n    }\n    if (i + p[i] > r) {\n \
    \     l = i - p[i], r = i + p[i];\n    }\n  }\n  return vector<int>(begin(p) +\
    \ 1, end(p) - 1);\n}\n\nvector<int> manacher(const string &s) {\n  string t;\n\
    \  for (auto c : s) {\n    t += string(\"#\") + c;\n  }\n  auto res = manacher_odd(t\
    \ + \"#\");\n  return vector<int>(begin(res) + 1, end(res) - 1);\n}\n\nstring\
    \ longest_palindrome(string s) {\n  auto p = manacher(s);\n  int mx_pos = max_element(begin(p),\
    \ end(p)) - begin(p), len = p[mx_pos] - 1;\n  return s.substr(mx_pos / 2 - 1,\
    \ len);\n}"
  dependsOn: []
  isVerificationFile: false
  path: strings/manacher.hpp
  requiredBy: []
  timestamp: '2022-08-19 01:14:13+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - strings/test/Enumerate_Palindromes.test.cpp
documentation_of: strings/manacher.hpp
layout: document
redirect_from:
- /library/strings/manacher.hpp
- /library/strings/manacher.hpp.html
title: strings/manacher.hpp
---
