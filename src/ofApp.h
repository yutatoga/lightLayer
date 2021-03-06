#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "ofxXmlSettings.h"
#include "ofxTimeMeasurements.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void flashDraw();
    void drawR();
    void drawG();
    void drawB();
    void drawRGB();
    void drawDebug();
    void imageFilter(ofImage *img, ofImage *filteredImage, float r, float g, float b);
    
    //ofxUI
    void exit();
    void guiEvent(ofxUIEventArgs &e);
    
    //camera
    void takePicture(int RGBID);
    
    ofFbo fboR, fboG, fboB, fbo;
    ofImage image;
    ofImage imageArrayRGB[3];
    ofShader shader;
    int colorSelector;
    
    //ofxUI
    ofxUICanvas *gui;
    bool toggleDrawR, toggleDrawG, toggleDrawB, toggleDrawDebug, toggleDrawCamera, buttonCameraR, buttonCameraG, buttonCameraB, enableProjectionRGB;
    float sliderR, sliderG, sliderB;
    
    //camera
    int cameraWidth;
    int cameraHeight;
    ofVideoGrabber videoGrabber;
    
    //enable projection installation
    //    bool enableProjectionRGB;
    int lastShootingTime;
    float flashTime;
    float waitingTime;
    int projectionColorID;
    
    bool cursorVisible;
};
