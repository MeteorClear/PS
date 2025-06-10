// https://www.acmicpc.net/problem/14626

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string isbn;
    cin >> isbn;
    
    int sum = 0, pos = -1, checksum = (10 - (isbn[12] - '0')) % 10;
    
    for (int i=0; i<12; ++i) {
        if (isbn[i] == '*') {
            pos = i;
            continue;
        }
        sum += (i & 1 ? 3 : 1) * (isbn[i] - '0');
    }
    
    for (int i=0; i<10; ++i) {
        if ((sum + ((pos & 1 ? 3 : 1) * i)) % 10 == checksum) {
            cout << i;
            break;
        }
    }

    return 0;
}
