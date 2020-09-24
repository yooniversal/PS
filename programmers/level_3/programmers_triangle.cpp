#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
const int MAX = 501;

vector<vector<int>> board;
int cache[MAX][MAX];
int n;

int f(int x, int y) {
    if (x == n) return 0;
    int& ret = cache[x][y];
    if (ret != -1) return ret;
    ret = max(ret, f(x + 1, y) + board[x][y]);
    ret = max(ret, f(x + 1, y + 1) + board[x][y]);
    return ret;
}

int solution(vector<vector<int>> triangle) {
    n = triangle.size();
    board = triangle;
    memset(cache, -1, sizeof(cache));
    return f(0, 0);
}