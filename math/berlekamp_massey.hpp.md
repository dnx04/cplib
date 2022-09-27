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
  bundledCode: "#line 2 \"math/berlekamp_massey.hpp\"\n\ntemplate <typename mint>\n\
    vector<mint> BerlekampMassey(const vector<mint> &s) {\n  const int N = (int)s.size();\n\
    \  vector<mint> b, c;\n  b.reserve(N + 1);\n  c.reserve(N + 1);\n  b.push_back(mint(1));\n\
    \  c.push_back(mint(1));\n  mint y = mint(1);\n  for (int ed = 1; ed <= N; ed++)\
    \ {\n    int l = int(c.size()), m = int(b.size());\n    mint x = 0;\n    for (int\
    \ i = 0; i < l; i++) x += c[i] * s[ed - l + i];\n    b.emplace_back(mint(0));\n\
    \    m++;\n    if (x == mint(0)) continue;\n    mint freq = x / y;\n    if (l\
    \ < m) {\n      auto tmp = c;\n      c.insert(begin(c), m - l, mint(0));\n   \
    \   for (int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];\n      b\
    \ = tmp;\n      y = x;\n    } else {\n      for (int i = 0; i < m; i++) c[l -\
    \ 1 - i] -= freq * b[m - 1 - i];\n    }\n  }\n  reverse(begin(c), end(c));\n \
    \ return c;\n}\n"
  code: "#pragma once\n\ntemplate <typename mint>\nvector<mint> BerlekampMassey(const\
    \ vector<mint> &s) {\n  const int N = (int)s.size();\n  vector<mint> b, c;\n \
    \ b.reserve(N + 1);\n  c.reserve(N + 1);\n  b.push_back(mint(1));\n  c.push_back(mint(1));\n\
    \  mint y = mint(1);\n  for (int ed = 1; ed <= N; ed++) {\n    int l = int(c.size()),\
    \ m = int(b.size());\n    mint x = 0;\n    for (int i = 0; i < l; i++) x += c[i]\
    \ * s[ed - l + i];\n    b.emplace_back(mint(0));\n    m++;\n    if (x == mint(0))\
    \ continue;\n    mint freq = x / y;\n    if (l < m) {\n      auto tmp = c;\n \
    \     c.insert(begin(c), m - l, mint(0));\n      for (int i = 0; i < m; i++) c[m\
    \ - 1 - i] -= freq * b[m - 1 - i];\n      b = tmp;\n      y = x;\n    } else {\n\
    \      for (int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];\n    }\n\
    \  }\n  reverse(begin(c), end(c));\n  return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/berlekamp_massey.hpp
  requiredBy: []
  timestamp: '2022-09-27 20:44:18+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/berlekamp_massey.hpp
layout: document
redirect_from:
- /library/math/berlekamp_massey.hpp
- /library/math/berlekamp_massey.hpp.html
title: math/berlekamp_massey.hpp
---
