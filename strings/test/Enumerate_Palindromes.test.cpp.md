---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: strings/manacher.hpp
    title: strings/manacher.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"strings/test/Enumerate_Palindromes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\n#include <bits/extc++.h>\n\
    \nusing namespace std;\nusing namespace __gnu_cxx;\nusing namespace __gnu_pbds;\n\
    \n#line 1 \"strings/manacher.hpp\"\nvector<int> manacher_odd(string s) {\n  int\
    \ n = s.size();\n  s = \"$\" + s + \"^\";\n  vector<int> p(n + 2);\n  int l =\
    \ 1, r = 1;\n  for (int i = 1; i <= n; i++) {\n    p[i] = max(0, min(r - i, p[l\
    \ + (r - i)]));\n    while (s[i - p[i]] == s[i + p[i]]) {\n      p[i]++;\n   \
    \ }\n    if (i + p[i] > r) {\n      l = i - p[i], r = i + p[i];\n    }\n  }\n\
    \  return vector<int>(begin(p) + 1, end(p) - 1);\n}\n\nvector<int> manacher(const\
    \ string &s) {\n  string t;\n  for (auto c : s) {\n    t += string(\"#\") + c;\n\
    \  }\n  auto res = manacher_odd(t + \"#\");\n  return vector<int>(begin(res) +\
    \ 1, end(res) - 1);\n}\n#line 10 \"strings/test/Enumerate_Palindromes.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  string s;\n  cin >> s;\n  auto ans = manacher(s);\n  for (auto v : ans) cout\
    \ << v - 1 << ' ';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include <bits/extc++.h>\n\nusing namespace std;\nusing namespace __gnu_cxx;\n\
    using namespace __gnu_pbds;\n\n#include \"../manacher.hpp\"\n\nsigned main() {\n\
    \  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  string s;\n  cin >> s;\n  auto ans = manacher(s);\n  for (auto v : ans) cout\
    \ << v - 1 << ' ';\n}"
  dependsOn:
  - strings/manacher.hpp
  isVerificationFile: true
  path: strings/test/Enumerate_Palindromes.test.cpp
  requiredBy: []
  timestamp: '2022-09-29 23:59:15+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: strings/test/Enumerate_Palindromes.test.cpp
layout: document
redirect_from:
- /verify/strings/test/Enumerate_Palindromes.test.cpp
- /verify/strings/test/Enumerate_Palindromes.test.cpp.html
title: strings/test/Enumerate_Palindromes.test.cpp
---
