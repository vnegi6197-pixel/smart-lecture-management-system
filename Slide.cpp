#include "Slide.h"
#include <iostream>
using namespace std;
Slide::Slide():id(0),timestamp(0){}
Slide::Slide(int id,int timestamp,string imagePath,string title,string text)
:id(id),timestamp(timestamp),imagePath(imagePath),title(title),text(text){}
int Slide::getId()const{return id;}
int Slide::getTimestamp()const{return timestamp;}
string Slide::getImagePath()const{return imagePath;}
string Slide::getTitle()const{return title;}
string Slide::getText()const{return text;}
void Slide::setTitle(string title){this->title=title;}
void Slide::setText(string text){this->text=text;}
void Slide::display()const{
 cout<<"\n-------------------------\n";
 cout<<"Slide ID   : "<<id<<"\n";
 cout<<"Timestamp  : "<<timestamp<<" seconds\n";
 cout<<"Image      : "<<imagePath<<"\n";
 cout<<"Title      : "<<title<<"\n";
 cout<<"Text       : "<<text<<"\n";
 cout<<"-------------------------\n";
}
