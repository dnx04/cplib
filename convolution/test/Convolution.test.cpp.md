---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: convolution/ntt.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"convolution/test/Convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\n\n#line 2 \"number-theory/modint.hpp\"\
    \n\nusing ll = long long;\n\ntemplate <const ll m>\nstruct Mod {\n  ll v;\n\n\
    \  Mod() : v(0){};\n  Mod(ll _v) : v((_v + m) % m){};\n  explicit operator ll()\
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
    \ Mod operator/(const Mod& that) const { return Mod(*this) /= that; }\n  bool\
    \ operator==(const Mod& that) const { return this->v == that.v; }\n  friend istream&\
    \ operator>>(istream& in, Mod& that) {\n    ll val;\n    in >> val;\n    that\
    \ = Mod(val);\n    return in;\n  }\n  friend ostream& operator<<(ostream& out,\
    \ const Mod& that) {\n    return out << that.v;\n  }\n};\n#line 2 \"convolution/ntt.hpp\"\
    \n\n// NTT modulo 998244353. If change modulo, change these parameters accordingly\n\
    using mint = Mod<998244353>;\nmint G = 3;\n\nvoid ntt(vector<mint>& a, bool invert)\
    \ {\n  int n = int(a.size()), s = 0;\n  while ((1 << s) < n) s++;\n  assert(1\
    \ << s == n);\n\n  static vector<mint> ep, iep;\n  while (int(ep.size()) <= s)\
    \ {\n    ep.push_back(G ^ ll(mint(-1) / (1 << ep.size())));\n    iep.push_back(ep.back().inv());\n\
    \  }\n  vector<mint> b(n);\n  for (int i = 1; i <= s; i++) {\n    int w = 1 <<\
    \ (s - i);\n    mint base = invert ? iep[i] : ep[i], now = 1;\n    for (int y\
    \ = 0; y < n / 2; y += w) {\n      for (int x = 0; x < w; x++) {\n        auto\
    \ l = a[y << 1 | x];\n        auto r = now * a[y << 1 | x | w];\n        b[y |\
    \ x] = l + r;\n        b[y | x | n >> 1] = l - r;\n      }\n      now *= base;\n\
    \    }\n    swap(a, b);\n  }\n  if(invert) for(auto &x: a) x /= n;\n}\n\nvector<mint>\
    \ nttconv(vector<mint> const& a, vector<mint> const& b) {\n  vector<mint> fa(a.begin(),\
    \ a.end()), fb(b.begin(), b.end());\n  int n = 1;\n  while (n < int(a.size() +\
    \ b.size())) n <<= 1;\n  fa.resize(n);\n  fb.resize(n);\n  ntt(fa, false);\n \
    \ ntt(fb, false);\n  for (int i = 0; i < n; i++) fa[i] *= fb[i];\n  ntt(fa, true);\n\
    \  fa.resize(int(a.size() + b.size() - 1));\n  return fa;\n}\n#line 10 \"convolution/test/Convolution.test.cpp\"\
    \n\nvoid solve(int ith) {\n  int n, m;\n  cin >> n >> m;\n  vector<mint> a(n),\
    \ b(m);\n  for (auto &x : a) cin >> x;\n  for (auto &x : b) cin >> x;\n  auto\
    \ c = nttconv(a, b);\n  for (auto val : c) cout << val << ' ';\n}\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\n#include\
    \ \"../ntt.hpp\"\n\nvoid solve(int ith) {\n  int n, m;\n  cin >> n >> m;\n  vector<mint>\
    \ a(n), b(m);\n  for (auto &x : a) cin >> x;\n  for (auto &x : b) cin >> x;\n\
    \  auto c = nttconv(a, b);\n  for (auto val : c) cout << val << ' ';\n}\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}"
  dependsOn:
  - convolution/ntt.hpp
  - number-theory/modint.hpp
  isVerificationFile: true
  path: convolution/test/Convolution.test.cpp
  requiredBy: []
  timestamp: '2022-09-04 21:32:52+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: convolution/test/Convolution.test.cpp
layout: document
redirect_from:
- /verify/convolution/test/Convolution.test.cpp
- /verify/convolution/test/Convolution.test.cpp.html
title: convolution/test/Convolution.test.cpp
---
