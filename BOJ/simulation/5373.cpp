//5373
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 2000000001, MOD = 1000000007;

void Reverseclockwise(vector<vector<char>>& cube, int block) {
	vector<char> tmp = cube[block];
	cube[block][6] = tmp[0];
	cube[block][7] = tmp[3];
	cube[block][8] = tmp[6];
	cube[block][5] = tmp[7];
	cube[block][2] = tmp[8];
	cube[block][1] = tmp[5];
	cube[block][0] = tmp[2];
	cube[block][3] = tmp[1];
}

void clockwise(vector<vector<char>>& cube, int block) {
	vector<char> tmp = cube[block];
	cube[block][2] = tmp[0];
	cube[block][5] = tmp[1];
	cube[block][8] = tmp[2];
	cube[block][7] = tmp[5];
	cube[block][6] = tmp[8];
	cube[block][3] = tmp[7];
	cube[block][0] = tmp[6];
	cube[block][1] = tmp[3];
}

void U(vector<vector<char>>& cube, int dir) {
	if (dir) {
		swap(cube[0][6], cube[3][8]);
		swap(cube[0][7], cube[3][5]);
		swap(cube[0][8], cube[3][2]);
		swap(cube[3][2], cube[2][0]);
		swap(cube[3][5], cube[2][1]);
		swap(cube[3][8], cube[2][2]);
		swap(cube[2][0], cube[4][6]);
		swap(cube[2][1], cube[4][3]);
		swap(cube[2][2], cube[4][0]);

		clockwise(cube, 1);
	}
	else {
		swap(cube[0][6], cube[4][0]);
		swap(cube[0][7], cube[4][3]);
		swap(cube[0][8], cube[4][6]);
		swap(cube[4][0], cube[2][2]);
		swap(cube[4][3], cube[2][1]);
		swap(cube[4][6], cube[2][0]);
		swap(cube[2][2], cube[3][8]);
		swap(cube[2][1], cube[3][5]);
		swap(cube[2][0], cube[3][2]);

		Reverseclockwise(cube, 1);
	}
}

void D(vector<vector<char>>& cube, int dir) {
	if (dir) {
		swap(cube[0][0], cube[4][2]);
		swap(cube[0][1], cube[4][5]);
		swap(cube[0][2], cube[4][8]);
		swap(cube[4][2], cube[2][8]);
		swap(cube[4][5], cube[2][7]);
		swap(cube[4][8], cube[2][6]);
		swap(cube[2][8], cube[3][6]);
		swap(cube[2][7], cube[3][3]);
		swap(cube[2][6], cube[3][0]);

		clockwise(cube, 5);
	}
	else {
		swap(cube[0][0], cube[3][6]);
		swap(cube[0][1], cube[3][3]);
		swap(cube[0][2], cube[3][0]);
		swap(cube[3][6], cube[2][8]);
		swap(cube[3][3], cube[2][7]);
		swap(cube[3][0], cube[2][6]);
		swap(cube[2][8], cube[4][2]);
		swap(cube[2][7], cube[4][5]);
		swap(cube[2][6], cube[4][8]);

		Reverseclockwise(cube, 5);
	}
}

void F(vector<vector<char>>& cube, int dir) {
	if (dir) {
		for (int next : {6, 7, 8}) swap(cube[5][next], cube[4][next]);
		for (int next : {6, 7, 8}) swap(cube[4][next], cube[1][next]);
		for (int next : {6, 7, 8}) swap(cube[1][next], cube[3][next]);

		clockwise(cube, 2);
	}
	else {
		for (int next : {6, 7, 8}) swap(cube[3][next], cube[1][next]);
		for (int next : {6, 7, 8}) swap(cube[1][next], cube[4][next]);
		for (int next : {6, 7, 8}) swap(cube[4][next], cube[5][next]);

		Reverseclockwise(cube, 2);
	}
}

void B(vector<vector<char>>& cube, int dir) {
	if (dir) {
		for (int next : {0, 1, 2}) swap(cube[3][next], cube[1][next]);
		for (int next : {0, 1, 2}) swap(cube[1][next], cube[4][next]);
		for (int next : {0, 1, 2}) swap(cube[4][next], cube[5][next]);

		clockwise(cube, 0);
	}
	else {
		for (int next : {0, 1, 2}) swap(cube[5][next], cube[4][next]);
		for (int next : {0, 1, 2}) swap(cube[4][next], cube[1][next]);
		for (int next : {0, 1, 2}) swap(cube[1][next], cube[3][next]);

		Reverseclockwise(cube, 0);
	}
}

void L(vector<vector<char>>& cube, int dir) {
	if (dir) {
		for (int i = 1; i >= 0; --i)
			for (int next : {0, 3, 6})
				swap(cube[i][next], cube[i + 1][next]);
		swap(cube[5][8], cube[0][0]);
		swap(cube[5][5], cube[0][3]);
		swap(cube[5][2], cube[0][6]);

		clockwise(cube, 3);
	}
	else {
		swap(cube[5][8], cube[0][0]);
		swap(cube[5][5], cube[0][3]);
		swap(cube[5][2], cube[0][6]);
		for (int i = 0; i <= 1; ++i)
			for (int next : {0, 3, 6})
				swap(cube[i][next], cube[i + 1][next]);

		Reverseclockwise(cube, 3);
	}
}

void R(vector<vector<char>>& cube, int dir) {
	if (dir) {
		swap(cube[5][6], cube[0][2]);
		swap(cube[5][3], cube[0][5]);
		swap(cube[5][0], cube[0][8]);
		for (int i = 0; i <= 1; ++i)
			for (int next : {2, 5, 8})
				swap(cube[i][next], cube[i + 1][next]);

		clockwise(cube, 4);
	}
	else {
		for (int i = 1; i >= 0; --i)
			for (int next : {2, 5, 8})
				swap(cube[i][next], cube[i + 1][next]);
		swap(cube[5][6], cube[0][2]);
		swap(cube[5][3], cube[0][5]);
		swap(cube[5][0], cube[0][8]);

		Reverseclockwise(cube, 4);
	}
}

void print(vector<vector<char>>& cube) {
	for (int i : {0, 3, 6}) {
		printf("    %c%c%c\n", cube[0][i], cube[0][i+1], cube[0][i+2]);
	}
	cout << "    ---\n";
	
	for (int i : {0, 3, 6}) {
		for (int block : {3, 1, 4, 5}) {
			printf("%c%c%c", cube[block][i], cube[block][i + 1], cube[block][i + 2]);
			if (block != 5) cout << '|';
		}
		cout << '\n';
	}
	cout << "    ---\n";
	for (int i : {0, 3, 6}) {
		printf("    %c%c%c\n", cube[2][i], cube[2][i + 1], cube[2][i + 2]);
	}
	cout << '\n';
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<char>> cube;
	cube.push_back(vector<char>(10, 'o'));
	cube.push_back(vector<char>(10, 'w'));
	cube.push_back(vector<char>(10, 'r'));
	cube.push_back(vector<char>(10, 'g'));
	cube.push_back(vector<char>(10, 'b'));
	cube.push_back(vector<char>(10, 'y'));

	int t; cin >> t;
	while (t--) {
		vector<vector<char>> cur = cube;
		int n; cin >> n;
		while (n--) {
			string oper; cin >> oper;
			int dir = oper[1] == '+' ? 1 : 0;
			if (oper[0] == 'U') U(cur, dir);
			else if (oper[0] == 'D') D(cur, dir);
			else if (oper[0] == 'F') F(cur, dir);
			else if (oper[0] == 'B') B(cur, dir);
			else if (oper[0] == 'L') L(cur, dir);
			else R(cur, dir);

			//printf("remain n:%d print::\n", n);
			//print(cur);
		}

		//À­¸é Ãâ·Â
		for (int i = 0; i < 9; ++i) {
			if (i != 0 && i % 3 == 0) cout << '\n';
			cout << cur[1][i];
		}
		cout << '\n';
	}

	return 0;
}