#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cur_w = 0;
    queue<int> on;

    int i = 0, fin = 0;
    while (fin != truck_weights.size()) {
        if (on.size() == bridge_length) {
            cur_w -= on.front();
            if (on.front() != 0) {
                fin++;
            }
            on.pop();
        }

        if (weight >= cur_w + truck_weights[i]) {
            on.push(truck_weights[i]);
            cur_w += truck_weights[i];
            i++;
        }
        else {
            on.push(0);
        }
        answer++;
    }

    return answer;
}