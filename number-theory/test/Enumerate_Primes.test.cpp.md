---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number-theory/bitset_sieve.hpp
    title: Sieve of Eratosthenes (using bitset)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"number-theory/test/Enumerate_Primes.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#include <bits/extc++.h>\n\
    \nusing namespace std;\nusing namespace __gnu_cxx;\nusing namespace __gnu_pbds;\n\
    \nusing ll = long long;\n\n#line 1 \"number-theory/bitset_sieve.hpp\"\ntemplate\
    \ <int LIMN>\nstruct bitset_sieve {\n  vector<int> primes;\n  bitset<LIMN + 1>\
    \ is_prime;\n  const int maxN;\n  bitset_sieve(int MAXN = LIMN) : maxN(MAXN) {\n\
    \    is_prime.set();\n    is_prime.reset(0), is_prime.reset(1);\n    for (int\
    \ p = 2; p <= MAXN; p++) {\n      if (is_prime[p]) {\n        primes.push_back(p);\n\
    \        for (int j = p * 2; j <= MAXN; j += p) is_prime[j] = 0;\n      }\n  \
    \  }\n  }\n  // Count primes less than or equal to x\n  int prime_counting(int\
    \ x) {\n    assert(x <= maxN);\n    return distance(primes.begin(),\n        \
    \            upper_bound(primes.begin(), primes.end(), x));\n  }\n};\n#line 12\
    \ \"number-theory/test/Enumerate_Primes.test.cpp\"\n\nvoid solve(int ith) {\n\
    \  int n, a, b;\n  cin >> n >> a >> b;\n  bitset_sieve<int(5e8 + 1)> sieve(n);\n\
    \  vector<int> ans;\n  for (int i = 0; a * i + b < (int)sieve.primes.size(); ++i)\n\
    \    ans.push_back(sieve.primes[a * i + b]);\n  cout << sieve.primes.size() <<\
    \ ' ' << ans.size() << '\\n';\n  for (auto v : ans) cout << v << ' ';\n}\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include <bits/extc++.h>\n\nusing namespace std;\nusing namespace __gnu_cxx;\n\
    using namespace __gnu_pbds;\n\nusing ll = long long;\n\n#include \"number-theory/bitset_sieve.hpp\"\
    \n\nvoid solve(int ith) {\n  int n, a, b;\n  cin >> n >> a >> b;\n  bitset_sieve<int(5e8\
    \ + 1)> sieve(n);\n  vector<int> ans;\n  for (int i = 0; a * i + b < (int)sieve.primes.size();\
    \ ++i)\n    ans.push_back(sieve.primes[a * i + b]);\n  cout << sieve.primes.size()\
    \ << ' ' << ans.size() << '\\n';\n  for (auto v : ans) cout << v << ' ';\n}\n\n\
    signed main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}"
  dependsOn:
  - number-theory/bitset_sieve.hpp
  isVerificationFile: true
  path: number-theory/test/Enumerate_Primes.test.cpp
  requiredBy: []
  timestamp: '2022-09-30 00:07:15+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: number-theory/test/Enumerate_Primes.test.cpp
layout: document
redirect_from:
- /verify/number-theory/test/Enumerate_Primes.test.cpp
- /verify/number-theory/test/Enumerate_Primes.test.cpp.html
title: number-theory/test/Enumerate_Primes.test.cpp
---
