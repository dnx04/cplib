---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/maxflow.hpp
    title: graph/maxflow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/extc++.h:\
    \ line -1: no such header\n"
  code: "#include \"bits/extc++.h\"\n\nusing namespace std;\nusing namespace __gnu_cxx;\n\
    using namespace __gnu_pbds;\n\n#include \"../algo/graph/maxflow.hpp\"\n\nsigned\
    \ main() {\n  int n, m;\n  cin >> n >> m;\n  mf_graph<int> g(n);\n  for (int i\
    \ = 0; i < m; ++i) {\n    int a, b, c;\n    cin >> a >> b >> c;\n    g.add_edge(a,\
    \ b, c);\n  }\n  cout << g.flow(0, n - 1);\n}"
  dependsOn:
  - graph/maxflow.hpp
  isVerificationFile: true
  path: graph/test/Maximum_Flow.test.cpp
  requiredBy: []
  timestamp: '2022-08-08 21:12:57+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: graph/test/Maximum_Flow.test.cpp
layout: document
redirect_from:
- /verify/graph/test/Maximum_Flow.test.cpp
- /verify/graph/test/Maximum_Flow.test.cpp.html
title: graph/test/Maximum_Flow.test.cpp
---
