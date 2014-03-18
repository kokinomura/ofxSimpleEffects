#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    ofSetCircleResolution(32);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    p = ofVec2f(0, 0);
    points = new ofVec2f[NCIRCLES];
    colors = new ofColor[NCIRCLES];
    
    ofVec2f nextPoint;
    for (int i = 0; i < NCIRCLES; i++) {
        double r = ofRandom(15) * ofRandom(15);
        double theta = ofRandom(2 * PI);
        nextPoint.x = r * cos(theta);
        nextPoint.y = r * sin(theta);
        
        double d = p.distance(nextPoint);
        int h = ofMap(d, 0, 250, 100, 200);
        ofColor c = ofColor::fromHsb(h, 150, 180, 30);
        colors[i] = c;
        
        points[i] = nextPoint;
        p = nextPoint;
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i=0; i<NCIRCLES; i++) {
        ofVec2f p = points[i];
        p.rotateRad(ofRandom(-0.2, 0.2));
        p.scale(ofRandom(-p.length()/10, p.length()/10) + p.length()).limit(200);
        points[i] = p;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    float glowAmount = ofMap(mouseX, 0, ofGetWidth(), 1, 5);
    float blurSize = ofMap(mouseY, 0, ofGetHeight(), 0, 50);
    
    glow.begin(glowAmount, blurSize);

    ofBackground(0);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    for (int i=0; i<NCIRCLES; i++) {
        ofSetColor(colors[i]);
        ofCircle(points[i], 4);
    }
    glow.end();
    
    glow.draw();
    
    ofSetColor(255);
    ofDrawBitmapString("FPS: " + ofToString(ofGetFrameRate()), 30, 30);
    ofDrawBitmapString("Blur Size: " + ofToString(blurSize), 30, 50);
    ofDrawBitmapString("Glow Amount: " + ofToString(glowAmount), 30, 70);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    //ofSaveFrame();
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}