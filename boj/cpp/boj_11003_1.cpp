// https://www.acmicpc.net/problem/11003

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, L, A;
    cin >> N >> L;
    
    priority_queue<pair<int, int>> pq;
    
    for(int i=1; i<=N; i++) {
        cin >> A;
        pq.push({-A, i});
        
        while(!pq.empty() && i-pq.top().second >= L) {
            pq.pop();
        }
        
        cout << -(pq.top().first) << ' ';
    }

    return 0;
}
