#ifndef LAYER_H
#define LAYER_H

#include "Neuron.h"

#include <iostream>
#include <random>
#include <cmath>

struct Layer{
    vector<Neuron*>neurons; //an array of neuron pointers
    vector<float> inputs;

public:
    //constructors
    Layer();
    Layer(int neuronCount);
    Layer(int neuronCount, int inputWeight);

    //does activation calculations
    float calculateActivation(vector<float>weights, vector<float> inputs);

    //returns neurons
    vector<Neuron*> returnNeurons(){
        return neurons;
    }

    //sets neurons
    void setNeuron(Neuron* a);


	
};
#endif
