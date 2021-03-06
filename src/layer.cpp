#include "layer.hpp"

namespace NN {
	Layer::Layer(unsigned size) {
		for (int i = 0; i < size; i++) {
			this->neurons.push_back(new Neuron());
		}
	}

	void Layer::Project(Layer &layer) {
		for (int i = 0; i < this->neurons.size(); i++) {
			for (int j = 0; j < layer.neurons.size(); j++) {
				this->neurons.at(i)->Project(*layer.neurons.at(j));
			}
		}
	}

	void Layer::Activate(float n) {
		for (auto& v : this->neurons) {
			v->Activate(n);
		}
	}

	std::vector<float> Layer::Activate() {
		std::vector<float> results;
		for (auto& v : this->neurons) {
			results.push_back(v->Activate());
		}
		return results;
	}
}