#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

//banned_id�� ��ġ�� ���� ������ üũ�ϱ� �����
//id ��ȣ�� ���ڸ��ϱ� ��� ��Ƽ� �����ϰ� map�� ���� üũ����

bool numused[10];
map<string, bool> chk;
vector<int> ban[10];
int FULL;
int ret;

void dfs(int cur, string s) {
    if (cur == FULL) {
        sort(s.begin(), s.end());
        if (!chk[s]) {
            chk[s] = true;
            ++ret;
        }
        return;
    }

    for (auto& next : ban[s.size()]) {
        if (numused[next]) continue;
        numused[next] = true;
        string tmp = s;
        tmp += next + '0';
        dfs(cur + 1, tmp);
        numused[next] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    FULL = banned_id.size();

    for (int i = 0; i < banned_id.size(); ++i) {
        for (int j = 0; j < user_id.size(); ++j) {
            if (banned_id[i].size() != user_id[j].size()) continue;
            bool flag = true;
            for (int k = 0; k < FULL; ++k)
                if (banned_id[i][k] != '*' && banned_id[i][k] != user_id[j][k]) {
                    flag = false; break;
                }
            if (flag) ban[i].push_back(j);
        }
    }

    string s;
    dfs(0, s);

    return ret;
}