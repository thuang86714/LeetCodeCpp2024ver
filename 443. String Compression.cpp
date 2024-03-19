#include <vector>
#include <string>
class Solution {
public:
    int compress(std::vector<char>& chars) {
        int index = 0, left = 0;
        while (left < chars.size()) {
            char currentChar = chars[left];
            int right = left;
            // Find the count of the current character
            while (right < chars.size() && chars[right] == currentChar) {
                right++;
            }
            int count = right - left;
            // Update the character and its count in the chars array
            chars[index++] = currentChar;
            if (count > 1) {
                // Convert count to a string and store each digit
                for (char c : std::to_string(count)) {
                    chars[index++] = c;
                }
            }
            left = right; // Move to the next distinct character
        }
        return index; // 'index' is the new length of the compressed string
    }
};
