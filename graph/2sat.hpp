#include "scc.hpp"

struct twosat : scc {
  int n;
  twosat(int n) : scc(2 * n), n(n) {}

  // add 2-SAT clause
  void add_clause(bool is_x_true, int x, bool is_y_true, int y) {
    assert(x >= 0 && x < n);
    assert(y >= 0 && y < n);
    if (!is_x_true) x += n;
    if (!is_y_true) y += n;
    // x || y
    // !x -> y
    // !y -> x
    add_edge((x + n) % (2 * n), y);
    add_edge((y + n) % (2 * n), x);
  }

  // Returns:
  // If no sol -> returns {false, {}}
  // If has sol -> returns {true, sol}
  //    where |sol| = n, sol = true / false
  pair<bool, vector<bool>> solve() {
    build();
    vector<bool> sol(n);
    for (int i = 0; i < n; i++) {
      if (id[i] == id[i + n]) {
        return {false, {}};
      }
      sol[i] = id[i] < id[i + n];
    }
    return {true, sol};
  }
};