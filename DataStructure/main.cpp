#include<iostream>

#define MAX 10

class Node
{
    public:
        int data;
        Node* next;
};

class linkList
{
    public:
        Node* head;
    public:
        linkList()
        {
            head = nullptr;
        }
        void iniNode(int pos = 0, int data = 1);
        void addNode(int pos, int data);
        void delNode(int pos);
        void reverseNode();
        void printLiskList();
};

// create head of link list
void linkList::iniNode(int pos, int data)
{
    if (head == nullptr) {
        head = new Node();
        head->data = data;
        head->next = nullptr;
        std::cout << "Creating head done!" << std::endl;
    } else {
        // do nothing
    }
}

// add node to link list
void linkList::addNode(int pos, int data)
{
    if (head == nullptr) {
        this->iniNode(0, data);
        return;
    }

    // insert first node
    if (pos == 0) {
        // create new node
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        // point to head by new Node
        newNode->next = head;

        // move head to new Node
        head = newNode;
    } else {
        int count = 1;
        // create a temporal pointer
        Node* tempNode = head;

        while (count != pos && tempNode->next != nullptr) {
            // increase count variable
            count++;
            tempNode = tempNode->next;
        }

        // when go out while loop
        if (count == pos || tempNode->next == nullptr) {
           // create new node
           Node* newNode = new Node();
           newNode->data = data;
           // point to next node from new node
           if (count == pos) {
                newNode->next = tempNode->next;
           } else {
                newNode->next = nullptr;
           }

           // point to new Node from location which is needed to insert new node
            tempNode->next = newNode;

        }
    }
}

void linkList::delNode(int pos)
{
    if (head == nullptr) {
        return;
    }

    // create temp head
    Node* tempNode = head;
    Node* preNode = head;

    int count = 0;
    while (count != pos && tempNode->next != nullptr) {
        count++;
        preNode = tempNode;
        tempNode = tempNode->next;
    }

    if (count == pos) {
        if (count == 0) {
            head = head->next;
        } else {
            preNode->next = tempNode->next;
        }
        delete tempNode;
    } else {
        std::cout << "No have node at the position" << std::endl;
    }
}

void linkList::reverseNode()
{
    // initialize 2 pointers prev, next;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* cur = head;

    while (cur != nullptr) {
        //store next node
        next = cur->next;
        //change next of current node
        cur->next = prev;

        // change head, prev
        prev = cur;
        cur = next;
    }

    //change head
    head = prev;
}

// print data of link list
void linkList::printLiskList()
{
    if (head == nullptr) {
        std::cout << "link list is empty!" << std::endl;
    }
    Node* tempNode = head;
    while (tempNode != nullptr) {
        std::cout << "Data is: " << tempNode->data << std::endl;
        tempNode = tempNode->next;
    }
}

class Stack
{
    public:
        Stack() { top = -1; }

    public:
        int top;
        int arr[MAX];
        void push(int val);
        int pop();
        int peek();
        bool isEmpty();
};

void Stack::push(int val)
{
    if (top < MAX - 1) {
        arr[++top] = val;
        std::cout << "Push val into stack is OK" << std::endl;
    } else {
        std::cout << "Stack is full" << std::endl;
    }
}

bool Stack::isEmpty()
{
    return (top == -1);
}

int Stack::pop()
{
    int ret = -1;
    if (!isEmpty()) {
        // store top value
        int temp = arr[top];
        // move top
        top--;
        // assign to ret value
        ret = temp;
        std::cout << "Remove top is successful" << std::endl;
    } else {
        std::cout << "Stack is empty" << std::endl;
    }
    return ret;
}

int Stack::peek()
{
    int ret = -1;
    ret =  arr[top];
    return ret;
}

class NodeList
    {
        public:
            int data;
            NodeList* next;
    };

class StackList
{
    public:
        StackList() { 
            //top = -1;
            headList = nullptr;
        }

    public:
        //int top;
        NodeList* headList;
        void push(int val);
        int pop();
        int peek();
        bool isEmpty();
};

void StackList::push(int val)
{
    if (headList == nullptr) {
        headList = new NodeList();
        headList->data = val;
        headList->next = nullptr;
    } else {
        // create new node
        NodeList *node = new NodeList();
        node->data = val;
        node->next = headList;

        // Assign head
        headList = node;
    }
}

int StackList::pop()
{
    // create temporal head
    NodeList *tempNode = headList;
    // move head
    headList = headList->next;
    // delete temporal head
    delete tempNode;
}

bool StackList::isEmpty()
{
    return (headList == nullptr);
}

int StackList::peek()
{
    return headList->data;
}

class queue
{
    public:
        queue()
        {
            front = 0;
            rear = MAX - 1;
            size = 0;
        }
    public:
        int front, rear, size;
        int arr[MAX];
        void enqueue(int val);
        int dequeue();
        bool isFull();
        bool isEmpty();  
        int getFront();
        int getRear();
};

int queue::getFront()
{
    return arr[front];
}

int queue::getRear()
{
    return arr[rear];
}

void queue::enqueue(int val)
{
    // update rear
    rear = (rear + 1) % MAX;
    // assign value to array
    arr[rear] = val;
    // increase size
    size++;
    std::cout << "enqueue value to queue successful!" << std::endl;
}

int queue::dequeue()
{
    // get temp first element
    int temp = arr[front];
    // move front
    front = (front + 1) % MAX;
    // decrease size
    size--;
    return temp;
}

bool queue::isFull()
{
    return (size == MAX);
}

bool queue::isEmpty()
{
    return (size == 0);
}

int main()
{
/*     // instance linkList object
    linkList list;
    // initialize list
    list.iniNode();
    // add node
    list.addNode(0, 2);
    list.addNode(1, 3);
    list.addNode(7, 4);
    list.addNode(3, 5);
    list.addNode(0, 0);
    list.addNode(10, 0);
    // print data of list
    std::cout << "link list before deleting node" << std::endl;
    list.printLiskList();
    // delete head
    list.delNode(0);
    // print data of list
    std::cout << "link list after deleting node" << std::endl;
    list.printLiskList();
    // reverse head
    list.reverseNode();
    // print data of list
    std::cout << "link list after reversing node" << std::endl; 
    list.printLiskList();*/

    /* Stack st;
    st.push(10);
    st.push(9);
    st.push(11);
    if (!st.isEmpty()) {
        std::cout << "Top is: " << st.peek() << std::endl;
    } else {
        std::cout << "Stack is emplty!" << std::endl;
    }

    if (!st.isEmpty()) {
        st.pop();
        if (!st.isEmpty()) {
            std::cout << "After popping, top is: " << st.peek() << std::endl;
        } else {
            std::cout << "Stack is empty, so can not peek or pop" << std::endl;
        }
    } else {
        std::cout << "Stack is emplty!" << std::endl;
    }

    if (!st.isEmpty()) {
        st.pop();
        if (!st.isEmpty()) {
            std::cout << "After popping, top is: " << st.peek() << std::endl;
        } else {
            std::cout << "Stack is empty, so can not peek or pop" << std::endl;
        }
    } else {
        std::cout << "Stack is emplty!" << std::endl;
    }

    if (!st.isEmpty()) {
        st.pop();
        if (!st.isEmpty()) {
            std::cout << "After popping, top is: " << st.peek() << std::endl;
        } else {
            std::cout << "Stack is empty, so can not peek or pop" << std::endl;
        }
    } else {
        std::cout << "Stack is emplty!" << std::endl;
    } */

    /* StackList stList;
    stList.push(1);
    stList.push(10);
    stList.push(11);
    if (!stList.isEmpty()) {
        std::cout << "Top is: " << stList.peek() << std::endl;
    } else {
        std::cout << "Stack is emplty!" << std::endl;
    }
    if (!stList.isEmpty()) {
        stList.pop();
        if (!stList.isEmpty()) {
            std::cout << "After popping, top is: " << stList.peek() << std::endl;
        } else {
            std::cout << "Stack is empty, so can not peek or pop" << std::endl;
        }
    } else {
        std::cout << "Stack is emplty!" << std::endl;
    }

    if (!stList.isEmpty()) {
        stList.pop();
        if (!stList.isEmpty()) {
            std::cout << "After popping, top is: " << stList.peek() << std::endl;
        } else {
            std::cout << "Stack is empty, so can not peek or pop" << std::endl;
        }
    } else {
        std::cout << "Stack is emplty!" << std::endl;
    }

    if (!stList.isEmpty()) {
        stList.pop();
        if (!stList.isEmpty()) {
            std::cout << "After popping, top i s: " << stList.peek() << std::endl;
        } else {
            std::cout << "Stack is empty, so can not peek or pop" << std::endl;
        }
    } else {
        std::cout << "Stack is emplty!" << std::endl;
    }

    if (!stList.isEmpty()) {
        stList.pop();
        if (!stList.isEmpty()) {
            std::cout << "After popping, top is: " << stList.peek() << std::endl;
        } else {
            std::cout << "Stack is empty, so can not peek or pop" << std::endl;
        }
    } else {
        std::cout << "Stack is emplty!" << std::endl;
    } */

    queue que;
    if (!que.isFull()) {
        que.enqueue(1);
    } else {
        std::cout << "queue is full, so can not enqueue anything!" << std::endl;
    }

    if (!que.isFull()) {
        que.enqueue(2);
    } else {
        std::cout << "queue is full, so can not enqueue anything!" << std::endl;
    }

    if (!que.isFull()) {
        que.enqueue(3);
    } else {
        std::cout << "queue is full, so can not enqueue anything!" << std::endl;
    }

    if (!que.isFull()) {
        que.enqueue(4);
    } else {
        std::cout << "queue is full, so can not enqueue anything!" << std::endl;
    }

    if (!que.isEmpty()) {
        std::cout << "first value is: " << que.getFront() << std::endl;
        std::cout << "last value is: " << que.getRear() << std::endl;
    } else {
        std::cout << "queue is empty, so can not get front or rear or dequeue!" << std::endl;
    }

    if (!que.isEmpty()) {
        std::cout << "dequeue first time: " << que.dequeue() << std::endl;
    } else {
        std::cout << "queue is empty, so can not get front or rear or dequeue!" << std::endl;
    }

    if (!que.isEmpty()) {
        std::cout << "dequeue second time: " << que.dequeue() << std::endl;
    } else {
        std::cout << "queue is empty, so can not get front or rear or dequeue!" << std::endl;
    }

    if (!que.isEmpty()) {
        std::cout << "After dequeue, first value is: " << que.getFront() << std::endl;
        std::cout << "After dequeue, last value is: " << que.getRear() << std::endl;
    } else {
        std::cout << "queue is empty, so can not get front or rear or dequeue!" << std::endl;
    }

    if (!que.isEmpty()) {
        std::cout << "dequeue third time: " << que.dequeue() << std::endl;
    } else {
        std::cout << "queue is empty, so can not get front or rear or dequeue!" << std::endl;
    }

    if (!que.isEmpty()) {
        std::cout << "dequeue fourth time: " << que.dequeue() << std::endl;
    } else {
        std::cout << "queue is empty, so can not get front or rear or dequeue!" << std::endl;
    }

    if (!que.isEmpty()) {
        std::cout << "After dequeue, first value is: " << que.getFront() << std::endl;
        std::cout << "After dequeue, last value is: " << que.getRear() << std::endl;
    } else {
        std::cout << "queue is empty, so can not get front or rear or dequeue!" << std::endl;
    }

}