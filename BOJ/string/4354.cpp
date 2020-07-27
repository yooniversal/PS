//4354

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

string T, P;
int saveT[MAXSIZE];
int prime[MAXSIZE];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		//input
		cin >> T;

		//Á¾·á
		if (T[0] == '.' && T.size() == 1) return 0;

		memset(saveT, 0, sizeof(saveT));
		int idxT = 0;

		//make saveT
		for (int i = 1; i < T.size(); i++) {
			while (idxT > 0 && T[i] != T[idxT])
				idxT = saveT[idxT - 1];
			if (T[i] == T[idxT])
				saveT[i] = ++idxT;
		}

		int P_len = 0;
		for (int i = T.size() - 1; i >= 0; i--) {
			if (saveT[i] == 1) {
				P_len = i;
				break;
			}
		}

		//answer
		if (T.size() % P_len == 0) cout << T.size() / P_len << '\n';
		else cout << "1" << '\n';
	}

	return 0;
}