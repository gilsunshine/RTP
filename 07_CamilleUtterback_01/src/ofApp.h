#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxBox2d.h"

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();

        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
        ofVideoGrabber grabber;
        ofImage camGray;
        ofImage prevGray;
        ofImage diffImg;
        ofImage threshImg;
        ofxCv::ContourFinder finder;

        ofColor targetColor;
        
        vector < ofPoint > pts;
        ofxBox2d box2d;
        
        ofTrueTypeFont font;

        vector <string> stringLetters;
        vector <ofPath> rainLetters;

        vector <shared_ptr<ofxBox2dBaseShape>> bodies;
        vector <shared_ptr<ofxBox2dRect>> rects;
        vector <shared_ptr<ofxBox2dEdge>> edges;
    
};
