struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev, *temp;
        //use fast-slow to find mid point
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        prev = slow;
        slow = slow->next;
        prev->next = nullptr;
        //turn around the second half
        while(slow){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        slow = prev;
        while(slow){
            if(head->val != slow->val){
                return false;
            }else{
                head = head->next;
                slow = slow->next;
            }
        }
        return true;
    }
};