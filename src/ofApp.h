#pragma once

#include "ofMain.h"
#include "ofxGui.h"
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
    void drawDebug();
    void imageFilter(ofImage *img, ofImage *filteredImage, float r, float g, float b);
    
    ofFbo fboR, fboG, fboB, fbo;
    ofxPanel gui;
    ofxToggle toggleR, toggleG, toggleB, toggleDebug;
    ofxFloatSlider floatSliderColorR, floatSliderColorG, floatSliderColorB;
    bool showGui;
    ofImage image;
    ofShader shader;
    int colorSelector;
};
