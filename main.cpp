#include <iostream>

#include "neuron.hpp"

int main(int argc, char *argv[]) {

	NN::Neuron A, B;
	A.Project(B);	

	A.SetLabel("A");
	B.SetLabel("B");

	std::cout << A.Activate(0.5) << std::endl;
	std::cout << B.Activate() << std::endl;

	for (int i = 0; i < 20000; i++) {
		A.Activate(1);
		B.Activate();
		B.Propagate(0.3f, 0.0f);
	}

	A.Activate(1);
	std::cout << "B: " << B.Activate() << std::endl;

	return EXIT_SUCCESS;
}




