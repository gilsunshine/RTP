#include "ofApp.h"
// NOTE THE VIDEO SETUP COMES DIRECTLY FROM THE VIDEOGRABBER EXAMPLE
//--------------------------------------------------------------
void ofApp::setup(){
    leaf00.load("images/leaf00.png");
    leaf01.load("images/leaf01.png");
    leaf02.load("images/leaf02.png");

    camWidth = ofGetWidth();
    camHeight = ofGetHeight();
    ofSetFrameRate(15);

    vector<ofVideoDevice> devices = vidGrabber.listDevices();

    for(size_t i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }

    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth, camHeight);

    videoPix.allocate(camWidth, camHeight, OF_PIXELS_RGB);
    videoTexture.allocate(videoPix);
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(255);
    vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    vector<ofImage> images;

        if(vidGrabber.isFrameNew()){
            ofPixels & pixels = vidGrabber.getPixels();
            
            for(size_t i = 0; i < pixels.getWidth(); i+=10){
                for(size_t j = 0; j < pixels.getHeight(); j+=10){
                    ofColor color = pixels.getColor(i, j);
                    float brightness = color.getBrightness();
                    ofPushMatrix();
                    ofTranslate(i,j);
                    ofRotateRad(ofMap(ofNoise(i,j),0,1,0,2*PI));

                    if( brightness < 100){
                        float brightScale = ofMap(brightness, 0, 100, .25, .75);
                        leaf00.draw(0,0, leaf00.getWidth() * brightScale, leaf00.getHeight() * brightScale);
                    }else if(brightness < 120){
                        float brightScale = ofMap(brightness, 100, 120, .25, .75);
                        leaf01.draw(0,0, leaf01.getWidth() * brightScale, leaf01.getHeight() * brightScale);
                    }else if (brightness < 160){
                        float brightScale = ofMap(brightness, 120, 160, .25, .75);
                        leaf02.draw(0,0, leaf02.getWidth() * brightScale, leaf02.getHeight() * brightScale);
                    }
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
