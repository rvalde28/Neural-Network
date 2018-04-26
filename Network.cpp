#include "Network.h"
#include <iomanip>

Network::Network(){
}

//initializes network 
Network::Network(int input, int hidden, int output){

    Layer* temp2= new Layer(hidden,input);

    vector<Neuron*> neurons = temp2->returnNeurons();



    hiddenLayer = temp2;

    Layer* temp3 = new Layer(output,hidden);


    neurons = temp3->returnNeurons();


    outputLayer = temp3;


}
//once the activation value is gotten call tangent for the hidden
//sigmoid for the output layer
float Network::logisticSigmoid(float value){
    return (1/(1+exp(-value)));
}

//tanh function
float Network::tangent(float value){
    return tanh(value);
}

//fuction for the derivative of the logistic function
float Network::derivativeLogistic(float value){
    return value * (1 - value);
}

//derivative for the tanh function which is sech^2
float Network::secant(float value){
    return (1/cosh(value))*(1/cosh(value));
}

float Network::errorLogistic(float expected, float output){
    return (expected - output)*derivativeLogistic(output);
}

float Network::errorSecant(vector<float> weights, vector<float> error, float input){
    float activation = hiddenLayer->calculateActivation(weights,error);
    return secant(input)*activation;
}

//forward propagation algorthm. Find the activation values and applies a g(x) formula, It then sets the putputs for the neurons which become the inputs for the neurons in the other layers
vector<float> Network::forward_propagate(Network* network, vector<float> row){
    //get inputs
    vector<float> inputs = row;
    vector<Layer*> layers = network->getLayers();

    for(int i = 0; i < layers.size(); i++){
        vector<float> new_inputs;
        vector<Neuron*> neurons = layers.at(i)->returnNeurons();


        for(int j = 0; j < neurons.size(); j++){
            vector<float> weights = neurons.at(j)->returnWeights();
            float activation = neurons.at(j)->getBias() + layers.at(i)->calculateActivation(weights, inputs);

            neurons.at(j)->setInput(activation);
            //set the output value of the neuron based on the sigmoid function
            float output;
            if(i == 0){  
                output = tangent(activation);
                neurons.at(j)->setOutput(output);

            }
            else if(i == 1){        
                output = logisticSigmoid(activation);
                neurons.at(j)->setOutput(output);
            }

            //set the output for the neuron
            new_inputs.push_back(output);

        }
        inputs = new_inputs;
    }

    return inputs;
}

//back propagtion function find the delta values for the neurons in the layer which will be used to update the weights
void Network::backward_propagate(Network* network, vector<float> expectedOutput){
    vector<Layer*> layers= network->getLayers();

    //Output layer to hidden layer
    //get the neurons from the 
    vector<Neuron*> neuronsOutput = layers.at(layers.size()-1)->returnNeurons();

    //calculates errors for the ouput layer
    vector<float> error;   
    for(int i = 0; i < expectedOutput.size(); i++){
        float er = (expectedOutput.at(i) - neuronsOutput.at(i)->getOutput());

        error.push_back(er);
    }

    float err;
    //multiply the erros by the derivative of the logistic sigmoid funcion to find the delta for the neuron
    for(int i = 0; i < neuronsOutput.size(); i++){
        float delta = error.at(i) * derivativeLogistic(neuronsOutput.at(i)->getOutput());
        neuronsOutput.at(i)->setDelta(delta);
    }
    error.clear();


    //hidden layer to first layer
    Layer* layerh = layers.at(0);
    vector<Neuron*> hiddenNeurons = layerh->returnNeurons();

   //finds the error for the hidden layer
    for(int i = 0; i < hiddenNeurons.size(); i++){
        float tempError = 0.0;
        for(int j = 0; j < neuronsOutput.size(); j++){
            tempError += neuronsOutput.at(j)->returnWeights().at(i) * neuronsOutput.at(j)->getDelta();
        }   
        error.push_back(tempError);
    }

    //find the deltas for the neurons of the hidden layer
    for(int i = 0; i < hiddenNeurons.size(); i++){
        float delta = error.at(i) * secant(hiddenNeurons.at(i)->getOutput());
        hiddenNeurons.at(i)->setDelta(delta);

    }

}

//updates the weights of each neuron in the network
void Network::updateWeights(Network* network, vector<float>input, float learningRate){
    vector<Layer*> layers = network->getLayers();
    vector<float> new_inputs = input;

    for(int i = 0; i < layers.size(); i++){
        vector<Neuron*> neurons = layers.at(i)->returnNeurons();

        //if we are at a layer other than the input layer
        if(i > 0){
            //get neurons of the previous layer
            vector<Neuron*> neurons2 = layers.at(i-1)->returnNeurons();
            vector<float> outputs;

            //get the outputs of all of the neurons of the previous layers
            //these becomes the inputs for that layer
            for(int j = 0; j < neurons2.size(); j++){
                outputs.push_back(neurons2.at(j)->getOutput());
            }
            new_inputs = outputs;
        }


        for(int j = 0; j < neurons.size(); j++){
            for(int k = 0; k < new_inputs.size(); k++){
                float newWeight = neurons.at(j)->getWeight(k)+(learningRate*neurons.at(j)->getDelta()*new_inputs.at(k));

                neurons.at(j)->setWeight(k, newWeight);
            
                }         
        }
        
    }
}
//This is based on the algorithm given to us 
//trains the network based on the algorithms provide, does forward propagation, then back propagation
// then updates the weights. The given inputs and expected outputs are also used for calculations
//it returns the error of the neural net
float Network::trainNetwork(Network* network, vector<float> dataInputs, float learningRate, int epoch, vector<float> dataOutputs){
    float error = 0.0;    
    for(int i = 0; i < epoch; i++){
        float errorSum = 0.0;
        //forward propagation
        vector<float> outputs = forward_propagate(network, dataInputs);
        vector<float> expectedOutputs = dataOutputs;

        //this finds the error of the neural net which will be used to find the accuracy which will be (1-errorSum)*100
        for(int j = 0; j < expectedOutputs.size(); j++){
            errorSum += pow((expectedOutputs.at(j) - outputs.at(j)),2);
        }

        //back propagation
        backward_propagate(network, expectedOutputs);
        //update weights
        updateWeights(network, dataInputs, learningRate);
        error = errorSum;
        
    }
    return error;
}


//predicts the letter byt doing forward propagation. It gets the index of the highest output when doing forward propagation which is the letter the net guessed
int Network::predict(Network* network, vector<float> input){
    vector<float> outputs = network->forward_propagate(network, input);
    float max = -1;
    int index;
    for(int i = 0; i < outputs.size(); i++){
        if(outputs.at(i) > max){
            max = outputs.at(i);    
            index = i;
        }
    }
    return index;
}

void Network::setHidden(Layer* layer){
        hiddenLayer = layer;
}

void Network::setOut(Layer* layer){
        outputLayer = layer;
}
