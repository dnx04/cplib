---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../number-theory/modint.hpp:\
    \ line -1: no such header\n"
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
  dependsOn: []
  isVerificationFile: false
  path: strings/rolling_hash.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/rolling_hash.hpp
layout: document
redirect_from:
- /library/strings/rolling_hash.hpp
- /library/strings/rolling_hash.hpp.html
title: strings/rolling_hash.hpp
---
