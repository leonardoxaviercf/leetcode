struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode* lento = head;
        ListNode* rapido = head;

        while (rapido != nullptr && rapido->next != nullptr) {
            lento = lento->next;         
            rapido = rapido->next->next; 
        }

        ListNode* segundaMetade = inverterLista(lento);
        ListNode* primeiraMetade = head;

        ListNode* iteradorSegunda = segundaMetade;
        bool ehPalindromo = true;

        while (iteradorSegunda != nullptr) {
            if (primeiraMetade->val != iteradorSegunda->val) {
                ehPalindromo = false;
                break; 
            }
            primeiraMetade = primeiraMetade->next;
            iteradorSegunda = iteradorSegunda->next;
        }

        return ehPalindromo;
    }

private:
    ListNode* inverterLista(ListNode* head) {
        ListNode* anterior = nullptr;
        ListNode* atual = head;

        while (atual != nullptr) {
            ListNode* proximoTemp = atual->next; 
            atual->next = anterior;              
            anterior = atual;                    
            atual = proximoTemp;                 
        }
        
        return anterior;
    }
};