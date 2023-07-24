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
  bundledCode: "#line 1 \"dp/dnc.hpp\"\n// calculate optimum of a function using divide\
    \ and conquer\nauto dnc = [&](auto dnc, int l, int r, int optl, int optr) {\n\
    \  if (l > r) return;\n\n  int mid = (l + r) >> 1;\n  pair<ll, ll> best = {INF,\
    \ -1};\n\n  for (int k = optl; k <= min(mid, optr); k++) {\n    best = min(best,\
    \ {(k ? dp[k - 1] : 0) + C(k, mid), k});\n  }\n\n  ndp[mid] = best.first;\n  int\
    \ opt = best.second;\n\n  dnc(dnc, l, mid - 1, optl, opt);\n  dnc(dnc, mid + 1,\
    \ r, opt, optr);\n};\n"
  code: "// calculate optimum of a function using divide and conquer\nauto dnc = [&](auto\
    \ dnc, int l, int r, int optl, int optr) {\n  if (l > r) return;\n\n  int mid\
    \ = (l + r) >> 1;\n  pair<ll, ll> best = {INF, -1};\n\n  for (int k = optl; k\
    \ <= min(mid, optr); k++) {\n    best = min(best, {(k ? dp[k - 1] : 0) + C(k,\
    \ mid), k});\n  }\n\n  ndp[mid] = best.first;\n  int opt = best.second;\n\n  dnc(dnc,\
    \ l, mid - 1, optl, opt);\n  dnc(dnc, mid + 1, r, opt, optr);\n};"
  dependsOn: []
  isVerificationFile: false
  path: dp/dnc.hpp
  requiredBy: []
  timestamp: '2023-07-25 00:50:50+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/dnc.hpp
layout: document
redirect_from:
- /library/dp/dnc.hpp
- /library/dp/dnc.hpp.html
title: dp/dnc.hpp
---
