---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: utility/static_modulo.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include <bits/extc++.h>\n\nusing namespace std;\n\n#include \"data-structure/swag.hpp\"\
    \n#include \"utility/static_modulo.hpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(0);\n  using Fp = static_modulo<998244353>;\n  struct F {\n    Fp a,\
    \ b;\n  };\n  auto op = [&](F l, F r) -> F {\n    Fp na = l.a * r.a, nb = l.b\
    \ * r.a + r.b;\n    return F{na, nb};\n  };\n  SWAG<F, decltype(op)> swag(F{1,\
    \ 0}, op);\n\n  int Q;\n  cin >> Q;\n  while (Q--) {\n    int t;\n    cin >> t;\n\
    \    if (t == 0) {\n      Fp a, b;\n      cin >> a >> b;\n      swag.push(F{a,\
    \ b});\n    } else if (t == 1) {\n      swag.pop();\n    } else {\n      Fp x;\n\
    \      cin >> x;\n      auto f = swag.sum();\n      cout << f.a * x + f.b << '\\\
    n';\n    }\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: data-structure/test/Queue_Operate_All_Composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: data-structure/test/Queue_Operate_All_Composite.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/Queue_Operate_All_Composite.test.cpp
- /verify/data-structure/test/Queue_Operate_All_Composite.test.cpp.html
title: data-structure/test/Queue_Operate_All_Composite.test.cpp
---
