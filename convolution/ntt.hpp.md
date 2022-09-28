---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/static_modulo.hpp
    title: Static Modular Arithmetic
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: convolution/test/Convolution.test.cpp
    title: convolution/test/Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/static_modulo.hpp\"\n\ntemplate <int mod>\nstruct\
    \ static_modulo {\n  using Fp = static_modulo;\n\n private:\n  int x;\n\n public:\n\
    \  static_modulo() : x(0) {}\n  static_modulo(int64_t y) : x(y >= 0 ? y % mod\
    \ : (mod - (-y) % mod) % mod) {}\n  Fp &operator+=(const Fp &p) {\n    if ((x\
    \ += p.x) >= mod) x -= mod;\n    return *this;\n  }\n  Fp &operator-=(const Fp\
    \ &p) {\n    if ((x += mod - p.x) >= mod) x -= mod;\n    return *this;\n  }\n\
    \  Fp &operator*=(const Fp &p) {\n    x = (int)(1ll * x * p.x % mod);\n    return\
    \ *this;\n  }\n  Fp &operator/=(const Fp &p) {\n    *this *= p.inv();\n    return\
    \ *this;\n  }\n  Fp operator-() const { return Fp(-x); }\n  Fp operator+(const\
    \ Fp &p) const { return Fp(*this) += p; }\n  Fp operator-(const Fp &p) const {\
    \ return Fp(*this) -= p; }\n  Fp operator*(const Fp &p) const { return Fp(*this)\
    \ *= p; }\n  Fp operator/(const Fp &p) const { return Fp(*this) /= p; }\n  bool\
    \ operator==(const Fp &p) const { return x == p.x; }\n  bool operator!=(const\
    \ Fp &p) const { return x != p.x; }\n  Fp inv() const { return pow(mod - 2); }\n\
    \  Fp pow(int64_t n) const {\n    Fp ret(1), mul(x);\n    while (n > 0) {\n  \
    \    if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  friend ostream &operator<<(ostream &os, const Fp &p) { return os\
    \ << p.x; }\n  friend istream &operator>>(istream &is, Fp &a) {\n    int64_t t;\n\
    \    is >> t;\n    a = static_modulo<mod>(t);\n    return (is);\n  }\n  int get()\
    \ const { return x; }\n  static constexpr int get_mod() { return mod; }\n};\n\
    #line 2 \"convolution/ntt.hpp\"\n\n// NTT modulo 998244353. If change modulo,\
    \ change these parameters accordingly\nusing Fp = static_modulo<998244353>;\n\
    Fp G = 3;\n\nvoid ntt(vector<Fp>& a, bool invert) {\n  int n = int(a.size()),\
    \ s = 0;\n  while ((1 << s) < n) s++;\n  assert(1 << s == n);\n\n  static vector<Fp>\
    \ ep, iep;\n  while (int(ep.size()) <= s) {\n    ep.push_back(G.pow((Fp(-1) /\
    \ (1 << ep.size())).get()));\n    iep.push_back(ep.back().inv());\n  }\n  vector<Fp>\
    \ b(n);\n  for (int i = 1; i <= s; i++) {\n    int w = 1 << (s - i);\n    Fp base\
    \ = invert ? iep[i] : ep[i], now = 1;\n    for (int y = 0; y < n / 2; y += w)\
    \ {\n      for (int x = 0; x < w; x++) {\n        auto l = a[y << 1 | x];\n  \
    \      auto r = now * a[y << 1 | x | w];\n        b[y | x] = l + r;\n        b[y\
    \ | x | n >> 1] = l - r;\n      }\n      now *= base;\n    }\n    swap(a, b);\n\
    \  }\n  if (invert)\n    for (auto& x : a) x /= n;\n}\n\nvector<Fp> nttconv(vector<Fp>\
    \ const& a, vector<Fp> const& b) {\n  vector<Fp> fa(a.begin(), a.end()), fb(b.begin(),\
    \ b.end());\n  int n = 1;\n  while (n < int(a.size() + b.size())) n <<= 1;\n \
    \ fa.resize(n);\n  fb.resize(n);\n  ntt(fa, false);\n  ntt(fb, false);\n  for\
    \ (int i = 0; i < n; i++) fa[i] *= fb[i];\n  ntt(fa, true);\n  fa.resize(int(a.size()\
    \ + b.size() - 1));\n  return fa;\n}\n"
  code: "#include \"../utility/static_modulo.hpp\"\n\n// NTT modulo 998244353. If\
    \ change modulo, change these parameters accordingly\nusing Fp = static_modulo<998244353>;\n\
    Fp G = 3;\n\nvoid ntt(vector<Fp>& a, bool invert) {\n  int n = int(a.size()),\
    \ s = 0;\n  while ((1 << s) < n) s++;\n  assert(1 << s == n);\n\n  static vector<Fp>\
    \ ep, iep;\n  while (int(ep.size()) <= s) {\n    ep.push_back(G.pow((Fp(-1) /\
    \ (1 << ep.size())).get()));\n    iep.push_back(ep.back().inv());\n  }\n  vector<Fp>\
    \ b(n);\n  for (int i = 1; i <= s; i++) {\n    int w = 1 << (s - i);\n    Fp base\
    \ = invert ? iep[i] : ep[i], now = 1;\n    for (int y = 0; y < n / 2; y += w)\
    \ {\n      for (int x = 0; x < w; x++) {\n        auto l = a[y << 1 | x];\n  \
    \      auto r = now * a[y << 1 | x | w];\n        b[y | x] = l + r;\n        b[y\
    \ | x | n >> 1] = l - r;\n      }\n      now *= base;\n    }\n    swap(a, b);\n\
    \  }\n  if (invert)\n    for (auto& x : a) x /= n;\n}\n\nvector<Fp> nttconv(vector<Fp>\
    \ const& a, vector<Fp> const& b) {\n  vector<Fp> fa(a.begin(), a.end()), fb(b.begin(),\
    \ b.end());\n  int n = 1;\n  while (n < int(a.size() + b.size())) n <<= 1;\n \
    \ fa.resize(n);\n  fb.resize(n);\n  ntt(fa, false);\n  ntt(fb, false);\n  for\
    \ (int i = 0; i < n; i++) fa[i] *= fb[i];\n  ntt(fa, true);\n  fa.resize(int(a.size()\
    \ + b.size() - 1));\n  return fa;\n}"
  dependsOn:
  - utility/static_modulo.hpp
  isVerificationFile: false
  path: convolution/ntt.hpp
  requiredBy: []
  timestamp: '2022-09-28 08:16:24+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - convolution/test/Convolution.test.cpp
documentation_of: convolution/ntt.hpp
layout: document
redirect_from:
- /library/convolution/ntt.hpp
- /library/convolution/ntt.hpp.html
title: convolution/ntt.hpp
---
