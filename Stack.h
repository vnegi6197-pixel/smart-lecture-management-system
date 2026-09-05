#ifndef STACK_H
#define STACK_H
#include <stdexcept>
template<class T> class Stack{
 struct Node{T data;Node* next;Node(T v):data(v),next(nullptr){}};
 Node* topNode;
public:
 Stack():topNode(nullptr){}
 ~Stack(){while(!empty())pop();}
 bool empty()const{return topNode==nullptr;}
 void push(T v){Node*n=new Node(v);n->next=topNode;topNode=n;}
 T pop(){if(empty())throw std::runtime_error("Stack is empty");Node*t=topNode;T v=t->data;topNode=topNode->next;delete t;return v;}
 T top()const{if(empty())throw std::runtime_error("Stack is empty");return topNode->data;}
};
#endif
