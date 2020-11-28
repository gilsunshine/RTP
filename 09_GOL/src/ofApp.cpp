#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetFrameRate(30);
    columns = 200;
    rows = 200;
    w = ofGetWidth()/columns;
}

//--------------------------------------------------------------
void ofApp::update(){

    for (int x = 0; x < columns; x++) {
      for (int y = 0; y < rows; y++) {

        float neighbors = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++){
                int col =(x+i+columns)%columns;
                int row = (y+j+rows)%rows;
            neighbors += board[col][row];
          }
        }
          
        neighbors -= board[x][y];
        

        if      ((board[x][y] == 1) && (neighbors <  2)) next[x][y] = 0;
        else if ((board[x][y] == 1) && (neighbors >  3)) next[x][y] = 0;
        else if ((board[x][y] == 0) && (neighbors == 3)) next[x][y] = 1;
        else if ((board[x][y] == 0) && (neighbors - floor(neighbors) == 0.5)) next[x][y] == 1;
        else if ((board[x][y] == 0.5) && (neighbors > 0.5)) next[x][y] = 1;

        else next[x][y] = board[x][y];
      }
    }

    for (int x = 0; x < columns; x++) {
        for (int y = 0; y < rows; y++) {
                prevBoard[x][y] = board[x][y];
                board[x][y] = next[x][y];
        }
    }
}


//--------------------------------------------------------------
void ofApp::draw(){
    for ( int i = 0; i < columns;i++) {
      for ( int j = 0; j < rows;j++) {
          if (prevBoard[i][j] == 0 && board[i][j] == 1){
              ofSetColor(255,255,0);
              ofDrawRectangle(i*w, j*w, w, w);

          }else if(board[i][j] == 1){
              col[i][j] += 2;
              ofSetColor(0);
              ofDrawRectangle(i*w, j*w, w, w);
          }else if(prevBoard[i][j] == 1 && board[i][j] == 0){
              ofSetColor(255,0,0);
              ofDrawRectangle(i*w, j*w, w, w);
          } else if(board[i][j] == 0){
              ofSetColor(0,col[i][j]);
              ofDrawRectangle(i*w, j*w, w, w);
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
    int num1 = ofMap(mouseX, 0, ofGetWidth(), 0, columns);
    int num2 = ofMap(mouseY, 0, ofGetHeight(), 0, rows);
    board[num1][num2] = 1;
    board[num1+1][num2+1] = 1;
    board[num1-1][num2+1] = 1;
    cout << board[num1][num2] << endl;

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
