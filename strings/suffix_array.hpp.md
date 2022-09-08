---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: strings/test/Number_of_Substrings.test.cpp
    title: strings/test/Number_of_Substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: strings/test/Suffix_Array.test.cpp
    title: strings/test/Suffix_Array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"strings/suffix_array.hpp\"\nvector<int> sort_cyclic_shifts(string\
    \ const& s) {\n  int n = s.size();\n  const int alphabet = 256;\n\n  vector<int>\
    \ p(n), c(n), cnt(max(alphabet, n), 0);\n  for (int i = 0; i < n; i++) cnt[s[i]]++;\n\
    \  for (int i = 1; i < alphabet; i++) cnt[i] += cnt[i - 1];\n  for (int i = 0;\
    \ i < n; i++) p[--cnt[s[i]]] = i;\n  c[p[0]] = 0;\n  int classes = 1;\n  for (int\
    \ i = 1; i < n; i++) {\n    if (s[p[i]] != s[p[i - 1]]) classes++;\n    c[p[i]]\
    \ = classes - 1;\n  }\n  vector<int> pn(n), cn(n);\n  for (int h = 0; (1 << h)\
    \ < n; ++h) {\n    for (int i = 0; i < n; i++) {\n      pn[i] = p[i] - (1 << h);\n\
    \      if (pn[i] < 0) pn[i] += n;\n    }\n    fill(cnt.begin(), cnt.begin() +\
    \ classes, 0);\n    for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;\n    for (int\
    \ i = 1; i < classes; i++) cnt[i] += cnt[i - 1];\n    for (int i = n - 1; i >=\
    \ 0; i--) p[--cnt[c[pn[i]]]] = pn[i];\n    cn[p[0]] = 0;\n    classes = 1;\n \
    \   for (int i = 1; i < n; i++) {\n      pair<int, int> cur = {c[p[i]], c[(p[i]\
    \ + (1 << h)) % n]};\n      pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] +\
    \ (1 << h)) % n]};\n      if (cur != prev) ++classes;\n      cn[p[i]] = classes\
    \ - 1;\n    }\n    c.swap(cn);\n  }\n  return p;\n}\n\nvector<int> suffix_array(string\
    \ s) {\n  s += string(1, 0);\n  vector<int> sorted_shifts = sort_cyclic_shifts(s);\n\
    \  sorted_shifts.erase(sorted_shifts.begin());\n  return sorted_shifts;\n}\n\n\
    vector<int> lcp_array(string const& s, vector<int> const& p) {\n  int n = s.size();\n\
    \  vector<int> rank(n, 0);\n  for (int i = 0; i < n; i++) rank[p[i]] = i;\n\n\
    \  int k = 0;\n  vector<int> lcp(n - 1, 0);\n  for (int i = 0; i < n; i++) {\n\
    \    if (rank[i] == n - 1) {\n      k = 0;\n      continue;\n    }\n    int j\
    \ = p[rank[i] + 1];\n    while (i + k < n && j + k < n && s[i + k] == s[j + k])\
    \ k++;\n    lcp[rank[i]] = k;\n    if (k) k--;\n  }\n  return lcp;\n}\n"
  code: "vector<int> sort_cyclic_shifts(string const& s) {\n  int n = s.size();\n\
    \  const int alphabet = 256;\n\n  vector<int> p(n), c(n), cnt(max(alphabet, n),\
    \ 0);\n  for (int i = 0; i < n; i++) cnt[s[i]]++;\n  for (int i = 1; i < alphabet;\
    \ i++) cnt[i] += cnt[i - 1];\n  for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;\n\
    \  c[p[0]] = 0;\n  int classes = 1;\n  for (int i = 1; i < n; i++) {\n    if (s[p[i]]\
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
    \  }\n  return lcp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: strings/suffix_array.hpp
  requiredBy: []
  timestamp: '2022-09-08 21:32:23+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - strings/test/Suffix_Array.test.cpp
  - strings/test/Number_of_Substrings.test.cpp
documentation_of: strings/suffix_array.hpp
layout: document
redirect_from:
- /library/strings/suffix_array.hpp
- /library/strings/suffix_array.hpp.html
title: strings/suffix_array.hpp
---
