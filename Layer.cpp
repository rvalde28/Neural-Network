#include "Layer.h"
Layer::Layer(){

}
//Initialize the neurons based on the size give and initialize the weights of those neurons
Layer::Layer(int neuronSize){
    for(int i = 0; i < neuronSize; i++){
        //cout << i <<endl;
        Neuron* temp = new Neuron();
        neurons.push_back(temp);
    }
}

//initilze neurons and the size of each neuron
Layer::Layer(int neuronSize, int numWeights){
    for(int i = 0; i < neuronSize; i++){
        Neuron* temp = new Neuron(numWeights);
        neurons.push_back(temp);
    }
}


//calculates the sum of the weights * inputs
float Layer::calculateActivation(vector<float>weights, vector<float>inputs){
    float sum = 0;
    
    for(int i = 0; i < weights.size(); i++){
        //cout << "W: " << weights.at(i) << endl;
        //cout << "I: " << inputs.at(i) << endl;
        sum += weights.at(i)*inputs.at(i);
    }    
//    cout << "Sum: " << sum << endl;
    return sum;
}

void Layer::setNeuron(Neuron* n){
	neurons.push_back(n);
}
