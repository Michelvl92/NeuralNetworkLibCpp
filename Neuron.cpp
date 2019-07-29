#include "Neuron.h"

Neuron::Neuron(int layerNum, int neuronNum, int neuronsInPreviousLayer) {
	__layerNum = layerNum;
	__neuronNum = neuronNum;
	__neuronsInPreviousLayer = neuronsInPreviousLayer;

	neuronsValue = -1;

	// If it's not the first layer (input) initialize weights from previous layer
	if (layerNum != 0) {
		weights = new float[__neuronsInPreviousLayer];
		randomizeWeightsArray();

	} // First layer's weights are unused
	else { 
		weights = NULL;
	}

	bias = (double)rand() / (RAND_MAX); // 0 - 1
	std::cout << "b: " << bias << std::endl;
}

Neuron::~Neuron() {
	if (__layerNum != 0) delete[] weights;
}

void Neuron::randomizeWeightsArray() {
	for (int i = 0; i < __neuronsInPreviousLayer; i++) {
		weights[i] = (double)rand() / (RAND_MAX); // 0 - 1
		std::cout << "w:" << weights[i] << std::endl;
	}
}

float Neuron::feedForward(float* inputs) {

	float sum = 0;
	for (int i = 0; i < __neuronsInPreviousLayer; i++) {
		sum += inputs[i] * weights[i] + bias;
	}

	float output = activationFunction(sum);
	neuronsValue = output;
	return output;
}

float Neuron::activationFunction(float x) {
	return 1 / (1 + exp(-x));
}

void Neuron::setOutput(float value) {
	neuronsValue = value;
}
float Neuron::getNeuronValue() {
	return neuronsValue;
}