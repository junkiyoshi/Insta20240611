#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto radius = 140;
	ofColor color;
	for (int y = -240; y <= 240; y += 240) {

		auto deg_param = 120;
		auto deg_start = ofMap(y, -280, 280, 0, 360);

		for (int deg = deg_start; deg <= deg_start + 90; deg += 15) {

			color.setHsb(ofMap(deg, deg_start, deg_start + 90, 0, 255), 200, 200);
			ofSetColor(color);

			vector<glm::vec2> vertices;
			auto tmp_deg = deg + ofGetFrameNum() * 3;

			for (int x = -220; x <= 220; x += 220) {

				auto vertex = glm::vec2(x, y) + this->make_point(radius, ofMap(tmp_deg % 360, 0, 360, 0, 100));
				vertices.push_back(vertex);
				tmp_deg += deg_param;
			}

			ofNoFill();
			ofSetLineWidth(1.5);
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape();

			ofFill();
			for (auto& vertex : vertices) {

				ofDrawCircle(vertex, 3);
			}

			ofNoFill();
			ofSetLineWidth(0.5);
			for (int x = -220; x <= 220; x += 220) {

				ofDrawRectangle(x, y, radius, radius);
			}
		}

		for (int deg = deg_start + 180; deg <= deg_start + 180 + 90; deg += 15) {

			color.setHsb(ofMap(deg, deg_start + 180, deg_start + 180+  90, 0, 255), 200, 200);
			ofSetColor(color);

			vector<glm::vec2> vertices;
			auto tmp_deg = deg + ofGetFrameNum() * 3;

			for (int x = -220; x <= 220; x += 220) {

				auto vertex = glm::vec2(x, y) + this->make_point(radius, ofMap(tmp_deg % 360, 0, 360, 0, 100));
				vertices.push_back(vertex);
				tmp_deg += deg_param;
			}

			ofNoFill();
			ofSetLineWidth(1.5);
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape();

			ofFill();
			for (auto& vertex : vertices) {

				ofDrawCircle(vertex, 3);
			}
		}
	}

	/*
	int start = 50;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}