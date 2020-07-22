#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

string dp[2000001] = { "", "1", "2", "4", "11", "12", "14", "21", "22", "24", "41" };

string ddp(int n) {
    if (n == 0) return "4";
    if (n > 2000000) {
        if (n % 3 == 0) return ddp(n / 3 - 1) + ddp(0);
        else return ddp(n / 3) + ddp(n % 3);
    }
    else {
        if (dp[n] != "") return dp[n];
        else {
            if (n % 3 == 0) dp[n] = ddp(n / 3 - 1) + ddp(0);
            else return dp[n] = ddp(n / 3) + ddp(n % 3);
            return dp[n];
        }
    }
}

int main() {
    int n;
    cin >> n;
    cout << ddp(n);

    return 0;
}
