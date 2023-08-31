// return a vector contains indices of the LIS
template <typename T>
vector<int> lis(const vector<T>& a) {
  int n = (int)a.size();
  vector<int> b(n + 1, 0), f(n, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    f[i] = lower_bound(begin(b) + 1, begin(b) + ans + 1, a[i]) - begin(b);
    ans = max(ans, f[i]);
    b[f[i]] = a[i];
  }
  int req = ans;
  vector<int> res;
  for (int i = n - 1; i >= 0; i--) {
    if (f[i] == req) {
      res.push_back(i);
      --req;
    }
  }
  reverse(begin(res), end(res));
  return res;
}