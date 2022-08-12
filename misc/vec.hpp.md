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
  bundledCode: "#line 1 \"misc/vec.hpp\"\ntemplate <int D, typename T>\nstruct Vec\
    \ : public vector<Vec<D - 1, T>> {\n  static_assert(D >= 1, \"Dimension must be\
    \ positive\");\n  template <typename... Args>\n  Vec(int n = 0, Args... args)\n\
    \      : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}\n};\n\ntemplate <typename\
    \ T>\nstruct Vec<1, T> : public vector<T> {\n  Vec(int n = 0, T val = T()) : vector<T>(n,\
    \ val) {}\n};\n"
  code: "template <int D, typename T>\nstruct Vec : public vector<Vec<D - 1, T>> {\n\
    \  static_assert(D >= 1, \"Dimension must be positive\");\n  template <typename...\
    \ Args>\n  Vec(int n = 0, Args... args)\n      : vector<Vec<D - 1, T>>(n, Vec<D\
    \ - 1, T>(args...)) {}\n};\n\ntemplate <typename T>\nstruct Vec<1, T> : public\
    \ vector<T> {\n  Vec(int n = 0, T val = T()) : vector<T>(n, val) {}\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/vec.hpp
  requiredBy: []
  timestamp: '2022-08-12 20:20:35+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/vec.hpp
layout: document
redirect_from:
- /library/misc/vec.hpp
- /library/misc/vec.hpp.html
title: misc/vec.hpp
---
