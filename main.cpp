#include "NeuralNetwork.h"

int main() {

	srand(time(NULL));
	NeuralNetwork *nn = new NeuralNetwork(std::vector<int>{3, 10, 3});

	float* inputs = new float[3];
	inputs[0] = 10;
	inputs[1] = -13;
	inputs[2] = 1.65;

	float* out = nn->feedForward(inputs);

	std::cout << std::endl;
	for(int i = 0; i < 3; i++) {
		std::cout << "out " << i+1 << ": " << out[i] << std::endl;
	}

	return 0;
}
