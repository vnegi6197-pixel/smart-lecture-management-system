# Smart Lecture Management System

A C++ and OpenCV based system for processing lecture videos and detecting unique slide changes.

## Overview

The Smart Lecture Management System analyzes a lecture video at one-second intervals and compares frames to detect when the displayed slide changes.

When a significant visual difference is detected, the frame is saved as a new slide image.

## Features

- Accepts a video path from the terminal
- Reads video FPS and duration
- Processes video frames at one-second intervals
- Converts frames to grayscale for comparison
- Calculates absolute frame differences
- Uses an average difference threshold to detect slide changes
- Saves detected slides as JPG images
- Displays the timestamp at which a new slide is detected

## Technologies Used

- C++
- OpenCV
- Data Structures and Algorithms concepts
- Image/frame processing

## Current Detection Method

The current version compares consecutive relevant frames using:

1. Grayscale conversion
2. Absolute pixel difference
3. Mean difference calculation
4. A configurable threshold

If the calculated difference is greater than the threshold, the system considers it a new slide.

> Note: Hashing-based duplicate detection is planned for a future version. The current implementation uses frame-difference detection.

## Requirements

- C++ compiler
- OpenCV

## How to Run

1. Install OpenCV and configure it with your C++ compiler.
2. Compile `main.cpp` with OpenCV.
3. Run the executable.
4. Enter the path of the lecture video when prompted.

Example:

```text
Enter video path: lecture.mp4
```

The detected slides will be saved as:

```text
slide_1.jpg
slide_2.jpg
slide_3.jpg
...
```

## Project Status

**Ongoing**

Future improvements may include:

- Hashing-based duplicate frame detection
- Better slide-change detection
- Timestamp storage
- Organized output directories
- More efficient video processing
