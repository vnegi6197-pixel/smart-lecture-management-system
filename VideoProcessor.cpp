#include "VideoProcessor.h"
#include "Queue.h"
#include <iostream>
#include <filesystem>
#include <cmath>
using namespace std;using namespace cv;namespace fs=std::filesystem;
double VideoProcessor::difference(const Mat&a,const Mat&b){
 Mat x,y,gx,gy,d;resize(a,x,Size(320,180));resize(b,y,Size(320,180));
 cvtColor(x,gx,COLOR_BGR2GRAY);cvtColor(y,gy,COLOR_BGR2GRAY);absdiff(gx,gy,d);return mean(d)[0];
}
void VideoProcessor::processVideo(const string&path,LinkedList&slides){
 VideoCapture video(path);if(!video.isOpened()){cerr<<"ERROR: Could not open video.\n";return;}
 double fps=video.get(CAP_PROP_FPS),total=video.get(CAP_PROP_FRAME_COUNT);
 if(fps<=0){cerr<<"ERROR: Invalid FPS.\n";return;}
 double duration=total/fps;
 cout<<"\nVideo Information\nFPS: "<<fps<<"\nFrames: "<<total<<"\nDuration: "<<duration<<" seconds\n";
 fs::create_directories("slides");Mat prev,cur;int id=0;
 for(int sec=0;sec<(int)ceil(duration);++sec){
  video.set(CAP_PROP_POS_MSEC,sec*1000.0);if(!video.read(cur))break;
  Queue<Mat>q;q.enqueue(cur.clone());Mat frame=q.dequeue();
  if(prev.empty()||difference(prev,frame)>threshold){
   string file="slides/slide_"+to_string(id)+".jpg";imwrite(file,frame);
   slides.insertEnd(Slide(id,sec,file));prev=frame.clone();
   cout<<"Slide detected at "<<sec<<" seconds\n";++id;
  }
 }
 video.release();cout<<"Processing complete. Total slides: "<<slides.getSize()<<"\n";
}
