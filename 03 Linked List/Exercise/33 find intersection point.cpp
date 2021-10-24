#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int l1 = 0;
        ListNode *trav1 = headA;
        while (trav1)
        {
            l1++;
            trav1 = trav1->next;
        }
        int l2 = 0;
        ListNode *trav2 = headB;
        while (trav2)
        {
            l2++;
            trav2 = trav2->next;
        }

        trav1 = headA;
        trav2 = headB;
        if (l1 > l2)
        {
            int d = l1 - l2;
            for (int i = 0; i < d; i++)
            {
                trav1 = trav1->next;
            }
        }
        else
        {
            int d = l2 - l1;
            for (int i = 0; i < d; i++)
            {
                trav2 = trav2->next;
            }
        }

        while (trav1 || trav2)
        {
            if (trav1 == trav2)
                return trav1;
            trav1 = trav1->next;
            trav2 = trav2->next;
        }
        return NULL;
    }
};