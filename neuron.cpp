#include "neuron.hpp"

// Returns a random float value between 0.0f and 1.0f
float frand() {
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

namespace NN {
	Neuron::Neuron() {
		this->_bias = frand() * 0.2f - 0.1f;
		std::cout << this->_bias;
	}
	
	
	void Neuron::Project(Neuron &n) {
		n.Connections.inputs.push_back({this, 0});
	}
		
	float Neuron::Activate(float n) {
		this->_state = n;
		return n;
	}

	float Neuron::Activate() {
		float sum = 0.0f;
		
		for (auto& v : this->Connections.inputs) {
			sum += v.conn->GetState();
		}

		switch(this->_squash) {
		case Squash::TANH: 
			sum = sum / (1 + abs(sum));		
			break;
		}

		this->_state = sum;
		return sum;
	}

	void Neuron::Gate() {}
	void Neuron::Propagate(float rate, float target) {
		float error = 0.0f;
		for (auto& v : this->Connections.inputs) {
			//error += v->Error.responsibility;
			// error += v.weight /* *magnitudee? */;
		}
	}
}