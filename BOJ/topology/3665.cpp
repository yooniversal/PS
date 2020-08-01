//3665

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define MAXSIZE 501

typedef long long ll;
vector<int> node[MAXSIZE];
int degree[MAXSIZE];
int rate[MAXSIZE];
bool chk[MAXSIZE];

void topology(int n, vector<int>& ans) {
    queue<int> q;

    //���� ������ 0�� ��带 ����
    for (int i = 1; i <= n; i++) {
        if (!degree[i])
            q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        chk[cur] = true;
        ans.push_back(cur);

        //�̿��� ����� ������ ��� ����
        for (auto& next : node[cur]) {
            if (!chk[next]) {
                degree[next]--;

                //���� ������ 0�̸� ť�� ����
                if (!degree[next]) {
                    q.push(next);
                }
            }
        }
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        memset(degree, 0, sizeof(degree));
        memset(chk, false, sizeof(chk));

        int n, m;
        cin >> n;

        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int team; cin >> team;
            arr.push_back(team);
            rate[team] = i; //��� ǥ��
            degree[team] = i;
        }

        //rate
        for (int i = 0; i < n-1; i++) {
            for (int j = i + 1; j < n; j++) {
                node[arr[i]].push_back(arr[j]);
                node[arr[j]].push_back(arr[i]);
            }
        }

        cin >> m;
        while (m--) {
            int s, e;
            cin >> s >> e;
            //s�� e���� ����� ���Ҵٸ�
            if (rate[s] < rate[e]) {
                degree[s]++;
                degree[e]--;
            }
            //e�� s���� ����� ���Ҵٸ�
            else {
                degree[e]++;
                degree[s]--;
            }
        }

        vector<int> ans;
        topology(n, ans);

        //answer
        if (ans.size() == n) {
            for (auto& a : ans) {
                cout << a << " ";
            }
            cout << '\n';
        }
        else {
            cout << "IMPOSSIBLE" << '\n';
        }

        for (int i = 1; i <= n; i++) node[i].clear();
    }

    return 0;
}