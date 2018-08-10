#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> checkCondition2(vector<int>* arr) {
    vector<int> ans = {-1, -1};
    int x1 = -1;
    for (int i = 0; i < arr->size()-1; i++) {
        if (ans[0] == -1) {
            if (arr->at(i) > arr->at(i+1)) {
                x1 = arr->at(i);
                ans[0] = i;
            }
        } else if (ans[1] == -1) {
            if (arr->at(i) < arr->at(i+1)) {
                if (x1 > arr->at(i+1)) {
                    ans[0] = -1;
                    break;
                }
                ans[1] = i;
            }
        } else {
            if (arr->at(i) > arr->at(i+1)) {
                ans[0] = -1;
                ans[1] = -1;
                break;
            }
        }
        if (i == arr->size()-2 && ans[1] == -1) {
            ans[1] = arr->size()-1;
        }
    }
    return ans;
}

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
    /*
     * Notes: arr needs to be in ASCENDING order, each element in arr is distinct
     * Operation 0: arr is already sorted
     * Operation 1: arr must swap exactly 2 elements to be sorted
     *   a) Exactly 1 element is out-of-order
     *       i) If the element can be swapped with one of its neighbors, Yes; else, No
     *   b) Exactly 2 elements are out-of-order
     *       i) If the 2 elements can be swapped to satisfy order, Yes; else, No
     * Operation 2: arr must be sorted EXCEPT for a subsequence that is in reverse order
     *   a) The subsequence must contain elements that are in reverse order
     *   b) The rest of the array must be already sorted
     *   c) Determine the start and end indicies of the subsequence
     *
     * IMPLEMENTATION:
     * First Pass: Check for condition 0, 1
     *   When an element is found
     * Second Pass: (If condition 0,1 are not met) Check for condition 2
     * <ALTERNATIVELY>
     * (Do above in 1 pass)
     *
     * FIRST PASS: Check for Condition 0, 1:
     */
    
    int x1 = -1, i1 = -1, x2 = -1, i2 = -1;
    int numWrong = 0;
    bool op0 = false;
    bool op1 = false;
    for (int i = 0; i < arr.size()-1; i++) {
        if (arr[i] > arr[i+1]) {
            numWrong++;
            if (numWrong > 2)
                break;
            if (x1 == -1) {
                i1 = i;
                x1 = arr[i];
            } else if (x2 == -1) {
                i2 = i+1;
                x2 = arr[i+1];
            }
        }
    }
    if (numWrong == 0) {
        op0 = true;
        cout << "yes";
    }
    else if (numWrong > 2) {
        vector<int> result = checkCondition2(&arr);
        if (result[0] == -1)
            cout << "no";
        else
            cout << "yes\nreverse " << result[0]+1 << ' ' << result[1]+1;
    } else if (numWrong == 2) {
        if ((i1 == 0 || arr[i1 - 1] < x2) && (i1 == arr.size()-1 || arr[i1 + 1] > x2)
            && arr[i2 - 1] < x1 && (i2 == arr.size()-1 || arr[i2 + 1] > x1)) {
            cout << "yes\nswap " << i1+1 << ' ' << i2+1;
        } else {
            cout << "no";
        }
    } else { // if numWrong == 1, check if element can be swapped with next element
        if ((i1 == 0 || arr[i1 - 1] < arr[i1 + 1]) && (i1 >= arr.size() - 2 || x1 < arr[i1 + 2]))         {
            cout << "yes\nswap " << i1+1 << ' ' << i1+2;
        } else {
            cout << "no";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);
        
        arr[i] = arr_item;
    }
    almostSorted(arr);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
