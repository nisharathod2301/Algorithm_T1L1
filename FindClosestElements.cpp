#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - k;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (x - arr[m] > arr[m + k] - x) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};

int main() {
    Solution solution;

    vector<int> arr = {1, 3, 5, 7, 8, 10};
    int k = 3;
    int x = 6;

    vector<int> closestElements = solution.findClosestElements(arr, k, x);

    cout << "Closest elements to " << x << ": ";
    for (int num : closestElements) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
