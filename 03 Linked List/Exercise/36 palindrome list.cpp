// * Definition for singly-linked list.
#include <iostream>
#include <stack>
using namespace std;
class ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<int> s;
        ListNode *trav = head;
        while (trav)
        {
            s.push(trav->val);
            trav = trav->next;
        }

        trav = head;
        while (trav)
        {
            if (trav->val != s.top())
                return false;
            trav = trav->next;
            s.pop();
        }
        return true;
    }
};