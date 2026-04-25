//Accepted

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    string vowels = "aeiou";
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int group_size = n/5;
        int n_big_groups = n%5;
        string ans = "";
        int i_big = 0;
        for (auto v: vowels) {
            int n_group = group_size;
            if (i_big < n_big_groups) {
                n_group += 1;
                i_big += 1;
            }
            for (int j = 0; j < n_group; j++) {
                ans.push_back(v);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
