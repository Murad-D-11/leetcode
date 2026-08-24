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
    // uses the turtoise vs. the hare method
    ListNode* splitList(ListNode* head) {
        // handle single-node lists
        if (head->next == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // handle odd & even node lists
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // disconnect the first half from the second half
        if (prev != nullptr) {
            prev->next = nullptr;
        }

        // slow is the head of the second half
        return slow;
    }

    // learned from #206 (Reverse Linked List) :)
    ListNode* reverse(ListNode* curr) {
        ListNode* prev = nullptr;

        while (curr) {
            ListNode* saved = curr->next; // saves the next element
            curr->next = prev;
            prev = curr;
            curr = saved; // goes to the unlinked saved element
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* head2 = reverse(splitList(head));
        
        while (head && head2) {
            if (head->val != head2->val) {
                return false;
            }

            head = head->next;
            head2 = head2->next;
        }

        return true;
    }
};
