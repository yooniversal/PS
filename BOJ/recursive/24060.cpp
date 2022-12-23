// 24060
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int n, k, cnt, ret = -1;

void merge(vi &a, int p, int q, int r)
{
    if (ret != -1)
        return;

    vi tmp(r-p+1);
    int i = p, j = q+1, t=0;
    while (i <= q && j <= r)
    {
        if (a[i] <= a[j])
            tmp[t++] = a[i++];
        else
            tmp[t++] = a[j++];
    }

    while (i <= q)
        tmp[t++] = a[i++];
    while (j <= r)
        tmp[t++] = a[j++];

    for (int idx = 0; idx < t; ++idx)
    {
        a[p + idx] = tmp[idx];
        if (++cnt == k)
        {
            ret = a[p + idx];
            break;
        }
    }
}

void msort(vi &a, int p, int r)
{
    if (p >= r || ret != -1)
        return;

    int q = (p + r) / 2;
    msort(a, p, q);
    msort(a, q + 1, r);
    merge(a, p, q, r);
}

int main()
{
    cin >> n >> k;

    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    msort(a, 0, n - 1);
    printf("%d\n", ret);

    return 0;
}
