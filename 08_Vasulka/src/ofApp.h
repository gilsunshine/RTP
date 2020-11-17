
#pragma once

#include "ofMain.h"
#include "ofxDelaunay.h"

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
        ofEasyCam cam;
        vector <ofPolyline> lines;
        vector <int> indices;
        int spacing;
        ofMesh mesh;
        ofxDelaunay triangulation;
        bool mouseDisplacement;
        ofMesh triMesh;
        ofMesh meshCopy;
        vector <ofColor> colors;
        int xSpacing;
};
