// calculate optimum of a function using divide and conquer
auto dnc = [&](auto dnc, int l, int r, int optl, int optr) {
  if (l > r) return;

  int mid = (l + r) >> 1;
  pair<ll, ll> best = {INF, -1};

  for (int k = optl; k <= min(mid, optr); k++) {
    best = min(best, {(k ? dp[k - 1] : 0) + C(k, mid), k});
  }

  ndp[mid] = best.first;
  int opt = best.second;

  dnc(dnc, l, mid - 1, optl, opt);
  dnc(dnc, mid + 1, r, opt, optr);
};