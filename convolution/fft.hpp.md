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
  bundledCode: "#line 1 \"convolution/fft.hpp\"\nusing cd = complex<double>;\n\nvoid\
    \ fft(vector<cd>& a, bool invert) {\n  int n = a.size();\n\n  for (int i = 1,\
    \ j = 0; i < n; i++) {\n    int bit = n >> 1;\n    for (; j & bit; bit >>= 1)\
    \ j ^= bit;\n    j ^= bit;\n\n    if (i < j) swap(a[i], a[j]);\n  }\n\n  for (int\
    \ len = 2; len <= n; len <<= 1) {\n    double ang = 2 * M_PI / len * (invert ?\
    \ -1 : 1);\n    cd wlen(cos(ang), sin(ang));\n    for (int i = 0; i < n; i +=\
    \ len) {\n      cd w(1);\n      for (int j = 0; j < len / 2; j++) {\n        cd\
    \ u = a[i + j], v = a[i + j + len / 2] * w;\n        a[i + j] = u + v;\n     \
    \   a[i + j + len / 2] = u - v;\n        w *= wlen;\n      }\n    }\n  }\n\n \
    \ if (invert) {\n    for (cd& x : a) x /= n;\n  }\n}\n\ntemplate <typename T>\n\
    vector<T> fftconv(vector<T> const& a, vector<T> const& b) {\n  vector<cd> fa(a.begin(),\
    \ a.end()), fb(b.begin(), b.end());\n  int n = 1;\n  while (n < int(a.size() +\
    \ b.size())) n <<= 1;\n  fa.resize(n);\n  fb.resize(n);\n\n  fft(fa, false);\n\
    \  fft(fb, false);\n  for (int i = 0; i < n; i++) fa[i] *= fb[i];\n  fft(fa, true);\n\
    \n  vector<T> result(n);\n  for (int i = 0; i < n; i++) result[i] = round(fa[i].real());\n\
    \  return result;\n}\n"
  code: "using cd = complex<double>;\n\nvoid fft(vector<cd>& a, bool invert) {\n \
    \ int n = a.size();\n\n  for (int i = 1, j = 0; i < n; i++) {\n    int bit = n\
    \ >> 1;\n    for (; j & bit; bit >>= 1) j ^= bit;\n    j ^= bit;\n\n    if (i\
    \ < j) swap(a[i], a[j]);\n  }\n\n  for (int len = 2; len <= n; len <<= 1) {\n\
    \    double ang = 2 * M_PI / len * (invert ? -1 : 1);\n    cd wlen(cos(ang), sin(ang));\n\
    \    for (int i = 0; i < n; i += len) {\n      cd w(1);\n      for (int j = 0;\
    \ j < len / 2; j++) {\n        cd u = a[i + j], v = a[i + j + len / 2] * w;\n\
    \        a[i + j] = u + v;\n        a[i + j + len / 2] = u - v;\n        w *=\
    \ wlen;\n      }\n    }\n  }\n\n  if (invert) {\n    for (cd& x : a) x /= n;\n\
    \  }\n}\n\ntemplate <typename T>\nvector<T> fftconv(vector<T> const& a, vector<T>\
    \ const& b) {\n  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());\n\
    \  int n = 1;\n  while (n < int(a.size() + b.size())) n <<= 1;\n  fa.resize(n);\n\
    \  fb.resize(n);\n\n  fft(fa, false);\n  fft(fb, false);\n  for (int i = 0; i\
    \ < n; i++) fa[i] *= fb[i];\n  fft(fa, true);\n\n  vector<T> result(n);\n  for\
    \ (int i = 0; i < n; i++) result[i] = round(fa[i].real());\n  return result;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: convolution/fft.hpp
  requiredBy: []
  timestamp: '2022-09-03 21:27:00+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/fft.hpp
layout: document
redirect_from:
- /library/convolution/fft.hpp
- /library/convolution/fft.hpp.html
title: convolution/fft.hpp
---
