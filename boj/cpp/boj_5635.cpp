// https://www.acmicpc.net/problem/5635

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int dd;
    int mm;
    int yyyy;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<Student> students;
    
    while (N--) {
        string name;
        int dd, mm, yyyy;
        cin >> name >> dd >> mm >> yyyy;
        students.push_back({name, dd, mm, yyyy});
    }
    
    sort(students.begin(), students.end(), [](const Student& a, const Student& b){
        if (a.yyyy != b.yyyy) return a.yyyy < b.yyyy;
        if (a.mm != b.mm) return a.mm < b.mm;
        return a.dd < b.dd;
    });
    
    cout << (*(students.end()-1)).name << '\n' << (*students.begin()).name;

    return 0;
}
