// RMQ using Sparse Table
// range_min for min, range_max for max

template <class T, T (*op)(T, T)>
struct rmq {
  rmq() = default;
  rmq(const vector<T>& v) : t{v}, n{(int)v.size()} {
    for (int k = 1; (1 << k) <= n; ++k) {
      t.emplace_back(n - (1 << k) + 1);
      for (int i = 0; i + (1 << k) <= n; ++i) {
        t[k][i] = op(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);
      }
    }
  }

  // get range [l, r-1]
  // doesn't work for empty range
  T get(int l, int r) const {
    assert(0 <= l && l < r && r <= n);
    int k = __lg(r - l);
    return op(t[k][l], t[k][r - (1 << k)]);
  }

 private:
  vector<vector<T>> t;
  int n;
};

template <class T>
T range_min(T a, T b) {
  return b < a ? b : a;
}
template <class T>
T range_max(T a, T b) {
  return a < b ? b : a;
}
