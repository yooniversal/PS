//2749

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int n;
vector<vector<long long>> mat;

//°öÇÏ±â ¿¬»ê
vector<vector<long long>> matcal(vector<vector<long long>> a, vector<vector<long long>> b) {
	vector<vector<long long>> tmp(n, vector<long long>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				tmp[i][j] += ((a[i][k] % 1000000) * (b[k][j] % 1000000)) % 1000000;

	return tmp;
}

//divide and conquer
//°ö¼À ¾ÆÀÌµð¾î
vector<vector<long long>> dc(long long b) {
	vector<vector<long long>> t;
	t.resize(n, vector<long long>(n));

	if (b == 1) return mat;
	else {
		t = dc(b / 2);
		if (b % 2 == 1) return matcal(matcal(t, t), mat);
		else return matcal(t, t);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long b;

	cin >> b;
	n = 2;
	mat.resize(n, vector<long long>(n));

	mat[0][0] = 0;
	mat[0][1] = 1;
	mat[1][0] = 1;
	mat[1][1] = 1;

	mat = dc(b);

	cout << mat[0][1] % 1000000;

	return 0;
}