//1786

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
int saveP[MAXSIZE];
int idxP;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	getline(cin, T);
	getline(cin, P);

	//make saveP
	for (int i = 1; i < P.size(); i++) {
		while (idxP>0 && P[i] != P[idxP])
			idxP = saveP[idxP-1];
		if (P[i] == P[idxP])
			saveP[i] = ++idxP;
	}

	//process
	idxP = 0;
	vector<int> ans;
	for (int i = 0; i < T.size(); i++) {
		//불일치
		while (idxP > 0 && T[i] != P[idxP])
			idxP = saveP[idxP - 1];
		//일치
		if (T[i] == P[idxP]) {
			//모든 문자열 일치
			if (idxP == P.size() - 1) {
				ans.push_back(i - idxP + 1);
				idxP = saveP[idxP]; //마지막 위치가 반복되는 문자일 수 있음
			}
			//부분 문자열 일치
			else {
				idxP++;
			}
		}
	}

	//answer
	cout << ans.size() << '\n';
	for (auto& a : ans) cout << a << " ";

	return 0;
}