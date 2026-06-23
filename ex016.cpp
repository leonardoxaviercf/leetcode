#include <iostream>
#include <vector>
#include <algorithm>
    
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int soma_mais_proxima = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {
            int esquerda = i + 1;
            int direita = nums.size() - 1;

            while (esquerda < direita) {
                int soma_atual = nums[i] + nums[esquerda] + nums[direita];
                
                if (soma_atual == target) {
                    return soma_atual;
                }

                if (abs(target - soma_atual) < abs(target - soma_mais_proxima)) {
                    soma_mais_proxima = soma_atual;
                }

                if (soma_atual < target) {
                    esquerda++;
                } else {
                    direita--;
                }
            }
        }
        
        return soma_mais_proxima;
    }
};