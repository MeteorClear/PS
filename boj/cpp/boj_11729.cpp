// https://www.acmicpc.net/problem/11729

#include <iostream>

using namespace std;

void hanoi(int n, int from, int by, int to) {
    if (n == 0) return;
    
    hanoi(n-1, from, to, by);
    
    cout << from << ' ' << to << '\n';
    
    hanoi(n-1, by, from, to);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    cout << (1<<N)-1 << '\n';
    hanoi(N, 1, 2, 3);

    return 0;
}
