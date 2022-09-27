---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  - icon: ':heavy_check_mark:'
    path: utility/static_modulo.hpp
    title: Static Modular Arithmetic
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"math/test/Matrix_Product.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/matrix_product\"\n\n#include <bits/extc++.h>\n\
    \nusing namespace std;\n\n#line 1 \"math/matrix.hpp\"\ntemplate <typename T>\n\
    struct matrix {\n  int n_row, n_col;\n  vector<T> x;\n\n  // accessors\n  typename\
    \ vector<T>::iterator operator[](int r) {\n    return x.begin() + r * n_col;\n\
    \  }\n  inline T get(int i, int j) const { return x[i * n_col + j]; }\n\n  //\
    \ constructors\n  matrix() = default;\n  matrix(int n_row, int n_col, T val =\
    \ 0)\n      : n_row(n_row), n_col(n_col), x(n_row * n_col, val) {}\n  matrix(const\
    \ vector<vector<T>>& d)\n      : n_row(d.size()), n_col(d.size() ? d[0].size()\
    \ : 0) {\n    for (auto& row : d) copy(row.begin(), row.end(), back_inserter(x));\n\
    \  }\n\n  // convert to 2d vec\n  vector<vector<T>> vecvec() const {\n    vector<vector<T>>\
    \ ret(n_row);\n    for (int i = 0; i < n_row; i++) {\n      copy(x.begin() + i\
    \ * n_col, x.begin() + (i + 1) * n_col,\n           back_inserter(ret[i]));\n\
    \    }\n    return ret;\n  }\n  operator vector<vector<T>>() const { return vecvec();\
    \ }\n\n  static matrix identity(int n) {\n    matrix res(n, n);\n    for (int\
    \ i = 0; i < n; i++) {\n      res[i][i] = 1;\n    }\n    return res;\n  }\n\n\
    \  matrix transpose() const {\n    matrix res(n_col, n_row);\n    for (int i =\
    \ 0; i < n_row; i++) {\n      for (int j = 0; j < n_col; j++) {\n        res[j][i]\
    \ = this->get(i, j);\n      }\n    }\n    return res;\n  }\n\n  matrix& operator*=(const\
    \ matrix& r) { return *this = *this * r; }\n  matrix operator*(const matrix& r)\
    \ const {\n    assert(n_col == r.n_row);\n    matrix res(n_row, r.n_col);\n\n\
    \    for (int i = 0; i < n_row; i++) {\n      for (int k = 0; k < n_col; k++)\
    \ {\n        for (int j = 0; j < r.n_col; j++) {\n          res[i][j] += this->get(i,\
    \ k) * r.get(k, j);\n        }\n      }\n    }\n    return res;\n  }\n\n  matrix\
    \ operator^(long long n) const {\n    assert(n_row == n_col);\n    if (n == 0)\
    \ return identity(n_row);\n    if (n == 1) return *this;\n    matrix res = *this\
    \ ^ (n >> 1);\n    res = res * res;\n    if (n & 1) res = res * *this;\n    return\
    \ res;\n  }\n};\n#line 2 \"utility/static_modulo.hpp\"\n\ntemplate <int mod>\n\
    struct static_modulo {\n  using Fp = static_modulo;\n\n private:\n  int x;\n\n\
    \ public:\n  static_modulo() : x(0) {}\n  static_modulo(int64_t y) : x(y >= 0\
    \ ? y % mod : (mod - (-y) % mod) % mod) {}\n  Fp &operator+=(const Fp &p) {\n\
    \    if ((x += p.x) >= mod) x -= mod;\n    return *this;\n  }\n  Fp &operator-=(const\
    \ Fp &p) {\n    if ((x += mod - p.x) >= mod) x -= mod;\n    return *this;\n  }\n\
    \  Fp &operator*=(const Fp &p) {\n    x = (int)(1ll * x * p.x % mod);\n    return\
    \ *this;\n  }\n  Fp &operator/=(const Fp &p) {\n    *this *= p.inv();\n    return\
    \ *this;\n  }\n  Fp operator-() const { return Fp(-x); }\n  Fp operator+(const\
    \ Fp &p) const { return Fp(*this) += p; }\n  Fp operator-(const Fp &p) const {\
    \ return Fp(*this) -= p; }\n  Fp operator*(const Fp &p) const { return Fp(*this)\
    \ *= p; }\n  Fp operator/(const Fp &p) const { return Fp(*this) /= p; }\n  bool\
    \ operator==(const Fp &p) const { return x == p.x; }\n  bool operator!=(const\
    \ Fp &p) const { return x != p.x; }\n  Fp inv() const {\n    int a = x, b = mod,\
    \ u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b);\n      swap(u -= t * v, v);\n    }\n    return Fp(u);\n  }\n  Fp pow(int64_t\
    \ n) const {\n    Fp ret(1), mul(x);\n    while (n > 0) {\n      if (n & 1) ret\
    \ *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n  friend\
    \ ostream &operator<<(ostream &os, const Fp &p) { return os << p.x; }\n  friend\
    \ istream &operator>>(istream &is, Fp &a) {\n    int64_t t;\n    is >> t;\n  \
    \  a = static_modulo<mod>(t);\n    return (is);\n  }\n  int get() const { return\
    \ x; }\n  static constexpr int get_mod() { return mod; }\n};\n#line 9 \"math/test/Matrix_Product.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  using Fp = static_modulo<998244353>;\n  int n, m, k;\n  cin >> n >> m >> k;\n\
    \  matrix<Fp> a(n, m), b(m, k);\n  for (int i = 0; i < n; ++i) {\n    for (int\
    \ j = 0; j < m; ++j) {\n      cin >> a[i][j];\n    }\n  }\n  for (int i = 0; i\
    \ < m; ++i) {\n    for (int j = 0; j < k; ++j) {\n      cin >> b[i][j];\n    }\n\
    \  }\n  matrix<Fp> c = a * b;\n  for (int i = 0; i < n; ++i) {\n    for (int j\
    \ = 0; j < k; ++j) {\n      cout << c[i][j] << \" \\n\"[j == k - 1];\n    }\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n\n#include\
    \ <bits/extc++.h>\n\nusing namespace std;\n\n#include \"math/matrix.hpp\"\n#include\
    \ \"utility/static_modulo.hpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  using Fp = static_modulo<998244353>;\n\
    \  int n, m, k;\n  cin >> n >> m >> k;\n  matrix<Fp> a(n, m), b(m, k);\n  for\
    \ (int i = 0; i < n; ++i) {\n    for (int j = 0; j < m; ++j) {\n      cin >> a[i][j];\n\
    \    }\n  }\n  for (int i = 0; i < m; ++i) {\n    for (int j = 0; j < k; ++j)\
    \ {\n      cin >> b[i][j];\n    }\n  }\n  matrix<Fp> c = a * b;\n  for (int i\
    \ = 0; i < n; ++i) {\n    for (int j = 0; j < k; ++j) {\n      cout << c[i][j]\
    \ << \" \\n\"[j == k - 1];\n    }\n  }\n}"
  dependsOn:
  - math/matrix.hpp
  - utility/static_modulo.hpp
  isVerificationFile: true
  path: math/test/Matrix_Product.test.cpp
  requiredBy: []
  timestamp: '2022-09-27 23:05:16+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: math/test/Matrix_Product.test.cpp
layout: document
redirect_from:
- /verify/math/test/Matrix_Product.test.cpp
- /verify/math/test/Matrix_Product.test.cpp.html
title: math/test/Matrix_Product.test.cpp
---
