---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"utility/test/Power.test.cpp\"\n#define PROBLEM \\\n  \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\n\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\n#line 1 \"utility/modint.hpp\"\n\
    typedef unsigned long long ull;\n\ntemplate <ull mod>\nstruct Mod {\n private:\n\
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
    \   in >> v;\n    a = Mod(v);\n    return in;\n  }\n};\n#line 9 \"utility/test/Power.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(0);\n  Mod<1000000007>\
    \ m;\n  int n;\n  cin >> m >> n;\n  cout << (m ^ n) << '\\n';\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#include \"../modint.hpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(0);\n  Mod<1000000007>\
    \ m;\n  int n;\n  cin >> m >> n;\n  cout << (m ^ n) << '\\n';\n}"
  dependsOn:
  - utility/modint.hpp
  isVerificationFile: true
  path: utility/test/Power.test.cpp
  requiredBy: []
  timestamp: '2022-06-06 10:42:55+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: utility/test/Power.test.cpp
layout: document
redirect_from:
- /verify/utility/test/Power.test.cpp
- /verify/utility/test/Power.test.cpp.html
title: utility/test/Power.test.cpp
---
