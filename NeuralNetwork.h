/**
	This is a fully connected* neural network library raw form for future training

	NeuralNetwork.h contains vector of vectors called __layers and all the methods to operate on it.
	It's a two dimentional matrix (grid) of Neurons, dynamicly initialized by constructor's input vector.

	Included file Neuron.h contains all methods needed for network to work, but weights are initialized randomly.

	This library is to be expanded by training methods, such as evolution algorythms.
	This library is to be converted into Nvidia CUDA project, to be trained using GPU resources.

	Both .cpp files contain a lot of console stream writing for debugging purposes.

	*fully connected means all neurons from layer n-1 are connected to every each neuron in layer n.
*/

#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>

#include "Neuron.h"

class NeuralNetwork {
private:

	// Main grid of the network
	std::vector<std::vector<Neuron*>> __layers;

	int __numOfLayers;

public:

	// Constructor takes a vector of grid dimensions.
	// Vector size indicates number of layers.
	// For example: vector<int>{2, 5, 1} means: 2 inputs, 5 hidden neurons, 1 output neuron
	NeuralNetwork(std::vector<int> layersDimensions);

	~NeuralNetwork();

	// Feeding whole network by using Neurons feedForward method.
	// Returns array with outputs of the last layer
	float* feedForward(float* inputs);
};
