#include<bits/stdc++.h>
using namespace std;
/// from HUNG MAI with love <3
struct point {
      double x, y;
};

struct line {
      point p1, p2;
};
point operator - (point a, point b) {
      point ans;
      ans.x = a.x - b.x;
      ans.y = a.y - b.y;
      return ans;
}
double operator * (point a, point b) {
      return a.x * b.y - a.y * b.x;
}

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

int n, m;
point a[10001], c[10001];
double res = 0;
bool cmp (point a, point b) {
      if (a.x == b.x) return a.y < b.y;
      return a.x < b.x;
}
int main () {
      if (fopen ("test.inp", "r")) {
            freopen ("test.inp", "r", stdin);
      }
      else {
            freopen ("CONVEX.inp", "r", stdin);
            freopen ("CONVEX.out", "w", stdout);
      }

      ios_base :: sync_with_stdio (0);
      cin.tie (0);
      cout.tie (0);

      cin >> n;
      for (int i = 1; i <= n; ++ i) {
            cin >> a[i].x >> a[i].y;
      }

      sort (a + 1, a + n + 1, cmp);
      m = 2;
      c[1] = a[1];
      c[2] = a[2];
      for (int i = 3; i <= n; ++ i) {
            c[++ m] = a[i];
            while (m > 2 && (c[m - 1] - c[m - 2]) * (c[m] - c[m - 1]) >= 0) {
                  -- m;
                  c[m] = c[m + 1];
            }
      }
      int m0 = m;
      c[++ m] = a[n - 1];
      for (int i = n - 2; i >= 1; -- i) {
            c[++ m] = a[i];
            while (m - m0 > 1 && (c[m - 1] - c[m - 2]) * (c[m] - c[m - 1]) >= 0) {
                  -- m;
                  c[m] = c[m + 1];
            }
      }
      -- m;
      c[m + 1] = c[1];
      for (int i = 1; i <= m; ++ i) {//cout << c[i].x << " " << c[i].y << "\n";
            res += dist (c[i], c[i + 1]);
      }
      cout << setprecision(2) << fixed << res;
}
/*
4
4 8
4 12
5 9.3
7 8
*/
