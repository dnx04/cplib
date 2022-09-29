---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: number-theory/test/Enumerate_Primes.test.cpp
    title: number-theory/test/Enumerate_Primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"number-theory/bitset_sieve.hpp\"\ntemplate <int LIMN>\n\
    struct bitset_sieve {\n  vector<int> primes;\n  bitset<LIMN + 1> is_prime;\n \
    \ const int maxN;\n  bitset_sieve(int MAXN = LIMN) : maxN(MAXN) {\n    is_prime.set();\n\
    \    is_prime.reset(0), is_prime.reset(1);\n    for (int p = 2; p <= MAXN; p++)\
    \ {\n      if (is_prime[p]) {\n        primes.push_back(p);\n        for (int\
    \ j = p * 2; j <= MAXN; j += p) is_prime[j] = 0;\n      }\n    }\n  }\n  // Count\
    \ primes less than or equal to x\n  int prime_counting(int x) {\n    assert(x\
    \ <= maxN);\n    return distance(primes.begin(),\n                    upper_bound(primes.begin(),\
    \ primes.end(), x));\n  }\n};\n"
  code: "template <int LIMN>\nstruct bitset_sieve {\n  vector<int> primes;\n  bitset<LIMN\
    \ + 1> is_prime;\n  const int maxN;\n  bitset_sieve(int MAXN = LIMN) : maxN(MAXN)\
    \ {\n    is_prime.set();\n    is_prime.reset(0), is_prime.reset(1);\n    for (int\
    \ p = 2; p <= MAXN; p++) {\n      if (is_prime[p]) {\n        primes.push_back(p);\n\
    \        for (int j = p * 2; j <= MAXN; j += p) is_prime[j] = 0;\n      }\n  \
    \  }\n  }\n  // Count primes less than or equal to x\n  int prime_counting(int\
    \ x) {\n    assert(x <= maxN);\n    return distance(primes.begin(),\n        \
    \            upper_bound(primes.begin(), primes.end(), x));\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: number-theory/bitset_sieve.hpp
  requiredBy: []
  timestamp: '2022-09-30 00:07:15+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - number-theory/test/Enumerate_Primes.test.cpp
documentation_of: number-theory/bitset_sieve.hpp
layout: document
title: Sieve of Eratosthenes (using bitset)
---
