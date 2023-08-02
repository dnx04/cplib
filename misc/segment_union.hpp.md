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
  bundledCode: "#line 1 \"misc/segment_union.hpp\"\nauto segment_union = [](vector<pair<int,\
    \ int>> &segs) {\n  sort(segs.begin(), segs.end());\n  vector<pair<int, int>>\
    \ res, lr;\n  for (auto &[u, v] : segs) {\n    lr.emplace_back(u, 0);\n    lr.emplace_back(v\
    \ + 1, 1);\n  }\n  stack<int> st;\n  sort(lr.begin(), lr.end());\n  for (auto\
    \ &[x, t] : lr) {\n    if (t == 0) {\n      st.push(x);\n    } else {\n      if\
    \ (st.size() == 1) {\n        res.emplace_back(st.top(), x - 1);\n      }\n  \
    \    st.pop();\n    }\n  }\n  return res;\n};\n"
  code: "auto segment_union = [](vector<pair<int, int>> &segs) {\n  sort(segs.begin(),\
    \ segs.end());\n  vector<pair<int, int>> res, lr;\n  for (auto &[u, v] : segs)\
    \ {\n    lr.emplace_back(u, 0);\n    lr.emplace_back(v + 1, 1);\n  }\n  stack<int>\
    \ st;\n  sort(lr.begin(), lr.end());\n  for (auto &[x, t] : lr) {\n    if (t ==\
    \ 0) {\n      st.push(x);\n    } else {\n      if (st.size() == 1) {\n       \
    \ res.emplace_back(st.top(), x - 1);\n      }\n      st.pop();\n    }\n  }\n \
    \ return res;\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/segment_union.hpp
  requiredBy: []
  timestamp: '2023-08-02 22:18:29+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/segment_union.hpp
layout: document
redirect_from:
- /library/misc/segment_union.hpp
- /library/misc/segment_union.hpp.html
title: misc/segment_union.hpp
---
