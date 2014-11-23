#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
		ofSetWindowPosition(300, 1200);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
		ofBackground(0, 0, 0, 0);
    fboR.allocate(ofGetWidth(), ofGetHeight());
    fboG.allocate(ofGetWidth(), ofGetHeight());
    fboB.allocate(ofGetWidth(), ofGetHeight());
    fbo.allocate(ofGetWidth(), ofGetHeight());
		
    fboR.begin();
    ofClear(0, 0, 0, 0);
    fboR.end();
    
    fboG.begin();
    ofClear(0, 0, 0, 0);
    fboG.end();
    
    fboB.begin();
    ofClear(0, 0, 0, 0);
    fboB.end();
		
		fbo.begin();
    ofClear(0, 0, 0, 0);
    fbo.end();

    gui.setup();
    gui.setPosition(10, 20);
    gui.add(toggleR.setup("draw R", true));
    gui.add(toggleG.setup("draw G", true));
    gui.add(toggleB.setup("draw B", true));
    gui.add(toggleDebug.setup("draw debug", true));
    showGui = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
		fbo.begin();
		ofClear(0, 0, 0, 0);
    if (toggleR) {
        drawR();
    }
    if (toggleG) {
        drawG();
    }
    if (toggleB) {
        drawB();
    }
		fbo.end();
		ofSetColor(255, 255, 255, 255);
		fbo.draw(0, 0);
    if (toggleDebug) {
        drawDebug();
    }
    if (showGui) {
        gui.draw();
    }
}

void ofApp::drawR(){
    ofPushStyle();
    fboR.begin();
				ofBackground(0, 0, 0, 0);
        ofSetColor(255, 0, 0, 200);
        ofCircle(100, 100, 100);
    fboR.end();
		ofSetColor(255, 255, 255, 255);
    fboR.draw(0, 0);
    ofPopStyle();
}

void ofApp::drawG(){
    ofPushStyle();
    fboG.begin();
				ofBackground(0, 0, 0, 0);
				ofSetColor(0, 255, 0, 200);
        ofCircle(150, 100, 100);
    fboG.end();
		ofSetColor(255, 255, 255, 255);
    fboG.draw(0, 0);
    ofPopStyle();
}

void ofApp::drawB(){
    ofPushStyle();
    fboB.begin();
				ofBackground(0, 0, 0, 0);
        ofSetColor(0, 0, 255, 200);
        ofCircle(125, 150, 100);
    fboB.end();
		ofSetColor(255, 255, 255, 255);
    fboB.draw(0, 0);
    ofPopStyle();
}

void ofApp::drawDebug(){
        // debug
        stringstream ss;
        ss << "framerate: " << ofToString(ofGetFrameRate(), 0);
        ofDrawBitmapString(ss.str(), 10, 15);
        
        // guide line
        ofPushStyle();
        ofSetColor(255, 255, 255);
        ofLine(0, ofGetHeight()/2., ofGetWidth(), ofGetHeight()/2.);
        ofLine(ofGetWidth()/2., 0, ofGetWidth()/2., ofGetHeight());
        ofSetColor(255, 0, 255);
        ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'h':
            showGui = !showGui;
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
