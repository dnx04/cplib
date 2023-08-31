// matrix must be square.

template <typename T>
pair<T, vector<int>> hungarian(int n, vector<vector<T>> c) {
  assert(n == sz(c)), assert(n == sz(c[0]));
  vector<T> v(n), dist(n);
  vector<int> L(n, -1), R(m, -1);
  vector<int> index(n), prev(n);
  auto getc = [&](int i, int j) { return c[i][j] - v[j]; };

  iota(index.begin(), index.end(), 0);
  for (int f = 0; f < n; ++f) {
    for (int j = 0; j < n; ++j) {
      dist[j] = getc(f, j), prev[j] = f;
    }
    T w = 0;
    int j, l = 0, s = 0, t = 0;
    while (true) {
      if (s == t) {
        l = s, w = dist[index[t++]];
        for (int k = t; k < n; ++k) {
          j = index[k];
          T h = dist[j];
          if (h <= w) {
            if (h < w) t = s, w = h;
            index[k] = index[t], index[t++] = j;
          }
        }
        for (int k = s; k < t; ++k) {
          j = index[k];
          if (R[j] < 0) goto augment;
        }
      }
      int q = index[s++], i = R[q];
      for (int k = t; k < n; ++k) {
        j = index[k];
        T h = getc(i, j) - getc(i, q) + w;
        if (h < dist[j]) {
          dist[j] = h, prev[j] = i;
          if (h == w) {
            if (R[j] < 0) goto augment;
            index[k] = index[t], index[t++] = j;
          }
        }
      }
    }
  augment:
    for (int k = 0; k < l; ++k) v[index[k]] += dist[index[k]] - w;
    int i;
    do {
      i = R[j] = prev[j];
      swap(j, L[i]);
    } while (i != f);
  }
  T ret = 0;
  for (int i = 0; i < n; ++i) ret += c[i][L[i]];
  return {ret, L};
}