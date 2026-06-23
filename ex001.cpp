#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapa_numeros;

        for (int i = 0; i < nums.size(); i++) {
            int falta = target - nums[i];
            
            if (mapa_numeros.find(falta) == mapa_numeros.end()) {
                mapa_numeros[nums[i]] = i;

            } else {
                return {
                    mapa_numeros[falta], i
                };
            }
        }

        return {};
    }
};