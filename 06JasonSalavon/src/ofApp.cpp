#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    float wid = 600;
//    float heigh = 400;
    float wid = 600;
     float heigh = 600;
    ofDirectory dir;
    dir.listDir("stationary_bike");
    for (int i = 0; i < dir.size(); i++){
        ofImage img;
        images.push_back(img);
        images.back().load(dir.getPath(i));
        cout << "loaded " << i << " of " << dir.size() << endl;
        
        ofRectangle targetDim(0,0,wid,heigh);
        ofRectangle imageDim(0,0,images.back().getWidth(),
                             images.back().getHeight());
        
        targetDim.scaleTo(imageDim);
        
        images.back().crop(targetDim.x, targetDim.y, targetDim.width, targetDim.height);
        images.back().resize(wid,heigh);
        
    }
    
    average.allocate(wid,heigh, OF_IMAGE_COLOR);
    
    for (int i = 0; i < wid; i++){
        for (int j = 0; j < heigh; j++){
            
            // average:
            // (1) add all values up
            float sumRed = 0;
            float sumBlue = 0;
            float sumGreen = 0;
            for (int k = 0; k < images.size(); k++){
                ofColor color = images[k].getColor(i,j);
//                if (color.getBrightness()>10){
                sumRed += color.r;
                sumGreen += color.g;
                sumBlue += color.b;
//                }
//                else{
//                    sumRed += color.r*10;
//                    sumGreen += color.g*10;
//                    sumBlue += color.b*10;
//                }
            }
            // (2) divide
            sumRed /= (float)images.size();
            sumBlue /= (float)images.size();
            sumGreen /= (float)images.size();
            average.setColor(i,j, ofColor(sumRed, sumGreen, sumBlue));
            
            
        }
    }
        for (int i = 0; i < wid; i++){
            for (int j = 0; j < heigh; j++){
                float sat = average.getColor(i,j).getSaturation();
                float bright = average.getColor(i,j).getBrightness();
                ofColor newCol = average.getColor(i,j);
                newCol.setSaturation(sat*1.2);
//                if(newCol.getBrightness()<254){
                    newCol.setBrightness(bright);
//                }
                average.setColor(i,j, newCol);
            }
        }
    
    average.update();
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
//    average.draw(100,200);
    average.draw(100,100);

    
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
