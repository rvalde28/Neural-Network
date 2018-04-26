#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <random>
#include <cmath>
#include <vector>

using namespace std;

class Neuron{
	vector<float> weights;
	float input; //weighted sum of input
	float output; //output value
	float delta;  //delta value for error
    float bias;
public:
    Neuron();//Constructor
    Neuron(int inputcount);//Allocates memory and initializates values
    double initializeWeight();
    vector<float> returnWeights();
    void printWeights();
    void setWeight(int index, float value);
    float getWeight(int index);
    void setOutput(float value);
    float getOutput();
    void setDelta(float value);
    float getDelta();
    void setInput(float value);
    float getInput();
    float getBias();
    void setBias(float bvalue);
};
#endif
