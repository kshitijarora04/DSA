// ListNode* reverseList(ListNode* head) {
//     // Base case: if list is empty or has one node
//     if (head == nullptr || head->next == nullptr) {
//         return head;
//     } else {
//         // Recursive case: reverse the rest of the list
//         ListNode* newHead = reverseList(head->next);

//         // Reverse the current link
//         head->next->next = head;
//         head->next = nullptr;

//         return newHead;
//     }
// }
