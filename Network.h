#ifndef NETWORK_H
#define NETWORK_H

#include "Layer.h" 
#include <cmath>

using namespace std;

class Network{

    Layer* hiddenLayer;
    Layer* outputLayer;



public:
    Network();

    Network(int numInputs,int numHidden, int numOutput);


    //updates the input values for the next layer
    void update();
    float logisticSigmoid(float value);
    float tangent(float value);
    float derivativeLogistic(float value);
    float secant(float value);
    float errorLogistic(float expected, float output);
    float errorSecant(vector<float> weights, vector<float> error,float input);
    
    vector<float> forward_propagate(Network* network, vector<float> row);
    void backward_propagate(Network* network, vector<float> expectedOutput);
    vector<Layer*> getLayers(){
        vector<Layer*> layers;
        layers.push_back(hiddenLayer);
        layers.push_back(outputLayer);

        return layers;
    }
    void updateWeights(Network* network, vector<float>input, float learningRate);
    float trainNetwork(Network* network, vector<float> data, float learningRate, int epoch, vector<float> outputs);
    int predict(Network* network,vector<float> input);
    void setHidden(Layer* l);
    void setOut(Layer* l);

};
#endif
