#ifndef SLIDE_H
#define SLIDE_H
#include <string>
using namespace std;

class Slide {
    int id, timestamp;
    string imagePath, title, text;
public:
    Slide();
    Slide(int id, int timestamp, string imagePath, string title="", string text="");
    int getId() const;
    int getTimestamp() const;
    string getImagePath() const;
    string getTitle() const;
    string getText() const;
    void setTitle(string title);
    void setText(string text);
    void display() const;
};
#endif
