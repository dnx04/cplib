---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../lowlink.hpp:\
    \ line -1: no such header\n"
  code: "#include <bits/extc++.h>\n\nusing namespace std;\nusing namespace __gnu_cxx;\n\
    using namespace __gnu_pbds;\n\nusing ll = long long;\n\n#include \"../lowlink.hpp\"\
    \n\nvoid solve(int ith) {\n  int n, m;\n  cin >> n >> m;\n  low_link t(n);\n \
    \ for(int i = 0; i < m; ++i){\n    int u, v;\n    cin >> u >> v;\n    t.add_edge(u,\
    \ v);\n  }\n  auto comps = t.two_edge_connected_components();\n  cout << comps.size()\
    \ << '\\n';\n  for(auto c : comps){\n    cout << c.size() << ' ';\n    for(auto\
    \ v: c) cout << v << ' ';\n    cout << '\\n';\n  }\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr), cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >>\
    \ tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}"
  dependsOn: []
  isVerificationFile: true
  path: graph/test/Two-Edge-Connected_Components.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: graph/test/Two-Edge-Connected_Components.test.cpp
layout: document
redirect_from:
- /verify/graph/test/Two-Edge-Connected_Components.test.cpp
- /verify/graph/test/Two-Edge-Connected_Components.test.cpp.html
title: graph/test/Two-Edge-Connected_Components.test.cpp
---
