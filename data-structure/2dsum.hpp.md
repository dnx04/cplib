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
  bundledCode: "#line 1 \"data-structure/2dsum.hpp\"\n// matrix should be 1-indexed\n\
    auto init = [&](vector<vector<int>> &a, int r, int c) {\n  for (int i = 1; i <=\
    \ r; ++i) {\n    for (int j = 1; j <= c; ++j) {\n      a[i][j] += a[i - 1][j]\
    \ + a[i][j - 1] - a[i - 1][j - 1];\n    }\n  }\n};\nauto sum = [&](const vector<vector<int>>\
    \ &a, int r1, int c1, int r2, int c2) {\n  return a[r2][c2] - a[r1 - 1][c2] -\
    \ a[r2][c1 - 1] + a[r1 - 1][c1 - 1];\n};\n"
  code: "// matrix should be 1-indexed\nauto init = [&](vector<vector<int>> &a, int\
    \ r, int c) {\n  for (int i = 1; i <= r; ++i) {\n    for (int j = 1; j <= c; ++j)\
    \ {\n      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];\n    }\n  }\n\
    };\nauto sum = [&](const vector<vector<int>> &a, int r1, int c1, int r2, int c2)\
    \ {\n  return a[r2][c2] - a[r1 - 1][c2] - a[r2][c1 - 1] + a[r1 - 1][c1 - 1];\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/2dsum.hpp
  requiredBy: []
  timestamp: '2022-06-10 16:31:43+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/2dsum.hpp
layout: document
redirect_from:
- /library/data-structure/2dsum.hpp
- /library/data-structure/2dsum.hpp.html
title: data-structure/2dsum.hpp
---
