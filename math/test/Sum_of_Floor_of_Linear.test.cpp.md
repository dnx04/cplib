---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/floor_sum.hpp
    title: Sum of Floor of Linear
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"math/test/Sum_of_Floor_of_Linear.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    \n#line 2 \"math/floor_sum.hpp\"\n\n// sum_{0 <= i < N} (ai + b) // m\ntemplate\
    \ <typename T>\nT sum_of_floor(T n, T m, T a, T b) {\n  T ret = 0;\n  if (a >=\
    \ m) ret += (n - 1) * n * (a / m) / 2, a %= m;\n  if (b >= m) ret += n * (b /\
    \ m), b %= m;\n  T y = (a * n + b) / m;\n  if (y == 0) return ret;\n  T x = y\
    \ * m - b;\n  ret += (n - (x + a - 1) / a) * y;\n  ret += sum_of_floor(y, a, m,\
    \ (a - x % a) % a);\n  return ret;\n}\n\n// verify www.codechef.com/viewsolution/36222026\n\
    // count x : ax + b mod m < yr, 0 <= x < xr\ntemplate <typename T>\nT mod_affine_range_counting(T\
    \ a, T b, T m, T xr, T yr) {\n  assert(0 <= yr && yr <= m);\n  return sum_of_floor(xr,\
    \ m, a, b + m) - sum_of_floor(xr, m, a, b + m - yr);\n}\n#line 11 \"math/test/Sum_of_Floor_of_Linear.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  int tc;\n  cin >> tc;\n  while(tc--){\n    int n, m, a, b;\n    cin >> n >>\
    \ m >> a >> b;\n    cout << sum_of_floor<ll>(n, m, a, b) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using ull = unsigned long long;\n\n#include \"math/floor_sum.hpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  int tc;\n  cin >> tc;\n  while(tc--){\n    int n, m, a, b;\n    cin >> n >>\
    \ m >> a >> b;\n    cout << sum_of_floor<ll>(n, m, a, b) << '\\n';\n  }\n}"
  dependsOn:
  - math/floor_sum.hpp
  isVerificationFile: true
  path: math/test/Sum_of_Floor_of_Linear.test.cpp
  requiredBy: []
  timestamp: '2022-09-27 23:15:57+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: math/test/Sum_of_Floor_of_Linear.test.cpp
layout: document
redirect_from:
- /verify/math/test/Sum_of_Floor_of_Linear.test.cpp
- /verify/math/test/Sum_of_Floor_of_Linear.test.cpp.html
title: math/test/Sum_of_Floor_of_Linear.test.cpp
---
