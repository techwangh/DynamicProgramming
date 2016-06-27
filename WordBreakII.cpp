#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        vector<bool> ispossible(s.size()+1, true);
        string words;
        breakWord(s, wordDict, 0, ispossible, words, res);
        return res;
    }

    void breakWord(string& s, unordered_set<string>& wordDict, int start, 
                   vector<bool>& ispossible, string& words, vector<string>& res) {
        if(start == s.size()) {
            res.push_back(words.substr(0, words.size()-1));
            return;
        }

        for(int i = start; i <s.size(); ++i) {
            string word = s.substr(start, i-start+1);
            if(wordDict.find(word) != wordDict.end() && ispossible[i+1]) {
                words.append(word).append(" ");
                int oldSize = res.size();
                breakWord(s, wordDict, i+1, ispossible, words, res);
                if(oldSize == res.size()) {
                    ispossible[i+1] = false;
                }
                words.resize(words.size() - word.size() - 1);
            }
        }
    }
};

int main() {
    return 0;
}