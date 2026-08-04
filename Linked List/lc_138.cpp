/* we are given a LL in which any node has a random pointer means any node of LL may be attached to another node of LL */
/* we have to create the copy of LL with random pointer */

#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next = NULL;
    Node *random = NULL;

    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->random = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

/* Approach 1 : HashMap which will store newNode mapped with oldNode      ||  T.C : O(n)   ||   S.C : O(n) */

Node *helperHash(Node *&head, unordered_map<Node *, Node *> &mp)
{

    if (!head)
        return nullptr;

    Node *newHead = new Node(head->data);       // will create newNode so that we can form same main LL but without random pointer
    mp[head] = newHead;                         // mapped newNode with its oldNode as oldNode will help newNode to link with random pointer
    newHead->next = helperHash(head->next, mp); // recursively form the main LL

    if (head->random)
    {                                       // if random exist
        newHead->random = mp[head->random]; // then link the newNode random with the help oldNode's random
    }

    return newHead;
}

Node *copyHashMap(Node *&head)
{

    if (!head)
        return nullptr;
    unordered_map<Node *, Node *> mp;
    return helperHash(head, mp);
}

// Optimal Approach :   ||   T.C : O(n)    ||  S.C : O(1)   ||

Node *optimal(Node *&head)
{

    if (!head)
        return nullptr;

    // step 1 : create the new LL of oldNode followed by cloneNode  || 7 -> 7 -> 13 -> 13 -> 11 -> 11 -> 10 -> 10 -> 1 ->1  like this
    Node *it = head;
    while (it)
    {
        Node *cloneNode = new Node(it->data);
        cloneNode->next = it->next;
        it->next = cloneNode;
        it = it->next->next;
    }

    // step 2 : now find the random of newNode & link it;
    it = head;
    while (it)
    {
        Node *cloneNode = it->next;
        cloneNode->random = it->random ? it->random->next : NULL;
        it = it->next->next;
    }

    // now de-attach the oldNode and cloneNode;
    it = head;
    Node *cloneHead = it->next;
    while (it)
    {
        Node *cloneNode = it->next;
        it->next = it->next->next;
        if (cloneNode->next)
        {
            cloneNode->next = cloneNode->next->next;
        }
        it = it->next;
    }
    return cloneHead;
}

void printList(Node *head)
{

    while (head)
    {

        cout << "Node = " << head->data;

        if (head->next)
            cout << " | Next = " << head->next->data;
        else
            cout << " | Next = NULL";

        if (head->random)
            cout << " | Random = " << head->random->data;
        else
            cout << " | Random = NULL";

        cout << endl;

        head = head->next;
    }
}

int main()
{

    Node *first = new Node(7);
    Node *second = new Node(13);
    Node *third = new Node(11);
    Node *fourth = new Node(10);
    Node *fifth = new Node(1);

    first->next = second;
    first->random = NULL;
    second->next = third;
    second->random = first;
    third->next = fourth;
    third->random = fifth;
    fourth->next = fifth;
    fourth->random = third;
    fifth->next = NULL;
    fifth->random = first;

    cout << "Original List : ";
    printList(first);
    cout<<endl;

    Node *newHead1 = copyHashMap(first);
    cout << " Copied List (HashMap) : ";
    printList(newHead1);
    cout<<endl;


    Node *newHead2 = optimal(first);
    cout << "Copied List (Optimal) : ";
    printList(newHead2);

    return 0;
}