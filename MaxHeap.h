#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <vector>
#include <stdexcept>
#include <utility>
using namespace std;
struct SlideScore{int slideId;int score;};
class MaxHeap{
 vector<SlideScore> h;
 void up(int i){while(i>0){int p=(i-1)/2;if(h[p].score>=h[i].score)break;swap(h[p],h[i]);i=p;}}
 void down(int i){int n=h.size();while(true){int l=2*i+1,r=2*i+2,b=i;if(l<n&&h[l].score>h[b].score)b=l;if(r<n&&h[r].score>h[b].score)b=r;if(b==i)break;swap(h[i],h[b]);i=b;}}
public:
 void push(SlideScore x){h.push_back(x);up(h.size()-1);}
 SlideScore pop(){if(h.empty())throw runtime_error("Heap is empty");auto x=h[0];h[0]=h.back();h.pop_back();if(!h.empty())down(0);return x;}
 bool empty()const{return h.empty();}
};
#endif
