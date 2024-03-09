struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *fast = head, *slow = head;
        int countLen = 0;
        while(fast->next){
            countLen++;
            fast = fast->next;
        }
        int target;
        if(countLen%2){
            target = countLen/2 + 1;
        }else{
            target = countLen/2;
        }
        for(int i = 0; i < target; i++){
            slow = slow->next;
        }
        return slow;


    }
};