#include <string>
#include <cctype> // for std::tolower and std::toupper

class Solution {
public:
    std::string makeGood(std::string s) {
        std::string result;
        for (const char &ch : s) {
            if (!result.empty() && (std::tolower(ch) == std::tolower(result.back())) 
                && (ch != result.back())) {
                // If the current character and the last character of the result 
                // are the same letter in different cases, pop the last character.
                result.pop_back();
            } else {
                // Otherwise, push the current character onto the result string.
                result.push_back(ch);
            }
        }
        return result;
    }
};
