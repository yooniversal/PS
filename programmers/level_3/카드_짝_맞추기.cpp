#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
const int INF = 987654321;

struct P{
    int x, y, cnt;
};

int ret = INF, alive_cnt, alive[7];
int dx[]={-1,1,0,0}, dy[]={0,0,1,-1};
vector<vector<int>> a;

P dist(int x, int y, int kind, bool start){
    if(a[x][y] == kind && start) return {x, y, 1}; //enter
    
    P ret = {-1, -1, INF};
    vector<vector<int>> d(4, vector<int>(4, INF));
    queue<pair<int, int>> q;
    d[x][y] = 0;
    q.push({x, y});
    while(!q.empty()){
        int cx = q.front().first, cy = q.front().second; q.pop();
        if((cx != x || cy != y) && a[cx][cy] == kind) {
            if(ret.x == -1) ret.x = cx;
            if(ret.y == -1) ret.y = cy;
            ret.cnt = min(ret.cnt, d[cx][cy]+1);
            continue;
        }
        
        for(int i=0; i<4; ++i){
            int nx = cx + dx[i], ny = cy + dy[i];
            if(nx<0 || nx>=4 || ny<0 || ny>=4) continue;
            if(d[nx][ny] > d[cx][cy] + 1) {
                d[nx][ny] = d[cx][cy] + 1;
                q.push({nx, ny});
            }
            
            // 1칸 이동에서 캐릭터를 안만났을 때
            // Ctrl 사용
            int ex = nx, ey = ny;
            if(a[nx][ny] == 0){
	            if(i < 2) { 
					while((0 <= ex && ex < 4) && !a[ex][ey]) 
						ex += dx[i]; 
					if(ex<0 || ex>=4) ex -= dx[i];
				}
	            else { 
					while((0 <= ey && ey < 4) && !a[ex][ey]) 
						ey += dy[i];
					if(ey<0 || ey>=4) ey -= dy[i];
				}
            	// Ctrl + 이동
            	if(ex==nx && ey==ny) continue;
                if(d[ex][ey] > d[cx][cy] + 1){
                	d[ex][ey] = d[cx][cy] + 1;
		            q.push({ex, ey});
		        }
            }
        }
    }
    return ret;
}

void solve(int x, int y, int cnt){
    if(alive_cnt == 0){
        ret = min(ret, cnt);
        return;
    }

    for(int i=1; i<=6; ++i){
        if(alive[i] == 0) continue;
        alive[i] -= 2, alive_cnt -= 2;
        P info = dist(x, y, i, 1);
        P info2 = dist(info.x, info.y, i, 0);
        int origin = a[info.x][info.y];
        a[info.x][info.y] = a[info2.x][info2.y] = 0;
        solve(info2.x, info2.y, cnt + info.cnt + info2.cnt);
        a[info.x][info.y] = a[info2.x][info2.y] = origin;
        alive[i] += 2, alive_cnt += 2;
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    a = board;
    for(int i=0; i<4; ++i)
        for(int j=0; j<4; ++j){
            if(board[i][j] == 0) continue;
            ++alive_cnt, ++alive[board[i][j]];
        }
    
    solve(r, c, 0);
    
    return ret;
}
