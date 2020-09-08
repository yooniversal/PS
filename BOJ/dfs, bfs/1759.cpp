//1759

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
#define INF 1000000000
#define MAX 20001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int L, C;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> L >> C;
	string all = "";
	for (int i = 0; i < C; i++) {
		char a; cin >> a;
		all += a;
	}
	sort(all.begin(), all.end()); //사전순으로 정렬

	vi anssection(C, 0);
	for (int i = 0; i < L; i++) anssection[i] = 1; //1인 부분만 출력

	do {
		string ret = "";
		int cons = 0, vowel = 0; //자음, 모음
		for (int i = 0; i < C; i++) {
			if (anssection[i]) {
				ret += all[i];
				if (all[i] == 'a' || all[i] == 'e' || all[i] == 'i' || all[i] == 'o' || all[i] == 'u') vowel++;
				else cons++;
			}
		}

		if (vowel >= 1 && cons >= 2) {
			cout << ret << '\n';
		}
	} while (prev_permutation(anssection.begin(), anssection.end()));

	return 0;
}