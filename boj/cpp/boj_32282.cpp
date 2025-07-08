// https://www.acmicpc.net/problem/32282

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int X, Y;
    double c;
    cin >> X >> Y >> c;

    if (!X && !Y) {
        cout << 0;
        return 0;
    }

    double dist = sqrt(X * X + Y * Y);
    const double EPS = 1e-9;

    if (fabs(dist - c) < EPS) {
        cout << 1;
    } else if (dist < c) {
        cout << 2;
    } else {
        cout << (int)ceil(dist / c);
    }

    return 0;
}
