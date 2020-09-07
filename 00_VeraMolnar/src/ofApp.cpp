#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(223, 223, 226); // slightly blue background
    ofSetColor(0, 0, 3, 200); // slightly blue squares  
    goBack = true;
    count = 0;
    cycleLength = 120;
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j <5; j++){
            startingPoints[i][j].set((i + 1) * 125 + 25, (j + 1) * 120 + 112); // lays out the "home" position for the rectangles
            ofSetRectMode(OF_RECTMODE_CENTER);
            columns[i][j].set(startingPoints[i][j], 120, 120); // start rectangles from "home" position
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    time = ofGetElapsedTimef(); // time is used to update noise function
    for (int i = 0; i < 5; i++){
        rowShift[i] = ofSignedNoise(time + i, time) * 0.25; // each element in a row subtley moves in conjunction.
    }
    
    if(count == cycleLength){
        goBack = !goBack; // resets the loop
        count = 0;
    }
    
    if(!goBack){
        count++;
        if (count < cycleLength / 6){
            for(int i = 0; i < 5; i++){
                columnShift = ofSignedNoise(time + i, time) * 2.5; // each element in a column moves moves in conjunction
                 for(int j = 0; j <5; j++){
                     float translateX = ofSignedNoise(time + i, time + j) * 0.1 + rowShift[j];
                     float translateY = ofSignedNoise(time + j, time + i) * 0.8 + columnShift;
                     columns[i][j].translate(translateX, translateY);
                 }
             }
        }
    } else {
        count++;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j <5; j++){
                if(columns[i][j].position.x != startingPoints[i][j].x && columns[i][j].position.y != startingPoints[i][j].y){
                    columns[i][j].set(columns[i][j].x - (columns[i][j].x - startingPoints[i][j].x) * 0.3, columns[i][j].y -  (columns[i][j].y - startingPoints[i][j].y) * 0.3 , 120,  120); //moves rectangle towards starting position.
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
