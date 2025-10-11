#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

const int INF = 987654321;
const int MOD = 1000000007;

struct Room {
    int level;
    vector<pair<int, string>> players;

    Room(int _level, pair<int, string> player): level(_level) {
        players.push_back(player);
    }

    void addPlayer(pair<int, string> player) {
        players.push_back(player);
    }

    void print(int fullSize) {
        if (players.size() >= fullSize) cout << "Started!" << '\n';
        else cout << "Waiting!" << '\n';

        // nickname 오름차순 정렬
        sort(players.begin(), players.end(), [](pair<int, string>& a, pair<int, string>& b) {
            return a.second < b.second;
        });

        for (auto& p : players) {
            cout << p.first << " " << p.second << '\n';
        }
    }
};

int main() {
    FASTIO;

    int p, m; cin >> p >> m;
    vector<Room> rooms;
    while (p--) {
        int level; string nickname; cin >> level >> nickname;

        bool notFoundRoom = true;
        for (auto& r : rooms) {
            if (r.players.size() < m 
                && (r.level-10 <= level && level <= r.level+10)
            ) {
                r.addPlayer({level, nickname});
                notFoundRoom = false;
                break;
            }
        }

        if (notFoundRoom) {
            rooms.push_back(
                Room(level, {level, nickname})
            );
        }
    }

    for (auto& r : rooms) r.print(m);

    return 0;
}