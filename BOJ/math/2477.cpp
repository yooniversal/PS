// 2477
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int f(vii& a, int i) {
    int next = (i + 3) % 6;
    return a[next].second * a[(next + 1) % 6].second;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int k; cin>>k;

    vii a;
    for (int i = 0; i < 6; ++i) {
        int d, l;
        cin >> d >> l;
        a.push_back({d, l});
    }

    int max_area = 0, max_idx = -1;
    for (int i = 0; i < 6; ++i) {
        if (max_area < a[i].second * a[(i + 1) % 6].second) {
            max_area = a[i].second * a[(i + 1) % 6].second;
            max_idx = i;
        }
    }

    int cut_area = f(a, max_idx);

    cout << (max_area - cut_area) * k << '\n';

    return 0;
}
