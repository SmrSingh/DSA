/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int l1_length = 0; 
        int l2_length = 0; 
        ListNode* current = l1; 

        // get l1 length 
        while (current != nullptr) {
            l1_length++; 
            current = current->next; 
        }

        // get l2 length 
        current = l2; 
        while (current != nullptr) {
            l2_length++; 
            current = current->next;
        }

        int next_digit = 0; 
        int temp_curr = 0;
        int temp_next = 0; 
        // add l2 to l1 if l1 is longer
        if (l2_length <= l1_length) {
            current = l1; 
            while (l2->next != nullptr) {
                temp_curr = current->val;
                temp_next = next_digit; 
                current->val = (l2->val + temp_curr + temp_next) % 10; 
                next_digit = (l2->val + temp_curr + temp_next) / 10;
                l2 = l2->next;
                current = current->next;
            }
            temp_curr = current->val;
            temp_next = next_digit; 
            current->val = (l2->val + temp_curr + temp_next) % 10; 
            next_digit = (l2->val + temp_curr + temp_next) / 10;

            if (l2_length < l1_length) {
                current = current->next;
                while (current->next != nullptr) {
                    temp_curr = current->val;
                    temp_next = next_digit; 
                    current->val = (temp_curr + temp_next) % 10; 
                    next_digit = (temp_curr + temp_next) / 10;
                    current = current->next;
                }
                temp_curr = current->val;
                temp_next = next_digit;
                current->val = (temp_curr + temp_next) % 10; 
                next_digit = (temp_curr + temp_next) / 10;
            }

            // only need to add one more node if next_digit > 0
            if (next_digit > 0) {
                current->next = new ListNode(next_digit);
            }
            return l1; 
            
        } else { // add l1 to l2 
            current = l2; 
            while (l1->next != nullptr) {
                temp_curr = current->val;
                temp_next = next_digit;
                current->val = (l1->val + temp_curr + temp_next) % 10; 
                next_digit = (l1->val + temp_curr + temp_next) / 10;
                l1 = l1->next;
                current = current->next;
            }
            temp_curr = current->val;
            temp_next = next_digit;
            current->val = (l1->val + temp_curr + temp_next) % 10; 
            next_digit = (l1->val + temp_curr + temp_next) / 10;

            current = current->next;
            while (current->next != nullptr) {
                temp_curr = current->val;
                temp_next = next_digit;
                current->val = (temp_curr + temp_next) % 10; 
                next_digit = (temp_curr + temp_next) / 10; 
                current = current->next;
            }
            temp_curr = current->val;
            temp_next = next_digit;
            current->val = (temp_curr + temp_next) % 10; 
            next_digit = (temp_curr + temp_next) / 10; 

            // only need to add one more node if next_digit > 0
            if (next_digit > 0) {
                current->next = new ListNode(next_digit); 
            }
            return l2; 
        }  
    }
};