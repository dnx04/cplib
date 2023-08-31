pair<ll, vector<int>> get_diameter(const vector<vector<pair<int, int>>>& g) {
  int n = g.size();
  vector<ll> dist(n);
  vector<int> parent(n);

  auto dfs = [&](auto self, int u, int fu, ll cur_dist) -> void {
    dist[u] = cur_dist;
    parent[u] = fu;
    for (auto [v, cost] : g[u])
      if (v != fu) {
        self(self, v, u, cur_dist + cost);
      }
  };
  dfs(dfs, 0, -1, 0);
  // r = furthest node from root
  int r = max_element(dist.begin(), dist.end()) - dist.begin();
  dfs(dfs, r, -1, 0);
  // r->s = longest path
  int s = max_element(dist.begin(), dist.end()) - dist.begin();

  vector<int> path;
  for (int x = s; x >= 0; x = parent[x]) path.push_back(x);

  return {dist[s], path};
}