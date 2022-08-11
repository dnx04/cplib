---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: number-theory/sieve.hpp
    title: number-theory/sieve.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009
  bundledCode: "#line 1 \"number-theory/test/Prime_Number.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009\"\n\n#include\
    \ <bits/extc++.h>\n\nusing namespace std;\nusing namespace __gnu_pbds;\nusing\
    \ namespace __gnu_cxx;\n\n#line 1 \"number-theory/sieve.hpp\"\nauto sieve = [](int\
    \ n) {\n  vector<int> lpf(n + 1);\n  iota(begin(lpf), end(lpf), 0);\n  for (int\
    \ i = 2; i <= n; ++i) {\n    if (lpf[i] == i) {\n      for (long long j = 1ll\
    \ * i * i; j <= n; j += i) {\n        lpf[j] = i;\n      }\n    }\n  }\n  return\
    \ lpf;\n};\n#line 10 \"number-theory/test/Prime_Number.test.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(0);\n  vector<int> primes = sieve(1e6);\n\
    \  for (int i = 1; i <= 1e6; ++i) {\n    primes[i] = (primes[i] == i && i >= 2)\
    \ + primes[i - 1];\n  }\n  int n;\n  while (cin >> n) {\n    cout << primes[n];\n\
    \    if (cin.peek() != EOF) cout << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009\"\
    \n\n#include <bits/extc++.h>\n\nusing namespace std;\nusing namespace __gnu_pbds;\n\
    using namespace __gnu_cxx;\n\n#include \"../sieve.hpp\"\n\nsigned main() {\n \
    \ ios::sync_with_stdio(false), cin.tie(0);\n  vector<int> primes = sieve(1e6);\n\
    \  for (int i = 1; i <= 1e6; ++i) {\n    primes[i] = (primes[i] == i && i >= 2)\
    \ + primes[i - 1];\n  }\n  int n;\n  while (cin >> n) {\n    cout << primes[n];\n\
    \    if (cin.peek() != EOF) cout << '\\n';\n  }\n}"
  dependsOn:
  - number-theory/sieve.hpp
  isVerificationFile: true
  path: number-theory/test/Prime_Number.test.cpp
  requiredBy: []
  timestamp: '2022-08-11 20:11:38+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: number-theory/test/Prime_Number.test.cpp
layout: document
redirect_from:
- /verify/number-theory/test/Prime_Number.test.cpp
- /verify/number-theory/test/Prime_Number.test.cpp.html
title: number-theory/test/Prime_Number.test.cpp
---
