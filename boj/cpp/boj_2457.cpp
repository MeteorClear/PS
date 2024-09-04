// https://www.acmicpc.net/problem/2457

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPast(int xM, int xD, int yM, int yD) {
    if (xM == yM) return xD <= yD;
    return xM <= yM;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<vector<int>> S(N, vector<int>(4));
    
    for (int i=0; i<N; ++i) cin >> S[i][0] >> S[i][1] >> S[i][2] >> S[i][3];
    
    stable_sort(S.begin(), S.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });

    int nowM = 3, nowD = 1, res = 0, i = 0;
    while (isPast(nowM, nowD, 11, 30)) {
        int tM=-1, tD=-1;
        bool isChange = false;
        
        while (i < N && isPast(S[i][0], S[i][1], nowM, nowD)) {
            if (isPast(tM, tD, S[i][2], S[i][3])) {
                isChange = true;
                tM = S[i][2]; tD = S[i][3];
            }
            ++i;
        }
        
        if (!isChange) {
            res = 0;
            break;
        }
        
        ++res;
        nowM = tM; nowD = tD;
    }
    
    cout << res;

    return 0;
}
