#include <vector>

using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        if(k > nums.size()) return 0;

        vector<int> odds;

        odds.push_back(-1);
        for(int i = 0; i < nums.size() ; i++){
            if(nums[i] & 1) odds.push_back(i);
        }
        odds.push_back(nums.size());

        int subarrays = 0;

        for(int i = 1, j = i + k - 1; j < odds.size() - 1; i++,j++){
            // cout << i << " " << j << endl;
            int left = odds[i] - odds[i - 1] - 1;
            int right = odds[j + 1] - odds[j] - 1;

            subarrays += 1 + left + right + left * right;
        }

        return subarrays;
    }
};