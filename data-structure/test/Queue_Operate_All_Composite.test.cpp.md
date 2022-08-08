---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/swag.hpp
    title: data-structure/swag.hpp
  - icon: ':heavy_check_mark:'
    path: number-theory/modint.hpp
    title: number-theory/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/extc++.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include \"bits/extc++.h\"\n\nusing namespace std;\n\n#include \"../algo/data-structure/swag.hpp\"\
    \n#include \"../algo/number-theory/modint.hpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(0);\n  using mint = Mod<998244353>;\n  struct F {\n    mint a, b;\n\
    \  };\n  auto op = [&](F l, F r) -> F {\n    mint na = l.a * r.a, nb = l.b * r.a\
    \ + r.b;\n    return F{na, nb};\n  };\n  SWAG<F, decltype(op)> swag(F{1, 0}, op);\n\
    \n  int Q;\n  cin >> Q;\n  while (Q--) {\n    int t;\n    cin >> t;\n    if (t\
    \ == 0) {\n      mint a, b;\n      cin >> a >> b;\n      swag.push(F{a, b});\n\
    \    } else if (t == 1) {\n      swag.pop();\n    } else {\n      mint x;\n  \
    \    cin >> x;\n      auto f = swag.sum();\n      cout << f.a * x + f.b << '\\\
    n';\n    }\n  }\n}"
  dependsOn:
  - data-structure/swag.hpp
  - number-theory/modint.hpp
  isVerificationFile: true
  path: data-structure/test/Queue_Operate_All_Composite.test.cpp
  requiredBy: []
  timestamp: '2022-06-30 19:56:15+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data-structure/test/Queue_Operate_All_Composite.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/Queue_Operate_All_Composite.test.cpp
- /verify/data-structure/test/Queue_Operate_All_Composite.test.cpp.html
title: data-structure/test/Queue_Operate_All_Composite.test.cpp
---
