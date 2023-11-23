#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& s : scoville) {
        pq.push(s);
    }
    
    bool flag = false;
    while (pq.size() > 1) {
        int fir = pq.top(); pq.pop();
        if (fir >= K) {
            flag = true;
            break;
        }
        
        int sec = pq.top(); pq.pop();
        pq.push(fir + sec * 2);
        
        answer++;
    }
    
    if (pq.top() >= K) flag = true;
    
    return flag ? answer : -1;
}