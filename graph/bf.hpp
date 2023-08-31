auto negcycle_check = [&]() {
  int x = -1;
  for (int i = 0; i < n; ++i) {
    x = -1;
    for (auto &e : edges) {
      if (dist[e.a] + e.w < dist[e.b]) {
        dist[e.b] = dist[e.a] + e.w;
        par[e.b] = e.a;
        x = e.b;
      }
    }
  }
  if (x == -1)
    cout << "NO";
  else {
    cout << "YES\n";
    for (int i = 0; i < n; ++i) x = par[x];
    vector<int> path;
    for (int v = x;; v = par[v]) {
      path.push_back(v);
      if (v == x && sz(path) > 1) break;
    }
    reverse(all(path));
    for (auto &v : path) cout << v + 1 << ' ';
  }
};