#include <vector>
#include <string>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false; // Different lengths cannot be isomorphic
        }

        std::vector<char> visited(128, 0); // Track characters visited in s

        for (int i = 0; i < s.length(); i++) {
            char charS = s[i];
            char charT = t[i];

            if (visited[charS] == 0) {
                // Check if the character in t has already been mapped
                if (std::count(visited.begin(), visited.end(), charT) > 0) {
                    return false;
                }

                visited[charS] = charT; // Map the character in s to the character in t
            } else if (visited[charS] != charT) {
                return false;
            }
        }

        return true;
    }
};