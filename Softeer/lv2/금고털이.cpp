#include<iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct S {
  int m, p;
  S(int m, int p): m(m), p(p) {}
  bool operator<(S& s) {
    return p < s.p;
  }
};

int main(int argc, char** argv)
{
   int w, n; cin >> w >> n;
   vector<S> a;
   for(int i=0; i<n; ++i) {
     int m, p; cin >> m >> p;
     a.push_back(S(m, p));
   }
   sort(a.rbegin(), a.rend());

   int ret = 0;
   for(int i=0; i<n; ++i) {
     if(w >= a[i].m) {
       w -= a[i].m;
       ret += a[i].m * a[i].p;
       continue;
     }

     ret += w * a[i].p;
     break;
   }

   cout << ret << '\n';
  
   return 0;
}