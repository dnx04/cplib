---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: convolution/test/Bitwise_And_Convolution.test.cpp
    title: convolution/test/Bitwise_And_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/test/Bitwise_Xor_Convolution.test.cpp
    title: convolution/test/Bitwise_Xor_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/dynamic_modulo.hpp\"\n\nstruct dynamic_modulo {\n\
    \  using Fp = dynamic_modulo;\n  using i64 = int64_t;\n  using u64 = uint64_t;\n\
    \  using u128 = __uint128_t;\n\n  static u64 mod;\n  static u64 r;\n  static u64\
    \ n2;\n\n  static u64 get_r() {\n    u64 ret = mod;\n    for (i64 i = 0; i < 5;\
    \ ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n  static void set_mod(u64\
    \ m) {\n    assert(m < (1LL << 62));\n    assert((m & 1) == 1);\n    mod = m;\n\
    \    n2 = -u128(m) % m;\n    r = get_r();\n    assert(r * mod == 1);\n  }\n  u64\
    \ a;\n  dynamic_modulo() : a(0) {}\n  dynamic_modulo(const int64_t &b) : a(reduce((u128(b)\
    \ + mod) * n2)){};\n  static u64 reduce(const u128 &b) {\n    return (b + u128(u64(b)\
    \ * u64(-r)) * mod) >> 64;\n  }\n  Fp &operator+=(const Fp &b) {\n    if (i64(a\
    \ += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n  Fp &operator-=(const\
    \ Fp &b) {\n    if (i64(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n\
    \  Fp &operator*=(const Fp &b) {\n    a = reduce(u128(a) * b.a);\n    return *this;\n\
    \  }\n  Fp &operator/=(const Fp &b) {\n    *this *= b.inv();\n    return *this;\n\
    \  }\n  Fp operator+(const Fp &b) const { return Fp(*this) += b; }\n  Fp operator-(const\
    \ Fp &b) const { return Fp(*this) -= b; }\n  Fp operator*(const Fp &b) const {\
    \ return Fp(*this) *= b; }\n  Fp operator/(const Fp &b) const { return Fp(*this)\
    \ /= b; }\n  bool operator==(const Fp &b) const {\n    return (a >= mod ? a -\
    \ mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n  bool operator!=(const Fp\
    \ &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod\
    \ : b.a);\n  }\n  Fp operator-() const { return Fp() - Fp(*this); }\n  Fp pow(u128\
    \ n) const {\n    Fp ret(1), mul(*this);\n    while (n > 0) {\n      if (n & 1)\
    \ ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n\
    \  friend ostream &operator<<(ostream &os, const Fp &b) { return os << b.get();\
    \ }\n  friend istream &operator>>(istream &is, Fp &b) {\n    int64_t t;\n    is\
    \ >> t;\n    b = dynamic_modulo(t);\n    return (is);\n  }\n  Fp inv() const {\
    \ return pow(mod - 2); }\n  u64 get() const {\n    u64 ret = reduce(a);\n    return\
    \ ret >= mod ? ret - mod : ret;\n  }\n  static u64 get_mod() { return mod; }\n\
    };\ntypename dynamic_modulo::u64 dynamic_modulo::mod, dynamic_modulo::r,\n   \
    \ dynamic_modulo::n2;\n"
  code: "#pragma once\n\nstruct dynamic_modulo {\n  using Fp = dynamic_modulo;\n \
    \ using i64 = int64_t;\n  using u64 = uint64_t;\n  using u128 = __uint128_t;\n\
    \n  static u64 mod;\n  static u64 r;\n  static u64 n2;\n\n  static u64 get_r()\
    \ {\n    u64 ret = mod;\n    for (i64 i = 0; i < 5; ++i) ret *= 2 - mod * ret;\n\
    \    return ret;\n  }\n  static void set_mod(u64 m) {\n    assert(m < (1LL <<\
    \ 62));\n    assert((m & 1) == 1);\n    mod = m;\n    n2 = -u128(m) % m;\n   \
    \ r = get_r();\n    assert(r * mod == 1);\n  }\n  u64 a;\n  dynamic_modulo() :\
    \ a(0) {}\n  dynamic_modulo(const int64_t &b) : a(reduce((u128(b) + mod) * n2)){};\n\
    \  static u64 reduce(const u128 &b) {\n    return (b + u128(u64(b) * u64(-r))\
    \ * mod) >> 64;\n  }\n  Fp &operator+=(const Fp &b) {\n    if (i64(a += b.a -\
    \ 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n  Fp &operator-=(const\
    \ Fp &b) {\n    if (i64(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n\
    \  Fp &operator*=(const Fp &b) {\n    a = reduce(u128(a) * b.a);\n    return *this;\n\
    \  }\n  Fp &operator/=(const Fp &b) {\n    *this *= b.inv();\n    return *this;\n\
    \  }\n  Fp operator+(const Fp &b) const { return Fp(*this) += b; }\n  Fp operator-(const\
    \ Fp &b) const { return Fp(*this) -= b; }\n  Fp operator*(const Fp &b) const {\
    \ return Fp(*this) *= b; }\n  Fp operator/(const Fp &b) const { return Fp(*this)\
    \ /= b; }\n  bool operator==(const Fp &b) const {\n    return (a >= mod ? a -\
    \ mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n  bool operator!=(const Fp\
    \ &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod\
    \ : b.a);\n  }\n  Fp operator-() const { return Fp() - Fp(*this); }\n  Fp pow(u128\
    \ n) const {\n    Fp ret(1), mul(*this);\n    while (n > 0) {\n      if (n & 1)\
    \ ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n\
    \  friend ostream &operator<<(ostream &os, const Fp &b) { return os << b.get();\
    \ }\n  friend istream &operator>>(istream &is, Fp &b) {\n    int64_t t;\n    is\
    \ >> t;\n    b = dynamic_modulo(t);\n    return (is);\n  }\n  Fp inv() const {\
    \ return pow(mod - 2); }\n  u64 get() const {\n    u64 ret = reduce(a);\n    return\
    \ ret >= mod ? ret - mod : ret;\n  }\n  static u64 get_mod() { return mod; }\n\
    };\ntypename dynamic_modulo::u64 dynamic_modulo::mod, dynamic_modulo::r,\n   \
    \ dynamic_modulo::n2;"
  dependsOn: []
  isVerificationFile: false
  path: utility/dynamic_modulo.hpp
  requiredBy: []
  timestamp: '2022-09-27 22:26:49+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - convolution/test/Bitwise_Xor_Convolution.test.cpp
  - convolution/test/Bitwise_And_Convolution.test.cpp
documentation_of: utility/dynamic_modulo.hpp
layout: document
redirect_from:
- /library/utility/dynamic_modulo.hpp
- /library/utility/dynamic_modulo.hpp.html
title: utility/dynamic_modulo.hpp
---
