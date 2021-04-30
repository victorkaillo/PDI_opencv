#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
        Mat image;
        int width, height;
        VideoCapture cap;
        vector<Mat> planes;
        Mat histR, histG, histB;
        int nbins = 64;
        float range[] = { 0, 256 };
        const float *histrange = { range };
        bool uniform = true;
        bool acummulate = false;
        float dif;

        cap.open(0);

        if (!cap.isOpened()) {
                cout << "cameras indisponiveis";
                return -1;
        }

        cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
        cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);  
        width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
        height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

        cout << "largura = " << width << endl;
        cout << "altura  = " << height << endl;

        int histw = nbins, histh = nbins / 2;
        Mat histImgR(histh, histw, CV_8UC3, Scalar(0, 0, 0));
        Mat histImgG(histh, histw, CV_8UC3, Scalar(0, 0, 0));
        Mat histImgB(histh, histw, CV_8UC3, Scalar(0, 0, 0));

        while (1) {
                cap >> image;
                split(image, planes);
                calcHist(&planes[0], 1, 0, Mat(), histR, 1,
                        &nbins, &histrange,
                        uniform, acummulate);
                cap >> image;
                split(image, planes);
                calcHist(&planes[0], 1, 0, Mat(), histG, 1,
                        &nbins, &histrange,
                        uniform, acummulate);
                dif = compareHist(histR, histG, HISTCMP_CORREL);
                if (dif <= 0.96) {
                        putText(image, "MOVIMENTO DETECTADO", Point(width/2 - 200, height/2), FONT_HERSHEY_SIMPLEX, 2, Scalar(0,150,0), 4);
                }

                imshow("Detector de Movimento", image);
                if (waitKey(30) >= 0) break;
        }
        return 0;
}