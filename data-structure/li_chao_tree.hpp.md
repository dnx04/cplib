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
  bundledCode: "#line 1 \"data-structure/li_chao_tree.hpp\"\ntemplate <class T, class\
    \ T_MP>\nstruct li_chao_tree {\n  int n, head;\n  vector<T> xs;\n  li_chao_tree()\
    \ : n(0), head(0) {}\n\n  struct Line {\n    T a, b;\n    int line_idx;\n    bool\
    \ is_valid;\n    T_MP eval(T x) const noexcept { return T_MP(a) * x + b; }\n \
    \ };\n\n  vector<Line> lines;\n  struct LCR {\n    T l, c, r;\n  };\n  vector<LCR>\
    \ lcr;\n\n  void init(const vector<T> &xs): xs(xs), n(xs.size()), head(1) {\n\
    \    sort(xs.begin(), xs.end());\n    xs.erase(unique(xs.begin(), xs.end()), xs.end());\n\
    \    while (head < _n) head <<= 1;\n    lines.assign(head * 2, {0, 0, -1, false});\n\
    \    lcr.resize(head * 2);\n    for (int i = 0; i < _n; ++i) lcr[head + i] = {xs[i],\
    \ xs[i], xs[i]};\n    for (int i = head - 1; i; --i) {\n      int l = i * 2, r\
    \ = i * 2 + 1;\n      lcr[i] = {lcr[l].l, lcr[r].l, lcr[r].r};\n    }\n  }\n\n\
    \  int il, ir;\n  void rec(int now, int nowl, int nowr, Line line_add) {\n   \
    \ const int nowc = (nowl + nowr) / 2;\n\n    if (nowl >= ir or nowr <= il) {\n\
    \      return;\n    } else if (il <= nowl and nowr <= ir) {\n      if (!lines[now].is_valid)\
    \ {\n        lines[now] = line_add;\n        return;\n      }\n      bool upd_l\
    \ = lines[now].eval(lcr[now].l) > line_add.eval(lcr[now].l);\n      bool upd_c\
    \ = lines[now].eval(lcr[now].c) > line_add.eval(lcr[now].c);\n      bool upd_r\
    \ = lines[now].eval(lcr[now].r) > line_add.eval(lcr[now].r);\n      if (upd_l\
    \ and upd_c and upd_r) {\n        lines[now] = line_add;\n        return;\n  \
    \    } else if (upd_c and upd_r) {\n        swap(lines[now], line_add);\n    \
    \    rec(now * 2, nowl, nowc, line_add);\n      } else if (upd_l and upd_c) {\n\
    \        swap(lines[now], line_add);\n        rec(now * 2 + 1, nowc, nowr, line_add);\n\
    \      } else if (upd_l) {\n        rec(now * 2, nowl, nowc, line_add);\n    \
    \  } else if (upd_r) {\n        rec(now * 2 + 1, nowc, nowr, line_add);\n    \
    \  } else {\n        return;\n      }\n    } else {\n      if (il < nowc) rec(now\
    \ * 2, nowl, nowc, line_add);\n      if (ir > nowc) rec(now * 2 + 1, nowc, nowr,\
    \ line_add);\n    }\n  }\n\n  void add_line(T a, T b, int idx = -1) {\n    il\
    \ = 0, ir = _n;\n    if (il >= ir) return;\n    rec(1, 0, head, Line{a, b, idx,\
    \ true});\n  }\n  void add_segment(T xl, T xr, T a, T b, int idx = -1) {\n   \
    \ il = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();\n    ir = lower_bound(xs.begin(),\
    \ xs.end(), xr) - xs.begin();\n    if (il >= ir) return;\n    rec(1, 0, head,\
    \ Line{a, b, idx, true});\n  }\n  struct Ret {\n    T line_a, line_b;\n    int\
    \ line_idx;\n    bool is_valid;\n    T_MP minval;\n  };\n  Ret get_i(int i, T\
    \ x) {\n    i += head;\n    Line ret = lines[i];\n    T_MP val = ret.is_valid\
    \ ? ret.eval(x) : 0;\n    for (i /= 2; i; i /= 2) {\n      if (!lines[i].is_valid)\
    \ continue;\n      T_MP tmp = lines[i].eval(x);\n      if (!ret.is_valid or tmp\
    \ < val) ret = lines[i], val = tmp;\n    }\n    return {ret.a, ret.b, ret.line_idx,\
    \ ret.is_valid, val};\n  }\n\n  Ret get(T x) {\n    int i = lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n    assert(i < _n and xs[i] == x);\n    return get_i(i,\
    \ x);\n  }\n};\n"
  code: "template <class T, class T_MP>\nstruct li_chao_tree {\n  int n, head;\n \
    \ vector<T> xs;\n  li_chao_tree() : n(0), head(0) {}\n\n  struct Line {\n    T\
    \ a, b;\n    int line_idx;\n    bool is_valid;\n    T_MP eval(T x) const noexcept\
    \ { return T_MP(a) * x + b; }\n  };\n\n  vector<Line> lines;\n  struct LCR {\n\
    \    T l, c, r;\n  };\n  vector<LCR> lcr;\n\n  void init(const vector<T> &xs):\
    \ xs(xs), n(xs.size()), head(1) {\n    sort(xs.begin(), xs.end());\n    xs.erase(unique(xs.begin(),\
    \ xs.end()), xs.end());\n    while (head < _n) head <<= 1;\n    lines.assign(head\
    \ * 2, {0, 0, -1, false});\n    lcr.resize(head * 2);\n    for (int i = 0; i <\
    \ _n; ++i) lcr[head + i] = {xs[i], xs[i], xs[i]};\n    for (int i = head - 1;\
    \ i; --i) {\n      int l = i * 2, r = i * 2 + 1;\n      lcr[i] = {lcr[l].l, lcr[r].l,\
    \ lcr[r].r};\n    }\n  }\n\n  int il, ir;\n  void rec(int now, int nowl, int nowr,\
    \ Line line_add) {\n    const int nowc = (nowl + nowr) / 2;\n\n    if (nowl >=\
    \ ir or nowr <= il) {\n      return;\n    } else if (il <= nowl and nowr <= ir)\
    \ {\n      if (!lines[now].is_valid) {\n        lines[now] = line_add;\n     \
    \   return;\n      }\n      bool upd_l = lines[now].eval(lcr[now].l) > line_add.eval(lcr[now].l);\n\
    \      bool upd_c = lines[now].eval(lcr[now].c) > line_add.eval(lcr[now].c);\n\
    \      bool upd_r = lines[now].eval(lcr[now].r) > line_add.eval(lcr[now].r);\n\
    \      if (upd_l and upd_c and upd_r) {\n        lines[now] = line_add;\n    \
    \    return;\n      } else if (upd_c and upd_r) {\n        swap(lines[now], line_add);\n\
    \        rec(now * 2, nowl, nowc, line_add);\n      } else if (upd_l and upd_c)\
    \ {\n        swap(lines[now], line_add);\n        rec(now * 2 + 1, nowc, nowr,\
    \ line_add);\n      } else if (upd_l) {\n        rec(now * 2, nowl, nowc, line_add);\n\
    \      } else if (upd_r) {\n        rec(now * 2 + 1, nowc, nowr, line_add);\n\
    \      } else {\n        return;\n      }\n    } else {\n      if (il < nowc)\
    \ rec(now * 2, nowl, nowc, line_add);\n      if (ir > nowc) rec(now * 2 + 1, nowc,\
    \ nowr, line_add);\n    }\n  }\n\n  void add_line(T a, T b, int idx = -1) {\n\
    \    il = 0, ir = _n;\n    if (il >= ir) return;\n    rec(1, 0, head, Line{a,\
    \ b, idx, true});\n  }\n  void add_segment(T xl, T xr, T a, T b, int idx = -1)\
    \ {\n    il = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();\n    ir = lower_bound(xs.begin(),\
    \ xs.end(), xr) - xs.begin();\n    if (il >= ir) return;\n    rec(1, 0, head,\
    \ Line{a, b, idx, true});\n  }\n  struct Ret {\n    T line_a, line_b;\n    int\
    \ line_idx;\n    bool is_valid;\n    T_MP minval;\n  };\n  Ret get_i(int i, T\
    \ x) {\n    i += head;\n    Line ret = lines[i];\n    T_MP val = ret.is_valid\
    \ ? ret.eval(x) : 0;\n    for (i /= 2; i; i /= 2) {\n      if (!lines[i].is_valid)\
    \ continue;\n      T_MP tmp = lines[i].eval(x);\n      if (!ret.is_valid or tmp\
    \ < val) ret = lines[i], val = tmp;\n    }\n    return {ret.a, ret.b, ret.line_idx,\
    \ ret.is_valid, val};\n  }\n\n  Ret get(T x) {\n    int i = lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n    assert(i < _n and xs[i] == x);\n    return get_i(i,\
    \ x);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2022-08-22 00:11:09+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/li_chao_tree.hpp
layout: document
redirect_from:
- /library/data-structure/li_chao_tree.hpp
- /library/data-structure/li_chao_tree.hpp.html
title: data-structure/li_chao_tree.hpp
---
