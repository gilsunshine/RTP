#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofEnableDepthTest();
    cam.setDistance(4);
    cam.setNearClip(0.0001);
    numIso = 0;
    res = 30;
    ofBackground(255);

}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    ofPolyline outsideIso;
    ofPolyline insideIso;
    shingles.clear();
    rings.clear();
    outsideIsos.clear();
    insideIsos.clear();
    float morph = ofMap(sin(time), -1, 1, 0.0, 1.0);

    
    int n = numIso;
    int m = res;
    float a = 1.2 ;
    float b = 1;
//    float turns = ofMap(mouseX, 0, ofGetWidth(), 0.0, 2.0);
    float turns = 1;
    
    for (int i = 0; i <= numIso; i++) {
//        float mis = ofMap(sin(time), -1,1, 0,5);
        float mis = 0;
        for (int j = mis; j <= res-mis; j++) {
//            float u1 = i * 2 * PI/numIso;
            
            float v1 = j * PI/res - 10;
            float x1 = a * sin(v1) * cos(turns*v1);
            float y1 = a * sin(v1) * sin(turns*v1);
            float z1 = a * cos(v1);
            
            float x2 = b * sin(v1) * cos(turns*v1);
            float y2 = b * sin(v1) * sin(turns*v1);
            float z2 = b * cos(v1);
            
            float u2 = i * 2*PI;
            float v2 = (j-10) * 2*PI/res;
            
            float c = .75;
            float d = 0.375;
            float x3 = a * (c + (d * cos(v2))) * cos(u2);
            float y3 = a * (c + (d * cos(v2))) * sin(u2);
            float z3 = a * d * sin(v2);
            
            float x4 = b * (c + (d * cos(v2))) * cos(u2);
            float y4 = b * (c + (d * cos(v2))) * sin(u2);
            float z4 = b * d * sin(v2);
            
            float xa = x1 * morph + x3 * (1.0 - morph);
            float ya = y1 * morph + y3 * (1.0 - morph);
            float za = z1 * morph + z3 * (1.0 - morph);
            
            float xb = x2 * morph + x4 * (1.0 - morph);
            float yb = y2 * morph + y4 * (1.0 - morph);
            float zb = z2 * morph + z4 * (1.0 - morph);
            
            outsideIso.addVertex(ofVec3f(xa,ya,za));
            insideIso.addVertex(ofVec3f(xb,yb,zb));
            
        }
        insideIso.removeVertex(insideIso.size()-1);
        outsideIsos.push_back(outsideIso);
        insideIsos.push_back(insideIso);
        
    }
    float numSpi = 2 * PI / 18;
    for (float i = numSpi; i < 2 * PI; i+=numSpi){

        ofPolyline newOutsideIso;
        ofPolyline newInsideIso;
        
        for(int j = 0; j < outsideIso.getVertices().size(); j++){
            ofVec3f newPt;
            newPt.set(outsideIso[j]);
            newPt = newPt.getRotatedRad(i, ofVec3f(0,0,1));
            newOutsideIso.addVertex(newPt);
        }

        for(int j = 0; j < insideIso.getVertices().size(); j++){
            ofVec3f newPt;
            newPt.set(insideIso[j]);
            newPt = newPt.getRotatedRad(i, ofVec3f(0,0,1));
            newInsideIso.addVertex(newPt);
        }
        outsideIsos.push_back(newOutsideIso);
        insideIsos.push_back(newInsideIso);

    }
    for (int i = 0; i <= outsideIsos.size() + 1; i++){
        ofPolyline ring;
        for(int j = 0; j < outsideIsos[i].size(); j++){
            ring.addVertex(outsideIsos[i][j]);
        }
        rings.push_back(ring);
    }
    
    for (int i = 0; i <= insideIsos.size(); i++){
        ofPolyline ring;
        for(int j = 0; j < insideIsos[i].size(); j++){
            ring.addVertex(insideIsos[i][j]);
        }
        rings.push_back(ring);
    }
        
    for (int i = 0; i < outsideIsos.size() - 1; i++){
        for (int j = 0; j < outsideIsos[i].getVertices().size()-1; j++){
            ofMesh shingle;
            shingle.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
            
            ofPoint firstPt;
            firstPt.set(outsideIsos[i][j+1]);
            shingle.addVertex(firstPt);
//            shingle.addColor(ofColor(0));
            shingle.addColor(ofColor(0));
            
            ofPoint secondPt;
            secondPt.set(outsideIsos[i][j]);
            shingle.addVertex(secondPt);
//            shingle.addColor(ofColor(0));
            shingle.addColor(ofColor(0));
            
            ofPoint thirdPt;
            thirdPt.set(outsideIsos[i+1][j+1]);
            shingle.addVertex(thirdPt);
//            shingle.addColor(ofColor(0));
            shingle.addColor(ofColor(0));

            ofPoint fourthPt;
            fourthPt.set(insideIsos[i+1][j]);
            shingle.addVertex(fourthPt);
//            shingle.addColor(ofColor(225,255,0));
            shingle.addColor(ofColor(225,255,0));
            shingles.push_back(shingle);

        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    cout << rings.size() << endl;
    ofPushMatrix();
    ofRotateXRad(PI/5);
    ofRotateYRad(PI/5);
    ofRotateZRad(ofGetElapsedTimef()/2);
    ofSetColor(225,225,0);
    float r = pow(ofMap(sin(ofGetElapsedTimef()),-1,1, 0, 0.99), 4);

    ofDrawSphere(0,0,0, r);
    
    ofSetColor(0,0,255);
    ofSetLineWidth(1);
    for (int i = 0; i < outsideIsos.size(); i++){
        outsideIsos[i].draw();
    }

    for (int i = 0; i < insideIsos.size(); i++){
        insideIsos[i].draw();
    }
    for (int i = 0; i < rings.size(); i++){
        rings[i].draw();
    }
    for (int i = 0; i < shingles.size(); i++){
         shingles[i].draw();
//        shingles[i].drawWireframe();
     }
    
    ofPopMatrix();
    cam.end();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
