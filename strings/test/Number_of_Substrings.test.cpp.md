---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: strings/suffix_array.hpp
    title: strings/suffix_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"strings/test/Number_of_Substrings.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\n\n#line 1 \"strings/suffix_array.hpp\"\
    \nvector<int> sort_cyclic_shifts(string const& s) {\n  int n = s.size();\n  const\
    \ int alphabet = 256;\n\n  vector<int> p(n), c(n), cnt(max(alphabet, n), 0);\n\
    \  for (int i = 0; i < n; i++) cnt[s[i]]++;\n  for (int i = 1; i < alphabet; i++)\
    \ cnt[i] += cnt[i - 1];\n  for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;\n \
    \ c[p[0]] = 0;\n  int classes = 1;\n  for (int i = 1; i < n; i++) {\n    if (s[p[i]]\
    \ != s[p[i - 1]]) classes++;\n    c[p[i]] = classes - 1;\n  }\n  vector<int> pn(n),\
    \ cn(n);\n  for (int h = 0; (1 << h) < n; ++h) {\n    for (int i = 0; i < n; i++)\
    \ {\n      pn[i] = p[i] - (1 << h);\n      if (pn[i] < 0) pn[i] += n;\n    }\n\
    \    fill(cnt.begin(), cnt.begin() + classes, 0);\n    for (int i = 0; i < n;\
    \ i++) cnt[c[pn[i]]]++;\n    for (int i = 1; i < classes; i++) cnt[i] += cnt[i\
    \ - 1];\n    for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];\n  \
    \  cn[p[0]] = 0;\n    classes = 1;\n    for (int i = 1; i < n; i++) {\n      pair<int,\
    \ int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};\n      pair<int, int> prev =\
    \ {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};\n      if (cur != prev) ++classes;\n\
    \      cn[p[i]] = classes - 1;\n    }\n    c.swap(cn);\n  }\n  return p;\n}\n\n\
    vector<int> suffix_array(string s) {\n  s += string(1, 0);\n  vector<int> sorted_shifts\
    \ = sort_cyclic_shifts(s);\n  sorted_shifts.erase(sorted_shifts.begin());\n  return\
    \ sorted_shifts;\n}\n\nvector<int> lcp_array(string const& s, vector<int> const&\
    \ p) {\n  int n = s.size();\n  vector<int> rank(n, 0);\n  for (int i = 0; i <\
    \ n; i++) rank[p[i]] = i;\n\n  int k = 0;\n  vector<int> lcp(n - 1, 0);\n  for\
    \ (int i = 0; i < n; i++) {\n    if (rank[i] == n - 1) {\n      k = 0;\n     \
    \ continue;\n    }\n    int j = p[rank[i] + 1];\n    while (i + k < n && j + k\
    \ < n && s[i + k] == s[j + k]) k++;\n    lcp[rank[i]] = k;\n    if (k) k--;\n\
    \  }\n  return lcp;\n}\n#line 10 \"strings/test/Number_of_Substrings.test.cpp\"\
    \n\nvoid solve(int ith) {\n  string s;\n  cin >> s;\n  int n = s.length();\n \
    \ auto lcp = lcp_array(s, suffix_array(s));\n  ll ans = 1ll * n * (n + 1) / 2;\n\
    \  for(auto v: lcp) ans -= v;\n  cout << ans;\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >>\
    \ tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\n\
    #include \"../suffix_array.hpp\"\n\nvoid solve(int ith) {\n  string s;\n  cin\
    \ >> s;\n  int n = s.length();\n  auto lcp = lcp_array(s, suffix_array(s));\n\
    \  ll ans = 1ll * n * (n + 1) / 2;\n  for(auto v: lcp) ans -= v;\n  cout << ans;\n\
    }\n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}"
  dependsOn:
  - strings/suffix_array.hpp
  isVerificationFile: true
  path: strings/test/Number_of_Substrings.test.cpp
  requiredBy: []
  timestamp: '2022-09-08 21:32:23+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: strings/test/Number_of_Substrings.test.cpp
layout: document
redirect_from:
- /verify/strings/test/Number_of_Substrings.test.cpp
- /verify/strings/test/Number_of_Substrings.test.cpp.html
title: strings/test/Number_of_Substrings.test.cpp
---
