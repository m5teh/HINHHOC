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
double  maxx = -1e11, minx = 1e11, maxy = -1e11, miny = 1e11;
point p[10];
vector <double> vmaxx, vminx, vmaxy, vminy;
int n;
line l;
bool check_apart (line l, point g, point h) {
      double a, b, c;
      eline (l.p1, l.p2, a, b, c);
      return ((a * g.x + b * g.y + c) * (a * h.x + b * h.y + c) >= 0);
}
bool check () {
      int ok = 1;
      for (int i = 1; i < 8; ++ i) {
            if (! check_apart (l, p[i], p[i + 1])) {
                  ok = 0;
            }
      }
      return ok;
}
int main () {
      if (fopen ("test.inp", "r")) {
            freopen ("test.inp", "r", stdin);
      }
      else {
            freopen ("HWAYS.inp", "r", stdin);
            freopen ("HWAYS.out", "w", stdout);
      }

      ios_base :: sync_with_stdio (0);
      cin.tie (0);
      cout.tie (0);
      cin >> n;

      for (int i = 1; i <= n; ++ i) {
            double x, y;
            cin >> x >> y;
            if (x < minx) {
                  minx = x;
                  vminx.clear ();
                  vminx.push_back (y);
            }
            else if (abs(x - minx) <= 1e-9) {
                  vminx.push_back (y);
            }
            if (x > maxx) {
                  maxx = x;
                  vmaxx.clear ();
                  vmaxx.push_back (y);
            }
            else if (abs(x - maxx) <= 1e-9) {
                  vmaxx.push_back (y);
            }
            if (y < miny) {
                  miny = y;
                  vminy.clear ();
                  vminy.push_back (x);
            }
            else if (abs(y - miny) <= 1e-9) {
                  vminy.push_back (x);
            }
            if (y > maxy) {
                  maxy = y;
                  vmaxy.clear ();
                  vmaxy.push_back (x);
            }
            else if (abs(y - maxy) <= 1e-9) {
                  vmaxy.push_back (x);
            }
      }
      sort (vminy.begin (), vminy.end ());
      sort (vmaxy.begin (), vmaxy.end ());
      sort (vminx.begin (), vminx.end ());
      sort (vmaxx.begin (), vmaxx.end ());
      p[1].x = minx;
      p[1].y = vminx[0];
      p[2].x = minx;
      p[2].y = vminx[vminx.size () - 1];
      p[3].x = maxx;
      p[3].y = vmaxx[0];
      p[4].x = maxx;
      p[4].y = vmaxx[vmaxx.size () - 1];
      p[5].y = miny;
      p[5].x = vminy[0];
      p[6].y = miny;
      p[6].x = vminy[vminy.size () - 1];
      p[7].y = maxy;
      p[7].x = vmaxy[0];
      p[8].y = maxy;
      p[8].x = vmaxy[vmaxy.size () - 1];
      while (cin >> l.p1.x >> l.p1.y >> l.p2.x >> l.p2.y) {
            if (check ()) {
                  cout << "GOOD\n";
            }
            else {
                  cout << "BAD\n";
            }
      }
}
/*
4
0.0 0
6.00 -0.001
3.125 4.747
4.747 0.47
5 3 7 0
4 -4.7 7 4.7
4 47 4 94
*/
