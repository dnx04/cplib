---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/swag.hpp
    title: data-structure/swag.hpp
  - icon: ':heavy_check_mark:'
    path: utility/static_modulo.hpp
    title: utility/static_modulo.hpp
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
    \ ? op(dq.front(), back) : back; }\n};\n#line 2 \"utility/static_modulo.hpp\"\n\
    \ntemplate <int mod>\nstruct static_modulo {\n  using Fp = static_modulo;\n\n\
    \ private:\n  int x;\n\n public:\n  static_modulo() : x(0) {}\n  static_modulo(int64_t\
    \ y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n  Fp &operator+=(const\
    \ Fp &p) {\n    if ((x += p.x) >= mod) x -= mod;\n    return *this;\n  }\n  Fp\
    \ &operator-=(const Fp &p) {\n    if ((x += mod - p.x) >= mod) x -= mod;\n   \
    \ return *this;\n  }\n  Fp &operator*=(const Fp &p) {\n    x = (int)(1ll * x *\
    \ p.x % mod);\n    return *this;\n  }\n  Fp &operator/=(const Fp &p) {\n    *this\
    \ *= p.inv();\n    return *this;\n  }\n  Fp operator-() const { return Fp(-x);\
    \ }\n  Fp operator+(const Fp &p) const { return Fp(*this) += p; }\n  Fp operator-(const\
    \ Fp &p) const { return Fp(*this) -= p; }\n  Fp operator*(const Fp &p) const {\
    \ return Fp(*this) *= p; }\n  Fp operator/(const Fp &p) const { return Fp(*this)\
    \ /= p; }\n  bool operator==(const Fp &p) const { return x == p.x; }\n  bool operator!=(const\
    \ Fp &p) const { return x != p.x; }\n  Fp inv() const {\n    int a = x, b = mod,\
    \ u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b);\n      swap(u -= t * v, v);\n    }\n    return Fp(u);\n  }\n  Fp pow(int64_t\
    \ n) const {\n    Fp ret(1), mul(x);\n    while (n > 0) {\n      if (n & 1) ret\
    \ *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n  friend\
    \ ostream &operator<<(ostream &os, const Fp &p) { return os << p.x; }\n  friend\
    \ istream &operator>>(istream &is, Fp &a) {\n    int64_t t;\n    is >> t;\n  \
    \  a = static_modulo<mod>(t);\n    return (is);\n  }\n  int get() const { return\
    \ x; }\n  static constexpr int get_mod() { return mod; }\n};\n#line 9 \"data-structure/test/Queue_Operate_All_Composite.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(0);\n  using Fp =\
    \ static_modulo<998244353>;\n  struct F {\n    Fp a, b;\n  };\n  auto op = [&](F\
    \ l, F r) -> F {\n    Fp na = l.a * r.a, nb = l.b * r.a + r.b;\n    return F{na,\
    \ nb};\n  };\n  SWAG<F, decltype(op)> swag(F{1, 0}, op);\n\n  int Q;\n  cin >>\
    \ Q;\n  while (Q--) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      Fp\
    \ a, b;\n      cin >> a >> b;\n      swag.push(F{a, b});\n    } else if (t ==\
    \ 1) {\n      swag.pop();\n    } else {\n      Fp x;\n      cin >> x;\n      auto\
    \ f = swag.sum();\n      cout << f.a * x + f.b << '\\n';\n    }\n  }\n}\n"
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
  dependsOn:
  - data-structure/swag.hpp
  - utility/static_modulo.hpp
  isVerificationFile: true
  path: data-structure/test/Queue_Operate_All_Composite.test.cpp
  requiredBy: []
  timestamp: '2022-09-27 22:26:49+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data-structure/test/Queue_Operate_All_Composite.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/Queue_Operate_All_Composite.test.cpp
- /verify/data-structure/test/Queue_Operate_All_Composite.test.cpp.html
title: data-structure/test/Queue_Operate_All_Composite.test.cpp
---
