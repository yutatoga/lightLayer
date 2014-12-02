#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
		ofSetWindowPosition(300, 1200);
//    ofEnableBlendMode(OF_BLENDMODE_ADD);
		glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE, GL_ONE, GL_ONE);
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
		
		glGetIntegerv( GL_BLEND_SRC, &last_blend_src );
		glGetIntegerv( GL_BLEND_DST, &last_blend_dst );
		glGetIntegerv(GL_BLEND_SRC_ALPHA, &last_blend_src_alpha);
		glGetIntegerv(GL_BLEND_DST_ALPHA, &last_blend_dst_alpha);
}

//--------------------------------------------------------------
void ofApp::update(){
		GLint blend_src, blend_dst, blend_src_alpha, blend_dst_alpha;
		glGetIntegerv( GL_BLEND_SRC, &blend_src );
		glGetIntegerv( GL_BLEND_DST, &blend_dst );
		glGetIntegerv(GL_BLEND_SRC_ALPHA, &blend_src_alpha);
		glGetIntegerv(GL_BLEND_DST_ALPHA, &blend_dst_alpha);
		if (blend_src != last_blend_src | blend_dst != last_blend_dst | blend_src_alpha != last_blend_src_alpha | blend_dst_alpha != last_blend_dst_alpha) {
				ofLogNotice("Blend Mode Changed!");
		}
		//ofLogNotice(ofToString(blend_src)+", "+ofToString(blend_dst)+", "+ofToString(blend_src_alpha)+", "+ofToString(blend_dst_alpha));
		last_blend_src = blend_src;
		last_blend_dst = blend_dst;
		last_blend_src_alpha = blend_src_alpha;
		last_blend_dst_alpha = blend_dst_alpha;
}

//--------------------------------------------------------------
void ofApp::draw(){
		ofClear(0, 0, 0, 255);
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

		ofSetColor(255, 0, 0, 127);
		ofCircle(100, 500, 100);
		ofSetColor(0, 255, 0, 127);
		ofCircle(150, 500, 100);
		ofSetColor(0, 0, 255, 127);
		ofCircle(125, 550, 100);
}

void ofApp::drawR(){
    fboR.begin();
				ofBackground(0, 0, 0, 0);
        ofSetColor(255, 0, 0, 127);
        ofCircle(100, 100, 100);
    fboR.end();
		ofSetColor(255, 255, 255, 255);
    fboR.draw(0, 0);
}

void ofApp::drawG(){
    fboG.begin();
				ofBackground(0, 0, 0, 0);
				ofSetColor(0, 255, 0, 127);
        ofCircle(150, 100, 100);
    fboG.end();
		ofSetColor(255, 255, 255, 255);
    fboG.draw(0, 0);
}

void ofApp::drawB(){
    fboB.begin();
				ofBackground(0, 0, 0, 0);
        ofSetColor(0, 0, 255, 127);
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
