#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    
    font.load("RobotoMono-Regular.ttf", 14, false, false, true);

    grabber.initGrabber(640, 480);
    
    finder.setMinAreaRadius(10);
    finder.setMaxAreaRadius(150);
    
    box2d.init();
    box2d.setGravity(0, 30);
    box2d.setFPS(60.00);
    
    string text = "heavyletters";
    for(int i = 0; i < text.length(); i++){
        stringLetters.push_back({1, text[i]});
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
     if (grabber.isFrameNew()){
         edges.clear();
         finder.setTargetColor(targetColor, true ? TRACK_COLOR_HS : TRACK_COLOR_RGB);
         finder.setThreshold(50);
         finder.findContours(grabber);
         auto edge = make_shared<ofxBox2dEdge>();
         if(finder.getPolyline(0).size() > 0) {
             for (int j=0; j<finder.getPolyline(0).size(); j++) {
                 float x = finder.getPolyline(0)[j].x;
                 float y = finder.getPolyline(0)[j].y;
                 edge->addVertex(x, y);
             }
         }
         edge->create(box2d.getWorld());
         edges.push_back(edge);
     }
    
    finder.setSortBySize(true);
    
    for (int i = 0; i < rects.size(); i++){
        if(rects.size()>200){
            rects.erase(rects.begin());
            rainLetters.erase(rainLetters.begin());
        }
    }
    if (ofGetFrameNum()%1 == 0 ){

        auto r = make_shared<ofxBox2dRect>();
        
        r->setPhysics(0.2, 0.2, 0.002);
        r->setup(box2d.getWorld(), ofRandom(ofGetWidth()), 0, 14, 14);
        r->setVelocity(0, 5);
        rects.push_back(r);
        
        ofPath letter = font.getStringAsPoints(stringLetters[ofRandom(stringLetters.size())])[0];
        rainLetters.push_back(letter);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    grabber.draw(0,0);
    box2d.update();

    
//    ofSetLineWidth(2);
//    if(finder.size() > 0){
//        finder.getPolyline(0).draw();
//    }
    
    for(int i = 0; i < rects.size(); i++){
        ofSetColor(50,100,255);
//        rects[i]->draw();
        ofPushMatrix();
        ofTranslate(rects[i]->getPosition().x-7, rects[i]->getPosition().y+7);
        ofRotateDeg(rects[i]->getRotation());
        ofFill();
        ofSetColor(50,100,255);
       rainLetters[i].draw();
        ofPopMatrix();
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
    targetColor = grabber.getPixels().getColor(x, y);
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
