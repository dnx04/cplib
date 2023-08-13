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
  bundledCode: "#line 1 \"misc/mex.hpp\"\nclass Mex {\n private:\n  map<int, int>\
    \ frequency;\n  set<int> missing_numbers;\n  vector<int> A;\n\n public:\n  Mex(vector<int>\
    \ const& A) : A(A) {\n    for (int i = 0; i <= A.size(); i++) missing_numbers.insert(i);\n\
    \n    for (int x : A) {\n      ++frequency[x];\n      missing_numbers.erase(x);\n\
    \    }\n  }\n\n  int mex() { return *missing_numbers.begin(); }\n\n  void update(int\
    \ idx, int new_value) {\n    if (--frequency[A[idx]] == 0) missing_numbers.insert(A[idx]);\n\
    \    A[idx] = new_value;\n    ++frequency[new_value];\n    missing_numbers.erase(new_value);\n\
    \  }\n};\n"
  code: "class Mex {\n private:\n  map<int, int> frequency;\n  set<int> missing_numbers;\n\
    \  vector<int> A;\n\n public:\n  Mex(vector<int> const& A) : A(A) {\n    for (int\
    \ i = 0; i <= A.size(); i++) missing_numbers.insert(i);\n\n    for (int x : A)\
    \ {\n      ++frequency[x];\n      missing_numbers.erase(x);\n    }\n  }\n\n  int\
    \ mex() { return *missing_numbers.begin(); }\n\n  void update(int idx, int new_value)\
    \ {\n    if (--frequency[A[idx]] == 0) missing_numbers.insert(A[idx]);\n    A[idx]\
    \ = new_value;\n    ++frequency[new_value];\n    missing_numbers.erase(new_value);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/mex.hpp
  requiredBy: []
  timestamp: '2023-08-13 15:15:35+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/mex.hpp
layout: document
redirect_from:
- /library/misc/mex.hpp
- /library/misc/mex.hpp.html
title: misc/mex.hpp
---
