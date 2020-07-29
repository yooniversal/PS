#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool right(string p) {
    int ans = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') ans++;
        else ans--;
        if (ans < 0) return false;
    }
    return true;
}

string sol(string p) {
    //�ùٸ� ��ȣ ���ڿ�
    if (right(p)) return p;

    int bracket = 0;
    string u, v;
    //�������� ��ȣ ���ڿ�
    bool balance = false;
    for (int i = 0; i < p.size(); i++) {
        if (balance) {
            v += p[i];
            continue;
        }
        if (p[i] == '(') bracket++;
        else if (p[i] == ')') bracket--;
        u += p[i];
        if (i != 0 && bracket == 0) balance = true;
    }

    string ans;
    //u�� �ùٸ� ��ȣ ���ڿ��̸�
    if (right(u)) {
        ans = u + sol(v);
    }
    else {
        ans = '(' + sol(v) + ')';
        for (int i = 1; i < u.size() - 1; i++)
            if (u[i] == '(') ans += ')';
            else ans += '(';
    }

    return ans;
}

string solution(string p) {
    return sol(p);
}