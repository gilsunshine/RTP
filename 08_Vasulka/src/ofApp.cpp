#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    grabber.listDevices();
    grabber.setDeviceID(0);
    
    grabber.setup(640, 480);
    spacing = 15;
    xSpacing = 5;
    ofEnableSmoothing();
    triMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
}

//--------------------------------------------------------------
void ofApp::update(){
//
    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    cam.enableOrtho();
    colors.clear();
    lines.clear();
    triMesh.clear();
    triangulation.reset();
    ofSetFrameRate(30);
    float time = ofGetElapsedTimef();
    for (int y = 0; y < grabber.getHeight(); y+=spacing){
//        ofPolyline line;
        for (int x = 0; x < grabber.getWidth(); x+=xSpacing){
            float brightness = grabber.getPixels().getColor(x,y).getBrightness();
            triangulation.addPoint(ofPoint(x - grabber.getWidth()/2, (grabber.getHeight()-y-1) - grabber.getHeight()/2, ofMap(brightness, 0, 255, -100, 100)));
        }
    }

    triangulation.triangulate();
    triMesh = triangulation.triangleMesh;
    

        ofVec3f mouse(mouseX - ofGetWidth()/2, ofGetHeight()/2 -mouseY, ofGetHeight()/2 -mouseY);
        for (int i=0; i<triMesh.getNumVertices(); ++i) {
            ofVec3f vertex = triMesh.getVertex(i);
            float distanceToMouse = mouse.distance(vertex);
            float displacement = ofMap(distanceToMouse, 0, 400, ofMap(mouseY, 0, ofGetHeight(), 0, 800), 0, true);
            ofVec3f direction = vertex - mouse;
            direction.normalize();
            ofVec3f displacedVertex = vertex + displacement*direction;
            triMesh.setVertex(i, displacedVertex);
        }

    for(int y = 0; y < grabber.getHeight()/spacing; y++){
        ofPolyline line;
        for(int x = 0; x < grabber.getWidth()/xSpacing; x++){
            line.addVertex(triMesh.getVertex(x + y * grabber.getWidth()/xSpacing));
        }
        line = line.getSmoothed(5);
        lines.push_back(line);

    }
    
        for (int i = 0 ; i < lines.size(); i ++){
            ofSetColor(255,150);
            lines[i].draw();
        }
    

    ofSetColor(255, 100);

    triMesh.drawVertices();
    ofSetColor(255, 50);
    triMesh.drawWireframe();

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
