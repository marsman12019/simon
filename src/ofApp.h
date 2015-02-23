#pragma once

#include "ofMain.h"
#include "ofxPd.h"
#include "NamedColors.h"

using namespace pd;

class ofApp : public ofBaseApp, public PdReceiver {

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
	
		void play();
		void listen();
	
		// PD -----
		ofxPd pd;
		void audioOut(float* output, int bufferSize, int numChannels);
		void audioIn(float* input, int bufferSize, int numChannels);
		void receiveFloat(const std::string& dest, float value);
		void receiveBang(const std::string& dest);
	
		// OF -----
		ofTrueTypeFont font;
	
		vector<string> song;
		void makeSong(int length);
		map<string, ofColor> colorMap;
		map<string, int> midiTable;
		string scale[5];
	
		int songLength;
		int fromFiddle;
		bool fromFiddleBang;
		int octave;
	
		int currentNote;
		int counter;

		int noteLength;
		int breathLength;
		int playbackLength;
};
