#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Slide.h"
#include <iostream>
using namespace std;
struct SlideNode{Slide data;SlideNode* next;SlideNode(Slide s):data(s),next(nullptr){}};
class LinkedList{
 SlideNode* head; int size;
public:
 LinkedList():head(nullptr),size(0){}
 ~LinkedList(){clear();}
 void insertEnd(Slide s){
  SlideNode* n=new SlideNode(s);
  if(!head) head=n; else {SlideNode* c=head;while(c->next)c=c->next;c->next=n;}
  ++size;
 }
 bool deleteById(int id){
  if(!head)return false;
  if(head->data.getId()==id){auto t=head;head=head->next;delete t;--size;return true;}
  SlideNode* c=head;
  while(c->next){if(c->next->data.getId()==id){auto t=c->next;c->next=t->next;delete t;--size;return true;}c=c->next;}
  return false;
 }
 Slide* findById(int id){for(auto c=head;c;c=c->next)if(c->data.getId()==id)return &c->data;return nullptr;}
 void displayAll()const{if(!head){cout<<"No slides available.\n";return;}for(auto c=head;c;c=c->next)c->data.display();}
 int getSize()const{return size;}
 SlideNode* getHead(){return head;}
 void clear(){auto c=head;while(c){auto t=c;c=c->next;delete t;}head=nullptr;size=0;}
};
#endif
