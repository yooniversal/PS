//2143
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    int n; cin >> n;
    vector<ll> a(n), Pa(n+1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        Pa[i + 1] = Pa[i] + a[i];
    }
    int m; cin >> m;
    vector<ll> b(m), Pb(m+1, 0);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        Pb[i + 1] = Pb[i] + b[i];
    }

    vector<ll> A, B;
    for (int i = Pa.size()-1; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            A.push_back(Pa[i] - Pa[j]);
        }
    }
    for (int i = Pb.size() - 1; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            B.push_back(Pb[i] - Pb[j]);
        }
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (auto a : A) cout << a << " ";
    cout << '\n';
    for (auto b : B) cout << b << " ";
    cout << '\n';

    int ret = 0;
    for (int i = 0; i < A.size(); ++i) {
        ll tmp = t - A[i];
        auto l = lower_bound(B.begin(), B.end(), tmp);
        auto r = upper_bound(B.begin(), B.end(), tmp);
        cout << "i:"<<i<<" r-l:" << r - l << '\n';
        ret += r - l;
    }
    
    cout << ret;

    return 0;
}