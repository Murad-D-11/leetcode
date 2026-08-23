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
#include <string>

class Solution {
public:
    long long calculateNum(ListNode* l) {
        int count = 0;
        long long num = 0;

        while (l) {
            num += l->val * std::pow(10, count);
            l = l->next;
            count++;
        }

        return num;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::string sum = std::to_string(calculateNum(l1) + calculateNum(l2));

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        for (int i = sum.size() - 1; i >= 0; i--) {
            ListNode* node = new ListNode(sum[i] - '0');

            if (head == nullptr) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }

        return head;
    }
};
