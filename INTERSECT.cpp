#include<bits/stdc++.h>
using namespace std;
/// from HUNG MAI with love <3

struct point {
      double x, y;
};

struct line {
      point p1, p2;
};

double dist (point p1, point p2) {
      return sqrt ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void eline (point p1, point p2, double &a, double &b, double &c) {
      a = p2.y - p1.y;
      b = p1.x - p2.x;
      c = - p1.x * (p2.y - p1.y) + p1.y * (p2.x - p1.x);
}

bool checkcut (line l1, line l2) {
      double a1, b1, c1, a2, b2, c2;
      eline (l1.p1, l1.p2, a1, b1, c1);
      eline (l2.p1, l2.p2, a2, b2, c2);
      return ((l1.p1.x * a2 + l1.p1.y * b2 + c2) * (l1.p2.x * a2 + l1.p2.y * b2 + c2) <= 0 && (l2.p1.x * a1 + l2.p1.y * b1 + c1) * (l2.p2.x * a1 + l2.p2.y * b1 + c1) <= 0);
}
line a, b;
int t;
int main () {
      if (fopen ("test.inp", "r")) {
            freopen ("test.inp", "r", stdin);
      }
      else {
            freopen ("INTERSECT.inp", "r", stdin);
            freopen ("INTERSECT.out", "w", stdout);
      }

      ios_base :: sync_with_stdio (0);
      cin.tie (0);
      cout.tie (0);

      cin >> t;
      while (t --) {
            cin >> a.p1.x >> a.p1.y >> a.p2.x >> a.p2.y >> b.p1.x >> b.p1.y >> b.p2.x >> b.p2.y;
            if (checkcut (a, b)) {
                  cout << "YES\n";
            }
            else {
                  cout << "NO\n";
            }
      }
}
