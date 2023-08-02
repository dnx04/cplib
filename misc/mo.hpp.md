---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/misc/mo.md
    document_title: Mo's algorithm
    links: []
  bundledCode: "#line 2 \"misc/mo.hpp\"\n\n// mo start from 1, so if query is [l,\
    \ r), then insert [l - 1, r)\n\nstruct mo_algo {\n  int width;\n  vector<int>\
    \ left, right, order;\n\n  mo_algo(int N, int Q) : order(Q) {\n    width = max<int>(1,\
    \ 1.0 * N / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));\n    iota(begin(order), end(order),\
    \ 0);\n  }\n\n  void insert(int l, int r) { /* [l, r) */\n    left.emplace_back(l);\n\
    \    right.emplace_back(r);\n  }\n\n  template <typename AL, typename AR, typename\
    \ DL, typename DR, typename REM>\n  void run(const AL &add_left, const AR &add_right,\
    \ const DL &delete_left,\n           const DR &delete_right, const REM &rem) {\n\
    \    assert(left.size() == order.size());\n    sort(begin(order), end(order),\
    \ [&](int a, int b) {\n      int ablock = left[a] / width, bblock = left[b] /\
    \ width;\n      if (ablock != bblock) return ablock < bblock;\n      if (ablock\
    \ & 1) return right[a] < right[b];\n      return right[a] > right[b];\n    });\n\
    \    int nl = 0, nr = 0;\n    for (auto idx : order) {\n      while (nl > left[idx])\
    \ add_left(--nl);\n      while (nr < right[idx]) add_right(nr++);\n      while\
    \ (nl < left[idx]) delete_left(nl++);\n      while (nr > right[idx]) delete_right(--nr);\n\
    \      rem(idx);\n    }\n  }\n};\n\n/**\n * @brief Mo's algorithm\n * @docs docs/misc/mo.md\n\
    \ */\n"
  code: "#pragma once\n\n// mo start from 1, so if query is [l, r), then insert [l\
    \ - 1, r)\n\nstruct mo_algo {\n  int width;\n  vector<int> left, right, order;\n\
    \n  mo_algo(int N, int Q) : order(Q) {\n    width = max<int>(1, 1.0 * N / max<double>(1.0,\
    \ sqrt(Q * 2.0 / 3.0)));\n    iota(begin(order), end(order), 0);\n  }\n\n  void\
    \ insert(int l, int r) { /* [l, r) */\n    left.emplace_back(l);\n    right.emplace_back(r);\n\
    \  }\n\n  template <typename AL, typename AR, typename DL, typename DR, typename\
    \ REM>\n  void run(const AL &add_left, const AR &add_right, const DL &delete_left,\n\
    \           const DR &delete_right, const REM &rem) {\n    assert(left.size()\
    \ == order.size());\n    sort(begin(order), end(order), [&](int a, int b) {\n\
    \      int ablock = left[a] / width, bblock = left[b] / width;\n      if (ablock\
    \ != bblock) return ablock < bblock;\n      if (ablock & 1) return right[a] <\
    \ right[b];\n      return right[a] > right[b];\n    });\n    int nl = 0, nr =\
    \ 0;\n    for (auto idx : order) {\n      while (nl > left[idx]) add_left(--nl);\n\
    \      while (nr < right[idx]) add_right(nr++);\n      while (nl < left[idx])\
    \ delete_left(nl++);\n      while (nr > right[idx]) delete_right(--nr);\n    \
    \  rem(idx);\n    }\n  }\n};\n\n/**\n * @brief Mo's algorithm\n * @docs docs/misc/mo.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: misc/mo.hpp
  requiredBy: []
  timestamp: '2023-08-02 22:18:29+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/mo.hpp
layout: document
redirect_from:
- /library/misc/mo.hpp
- /library/misc/mo.hpp.html
title: Mo's algorithm
---
