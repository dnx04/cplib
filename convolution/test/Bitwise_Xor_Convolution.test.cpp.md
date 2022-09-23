---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/hadamard.hpp
    title: convolution/hadamard.hpp
  - icon: ':heavy_check_mark:'
    path: number-theory/modint.hpp
    title: number-theory/modint.hpp
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
    \ <bits/extc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\n#line 2\
    \ \"number-theory/modint.hpp\"\n\nusing ll = long long;\n\ntemplate <const ll\
    \ m>\nstruct Mod {\n  ll v;\n\n  Mod() : v(0){};\n  Mod(ll v) : v((v + m) % m){};\n\
    \  explicit operator ll() { return v; }\n  Mod inv() const {\n    ll a = v, b\
    \ = m, ax = 1, bx = 0;\n    while (b) {\n      ll q = a / b, t = a % b;\n    \
    \  a = b, b = t, t = ax - bx * q, ax = bx, bx = t;\n    }\n    assert(a == 1);\n\
    \    ax = (ax < 0 ? ax + m : ax);\n    return ax;\n  }\n  Mod& operator+=(const\
    \ Mod& that) {\n    v = (v + that.v >= m ? v + that.v - m : v + that.v);\n   \
    \ return *this;\n  }\n  Mod& operator-=(const Mod& that) {\n    v = (v >= that.v\
    \ ? v - that.v : v + m - that.v);\n    return *this;\n  }\n  Mod& operator*=(const\
    \ Mod& that) {\n    v = v * that.v % m;\n    return *this;\n  }\n  Mod& operator/=(const\
    \ Mod& that) { return (*this) *= that.inv(); }\n  Mod operator^(ll y) {\n    if\
    \ (!y) return Mod(1);\n    Mod r = *this ^ (y >> 1);\n    r = r * r;\n    return\
    \ y & 1 ? *this * r : r;\n  }\n  Mod operator+(const Mod& that) const { return\
    \ Mod(*this) += that; }\n  Mod operator-(const Mod& that) const { return Mod(*this)\
    \ -= that; }\n  Mod operator*(const Mod& that) const { return Mod(*this) *= that;\
    \ }\n  Mod operator/(const Mod& that) const { return Mod(*this) /= that; }\n \
    \ bool operator==(const Mod& that) const { return this->v == that.v; }\n  friend\
    \ istream& operator>>(istream& in, Mod& that) {\n    ll val;\n    in >> val;\n\
    \    that = Mod(val);\n    return in;\n  }\n  friend ostream& operator<<(ostream&\
    \ out, const Mod& that) {\n    return out << that.v;\n  }\n};\n#line 1 \"convolution/hadamard.hpp\"\
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
    \ { hi -= lo; });\n}\n#line 11 \"convolution/test/Bitwise_Xor_Convolution.test.cpp\"\
    \n\nvoid solve(int ith) {\n  int n;\n  cin >> n;\n  vector<Mod<998244353>> a(1\
    \ << n), b(1 << n);\n  for (auto &x : a) cin >> x;\n  for (auto &x : b) cin >>\
    \ x;\n  for (auto v : xorconv(a, b)) cout << v << ' ';\n}\n\nsigned main() {\n\
    \  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include <bits/extc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    \n#include \"../../number-theory/modint.hpp\"\n#include \"../hadamard.hpp\"\n\n\
    void solve(int ith) {\n  int n;\n  cin >> n;\n  vector<Mod<998244353>> a(1 <<\
    \ n), b(1 << n);\n  for (auto &x : a) cin >> x;\n  for (auto &x : b) cin >> x;\n\
    \  for (auto v : xorconv(a, b)) cout << v << ' ';\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >>\
    \ tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}"
  dependsOn:
  - number-theory/modint.hpp
  - convolution/hadamard.hpp
  isVerificationFile: true
  path: convolution/test/Bitwise_Xor_Convolution.test.cpp
  requiredBy: []
  timestamp: '2022-09-08 21:32:23+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: convolution/test/Bitwise_Xor_Convolution.test.cpp
layout: document
redirect_from:
- /verify/convolution/test/Bitwise_Xor_Convolution.test.cpp
- /verify/convolution/test/Bitwise_Xor_Convolution.test.cpp.html
title: convolution/test/Bitwise_Xor_Convolution.test.cpp
---
