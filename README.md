# Smart Lecture Management System

Complete C++17 + OpenCV DSA core for the Smart Lecture Management System.

Features:
- Video input
- FPS/frame count/duration
- 1 frame per second sampling
- Basic slide-change detection
- Custom Queue, Linked List, Stack, Hash Table
- BST timestamp ordering
- Max Heap ranking
- Graph + BFS
- Keyword indexing/search
- Save/load lecture data
- TXT notes export

## Termux build

Check OpenCV availability:
pkg update
pkg search opencv

Then compile:
g++ -std=c++17 main.cpp Slide.cpp VideoProcessor.cpp LectureManager.cpp -o smartlecture $(pkg-config --cflags --libs opencv4)

Run:
./smartlecture

Note: OCR/Tesseract and PDF generation are not included yet because Termux package availability varies. Slide already has title/text fields for later OCR integration.
