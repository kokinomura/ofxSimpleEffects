#pragma once

#include "ofMain.h"

#include "GlowEffect.h"

#define NCIRCLES 10000
#define WIDTH 800
#define HEIGHT 600

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    // figure
    ofVec2f p;
    ofVec2f *points;
    ofColor *colors;
    
    GlowEffect glow;
};
