#include "neuron.hpp"

// Returns a random float value between 0.0f and 1.0f
float frand() {
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

namespace NN {
	Neuron::Neuron() {
		this->bias = frand() * 0.2f - 0.1f;
	}
	
	void Neuron::Project(Neuron &n) {
		n.Connections.inputs.push_back({this, frand()});
	}
		
	float Neuron::Activate(float n) {
		this->state = n;
		return n;
	}

	float Neuron::Activate() {
		float sum = this->bias;
		for (auto& v : this->Connections.inputs) {
			sum += v.conn->state * v.weight;
		}

		switch(this->squash) {
		case Squash::ABS: 
			sum = sum / (1 + abs(sum));		
			break;
		case Squash::SIG:
			sum = 1 / (1 + pow(2.71828, (sum * -1)));
			break;
		}

		this->state = sum;
		return sum;
	}
}