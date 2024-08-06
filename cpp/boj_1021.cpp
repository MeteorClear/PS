// https://www.acmicpc.net/problem/1021

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, c=0;
    cin >> N >> M;
    
    deque<int> dq;
    
    for (int i=1; i<=N; i++) {
        dq.push_back(i);
    }
    
    while(M--) {
        int target;
        cin >> target;
        
        auto it = find(dq.begin(), dq.end(), target);
        auto rit = find(dq.rbegin(), dq.rend(), target);
        
        int dist = distance(dq.begin(), it);
        int rdist = distance(dq.rbegin(), rit);
        
        if (dist <= rdist) {
            for (int i=0; i<dist; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
                c++;
            }
            dq.pop_front();
        } else {
            for (int i=0; i<rdist+1; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
                c++;
            }
            dq.pop_front();
        }
    }
    cout << c;

    return 0;
}
