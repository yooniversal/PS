//18258

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, temp;
	string str;
	queue<int> q;

	cin >> n;
	while (n--) {
		cin >> str;

		if (!(str.compare("push"))) {
			cin >> temp;
			q.push(temp);
		}
		else if (!(str.compare("pop"))) {
			if (q.size() == 0)
				cout << "-1" << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (!(str.compare("size")))
			cout << q.size() << "\n";
		else if (!(str.compare("empty")))
			if (q.size() == 0)
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		else if (!(str.compare("front")))
			if (q.size() == 0)
				cout << "-1" << "\n";
			else
				cout << q.front() << "\n";
		else if (!(str.compare("back")))
			if (q.size() == 0)
				cout << "-1" << "\n";
			else
				cout << q.back() << "\n";
	}

	return 0;
}