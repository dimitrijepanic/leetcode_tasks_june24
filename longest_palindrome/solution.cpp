#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> letters(127, 0);
        int result = 0;
        bool odd = false;
        for(auto e: s) letters[e]++;

        for(auto e: letters) {
            if(e & 1) {
                result += e - 1 + (odd ? 0 : 1);
                odd = true; 
            } else result += e;
        }

        return result;
    }
};