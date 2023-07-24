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
  bundledCode: "#line 1 \"misc/ternary_search.hpp\"\n// optimizing convex/concave\
    \ functions\n\nauto ternary_search = [&](int low, int high, auto f) {\n  while\
    \ (high - low > 2) {\n    const int m1 = (low + high) / 2;\n    const int m2 =\
    \ m1 + 1;\n    if (f(m1) < f(m2)) {\n      low = m1;\n    } else {\n      high\
    \ = m2;\n    }\n  }\n  return {low + 1, f(low + 1)};\n};\n"
  code: "// optimizing convex/concave functions\n\nauto ternary_search = [&](int low,\
    \ int high, auto f) {\n  while (high - low > 2) {\n    const int m1 = (low + high)\
    \ / 2;\n    const int m2 = m1 + 1;\n    if (f(m1) < f(m2)) {\n      low = m1;\n\
    \    } else {\n      high = m2;\n    }\n  }\n  return {low + 1, f(low + 1)};\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: misc/ternary_search.hpp
  requiredBy: []
  timestamp: '2023-07-25 00:50:50+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/ternary_search.hpp
layout: document
redirect_from:
- /library/misc/ternary_search.hpp
- /library/misc/ternary_search.hpp.html
title: misc/ternary_search.hpp
---
