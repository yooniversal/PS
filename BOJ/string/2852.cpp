#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 987654321;
const int MOD = 1000000007;

int convertToSeconds(string time) {
    int minutes = stoi(time.substr(0, 2));
    int seconds = stoi(time.substr(3, 2));
    return minutes * 60 + seconds; 
}

string toMMSS(int totalSeconds) {
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    string mm = (minutes < 10 ? "0" + to_string(minutes) : to_string(minutes));
    string ss = (seconds < 10 ? "0" + to_string(seconds) : to_string(seconds));

    return mm + ":" + ss;
}

int main() {
    FASTIO;
    
    int n; cin >> n;
    int winTime[2] = {0, 0}, score[2] = {0, 0};
    int beforeSeconds = 0;
    while (n--) {
        int team; string goalTime; cin >> team >> goalTime;
        int goalSeconds = convertToSeconds(goalTime);

        int diffSeconds = goalSeconds - beforeSeconds;
        if (score[0] != score[1]) {
            if (score[0] > score[1]) winTime[0] += diffSeconds;
            else winTime[1] += diffSeconds;
            
        }

        score[team-1]++;
        beforeSeconds = goalSeconds;
    }

    int diffSeconds = 48 *  60 - beforeSeconds;
    if (score[0] > score[1]) winTime[0] += diffSeconds;
    else if (score[0] < score[1]) winTime[1] += diffSeconds;

    cout << toMMSS(winTime[0]) << '\n';
    cout << toMMSS(winTime[1]) << '\n';

    return 0;
}