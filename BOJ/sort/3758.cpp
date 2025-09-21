#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 987654321;
const int MOD = 1000000007;

struct TeamScore {
    int id;
    int scoreSum;
    int submitCnt;
    int lastSubmittedTime;
    int scoreByQuestion[105];

    TeamScore(int _id) {
        id = _id;
        scoreSum = submitCnt = 0;
        lastSubmittedTime = INF;
        fill(scoreByQuestion, scoreByQuestion+105, 0);
    }

    void submit(int j, int s, int submitTime) {
        if (scoreByQuestion[j] < s) {
            scoreSum += (-scoreByQuestion[j] + s);
            scoreByQuestion[j] = s;
        }

        submitCnt++;
        lastSubmittedTime = submitTime;
    }

    bool operator<(const TeamScore& t) const {
        if (scoreSum != t.scoreSum) return scoreSum > t.scoreSum;
        if (submitCnt != t.submitCnt) return submitCnt < t.submitCnt;
        return lastSubmittedTime < t.lastSubmittedTime;
    }
};

int main() {
    FASTIO;
    
    int t; cin >> t;
    while (t--) {
        int n, k, myTeamId, m; cin >> n >> k >> myTeamId >> m;
        vector<TeamScore> teamScores;
        for (int id=0; id<=n; id++) teamScores.push_back(TeamScore(id));

        for (int i=0; i<m; i++) {
            int id, j, s; cin >> id >> j >> s;
            teamScores[id].submit(j, s, i);
        }

        sort(teamScores.begin(), teamScores.end());

        int ret = 0;
        for (int i=0; i<teamScores.size(); i++) {
            if (teamScores[i].id == myTeamId) {
                ret = i+1;
                break;
            }
        }
        cout << ret << '\n';
    }

    return 0;
}