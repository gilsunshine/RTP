#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    grid = 900/12;
    transX = 1.5*grid;
    transY = 900-2*grid;
    font.load("Lato-Thin.ttf", 650, true, true, true);
    count = 0;
    holdCount = false;
    paths = font.getStringAsPoints("HELLOCOOPER");
    numLetters = paths.size();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);

    ofTranslate(transX,transY);
    if (count%numLetters == 0){
        paths = font.getStringAsPoints("H");
    }else if (count%numLetters == 1){
        paths = font.getStringAsPoints("E");
    }else if (count%numLetters == 2){
        paths = font.getStringAsPoints("L");
    }
    else if (count%numLetters == 3){
        paths = font.getStringAsPoints("L");
    }  else if (count%numLetters == 4){
           paths = font.getStringAsPoints("O");
    }else if (count%numLetters == 5){
        paths = font.getStringAsPoints("C");
    }else if (count%numLetters == 6){
        paths = font.getStringAsPoints("O");
    }
    else if (count%numLetters == 7){
        paths = font.getStringAsPoints("O");
    }  else if (count%numLetters == 8){
           paths = font.getStringAsPoints("P");
    }else if (count%numLetters == 9){
           paths = font.getStringAsPoints("E");
    }
    else{
        paths = font.getStringAsPoints("R");
    }
    cout<<count%numLetters<<endl;
    
        paths[0].setPolyWindingMode(OF_POLY_WINDING_ODD);
        vector < ofPolyline > lines = paths[0].getOutline();
    
        for (int j = 0; j < lines.size(); j++){

            lines[j].setClosed(true);
            lines[j] = lines[j].getResampledBySpacing(3);
            
            

             for(int g = grid; g < ofGetWidth(); g+=grid){
                    ofSetColor(255,50);
                    ofSetLineWidth(2);
                 if(g != grid && g != ofGetWidth() - grid){
                     if(j==0){
                         ofDrawLine(g-transX, grid - transY, g - transX, ofGetHeight() - transY - grid);
                         ofDrawLine(grid - transX, g - transY, ofGetWidth() - transX - grid, g - transY);
                     }

                 }
                    for(int h = grid; h < ofGetHeight(); h+=grid){
                        ofSetColor(255);
                        ofPoint point;
                        point.x = g - transX;
                        point.y = h - transY;
                        ofPoint closest = lines[j].getClosestPoint(point);
                        float dist = sqrt(pow(closest.x - point.x, 2)+pow(closest.y - point.y, 2));
                        float maxDist = 180;
                        if(dist > maxDist){
                            dist = maxDist;
                        }
                        float radius = ofMap(dist, 0, maxDist, 15, 0) + ofMap(mouseX, 0, ofGetWidth(), -15, 0);
                        if (radius < 0){
                            radius = 0;
                        }
                        ofDrawCircle(point.x, point.y, radius);
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
    if(x < grid && !holdCount){
        count++;
        paths.clear();
        holdCount = true;
    }
    if(x > ofGetWidth() - grid && holdCount){
        holdCount = false;
    }
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
