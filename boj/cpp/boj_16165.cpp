// https://www.acmicpc.net/problem/16165

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    unordered_map<string, vector<string>> members;
    unordered_map<string, string> agency;
    
    while (N--) {
        string gname;
        cin >> gname;
        
        members[gname] = {};
        
        int num;
        cin >> num;
        
        while (num--) {
            string name;
            cin >> name;
            
            members[gname].push_back(name);
            agency[name] = gname;
        }
    }
    
    while (M--) {
        string question;
        int type;
        cin >> question >> type;
        
        if (type) {
            cout << agency[question] << '\n';
        } else {
            auto res = members[question];
            sort(res.begin(), res.end());
            
            for (auto e : res) {
                cout << e << '\n';
            }
        }
    }
    
    return 0;
}
