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
  bundledCode: "#line 1 \"data-structure/dynamic_hull.hpp\"\nstruct Line {\n  ll m,\
    \ b;\n  mutable function<const Line*()> succ;\n  bool operator<(const Line& rhs)\
    \ const {\n    if (rhs.b != -INF) return m < rhs.m;\n    const Line* s = succ();\n\
    \    if (!s) return 0;\n    ll x = rhs.m;\n    return b - s->b < (s->m - m) *\
    \ x;\n  }\n};\n\nstruct dynamic_hull\n    : public multiset<Line> {  // will maintain\
    \ upper hull for maximum\n  bool bad(iterator y) {\n    auto z = next(y);\n  \
    \  if (y == begin()) {\n      if (z == end()) return 0;\n      return y->m ==\
    \ z->m && y->b <= z->b;\n    }\n    auto x = prev(y);\n    if (z == end()) return\
    \ y->m == x->m && y->b <= x->b;\n    return 1.0 * (x->b - y->b) * (z->m - y->m)\
    \ >=\n           1.0 * (y->b - z->b) * (y->m - x->m);\n  }\n  void insert_line(ll\
    \ m, ll b) {\n    auto y = insert({m, b});\n    y->succ = [=] { return next(y)\
    \ == end() ? 0 : &*next(y); };\n    if (bad(y)) {\n      erase(y);\n      return;\n\
    \    }\n    while (next(y) != end() && bad(next(y))) erase(next(y));\n    while\
    \ (y != begin() && bad(prev(y))) erase(prev(y));\n  }\n  ll eval(ll x) {\n   \
    \ auto l = *lower_bound((Line){x, -INF});\n    return l.m * x + l.b;\n  }\n};\n"
  code: "struct Line {\n  ll m, b;\n  mutable function<const Line*()> succ;\n  bool\
    \ operator<(const Line& rhs) const {\n    if (rhs.b != -INF) return m < rhs.m;\n\
    \    const Line* s = succ();\n    if (!s) return 0;\n    ll x = rhs.m;\n    return\
    \ b - s->b < (s->m - m) * x;\n  }\n};\n\nstruct dynamic_hull\n    : public multiset<Line>\
    \ {  // will maintain upper hull for maximum\n  bool bad(iterator y) {\n    auto\
    \ z = next(y);\n    if (y == begin()) {\n      if (z == end()) return 0;\n   \
    \   return y->m == z->m && y->b <= z->b;\n    }\n    auto x = prev(y);\n    if\
    \ (z == end()) return y->m == x->m && y->b <= x->b;\n    return 1.0 * (x->b -\
    \ y->b) * (z->m - y->m) >=\n           1.0 * (y->b - z->b) * (y->m - x->m);\n\
    \  }\n  void insert_line(ll m, ll b) {\n    auto y = insert({m, b});\n    y->succ\
    \ = [=] { return next(y) == end() ? 0 : &*next(y); };\n    if (bad(y)) {\n   \
    \   erase(y);\n      return;\n    }\n    while (next(y) != end() && bad(next(y)))\
    \ erase(next(y));\n    while (y != begin() && bad(prev(y))) erase(prev(y));\n\
    \  }\n  ll eval(ll x) {\n    auto l = *lower_bound((Line){x, -INF});\n    return\
    \ l.m * x + l.b;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dynamic_hull.hpp
  requiredBy: []
  timestamp: '2022-08-22 00:11:09+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/dynamic_hull.hpp
layout: document
title: Dynamic Line Container (Convex Hull Trick)
---
