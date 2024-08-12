// https://www.acmicpc.net/problem/6198

#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    long long res = 0;
    cin >> N;
    
    stack<int> s;
    for (int i=0; i<N; i++) {
        int height;
        cin >> height;
        
        while(!s.empty() && s.top() <= height) {
            s.pop();
        }
        res += (long long)s.size();
        
        s.push(height);
    }
    cout << res;
    
    return 0;
}
