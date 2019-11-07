#include<iostream>
#include"../inc/node.h"


void ListNode::InitialNode(Node** head, int data)
{
    if (*head == nullptr) {
        *head = new Node(data);
    } else {
        (*head)->m_data = data;
    }
}

void ListNode::InsertNode(Node** head, int data, int pos)
{
    // create new node
    Node* newNode = new Node(data);
    if (pos == 0) {
        // assign next node of new node
        newNode->next = *head;
        // move head node
        *head = newNode;
    } else {
        // create temp node
        Node* tempNode = *head;
        // create previous node
        Node* preNode = *head;
        // create count
        int count = 0;

        while(count < pos && tempNode != nullptr ) {
            preNode = tempNode;
            tempNode = tempNode->next;
            count++;
        }

        if (count == pos) {
            newNode->next = tempNode;
            preNode->next = newNode;
            std::cout << "data: " << data << std::endl;
        } else {  
            preNode->next = newNode;
        }
    }
}

void ListNode::PrintList(Node* head)
{
    if (head == nullptr) {
        std::cout << "head is nullptr!" << std::endl;
    } else {
        std::cout << "head is not nullptr!" << std::endl;
    }

    while (head != nullptr) {
        std::cout << head->m_data << std::endl;
        head = head->next;
    }
}