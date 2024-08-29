// https://www.acmicpc.net/problem/10825

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
    string name;
    int kor;
    int eng;
    int mat;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<student> students;
    
    for (int i = 0; i < N; ++i) {
        string tname;
        int tkor, teng, tmat;
        cin >> tname >> tkor >> teng >> tmat;
        students.push_back({tname, tkor, teng, tmat});
    }
    
    sort(students.begin(), students.end(), [](auto& a, auto& b) {
        if (a.kor != b.kor) {
            return a.kor > b.kor;
        }
        if (a.eng != b.eng) {
            return a.eng < b.eng;
        }
        if (a.mat != b.mat) {
            return a.mat > b.mat;
        }
        return a.name < b.name;
    });
    
    for (auto& student : students) {
        cout << student.name << '\n';
    }

    return 0;
}
