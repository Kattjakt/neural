#include <iostream>
#include <time.h>
#include "network.hpp"

int main(int argc, char *argv[]) {
	NN::Layer input(2);
	NN::Layer hidden(3);
	NN::Layer output(1);

	input.Project(hidden);
	hidden.Project(output);
	
	NN::Network Network(
		input,
		hidden,
		output
	);

	for (int i = 0; i < 20000; i++) {
		Network.Activate(1.0f);
		Network.Propagate(1.0f);

		Network.Activate(0.0f);
		Network.Propagate(0.0f);
	}
	

	getchar();

	return EXIT_SUCCESS;
}




