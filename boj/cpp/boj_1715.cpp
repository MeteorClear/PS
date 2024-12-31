// https://www.acmicpc.net/problem/1715

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    priority_queue<int> pq;
    
    while (N--) {
        int carddeck;
        cin >> carddeck;
        
        pq.push(-carddeck);
    }
    
    int res = 0;
    
    while (pq.size() > 1) {
        int A = -pq.top();
        pq.pop();
        int B = -pq.top();
        pq.pop();
        
        res += A + B;
        pq.push(-(A + B));
    }
    
    cout << res;
    
    return 0;
}
