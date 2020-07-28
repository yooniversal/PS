//11585

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

int saveP[MAXSIZE];

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int GCD(int a, int b) {
	if (a < b) swap(&a, &b);

	while (b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string T, P;

	//input
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		P += c;
	}
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		T += c;
	}
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
	int cnt = 0;
	for (int i = 0; i < 2*n-1; i++) {	
		//불일치
		while (idxP > 0 && T[i] != P[idxP])
			idxP = saveP[idxP - 1];
		//일치
		if (T[i] == P[idxP]) {
			if (idxP == P.size() - 1) {
				cnt++;
				idxP = saveP[idxP];
			}
			else {
				idxP++;
			}
		}
	}

	//answer
	cout << cnt / GCD(n, cnt) << "/" << n / GCD(n, cnt);

	return 0;
}