#include <vector>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int numComponents(ListNode* head, std::vector<int>& nums) {
        std::unordered_set<int> conjuntoNums(nums.begin(), nums.end());
        
        int componentes = 0;
        bool dentroDeUmComponente = false;
        
        ListNode* atual = head;
        
        while (atual != nullptr) {
            if (conjuntoNums.count(atual->val) > 0) {
                if (!dentroDeUmComponente) {
                    componentes++;
                    dentroDeUmComponente = true; 
                }
            } else {
                dentroDeUmComponente = false;
            }
            
            atual = atual->next; 
        }
        
        return componentes;
    }
};