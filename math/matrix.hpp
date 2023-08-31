template <class T, int N>
struct matrix {
  typedef matrix M;
  array<array<T, N>, N> d{};
  M operator*(const M& m) const {
    M a;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        for (int k = 0; k < N; ++k) a.d[i][j] += d[i][k] * m.d[k][j];
    return a;
  }
  vector<T> operator*(const vector<T>& vec) const {
    vector<T> ret(N);
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; j++) ret[i] += d[i][j] * vec[j];
    return ret;
  }
  M operator^(ll p) const {
    assert(p >= 0);
    M a, b(*this);
    for (int i = 0; i < N; ++i) a.d[i][i] = 1;
    while (p) {
      if (p & 1) a = a * b;
      b = b * b;
      p >>= 1;
    }
    return a;
  }
};