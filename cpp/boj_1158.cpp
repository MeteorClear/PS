// https://www.acmicpc.net/problem/1158

#include <iostream>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    list<int> l, r;
    int p = 0;
    
    cin >> N >> K;
    
    for (int i=1; i<=N; i++) l.push_back(i);
    
    while (!l.empty()) {
        p = (p + K-1) % l.size();
        
        auto lt = l.begin();
        for (int i=0; i<p; i++) lt++;
        
        r.push_back(*lt);
        l.erase(lt);
    }
    
    cout << "<";
    auto k = r.begin();
    for (int i=0; i<r.size(); i++) {
        cout << *k++;
        if (i != r.size()-1) cout << ", ";
    }
    cout << ">";

    return 0;
}
