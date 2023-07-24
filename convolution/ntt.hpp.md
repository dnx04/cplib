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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: utility/static_modulo.hpp:\
    \ line -1: no such header\n"
  code: "#include \"utility/static_modulo.hpp\"\n\n// NTT modulo 998244353. If change\
    \ modulo, change these parameters accordingly\nusing Fp = static_modulo<998244353>;\n\
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
  dependsOn: []
  isVerificationFile: false
  path: convolution/ntt.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/ntt.hpp
layout: document
title: Number Theoretic Transform
---
