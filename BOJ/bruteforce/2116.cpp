#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
const int INF = 987654321;
typedef pair<int, int> ii;

int n, ret;
int reverse_index[6] = {5, 3, 4, 1, 2, 0};
vector<vector<int>> dices;
vector<map<int, int>> route; // 값 -> 인덱스
vector<map<ii, int>> maxv_side;

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

void init_max_value(vector<int>& dice) {
    map<ii, int> ret;
    
    for (int i=0; i<6; i++) {
        for (int j=0; j<6; j++) {
            if (i == j) continue;
            int maxv = 0;
            for (int k=0; k<6; k++) {
                if (k == i || k == j) continue;
                maxv = max(maxv, dice[k]);
            }
            ret[{i, j}] = maxv;
            ret[{j, i}] = maxv;
        }
    }

    maxv_side.push_back(ret);
}

void init_route(vector<int>& dice) {
    map<int, int> ret;

    for (int i=0; i<dice.size(); i++) {
        ret[dice[i]] = i;
    }

    route.push_back(ret);
}

void dfs(int cur, int before_top, int sum) {
    if (cur >= n) {
        ret = max(ret, sum);
        return;
    }

    int avoid_idx = route[cur][before_top]; // 밑면 인덱스
    int reverse_idx = reverse_index[avoid_idx]; // 윗면 인덱스

    dfs(cur+1, dices[cur][reverse_idx], sum + maxv_side[cur][{avoid_idx, reverse_idx}]);
}

int main() {
    FASTIO();
    
    cin >> n;
    for (int i=0; i<n; i++) {
        vector<int> tmp;
        for (int j=0; j<6; j++) {
            int v; cin >> v;
            tmp.push_back(v);
        }
        init_max_value(tmp);
        init_route(tmp);
        dices.push_back(tmp);
    }

    // 맨 밑에서 어떤걸 윗면으로 선택하냐에 따라 앞으로의 윗면/밑면이 정해진다
    // 여기서는 i를 윗면으로 고정
    for (int i=0; i<6; i++) {
        dfs(1, dices[0][i], maxv_side[0][{i, reverse_index[i]}]);
    }

    cout << ret << '\n';

    return 0;
}