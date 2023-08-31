template <typename Fp>
vector<Fp> berlekamp_massey(const vector<Fp> &s) {
  const int N = (int)s.size();
  vector<Fp> b, c;
  b.reserve(N + 1);
  c.reserve(N + 1);
  b.push_back(Fp(1));
  c.push_back(Fp(1));
  Fp y = Fp(1);
  for (int ed = 1; ed <= N; ed++) {
    int l = int(c.size()), m = int(b.size());
    Fp x = 0;
    for (int i = 0; i < l; i++) x += c[i] * s[ed - l + i];
    b.emplace_back(Fp(0));
    m++;
    if (x == Fp(0)) continue;
    Fp freq = x / y;
    if (l < m) {
      auto tmp = c;
      c.insert(begin(c), m - l, Fp(0));
      for (int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];
      b = tmp;
      y = x;
    } else {
      for (int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];
    }
  }
  reverse(begin(c), end(c));
  return c;
}