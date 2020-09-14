#pragma once

#include "ofMain.h"
#include "ofxShivaVGRenderer.h"
#include "ofxPoly.h"
#include "ofxFatLine.h"


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
        
    
        float xOrig = ofGetWindowWidth() / 2;
        float yOrig = ofGetWindowHeight() / 2;
    
        float radius = 120;
        float length = 100;
    
        ofPolyline lines[36];
        ofPolyline p;
    
        int numCurves = 28;
    
        ofPolyline polyPoints;
        ofPolyline polyPoints1;
        ofPolyline polyPoints2;
        ofPolyline polyPoints3;
        ofPolyline polyPoints4;
        ofPolyline polyPoints5;
        ofPolyline polyPoints6;
        ofPolyline polyPoints7;

        float polyThickness;
        ofxFatLine fatLine;
        ofxFatLine fatLine1;
        ofxFatLine fatLine2;
        ofxFatLine fatLine3;
    
        vector<ofDefaultVec3> points;
        vector<ofDefaultVec3> points1;
        vector<ofDefaultVec3> points2;
        vector<ofDefaultVec3> points3;
    
        vector<ofFloatColor> colors;
        vector<ofFloatColor> colors1;
        vector<ofFloatColor> colors2;
        vector<ofFloatColor> colors3;
    
        vector<double> weights;
        vector<double> weights1;
        vector<double> weights2;
        vector<double> weights3;
    
        ofxFatLine fatLine4;
        ofxFatLine fatLine5;
        ofxFatLine fatLine6;
        ofxFatLine fatLine7;
    
        vector<ofDefaultVec3> points4;
        vector<ofDefaultVec3> points5;
        vector<ofDefaultVec3> points6;
        vector<ofDefaultVec3> points7;
    
        vector<ofFloatColor> colors4;
        vector<ofFloatColor> colors5;
        vector<ofFloatColor> colors6;
        vector<ofFloatColor> colors7;
    
        vector<double> weights4;
        vector<double> weights5;
        vector<double> weights6;
        vector<double> weights7;
    
        float zShift;
    
    private:
        ofPtr<ofBaseRenderer> _defaultRenderer;
        ofPtr<ofxShivaVGRenderer> _shivaVGRenderer;

    		
};
