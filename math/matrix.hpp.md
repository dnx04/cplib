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
  bundledCode: "#line 2 \"math/matrix.hpp\"\n\ntemplate <typename T, int H, int W>\n\
    struct matrix {\n  using Array = array<array<T, W>, H>;\n  Array A;\n\n  matrix()\
    \ : A() {\n    for (int i = 0; i < H; i++)\n      for (int j = 0; j < W; j++)\
    \ (*this)[i][j] = T();\n  }\n\n  int height() const { return H; }\n\n  int width()\
    \ const { return W; }\n\n  inline const array<T, W> &operator[](int k) const {\
    \ return A[k]; }\n\n  inline array<T, W> &operator[](int k) { return A[k]; }\n\
    \n  static matrix I() {\n    assert(H == W);\n    matrix mat;\n    for (int i\
    \ = 0; i < H; i++) mat[i][i] = 1;\n    return (mat);\n  }\n\n  matrix &operator+=(const\
    \ matrix &B) {\n    for (int i = 0; i < H; i++)\n      for (int j = 0; j < W;\
    \ j++) A[i][j] += B[i][j];\n    return (*this);\n  }\n\n  matrix &operator-=(const\
    \ matrix &B) {\n    for (int i = 0; i < H; i++)\n      for (int j = 0; j < W;\
    \ j++) A[i][j] -= B[i][j];\n    return (*this);\n  }\n\n  matrix &operator*=(const\
    \ matrix &B) {\n    assert(H == W);\n    matrix C;\n    for (int i = 0; i < H;\
    \ i++)\n      for (int k = 0; k < H; k++)\n        for (int j = 0; j < H; j++)\
    \ C[i][j] += A[i][k] * B[k][j];\n    A.swap(C.A);\n    return (*this);\n  }\n\n\
    \  matrix &operator^=(long long k) {\n    matrix B = matrix::I();\n    while (k\
    \ > 0) {\n      if (k & 1) B *= *this;\n      *this *= *this;\n      k >>= 1LL;\n\
    \    }\n    A.swap(B.A);\n    return (*this);\n  }\n\n  matrix operator+(const\
    \ matrix &B) const { return (matrix(*this) += B); }\n\n  matrix operator-(const\
    \ matrix &B) const { return (matrix(*this) -= B); }\n\n  matrix operator*(const\
    \ matrix &B) const { return (matrix(*this) *= B); }\n\n  matrix operator^(const\
    \ long long k) const { return (matrix(*this) ^= k); }\n\n  bool operator==(const\
    \ matrix &B) const {\n    for (int i = 0; i < H; i++)\n      for (int j = 0; j\
    \ < W; j++)\n        if (A[i][j] != B[i][j]) return false;\n    return true;\n\
    \  }\n\n  bool operator!=(const matrix &B) const {\n    for (int i = 0; i < H;\
    \ i++)\n      for (int j = 0; j < W; j++)\n        if (A[i][j] != B[i][j]) return\
    \ true;\n    return false;\n  }\n\n  friend ostream &operator<<(ostream &os, const\
    \ matrix &p) {\n    for (int i = 0; i < H; i++) {\n      os << \"[\";\n      for\
    \ (int j = 0; j < W; j++) {\n        os << p[i][j] << (j + 1 == W ? \"]\\n\" :\
    \ \",\");\n      }\n    }\n    return (os);\n  }\n\n  T determinant(int n = -1)\
    \ {\n    if (n == -1) n = H;\n    matrix B(*this);\n    T ret = 1;\n    for (int\
    \ i = 0; i < n; i++) {\n      int idx = -1;\n      for (int j = i; j < n; j++)\
    \ {\n        if (B[j][i] != 0) {\n          idx = j;\n          break;\n     \
    \   }\n      }\n      if (idx == -1) return 0;\n      if (i != idx) {\n      \
    \  ret *= T(-1);\n        swap(B[i], B[idx]);\n      }\n      ret *= B[i][i];\n\
    \      T inv = T(1) / B[i][i];\n      for (int j = 0; j < n; j++) {\n        B[i][j]\
    \ *= inv;\n      }\n      for (int j = i + 1; j < n; j++) {\n        T a = B[j][i];\n\
    \        if (a == 0) continue;\n        for (int k = i; k < n; k++) {\n      \
    \    B[j][k] -= B[i][k] * a;\n        }\n      }\n    }\n    return (ret);\n \
    \ }\n};\n"
  code: "#pragma once\n\ntemplate <typename T, int H, int W>\nstruct matrix {\n  using\
    \ Array = array<array<T, W>, H>;\n  Array A;\n\n  matrix() : A() {\n    for (int\
    \ i = 0; i < H; i++)\n      for (int j = 0; j < W; j++) (*this)[i][j] = T();\n\
    \  }\n\n  int height() const { return H; }\n\n  int width() const { return W;\
    \ }\n\n  inline const array<T, W> &operator[](int k) const { return A[k]; }\n\n\
    \  inline array<T, W> &operator[](int k) { return A[k]; }\n\n  static matrix I()\
    \ {\n    assert(H == W);\n    matrix mat;\n    for (int i = 0; i < H; i++) mat[i][i]\
    \ = 1;\n    return (mat);\n  }\n\n  matrix &operator+=(const matrix &B) {\n  \
    \  for (int i = 0; i < H; i++)\n      for (int j = 0; j < W; j++) A[i][j] += B[i][j];\n\
    \    return (*this);\n  }\n\n  matrix &operator-=(const matrix &B) {\n    for\
    \ (int i = 0; i < H; i++)\n      for (int j = 0; j < W; j++) A[i][j] -= B[i][j];\n\
    \    return (*this);\n  }\n\n  matrix &operator*=(const matrix &B) {\n    assert(H\
    \ == W);\n    matrix C;\n    for (int i = 0; i < H; i++)\n      for (int k = 0;\
    \ k < H; k++)\n        for (int j = 0; j < H; j++) C[i][j] += A[i][k] * B[k][j];\n\
    \    A.swap(C.A);\n    return (*this);\n  }\n\n  matrix &operator^=(long long\
    \ k) {\n    matrix B = matrix::I();\n    while (k > 0) {\n      if (k & 1) B *=\
    \ *this;\n      *this *= *this;\n      k >>= 1LL;\n    }\n    A.swap(B.A);\n \
    \   return (*this);\n  }\n\n  matrix operator+(const matrix &B) const { return\
    \ (matrix(*this) += B); }\n\n  matrix operator-(const matrix &B) const { return\
    \ (matrix(*this) -= B); }\n\n  matrix operator*(const matrix &B) const { return\
    \ (matrix(*this) *= B); }\n\n  matrix operator^(const long long k) const { return\
    \ (matrix(*this) ^= k); }\n\n  bool operator==(const matrix &B) const {\n    for\
    \ (int i = 0; i < H; i++)\n      for (int j = 0; j < W; j++)\n        if (A[i][j]\
    \ != B[i][j]) return false;\n    return true;\n  }\n\n  bool operator!=(const\
    \ matrix &B) const {\n    for (int i = 0; i < H; i++)\n      for (int j = 0; j\
    \ < W; j++)\n        if (A[i][j] != B[i][j]) return true;\n    return false;\n\
    \  }\n\n  friend ostream &operator<<(ostream &os, const matrix &p) {\n    for\
    \ (int i = 0; i < H; i++) {\n      os << \"[\";\n      for (int j = 0; j < W;\
    \ j++) {\n        os << p[i][j] << (j + 1 == W ? \"]\\n\" : \",\");\n      }\n\
    \    }\n    return (os);\n  }\n\n  T determinant(int n = -1) {\n    if (n == -1)\
    \ n = H;\n    matrix B(*this);\n    T ret = 1;\n    for (int i = 0; i < n; i++)\
    \ {\n      int idx = -1;\n      for (int j = i; j < n; j++) {\n        if (B[j][i]\
    \ != 0) {\n          idx = j;\n          break;\n        }\n      }\n      if\
    \ (idx == -1) return 0;\n      if (i != idx) {\n        ret *= T(-1);\n      \
    \  swap(B[i], B[idx]);\n      }\n      ret *= B[i][i];\n      T inv = T(1) / B[i][i];\n\
    \      for (int j = 0; j < n; j++) {\n        B[i][j] *= inv;\n      }\n     \
    \ for (int j = i + 1; j < n; j++) {\n        T a = B[j][i];\n        if (a ==\
    \ 0) continue;\n        for (int k = i; k < n; k++) {\n          B[j][k] -= B[i][k]\
    \ * a;\n        }\n      }\n    }\n    return (ret);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2022-09-27 20:44:18+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: math/matrix.hpp
---
