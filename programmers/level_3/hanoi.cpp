#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> ret;

void solve(int from, int tmp, int to, int n) {
    vector<int> v(2);
    if (n == 1) {
        v[0] = from; v[1] = to;
        ret.push_back(v);
        return;
    }
    solve(from, to, tmp, n - 1);
    solve(from, tmp, to, 1);
    solve(tmp, from, to, n - 1);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    solve(1, 2, 3, n);
    return ret;
}