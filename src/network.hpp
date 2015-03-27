#pragma once

#include "layer.hpp"

namespace NN {
	class Network {
	private:
		std::vector<NN::Layer*> layers;
		float trainingrate = 0.3f;

	public:
		Network::Network(
			NN::Layer &input, 
			NN::Layer &hidden, 
			NN::Layer &output
		);

		void Activate(bool print = false);
		void Activate(float n);
		void Propagate(float target);
	};
}