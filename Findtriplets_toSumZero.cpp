#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> findTriplets(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    
    if (n < 3) {
        return result;
    }
    
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    vector<vector<int>> triplets = findTriplets(nums);
    
    if (triplets.empty()) {
        cout << "No triplets found with sum 0." << endl;
    } else {
        cout << "Triplets with sum 0:" << endl;
        for (const auto& triplet : triplets) {
            cout << "(" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << ")" << endl;
        }
    }
    
    return 0;
}
