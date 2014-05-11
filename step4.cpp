/*************************************************************************
  > File Name: step4.cpp
  > Author: Yunfei Phil F
  > Mail: yunfei@iastate.edu
  > Version:  1.0
  > Function:  
  > Comments:  http://hxr99.blogspot.com/2011/12/opencv-examples-camera-capture.html
  > Created Time: 2014-4-13 21:56:19
  > Updated Time:  
 ************************************************************************/

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;


int main( int argc, const char** argv )
{
    CvCapture* capture = 0;
    Mat frame, frameCopy, image;

    capture = cvCaptureFromCAM( CV_CAP_ANY ); //0=default, -1=any camera, 1..99=your camera
    if( !capture )
    {
        cout << "No camera detected" << endl;
    }

    cvNamedWindow( "result", CV_WINDOW_AUTOSIZE );

    if( capture )
    {
        cout << "In capture ..." << endl;
        for(;;)
        {
            IplImage* iplImg = cvQueryFrame( capture );
            frame = iplImg;

            if( frame.empty() )
                break;
            if( iplImg->origin == IPL_ORIGIN_TL )
                frame.copyTo( frameCopy );
            else
                flip( frame, frameCopy, 0 );

            cvShowImage( "result", iplImg );

            if( waitKey( 10 ) >= 0 ){
                char save_path[80] = ".\\CapturedImage.jpg";  
                
                cvSaveImage(save_path, iplImg);  
                break;
            }
		}
            // waitKey(0);
        }

        cvReleaseCapture( &capture );
        cvDestroyWindow( "result" );

        return 0;
    }

