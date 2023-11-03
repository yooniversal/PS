#include<iostream>
#include <cstring>

using namespace std;

int cache[3005];
int a[3005];
int n;

int f(int cur) {
   if(cur >= n) return 0;
   int& ret = cache[cur];
   if(ret != -1) return ret;
   ret = 1;

   for(int i=cur+1; i<n; ++i) {
      if(a[cur] >= a[i]) continue;
      ret = max(ret, f(i) + 1);
   }
  
   return ret;
}

int main(int argc, char** argv)
{
   memset(cache, -1, sizeof(cache));
   cin >> n;
   for(int i=0; i<n; ++i) {
      cin >> a[i];
   }

   int ret = 0;
   for(int i=0; i<n; ++i) {
      ret = max(ret, f(i));
   }

   cout << ret << '\n';
  
   return 0;
}