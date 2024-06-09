#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefixSum = 0;
        int result = 0;

        for(auto e: nums){
            prefixSum = (prefixSum + e % k + k) % k;
            result += mp[prefixSum];
            mp[prefixSum]++;
        }

        return result;
    }
};