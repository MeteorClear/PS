// https://www.acmicpc.net/problem/11279

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int> pq;
    
    int N;
    cin >> N;
    
    while (N--) {
        int x;
        cin >> x;
        
        if (x) {
            pq.push(x);
            continue;
        }
        
        if (pq.empty()) {
            cout << "0\n";
            continue;
        }
        
        cout << pq.top() << '\n';
        pq.pop();
    }
    
    return 0;
}
