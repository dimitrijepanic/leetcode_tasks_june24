#include <vector>

using namespace std;
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> count(101, 0);
        
        for(auto e: heights){
            count[e]++;    
        }

        int result = 0;
        int j = 0;
        for(int i = 0; i < 101; i++){
            if(!count[i]) continue;
            while(count[i]-- > 0){
                if(heights[j++] != i) result++;
            }
        }

        return result;
    }
};