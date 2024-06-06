#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        unordered_map<int, int> mp;

        for(auto e: hand) mp[e]++;

        for(auto e: hand){
            if(mp[e] == 0) continue;
            int tmp = groupSize - 1;
            int size = mp[e];
            mp[e] = 0;
            int i = 1;
            while(tmp > 0){
                if(mp[e + i] < size) return false;
                mp[e + i] -= size;
                tmp--;
                i++;
            }
        }
    
        return true;
    }
};