#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(std::vector<int> layersDimensions) {
	NeuralNetwork::__numOfLayers = layersDimensions.size();

	for (int layerNum = 0; layerNum < NeuralNetwork::__numOfLayers; layerNum++) {
		std::vector<Neuron*> tmpLayer;

		int neuronsInPreviousLayer = 0;
		if (layerNum != 0) neuronsInPreviousLayer = layersDimensions[layerNum - 1];

		std::cout << "neurons in previous layer: " << neuronsInPreviousLayer << std::endl;

		for (int neuronNum = 0; neuronNum < layersDimensions[layerNum]; neuronNum++) {

			tmpLayer.push_back(new Neuron(layerNum, neuronNum, neuronsInPreviousLayer));
		}

		__layers.push_back(tmpLayer);
	}
}

NeuralNetwork::~NeuralNetwork() {
	for (int layerNum = 0; layerNum < __numOfLayers; layerNum++) {

		for (unsigned int neuronNum = 0; neuronNum < __layers[layerNum].size(); neuronNum++) {
			delete __layers[layerNum][neuronNum];
		}
	}
}

float* NeuralNetwork::feedForward(float* inputs) {
	int outputs = __layers.back().size();
	float* outputArr = new float[outputs];

	for (int layerNum = 0; layerNum < __numOfLayers; layerNum++) {

		// First layer skips feedForward and just sets inputs as outputs
		if (layerNum == 0) {
			for (unsigned int i = 0; i < __layers[layerNum].size(); i++) {
				__layers[layerNum][i]->setOutput(inputs[i]);
			}
		}
		else {
			// Feeding forward rest of the layers, one by one

			std::cout << std::endl;
			// Creating array of previous layer's outputs
			int prevLayerSize = __layers[layerNum - 1].size();
			float* inPrevLayer = new float[prevLayerSize];
			for (int i = 0; i < prevLayerSize; i++) {
				inPrevLayer[i] = __layers[layerNum - 1][i]->getNeuronValue();
				std::cout << "layer " << layerNum-1 << ": " << inPrevLayer[i] << std::endl;
			}
			std::cout << std::endl;

			for (unsigned int i = 0; i < __layers[layerNum].size(); i++) {
				__layers[layerNum][i]->feedForward(inPrevLayer);
			}

			delete[] inPrevLayer;
		}
	}

	for (unsigned int i = 0; i < outputs; i++) {
		outputArr[i] = __layers.back()[i]->getNeuronValue();
	}

	return outputArr;
}
