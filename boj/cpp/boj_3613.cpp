// https://www.acmicpc.net/problem/3613

#include <iostream>
#include <string>

using namespace std;

bool CheckJavaStyle(string& name) {
    if (name.empty() || (name[0] >= 'A' && name[0] <= 'Z')) return false;
    for (char c : name) {
        if (c == '_') return false;
    }
    return true;
}

bool CheckCppStyle(string& name) {
    if (name.empty() || name[0] == '_' || name.back() == '_') return false;
    bool last_is_underscore = false;

    for (char c : name) {
        if (c >= 'A' && c <= 'Z') return false;
        if (c == '_') {
            if (last_is_underscore) return false;
            last_is_underscore = true;
        } else {
            last_is_underscore = false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string variable_name;
    cin >> variable_name;

    bool is_java = CheckJavaStyle(variable_name);
    bool is_cpp = CheckCppStyle(variable_name);

    if (!is_java && !is_cpp) {
        cout << "Error!";
        return 0;
    }

    if (is_java) {
        for (char c : variable_name) {
            if (c >= 'A' && c <= 'Z') {
                cout << '_' << char(c + 32);
            } else {
                cout << c;
            }
        }
    } else {
        bool is_underscore = false;
        for (char c : variable_name) {
            if (c == '_') {
                is_underscore = true;
                continue;
            }
            if (is_underscore) {
                cout << char(c - 32);
                is_underscore = false;
            } else {
                cout << c;
            }
        }
    }

    return 0;
}
