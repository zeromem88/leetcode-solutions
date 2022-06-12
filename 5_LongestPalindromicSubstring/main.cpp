#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>

using std::string;

class Solution {
   public:
    inline int len(std::pair<int, int> pair) {
        return pair.second - pair.first;
    }

    std::pair<int, int> palindorme(const string& s, int begin, int end) {
        bool found = false;
        while (begin >= 0 && end < s.size() && s[begin] == s[end]) {
            begin--;
            end++;
            found = true;
        }
        if (found) {
            return std::make_pair(begin + 1, end - 1);
        }

        return std::make_pair(0, 0);
    }

    string longestPalindrome(string s) {
        int curLen = 0;
        std::pair<int, int> curPos{0, 0};

        for (int i = 0; i < s.size(); i++) {
            auto pos1 = palindorme(s, i, i);
            auto pos2 = palindorme(s, i, i + 1);

            if (curLen < len(pos1)) {
                curPos = pos1;
                curLen = len(curPos);
            }

            if (curLen < len(pos2)) {
                curPos = pos2;
                curLen = len(curPos);
            }
        }

        return s.substr(curPos.first, curLen + 1);
    }
};

int main(int argc, char* argv[]) {
    std::cout << "Longest palindrome substring!" << std::endl;
    Solution s;
    
    std::cout << "babad: " << s.longestPalindrome("babad") << std::endl;
    std::cout << "cbbd: " << s.longestPalindrome("cbbd") << std::endl;
    std::cout << "a: " << s.longestPalindrome("a") << std::endl;
    std::cout << "bbbbbb: " << s.longestPalindrome("bbbbbb") << std::endl;
    std::cout << "abbbbbbbc: " << s.longestPalindrome("abbbbbbbc") << std::endl;

    return 0;
}