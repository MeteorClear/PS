// https://www.acmicpc.net/problem/2139

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    const int kMonthLength[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    while (1) {
        int d, m, y;
        cin >> d >> m >> y;
        if (!d && !m && !y) break;
        
        int ord = d;
        for (int i=1; i<m; ++i) {
            ord += kMonthLength[i-1];
            if (i == 2 && ((y%400 == 0) || (y%4 == 0 && y%100 != 0))) ++ord;
        }
        cout << ord << '\n';
    }

    return 0;
}
