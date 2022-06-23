---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: number-theory/test/Power.test.cpp
    title: number-theory/test/Power.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"number-theory/modint.hpp\"\n// works for mod < 2^63\n\n\
    using ull = unsigned long long;\ntemplate <ull m>\nstruct Mod {\n  ull v;\n\n\
    \  Mod() : v(0){};\n  Mod(__uint128_t _v) : v(_v % m){};\n  explicit operator\
    \ ull() { return v; }\n  Mod inv() const {\n    int64_t a = v, b = m, ax = 1,\
    \ bx = 0;\n    while (b) {\n      ull q = a / b, t = a % b;\n      a = b, b =\
    \ t, t = ax - bx * q, ax = bx, bx = t;\n    }\n    assert(a == 1);\n    ax = (ax\
    \ < 0 ? ax + m : ax);\n    return ax;\n  }\n  Mod& operator+=(const Mod& that)\
    \ {\n    v = (v + that.v >= m ? v + that.v - m : v + that.v);\n    return *this;\n\
    \  }\n  Mod& operator-=(const Mod& that) {\n    v = (v >= that.v ? v - that.v\
    \ : v + m - that.v);\n    return *this;\n  }\n  Mod& operator*=(const Mod& that)\
    \ {\n    v = __uint128_t(v) * that.v % m;\n    return *this;\n  }\n  Mod& operator/=(const\
    \ Mod& that) { return (*this) *= that.inv(); }\n  Mod operator^(ull y) {\n   \
    \ if (!y) return Mod(1);\n    Mod r = *this ^ (y >> 1);\n    r = r * r;\n    return\
    \ y & 1 ? *this * r : r;\n  }\n  Mod operator+(const Mod& that) const { return\
    \ Mod(*this) += that; }\n  Mod operator-(const Mod& that) const { return Mod(*this)\
    \ -= that; }\n  Mod operator*(const Mod& that) const { return Mod(*this) *= that;\
    \ }\n  Mod operator/(const Mod& that) const { return Mod(*this) /= that; }\n \
    \ friend istream& operator>>(istream& in, Mod& that) {\n    ull val;\n    in >>\
    \ val;\n    that = Mod(val);\n    return in;\n  }\n  friend ostream& operator<<(ostream&\
    \ out, const Mod& that) {\n    return out << that.v;\n  }\n};\n"
  code: "// works for mod < 2^63\n\nusing ull = unsigned long long;\ntemplate <ull\
    \ m>\nstruct Mod {\n  ull v;\n\n  Mod() : v(0){};\n  Mod(__uint128_t _v) : v(_v\
    \ % m){};\n  explicit operator ull() { return v; }\n  Mod inv() const {\n    int64_t\
    \ a = v, b = m, ax = 1, bx = 0;\n    while (b) {\n      ull q = a / b, t = a %\
    \ b;\n      a = b, b = t, t = ax - bx * q, ax = bx, bx = t;\n    }\n    assert(a\
    \ == 1);\n    ax = (ax < 0 ? ax + m : ax);\n    return ax;\n  }\n  Mod& operator+=(const\
    \ Mod& that) {\n    v = (v + that.v >= m ? v + that.v - m : v + that.v);\n   \
    \ return *this;\n  }\n  Mod& operator-=(const Mod& that) {\n    v = (v >= that.v\
    \ ? v - that.v : v + m - that.v);\n    return *this;\n  }\n  Mod& operator*=(const\
    \ Mod& that) {\n    v = __uint128_t(v) * that.v % m;\n    return *this;\n  }\n\
    \  Mod& operator/=(const Mod& that) { return (*this) *= that.inv(); }\n  Mod operator^(ull\
    \ y) {\n    if (!y) return Mod(1);\n    Mod r = *this ^ (y >> 1);\n    r = r *\
    \ r;\n    return y & 1 ? *this * r : r;\n  }\n  Mod operator+(const Mod& that)\
    \ const { return Mod(*this) += that; }\n  Mod operator-(const Mod& that) const\
    \ { return Mod(*this) -= that; }\n  Mod operator*(const Mod& that) const { return\
    \ Mod(*this) *= that; }\n  Mod operator/(const Mod& that) const { return Mod(*this)\
    \ /= that; }\n  friend istream& operator>>(istream& in, Mod& that) {\n    ull\
    \ val;\n    in >> val;\n    that = Mod(val);\n    return in;\n  }\n  friend ostream&\
    \ operator<<(ostream& out, const Mod& that) {\n    return out << that.v;\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: number-theory/modint.hpp
  requiredBy: []
  timestamp: '2022-06-23 16:05:16+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - number-theory/test/Power.test.cpp
documentation_of: number-theory/modint.hpp
layout: document
redirect_from:
- /library/number-theory/modint.hpp
- /library/number-theory/modint.hpp.html
title: number-theory/modint.hpp
---
