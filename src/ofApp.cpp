#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetWindowPosition(300, 1200);
    ofSetWindowShape(1200, 320);
    ofBackground(0, 0, 0, 0);

    fboR.allocate(ofGetWidth(), ofGetHeight());
    fboR.begin();
    ofClear(0, 0, 0, 0);
    fboR.end();

    fboG.allocate(ofGetWidth(), ofGetHeight());
    fboG.begin();
    ofClear(0, 0, 0, 0);
    fboG.end();

    fboB.allocate(ofGetWidth(), ofGetHeight());
    fboB.begin();
    ofClear(0, 0, 0, 0);
    fboB.end();
		
    fbo.allocate(ofGetWidth(), ofGetHeight());
    fbo.begin();
    ofClear(0, 0, 0, 0);
    fbo.end();
    
    gui.setup();
    gui.setPosition(10, 20);
    gui.add(toggleR.setup("draw R", true));
    gui.add(toggleG.setup("draw G", true));
    gui.add(toggleB.setup("draw B", true));
    gui.add(toggleDebug.setup("draw debug", true));
    gui.add(floatSliderColorR.setup("color R", 1.0, 0.0, 5.0));
    gui.add(floatSliderColorG.setup("color G", 1.0, 0.0, 5.0));
    gui.add(floatSliderColorB.setup("color B", 1.0, 0.0, 5.0));
    showGui = true;
		
    image.loadImage("photo.jpg");
		
#ifdef TARGET_OPENGLES
//    shader.load("shadersES2/shader");
    ofLogNotice("shader not found: TARGET_OPENGLES");
#else
    if(ofIsGLProgrammableRenderer()){
        shader.load("shadersGL3/shader");
    }else{
//        shader.load("shadersGL2/shader");
        ofLogNotice("shader not found: shadersGL2");
    }
#endif
		
		
    TIME_SAMPLE_SET_FRAMERATE(60.0f);
//    ofSetVerticalSync(false);
    colorSelector = 0;
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofLogNotice(ofToString((float)floatSliderColorB));
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
    ofClear(0, 0, 0, 0);
    //R
    shader.begin();
    float colorValueR[] = {floatSliderColorR, 0.0, 0.0, 1.0};
    shader.setUniform4fv("colorValue", colorValueR);
    image.draw(0, 0);
    shader.end();
    
    //G
    shader.begin();
    float colorValueG[] = {0.0, floatSliderColorG, 0.0, 1.0};
    shader.setUniform4fv("colorValue", colorValueG);
    image.draw(0, 0);
    shader.end();

    //B
    shader.begin();
    float colorValueB[] = {0.0, 0.0, floatSliderColorB, 1.0};
    shader.setUniform4fv("colorValue", colorValueB);
    image.draw(0, 0);
    shader.end();

    fbo.end();
    fbo.draw(0, 0);
    
    if (toggleDebug) {
        drawDebug();
    }
    if (showGui) {
        gui.draw();
    }
    
    

}

void ofApp::flashDraw(){
    shader.begin();
    colorSelector++;
    colorSelector %= 3;
    float col[4];
    switch (colorSelector) {
        case 0:
            col[0] = 1.0;
            col[1] = 0.0;
            col[2] = 0.0;
            col[3] = 1.0;
            break;
        case 1:
            col[0] = 0.0;
            col[1] = 1.0;
            col[2] = 0.0;
            col[3] = 1.0;
            break;
        case 2:
            col[0] = 0.0;
            col[1] = 0.0;
            col[2] = 1.0;
            col[3] = 1.0;
            break;
        default:
            break;
    }
    shader.setUniform4fv("colorValue", col);
    image.draw(0, 0);
    shader.end();
}

void ofApp::drawR(){
    fboR.begin();
	ofClear(0, 0, 0, 0);
    ofSetColor(255, 0, 0, 85);
    ofCircle(100, 100, 100);
    fboR.end();
    ofSetColor(255, 255, 255, 255);
    fboR.draw(0, 0);
}

void ofApp::drawG(){
    fboG.begin();
    ofClear(0, 0, 0, 0);
	ofSetColor(0, 255, 0, 85);
    ofCircle(150, 100, 100);
    fboG.end();
	ofSetColor(255, 255, 255, 255);
    fboG.draw(0, 0);
}

void ofApp::drawB(){
    fboB.begin();
    ofClear(0, 0, 0, 0);
    ofSetColor(0, 0, 255, 85);
    ofCircle(125, 150, 100);
    fboB.end();
    ofSetColor(255, 255, 255, 255);
    fboB.draw(0, 0);
}

void ofApp::imageFilter(ofImage *img, ofImage *filteredImage, float r, float g, float b){
    *filteredImage = *img;
    unsigned char* imageData =  filteredImage->getPixels();
    for (int i = 0; i < img->getHeight(); i++) {
        for (int j = 0; j < img->getWidth(); j++) {
            imageData[(int)img->getWidth()*3*i+3*j] *= r;
            imageData[(int)img->getWidth()*3*i+3*j+1] *= g;
            imageData[(int)img->getWidth()*3*i+3*j+2] *= b;
        }
    }
    filteredImage->update();
}

void ofApp::drawDebug(){
    // show frame rate
    ofSetWindowTitle(ofToString(ofGetFrameRate(), 0));
    // guide line
    ofSetColor(255, 255, 255);
    ofLine(0, ofGetHeight()/2., ofGetWidth(), ofGetHeight()/2.);
    ofLine(ofGetWidth()/2., 0, ofGetWidth()/2., ofGetHeight());
    ofSetColor(255, 255, 255, 255);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'h':
            showGui = !showGui;
            break;
        case 't':
            TIME_SAMPLE_GET_ENABLED() ? TIME_SAMPLE_DISABLE() : TIME_SAMPLE_ENABLE();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
		
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
		
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
		
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
		
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
		
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
