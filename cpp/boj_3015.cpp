// https://www.acmicpc.net/problem/3015

#include <iostream>
#include <stack>

using namespace std;

struct P {
    int h;
    int s;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    long long res = 0;
    cin >> N;
    
    stack<P> s;
    
    for (int i=0; i<N; i++) {
        int t;
        cin >> t;
        
        while (!s.empty() && s.top().h < t) {
            res += (long long)s.top().s;
            s.pop();
        }
        
        if (s.empty()) {
            s.push({t, 1});
        } else if (s.top().h == t) {
            int temp = s.top().s;
            res += (long long)temp;
            s.pop();
            
            if (!s.empty()) res ++;
            s.push({t, temp+1});
        } else {
            s.push({t, 1});
            res++;
        }
    }
    
    cout << res;
    
    return 0;
}
