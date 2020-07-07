//10808

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	int a=0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h=0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0, r = 0, s = 0, t=0, u=0, v = 0, w = 0, x = 0, y = 0, z = 0;


	cin >> str;
	for (int qq = 0; qq < str.size(); qq++) {
		if (str[qq] == 'a') a++;
		else if (str[qq] == 'b') b++;
		else if (str[qq] == 'c') c++;
		else if (str[qq] == 'd') d++;
		else if (str[qq] == 'e') e++;
		else if (str[qq] == 'f') f++;
		else if (str[qq] == 'g') g++;
		else if (str[qq] == 'h') h++;
		else if (str[qq] == 'i') i++;
		else if (str[qq] == 'j') j++;
		else if (str[qq] == 'k') k++;
		else if (str[qq] == 'l') l++;
		else if (str[qq] == 'm') m++;
		else if (str[qq] == 'n') n++;
		else if (str[qq] == 'o') o++;
		else if (str[qq] == 'p') p++;
		else if (str[qq] == 'q') q++;
		else if (str[qq] == 'r') r++;
		else if (str[qq] == 's') s++;
		else if (str[qq] == 't') t++;
		else if (str[qq] == 'u') u++;
		else if (str[qq] == 'v') v++;
		else if (str[qq] == 'w') w++;
		else if (str[qq] == 'x') x++;
		else if (str[qq] == 'y') y++;
		else if (str[qq] == 'z') z++;
	}

	cout << a <<" " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " " << j << " " << k << " " << l << " " << m << " " << n << " " << o << " " << p << " " << q << " " << r << " " << s << " " << t << " " << u << " " << v << " " << w << " " << x << " " << y << " " << z << "\n";

	return 0;
}