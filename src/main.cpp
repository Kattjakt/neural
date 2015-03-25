#include <iostream>
#include <time.h>
#include "layer.hpp"

int main(int argc, char *argv[]) {
	NN::Layer input(4);
	NN::Layer hidden(6);
	NN::Layer output(2);

	input.Project(hidden);
	hidden.Project(output);
	
	input.Activate(5.0f);
	output.Activate();

	getchar();

	return EXIT_SUCCESS;
}




