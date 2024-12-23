// https://www.acmicpc.net/problem/1459

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long X, Y, W, S, diagonal_section[3], straight_section[3];
    cin >> X >> Y >> W >> S;
    
    diagonal_section[0] = min(X, Y) * S;
    diagonal_section[1] = min(X, Y) * W * 2;
    diagonal_section[2] = min(diagonal_section[0], diagonal_section[1]);
    
    straight_section[0] = ((max(X, Y) - min(X, Y)) / 2 * S * 2) + (((max(X, Y) - min(X, Y)) % 2) * W);
    straight_section[1] = (max(X, Y) - min(X, Y)) * W;
    straight_section[2] = min(straight_section[0], straight_section[1]);

    cout << diagonal_section[2] + straight_section[2];

    return 0;
}
