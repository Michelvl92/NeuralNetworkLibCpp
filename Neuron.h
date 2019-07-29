/**
	This file contains all the methods needed in raw version of neural networks neuron.

	Training methods are not included.
	This file along with it's .cpp version is to be expanded by such methods.
*/

#pragma once
#include <cstdlib>
#include <iostream>
#include <vector>
#include <math.h>

class Neuron {
private:
	// Array of weights between previous layer's neurons and this one (fully connected network)
	float* weights;

	float bias;

	// Neurons calculated value.
	// Initialized to -1, between 0 and 1 after feed forward method call
	float neuronsValue;

	// Every neuron knows it's place in the network grid and previous layer's size.
	// These are the arguments needed to create new neuron
	int __layerNum; // In what layer
	int __neuronNum; // Place in layer
	int __neuronsInPreviousLayer;
public:
	Neuron(int layerNum, int neuronNum, int neuronsInPreviousLayer);
	~Neuron();

	// Sigmoid by default.
	// Return float between 0 and 1
	float activationFunction(float x);

	// Single neuron's calculations, used by NeuralNetwork class
	float feedForward(float* inputs);

	// Manual neuron's output setting, for first layer "feed forward"
	void setOutput(float value);

	float getNeuronValue();

	// Used by constructor to initialize weights with random values between 0 and 1
	void randomizeWeightsArray();
};