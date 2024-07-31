// https://www.acmicpc.net/problem/1475

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    string N;
    int a[10] = {0};
    
    cin >> N;
    for (char n : N) a[n-'0']++;
    
    a[6] = ((a[6]+a[9]) / 2) + ((a[6]+a[9]) & 1);
    
    int m = -1;
    for (int i=0; i<9; i++) m = a[i]>m ? a[i] : m;
    
    cout << m;

    return 0;
}
