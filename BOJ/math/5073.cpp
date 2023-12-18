#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int INF = 987654321;

bool isTriangle(int a, int b, int c) {
    if (a < b) swap(a, b);
    if (a < c) swap(a, c);
    return a < (b + c);
}

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b, c;
    while (1) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;

        if (!isTriangle(a, b, c)) {
            cout << "Invalid\n";
            continue;
        }

        if (a == b && b == c) {
            cout << "Equilateral\n";
            continue;
        }

        if ((a == b && b != c) || (b == c && a != b) || (a == c && b != c)) {
            cout << "Isosceles\n";
            continue;
        }

        cout << "Scalene\n";
    }

    return 0;
}