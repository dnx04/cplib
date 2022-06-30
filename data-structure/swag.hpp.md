---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data-structure/test/Queue_Operate_All_Composite.test.cpp
    title: data-structure/test/Queue_Operate_All_Composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/swag.hpp\"\ntemplate <class T, class Op>\n\
    struct SWAG {\n  T e;\n  Op op;\n  deque<T> dq;\n  int front;\n  T back;\n\n \
    \ SWAG(T e_, Op op_) : e(e_), op(op_) {\n    front = 0;\n    back = e;\n  }\n\n\
    \  void push(T x) {\n    dq.push_back(x);\n    back = op(back, x);\n  }\n\n  void\
    \ pop() {\n    assert(not dq.empty());\n    dq.pop_front();\n    if (front) {\n\
    \      --front;\n    } else {\n      int len = dq.size();\n      for (int i =\
    \ len - 2; i >= 0; i--) dq[i] = op(dq[i], dq[i + 1]);\n      front = len;\n  \
    \    back = e;\n    }\n  }\n\n  T sum() const { return front ? op(dq.front(),\
    \ back) : back; }\n};\n"
  code: "template <class T, class Op>\nstruct SWAG {\n  T e;\n  Op op;\n  deque<T>\
    \ dq;\n  int front;\n  T back;\n\n  SWAG(T e_, Op op_) : e(e_), op(op_) {\n  \
    \  front = 0;\n    back = e;\n  }\n\n  void push(T x) {\n    dq.push_back(x);\n\
    \    back = op(back, x);\n  }\n\n  void pop() {\n    assert(not dq.empty());\n\
    \    dq.pop_front();\n    if (front) {\n      --front;\n    } else {\n      int\
    \ len = dq.size();\n      for (int i = len - 2; i >= 0; i--) dq[i] = op(dq[i],\
    \ dq[i + 1]);\n      front = len;\n      back = e;\n    }\n  }\n\n  T sum() const\
    \ { return front ? op(dq.front(), back) : back; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/swag.hpp
  requiredBy: []
  timestamp: '2022-06-30 19:56:15+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data-structure/test/Queue_Operate_All_Composite.test.cpp
documentation_of: data-structure/swag.hpp
layout: document
redirect_from:
- /library/data-structure/swag.hpp
- /library/data-structure/swag.hpp.html
title: data-structure/swag.hpp
---
