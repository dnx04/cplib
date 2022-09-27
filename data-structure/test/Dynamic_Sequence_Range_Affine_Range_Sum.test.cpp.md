---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: number-theory/modint.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <bits/extc++.h>\n\nusing namespace std;\nusing namespace __gnu_cxx;\n\
    using namespace __gnu_pbds;\n\n#include \"../algo/number-theory/modint.hpp\"\n\
    #include \"../splay.hpp\"\n\nusing mint = Mod<998244353>;\n\nstruct S {\n  mint\
    \ sum;\n  int sz;\n};\n\nstruct F {\n  mint a, b;\n};\n\nusing Node = node_t<mint,\
    \ S, F>;\n\nS op(S left, mint key, S right) {\n  return S{left.sum + key + right.sum,\
    \ left.sz + 1 + right.sz};\n};\npair<mint, S> e() { return {0, {0, 0}}; }\npair<mint,\
    \ S> mapping(F f, Node* node) {\n  return {(f.a * node->key + f.b),\n        \
    \  S{f.a * node->data.sum + f.b * node->data.sz, node->data.sz}};\n}\nF composition(F\
    \ f, F g) { return F{f.a * g.a, f.a * g.b + f.b}; }\nF id() { return F{1, 0};\
    \ }\n\nvoid solve([[maybe_unused]] int ith) {\n  int n, q;\n  cin >> n >> q;\n\
    \  splay_tree<mint, S, op, e, F, mapping, composition, id> st;\n  for (int i =\
    \ 0; i < n; ++i) {\n    int x;\n    cin >> x;\n    st.insert(i, x);\n  }\n  while\
    \ (q--) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      int pos, val;\n\
    \      cin >> pos >> val;\n      st.insert(pos, val);\n    } else if (t == 1)\
    \ {\n      int pos;\n      cin >> pos;\n      st.erase(pos);\n    } else if (t\
    \ == 2) {\n      int l, r;\n      cin >> l >> r;\n      st.reverse(l, r);\n  \
    \  } else if (t == 3) {\n      int l, r, a, b;\n      cin >> l >> r >> a >> b;\n\
    \      st.apply(l, r, F{a, b});\n    } else {\n      int l, r;\n      cin >> l\
    \ >> r;\n      cout << st.prod(l, r).sum << '\\n';\n    }\n  }\n}\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}"
  dependsOn: []
  isVerificationFile: true
  path: data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
- /verify/data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp.html
title: data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
---
