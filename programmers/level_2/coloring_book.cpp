#include <vector>
#include <iostream>
using namespace std;
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,1,-1 };
int area;
bool chk[101][101];
void dfs(int y, int x, int n, int m, int key, vector<vector<int>>& picture) {
    chk[y][x] = true;
    area++;

    for (int i = 0; i < 4; i++) {
        int hy = y + dy[i], hx = x + dx[i];
        //������ �����
        if (hy < 0 || hy >= m || hx < 0 || hx >= n) continue;
        //�̹� üũ�� �ڸ����
        if (chk[hy][hx]) continue;
        //���� ������ �ƴ϶��
        if (picture[hy][hx] != key) continue;

        dfs(hy, hx, n, m, key, picture);
    }
}
int max(int a, int b) {
    if (a > b) return a;
    else return b;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            chk[i][j] = false;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            //üũ�� �ȵư� ��ĥ�� �����̶��
            if (!chk[i][j] && picture[i][j]) {
                area = 0;
                dfs(i, j, n, m, picture[i][j], picture);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, area);
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}