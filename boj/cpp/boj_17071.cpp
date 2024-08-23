// https://www.acmicpc.net/problem/17071

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    queue<pair<int, int>> q;
    vector<vector<int>> visited(500001, vector<int>(2, -1));
    
    visited[N][0] = 0;
    q.push({N, 0});
    
    while (!q.empty()) {
        auto [curPos, curTime] = q.front();
        q.pop();
        
        int next[3] = {curPos-1, curPos+1, curPos*2};
        for(int dir : next) {
            if (dir < 0 || dir >= 500001) continue;
            if (visited[dir][(curTime+1)%2] != -1) continue;
            
            visited[dir][(curTime+1)%2] = curTime+1;
            q.push({dir, curTime+1});
            
        }
    }
    
    int nowTime = 0, curK = K;
    bool found = false;
    
    while (curK < 500001) {
        if (visited[curK][nowTime%2] != -1 &&visited[curK][nowTime%2] <= nowTime) {
            found = true;
            break;
        }
        ++nowTime;
        curK += nowTime;
    }
    
    cout << (found ? nowTime : -1);

    return 0;
}
