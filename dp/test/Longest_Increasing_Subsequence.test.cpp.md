---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/lis.hpp
    title: dp/lis.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"dp/test/Longest_Increasing_Subsequence.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\n\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using ull = unsigned long long;\n\n#line 1 \"dp/lis.hpp\"\n// return a vector\
    \ contains indices of the LIS\ntemplate <typename T>\nvector<int> lis(const vector<T>&\
    \ a) {\n  int n = (int)a.size();\n  vector<int> b(n + 1, 0), f(n, 0);\n  int ans\
    \ = 0;\n  for (int i = 0; i < n; i++) {\n    f[i] = lower_bound(begin(b) + 1,\
    \ begin(b) + ans + 1, a[i]) - begin(b);\n    ans = max(ans, f[i]);\n    b[f[i]]\
    \ = a[i];\n  }\n  int req = ans;\n  vector<int> res;\n  for (int i = n - 1; i\
    \ >= 0; i--) {\n    if (f[i] == req) {\n      res.push_back(i);\n      --req;\n\
    \    }\n  }\n  reverse(begin(res), end(res));\n  return res;\n}\n#line 11 \"dp/test/Longest_Increasing_Subsequence.test.cpp\"\
    \n\nvoid solve([[maybe_unused]] int ith) {\n  int n;\n  cin >> n;\n  vector<int>\
    \ a(n);\n  for (auto &x : a) cin >> x;\n  auto ans = lis(a);\n  cout << ans.size()\
    \ << '\\n';\n  for (auto idx : ans) cout << idx << ' ';\n}\n\nsigned main() {\n\
    \  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using ull = unsigned long long;\n\n#include \"../lis.hpp\"\n\nvoid solve([[maybe_unused]]\
    \ int ith) {\n  int n;\n  cin >> n;\n  vector<int> a(n);\n  for (auto &x : a)\
    \ cin >> x;\n  auto ans = lis(a);\n  cout << ans.size() << '\\n';\n  for (auto\
    \ idx : ans) cout << idx << ' ';\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >>\
    \ tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}"
  dependsOn:
  - dp/lis.hpp
  isVerificationFile: true
  path: dp/test/Longest_Increasing_Subsequence.test.cpp
  requiredBy: []
  timestamp: '2022-09-09 16:34:35+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: dp/test/Longest_Increasing_Subsequence.test.cpp
layout: document
redirect_from:
- /verify/dp/test/Longest_Increasing_Subsequence.test.cpp
- /verify/dp/test/Longest_Increasing_Subsequence.test.cpp.html
title: dp/test/Longest_Increasing_Subsequence.test.cpp
---
