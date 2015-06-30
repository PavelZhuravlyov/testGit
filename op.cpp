#include <stdio.h>
#include "highgui.h"
#include "cv.h"

int main() {
    
    IplImage *test; //create image pointer
    test = cvCreateImage(cvSize(640,480), IPL_DEPTH_8U, 3); //image size, 8-bit depth per channel, and 3 channels (RGB)
    cvSetZero(test); //image will be black (all zeroes) by default, so this is belt and suspenders
    
    //set up a font to use on images
    CvFont textfont;
    cvInitFont(&textfont, CV_FONT_HERSHEY_DUPLEX, 3,3, 0, 3, 4);
    
    //RGB color - white
    CvScalar color = cvScalar(255,255,255,0); //fourth value is unused
    
    //write some text on the image
    cvPutText(test, "Hello World", cvPoint(40,270), &textfont, color);
    
    cvNamedWindow("Test", CV_WINDOW_AUTOSIZE); //create a window
    cvShowImage("Test", test); //name of window and image to display in it
    
    cvWaitKey(0); //wait for the user to press a key
    
    cvDestroyWindow("Test");
    cvReleaseImage(&test); //frees the memory
}
