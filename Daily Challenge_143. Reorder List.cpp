struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        //TC O(n), SC O(1)
        if (!head || !head->next || !head->next->next){
            return;
        }
        //divide the linked list into 2 halves-->slow fast algo
        ListNode *slow = head, *fast = head, *prev, *temp;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;//put an end to the first half

        prev = nullptr;
        //reverse the second half-->in place
        while(slow){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        
        //iterate both halves and combine into one linked list
        // Now, 'prev' is the head of the reversed second half
        ListNode *secondHalf = prev;
        ListNode *firstHalf = head;
        
        // Merge the two halves
        while(firstHalf && secondHalf){
            temp = firstHalf->next; // Store next node of first half
            firstHalf->next = secondHalf; // Link first half node to second half node
            firstHalf = temp; // Move firstHalf to next node in its list
            
            if(firstHalf){ // Check to prevent accessing null
                temp = secondHalf->next; // Store next node of second half
                secondHalf->next = firstHalf; // Link second half node back to first half node
                secondHalf = temp; // Move secondHalf to next node in its list
            }
        }
       
    }
};