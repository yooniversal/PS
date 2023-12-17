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

bool isSame(int a, int b, int c) {
    return (a == b && b != c) ||
    (b == c && c != a) ||
    (a == c && c != b);
}

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b, c; cin >> a >> b >> c;
    int sum = a + b + c;
    
    if (a == 60 && b == 60 && c == 60) {
        cout << "Equilateral\n";
    } else if (sum != 180) {
        cout << "Error\n";
    } else {
        if (isSame(a, b, c)) {
            cout << "Isosceles\n";
        } else {
            cout << "Scalene\n";
        }
    }

    return 0;
}