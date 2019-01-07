#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

#define CV_BGR2GRAY cv::COLOR_BGRA2GRAY
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cv::CascadeClassifier faceCascade;
    cv::CascadeClassifier eyesCascade;


    if (!faceCascade.load("/home/tylnesh/devel/EmoSens/OpenCV_eyetracking/haarcascade_frontalface_alt.xml"))
      {
          qDebug()  << "Could not load face detector." << endl;

      }
      if (!eyesCascade.load("/home/tylnesh/devel/EmoSens/OpenCV_eyetracking/haarcascade_eye_tree_eyeglasses.xml"))
      {
          qDebug() << "Could not load eye detector." << endl;

      }



    cv::VideoCapture cap(0); // the fist webcam connected to your PC
      if (!cap.isOpened())
      {
          qDebug() << "webcam not available";
      }
      cv::Mat frame;
      while (1)
      {
          cap >> frame; // outputs the webcam image to a Mat
          detectEyes(frame, faceCascade, eyesCascade);
          cv::imshow("Webcam", frame); // displays the Mat
          if (cv::waitKey(30) >= 0) break; // takes 30 frames per second. if the user presses any button, it stops from showing the webcam
      }


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::detectEyes(cv::Mat &frame, cv::CascadeClassifier &faceCascade, cv::CascadeClassifier &eyesCascade)
{
  cv::Mat grayscale;
  cv::cvtColor(frame, grayscale, CV_BGR2GRAY); // convert image to grayscale
  cv::equalizeHist(grayscale, grayscale); // enhance image contrast
  std::vector<cv::Rect> faces;
  faceCascade.detectMultiScale(grayscale, faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(150, 150));

  if (faces.size() == 0) return; // none face was detected
   cv::Mat face = frame(faces[0]); // crop the face
   std::vector<cv::Rect> eyes;
   eyesCascade.detectMultiScale(face, eyes, 1.1, 2, 0 |  cv::CASCADE_SCALE_IMAGE, cv::Size(150, 150)); // same thing as above

   rectangle(frame, faces[0].tl(), faces[0].br(), cv::Scalar(255, 0, 0), 2);
   if (eyes.size() != 1) return; // both eyes were not detected
   for (cv::Rect &eye : eyes)
   {
       rectangle(frame, faces[0].tl() + eye.tl(), faces[0].tl() + eye.br(), cv::Scalar(0, 255, 0), 2);
   }


}

