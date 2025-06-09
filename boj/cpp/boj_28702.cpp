// https://www.acmicpc.net/problem/28702

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int i=3, n;
    for (; i>0; --i) {
        string s;
        cin >> s;
        if (s == "FizzBuzz" || s == "Fizz" || s == "Buzz") continue;
        n = stoi(s) + i;
        break;
    }
    
    if (n%3 == 0 && n%5 == 0) {
        cout << "FizzBuzz";
    } else if (n%3 == 0) {
        cout << "Fizz";
    } else if (n%5 == 0) {
        cout << "Buzz";
    } else {
        cout << n;
    }
    
    return 0;
}
