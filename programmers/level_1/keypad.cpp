#include <string>
#include <vector>

using namespace std;

int dist(int s, int e) {
    int sy = s / 3, sx = s % 3;
    int ey = e / 3, ex = e % 3;

    if (sx == 0) {
        sx = 3; sy--;
    }
    if (ex == 0) {
        ex = 3; ey--;
    }

    if (s == 0) {
        sy = 3; sx = 2;
    }
    if (e == 0) {
        ey = 3; ex = 2;
    }

    return abs(sy - ey) + abs(sx - ex);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int l = 10, r = 12; // *=10, #=12

    for (int i = 0; i < numbers.size(); i++) {
        //1, 3, 7은 무조건 왼쪽 손가락
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            l = numbers[i];
            answer += 'L';
        }
        //3, 6, 9는 무조건 오른쪽 손가락
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            r = numbers[i];
            answer += 'R';
        }
        //2, 5, 8, 0
        else {
            if (dist(l, numbers[i]) > dist(r, numbers[i])) {
                r = numbers[i];
                answer += 'R';
            }
            else if (dist(l, numbers[i]) < dist(r, numbers[i])) {
                l = numbers[i];
                answer += 'L';
            }
            else if (dist(l, numbers[i]) == dist(r, numbers[i])) {
                if (hand.compare("left") == 0) {
                    l = numbers[i];
                    answer += 'L';
                }
                else {
                    r = numbers[i];
                    answer += 'R';
                }
            }
        }
    }

    return answer;
}