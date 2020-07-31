//2252

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
#define MAXSIZE 32001

typedef long long ll;

vector<int> node[MAXSIZE];
int degree[MAXSIZE];
bool chk[MAXSIZE];
queue<int> q;
vector<int> ans;

void topology(int n) {
    //���� ������ 0�� ��带 ����
    for (int i = 1; i <= n; i++) {
        if (!degree[i]) q.push(i);
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

    int n, m;
    cin >> n >> m;

    while (m--) {
        int s, e;
        cin >> s >> e;
        node[s].push_back(e);
        node[e].push_back(s);
        degree[e]++; //���� ����
    }

    topology(n);

    //answer
    for (auto& a : ans) {
        cout << a << " ";
    }

    return 0;
}