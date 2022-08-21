---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/splay.hpp
    title: data-structure/splay.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <bits/extc++.h>\n\nusing namespace std;\nusing namespace __gnu_cxx;\n\
    using namespace __gnu_pbds;\n\n#line 1 \"number-theory/modint.hpp\"\nusing ll\
    \ = long long;\ntemplate <const ll m>\nstruct Mod {\n  ll v;\n\n  Mod() : v(0){};\n\
    \  Mod(ll _v) : v((_v + m) % m){};\n  explicit operator ll() { return v; }\n \
    \ Mod inv() const {\n    ll a = v, b = m, ax = 1, bx = 0;\n    while (b) {\n \
    \     ll q = a / b, t = a % b;\n      a = b, b = t, t = ax - bx * q, ax = bx,\
    \ bx = t;\n    }\n    assert(a == 1);\n    ax = (ax < 0 ? ax + m : ax);\n    return\
    \ ax;\n  }\n  Mod& operator+=(const Mod& that) {\n    v = (v + that.v >= m ? v\
    \ + that.v - m : v + that.v);\n    return *this;\n  }\n  Mod& operator-=(const\
    \ Mod& that) {\n    v = (v >= that.v ? v - that.v : v + m - that.v);\n    return\
    \ *this;\n  }\n  Mod& operator*=(const Mod& that) {\n    v = v * that.v % m;\n\
    \    return *this;\n  }\n  Mod& operator/=(const Mod& that) { return (*this) *=\
    \ that.inv(); }\n  Mod operator^(ll y) {\n    if (!y) return Mod(1);\n    Mod\
    \ r = *this ^ (y >> 1);\n    r = r * r;\n    return y & 1 ? *this * r : r;\n \
    \ }\n  Mod operator+(const Mod& that) const { return Mod(*this) += that; }\n \
    \ Mod operator-(const Mod& that) const { return Mod(*this) -= that; }\n  Mod operator*(const\
    \ Mod& that) const { return Mod(*this) *= that; }\n  Mod operator/(const Mod&\
    \ that) const { return Mod(*this) /= that; }\n  friend istream& operator>>(istream&\
    \ in, Mod& that) {\n    ll val;\n    in >> val;\n    that = Mod(val);\n    return\
    \ in;\n  }\n  friend ostream& operator<<(ostream& out, const Mod& that) {\n  \
    \  return out << that.v;\n  }\n};\n#line 1 \"data-structure/splay.hpp\"\ntemplate\
    \ <class K, class S, class F>\nstruct node_t {\n  using Node = node_t<K, S, F>;\n\
    \n  array<Node *, 2> child;\n  Node *father;\n  int size;\n  bool reverse;\n\n\
    \  K key;\n  S data;\n  F lazy;\n};\ntemplate <class K,            // key\n  \
    \        class S,            // node aggregate data\n          S (*op)(S, K, S),\
    \   // for recomputing data of a node\n          pair<K, S> (*e)(),  // identity\
    \ data\n          class F,            // lazy propagation tag\n          pair<K,\
    \ S> (*mapping)(F, node_t<K, S, F> *),  // apply tag F on a node\n          F\
    \ (*composition)(F, F),                       // combine 2 tags\n          F (*id)()\
    \                                     // identity tag\n          >\nstruct splay_tree\
    \ {\n  using Node = node_t<K, S, F>;\n\n  Node *nil, *root;\n\n  splay_tree()\
    \ {\n    initNil();\n    root = nil;\n  }\n  splay_tree(const vector<K> &keys)\
    \ {\n    initNil();\n    root = createNode(keys, 0, (int)keys.size());\n  }\n\n\
    \  vector<K> get_keys() {\n    vector<K> keys;\n    traverse(root, keys);\n  \
    \  return keys;\n  }\n\n  // k in [0, n-1]\n  Node *kth(int k) {\n    auto res\
    \ = _kth(root, k);\n    splay(res);\n    root = res;\n    return res;\n  }\n\n\
    \  // Return <L, R>:\n  // - L contains [0, k-1]\n  // - R contains [k, N-1]\n\
    \  // Modify tree\n  pair<Node *, Node *> cut(int k) {\n    if (k == 0) {\n  \
    \    return {nil, root};\n    } else if (k == root->size) {\n      return {root,\
    \ nil};\n    } else {\n      Node *left = kth(k - 1);  // kth already splayed\n\
    \      Node *right = left->child[1];\n      left->child[1] = right->father = nil;\n\
    \      pushUp(left);\n      return {left, right};\n    }\n  }\n\n  // Return <X,\
    \ Y, Z>:\n  // - X contains [0, u-1]\n  // - Y contains [u, v-1]\n  // - Z contains\
    \ [v, N-1]\n  // This is useful for queries on [u, v-1]\n  // Modify tree\n  tuple<Node\
    \ *, Node *, Node *> cut(int u, int v) {\n    auto [xy, z] = cut(v);\n    root\
    \ = xy;\n    auto [x, y] = cut(u);\n    return {x, y, z};\n  }\n\n  // Make this\
    \ tree x + y\n  void join(Node *x, Node *y) {\n    if (x == nil) {\n      root\
    \ = y;\n      return;\n    }\n    while (1) {\n      pushDown(x);\n      if (x->child[1]\
    \ == nil) break;\n      x = x->child[1];\n    }\n    splay(x);\n    setChild(x,\
    \ y, 1);\n    pushUp(x);\n    root = x;\n  }\n\n  // reverse range [u, v-1]\n\
    \  void reverse(int u, int v) {\n    assert(0 <= u && u <= v && v <= root->size);\n\
    \    if (u == v) return;\n\n    auto [x, y, z] = cut(u, v);\n    y->reverse =\
    \ true;\n    join(x, y);\n    join(root, z);\n  }\n\n  // apply F on range [u,\
    \ v-1]\n  void apply(int u, int v, const F &f) {\n    assert(0 <= u && u <= v\
    \ && v <= root->size);\n    if (u == v) return;\n\n    auto [x, y, z] = cut(u,\
    \ v);\n    y->lazy = composition(f, y->lazy);\n    tie(y->key, y->data) = mapping(f,\
    \ y);\n\n    join(x, y);\n    join(root, z);\n  }\n\n  // Insert before pos\n\
    \  // pos in [0, N]\n  void insert(int pos, K key) {\n    assert(0 <= pos && pos\
    \ <= root->size);\n    // x: [0, pos-1]\n    // y: [pos, N-1]\n    auto [x, y]\
    \ = cut(pos);\n    auto node = createNode(key);\n    setChild(node, x, 0);\n \
    \   setChild(node, y, 1);\n    pushUp(node);\n    root = node;\n  }\n\n  // Delete\
    \ pos; pos in [0, N-1]\n  K erase(int pos) {\n    assert(0 <= pos && pos < root->size);\n\
    \n    // x = [0, pos-1]\n    // y = [pos, pos]\n    // z = [pos+1, N-1]\n    auto\
    \ [x, y, z] = cut(pos, pos + 1);\n    join(x, z);\n    return y->key;\n  }\n\n\
    \  // aggregated data of range [l, r-1]\n  S prod(int l, int r) {\n    auto [x,\
    \ y, z] = cut(l, r);\n    auto res = y->data;\n    join(x, y);\n    join(root,\
    \ z);\n    return res;\n  }\n\n private:\n  void initNil() {\n    nil = new Node();\n\
    \    nil->child[0] = nil->child[1] = nil->father = nil;\n    nil->size = 0;\n\
    \    nil->reverse = false;\n    tie(nil->key, nil->data) = e();\n    nil->lazy\
    \ = id();\n  }\n  void pushUp(Node *x) {\n    if (x == nil) return;\n    x->size\
    \ = x->child[0]->size + x->child[1]->size + 1;\n    x->data = op(x->child[0]->data,\
    \ x->key, x->child[1]->data);\n  }\n  void pushDown(Node *x) {\n    if (x == nil)\
    \ return;\n\n    if (x->reverse) {\n      for (auto c : x->child) {\n        if\
    \ (c != nil) {\n          c->reverse ^= 1;\n        }\n      }\n      swap(x->child[0],\
    \ x->child[1]);\n      x->reverse = false;\n    }\n\n    for (auto c : x->child)\
    \ {\n      if (c != nil) {\n        tie(c->key, c->data) = mapping(x->lazy, c);\n\
    \        c->lazy = composition(x->lazy, c->lazy);\n      }\n      // For problem\
    \ like UPIT, where we want to push different\n      // lazy tags to left & right\
    \ children, may need to modify\n      // code here\n      // (query L R X: a(L)\
    \ += X, a(L+1) += 2X, ...)\n      // e.g. for UPIT:\n      // x->lazy.add_left\
    \ += (1 + c->size) * x->lazy.step;\n    }\n\n    x->lazy = id();\n  }\n  Node\
    \ *createNode(K key) {\n    Node *res = new Node();\n    res->child[0] = res->child[1]\
    \ = res->father = nil;\n    res->key = key;\n    res->size = 1;\n    res->data\
    \ = e().second;\n    res->lazy = id();\n    return res;\n  }\n  void setChild(Node\
    \ *x, Node *y, int d) {\n    x->child[d] = y;\n    if (y != nil) y->father = x;\n\
    \  }\n  // Assumption: x is father of y\n  int getDirection(Node *x, Node *y)\
    \ {\n    assert(y->father == x);\n    return x->child[0] == y ? 0 : 1;\n  }\n\
    \  // create subtree from keys[l, r-1]\n  Node *createNode(const vector<K> &keys,\
    \ int l, int r) {\n    if (l >= r) {  // empty\n      return nil;\n    }\n   \
    \ int mid = (l + r) / 2;\n    Node *p = createNode(keys[mid]);\n    Node *left\
    \ = createNode(keys, l, mid);\n    Node *right = createNode(keys, mid + 1, r);\n\
    \n    setChild(p, left, 0);\n    setChild(p, right, 1);\n\n    pushUp(p);\n  \
    \  return p;\n  }\n  void traverse(Node *x, vector<K> &keys) {\n    if (x == nil)\
    \ return;\n    pushDown(x);\n    traverse(x->child[0], keys);\n    keys.push_back(x->key);\n\
    \    traverse(x->child[1], keys);\n  }\n\n  void rotate(Node *x, int d) {\n  \
    \  Node *y = x->father;\n    Node *z = x->child[d];\n    setChild(x, z->child[d\
    \ ^ 1], d);\n    setChild(y, z, getDirection(y, x));\n    setChild(z, x, d ^ 1);\n\
    \    pushUp(x);\n    pushUp(z);\n  }\n  // Make x root of tree\n  Node *splay(Node\
    \ *x) {\n    if (x == nil) return nil;\n    while (x->father != nil) {\n     \
    \ Node *y = x->father;\n      Node *z = y->father;\n      int dy = getDirection(y,\
    \ x);\n      int dz = getDirection(z, y);\n      if (z == nil) {\n        rotate(y,\
    \ dy);\n      } else if (dy == dz) {\n        rotate(z, dz);\n        rotate(y,\
    \ dy);\n      } else {\n        rotate(y, dy);\n        rotate(z, dz);\n     \
    \ }\n    }\n    return x;\n  }\n\n  Node *_kth(Node *p, int k) {\n    pushDown(p);\n\
    \    // left: [0, left->size - 1]\n    if (k < p->child[0]->size) {\n      return\
    \ _kth(p->child[0], k);\n    }\n    k -= p->child[0]->size;\n    if (!k) return\
    \ p;\n    return _kth(p->child[1], k - 1);\n  }\n};\n#line 12 \"data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp\"\
    \n\nusing mint = Mod<998244353>;\n\nstruct S {\n  mint sum;\n  int sz;\n};\n\n\
    struct F {\n  mint a, b;\n};\n\nusing Node = node_t<mint, S, F>;\n\nS op(S left,\
    \ mint key, S right) {\n  return S{left.sum + key + right.sum, left.sz + 1 + right.sz};\n\
    };\npair<mint, S> e() { return {0, {0, 0}}; }\npair<mint, S> mapping(F f, Node*\
    \ node) {\n  return {(f.a * node->key + f.b),\n          S{f.a * node->data.sum\
    \ + f.b * node->data.sz, node->data.sz}};\n}\nF composition(F f, F g) { return\
    \ F{f.a * g.a, f.a * g.b + f.b}; }\nF id() { return F{1, 0}; }\n\nvoid solve([[maybe_unused]]\
    \ int ith) {\n  int n, q;\n  cin >> n >> q;\n  splay_tree<mint, S, op, e, F, mapping,\
    \ composition, id> st;\n  for (int i = 0; i < n; ++i) {\n    int x;\n    cin >>\
    \ x;\n    st.insert(i, x);\n  }\n  while (q--) {\n    int t;\n    cin >> t;\n\
    \    if (t == 0) {\n      int pos, val;\n      cin >> pos >> val;\n      st.insert(pos,\
    \ val);\n    } else if (t == 1) {\n      int pos;\n      cin >> pos;\n      st.erase(pos);\n\
    \    } else if (t == 2) {\n      int l, r;\n      cin >> l >> r;\n      st.reverse(l,\
    \ r);\n    } else if (t == 3) {\n      int l, r, a, b;\n      cin >> l >> r >>\
    \ a >> b;\n      st.apply(l, r, F{a, b});\n    } else {\n      int l, r;\n   \
    \   cin >> l >> r;\n      cout << st.prod(l, r).sum << '\\n';\n    }\n  }\n}\n\
    \nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr), cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) solve(i);\n}\n"
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
  dependsOn:
  - number-theory/modint.hpp
  - data-structure/splay.hpp
  isVerificationFile: true
  path: data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2022-08-20 00:16:10+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
- /verify/data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp.html
title: data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
---
