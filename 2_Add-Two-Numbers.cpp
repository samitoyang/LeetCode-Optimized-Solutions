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
        ListNode head;
        ListNode* node = &head;
        for (int n = 0; n || l1 || l2; n /= 10) {
            for (auto l : {&l1, &l2})
                if (*l) {
                    n += (*l)->val;
                    *l = (*l)->next;
                }
            node->next = new ListNode(n % 10);
            node = node->next;
        }
        return head.next;
    }
};
