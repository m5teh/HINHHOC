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
point p[100011];
int n;
double res = 0;
int main () {
      if (fopen ("test.inp", "r")) {
            freopen ("test.inp", "r", stdin);
      }
      else {
            freopen ("MAXDIS.inp", "r", stdin);
            freopen ("MAXDIS.out", "w", stdout);
      }

      ios_base :: sync_with_stdio (0);
      cin.tie (0);
      cout.tie (0);
      cin >> n;
      for (int i = 1; i <= n; ++ i) {
            cin >> p[i].x >> p[i].y;
      }
      p[n + 1] = p[1];
      int i = 1, j = 2;
      while (i <= n) {
            double ans = 0;
            while (j <= n + 1) {
                  if (dist (p[i], p[j]) >= ans) {
                        ans = dist (p[i], p[j]);
                        ++ j;
                        res = max (res, ans);
                  }
                  else break;
            }
            ++ i;
      }
      p[0] = p[n];
      i = n;
      j = n - 1;
      while (i >= 1) {
            double ans = 0;
            while (j >= 0) {
                  if (dist (p[i], p[j]) >= ans) {
                        ans = dist (p[i], p[j]);
                        -- j;
                        res = max (res, ans);
                  }
                  else break;
            }
            -- i;
      }
      cout << setprecision(4) << fixed << res;
}
