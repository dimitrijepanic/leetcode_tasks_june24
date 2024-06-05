#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> letters(26, 0);

        for(auto c: words[0]){
            letters[c - 'a']++;
        }

        for(int i = 1; i < words.size(); i++){
            vector<int> tmp(26, 0);

            for(auto c: words[i]){
                tmp[c - 'a']++;
            }

            for(int i = 0; i < 26; i++){
                letters[i] = min(letters[i], tmp[i]);
            }
        }

        vector<string> result;
        for(int i = 0; i < letters.size(); i++){
            while(--letters[i] >= 0) result.push_back(string(1, 'a' + i));
        }

        return result;
    }
};