#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//		ofSetWindowPosition(300, 1200);
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
    showGui = true;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
		fbo.begin();
		ofClear(0, 0, 0, 0);
		glBlendFunc(GL_ONE, GL_ONE);
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
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		fbo.draw(0, 0);
    if (toggleDebug) {
        drawDebug();
    }
    if (showGui) {
        gui.draw();
    }
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
