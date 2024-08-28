// https://www.acmicpc.net/problem/16987

#include <iostream>
#include <vector>

using namespace std;

void breakEggs(vector<pair<int, int>>& eggs, int now, int broken, int& count) {
    if (now == eggs.size()) {
        count = max(count, broken);
        return;
    }
    
    if (eggs[now].first <= 0 || broken == eggs.size()-1) {
        breakEggs(eggs, now+1, broken, count);
        return;
    }
    
    for (int i=0; i<eggs.size(); ++i) {
        if (now == i || eggs[i].first <= 0) continue;
        
        eggs[now].first -= eggs[i].second;
        eggs[i].first -= eggs[now].second;
        if (eggs[now].first <= 0) ++broken;
        if (eggs[i].first <= 0) ++broken;
        
        breakEggs(eggs, now+1, broken, count);
        
        if (eggs[i].first <= 0) --broken;
        if (eggs[now].first <= 0) --broken;
        eggs[i].first += eggs[now].second;
        eggs[now].first += eggs[i].second;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, count = 0;
    cin >> N;
    
    vector<pair<int, int>> eggs;
    for (int i=0; i<N; ++i) {
        int S, W;
        cin >> S >> W;
        eggs.push_back({S, W});
    }
    
    breakEggs(eggs, 0, 0, count);
    
    cout << count;

    return 0;
}
