// https://www.acmicpc.net/problem/11399
// 11399번 ATM
// 정렬, 그리디 문제
// 인출 시간을 오름차순 정렬한 후 누적 합을 구해 총합을 구해 해결 가능
// 각 사람이 돈을 인출하는데 필요한 시간의 합은 인출 시간이 짧은 사람을 앞에 배치할수록 줄어듬

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> P(N);
    for (int i=0; i<N; ++i) cin >> P[i];
    
    sort(P.begin(), P.end());
    
    int res = 0, sum = 0;
    for (int i=0; i<N; ++i) {
        sum += P[i];
        res += sum;
    }
    
    cout << res;
    
    return 0;
}
