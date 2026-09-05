#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>
using namespace std;
class HashTable{
 struct Entry{string key;vector<int> ids;bool occupied;Entry():occupied(false){}};
 vector<Entry> table; int capacity;
 int hashFunction(const string&k)const{unsigned long h=0;for(char c:k)h=h*31+(unsigned char)c;return h%capacity;}
public:
 explicit HashTable(int n=101):table(n),capacity(n){}
 void insert(const string&k,int id){
  if(k.empty())return;int i=hashFunction(k),s=i;
  while(table[i].occupied&&table[i].key!=k){i=(i+1)%capacity;if(i==s)return;}
  if(!table[i].occupied){table[i].occupied=true;table[i].key=k;}
  for(int x:table[i].ids)if(x==id)return;table[i].ids.push_back(id);
 }
 vector<int> search(const string&k)const{
  int i=hashFunction(k),s=i;
  while(table[i].occupied){if(table[i].key==k)return table[i].ids;i=(i+1)%capacity;if(i==s)break;}
  return {};
 }
};
#endif
