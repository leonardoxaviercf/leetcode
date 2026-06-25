class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };

    Node* dummyHead;
    int size;

public:
    MyLinkedList() {
        dummyHead = new Node(0);
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        
        Node* atual = dummyHead->next; 
        for (int i = 0; i < index; ++i) {
            atual = atual->next;
        }
        return atual->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        if (index < 0) {
            index = 0;
        }
        
        Node* atual = dummyHead;
        for (int i = 0; i < index; ++i) {
            atual = atual->next;
        }
        
        Node* novoNo = new Node(val);
        novoNo->next = atual->next;
        atual->next = novoNo;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        
        Node* atual = dummyHead;
        for (int i = 0; i < index; ++i) {
            atual = atual->next;
        }
        
        Node* noAExcluir = atual->next;
        atual->next = noAExcluir->next;
        delete noAExcluir;
        size--;
    }
};