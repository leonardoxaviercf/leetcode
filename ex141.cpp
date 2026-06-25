#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *lento = head;
        ListNode *rapido = head;
        
        while (rapido != nullptr && rapido->next != nullptr) {
            lento = lento->next;
            rapido = rapido->next->next;
            
            if (lento == rapido) {
                return true;
            }
        }
        
        return false;
    }
};