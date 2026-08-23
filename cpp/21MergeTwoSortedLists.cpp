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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode beginning(0);
        ListNode* head = &beginning;
        
        /**
         * Links up the next ListNodes of a linked list to the pointer's .next attribute
         * Dissociates the remaining links of the previous list if the next ListNode's value attribute is smaller.
         * Continues until one of the linked lists hit a nullptr
        */
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val >= list2->val) {
                head->next = list2;
                list2 = list2->next;
            } else if (list1->val <= list2->val) {
                head->next = list1;
                list1 = list1->next;
            }

            head = head->next;
        }

        if (list1 != nullptr) {
            head->next = list1; // attaches all of the linked ListNodes past this point
        } else {
            head->next = list2;
        }

        return beginning.next; // only return its next attribute's linked ListNodes
    }
};
