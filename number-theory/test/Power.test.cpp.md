---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"number-theory/test/Power.test.cpp\"\n#define PROBLEM \\\n\
    \  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\n\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\n#line 1 \"number-theory/modint.hpp\"\
    \n// works for mod < 2^63\n\nusing ull = unsigned long long;\ntemplate <ull m>\n\
    struct Mod {\n  ull v;\n\n  Mod() : v(0){};\n  Mod(__uint128_t _v) : v(_v % m){};\n\
    \  explicit operator ull() { return v; }\n  Mod inv() const {\n    int64_t a =\
    \ v, b = m, ax = 1, bx = 0;\n    while (b) {\n      ull q = a / b, t = a % b;\n\
    \      a = b, b = t, t = ax - bx * q, ax = bx, bx = t;\n    }\n    assert(a ==\
    \ 1);\n    ax = (ax < 0 ? ax + m : ax);\n    return ax;\n  }\n  Mod& operator+=(const\
    \ Mod& that) {\n    v = (v + that.v >= m ? v + that.v - m : v + that.v);\n   \
    \ return *this;\n  }\n  Mod& operator-=(const Mod& that) {\n    v = (v >= that.v\
    \ ? v - that.v : v + m - that.v);\n    return *this;\n  }\n  Mod& operator*=(const\
    \ Mod& that) {\n    long double x;\n    uint64_t c;\n    int64_t r;\n    x = v;\n\
    \    c = x * that.v / m;\n    r = (int64_t)(v * that.v - c * m) % (int64_t)m;\n\
    \    v = (r < 0 ? r + m : r);\n    return *this;\n  }\n  Mod& operator/=(const\
    \ Mod& that) { return (*this) *= that.inv(); }\n  Mod operator^(ull y) {\n   \
    \ if (!y) return Mod(1);\n    Mod r = *this ^ (y >> 1);\n    r = r * r;\n    return\
    \ y & 1 ? *this * r : r;\n  }\n  Mod operator+(const Mod& that) const { return\
    \ Mod(*this) += that; }\n  Mod operator-(const Mod& that) const { return Mod(*this)\
    \ -= that; }\n  Mod operator*(const Mod& that) const { return Mod(*this) *= that;\
    \ }\n  Mod operator/(const Mod& that) const { return Mod(*this) /= that; }\n \
    \ friend istream& operator>>(istream& in, Mod& that) {\n    ull val;\n    in >>\
    \ val;\n    that = Mod(val);\n    return in;\n  }\n  friend ostream& operator<<(ostream&\
    \ out, const Mod& that) {\n    return out << that.v;\n  }\n};\n#line 9 \"number-theory/test/Power.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(0);\n  Mod<1000000007>\
    \ m;\n  int n;\n  cin >> m >> n;\n  cout << (m ^ n) << '\\n';\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#include \"../modint.hpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(0);\n  Mod<1000000007>\
    \ m;\n  int n;\n  cin >> m >> n;\n  cout << (m ^ n) << '\\n';\n}"
  dependsOn:
  - number-theory/modint.hpp
  isVerificationFile: true
  path: number-theory/test/Power.test.cpp
  requiredBy: []
  timestamp: '2022-06-14 14:26:41+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: number-theory/test/Power.test.cpp
layout: document
redirect_from:
- /verify/number-theory/test/Power.test.cpp
- /verify/number-theory/test/Power.test.cpp.html
title: number-theory/test/Power.test.cpp
---
