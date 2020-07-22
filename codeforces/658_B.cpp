#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;

struct triple {
	int cnt;
	string str;
	vector<int> idx;
	triple(int c, string s) {
		cnt = c;
		str = s;
	}
	triple(int c, string s, vector<int> i) {
		cnt = c;
		str = s;
		idx = i;
	}
};

string oper(string s, int idx) {
	for (int i = 0; i < idx; i++) {
		if (s[i] == '0') s[i] = '1';
		else s[i] = '0';
	}
	string ans = "";
	for (int i = idx - 1; i >= 0; i--)
		ans += s[i];
	for (int i = idx; i < s.size(); i++)
		ans += s[i];

	return ans;
}

void bfs(string s1, string s2) {
	queue<triple> q;
	q.push({ 0, s1});
	while (!q.empty()) {
		int cnt = q.front().cnt;
		string cur = q.front().str;

		//종료 조건
		if (!cur.compare(s2)) {
			cout << cnt << " ";
			for (int i = 0; i < q.front().idx.size(); i++)
				cout << q.front().idx[i] << " ";
			cout << '\n';
			return;
		}

		for (int i = 1; i <= n; i++) {
			vector<int> tmp = q.front().idx;
			tmp.push_back(i);
			q.push({ cnt + 1, oper(cur, i), tmp });
		}

		q.pop();
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n, cnt=0;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] == 1) cnt++;
		}
		
		int key = 0; bool prev = false;
		if (arr[0] == 1) {
			prev = true;
			key++;
		}
		for (int i = 1; i < n; i++) {
			if (prev && arr[i] == 1) key++;
			else prev = false;
		}

		if (cnt == n) {
			if (n % 2) cout << "First" << '\n';
			else cout << "Second" << '\n';
		}
		else {
			if (key % 2) cout << "Second" << '\n';
			else cout << "First" << '\n';
		}
	}

	return 0;
}