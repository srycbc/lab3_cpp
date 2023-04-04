
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (rear == NULL) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    int top() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return front->data;
    }

    int size() {
        int count = 0;
        Node* temp = front;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    bool isEmpty() {
        if (front == NULL) {
            cout << "Yes" << endl;
            return true;
        } else {
            cout << "No" << endl;
            return false;
        }
    }

    void frontToBack(){
        Node *current, *prev, *next;
        current = front;
        next = front;
        prev = NULL;
        next = NULL;
        rear = front;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        front = prev;

    }
};

int main() {
    Queue q;

    q.enqueue(29);
    q.enqueue(33);
    q.enqueue(51);
    q.enqueue(47);
    q.enqueue(63);


    q.display();
    q.frontToBack();
    q.display();


    q.dequeue();
    q.dequeue();

    q.display();
    q.frontToBack();


    return 0 ;
}

