// https://www.acmicpc.net/problem/9996

#include <iostream>
#include <regex>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    string match_pattern;
    cin >> N >> match_pattern;
    
    auto pos = match_pattern.find("*", 0);
    if (pos != string::npos) match_pattern.replace(pos, 1, ".*");
    
    regex pattern(match_pattern);
    
    while (N--) {
        string file_name;
        cin >> file_name;
        
        if (regex_match(file_name, pattern)) cout << "DA\n";
        else cout << "NE\n";
    }

    return 0;
}
