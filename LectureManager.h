#ifndef LECTUREMANAGER_H
#define LECTUREMANAGER_H
#include "LinkedList.h"
#include "HashTable.h"
#include "Stack.h"
#include "VideoProcessor.h"
class LectureManager{
 LinkedList slides;HashTable keywordIndex;Stack<int> undoStack;
public:
 void processVideo(const std::string&);void displaySlides();void addManualSlide();void deleteSlide();void undo();
 void buildKeywordIndex();void searchKeyword();void sortSlides();void rankSlides();void graphDemo();
 void saveLecture();void loadLecture();void exportNotes();
};
#endif
