#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    xGrid = 13;
    yGrid = 34;
    xSpacing = ofGetWidth()/xGrid;
    ySpacing = 0;
    yTrans = 0;
    for (int i = 0; i < yGrid; i ++){
        ySpaces[i] = ofMap(sin(i * PI/yGrid), 0, 1, 5, yGrid);
    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    yTrans = 0;
    float time = ofGetElapsedTimef();
    
    for (int j = 0; j <= yGrid; j++){
        ySpacing = ofMap(sin(j * PI/yGrid), 0, 1, 5, yGrid);

        if(j > 0){
            yTrans += ySpaces[j - 1];
        }

        for (int i = 0; i < xGrid; i ++){
            
            ofSetColor(ofMap(sin(j * PI / yGrid), 0, 1, 225, 0) + ofNoise(i) * 20);
            
            if((i + j) % 2 == 0){
                
                float shift = ofMap(sin(0.2*(time - j)), -1, 1, 0, 1);
                ofPushMatrix();
                ofTranslate(i * xSpacing, yTrans);
                ofSetPolyMode(OF_POLY_WINDING_NONZERO);
                ofBeginShape();
                    ofVertex(0,ySpacing);
                    ofVertex(xSpacing, ySpacing);
                    ofVertex(shift * xSpacing, 0);
                ofEndShape();
                ofPopMatrix();
            }
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
