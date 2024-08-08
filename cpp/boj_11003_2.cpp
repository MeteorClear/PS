// https://www.acmicpc.net/problem/11003

#include <iostream>
#include <deque>

using namespace std;

struct E {
    int a;
    int idx;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, L;
    cin >> N >> L;
    
    deque<E> dq;
    
    for (int i=0; i<N; i++) {
        int A;
        cin >> A;
        
        while (!dq.empty() && i-dq.front().idx >= L) dq.pop_front();
        while (!dq.empty() && dq.back().a >= A) dq.pop_back();
        
        dq.push_back({A, i});
        
        cout << dq.front().a << ' ';
    }

    return 0;
}
