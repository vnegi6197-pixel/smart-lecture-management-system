#ifndef BST_H
#define BST_H
#include "Slide.h"
#include <iostream>
using namespace std;
class BST{
 struct Node{Slide data;Node*l,*r;Node(Slide s):data(s),l(nullptr),r(nullptr){}};
 Node* root;
 Node* ins(Node*n,Slide s){if(!n)return new Node(s);if(s.getTimestamp()<n->data.getTimestamp())n->l=ins(n->l,s);else n->r=ins(n->r,s);return n;}
 void in(Node*n){if(!n)return;in(n->l);cout<<"Slide "<<n->data.getId()<<" -> "<<n->data.getTimestamp()<<" sec\n";in(n->r);}
 void del(Node*n){if(!n)return;del(n->l);del(n->r);delete n;}
public:
 BST():root(nullptr){}~BST(){del(root);}
 void insert(Slide s){root=ins(root,s);}
 void displaySorted(){cout<<"\nSlides sorted by timestamp:\n";in(root);}
};
#endif
