---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://cses.fi/problemset/task/2190/
  bundledCode: "#line 2 \"geometry/basic.hpp\"\n\n// Basic geometry objects: Point,\
    \ Line, Segment\n// Works with both integers and floating points\n// Unless the\
    \ problem has precision issue, can use Point, which uses double\n// and has more\
    \ functionalities.\n// For integers, can use P<long long>\n\n#ifndef EPS  // allow\
    \ test files to overwrite EPS\n#define EPS 1e-6\n#endif\n\nconst double PI = acos(-1.0);\n\
    \ndouble DEG_to_RAD(double d) { return d * PI / 180.0; }\ndouble RAD_to_DEG(double\
    \ r) { return r * 180.0 / PI; }\n\ninline int cmp(double a, double b) {\n  return\
    \ (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);\n}\n\n// for int types\ntemplate\
    \ <typename T, typename std::enable_if<\n                          !std::is_floating_point<T>::value>::type*\
    \ = nullptr>\ninline int cmp(T a, T b) {\n  return (a == b) ? 0 : (a < b) ? -1\
    \ : 1;\n}\n\ntemplate <typename T>\nstruct P {\n  T x, y;\n  P() { x = y = T(0);\
    \ }\n  P(T _x, T _y) : x(_x), y(_y) {}\n\n  P operator+(const P& a) const { return\
    \ P(x + a.x, y + a.y); }\n  P operator-(const P& a) const { return P(x - a.x,\
    \ y - a.y); }\n  P operator*(T k) const { return P(x * k, y * k); }\n  P<double>\
    \ operator/(double k) const { return P(x / k, y / k); }\n\n  T operator*(const\
    \ P& a) const { return x * a.x + y * a.y; }  // dot product\n  T operator%(const\
    \ P& a) const { return x * a.y - y * a.x; }  // cross product\n\n  int cmp(const\
    \ P<T>& q) const {\n    if (int t = ::cmp(x, q.x)) return t;\n    return ::cmp(y,\
    \ q.y);\n  }\n\n#define Comp(x) \\\n  bool operator x(const P& q) const { return\
    \ cmp(q) x 0; }\n  Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)\n#undef\
    \ Comp\n\n      T norm() {\n    return x * x + y * y;\n  }\n\n  // Note: There\
    \ are 2 ways for implementing len():\n  // 1. sqrt(norm()) --> fast, but inaccurate\
    \ (produce some values that are of\n  // order X^2)\n  // 2. hypot(x, y) --> slow,\
    \ but much more accurate\n  double len() { return hypot(x, y); }\n\n  P<double>\
    \ rotate(double alpha) {\n    double cosa = cos(alpha), sina = sin(alpha);\n \
    \   return P(x * cosa - y * sina, x * sina + y * cosa);\n  }\n};\nusing Point\
    \ = P<double>;\n\n// Compare points by (y, x)\ntemplate <typename T = double>\n\
    bool cmpy(const P<T>& a, const P<T>& b) {\n  if (cmp(a.y, b.y)) return a.y < b.y;\n\
    \  return a.x < b.x;\n};\n\ntemplate <typename T>\nint ccw(P<T> a, P<T> b, P<T>\
    \ c) {\n  return cmp((b - a) % (c - a), T(0));\n}\n\nint RE_TRAI = ccw(P<int>(0,\
    \ 0), P<int>(0, 1), P<int>(-1, 1));\nint RE_PHAI = ccw(P<int>(0, 0), P<int>(0,\
    \ 1), P<int>(1, 1));\n\ntemplate <typename T>\nistream& operator>>(istream& cin,\
    \ P<T>& p) {\n  cin >> p.x >> p.y;\n  return cin;\n}\ntemplate <typename T>\n\
    ostream& operator<<(ostream& cout, const P<T>& p) {\n  cout << p.x << ' ' << p.y;\n\
    \  return cout;\n}\n\ndouble angle(Point a, Point o, Point b) {  // min of directed\
    \ angle AOB & BOA\n  a = a - o;\n  b = b - o;\n  return acos((a * b) / sqrt(a.norm())\
    \ / sqrt(b.norm()));\n}\n\ndouble directed_angle(Point a, Point o,\n         \
    \             Point b) {  // angle AOB, in range [0, 2*PI)\n  double t = -atan2(a.y\
    \ - o.y, a.x - o.x) + atan2(b.y - o.y, b.x - o.x);\n  while (t < 0) t += 2 * PI;\n\
    \  return t;\n}\n\n// Distance from p to Line ab (closest Point --> c)\n// i.e.\
    \ c is projection of p on AB\ndouble distToLine(Point p, Point a, Point b, Point&\
    \ c) {\n  Point ap = p - a, ab = b - a;\n  double u = (ap * ab) / ab.norm();\n\
    \  c = a + (ab * u);\n  return (p - c).len();\n}\n\n// Distance from p to segment\
    \ ab (closest Point --> c)\ndouble distToLineSegment(Point p, Point a, Point b,\
    \ Point& c) {\n  Point ap = p - a, ab = b - a;\n  double u = (ap * ab) / ab.norm();\n\
    \  if (u < 0.0) {\n    c = Point(a.x, a.y);\n    return (p - a).len();\n  }\n\
    \  if (u > 1.0) {\n    c = Point(b.x, b.y);\n    return (p - b).len();\n  }\n\
    \  return distToLine(p, a, b, c);\n}\n\n// NOTE: WILL NOT WORK WHEN a = b = 0.\n\
    struct Line {\n  double a, b, c;  // ax + by + c = 0\n  Point A, B;  // Added\
    \ for polygon intersect line. Do not rely on assumption\n               // that\
    \ these are valid\n\n  Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c)\
    \ {}\n\n  Line(Point _A, Point _B) : A(_A), B(_B) {\n    a = B.y - A.y;\n    b\
    \ = A.x - B.x;\n    c = -(a * A.x + b * A.y);\n  }\n  Line(Point P, double m)\
    \ {\n    a = -m;\n    b = 1;\n    c = -((a * P.x) + (b * P.y));\n  }\n  double\
    \ f(Point p) { return a * p.x + b * p.y + c; }\n};\nostream& operator>>(ostream&\
    \ cout, const Line& l) {\n  cout << l.a << \"*x + \" << l.b << \"*y + \" << l.c;\n\
    \  return cout;\n}\n\nbool areParallel(Line l1, Line l2) {\n  return cmp(l1.a\
    \ * l2.b, l1.b * l2.a) == 0;\n}\n\nbool areSame(Line l1, Line l2) {\n  return\
    \ areParallel(l1, l2) && cmp(l1.c * l2.a, l2.c * l1.a) == 0 &&\n         cmp(l1.c\
    \ * l2.b, l1.b * l2.c) == 0;\n}\n\nbool areIntersect(Line l1, Line l2, Point&\
    \ p) {\n  if (areParallel(l1, l2)) return false;\n  double dx = l1.b * l2.c -\
    \ l2.b * l1.c;\n  double dy = l1.c * l2.a - l2.c * l1.a;\n  double d = l1.a *\
    \ l2.b - l2.a * l1.b;\n  p = Point(dx / d, dy / d);\n  return true;\n}\n\n// closest\
    \ point from p in line l.\nvoid closestPoint(Line l, Point p, Point& ans) {\n\
    \  if (fabs(l.b) < EPS) {\n    ans.x = -(l.c) / l.a;\n    ans.y = p.y;\n    return;\n\
    \  }\n  if (fabs(l.a) < EPS) {\n    ans.x = p.x;\n    ans.y = -(l.c) / l.b;\n\
    \    return;\n  }\n  Line perp(l.b, -l.a, -(l.b * p.x - l.a * p.y));\n  areIntersect(l,\
    \ perp, ans);\n}\n\n// Segment intersect\n// Tested:\n// - https://cses.fi/problemset/task/2190/\n\
    // returns true if p is on segment [a, b]\ntemplate <typename T>\nbool onSegment(const\
    \ P<T>& a, const P<T>& b, const P<T>& p) {\n  return ccw(a, b, p) == 0 && min(a.x,\
    \ b.x) <= p.x && p.x <= max(a.x, b.x) &&\n         min(a.y, b.y) <= p.y && p.y\
    \ <= max(a.y, b.y);\n}\n\n// Returns true if segment [a, b] and [c, d] intersects\n\
    // End point also returns true\ntemplate <typename T>\nbool segmentIntersect(const\
    \ P<T>& a, const P<T>& b, const P<T>& c,\n                      const P<T>& d)\
    \ {\n  if (onSegment(a, b, c) || onSegment(a, b, d) || onSegment(c, d, a) ||\n\
    \      onSegment(c, d, b)) {\n    return true;\n  }\n\n  return ccw(a, b, c) *\
    \ ccw(a, b, d) < 0 && ccw(c, d, a) * ccw(c, d, b) < 0;\n}\n"
  code: "#pragma once\n\n// Basic geometry objects: Point, Line, Segment\n// Works\
    \ with both integers and floating points\n// Unless the problem has precision\
    \ issue, can use Point, which uses double\n// and has more functionalities.\n\
    // For integers, can use P<long long>\n\n#ifndef EPS  // allow test files to overwrite\
    \ EPS\n#define EPS 1e-6\n#endif\n\nconst double PI = acos(-1.0);\n\ndouble DEG_to_RAD(double\
    \ d) { return d * PI / 180.0; }\ndouble RAD_to_DEG(double r) { return r * 180.0\
    \ / PI; }\n\ninline int cmp(double a, double b) {\n  return (a < b - EPS) ? -1\
    \ : ((a > b + EPS) ? 1 : 0);\n}\n\n// for int types\ntemplate <typename T, typename\
    \ std::enable_if<\n                          !std::is_floating_point<T>::value>::type*\
    \ = nullptr>\ninline int cmp(T a, T b) {\n  return (a == b) ? 0 : (a < b) ? -1\
    \ : 1;\n}\n\ntemplate <typename T>\nstruct P {\n  T x, y;\n  P() { x = y = T(0);\
    \ }\n  P(T _x, T _y) : x(_x), y(_y) {}\n\n  P operator+(const P& a) const { return\
    \ P(x + a.x, y + a.y); }\n  P operator-(const P& a) const { return P(x - a.x,\
    \ y - a.y); }\n  P operator*(T k) const { return P(x * k, y * k); }\n  P<double>\
    \ operator/(double k) const { return P(x / k, y / k); }\n\n  T operator*(const\
    \ P& a) const { return x * a.x + y * a.y; }  // dot product\n  T operator%(const\
    \ P& a) const { return x * a.y - y * a.x; }  // cross product\n\n  int cmp(const\
    \ P<T>& q) const {\n    if (int t = ::cmp(x, q.x)) return t;\n    return ::cmp(y,\
    \ q.y);\n  }\n\n#define Comp(x) \\\n  bool operator x(const P& q) const { return\
    \ cmp(q) x 0; }\n  Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)\n#undef\
    \ Comp\n\n      T norm() {\n    return x * x + y * y;\n  }\n\n  // Note: There\
    \ are 2 ways for implementing len():\n  // 1. sqrt(norm()) --> fast, but inaccurate\
    \ (produce some values that are of\n  // order X^2)\n  // 2. hypot(x, y) --> slow,\
    \ but much more accurate\n  double len() { return hypot(x, y); }\n\n  P<double>\
    \ rotate(double alpha) {\n    double cosa = cos(alpha), sina = sin(alpha);\n \
    \   return P(x * cosa - y * sina, x * sina + y * cosa);\n  }\n};\nusing Point\
    \ = P<double>;\n\n// Compare points by (y, x)\ntemplate <typename T = double>\n\
    bool cmpy(const P<T>& a, const P<T>& b) {\n  if (cmp(a.y, b.y)) return a.y < b.y;\n\
    \  return a.x < b.x;\n};\n\ntemplate <typename T>\nint ccw(P<T> a, P<T> b, P<T>\
    \ c) {\n  return cmp((b - a) % (c - a), T(0));\n}\n\nint RE_TRAI = ccw(P<int>(0,\
    \ 0), P<int>(0, 1), P<int>(-1, 1));\nint RE_PHAI = ccw(P<int>(0, 0), P<int>(0,\
    \ 1), P<int>(1, 1));\n\ntemplate <typename T>\nistream& operator>>(istream& cin,\
    \ P<T>& p) {\n  cin >> p.x >> p.y;\n  return cin;\n}\ntemplate <typename T>\n\
    ostream& operator<<(ostream& cout, const P<T>& p) {\n  cout << p.x << ' ' << p.y;\n\
    \  return cout;\n}\n\ndouble angle(Point a, Point o, Point b) {  // min of directed\
    \ angle AOB & BOA\n  a = a - o;\n  b = b - o;\n  return acos((a * b) / sqrt(a.norm())\
    \ / sqrt(b.norm()));\n}\n\ndouble directed_angle(Point a, Point o,\n         \
    \             Point b) {  // angle AOB, in range [0, 2*PI)\n  double t = -atan2(a.y\
    \ - o.y, a.x - o.x) + atan2(b.y - o.y, b.x - o.x);\n  while (t < 0) t += 2 * PI;\n\
    \  return t;\n}\n\n// Distance from p to Line ab (closest Point --> c)\n// i.e.\
    \ c is projection of p on AB\ndouble distToLine(Point p, Point a, Point b, Point&\
    \ c) {\n  Point ap = p - a, ab = b - a;\n  double u = (ap * ab) / ab.norm();\n\
    \  c = a + (ab * u);\n  return (p - c).len();\n}\n\n// Distance from p to segment\
    \ ab (closest Point --> c)\ndouble distToLineSegment(Point p, Point a, Point b,\
    \ Point& c) {\n  Point ap = p - a, ab = b - a;\n  double u = (ap * ab) / ab.norm();\n\
    \  if (u < 0.0) {\n    c = Point(a.x, a.y);\n    return (p - a).len();\n  }\n\
    \  if (u > 1.0) {\n    c = Point(b.x, b.y);\n    return (p - b).len();\n  }\n\
    \  return distToLine(p, a, b, c);\n}\n\n// NOTE: WILL NOT WORK WHEN a = b = 0.\n\
    struct Line {\n  double a, b, c;  // ax + by + c = 0\n  Point A, B;  // Added\
    \ for polygon intersect line. Do not rely on assumption\n               // that\
    \ these are valid\n\n  Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c)\
    \ {}\n\n  Line(Point _A, Point _B) : A(_A), B(_B) {\n    a = B.y - A.y;\n    b\
    \ = A.x - B.x;\n    c = -(a * A.x + b * A.y);\n  }\n  Line(Point P, double m)\
    \ {\n    a = -m;\n    b = 1;\n    c = -((a * P.x) + (b * P.y));\n  }\n  double\
    \ f(Point p) { return a * p.x + b * p.y + c; }\n};\nostream& operator>>(ostream&\
    \ cout, const Line& l) {\n  cout << l.a << \"*x + \" << l.b << \"*y + \" << l.c;\n\
    \  return cout;\n}\n\nbool areParallel(Line l1, Line l2) {\n  return cmp(l1.a\
    \ * l2.b, l1.b * l2.a) == 0;\n}\n\nbool areSame(Line l1, Line l2) {\n  return\
    \ areParallel(l1, l2) && cmp(l1.c * l2.a, l2.c * l1.a) == 0 &&\n         cmp(l1.c\
    \ * l2.b, l1.b * l2.c) == 0;\n}\n\nbool areIntersect(Line l1, Line l2, Point&\
    \ p) {\n  if (areParallel(l1, l2)) return false;\n  double dx = l1.b * l2.c -\
    \ l2.b * l1.c;\n  double dy = l1.c * l2.a - l2.c * l1.a;\n  double d = l1.a *\
    \ l2.b - l2.a * l1.b;\n  p = Point(dx / d, dy / d);\n  return true;\n}\n\n// closest\
    \ point from p in line l.\nvoid closestPoint(Line l, Point p, Point& ans) {\n\
    \  if (fabs(l.b) < EPS) {\n    ans.x = -(l.c) / l.a;\n    ans.y = p.y;\n    return;\n\
    \  }\n  if (fabs(l.a) < EPS) {\n    ans.x = p.x;\n    ans.y = -(l.c) / l.b;\n\
    \    return;\n  }\n  Line perp(l.b, -l.a, -(l.b * p.x - l.a * p.y));\n  areIntersect(l,\
    \ perp, ans);\n}\n\n// Segment intersect\n// Tested:\n// - https://cses.fi/problemset/task/2190/\n\
    // returns true if p is on segment [a, b]\ntemplate <typename T>\nbool onSegment(const\
    \ P<T>& a, const P<T>& b, const P<T>& p) {\n  return ccw(a, b, p) == 0 && min(a.x,\
    \ b.x) <= p.x && p.x <= max(a.x, b.x) &&\n         min(a.y, b.y) <= p.y && p.y\
    \ <= max(a.y, b.y);\n}\n\n// Returns true if segment [a, b] and [c, d] intersects\n\
    // End point also returns true\ntemplate <typename T>\nbool segmentIntersect(const\
    \ P<T>& a, const P<T>& b, const P<T>& c,\n                      const P<T>& d)\
    \ {\n  if (onSegment(a, b, c) || onSegment(a, b, d) || onSegment(c, d, a) ||\n\
    \      onSegment(c, d, b)) {\n    return true;\n  }\n\n  return ccw(a, b, c) *\
    \ ccw(a, b, d) < 0 && ccw(c, d, a) * ccw(c, d, b) < 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: geometry/basic.hpp
  requiredBy: []
  timestamp: '2023-08-13 15:15:35+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/basic.hpp
layout: document
redirect_from:
- /library/geometry/basic.hpp
- /library/geometry/basic.hpp.html
title: geometry/basic.hpp
---
