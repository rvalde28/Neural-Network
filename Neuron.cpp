#include "Neuron.h"

Neuron::Neuron(){
    input = 0.0; 
    output = 0.0; 
    delta = 0.0;  
    bias = 0.0;
}

//each neuron will have n inputs, so we initialize n weights with a random number between -0.1 and 0.1 and that is not equal to 0
Neuron::Neuron(int size){
    for(int i = 0; i < size; i < i++){
        weights.push_back(initializeWeight());
    }
    input = 0.0; 
    output = 0.0; 
    delta = 0.0;  
    bias = initializeWeight();
}


//return a random variable between -0.1 and 0.1 and not equal to 0
double Neuron::initializeWeight(){
        double number;
        while(true){
            random_device rd;
            default_random_engine generator(rd()); // rd() provides a random seed
            uniform_real_distribution<double> distribution(-0.1,0.1);

            number = distribution(generator);

            //if the number is == 0 then it can break, if not then it keeps looping until it is not 0
            if(number != 0.00){
                break;
            }

        }

        return number;
}

void Neuron::printWeights(){
    for(int i = 0; i < weights.size();i++){
        cout << weights.at(i) << endl;
    }
}

void Neuron::setWeight(int index, float value){
    weights.at(index) = value;
}

float Neuron::getWeight(int index){
    return weights.at(index);
}

void Neuron::setOutput(float value){
    output = value;
}
float Neuron::getOutput(){
    return output;
}

void Neuron::setDelta(float value){
    delta = value;
}

float Neuron::getDelta(){
    return delta;
}

void Neuron::setInput(float value){
    input = value;
}

float Neuron::getInput(){
    return input;
}
vector<float> Neuron::returnWeights(){
    return weights;
}
void Neuron::setBias(float value){
    bias = value;
}

float Neuron::getBias(){
    return bias;
}
