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
  bundledCode: "#line 1 \"misc/optimize.hpp\"\n// optimizing convex/concave functions\n\
    \nauto optimize = [&](int low, int high, auto f) {\n  while (high - low > 2) {\n\
    \    const int m1 = (low + high) / 2;\n    const int m2 = m1 + 1;\n    if (f(m1)\
    \ < f(m2)) {\n      low = m1;\n    } else {\n      high = m2;\n    }\n  }\n  return\
    \ {low + 1, f(low + 1)};\n};\n"
  code: "// optimizing convex/concave functions\n\nauto optimize = [&](int low, int\
    \ high, auto f) {\n  while (high - low > 2) {\n    const int m1 = (low + high)\
    \ / 2;\n    const int m2 = m1 + 1;\n    if (f(m1) < f(m2)) {\n      low = m1;\n\
    \    } else {\n      high = m2;\n    }\n  }\n  return {low + 1, f(low + 1)};\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: misc/optimize.hpp
  requiredBy: []
  timestamp: '2022-09-23 09:40:42+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/optimize.hpp
layout: document
redirect_from:
- /library/misc/optimize.hpp
- /library/misc/optimize.hpp.html
title: misc/optimize.hpp
---
