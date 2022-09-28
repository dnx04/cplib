---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/berlekamp_massey.hpp
    title: Berlekamp-Massey algorithm
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
    PROBLEM: https://judge.yosupo.jp/problem/find_linear_recurrence
    links:
    - https://judge.yosupo.jp/problem/find_linear_recurrence
  bundledCode: "#line 1 \"math/test/Find_Linear_Recurrence.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    \n#line 2 \"math/berlekamp_massey.hpp\"\n\ntemplate <typename Fp>\nvector<Fp>\
    \ berlekamp_massey(const vector<Fp> &s) {\n  const int N = (int)s.size();\n  vector<Fp>\
    \ b, c;\n  b.reserve(N + 1);\n  c.reserve(N + 1);\n  b.push_back(Fp(1));\n  c.push_back(Fp(1));\n\
    \  Fp y = Fp(1);\n  for (int ed = 1; ed <= N; ed++) {\n    int l = int(c.size()),\
    \ m = int(b.size());\n    Fp x = 0;\n    for (int i = 0; i < l; i++) x += c[i]\
    \ * s[ed - l + i];\n    b.emplace_back(Fp(0));\n    m++;\n    if (x == Fp(0))\
    \ continue;\n    Fp freq = x / y;\n    if (l < m) {\n      auto tmp = c;\n   \
    \   c.insert(begin(c), m - l, Fp(0));\n      for (int i = 0; i < m; i++) c[m -\
    \ 1 - i] -= freq * b[m - 1 - i];\n      b = tmp;\n      y = x;\n    } else {\n\
    \      for (int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];\n    }\n\
    \  }\n  reverse(begin(c), end(c));\n  return c;\n}\n#line 2 \"utility/static_modulo.hpp\"\
    \n\ntemplate <int mod>\nstruct static_modulo {\n  using Fp = static_modulo;\n\n\
    \ private:\n  int x;\n\n public:\n  static_modulo() : x(0) {}\n  static_modulo(int64_t\
    \ y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n  Fp &operator+=(const\
    \ Fp &p) {\n    if ((x += p.x) >= mod) x -= mod;\n    return *this;\n  }\n  Fp\
    \ &operator-=(const Fp &p) {\n    if ((x += mod - p.x) >= mod) x -= mod;\n   \
    \ return *this;\n  }\n  Fp &operator*=(const Fp &p) {\n    x = (int)(1ll * x *\
    \ p.x % mod);\n    return *this;\n  }\n  Fp &operator/=(const Fp &p) {\n    *this\
    \ *= p.inv();\n    return *this;\n  }\n  Fp operator-() const { return Fp(-x);\
    \ }\n  Fp operator+(const Fp &p) const { return Fp(*this) += p; }\n  Fp operator-(const\
    \ Fp &p) const { return Fp(*this) -= p; }\n  Fp operator*(const Fp &p) const {\
    \ return Fp(*this) *= p; }\n  Fp operator/(const Fp &p) const { return Fp(*this)\
    \ /= p; }\n  bool operator==(const Fp &p) const { return x == p.x; }\n  bool operator!=(const\
    \ Fp &p) const { return x != p.x; }\n  Fp inv() const { return pow(mod - 2); }\n\
    \  Fp pow(int64_t n) const {\n    Fp ret(1), mul(x);\n    while (n > 0) {\n  \
    \    if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  friend ostream &operator<<(ostream &os, const Fp &p) { return os\
    \ << p.x; }\n  friend istream &operator>>(istream &is, Fp &a) {\n    int64_t t;\n\
    \    is >> t;\n    a = static_modulo<mod>(t);\n    return (is);\n  }\n  int get()\
    \ const { return x; }\n  static constexpr int get_mod() { return mod; }\n};\n\
    #line 12 \"math/test/Find_Linear_Recurrence.test.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  using Fp = static_modulo<998244353>;\n\
    \  int n;\n  cin >> n;\n  vector<Fp> c(n);\n  for (auto &x : c) cin >> x;\n  auto\
    \ f = berlekamp_massey<Fp>(c);\n  cout << (int)f.size() - 1 << '\\n';\n  for (int\
    \ i = 1; i < (int)f.size(); ++i) cout << -f[i] << ' ';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using ull = unsigned long long;\n\n#include \"math/berlekamp_massey.hpp\"\n#include\
    \ \"utility/static_modulo.hpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  using Fp = static_modulo<998244353>;\n\
    \  int n;\n  cin >> n;\n  vector<Fp> c(n);\n  for (auto &x : c) cin >> x;\n  auto\
    \ f = berlekamp_massey<Fp>(c);\n  cout << (int)f.size() - 1 << '\\n';\n  for (int\
    \ i = 1; i < (int)f.size(); ++i) cout << -f[i] << ' ';\n}"
  dependsOn:
  - math/berlekamp_massey.hpp
  - utility/static_modulo.hpp
  isVerificationFile: true
  path: math/test/Find_Linear_Recurrence.test.cpp
  requiredBy: []
  timestamp: '2022-09-28 08:16:24+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: math/test/Find_Linear_Recurrence.test.cpp
layout: document
redirect_from:
- /verify/math/test/Find_Linear_Recurrence.test.cpp
- /verify/math/test/Find_Linear_Recurrence.test.cpp.html
title: math/test/Find_Linear_Recurrence.test.cpp
---
