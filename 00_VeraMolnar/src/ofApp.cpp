#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(225);
    ofSetColor(0,0,10,200);
    goBack = true;
    count = 0;
    cycleLength = 120;
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j <5; j++){
            startingPoints[i][j].set((i + 1) * 125 + 25, (j + 1) * 120 + 105);
            ofSetRectMode(OF_RECTMODE_CENTER);
            columns[i][j].set(startingPoints[i][j], 120, 120);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    time = ofGetElapsedTimef();
    for (int i = 0; i < 5; i++){
        rowShift[i] = ofSignedNoise(time + i, time) * 0.5;
    }
    
    if(count == cycleLength){
        goBack = !goBack;
        count = 0;
    }
    
    if(!goBack){
        count++;
        if (count < cycleLength / 6){
            for(int i = 0; i < 5; i++){
                columnShift = ofSignedNoise(time + i, time) * 2;
                 for(int j = 0; j <5; j++){
                     float translateX = ofSignedNoise(time + i, time + j) * 0.1 + rowShift[j] * 0.35;
                     float translateY = ofSignedNoise(time + j, time + i) * 0.5 + columnShift;
                     columns[i][j].translate(translateX, translateY);
                 }
             }
        }
    } else {
        count++;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j <5; j++){
                if(columns[i][j].position.x != startingPoints[i][j].x && columns[i][j].position.y != startingPoints[i][j].y){
                    columns[i][j].set(columns[i][j].x - (columns[i][j].x - startingPoints[i][j].x) * 0.3, columns[i][j].y -  (columns[i][j].y - startingPoints[i][j].y) * 0.3 , 120,  120);
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j <5; j++){
            ofDrawRectangle(columns[i][j]);
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
