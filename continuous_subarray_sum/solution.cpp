#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefix = 0;
        unordered_map<int, int> modSeen;
        modSeen[0] = -1;

        for(int  i = 0 ; i < nums.size(); i++){
            prefix = (prefix + nums[i]) % k;

            if(modSeen.find(prefix) != modSeen.end()){

                if(i - modSeen[prefix] > 1) return 1;
            } else 
                modSeen[prefix] = i;
        }

        return 0;

    }
};