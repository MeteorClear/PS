// https://www.acmicpc.net/problem/4796

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i=1; ; ++i) {
        int L, P, V;
        cin >> L >> P >> V;
        
        if (!L && !P && !V) break;
        
        cout << "Case " << i << ": " << ((V / P * L) + ((V % P) > L ? L : (V % P))) << '\n';
    }

    return 0;
}
