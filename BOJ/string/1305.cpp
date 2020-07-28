//1305

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define MAXSIZE 1000005
	
typedef long long ll;

int saveT[MAXSIZE];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int L;
	string T;

	//input
	cin >> L >> T;

	int idxT = 0;

	//make saveT
	for (int i = 1; i < T.size(); i++) {
		while (idxT > 0 && T[i] != T[idxT])
			idxT = saveT[idxT - 1];
		if (T[i] == T[idxT])
			saveT[i] = ++idxT;
	}

	int P_len = T.size() - saveT[T.size() - 1];

	//answer
	cout << P_len;

	return 0;
}