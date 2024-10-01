// https://www.acmicpc.net/problem/1620

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    map<string, int> book;
    map<int, string> idxBook;
    
    for (int i=1; i<=N; ++i) {
        string name;
        cin >> name;
        book[name] = i;
        idxBook[i] = name;
    }
    
    while (M--) {
        string temp;
        cin >> temp;
        
        try {
            int num = stoi(temp);
            cout << idxBook[num] << '\n';
        } catch (...) {
            cout << book[temp] << '\n';
        }
    }

    return 0;
}
