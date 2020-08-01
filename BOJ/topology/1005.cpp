//1005

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
#define MAXSIZE 1001

typedef long long ll;
vector<int> node[MAXSIZE];
int degree[MAXSIZE];
int buildtime[MAXSIZE], eachtime[MAXSIZE];
bool chk[MAXSIZE];

void topology(int n, int fin) {
    queue<int> q;

    //���� ������ 0�� ��带 ����
    for (int i = 1; i <= n; i++) {
        if (!degree[i]) {
            q.push(i);
            buildtime[i] = eachtime[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        chk[cur] = true;

        //�̿��� ����� ������ ��� ����
        for (auto& next : node[cur]) {
            if (!chk[next]) {
                degree[next]--;
                buildtime[next] = max(buildtime[next], buildtime[cur]);
                //���� ������ 0�̸� ť�� ����
                if (!degree[next]) {
                    q.push(next);
                    buildtime[next] += eachtime[next];
                    //��ǥ ������ ����
                    if (next == fin) return;
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
        memset(buildtime, 0, sizeof(buildtime));
        memset(eachtime, 0, sizeof(eachtime));

        int n, k;
        cin >> n >> k;

        //update build time
        for (int i = 1; i <= n; i++) {
            cin >> eachtime[i];
        }

        while (k--) {
            int s, e;
            cin >> s >> e;
            node[s].push_back(e);
            node[e].push_back(s);
            degree[e]++;
        }

        int fin; cin >> fin;
        topology(n, fin);

        //answer
        cout << buildtime[fin] << '\n';

        for (int i = 1; i <= n; i++) node[i].clear();
    }

    return 0;
}