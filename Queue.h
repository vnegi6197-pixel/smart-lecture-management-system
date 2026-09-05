#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>
template<class T> class Queue{
 struct Node{T data;Node* next;Node(T v):data(v),next(nullptr){}};
 Node *frontNode,*rearNode; int size;
public:
 Queue():frontNode(nullptr),rearNode(nullptr),size(0){}
 ~Queue(){while(!empty())dequeue();}
 bool empty()const{return frontNode==nullptr;}
 void enqueue(T v){Node*n=new Node(v);if(!rearNode)frontNode=rearNode=n;else{rearNode->next=n;rearNode=n;}++size;}
 T dequeue(){if(empty())throw std::runtime_error("Queue is empty");Node*t=frontNode;T v=t->data;frontNode=frontNode->next;if(!frontNode)rearNode=nullptr;delete t;--size;return v;}
 int getSize()const{return size;}
};
#endif
