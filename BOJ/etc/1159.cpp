//1159

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

string str;
vector<char> ans;
string fin;
int num[150];
int n, cnt, idx;

bool check() {
	for (int i = 0; i < ans.size(); i++)
		if (ans[i] == str[0]) {
			idx = i;
			return false;
		}
	return true;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int surrend = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;

		//새로운게 들어오면
		if (check() == true) {
			ans.push_back(str[0]);
			num[cnt++] = 1;
		}
		//같은게 있으면
		else {
			num[idx]++;
		}
	}

	for(int i=0; i<cnt; i++)
		if (num[i] >= 5) {
			surrend = 1;
			fin.push_back(ans[i]);
		}

	sort(fin.begin(), fin.end());

	if (!surrend) cout << "PREDAJA";
	else cout << fin;

	return 0;
}