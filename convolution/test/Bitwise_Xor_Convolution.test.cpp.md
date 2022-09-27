---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/hadamard.hpp
    title: convolution/hadamard.hpp
  - icon: ':heavy_check_mark:'
    path: utility/dynamic_modulo.hpp
    title: utility/dynamic_modulo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"convolution/test/Bitwise_Xor_Convolution.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\n\n#include\
    \ <bits/extc++.h>\n\nusing namespace std;\n\n#line 1 \"convolution/hadamard.hpp\"\
    \ntemplate <typename T, typename F>\nvoid abstract_fwht(vector<T> &seq, F f) {\n\
    \  const int n = seq.size();\n  assert(__builtin_popcount(n) == 1);\n  for (int\
    \ w = 1; w < n; w *= 2) {\n    for (int i = 0; i < n; i += w * 2) {\n      for\
    \ (int j = 0; j < w; j++) {\n        f(seq[i + j], seq[i + j + w]);\n      }\n\
    \    }\n  }\n}\n\ntemplate <typename T, typename F1, typename F2>\nvector<T> bitwise_conv(vector<T>\
    \ x, vector<T> y, F1 f, F2 finv) {\n  const int n = x.size();\n  assert(__builtin_popcount(n)\
    \ == 1);\n  assert(x.size() == y.size());\n  if (x == y) {\n    abstract_fwht(x,\
    \ f), y = x;\n  } else {\n    abstract_fwht(x, f), abstract_fwht(y, f);\n  }\n\
    \  for (size_t i = 0; i < x.size(); i++) {\n    x[i] *= y[i];\n  }\n  abstract_fwht(x,\
    \ finv);\n  return x;\n}\n\n// bitwise xor convolution (FWHT-based)\n// ret[i]\
    \ = \\sum_j x[j] * y[i ^ j]\n// if T is integer, ||x||_1 * ||y||_1 * 2 < numeric_limits<T>::max()\n\
    template <typename T>\nvector<T> xorconv(vector<T> x, vector<T> y) {\n  auto f\
    \ = [](T &lo, T &hi) {\n    T c = lo + hi;\n    hi = lo - hi, lo = c;\n  };\n\
    \  auto finv = [](T &lo, T &hi) {\n    T c = lo + hi;\n    hi = (lo - hi) / 2,\n\
    \    lo =\n        c / 2;  // Reconsider HEAVY complexity of division by 2 when\
    \ T is ModInt\n  };\n  return bitwise_conv(x, y, f, finv);\n}\n\n// bitwise AND\
    \ conolution\n// ret[i] = \\sum_{(j & k) == i} x[j] * y[k]\ntemplate <typename\
    \ T>\nvector<T> andconv(vector<T> x, vector<T> y) {\n  return bitwise_conv(\n\
    \      x, y, [](T &lo, T &hi) { lo += hi; }, [](T &lo, T &hi) { lo -= hi; });\n\
    }\n\n// bitwise OR convolution\n// ret[i] = \\sum_{(j | k) == i} x[j] * y[k]\n\
    template <typename T>\nvector<T> orconv(vector<T> x, vector<T> y) {\n  return\
    \ bitwise_conv(\n      x, y, [](T &lo, T &hi) { hi += lo; }, [](T &lo, T &hi)\
    \ { hi -= lo; });\n}\n#line 2 \"utility/dynamic_modulo.hpp\"\n\nstruct dynamic_modulo\
    \ {\n  using Fp = dynamic_modulo;\n  using i64 = int64_t;\n  using u64 = uint64_t;\n\
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
    \ dynamic_modulo::n2;\n#line 9 \"convolution/test/Bitwise_Xor_Convolution.test.cpp\"\
    \n\nvoid solve(int ith) {\n  dynamic_modulo::set_mod(998244353);\n  using Fp =\
    \ dynamic_modulo;\n  int n;\n  cin >> n;\n  vector<Fp> a(1 << n), b(1 << n);\n\
    \  for (auto &x : a) cin >> x;\n  for (auto &x : b) cin >> x;\n  for (auto v :\
    \ xorconv(a, b)) cout << v << ' ';\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >>\
    \ tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include <bits/extc++.h>\n\nusing namespace std;\n\n#include \"convolution/hadamard.hpp\"\
    \n#include \"utility/dynamic_modulo.hpp\"\n\nvoid solve(int ith) {\n  dynamic_modulo::set_mod(998244353);\n\
    \  using Fp = dynamic_modulo;\n  int n;\n  cin >> n;\n  vector<Fp> a(1 << n),\
    \ b(1 << n);\n  for (auto &x : a) cin >> x;\n  for (auto &x : b) cin >> x;\n \
    \ for (auto v : xorconv(a, b)) cout << v << ' ';\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >>\
    \ tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}"
  dependsOn:
  - convolution/hadamard.hpp
  - utility/dynamic_modulo.hpp
  isVerificationFile: true
  path: convolution/test/Bitwise_Xor_Convolution.test.cpp
  requiredBy: []
  timestamp: '2022-09-27 23:05:16+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: convolution/test/Bitwise_Xor_Convolution.test.cpp
layout: document
redirect_from:
- /verify/convolution/test/Bitwise_Xor_Convolution.test.cpp
- /verify/convolution/test/Bitwise_Xor_Convolution.test.cpp.html
title: convolution/test/Bitwise_Xor_Convolution.test.cpp
---
