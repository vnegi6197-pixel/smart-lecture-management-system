#include "LectureManager.h"
#include "BST.h"
#include "MaxHeap.h"
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;
static string norm(string s){string r;for(unsigned char c:s)if(isalnum(c))r+=tolower(c);return r;}
void LectureManager::processVideo(const string&p){VideoProcessor(15.0).processVideo(p,slides);}
void LectureManager::displaySlides(){slides.displayAll();}
void LectureManager::addManualSlide(){
 int id,t;string img,title,text;cout<<"Enter slide ID: ";cin>>id;cout<<"Enter timestamp: ";cin>>t;cin.ignore();
 cout<<"Enter image path: ";getline(cin,img);cout<<"Enter title: ";getline(cin,title);cout<<"Enter notes: ";getline(cin,text);
 slides.insertEnd(Slide(id,t,img,title,text));undoStack.push(id);cout<<"Slide added.\n";
}
void LectureManager::deleteSlide(){int id;cout<<"Enter slide ID: ";cin>>id;if(slides.deleteById(id))cout<<"Slide deleted.\n";else cout<<"Slide not found.\n";}
void LectureManager::undo(){if(undoStack.empty()){cout<<"Nothing to undo.\n";return;}int id=undoStack.pop();if(slides.deleteById(id))cout<<"Undo successful.\n";}
void LectureManager::buildKeywordIndex(){
 for(SlideNode*c=slides.getHead();c;c=c->next){stringstream ss(c->data.getTitle()+" "+c->data.getText());string w;while(ss>>w){w=norm(w);if(!w.empty())keywordIndex.insert(w,c->data.getId());}}
 cout<<"Keyword index created.\n";
}
void LectureManager::searchKeyword(){string k;cout<<"Enter keyword: ";cin>>k;k=norm(k);auto r=keywordIndex.search(k);if(r.empty())cout<<"No slide found.\n";else{cout<<"Found in slides: ";for(int x:r)cout<<x<<" ";cout<<"\n";}}
void LectureManager::sortSlides(){BST b;for(SlideNode*c=slides.getHead();c;c=c->next)b.insert(c->data);b.displaySorted();}
void LectureManager::rankSlides(){MaxHeap h;for(SlideNode*c=slides.getHead();c;c=c->next)h.push({c->data.getId(),(int)(c->data.getTitle().size()+c->data.getText().size())});while(!h.empty()){auto x=h.pop();cout<<"Slide "<<x.slideId<<" -> Score "<<x.score<<"\n";}}
void LectureManager::graphDemo(){int n=slides.getSize();if(!n){cout<<"No slides available.\n";return;}Graph g(n);for(int i=0;i+1<n;i++)g.addEdge(i,i+1);g.BFS(0);}
void LectureManager::saveLecture(){ofstream f("lecture_database.txt");for(SlideNode*c=slides.getHead();c;c=c->next){auto&s=c->data;f<<s.getId()<<"|"<<s.getTimestamp()<<"|"<<s.getImagePath()<<"|"<<s.getTitle()<<"|"<<s.getText()<<"\n";}cout<<"Lecture saved.\n";}
void LectureManager::loadLecture(){ifstream f("lecture_database.txt");if(!f){cout<<"No saved lecture found.\n";return;}slides.clear();string line;while(getline(f,line)){stringstream ss(line);string a,b,c,d,e;getline(ss,a,'|');getline(ss,b,'|');getline(ss,c,'|');getline(ss,d,'|');getline(ss,e);try{slides.insertEnd(Slide(stoi(a),stoi(b),c,d,e));}catch(...){}}cout<<"Lecture loaded.\n";}
void LectureManager::exportNotes(){ofstream f("LectureNotes.txt");f<<"SMART LECTURE NOTES\n===================\n\n";for(SlideNode*c=slides.getHead();c;c=c->next){auto&s=c->data;f<<"Slide "<<s.getId()<<"\nTimestamp: "<<s.getTimestamp()<<" seconds\nTitle: "<<s.getTitle()<<"\nNotes: "<<s.getText()<<"\n\n";}cout<<"Notes exported to LectureNotes.txt\n";}
