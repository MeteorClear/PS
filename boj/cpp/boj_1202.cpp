// https://www.acmicpc.net/problem/1202

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct Jewel {
    int weight, value;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    multiset<int> bag;
    
    int N, K;
    cin >> N >> K;
    
    vector<Jewel> jewels(N);
    
    for (int i=0; i<N; ++i) {
        int M, V;
        cin >> M >> V;
        
        jewels[i].value = V;
        jewels[i].weight = M;
    }
    
    sort(jewels.begin(), jewels.end(), [](const Jewel& a, const Jewel& b) {
        return a.value > b.value;
    });
    
    while (K--) {
        int C;
        cin >> C;
        bag.insert(C);
    }
    
    long long res = 0;
    
    for (auto jewel : jewels) {
        if (bag.empty()) break;
        
        auto iter = bag.lower_bound(jewel.weight);
        if (iter == bag.end()) continue;
        
        res += jewel.value;
        bag.erase(iter);
    }
    
    cout << res;
    
    return 0;
}
