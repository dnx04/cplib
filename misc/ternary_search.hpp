// optimizing convex/concave functions

auto ternary_search = [&](int low, int high, auto f) {
  while (high - low > 2) {
    const int m1 = (low + high) / 2;
    const int m2 = m1 + 1;
    if (f(m1) < f(m2)) {
      low = m1;
    } else {
      high = m2;
    }
  }
  return {low + 1, f(low + 1)};
};