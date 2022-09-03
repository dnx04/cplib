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
  bundledCode: "#line 1 \"data-structure/test/Queue_Operate_All_Composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include <bits/extc++.h>\n\nusing namespace std;\n\n#line 1 \"data-structure/swag.hpp\"\
    \ntemplate <class T, class Op>\nstruct SWAG {\n  T e;\n  Op op;\n  deque<T> dq;\n\
    \  int front;\n  T back;\n\n  SWAG(T e_, Op op_) : e(e_), op(op_) {\n    front\
    \ = 0;\n    back = e;\n  }\n\n  void push(T x) {\n    dq.push_back(x);\n    back\
    \ = op(back, x);\n  }\n\n  void pop() {\n    assert(not dq.empty());\n    dq.pop_front();\n\
    \    if (front) {\n      --front;\n    } else {\n      int len = dq.size();\n\
    \      for (int i = len - 2; i >= 0; i--) dq[i] = op(dq[i], dq[i + 1]);\n    \
    \  front = len;\n      back = e;\n    }\n  }\n\n  T sum() const { return front\
    \ ? op(dq.front(), back) : back; }\n};\n#line 1 \"number-theory/modint.hpp\"\n\
    using ll = long long;\n\ntemplate <const ll m>\nstruct Mod {\n  ll v;\n\n  Mod()\
    \ : v(0){};\n  Mod(ll _v) : v((_v + m) % m){};\n  explicit operator ll() { return\
    \ v; }\n  Mod inv() const {\n    ll a = v, b = m, ax = 1, bx = 0;\n    while (b)\
    \ {\n      ll q = a / b, t = a % b;\n      a = b, b = t, t = ax - bx * q, ax =\
    \ bx, bx = t;\n    }\n    assert(a == 1);\n    ax = (ax < 0 ? ax + m : ax);\n\
    \    return ax;\n  }\n  Mod& operator+=(const Mod& that) {\n    v = (v + that.v\
    \ >= m ? v + that.v - m : v + that.v);\n    return *this;\n  }\n  Mod& operator-=(const\
    \ Mod& that) {\n    v = (v >= that.v ? v - that.v : v + m - that.v);\n    return\
    \ *this;\n  }\n  Mod& operator*=(const Mod& that) {\n    v = v * that.v % m;\n\
    \    return *this;\n  }\n  Mod& operator/=(const Mod& that) { return (*this) *=\
    \ that.inv(); }\n  Mod operator^(ll y) {\n    if (!y) return Mod(1);\n    Mod\
    \ r = *this ^ (y >> 1);\n    r = r * r;\n    return y & 1 ? *this * r : r;\n \
    \ }\n  Mod operator+(const Mod& that) const { return Mod(*this) += that; }\n \
    \ Mod operator-(const Mod& that) const { return Mod(*this) -= that; }\n  Mod operator*(const\
    \ Mod& that) const { return Mod(*this) *= that; }\n  Mod operator/(const Mod&\
    \ that) const { return Mod(*this) /= that; }\n  bool operator==(const Mod& that)\
    \ const { return this->v == that.v; }\n  friend istream& operator>>(istream& in,\
    \ Mod& that) {\n    ll val;\n    in >> val;\n    that = Mod(val);\n    return\
    \ in;\n  }\n  friend ostream& operator<<(ostream& out, const Mod& that) {\n  \
    \  return out << that.v;\n  }\n};\n#line 9 \"data-structure/test/Queue_Operate_All_Composite.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(0);\n  using mint\
    \ = Mod<998244353>;\n  struct F {\n    mint a, b;\n  };\n  auto op = [&](F l,\
    \ F r) -> F {\n    mint na = l.a * r.a, nb = l.b * r.a + r.b;\n    return F{na,\
    \ nb};\n  };\n  SWAG<F, decltype(op)> swag(F{1, 0}, op);\n\n  int Q;\n  cin >>\
    \ Q;\n  while (Q--) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      mint\
    \ a, b;\n      cin >> a >> b;\n      swag.push(F{a, b});\n    } else if (t ==\
    \ 1) {\n      swag.pop();\n    } else {\n      mint x;\n      cin >> x;\n    \
    \  auto f = swag.sum();\n      cout << f.a * x + f.b << '\\n';\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include <bits/extc++.h>\n\nusing namespace std;\n\n#include \"../algo/data-structure/swag.hpp\"\
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
  timestamp: '2022-08-28 22:13:17+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data-structure/test/Queue_Operate_All_Composite.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/Queue_Operate_All_Composite.test.cpp
- /verify/data-structure/test/Queue_Operate_All_Composite.test.cpp.html
title: data-structure/test/Queue_Operate_All_Composite.test.cpp
---
