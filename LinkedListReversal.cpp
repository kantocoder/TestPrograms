// Compilation : g++ -std=c++11 LinkedListReversal.cpp -o LinkedListReversal

#include <iostream>

struct Node {

    Node() : id(0), next(nullptr)
        {}

    int  id;
    Node * next;
    
    void connect (Node & node_) {
        next = &node_;
    }
    
    ~Node() {std::cout << "Destroying Node, id: "<<id<<"\n";}
};


Node * reverse_linked_list (Node & head)
{
    Node * curr_node_ptr, *prev_node_ptr, *next_node_ptr;

    prev_node_ptr =  &head;
    curr_node_ptr =  head.next;


    while (1)
    {
        if (curr_node_ptr == nullptr)
            break;

        next_node_ptr = curr_node_ptr->next;
        
        //  switching pointers
        curr_node_ptr->next = prev_node_ptr;

        prev_node_ptr = curr_node_ptr;

        curr_node_ptr = next_node_ptr;
    }    

    head.next = nullptr;
    
    return prev_node_ptr;
}


int main()
{
    Node * pHead = new Node;
    Node * ptr = pHead;
    for (int i = 1; i < 10; i++)
    {
        ptr->connect(*new Node);
        ptr = ptr->next;

        ptr->id = i;
    }

    for (Node * ptr = pHead; ptr != nullptr; ptr = ptr->next)
        std::cout << ptr->id << "\n";

    std::cout << "\n";
    pHead = reverse_linked_list (*pHead);
    
    for (Node * ptr = pHead; ptr != nullptr; ptr = ptr->next)
        std::cout << ptr->id << "\n";

    std::cout << "\n";
    
    // deleting list
    for (Node * ptr = pHead; ptr != nullptr;)
    {
        Node * next = ptr->next;
        delete ptr;
        ptr = next;
    }    
}

