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
  code: "#include \"../number-theory/modint.hpp\"\n\n// NTT modulo 998244353. If change\
    \ modulo, change these parameters accordingly\nusing mint = Mod<998244353>;\n\
    mint G = 3;\n\nvoid ntt(vector<mint>& a, bool invert) {\n  int n = int(a.size()),\
    \ s = 0;\n  while ((1 << s) < n) s++;\n  assert(1 << s == n);\n\n  static vector<mint>\
    \ ep, iep;\n  while (int(ep.size()) <= s) {\n    ep.push_back(G ^ ll(mint(-1)\
    \ / (1 << ep.size())));\n    iep.push_back(ep.back().inv());\n  }\n  vector<mint>\
    \ b(n);\n  for (int i = 1; i <= s; i++) {\n    int w = 1 << (s - i);\n    mint\
    \ base = invert ? iep[i] : ep[i], now = 1;\n    for (int y = 0; y < n / 2; y +=\
    \ w) {\n      for (int x = 0; x < w; x++) {\n        auto l = a[y << 1 | x];\n\
    \        auto r = now * a[y << 1 | x | w];\n        b[y | x] = l + r;\n      \
    \  b[y | x | n >> 1] = l - r;\n      }\n      now *= base;\n    }\n    swap(a,\
    \ b);\n  }\n  if(invert) for(auto &x: a) x /= n;\n}\n\nvector<mint> nttconv(vector<mint>\
    \ const& a, vector<mint> const& b) {\n  vector<mint> fa(a.begin(), a.end()), fb(b.begin(),\
    \ b.end());\n  int n = 1;\n  while (n < int(a.size() + b.size())) n <<= 1;\n \
    \ fa.resize(n);\n  fb.resize(n);\n  ntt(fa, false);\n  ntt(fb, false);\n  for\
    \ (int i = 0; i < n; i++) fa[i] *= fb[i];\n  ntt(fa, true);\n  fa.resize(int(a.size()\
    \ + b.size() - 1));\n  return fa;\n}"
  dependsOn: []
  isVerificationFile: false
  path: convolution/ntt.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/ntt.hpp
layout: document
redirect_from:
- /library/convolution/ntt.hpp
- /library/convolution/ntt.hpp.html
title: convolution/ntt.hpp
---
