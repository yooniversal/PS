#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string Nximal(int n, int target) {
    if (target == 0) return "0";
    string ret = "";

    stack<int> q;
    while (target) {
        q.push(target % n);
        target /= n;
    }

    while (!q.empty()) {
        int a = q.top(); q.pop();
        if (a == 10) ret += 'A';
        else if (a == 11) ret += 'B';
        else if (a == 12) ret += 'C';
        else if (a == 13) ret += 'D';
        else if (a == 14) ret += 'E';
        else if (a == 15) ret += 'F';
        else ret += (a + '0');
    }

    return ret;
}

string f(int n, int t, int m, int p) {
    string ret = "", tmp = "";
    for (int i = 0; tmp.size() < (m + 1) * t; ++i) {
        tmp += Nximal(n, i);
    }

    int idx = p - 1;
    while (ret.size() < t) {
        ret += tmp[idx];
        idx += m;
    }

    return ret;
}

string solution(int n, int t, int m, int p) {
    return f(n, t, m, p);
}