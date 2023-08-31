// Usage:
// MaxFlow flow(n)
// For each edge: flow.addEdge(u, v, c, edge_id)  // edge_id for trace
// flow.getMaxFlow(s, t)
// flow.trace() --> edges in minimum cut
// Index from 0

const int INF = 1e9;

struct Edge {
  int a, b, cap, flow, id;
};

struct Dinic {
  int n, s, t;
  vector<int> d, ptr, q;
  vector<Edge> e;
  vector<vector<int> > g;

  Dinic(int n) : n(n), d(n), ptr(n), q(n), g(n) {
    e.clear();
    for (int i = 0; i < n; ++i) {
      g[i].clear();
      ptr[i] = 0;
    }
  }

  void add_edge(int a, int b, int cap, int id) {  // one-direction
    Edge e1 = {a, b, cap, 0, id};
    Edge e2 = {b, a, 0, 0, id};
    g[a].push_back((int)e.size());
    e.push_back(e1);
    g[b].push_back((int)e.size());
    e.push_back(e2);
  }
  int maxflow(int _s, int _t) {
    s = _s;
    t = _t;
    int flow = 0;
    for (;;) {
      if (!bfs()) break;
      fill(all(ptr), 0);
      while (int pushed = dfs(s, INF)) flow += pushed;
    }
    return flow;
  }

  vector<int> trace() {
    bfs();
    vector<int> res;
    for (auto edge : e) {
      if (d[edge.a] >= 0 && d[edge.b] < 0 && edge.cap > 0) {
        res.push_back(edge.id);
      }
    }
    return res;
  }

 private:
  bool bfs() {
    int qh = 0, qt = 0;
    q[qt++] = s;
    fill(all(d), -1);
    d[s] = 0;

    while (qh < qt && d[t] == -1) {
      int v = q[qh++];
      for(auto id: g[v]) {
        int to = e[id].b;
        if (d[to] == -1 && e[id].flow < e[id].cap) {
          q[qt++] = to;
          d[to] = d[v] + 1;
        }
      }
    }
    return d[t] != -1;
  }

  int dfs(int v, int flow) {
    if (!flow) return 0;
    if (v == t) return flow;
    for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
      int id = g[v][ptr[v]], to = e[id].b;
      if (d[to] != d[v] + 1) continue;
      int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
      if (pushed) {
        e[id].flow += pushed;
        e[id ^ 1].flow -= pushed;
        return pushed;
      }
    }
    return 0;
  }
};