#pragma once

#include <vector>
#include "neuron.hpp"

namespace NN {
	class Layer {
	private:
		std::vector<Neuron*> neurons; 

	public:
		Layer::Layer(unsigned size);
		void Project(Layer &layer);
		void Activate(float n);
		void Activate();
	};
}