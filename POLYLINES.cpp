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
point a[201], m;
int n, res = 0;
bool check (point aa, point b, int pos) {
      line f, g, h;
      int ok = 1;
      f.p1 = aa;
      f.p2 = m;
      g.p1 = b;
      g.p2 = m;
      for (int i = 1; i <= n; ++ i) if (i != pos) {
            h.p1 = a[i];
            h.p2 = a[i + 1];
            if (checkcut (f, h) && checkcut (g, h)) {
                  ok = 0;
            }
      }
      return ok;
}
vector <pair <pair <double, double>, pair <double, double> > > ans;
int main () {
      if (fopen ("test.inp", "r")) {
            freopen ("test.inp", "r", stdin);
      }
      else {
            freopen ("POLYLINES.inp", "r", stdin);
            freopen ("POLYLINES.out", "w", stdout);
      }

      ios_base :: sync_with_stdio (0);
      cin.tie (0);
      cout.tie (0);
      cin >> n;
      cin >> m.x >> m.y;
      for (int i = 1; i <= n; ++ i) {
            cin >> a[i].x >> a[i].y;
      }
      a[n + 1].x = a[1].x; a[n + 1].y = a[1].y;

      for (int i = 1; i <= n; ++ i) {
            if (check (a[i], a[i + 1], i)) {
                  ++ res;
                  ans.push_back ({{a[i].x, a[i].y}, {a[i + 1].x, a[i + 1].y}});
            }
      }

      cout << res << "\n";
      for (auto val : ans) {
            cout << val.first.first << " " << val.first.second << " " << val.second.first << " " << val.second.second << "\n";
      }
}
/*
13
5 5
0 0
7 0
5 2
7 5
5 7
3 5
4 9
1 8
2 5
0 9
-2 7
0 3
-3 1
*/
