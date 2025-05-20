// https://www.acmicpc.net/problem/8979

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Score {
    int id;
    int gold;
    int silver;
    int bronze;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    vector<Score> leaderboard;
    for (int i=0; i<N; ++i) {
        int id, gold, silver, bronze;
        cin >> id >> gold >> silver >> bronze;
        leaderboard.push_back({id, gold, silver, bronze});
    }
    
    sort(leaderboard.begin(), leaderboard.end(), [](const Score& a, const Score& b){
       return tie(a.gold, a.silver, a.bronze) > tie(b.gold, b.silver, b.bronze);
    });
    
    Score base;
    for (int i=0; i<N; ++i) {
        if (leaderboard[i].id == K) {
            base = leaderboard[i];
            break;
        }
    }
    
    int rank = 1;
    for (const auto& now : leaderboard) {
        if(now.gold == base.gold && now.silver == base.silver && now.bronze == base.bronze) break;
        ++rank;
    }
    
    cout << rank;

    return 0;
}
