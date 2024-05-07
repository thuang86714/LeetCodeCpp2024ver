struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* reverseList(ListNode *node){
        ListNode *prev = nullptr;
        while(node){
            ListNode *nodeNext = node->next;
            node->next = prev;
            prev = node;
            node = nodeNext;
        }
        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        //TC O(n), SC O(1)
        if(!head){
            return head;
        }
        //reverse the linked list
        ListNode *cur = reverseList(head);
        ListNode *reverseNode = cur;
        int carry = 0;
        while(cur){
            int newVal = (cur->val*2 + carry);
            cur->val = newVal%10;
            carry = newVal/10;
            if(!cur->next){
                break;
            }
            cur = cur->next;
        }

        if(carry){
            cur->next = new ListNode(carry);
        }

        //reverse it back
        return reverseList(reverseNode);
    }
};