#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> count_monsters_left(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<int> result;
    vector<pair<int, int>> monsters;
    for (int i = 0; i < A.size(); i++) {
        for (int j = A[i][0]; j <= A[i][1]; j++) {
            monsters.push_back(make_pair(j, A[i][2]));
        }
    }
    sort(B.begin(), B.end());
    int index = 0;
    for (int i = 0; i < B.size(); i++) {
        int hero_pos = B[i][0];
        int hero_strength = B[i][1];
        while (index < monsters.size() && monsters[index].first <= hero_pos) {
            if (monsters[index].second <= hero_strength) {
                index++;
            } else {
                monsters[index].second -= hero_strength;
                if (monsters[index].second <= 0) {
                    index++;
                }
            }
        }
        result.push_back(monsters.size() - index);
    }
    return result;
}


int main() {
    vector<vector<int>> A {{1, 3, 7}, {2, 5, 4}, {4,8,6}};
    vector<vector<int>> B {{3, 5}, {5, 8}};

    // cout<< count_monsters_left(A, B);
     vector<int> result = count_monsters_left(A, B);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    //  cout << "Number of monsters left: " << monsters_left << endl;

    return 0;
}
