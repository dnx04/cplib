---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick.hpp
    title: data-structure/fenwick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data-structure/test/fenwick.test.cpp: line 8: unable to process #include in\
    \ #if / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef local\n#include \"\
    lib/prettyprint.hpp\"\n#endif\n\n#include \"../fenwick.hpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(0);\n  int n, q;\n  cin >> n >> q;\n\
    \  fenwick_tree<int64_t> fw(n);\n  for (int i = 0; i < n; ++i) {\n    int x;\n\
    \    cin >> x;\n    fw.add(i, x);\n  }\n  while (q--) {\n    int t, l, r;\n  \
    \  cin >> t >> l >> r;\n    if (t)\n      cout << fw.sum(l, r) << '\\n';\n   \
    \ else\n      fw.add(l, r);\n  }\n}"
  dependsOn:
  - data-structure/fenwick.hpp
  isVerificationFile: true
  path: data-structure/test/fenwick.test.cpp
  requiredBy: []
  timestamp: '2022-06-05 23:00:55+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data-structure/test/fenwick.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/fenwick.test.cpp
- /verify/data-structure/test/fenwick.test.cpp.html
title: data-structure/test/fenwick.test.cpp
---
