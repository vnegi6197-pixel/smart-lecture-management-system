#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int main()
{
    string path;

    cout << "Enter video path: ";
    getline(cin, path);

    VideoCapture video(path);

    if (!video.isOpened())
    {
        cout << "Error: Cannot open video.\n";
        return 1;
    }

    double fps = video.get(CAP_PROP_FPS);
    double totalFrames = video.get(CAP_PROP_FRAME_COUNT);

    double duration = totalFrames / fps;

    cout << "\nFPS: " << fps << endl;
    cout << "Duration: " << duration << " seconds\n";

    Mat previousFrame;
    Mat currentFrame;

    int slideNumber = 0;

    // Difference threshold
    double threshold = 15.0;

    for (int second = 0; second < duration; second++)
    {
        // Move to required second
        video.set(CAP_PROP_POS_MSEC, second * 1000);

        // Read current frame
        if (!video.read(currentFrame))
        {
            cout << "Could not read frame.\n";
            break;
        }

        // First frame is automatically a slide
        if (previousFrame.empty())
        {
            slideNumber++;

            string filename =
                "slide_" + to_string(slideNumber) + ".jpg";

            imwrite(filename, currentFrame);

            cout << "New slide detected at "
                 << second << " sec -> "
                 << filename << endl;

            // Store current frame
            currentFrame.copyTo(previousFrame);

            continue;
        }

        // Convert both frames to grayscale
        Mat previousGray;
        Mat currentGray;

        cvtColor(previousFrame, previousGray, COLOR_BGR2GRAY);
        cvtColor(currentFrame, currentGray, COLOR_BGR2GRAY);

        // Calculate absolute difference
        Mat difference;

        absdiff(previousGray, currentGray, difference);

        // Calculate average difference
        Scalar meanDifference = mean(difference);

        double differenceValue = meanDifference[0];

        cout << "Second " << second
             << " | Difference = "
             << differenceValue << endl;

        // Check whether slide changed
        if (differenceValue > threshold)
        {
            slideNumber++;

            string filename =
                "slide_" + to_string(slideNumber) + ".jpg";

            imwrite(filename, currentFrame);

            cout << ">>> NEW SLIDE: "
                 << filename << endl;

            // Update previous slide
            currentFrame.copyTo(previousFrame);
        }
    }

    video.release();

    cout << "\nTotal slides detected: "
         << slideNumber << endl;

    return 0;
}
