#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    gridSize = 31;
    spacing = ofGetWidth()/31;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float time = ofGetElapsedTimef();
    ofSetColor(50);
    for (int i = 1; i < gridSize; i ++){
        for (int j = 1; j < gridSize; j++){
            float shift = ofNoise(i * .05 * sin(time * 0.5),j * .05 * sin(time * 0.5));

            ofPushMatrix();
            ofTranslate(i * spacing, j * spacing);
            ofSetPolyMode(OF_POLY_WINDING_NONZERO);
            ofBeginShape();
                ofVertex(0,0);
                ofVertex(spacing, 0);
                ofVertex(shift * spacing, spacing);
            ofEndShape();
            ofPopMatrix();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
