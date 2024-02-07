#pragma once
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    void push_front(int data)
    {
        Node* node = new Node(data);

        if (head != nullptr)
        {
            node->next = head;
        }

        head = node;
    }

    void print()
    {
        Node* current = head;
        while (current)
        {
            std::cout << current->data;
            current = current->next;
        }
    }

    void push_back(int data)
    {
    }

    void popFront()
    {
        if (head == nullptr)
        {
            return;
        }

        Node* nodeToDelete = head;
        head = head->next;

        delete nodeToDelete;
    }

    void popBack() {}

    int front() {
        return head->data;
    }
    int back() { return 0; }

    int size() const { return 2; }

    Node* getHead() {
        return head;
    }

private:
    Node* head = nullptr;
    //Node* tail = nullptr;
};

bool has_cycle(Node* head);

unsigned int uniqueWordsCount(const std::string& line);

std::string mostOccuredWord(const std::string& line);

bool areBracketsWellClosed(std::string line);