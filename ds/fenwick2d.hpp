#include "data-structure/fenwick.hpp"

template <class T>
struct fenwick2d {
  int n, m;
  vector<fenwick<T>> f;
  fenwick2d(int n, int m) : n(n), m(m), f(n + 1, fenwick<T>(m)) {}
  void add(int x, int y, T v) {
    assert(0 <= x && x < n && 0 <= y && y < m);
    ++x;
    while (x <= n) f[x].add(y, v), x += x & -x;
  }
  // add v to [x1, x2) x [y1, y2)
  void add(int x1, int y1, int x2, int y2, T v) {
    add(x1, y1, v);
    add(x1, y2, -v);
    add(x2, y1, -v);
    add(x2, y2, v);
  }
  // sum of [0, x) * [0, y)
  T sum(int x, int y) {
    T res = 0;
    while(x) res += f[x].sum(y), x -= x & -x;
    return res;
  }
  // sum of [x1, x2) * [y1, y2)
  T sum(int x1, int y1, int x2, int y2) {
    return sum(x2, y2) - sum(x1, y2) - sum(x2, y1) + sum(x1, y1);
  }
};