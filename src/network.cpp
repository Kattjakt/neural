#include "network.hpp"

#include <vector>

namespace NN {
	Network::Network(NN::Layer &input, NN::Layer &hidden, NN::Layer &output) {
		this->layers.push_back(&input);
		this->layers.push_back(&hidden); // support multiple?
		this->layers.push_back(&output);
	}

	void Network::Activate(bool print) {
		for (int i = 0; i < this->layers.size(); i++) {
			if (i == this->layers.size() - 1) {
				std::vector<float> output = this->layers.at(i)->Activate();
				for (int j = 0; j < output.size() && print; j++) {
					printf("out %i: %f\n", j, output.at(j));	
				}
			}	
		}
	}

	void Network::Activate(float n) {
		for (int i = 0; i < this->layers.size(); i++) {
			this->layers.at(i)->Activate(n);
		}
	}

	void Network::Propagate(float target) {
		Layer *input = this->layers.front();
		Layer *output = this->layers.back();

		for (auto& layer : this->layers) {
			for (auto& neuron : layer->neurons) {
				float error = neuron->state - target;
				for (auto& inputs : neuron->Connections.inputs) {
					inputs.weight -= error * 0.3; // this is all so wrong
				}
			}			
		}
	}
}