#include <bits/stdc++.h>

using namespace std;

vector < int > solve(vector < int > grades){
    vector <int> solution;
    for (int i = 0; i < grades.size(); i++) {
        int grade = grades.at(i);
        if (grade >= 38) {
            int diff = grade % 5;
            if (diff == 3 || diff == 4)
                grade += 5-diff;
        }
        solution.push_back(grade);
    }
    return solution;
}

int main() {
    int n;
    cin >> n;
    vector<int> grades(n);
    for(int grades_i = 0; grades_i < n; grades_i++){
       cin >> grades[grades_i];
    }
    vector < int > result = solve(grades);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;
    

    return 0;
}
