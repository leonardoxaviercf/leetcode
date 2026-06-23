#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        string prefixo = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefixo) != 0) {
                prefixo = prefixo.substr(0, prefixo.length() - 1);

                if (prefixo.empty()) {
                    return "";
                }
            }
        }

        return prefixo;
    }
};