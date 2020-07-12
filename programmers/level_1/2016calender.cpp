#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int day = 0;
    for (int i = 1; i < a; i++) {
        if (i == 2) {
            day += 29;
            continue;
        }
        if (i <= 7) {
            if (i % 2 == 1) day += 31;
            else day += 30;
        }
        else {
            if (i % 2 == 1) day += 30;
            else day += 31;
        }
    }
    day += b - 1;
    cout << "day" << day;
    day %= 7;

    if (day == 0) answer = "FRI";
    else if (day == 1) answer = "SAT";
    else if (day == 2) answer = "SUN";
    else if (day == 3) answer = "MON";
    else if (day == 4) answer = "TUE";
    else if (day == 5) answer = "WED";
    else if (day == 6) answer = "THU";
    return answer;
}