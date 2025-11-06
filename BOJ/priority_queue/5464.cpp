#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int main() {
    FASTIO;

    int n, m; cin >> n >> m;
    vi park(n+1), car(m+1);
    for (int i=1; i<=n; i++) cin >> park[i];
    for (int i=1; i<=m; i++) cin >> car[i];

    priority_queue<int, vi, greater<int>> emptyParkQueue;
    for (int i=1; i<=n; i++) emptyParkQueue.push(i);

    ll ret = 0;
    map<int, int> parkByCar;
    queue<int> delayedCars;
    for (int i=0; i<2*m; i++) {
        int selectedCar; cin >> selectedCar;
        if (selectedCar > 0) {
            if (!emptyParkQueue.empty()) {
                int targetPark = emptyParkQueue.top(); emptyParkQueue.pop();
                parkByCar[selectedCar] = targetPark;
                ret += park[targetPark] * car[selectedCar];
            } else {
                delayedCars.push(selectedCar);
            }
        } else {
            emptyParkQueue.push(parkByCar[-selectedCar]);
            if (!delayedCars.empty()) {
                int targetPark = emptyParkQueue.top(); emptyParkQueue.pop();
                int delayedCar = delayedCars.front(); delayedCars.pop();
                parkByCar[delayedCar] = targetPark;
                ret += park[targetPark] * car[delayedCar];
            }
        }
    }

    cout << ret << '\n';

    return 0;
}