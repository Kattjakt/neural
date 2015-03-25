#include "network.hpp"

#include <vector>

namespace NN {
	Network::Network(NN::Layer &input, NN::Layer &hidden, NN::Layer &output) {
		this->layers.push_back(&input);
		this->layers.push_back(&hidden); // support multiple?
		this->layers.push_back(&output);
	}

	void Network::Activate(float n) {
		for (auto& v : this->layers) {
			v->Activate(n);
		}
	}

	void Network::Propagate(float target) {
		Layer *input = this->layers.front();
		Layer *output = this->layers.back();

		// ...
	}
}