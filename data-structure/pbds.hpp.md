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
  bundledCode: "#line 2 \"data-structure/pbds.hpp\"\n\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tag_and_trait.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    \nusing namespace __gnu_pbds;  // find_by_order(), order_of_key()\ntemplate <typename\
    \ TK>\nusing pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag,\n         \
    \             tree_order_statistics_node_update>;\ntemplate <typename TK, typename\
    \ TV>\nusing pbds_map =\n    tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;\n"
  code: "#pragma once\n\n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tag_and_trait.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n\nusing namespace __gnu_pbds;  // find_by_order(),\
    \ order_of_key()\ntemplate <typename TK>\nusing pbds_set = tree<TK, null_type,\
    \ less<TK>, rb_tree_tag,\n                      tree_order_statistics_node_update>;\n\
    template <typename TK, typename TV>\nusing pbds_map =\n    tree<TK, TV, less<TK>,\
    \ rb_tree_tag, tree_order_statistics_node_update>;"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/pbds.hpp
  requiredBy: []
  timestamp: '2022-09-04 10:50:22+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/pbds.hpp
layout: document
redirect_from:
- /library/data-structure/pbds.hpp
- /library/data-structure/pbds.hpp.html
title: data-structure/pbds.hpp
---
