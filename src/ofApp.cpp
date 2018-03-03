#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    bufferSize = 512;
    sampleRate = 44100;
    frequency = 200;
    trigger = 0;
    
    
    soundStream.setup(this, 2, 0, sampleRate, bufferSize, 2);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    envelope.setAttack(10);
    envelope.setDecay(500);
    envelope.setSustain(1);
    envelope.setRelease(1000);

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 32){
        trigger = 1;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if(key == 32){
        trigger = 0;
    }

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
void ofApp::audioOut(float * output, int bufferSize, int nChannels){
    
    for (int i = 0; i < bufferSize; i++){
        
       double mySound = myOsc.sinewave(200);
       float oscOutput = envelope.adsr(mySound, trigger);
        
                output[i * nChannels] = oscOutput;
                output[i * nChannels + 1] = oscOutput;
    }
}
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
