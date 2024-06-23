#include <deque>
#include <vector>

using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxdq, mindq;
        int left = 0, right;
        int maxLength = 0;

        for (right = 0; right < nums.size(); ++right) {
            while (!maxdq.empty() && maxdq.back() < nums[right]) {
                maxdq.pop_back();
            }
            maxdq.push_back(nums[right]);

            while (!mindq.empty() && mindq.back() > nums[right]) {
                mindq.pop_back();
            }
            mindq.push_back(nums[right]);

            while (maxdq.front() - mindq.front() > limit) {
                
                if (maxdq.front() == nums[left]) {
                    maxdq.pop_front();
                }
                if (mindq.front() == nums[left]) {
                    mindq.pop_front();
                }
                ++left;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};