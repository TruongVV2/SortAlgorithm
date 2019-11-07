#ifndef _NODE_HEADER_
#define _NODE_HEADER_

class Node
{
    public:
        Node(int data)
        { 
            m_data = data;
            next = nullptr; 
        }
    public:
        int m_data;
        Node* next;
};

class ListNode
{
    public:
        void InitialNode(Node** head, int data);
        void InsertNode(Node** head, int data, int pos);
        void RemoveNode(Node** head, int pos);
        void PrintList(Node* head);
};

#endif /* _NODE_HEADER_ */