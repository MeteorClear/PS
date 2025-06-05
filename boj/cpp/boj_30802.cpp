// https://www.acmicpc.net/problem/30802

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, T, P;
    cin >> N;
    
    int shirt[6];
    for (int i=0; i<6; ++i) {
        cin >> shirt[i];
    }
    
    cin >> T >> P;
    
    int total = 0;
    for (int i=0; i<6; ++i) {
        total += (shirt[i]%T == 0 ? shirt[i] / T : shirt[i] / T + 1);
    }
    
    cout << total << '\n' << N / P << ' ' << N % P;

    return 0;
}
