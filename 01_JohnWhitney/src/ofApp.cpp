#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    _shivaVGRenderer = ofPtr<ofxShivaVGRenderer>(new ofxShivaVGRenderer);
    ofSetCurrentRenderer(_shivaVGRenderer);
    
    for (int i = 0; i < numCurves; i++){
        float angle =ofMap(i, 0, numCurves, 0, 2*PI);
        float x = xOrig + radius * cos(angle);
        float y = yOrig + radius * sin(angle);
        float x1 = x;
        float y1 = y + length;

        lines[i].addVertex(x,y);
        lines[i].addVertex(x1,y1);
    }
    float sm =  -2;
    float md = -1;
    float lg = 1;
        
        ofVec3f vec;
        vec.set(-8.228,-8.827,md);
        polyPoints.addVertex(vec);
        vec.set(1.197,-14.362,sm);
        polyPoints.addVertex(vec);
        vec.set(9.275,-8.827,md);
        polyPoints.addVertex(vec);
        vec.set(12.716,11.220,lg);
        polyPoints.addVertex(vec);
        vec.set(-12.118,119.983,lg);
        polyPoints.addVertex(vec);
        vec.set(-4.638,141.825,md);
        polyPoints.addVertex(vec);
        vec.set(4.638,147.959,sm);
        polyPoints.addVertex(vec);
        vec.set(13.315,141.675,md);
        polyPoints.addVertex(vec);
    
        vec.set(13.315,141.675,md);
        polyPoints1.addVertex(vec);
        vec.set(4.638,147.959,sm);
        polyPoints1.addVertex(vec);
        vec.set(13.315,141.675,md);
        polyPoints1.addVertex(vec);
        vec.set(13.315,115.794,lg);
        polyPoints1.addVertex(vec);
        vec.set(-19.000,39.346,lg);
        polyPoints1.addVertex(vec);
        vec.set(-2.244,8.228,md);
        polyPoints1.addVertex(vec);
        vec.set(15.164,0.500,sm);
        polyPoints1.addVertex(vec);
        vec.set(24.086,11.220,md);
        polyPoints1.addVertex(vec);
    
        vec.set(-2.244,8.228,md);
        polyPoints2.addVertex(vec);
        vec.set(15.164,0.500,sm);
        polyPoints2.addVertex(vec);
        vec.set(24.086,11.220,md);
        polyPoints2.addVertex(vec);
        vec.set(22.590,31.118,lg);
        polyPoints2.addVertex(vec);
        vec.set(1.197,101.432,lg);
        polyPoints2.addVertex(vec);
        vec.set(2.094,119.983,md);
        polyPoints2.addVertex(vec);
        vec.set(13.315,127.463,sm);
        polyPoints2.addVertex(vec);
        vec.set(22.590,119.983,md);
        polyPoints2.addVertex(vec);
    
        vec.set(2.094,119.983,md);
        polyPoints3.addVertex(vec);
        vec.set(13.315,127.463,sm);
        polyPoints3.addVertex(vec);
        vec.set(22.590,119.983,md);
        polyPoints3.addVertex(vec);
        vec.set(22.590,94.999,lg);
        polyPoints3.addVertex(vec);
        vec.set(-14.512,11.220,lg);
        polyPoints3.addVertex(vec);
        vec.set(-8.228,-8.827,md);
        polyPoints3.addVertex(vec);
        vec.set(1.197,-14.362,sm);
        polyPoints3.addVertex(vec);
        vec.set(9.275,-8.827,md);
        polyPoints3.addVertex(vec);
    

        vec.set(-8.228,-8.827,md);
        polyPoints4.addVertex(vec);
        vec.set(1.197,-14.362,sm);
        polyPoints4.addVertex(vec);
        vec.set(9.275,-8.827,md);
        polyPoints4.addVertex(vec);
        vec.set(12.716,11.220,lg);
        polyPoints4.addVertex(vec);
        vec.set(-12.118,119.983,lg);
        polyPoints4.addVertex(vec);
        vec.set(-4.638,141.825,md);
        polyPoints4.addVertex(vec);
        vec.set(4.638,147.959,sm);
        polyPoints4.addVertex(vec);
        vec.set(13.315,141.675,md);
        polyPoints4.addVertex(vec);
    
        vec.set(13.315,141.675,md);
        polyPoints5.addVertex(vec);
        vec.set(4.638,147.959,sm);
        polyPoints5.addVertex(vec);
        vec.set(13.315,141.675,md);
        polyPoints5.addVertex(vec);
        vec.set(13.315,115.794,lg);
        polyPoints5.addVertex(vec);
        vec.set(-19.000,39.346,lg);
        polyPoints5.addVertex(vec);
        vec.set(-2.244,8.228,md);
        polyPoints5.addVertex(vec);
        vec.set(15.164,0.500,sm);
        polyPoints5.addVertex(vec);
        vec.set(24.086,11.220,md);
        polyPoints5.addVertex(vec);
    
        vec.set(-2.244,8.228,md);
        polyPoints6.addVertex(vec);
        vec.set(15.164,0.500,sm);
        polyPoints6.addVertex(vec);
        vec.set(24.086,11.220,md);
        polyPoints6.addVertex(vec);
        vec.set(22.590,31.118,lg);
        polyPoints6.addVertex(vec);
        vec.set(1.197,101.432,lg);
        polyPoints6.addVertex(vec);
        vec.set(2.094,119.983,md);
        polyPoints6.addVertex(vec);
        vec.set(13.315,127.463,sm);
        polyPoints6.addVertex(vec);
        vec.set(22.590,119.983,md);
        polyPoints6.addVertex(vec);
    
        vec.set(2.094,119.983,md);
        polyPoints7.addVertex(vec);
        vec.set(13.315,127.463,sm);
        polyPoints7.addVertex(vec);
        vec.set(22.590,119.983,md);
        polyPoints7.addVertex(vec);
        vec.set(22.590,94.999,lg);
        polyPoints7.addVertex(vec);
        vec.set(-14.512,11.220,lg);
        polyPoints7.addVertex(vec);
        vec.set(-8.228,-8.827,md);
        polyPoints7.addVertex(vec);
        vec.set(1.197,-14.362,sm);
        polyPoints7.addVertex(vec);
        vec.set(9.275,-8.827,md);
        polyPoints7.addVertex(vec);
    
//        polyPoints.close();
    float scale = 1.3;
        polyPoints.scale(scale, scale);
        polyPoints = polyPoints.getResampledBySpacing(1);
        polyPoints = polyPoints.getSmoothed(20);
    
        polyPoints1.scale(scale, scale);
        polyPoints1 = polyPoints1.getResampledBySpacing(1);
        polyPoints1 = polyPoints1.getSmoothed(20);
        
        polyPoints2.scale(scale, scale);
        polyPoints2 = polyPoints2.getResampledBySpacing(1);
        polyPoints2 = polyPoints2.getSmoothed(20);
        
        polyPoints3.scale(scale, scale);
        polyPoints3 = polyPoints3.getResampledBySpacing(1);
        polyPoints3 = polyPoints3.getSmoothed(20);
    
        polyPoints4.scale(scale, scale);
        polyPoints4 = polyPoints4.getResampledBySpacing(1);
        polyPoints4 = polyPoints4.getSmoothed(20);
    
        polyPoints5.scale(scale, scale);
        polyPoints5 = polyPoints5.getResampledBySpacing(1);
        polyPoints5 = polyPoints5.getSmoothed(20);
        
        polyPoints6.scale(scale, scale);
        polyPoints6 = polyPoints6.getResampledBySpacing(1);
        polyPoints6 = polyPoints6.getSmoothed(20);
        
        polyPoints7.scale(scale, scale);
        polyPoints7 = polyPoints7.getResampledBySpacing(1);
        polyPoints7 = polyPoints7.getSmoothed(20);
    
    for(int i = 0;  i < polyPoints.getVertices().size(); i++){
        double weight = ofMap(polyPoints[i].z, -1, 1, 0.01, 2.5);
        weights.push_back(weight);
        ofFloatColor c = ofColor::fromHsb(150, 255, 240);
        colors.push_back(c);
        points.push_back(polyPoints[i]);
    }
    
    for(int i = 0;  i < polyPoints1.getVertices().size(); i++){
        double weight = ofMap(polyPoints1[i].z, -1, 1, 0.01, 2.5);
        weights1.push_back(weight);
        ofFloatColor c = ofColor::fromHsb(150, 255, 120);
        colors1.push_back(c);
        points1.push_back(polyPoints1[i]);
    }
    
    for(int i = 0;  i < polyPoints2.getVertices().size(); i++){
        double weight = ofMap(polyPoints2[i].z, -1, 1, 0.01, 2.5);
        weights2.push_back(weight);
        ofFloatColor c = ofColor::fromHsb(150, 255, 120);
        colors2.push_back(c);
        points2.push_back(polyPoints2[i]);
    }
    
    for(int i = 0;  i < polyPoints3.getVertices().size(); i++){
        double weight = ofMap(polyPoints3[i].z, -1, 1, 0.01, 2.5);
        weights3.push_back(weight);
        ofFloatColor c = ofColor::fromHsb(150, 255, 240);

        colors3.push_back(c);
        points3.push_back(polyPoints3[i]);
    }
        fatLine.add(points, colors, weights);
        fatLine1.add(points1, colors1, weights1);
        fatLine2.add(points2, colors2, weights2);
        fatLine3.add(points3, colors3, weights3);
    
    
    
    for(int i = 0;  i < polyPoints4.getVertices().size(); i++){
        double weight = ofMap(polyPoints4[i].z, -1, 1, 0.01, 2.5);
        weights4.push_back(weight);
        ofFloatColor c = ofColor::fromHsb(75, 255, 240);
        colors4.push_back(c);
        points4.push_back(polyPoints4[i]);
    }
    
    for(int i = 0;  i < polyPoints5.getVertices().size(); i++){
        double weight = ofMap(polyPoints5[i].z, -1, 1, 0.01, 2.5);
        weights5.push_back(weight);
        ofFloatColor c = ofColor::fromHsb(75, 255, 120);
        colors5.push_back(c);
        points5.push_back(polyPoints5[i]);
    }
    
    for(int i = 0;  i < polyPoints6.getVertices().size(); i++){
        double weight = ofMap(polyPoints6[i].z, -1, 1, 0.01, 2.5);
        weights6.push_back(weight);
        ofFloatColor c = ofColor::fromHsb(75, 255, 240);
        colors6.push_back(c);
        points6.push_back(polyPoints6[i]);
    }
    
    for(int i = 0;  i < polyPoints7.getVertices().size(); i++){
        double weight = ofMap(polyPoints7[i].z, -1, 1, 0.01, 2.5);
        weights7.push_back(weight);
        ofFloatColor c = ofColor::fromHsb(75, 255, 120);
        colors7.push_back(c);
        points7.push_back(polyPoints7[i]);
    }
        fatLine4.add(points4, colors4, weights4);
        fatLine5.add(points5, colors5, weights5);
        fatLine6.add(points6, colors6, weights6);
        fatLine7.add(points7, colors7, weights7);
    
    fatLine.printDebug();


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);

    float time = ofGetElapsedTimef();



        for(int i = 0; i < numCurves; i++){
            ofPushMatrix();
            ofTranslate(lines[i].getVertices()[0]);
            ofEnableDepthTest();
            ofEnableBlendMode(OF_BLENDMODE_ADD);
            float phaseShift = sin(i*0.001);
            float angle = time + ofMap(sin(time + (i+1) * phaseShift) * sin(time*(i+1)*0.01), -1, 1, 0, 2*PI);//DO NOT CHANGE
            ofRotateRad(angle);
            if(i%2== 0){
                fatLine.draw();
                fatLine2.draw();
                fatLine1.draw();
                fatLine3.draw();
            }else{
                fatLine4.draw();
                fatLine5.draw();
                fatLine6.draw();
                fatLine7.draw();
            }

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
