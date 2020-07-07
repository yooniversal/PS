//1408

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	 //ios_base::sync_with_stdio(false);

	int shour, smin, ssec, ehour, emin, esec, s, e;
	string start, end;

	cin >> start >> end;

	shour = (start[0]-'0') * 10 + (start[1] - '0');
	smin = (start[3] - '0') * 10 + (start[4] - '0');
	ssec = (start[6] - '0') * 10 + (start[7] - '0');
	ehour = (end[0] - '0') * 10 + (end[1] - '0');
	emin = (end[3] - '0') * 10 + (end[4] - '0');
	esec = (end[6] - '0') * 10 + (end[7] - '0');

	s = shour * 3600 + smin * 60 + ssec;
	e = ehour * 3600 + emin * 60 + esec;

	if (s < e) {
		e -= s;
		printf("%02d:", e / 3600);
		e %= 3600;
		printf("%02d:", e / 60);
		e %= 60;
		printf("%02d", e);
	}
	else {
		s = 86400 - (s - e);
		printf("%02d:", s / 3600);
		s %= 3600;
		printf("%02d:", s / 60);
		s %= 60;
		printf("%02d", s);
	}

	return 0;
}