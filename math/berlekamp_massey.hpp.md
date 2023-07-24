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
  bundledCode: "#line 2 \"math/berlekamp_massey.hpp\"\n\ntemplate <typename Fp>\n\
    vector<Fp> berlekamp_massey(const vector<Fp> &s) {\n  const int N = (int)s.size();\n\
    \  vector<Fp> b, c;\n  b.reserve(N + 1);\n  c.reserve(N + 1);\n  b.push_back(Fp(1));\n\
    \  c.push_back(Fp(1));\n  Fp y = Fp(1);\n  for (int ed = 1; ed <= N; ed++) {\n\
    \    int l = int(c.size()), m = int(b.size());\n    Fp x = 0;\n    for (int i\
    \ = 0; i < l; i++) x += c[i] * s[ed - l + i];\n    b.emplace_back(Fp(0));\n  \
    \  m++;\n    if (x == Fp(0)) continue;\n    Fp freq = x / y;\n    if (l < m) {\n\
    \      auto tmp = c;\n      c.insert(begin(c), m - l, Fp(0));\n      for (int\
    \ i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];\n      b = tmp;\n  \
    \    y = x;\n    } else {\n      for (int i = 0; i < m; i++) c[l - 1 - i] -= freq\
    \ * b[m - 1 - i];\n    }\n  }\n  reverse(begin(c), end(c));\n  return c;\n}\n"
  code: "#pragma once\n\ntemplate <typename Fp>\nvector<Fp> berlekamp_massey(const\
    \ vector<Fp> &s) {\n  const int N = (int)s.size();\n  vector<Fp> b, c;\n  b.reserve(N\
    \ + 1);\n  c.reserve(N + 1);\n  b.push_back(Fp(1));\n  c.push_back(Fp(1));\n \
    \ Fp y = Fp(1);\n  for (int ed = 1; ed <= N; ed++) {\n    int l = int(c.size()),\
    \ m = int(b.size());\n    Fp x = 0;\n    for (int i = 0; i < l; i++) x += c[i]\
    \ * s[ed - l + i];\n    b.emplace_back(Fp(0));\n    m++;\n    if (x == Fp(0))\
    \ continue;\n    Fp freq = x / y;\n    if (l < m) {\n      auto tmp = c;\n   \
    \   c.insert(begin(c), m - l, Fp(0));\n      for (int i = 0; i < m; i++) c[m -\
    \ 1 - i] -= freq * b[m - 1 - i];\n      b = tmp;\n      y = x;\n    } else {\n\
    \      for (int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];\n    }\n\
    \  }\n  reverse(begin(c), end(c));\n  return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/berlekamp_massey.hpp
  requiredBy: []
  timestamp: '2023-07-25 00:50:50+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/berlekamp_massey.hpp
layout: document
title: Berlekamp-Massey algorithm
---
