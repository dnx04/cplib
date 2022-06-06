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
  bundledCode: "#line 1 \"number-theory/modint.hpp\"\ntypedef unsigned long long ull;\n\
    \ntemplate <ull mod>\nstruct Mod {\n private:\n  ull v;\n  static ull inv(ull\
    \ a, ull m) {\n    a %= m;\n    assert(a);\n    return a == 1 ? 1 : ull(m - __uint128_t(inv(m,\
    \ a)) * m / a);\n  }\n\n public:\n  Mod() : v(0){};\n  Mod(ull _v) : v((_v % mod\
    \ + mod) % mod){};\n  Mod inv() const {\n    Mod res;\n    res.v = inv(v, mod);\n\
    \    return res;\n  }\n  friend Mod inv(const Mod& a) { return a.inv(); }\n  Mod&\
    \ operator+=(const Mod& a) {\n    v += a.v;\n    if (v >= mod) v -= mod;\n   \
    \ return *this;\n  }\n  Mod& operator-=(const Mod& a) {\n    v += mod - a.v;\n\
    \    if (v >= mod) v -= mod;\n    return *this;\n  }\n  Mod& operator*=(const\
    \ Mod& a) {\n    v = __uint128_t(v) * a.v % mod;\n    return *this;\n  }\n  Mod&\
    \ operator/=(const Mod& a) { return *this *= a.inv(); }\n  friend Mod operator+(const\
    \ Mod& a, const Mod& b) { return Mod(a) += b; }\n  friend Mod operator-(const\
    \ Mod& a, const Mod& b) { return Mod(a) -= b; }\n  friend Mod operator*(const\
    \ Mod& a, const Mod& b) { return Mod(a) *= b; }\n  friend Mod operator/(const\
    \ Mod& a, const Mod& b) { return Mod(a) /= b; }\n  Mod operator^(ull y) {\n  \
    \  if (!y) return Mod(1);\n    Mod r = *this ^ (y >> 1);\n    r = r * r;\n   \
    \ return y & 1 ? *this * r : r;\n  }\n  friend ostream& operator<<(std::ostream&\
    \ out, const Mod& a) {\n    return out << a.v;\n  }\n  friend istream& operator>>(std::istream&\
    \ in, Mod& a) {\n    ull v;\n    in >> v;\n    a = Mod(v);\n    return in;\n \
    \ }\n};\n"
  code: "typedef unsigned long long ull;\n\ntemplate <ull mod>\nstruct Mod {\n private:\n\
    \  ull v;\n  static ull inv(ull a, ull m) {\n    a %= m;\n    assert(a);\n   \
    \ return a == 1 ? 1 : ull(m - __uint128_t(inv(m, a)) * m / a);\n  }\n\n public:\n\
    \  Mod() : v(0){};\n  Mod(ull _v) : v((_v % mod + mod) % mod){};\n  Mod inv()\
    \ const {\n    Mod res;\n    res.v = inv(v, mod);\n    return res;\n  }\n  friend\
    \ Mod inv(const Mod& a) { return a.inv(); }\n  Mod& operator+=(const Mod& a) {\n\
    \    v += a.v;\n    if (v >= mod) v -= mod;\n    return *this;\n  }\n  Mod& operator-=(const\
    \ Mod& a) {\n    v += mod - a.v;\n    if (v >= mod) v -= mod;\n    return *this;\n\
    \  }\n  Mod& operator*=(const Mod& a) {\n    v = __uint128_t(v) * a.v % mod;\n\
    \    return *this;\n  }\n  Mod& operator/=(const Mod& a) { return *this *= a.inv();\
    \ }\n  friend Mod operator+(const Mod& a, const Mod& b) { return Mod(a) += b;\
    \ }\n  friend Mod operator-(const Mod& a, const Mod& b) { return Mod(a) -= b;\
    \ }\n  friend Mod operator*(const Mod& a, const Mod& b) { return Mod(a) *= b;\
    \ }\n  friend Mod operator/(const Mod& a, const Mod& b) { return Mod(a) /= b;\
    \ }\n  Mod operator^(ull y) {\n    if (!y) return Mod(1);\n    Mod r = *this ^\
    \ (y >> 1);\n    r = r * r;\n    return y & 1 ? *this * r : r;\n  }\n  friend\
    \ ostream& operator<<(std::ostream& out, const Mod& a) {\n    return out << a.v;\n\
    \  }\n  friend istream& operator>>(std::istream& in, Mod& a) {\n    ull v;\n \
    \   in >> v;\n    a = Mod(v);\n    return in;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: number-theory/modint.hpp
  requiredBy: []
  timestamp: '2022-06-06 11:29:09+07:00'
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
