#include <iostream>
#include <string>
#include "LectureManager.h"
using namespace std;
int main(){
 LectureManager system;int choice;
 do{
  cout<<"\n====================================\nSMART LECTURE MANAGEMENT SYSTEM\n====================================\n";
  cout<<"1. Process Lecture Video\n2. Display Slides\n3. Add Slide Manually\n4. Delete Slide\n5. Undo Last Addition\n6. Build Keyword Index\n7. Search Keyword\n8. Sort Slides by Timestamp\n9. Rank Slides\n10. Related Slides using BFS\n11. Save Lecture\n12. Load Lecture\n13. Export Notes\n0. Exit\nEnter choice: ";
  if(!(cin>>choice)){cin.clear();cin.ignore(10000,'\n');continue;}
  switch(choice){
   case 1:{string p;cout<<"Enter video path: ";cin>>p;system.processVideo(p);break;}
   case 2:system.displaySlides();break;case 3:system.addManualSlide();break;case 4:system.deleteSlide();break;case 5:system.undo();break;
   case 6:system.buildKeywordIndex();break;case 7:system.searchKeyword();break;case 8:system.sortSlides();break;case 9:system.rankSlides();break;
   case 10:system.graphDemo();break;case 11:system.saveLecture();break;case 12:system.loadLecture();break;case 13:system.exportNotes();break;
   case 0:cout<<"Exiting...\n";break;default:cout<<"Invalid choice.\n";
  }
 }while(choice!=0);
 return 0;
}
