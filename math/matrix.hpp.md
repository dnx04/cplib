---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: math/test/Matrix_Product.test.cpp
    title: math/test/Matrix_Product.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/matrix.hpp\"\ntemplate <typename T>\nstruct matrix\
    \ {\n  int n_row, n_col;\n  vector<T> x;\n\n  // accessors\n  typename vector<T>::iterator\
    \ operator[](int r) {\n    return x.begin() + r * n_col;\n  }\n  inline T get(int\
    \ i, int j) const { return x[i * n_col + j]; }\n\n  // constructors\n  matrix()\
    \ = default;\n  matrix(int n_row, int n_col, T val = 0)\n      : n_row(n_row),\
    \ n_col(n_col), x(n_row * n_col, val) {}\n  matrix(const vector<vector<T>>& d)\n\
    \      : n_row(d.size()), n_col(d.size() ? d[0].size() : 0) {\n    for (auto&\
    \ row : d) copy(row.begin(), row.end(), back_inserter(x));\n  }\n\n  // convert\
    \ to 2d vec\n  vector<vector<T>> vecvec() const {\n    vector<vector<T>> ret(n_row);\n\
    \    for (int i = 0; i < n_row; i++) {\n      copy(x.begin() + i * n_col, x.begin()\
    \ + (i + 1) * n_col,\n           back_inserter(ret[i]));\n    }\n    return ret;\n\
    \  }\n  operator vector<vector<T>>() const { return vecvec(); }\n\n  static matrix\
    \ identity(int n) {\n    matrix res(n, n);\n    for (int i = 0; i < n; i++) {\n\
    \      res[i][i] = 1;\n    }\n    return res;\n  }\n\n  matrix transpose() const\
    \ {\n    matrix res(n_col, n_row);\n    for (int i = 0; i < n_row; i++) {\n  \
    \    for (int j = 0; j < n_col; j++) {\n        res[j][i] = this->get(i, j);\n\
    \      }\n    }\n    return res;\n  }\n\n  matrix& operator*=(const matrix& r)\
    \ { return *this = *this * r; }\n  matrix operator*(const matrix& r) const {\n\
    \    assert(n_col == r.n_row);\n    matrix res(n_row, r.n_col);\n\n    for (int\
    \ i = 0; i < n_row; i++) {\n      for (int k = 0; k < n_col; k++) {\n        for\
    \ (int j = 0; j < r.n_col; j++) {\n          res[i][j] += this->get(i, k) * r.get(k,\
    \ j);\n        }\n      }\n    }\n    return res;\n  }\n\n  matrix operator^(long\
    \ long n) const {\n    assert(n_row == n_col);\n    if (n == 0) return identity(n_row);\n\
    \    if (n == 1) return *this;\n    matrix res = *this ^ (n >> 1);\n    res =\
    \ res * res;\n    if (n & 1) res = res * *this;\n    return res;\n  }\n};\n"
  code: "template <typename T>\nstruct matrix {\n  int n_row, n_col;\n  vector<T>\
    \ x;\n\n  // accessors\n  typename vector<T>::iterator operator[](int r) {\n \
    \   return x.begin() + r * n_col;\n  }\n  inline T get(int i, int j) const { return\
    \ x[i * n_col + j]; }\n\n  // constructors\n  matrix() = default;\n  matrix(int\
    \ n_row, int n_col, T val = 0)\n      : n_row(n_row), n_col(n_col), x(n_row *\
    \ n_col, val) {}\n  matrix(const vector<vector<T>>& d)\n      : n_row(d.size()),\
    \ n_col(d.size() ? d[0].size() : 0) {\n    for (auto& row : d) copy(row.begin(),\
    \ row.end(), back_inserter(x));\n  }\n\n  // convert to 2d vec\n  vector<vector<T>>\
    \ vecvec() const {\n    vector<vector<T>> ret(n_row);\n    for (int i = 0; i <\
    \ n_row; i++) {\n      copy(x.begin() + i * n_col, x.begin() + (i + 1) * n_col,\n\
    \           back_inserter(ret[i]));\n    }\n    return ret;\n  }\n  operator vector<vector<T>>()\
    \ const { return vecvec(); }\n\n  static matrix identity(int n) {\n    matrix\
    \ res(n, n);\n    for (int i = 0; i < n; i++) {\n      res[i][i] = 1;\n    }\n\
    \    return res;\n  }\n\n  matrix transpose() const {\n    matrix res(n_col, n_row);\n\
    \    for (int i = 0; i < n_row; i++) {\n      for (int j = 0; j < n_col; j++)\
    \ {\n        res[j][i] = this->get(i, j);\n      }\n    }\n    return res;\n \
    \ }\n\n  matrix& operator*=(const matrix& r) { return *this = *this * r; }\n \
    \ matrix operator*(const matrix& r) const {\n    assert(n_col == r.n_row);\n \
    \   matrix res(n_row, r.n_col);\n\n    for (int i = 0; i < n_row; i++) {\n   \
    \   for (int k = 0; k < n_col; k++) {\n        for (int j = 0; j < r.n_col; j++)\
    \ {\n          res[i][j] += this->get(i, k) * r.get(k, j);\n        }\n      }\n\
    \    }\n    return res;\n  }\n\n  matrix operator^(long long n) const {\n    assert(n_row\
    \ == n_col);\n    if (n == 0) return identity(n_row);\n    if (n == 1) return\
    \ *this;\n    matrix res = *this ^ (n >> 1);\n    res = res * res;\n    if (n\
    \ & 1) res = res * *this;\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2022-09-27 23:05:16+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - math/test/Matrix_Product.test.cpp
documentation_of: math/matrix.hpp
layout: document
title: Operators on Matrix
---
