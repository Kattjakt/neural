#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>

namespace NN {
	enum Squash {
		ABS, SIG
	};
	
	class Neuron {
	private:
		std::string label = "";
		Squash squash = Squash::ABS;
		float state = 0.0f;
		float bias = 0.0f;

		typedef struct Connection_t {
			Neuron *conn;
			float weight;
			float gain;
		} Connection;

		struct Connections_t {
			std::vector<Connection> inputs; 
			std::vector<Connection> projected; 
			std::vector<Connection> gated; 
		} Connections;
		
		struct Error_t {
			float responsibility = 0.0f;
			float projected		 = 0.0f;
			float gated			 = 0.0f;
		} Error;

	public:
		Neuron::Neuron();		
		void SetLabel(std::string label) {this->label = label; }
		void Gate();
		void Project(Neuron &n);
		void Propagate(float rate, float target);
		float GetState() { return this->state; }
		float Activate(float n);
		float Activate();
	};
}