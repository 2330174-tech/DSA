class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            return nullptr;
        }

        int count = 0;
        ListNode* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }

        int mid = count / 2;

        ListNode* prev = nullptr;
        ListNode* target = head;
        for (int i = 0; i < mid; i++) {
            prev = target;
            target = target->next;
        }

        if (prev) {
            prev->next = target->next;
        } else {
            head = target->next;
        }

        return head;
    }
};