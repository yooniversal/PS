#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
const int INF = 987654321;

int main() {
    FASTIO;

    int N; cin >> N;

    string morning, evening; cin >> morning >> evening;

    int cntMorning = 0, cntEvening = 0;

    for (int i=0; i<N; i++) {
        if (morning[i] == 'w') cntMorning++;
        if (evening[i] == 'w') cntEvening++;
    }

    if (cntEvening < cntMorning) {
        cout << "Oryang" << '\n';
    } else if (cntEvening > cntMorning) {
        cout << "Manners maketh man"  << '\n';
    } else {
        if (morning == evening) {
            cout << "Good" << '\n';
        } else {
            cout << "Its fine" << '\n';
        }
    }

    return 0;
}