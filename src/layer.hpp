#pragma once

#include <vector>
#include "neuron.hpp"

namespace NN {
	class Layer {
	public:
		std::vector<Neuron*> neurons; 

	public:
		Layer::Layer(unsigned size);
		void Project(Layer &layer);
		void Activate(float n);
		std::vector<float> Activate();
	};
}