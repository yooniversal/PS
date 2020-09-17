#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
const int MAX = 51;

bool chk[MAX];
vector<int> node[MAX];
vector<string> word;

bool onediff(const string& a, const string& b) {
    int ret = 0;
    int SIZE = a.size();
    for (int i = 0; i < SIZE; i++) {
        if (a[i] != b[i]) ret++;
        if (ret > 1) return false;
    }
    return ret == 1;
}

int bfs(int cur, string& target) {
    queue<pair<int, int>> q;
    chk[cur] = true;
    q.push({ cur, 0 });
    while (!q.empty()) {
        int idx = q.front().first;
        int cnt = q.front().second;
        q.pop();
        string str = word[idx];

        if (str == target) return cnt;

        for (auto& next : node[idx]) {
            if (chk[next]) continue;
            chk[next] = true;
            q.push({ next, cnt + 1 });
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);
    for (int i = 0; i < words.size() - 1; i++) {
        for (int j = i + 1; j < words.size(); j++) {
            if (onediff(words[i], words[j])) {
                node[i].push_back(j);
                node[j].push_back(i);
            }
        }
    }
    word = words;

    return bfs(words.size() - 1, target);
}