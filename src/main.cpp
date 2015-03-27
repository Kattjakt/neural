#include <iostream>
#include <time.h>
#include "network.hpp"

int main(int argc, char *argv[]) {
	NN::Layer input(2);
	NN::Layer hidden(6);
	NN::Layer output(1);

	input.Project(hidden);
	hidden.Project(output);
	
	NN::Network Network(
		input,
		hidden,
		output
	);

	for (int i = 0; i < 1000; i++) {
		Network.Activate(1.0f);
		Network.Activate();
		Network.Propagate(1.0f);

		Network.Activate(0.0f);
		Network.Activate();
		Network.Propagate(0.0f);
	}
	
	Network.Activate(0.0f);
	Network.Activate(true);

	Network.Activate(1.0f);
	Network.Activate(true);

	getchar();

	return EXIT_SUCCESS;
}




