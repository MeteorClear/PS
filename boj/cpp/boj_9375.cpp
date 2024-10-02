// https://www.acmicpc.net/problem/9375

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        unordered_map<string, int> clothes;
        
        while (n--) {
            string apparel, type;
            cin >> apparel >> type;
            
            if (clothes.find(type) == clothes.end()) {
                clothes[type] = 1;
            } else {
                clothes[type] += 1;
            }
        }
        
        int res = 1;
        for (auto [key, value] : clothes) res *= value + 1;
        
        cout << res-1 << '\n';
    }
    
    return 0;
}
