//
// Created by uqamportable on 02/08/18.
//

#ifndef IMAGEREC_IMAGETREATMENT_H
#define IMAGEREC_IMAGETREATMENT_H

#include "Serializable.h"
#include "VideoSources/VideoSource.h"
#include "VideoSources/RealSense.h"
#include "VideoSources/RealSenseVideo.h"
#include "VideoSources/Kinect.h"
#include "VideoSources/WebCam.h"
#include "ActivityRegion.h"

#include <map>
#include <string>
#include <opencv2/opencv.hpp>
#include <list>
#include <cstdlib>


class ImageTreatment : public Serializable {

public:
     ImageTreatment(std::map<std::string,std::string> stream);

     ~ImageTreatment();
     void deserialize(std::map<std::string,std::string> stream);
     std::string getCurrentTimeStamp();

     void update();
     void treatPicture(ActivityRegion* act);

     cv::Mat getOriginalImage();
     cv::Mat getCurrentImage();
     cv::Mat getDepthImage();


private:

    void saveVideos();

    cv::Mat colorPicture;
    cv::Mat depthPicture;
    cv::Mat imageTreated;
    cv::Mat resizedPicture;
    //cv::VideoWriter colorVid;
    //cv::VideoWriter depthVid;
    std::list<cv::Mat> colorFeed;
    std::list<cv::Mat> programFeed;
    std::list<cv::Mat> depthFeed;
    std::pair<int,int> screenSize;
    std::pair<int,int> originalSize;
    bool showPercentage;
    bool showName;
    bool showzone;
    VideoSource* source;
    bool videoSave;

};


#endif //IMAGEREC_IMAGETREATMENT_H