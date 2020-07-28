//10266

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
#define MAXSIZE 360001

typedef long long ll;

int saveP[MAXSIZE];
int strT[MAXSIZE], strP[MAXSIZE];
string T, P;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	//input
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		strT[input]++;
	}
	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		strP[input]++;
	}

	for (int i = 0; i < MAXSIZE - 1; i++) T += strT[i] + '0';
	for (int i = 0; i < MAXSIZE - 1; i++) P += strP[i] + '0';

	T += T;

	int idxP = 0;

	//make saveP
	for (int i = 1; i < P.size(); i++) {
		while (idxP > 0 && P[i] != P[idxP])
			idxP = saveP[idxP - 1];
		if (P[i] == P[idxP])
			saveP[i] = ++idxP;
	}

	//process
	idxP = 0;
	bool ans = false;
	for (int i = 0; i < 2 * (MAXSIZE-1) - 1; i++) {
		//불일치
		while (idxP > 0 && T[i] != P[idxP])
			idxP = saveP[idxP - 1];
		//일치
		if (T[i] == P[idxP]) {
			if (idxP == P.size() - 1) {
				ans = true;
				break;
				//idxP = saveP[idxP];
			}
			else {
				idxP++;
			}
		}
	}

	//answer
	if (ans) cout << "possible";
	else cout << "impossible";

	return 0;
}