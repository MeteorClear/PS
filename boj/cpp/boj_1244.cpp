// https://www.acmicpc.net/problem/1244

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num_switch;
    cin >> num_switch;
    
    bool switch_[num_switch];
    for (int i=0; i<num_switch; ++i) {
        cin >> switch_[i];
    }
    
    int num_student;
    cin >> num_student;
    while (num_student--) {
        int gender, switch_num;
        cin >> gender >> switch_num;
        
        if (gender == 1) {
            for (int i=switch_num-1; i<num_switch; i+=switch_num) {
                switch_[i] = !switch_[i];
            }
        } else if (gender == 2) {
            --switch_num;
            switch_[switch_num] = !switch_[switch_num];
            int lp = switch_num-1, rp = switch_num+1;
            while (lp >= 0 && rp < num_switch) {
                if (switch_[lp] == switch_[rp]) {
                    switch_[lp] = !switch_[lp];
                    switch_[rp] = !switch_[rp];
                    --lp; ++rp;
                } else break;
            }
        }
    }
    
    for (int i=0; i<num_switch; ++i) {
        if (i > 0 && i % 20 == 0) cout << '\n';
        cout << switch_[i] << ' ';
    }

    return 0;
}
