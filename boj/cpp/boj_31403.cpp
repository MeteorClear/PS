// https://www.acmicpc.net/problem/31403

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string A, B;
    int C;
    cin >> A >> B >> C;
    
    cout << stoi(A) + stoi(B) - C << '\n' << stoi(A + B) - C;

    return 0;
}
