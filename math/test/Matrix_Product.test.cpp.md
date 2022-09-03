---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  - icon: ':question:'
    path: number-theory/modint.hpp
    title: number-theory/modint.hpp
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
    \nusing namespace std;\n\n#line 1 \"number-theory/modint.hpp\"\nusing ll = long\
    \ long;\n\ntemplate <const ll m>\nstruct Mod {\n  ll v;\n\n  Mod() : v(0){};\n\
    \  Mod(ll _v) : v((_v + m) % m){};\n  explicit operator ll() { return v; }\n \
    \ Mod inv() const {\n    ll a = v, b = m, ax = 1, bx = 0;\n    while (b) {\n \
    \     ll q = a / b, t = a % b;\n      a = b, b = t, t = ax - bx * q, ax = bx,\
    \ bx = t;\n    }\n    assert(a == 1);\n    ax = (ax < 0 ? ax + m : ax);\n    return\
    \ ax;\n  }\n  Mod& operator+=(const Mod& that) {\n    v = (v + that.v >= m ? v\
    \ + that.v - m : v + that.v);\n    return *this;\n  }\n  Mod& operator-=(const\
    \ Mod& that) {\n    v = (v >= that.v ? v - that.v : v + m - that.v);\n    return\
    \ *this;\n  }\n  Mod& operator*=(const Mod& that) {\n    v = v * that.v % m;\n\
    \    return *this;\n  }\n  Mod& operator/=(const Mod& that) { return (*this) *=\
    \ that.inv(); }\n  Mod operator^(ll y) {\n    if (!y) return Mod(1);\n    Mod\
    \ r = *this ^ (y >> 1);\n    r = r * r;\n    return y & 1 ? *this * r : r;\n \
    \ }\n  Mod operator+(const Mod& that) const { return Mod(*this) += that; }\n \
    \ Mod operator-(const Mod& that) const { return Mod(*this) -= that; }\n  Mod operator*(const\
    \ Mod& that) const { return Mod(*this) *= that; }\n  Mod operator/(const Mod&\
    \ that) const { return Mod(*this) /= that; }\n  bool operator==(const Mod& that)\
    \ const { return this->v == that.v; }\n  friend istream& operator>>(istream& in,\
    \ Mod& that) {\n    ll val;\n    in >> val;\n    that = Mod(val);\n    return\
    \ in;\n  }\n  friend ostream& operator<<(ostream& out, const Mod& that) {\n  \
    \  return out << that.v;\n  }\n};\n#line 1 \"math/matrix.hpp\"\ntemplate <typename\
    \ T>\nstruct matrix {\n  int n_row, n_col;\n  vector<T> x;\n\n  // accessors\n\
    \  typename vector<T>::iterator operator[](int r) {\n    return x.begin() + r\
    \ * n_col;\n  }\n  inline T get(int i, int j) const { return x[i * n_col + j];\
    \ }\n\n  // constructors\n  matrix() = default;\n  matrix(int n_row, int n_col,\
    \ T val = 0)\n      : n_row(n_row), n_col(n_col), x(n_row * n_col, val) {}\n \
    \ matrix(const vector<vector<T>>& d)\n      : n_row(d.size()), n_col(d.size()\
    \ ? d[0].size() : 0) {\n    for (auto& row : d) copy(row.begin(), row.end(), back_inserter(x));\n\
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
    \ res;\n  }\n};\n#line 9 \"math/test/Matrix_Product.test.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  using mint = Mod<998244353>;\n  int n, m, k;\n  cin >> n >> m >> k;\n  matrix<mint>\
    \ a(n, m), b(m, k);\n  for (int i = 0; i < n; ++i) {\n    for (int j = 0; j <\
    \ m; ++j) {\n      cin >> a[i][j];\n    }\n  }\n  for (int i = 0; i < m; ++i)\
    \ {\n    for (int j = 0; j < k; ++j) {\n      cin >> b[i][j];\n    }\n  }\n  matrix<mint>\
    \ c = a * b;\n  for (int i = 0; i < n; ++i) {\n    for (int j = 0; j < k; ++j)\
    \ {\n      cout << c[i][j] << \" \\n\"[j == k - 1];\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n\n#include\
    \ <bits/extc++.h>\n\nusing namespace std;\n\n#include \"../algo/number-theory/modint.hpp\"\
    \n#include \"../matrix.hpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  using mint = Mod<998244353>;\n\
    \  int n, m, k;\n  cin >> n >> m >> k;\n  matrix<mint> a(n, m), b(m, k);\n  for\
    \ (int i = 0; i < n; ++i) {\n    for (int j = 0; j < m; ++j) {\n      cin >> a[i][j];\n\
    \    }\n  }\n  for (int i = 0; i < m; ++i) {\n    for (int j = 0; j < k; ++j)\
    \ {\n      cin >> b[i][j];\n    }\n  }\n  matrix<mint> c = a * b;\n  for (int\
    \ i = 0; i < n; ++i) {\n    for (int j = 0; j < k; ++j) {\n      cout << c[i][j]\
    \ << \" \\n\"[j == k - 1];\n    }\n  }\n}"
  dependsOn:
  - number-theory/modint.hpp
  - math/matrix.hpp
  isVerificationFile: true
  path: math/test/Matrix_Product.test.cpp
  requiredBy: []
  timestamp: '2022-08-28 22:13:17+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: math/test/Matrix_Product.test.cpp
layout: document
redirect_from:
- /verify/math/test/Matrix_Product.test.cpp
- /verify/math/test/Matrix_Product.test.cpp.html
title: math/test/Matrix_Product.test.cpp
---
