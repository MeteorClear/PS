// https://www.acmicpc.net/problem/18110

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    if (!n) {
        cout << 0;
        return 0;
    }
    
    vector<int> level(n);
    for (int i=0; i<n; ++i) {
        cin >> level[i];
    }
    
    sort(level.begin(), level.end());
    int sum = 0, outlier = round((float)n * 0.15);

    for (int i=outlier; i<n-outlier; ++i) {
        sum += level[i];
    }
    cout << round((float)sum / (n - 2 * outlier));
    
    return 0;
}
