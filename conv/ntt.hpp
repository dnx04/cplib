#include "utility/static_modulo.hpp"

// NTT modulo 998244353. If change modulo, change these parameters accordingly
using Fp = static_modulo<998244353>;
Fp G = 3;

void ntt(vector<Fp>& a, bool invert) {
  int n = int(a.size()), s = 0;
  while ((1 << s) < n) s++;
  assert(1 << s == n);

  static vector<Fp> ep, iep;
  while (int(ep.size()) <= s) {
    ep.push_back(G.pow((Fp(-1) / (1 << ep.size())).get()));
    iep.push_back(ep.back().inv());
  }
  vector<Fp> b(n);
  for (int i = 1; i <= s; i++) {
    int w = 1 << (s - i);
    Fp base = invert ? iep[i] : ep[i], now = 1;
    for (int y = 0; y < n / 2; y += w) {
      for (int x = 0; x < w; x++) {
        auto l = a[y << 1 | x];
        auto r = now * a[y << 1 | x | w];
        b[y | x] = l + r;
        b[y | x | n >> 1] = l - r;
      }
      now *= base;
    }
    swap(a, b);
  }
  if (invert)
    for (auto& x : a) x /= n;
}

vector<Fp> nttconv(vector<Fp> const& a, vector<Fp> const& b) {
  vector<Fp> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < int(a.size() + b.size())) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  ntt(fa, false);
  ntt(fb, false);
  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  ntt(fa, true);
  fa.resize(int(a.size() + b.size() - 1));
  return fa;
}