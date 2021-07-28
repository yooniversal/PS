#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

map<string, int> m;
int last = 26;

//���� ���� ���� �Ǵ�
//�����ϴ� �ܾ��� �ε���, ���� ��ȣ ��ȯ
pair<int, int> exist(string& s, int idx) {
    string cur = ""; cur += s[idx];
    for (int i = idx + 1; i < s.size(); i++) {
        cur += s[i];
        //�������� ������ ��ȯ
        //�������� �������� �ǹ�
        if (!m[cur]) {
            m[cur] = ++last;
            cur.pop_back();
            return { i - 1, m[cur] };
        }
    }
    return { s.size() - 1, m[cur] };
}

vector<int> solution(string msg) {
    vector<int> answer;

    for (int i = 0; i < 26; i++) {
        string s = ""; s += 'A' + i;
        m[s] = i + 1;
    }

    int i = 0;
    while (i != msg.size()) {
        pair<int, int> result = exist(msg, i);
        answer.push_back(result.second);
        i = result.first + 1;
    }

    return answer;
}