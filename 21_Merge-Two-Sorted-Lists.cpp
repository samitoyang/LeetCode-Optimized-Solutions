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
        ListNode* result;
        ListNode** min = nullptr;
        for (auto l : {&list1, &list2})
            if (*l) {
                if (!min)
                    min = l;
                else if ((*l)->val < (*min)->val)
                    min = l;
            }
        if (min) {
            result = *min;
            *min = (*min)->next;
            result->next = mergeTwoLists(list1, list2);
        }
        return result;
    }
};
