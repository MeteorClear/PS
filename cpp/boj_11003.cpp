// https://www.acmicpc.net/problem/11003

#include <iostream>
#include <deque>
#include <queue>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, L, A;
    cin >> N >> L;
    
    deque<int> dq;
    priority_queue<int, vector<int>, greater<int>> pq, ban;
    
    while (N--) {
        cin >> A;
        
        dq.push_back(A);
        pq.push(A);
        
        if (dq.size() > L) {
            ban.push(dq.front());
            dq.pop_front();
            while(!ban.empty() && ban.top() <= pq.top()) {
                ban.pop();
                pq.pop();
            }
        }
        
        cout << pq.top() << ' ';
    }

    return 0;
}
