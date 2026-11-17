#include <sstream>

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> forward;
        unordered_map<string, char> reverse;
        istringstream input(s);
        string word;
        for (char letter : pattern) {
            if (!(input >> word)) {
                return false;
            }
            auto a = forward.find(letter);
            auto b = reverse.find(word);
            if ((a != forward.end() && a->second != word) ||
                (b != reverse.end() && b->second != letter)) {
                return false;
            }
            forward[letter] = word;
            reverse[word] = letter;
        }
        return !(input >> word);
    }
};
