#include<iostream>


using namespace std;

int a[1000005];

int main(int argc, char** argv)
{

  int n, k; cin >> n >> k;
  for(int i=0; i<n; ++i) {
    if(i==0) {
      cin >> a[i];
      continue;
    }
    int v; cin >> v;
    a[i] = a[i-1] + v;
  }

  while(k--) {
    int u, v; cin >> u >> v;
    --u; --v;
    int sum = u > 0 ? a[v] - a[u-1] : a[v];
    double ret = sum / (double)(v-u+1);
    printf("%0.2f\n", ret);
  }
  
   return 0;
}