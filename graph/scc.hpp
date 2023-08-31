struct scc {
  vector<vector<int>> g;
  int n;
  vector<int> num, low, current, S;
  int counter;
  vector<int> id;
  vector<vector<int>> scc_list;

  scc(int n)
      : g(n),
        n(n),
        num(n, -1),
        low(n, 0),
        current(n, 0),
        counter(0),
        id(n, -1) {}

  void add_edge(int u, int v) { g[u].push_back(v); }

  void dfs(int u) {
    low[u] = num[u] = counter++;
    S.push_back(u);
    current[u] = 1;
    for (auto v : g[u]) {
      if (num[v] == -1) dfs(v);
      if (current[v]) low[u] = min(low[u], low[v]);
    }
    if (low[u] == num[u]) {
      scc_list.push_back(vector<int>());
      while (1) {
        int v = S.back();
        S.pop_back();
        current[v] = 0;
        scc_list.back().push_back(v);
        id[v] = (int)scc_list.size() - 1;
        if (u == v) break;
      }
    }
  }

  // build scc_list
  void build() {
    for (int i = 0; i < n; i++) {
      if (num[i] == -1) dfs(i);
    }
    reverse(begin(scc_list), end(scc_list));
  }

  // build DAG of strongly connected components
  // Returns: adjacency list of DAG, and root vertices (in-degree
  // = 0)
  pair<vector<vector<int>>, vector<int>> condense() {
    vector<vector<int>> dag(scc_list.size());
    vector<int> roots, in(scc_list.size());
    for (int u = 0; u < n; ++u) {
      int x = id[u];
      for (int v : g[u]) {
        int y = id[v];
        if (x != y) {
          dag[x].push_back(y);
          ++in[y];
        }
      }
    }
    for (int u = 0; u < (int)dag.size(); ++u)
      if (in[u] == 0) roots.push_back(u);
    return {dag, roots};
  }
};