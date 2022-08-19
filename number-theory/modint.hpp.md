---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
    title: data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data-structure/test/Queue_Operate_All_Composite.test.cpp
    title: data-structure/test/Queue_Operate_All_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data-structure/test/Range_Affine_Range_Sum.test.cpp
    title: data-structure/test/Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/Matrix_Product.test.cpp
    title: math/test/Matrix_Product.test.cpp
  - icon: ':heavy_check_mark:'
    path: number-theory/test/Power.test.cpp
    title: number-theory/test/Power.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"number-theory/modint.hpp\"\nusing ll = long long;\ntemplate\
    \ <const ll m>\nstruct Mod {\n  ll v;\n\n  Mod() : v(0){};\n  Mod(ll _v) : v((_v\
    \ + m) % m){};\n  explicit operator ll() { return v; }\n  Mod inv() const {\n\
    \    ll a = v, b = m, ax = 1, bx = 0;\n    while (b) {\n      ll q = a / b, t\
    \ = a % b;\n      a = b, b = t, t = ax - bx * q, ax = bx, bx = t;\n    }\n   \
    \ assert(a == 1);\n    ax = (ax < 0 ? ax + m : ax);\n    return ax;\n  }\n  Mod&\
    \ operator+=(const Mod& that) {\n    v = (v + that.v >= m ? v + that.v - m : v\
    \ + that.v);\n    return *this;\n  }\n  Mod& operator-=(const Mod& that) {\n \
    \   v = (v >= that.v ? v - that.v : v + m - that.v);\n    return *this;\n  }\n\
    \  Mod& operator*=(const Mod& that) {\n    v = v * that.v % m;\n    return *this;\n\
    \  }\n  Mod& operator/=(const Mod& that) { return (*this) *= that.inv(); }\n \
    \ Mod operator^(ll y) {\n    if (!y) return Mod(1);\n    Mod r = *this ^ (y >>\
    \ 1);\n    r = r * r;\n    return y & 1 ? *this * r : r;\n  }\n  Mod operator+(const\
    \ Mod& that) const { return Mod(*this) += that; }\n  Mod operator-(const Mod&\
    \ that) const { return Mod(*this) -= that; }\n  Mod operator*(const Mod& that)\
    \ const { return Mod(*this) *= that; }\n  Mod operator/(const Mod& that) const\
    \ { return Mod(*this) /= that; }\n  friend istream& operator>>(istream& in, Mod&\
    \ that) {\n    ll val;\n    in >> val;\n    that = Mod(val);\n    return in;\n\
    \  }\n  friend ostream& operator<<(ostream& out, const Mod& that) {\n    return\
    \ out << that.v;\n  }\n};\n"
  code: "using ll = long long;\ntemplate <const ll m>\nstruct Mod {\n  ll v;\n\n \
    \ Mod() : v(0){};\n  Mod(ll _v) : v((_v + m) % m){};\n  explicit operator ll()\
    \ { return v; }\n  Mod inv() const {\n    ll a = v, b = m, ax = 1, bx = 0;\n \
    \   while (b) {\n      ll q = a / b, t = a % b;\n      a = b, b = t, t = ax -\
    \ bx * q, ax = bx, bx = t;\n    }\n    assert(a == 1);\n    ax = (ax < 0 ? ax\
    \ + m : ax);\n    return ax;\n  }\n  Mod& operator+=(const Mod& that) {\n    v\
    \ = (v + that.v >= m ? v + that.v - m : v + that.v);\n    return *this;\n  }\n\
    \  Mod& operator-=(const Mod& that) {\n    v = (v >= that.v ? v - that.v : v +\
    \ m - that.v);\n    return *this;\n  }\n  Mod& operator*=(const Mod& that) {\n\
    \    v = v * that.v % m;\n    return *this;\n  }\n  Mod& operator/=(const Mod&\
    \ that) { return (*this) *= that.inv(); }\n  Mod operator^(ll y) {\n    if (!y)\
    \ return Mod(1);\n    Mod r = *this ^ (y >> 1);\n    r = r * r;\n    return y\
    \ & 1 ? *this * r : r;\n  }\n  Mod operator+(const Mod& that) const { return Mod(*this)\
    \ += that; }\n  Mod operator-(const Mod& that) const { return Mod(*this) -= that;\
    \ }\n  Mod operator*(const Mod& that) const { return Mod(*this) *= that; }\n \
    \ Mod operator/(const Mod& that) const { return Mod(*this) /= that; }\n  friend\
    \ istream& operator>>(istream& in, Mod& that) {\n    ll val;\n    in >> val;\n\
    \    that = Mod(val);\n    return in;\n  }\n  friend ostream& operator<<(ostream&\
    \ out, const Mod& that) {\n    return out << that.v;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: number-theory/modint.hpp
  requiredBy: []
  timestamp: '2022-06-30 19:56:15+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - data-structure/test/Range_Affine_Range_Sum.test.cpp
  - data-structure/test/Queue_Operate_All_Composite.test.cpp
  - math/test/Matrix_Product.test.cpp
  - number-theory/test/Power.test.cpp
documentation_of: number-theory/modint.hpp
layout: document
redirect_from:
- /library/number-theory/modint.hpp
- /library/number-theory/modint.hpp.html
title: number-theory/modint.hpp
---
