---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number-theory/modint.hpp
    title: number-theory/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number-theory/modint.hpp\"\n\nusing ll = long long;\n\n\
    template <const ll m>\nstruct Mod {\n  ll v;\n\n  Mod() : v(0){};\n  Mod(ll v)\
    \ : v((v + m) % m){};\n  explicit operator ll() { return v; }\n  Mod inv() const\
    \ {\n    ll a = v, b = m, ax = 1, bx = 0;\n    while (b) {\n      ll q = a / b,\
    \ t = a % b;\n      a = b, b = t, t = ax - bx * q, ax = bx, bx = t;\n    }\n \
    \   assert(a == 1);\n    ax = (ax < 0 ? ax + m : ax);\n    return ax;\n  }\n \
    \ Mod& operator+=(const Mod& that) {\n    v = (v + that.v >= m ? v + that.v -\
    \ m : v + that.v);\n    return *this;\n  }\n  Mod& operator-=(const Mod& that)\
    \ {\n    v = (v >= that.v ? v - that.v : v + m - that.v);\n    return *this;\n\
    \  }\n  Mod& operator*=(const Mod& that) {\n    v = v * that.v % m;\n    return\
    \ *this;\n  }\n  Mod& operator/=(const Mod& that) { return (*this) *= that.inv();\
    \ }\n  Mod operator^(ll y) {\n    if (!y) return Mod(1);\n    Mod r = *this ^\
    \ (y >> 1);\n    r = r * r;\n    return y & 1 ? *this * r : r;\n  }\n  Mod operator+(const\
    \ Mod& that) const { return Mod(*this) += that; }\n  Mod operator-(const Mod&\
    \ that) const { return Mod(*this) -= that; }\n  Mod operator*(const Mod& that)\
    \ const { return Mod(*this) *= that; }\n  Mod operator/(const Mod& that) const\
    \ { return Mod(*this) /= that; }\n  bool operator==(const Mod& that) const { return\
    \ this->v == that.v; }\n  friend istream& operator>>(istream& in, Mod& that) {\n\
    \    ll val;\n    in >> val;\n    that = Mod(val);\n    return in;\n  }\n  friend\
    \ ostream& operator<<(ostream& out, const Mod& that) {\n    return out << that.v;\n\
    \  }\n};\n#line 2 \"strings/rolling_hash.hpp\"\n\nstruct rh {\n  using mint =\
    \ Mod<1000000007>;\n  mint x;\n  ll y;\n  rh operator+(const rh& a) const { return\
    \ rh{x + a.x, y + a.y}; }\n  rh operator-(const rh& a) const { return rh{x - a.x,\
    \ y - a.y}; }\n  rh operator*(const rh& a) const { return rh{x * a.x, y * a.y};\
    \ }\n  rh operator*(int k) const { return rh{x * k, y * k}; }\n  bool operator==(const\
    \ rh& a) const { return x == a.x && y == a.y; }\n};\n\nnamespace std {\ntemplate\
    \ <>\nstruct hash<rh> {\n public:\n  size_t operator()(const rh& h) const { return\
    \ h.y * 998244353 + h.x.v; }\n};\n}  // namespace std\n\ntemplate <bool iso =\
    \ false>\nclass rolling_hash {\n private:\n  const ll base = 9973;\n  int n;\n\
    \  string s;\n\n public:\n  vector<rh> h, p;\n  rolling_hash(const string& s)\
    \ : s(s), n(s.length()) {\n    h.resize(n);\n    h[0] = rh{base + s[0], base +\
    \ s[0]};\n    if (iso) {\n      for (int i = 0; i < n; ++i) h[i] = rh{base + s[i],\
    \ base + s[i]};\n      partial_sum(begin(h), end(h), begin(h), multiplies<rh>());\n\
    \    } else {\n      p.assign(n, rh{base, base});\n      partial_sum(begin(p),\
    \ end(p), begin(p), multiplies<rh>());\n      for (int i = 0; i < n; ++i) h[i]\
    \ = rh{s[i], s[i]} * p[i];\n      partial_sum(begin(h), end(h), begin(h));\n \
    \   }\n  }\n  rh get_hash(int l, int r) { return h[r] - (l ? rh{0, 0} : h[l -\
    \ 1]); }\n};\n"
  code: "#include \"../number-theory/modint.hpp\"\n\nstruct rh {\n  using mint = Mod<1000000007>;\n\
    \  mint x;\n  ll y;\n  rh operator+(const rh& a) const { return rh{x + a.x, y\
    \ + a.y}; }\n  rh operator-(const rh& a) const { return rh{x - a.x, y - a.y};\
    \ }\n  rh operator*(const rh& a) const { return rh{x * a.x, y * a.y}; }\n  rh\
    \ operator*(int k) const { return rh{x * k, y * k}; }\n  bool operator==(const\
    \ rh& a) const { return x == a.x && y == a.y; }\n};\n\nnamespace std {\ntemplate\
    \ <>\nstruct hash<rh> {\n public:\n  size_t operator()(const rh& h) const { return\
    \ h.y * 998244353 + h.x.v; }\n};\n}  // namespace std\n\ntemplate <bool iso =\
    \ false>\nclass rolling_hash {\n private:\n  const ll base = 9973;\n  int n;\n\
    \  string s;\n\n public:\n  vector<rh> h, p;\n  rolling_hash(const string& s)\
    \ : s(s), n(s.length()) {\n    h.resize(n);\n    h[0] = rh{base + s[0], base +\
    \ s[0]};\n    if (iso) {\n      for (int i = 0; i < n; ++i) h[i] = rh{base + s[i],\
    \ base + s[i]};\n      partial_sum(begin(h), end(h), begin(h), multiplies<rh>());\n\
    \    } else {\n      p.assign(n, rh{base, base});\n      partial_sum(begin(p),\
    \ end(p), begin(p), multiplies<rh>());\n      for (int i = 0; i < n; ++i) h[i]\
    \ = rh{s[i], s[i]} * p[i];\n      partial_sum(begin(h), end(h), begin(h));\n \
    \   }\n  }\n  rh get_hash(int l, int r) { return h[r] - (l ? rh{0, 0} : h[l -\
    \ 1]); }\n};"
  dependsOn:
  - number-theory/modint.hpp
  isVerificationFile: false
  path: strings/rolling_hash.hpp
  requiredBy: []
  timestamp: '2022-09-23 09:40:42+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/rolling_hash.hpp
layout: document
redirect_from:
- /library/strings/rolling_hash.hpp
- /library/strings/rolling_hash.hpp.html
title: strings/rolling_hash.hpp
---
