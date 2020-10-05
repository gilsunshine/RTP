#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gridNum = 26;
    gridSize = ofGetWidth()/gridNum;
    xOffset = gridSize;
    yOffset = 0;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    line = holdLine;
    line = line.getResampledBySpacing(gridSize/4);
    line = line.getSmoothed(3,0);

    ofBackground(255);

    for (int i = 1; i <= 26; i ++){
        
        for (int j = 1; j <= 26; j++){
            ofSetColor(225);
            ofDrawLine(i * gridSize, 0, i * gridSize, ofGetHeight());
            ofDrawLine(0, j * gridSize, ofGetWidth(), j * gridSize);

        }
        
    }
 
    if (line.size() > 2){

        ofMesh mesh;
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        for (int i = 0; i < line.size(); i++){


            ofPoint one;
            one.set(line[i].x - xOffset, line[i].y - yOffset, line[i].z);
            ofPoint two = one;
            two.x = two.x + (2 * xOffset);
            two.y = two.y + (2 * yOffset);
            mesh.addVertex(one);
            mesh.addVertex(two);


        }
        ofSetColor(0);
        mesh.draw();
        mesh.drawWireframe();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's'){
        xOffset = 0;
        yOffset = gridSize;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    xOffset = gridSize;
    yOffset = 0;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){


    if(abs(previousX - mouseX) < gridSize){
        currentX = previousX;
    } else{
        currentX = round(mouseX / gridSize) * gridSize;
    }
    
    if(abs(previousY - mouseY) < gridSize){
        currentY = previousY;
    } else{
        currentY = round(mouseY / gridSize) * gridSize;
    }

    if(line.size() == 0){
        holdLine.addVertex(currentX, currentY);
        line.addVertex(currentX, currentY);
        previousX = currentX;
        previousY = currentY;

    } else{
        float xDif = abs(mouseX - previousX);
        float yDif = abs(mouseY - previousY);

        if(abs(mouseX - previousX) > gridSize || abs(mouseY - previousY) > gridSize){
                if (xDif > yDif){
                    holdLine.addVertex(currentX, previousY);
                    line.addVertex(currentX, previousY);
                    previousX = currentX;
                    currentY = previousY;

                } else {
                    holdLine.addVertex(currentX, currentY);
                    line.addVertex(currentX, currentY);
                    previousY = currentY;
                    currentX = previousX;

                }
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    line.clear();
    holdLine.clear();
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
