#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int val){
            data = val;
            next = NULL;
        }
};
class queue{
    private:
        int size;
        Node *front;
        Node *rear;
    public:
    queue(){
            size = 0;
            front = rear = NULL;
    }
    void push(int val){
            Node *temp = new Node(val);
            if(front==NULL && rear==NULL){
                front = rear = temp;
            }
            else{
                rear->next = temp;
                rear = temp;
            }
    }
    int pop(){
        if(front==NULL && rear==NULL){
                return -1;
        }
        Node *temp = front;
        int val = temp->data;
        if(front==rear){
                temp = front;
                delete temp;
                front = rear = NULL;
                
        }
        else{
                front = front->next;
                delete temp;
        }
        return val;
    }
    int peek(){
        if(front==NULL && rear==NULL)
                return -1;
        else
                return front->data;
    }
    bool empty(){
        return front == NULL && rear == NULL;
    }

};
int main(){
    queue q;
    cout << q.pop() << endl;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "peek element is " << q.peek() << endl;
    while (!q.empty())
    {
        cout << q.peek() << " ";
        q.pop();
    }
    cout << endl
         << "is empty " << q.empty() << endl;
}