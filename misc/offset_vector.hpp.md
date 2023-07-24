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
  bundledCode: "#line 1 \"misc/offset_vector.hpp\"\ntemplate <typename V>\nstruct\
    \ offset_vector {\n  // Index should be in [minIndex, maxIndex].\n  // minIndex\
    \ and maxIndex can be negative.\n  offset_Vector(int minIndex, int maxIndex) {\n\
    \    x.resize(maxIndex - minIndex + 1);\n    offset = minIndex;\n  }\n\n  V& operator[](int\
    \ index) { return x[index - offset]; }\n\n  auto begin() { return x.begin(); }\n\
    \  auto end() { return x.end(); }\n  auto size() { return x.size(); }\n\n private:\n\
    \  vector<V> x;\n  int offset;\n};\n"
  code: "template <typename V>\nstruct offset_vector {\n  // Index should be in [minIndex,\
    \ maxIndex].\n  // minIndex and maxIndex can be negative.\n  offset_Vector(int\
    \ minIndex, int maxIndex) {\n    x.resize(maxIndex - minIndex + 1);\n    offset\
    \ = minIndex;\n  }\n\n  V& operator[](int index) { return x[index - offset]; }\n\
    \n  auto begin() { return x.begin(); }\n  auto end() { return x.end(); }\n  auto\
    \ size() { return x.size(); }\n\n private:\n  vector<V> x;\n  int offset;\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/offset_vector.hpp
  requiredBy: []
  timestamp: '2023-07-25 00:50:50+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/offset_vector.hpp
layout: document
redirect_from:
- /library/misc/offset_vector.hpp
- /library/misc/offset_vector.hpp.html
title: misc/offset_vector.hpp
---
