#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int result = 0;
        char prev = s[0];
        
        for(auto c: s) { result += abs(c - prev); prev = c;}

        return result;
    }
};

int main(){
    Solution solution;

    cout << solution.scoreOfString("pana") << endl;
    cout << solution.scoreOfString("aa") << endl;
}