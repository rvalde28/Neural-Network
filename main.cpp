#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Network.h"

using namespace std;

//letters are stored in the struct as vectors with several methods
struct Letters{
    vector<int> A ={1,1,1,1,1,1,0,
                    0,0,0,1,0,0,1,
                    0,0,0,1,0,0,1,
                    0,0,0,1,0,0,1,
                    1,1,1,1,1,1,0};                  

    vector<int> B ={1,1,1,1,1,1,1,
                    1,0,0,1,0,0,1,
                    1,0,0,1,0,0,1,
                    1,0,0,1,0,0,1,
                    0,1,1,0,1,1,0};

    vector<int> C ={0,1,1,1,1,1,0,
                    1,0,0,0,0,0,1,
                    1,0,0,0,0,0,1,
                    1,0,0,0,0,0,1,
                    0,1,0,0,0,1,0};

    vector<int> D ={1,1,1,1,1,1,1,
                    1,0,0,0,0,0,1,
                    1,0,0,0,0,0,1,
                    0,1,0,0,0,1,0,
                    0,0,1,1,1,0,0};

    vector<int> E ={1,1,1,1,1,1,1,
                    1,0,0,1,0,0,1,
                    1,0,0,1,0,0,1,
                    1,0,0,1,0,0,1,
                    1,0,0,0,0,0,1}; 

    vector<int> F ={1,1,1,1,1,1,1,
                    0,0,0,1,0,0,1,
                    0,0,0,1,0,0,1,
                    0,0,0,0,0,0,1,
                    0,0,0,0,0,0,1};

    vector<int> G ={1,1,1,1,1,1,0,
                    1,0,0,0,0,0,1,
                    1,0,0,0,0,0,1,
                    1,0,1,0,0,0,1,
                    1,1,1,0,0,0,1};

    vector<int> H ={1,1,1,1,1,1,1,
                    0,0,0,1,0,0,0, 
                    0,0,0,1,0,0,0,
                    0,0,0,1,0,0,0,
                    1,1,1,1,1,1,1};

    vector<int> I ={0,0,0,0,0,0,0,
                    1,0,0,0,0,0,1,
                    1,1,1,1,1,1,1,
                    1,0,0,0,0,0,1,
                    0,0,0,0,0,0,0};

    vector<int> J ={0,1,0,0,0,0,0,
                    1,0,0,0,0,0,0,
                    1,0,0,0,0,0,1,
                    0,1,1,1,1,1,1,
                    0,0,0,0,0,0,1};

    vector<int> K ={1,1,1,1,1,1,1,
                    0,0,0,1,0,0,0,
                    0,0,1,0,1,0,0,
                    0,1,0,0,0,1,0,
                    1,0,0,0,0,0,1};

    vector<int> L ={1,1,1,1,1,1,1,
                    1,0,0,0,0,0,0,
                    1,0,0,0,0,0,0,
                    1,0,0,0,0,0,0,
                    1,0,0,0,0,0,0};


    vector<int> M ={1,1,1,1,1,1,1,
                    0,0,0,0,0,1,0,
                    0,0,0,0,1,0,0,
                    0,0,0,0,0,1,0,   
                    1,1,1,1,1,1,1};

    vector<int> N ={1,1,1,1,1,1,1,
                    0,0,0,0,1,0,0,
                    0,0,0,1,0,0,0,
                    0,0,1,0,0,0,0,
                    1,1,1,1,1,1,1};
                    
    vector<int> O ={0,1,1,1,1,1,0,
                    1,0,0,0,0,0,1,
                    1,0,0,0,0,0,1,
                    1,0,0,0,0,0,1,
                    0,1,1,1,1,1,0};

    vector<int> P ={1,1,1,1,1,1,1,
                    0,0,0,1,0,0,1,
                    0,0,0,1,0,0,1,
                    0,0,0,1,0,0,1,
                    0,0,0,0,1,1,0};

    vector<int> Q ={0,1,1,1,1,1,0,
                    1,0,0,0,0,0,1,
                    1,0,1,0,0,0,1,
                    0,1,0,0,0,0,1,
                    1,0,1,1,1,1,0};

    vector<int> R ={1,1,1,1,1,1,1,
                    0,0,0,1,0,0,1,
                    0,0,1,1,0,0,1,
                    0,1,0,1,0,0,1,
                    1,0,0,0,1,1,0};

    vector<int> S ={1,0,0,0,1,1,0,
                    1,0,0,1,0,0,1,
                    1,0,0,1,0,0,1,
                    1,0,0,1,0,0,1,
                    0,1,1,0,0,0,1};

    vector<int> T ={0,0,0,0,0,0,1,
                    0,0,0,0,0,0,1,
                    1,1,1,1,1,1,1,
                    0,0,0,0,0,0,1,
                    0,0,0,0,0,0,1};

    vector<int> U ={0,1,1,1,1,1,1,
                    1,0,0,0,0,0,0,
                    1,0,0,0,0,0,0,
                    1,0,0,0,0,0,0,
                    0,1,1,1,1,1,1};

    vector<int> V ={0,0,1,1,1,1,1,
                    0,1,0,0,0,0,0,
                    1,0,0,0,0,0,0,
                    0,1,0,0,0,0,0,
                    0,0,1,1,1,1,1};                        

    vector<int> W ={1,1,1,1,1,1,1,
                    0,1,0,0,0,0,0,
                    0,0,1,0,0,0,0,
                    0,1,0,0,0,0,0,
                    1,1,1,1,1,1,1};

    vector<int> X ={1,1,0,0,0,1,1,
                    0,0,1,0,1,0,0,
                    0,0,0,1,0,0,0,
                    0,0,1,0,1,0,0,
                    1,1,0,0,0,1,1};

    vector<int> Y ={0,0,0,0,0,1,1,
                    0,0,0,0,1,0,0,
                    1,1,1,1,0,0,0,
                    0,0,0,0,1,0,0,
                    0,0,0,0,0,1,1};

    vector<int> Z ={1,1,0,0,0,0,1,
                    1,0,1,0,0,0,1,
                    1,0,0,1,0,0,1,
                    1,0,0,0,1,0,1,
                    1,0,0,0,0,1,1};

    vector<vector<int>> returnAll(){
        vector<vector<int>> letters;
        letters.push_back(A);
        letters.push_back(B);
        letters.push_back(C);
        letters.push_back(D);
        letters.push_back(E);
        letters.push_back(F);
        letters.push_back(G);
        letters.push_back(H);
        letters.push_back(I);
        letters.push_back(J);
        letters.push_back(K);
        letters.push_back(L);
        letters.push_back(M);
        letters.push_back(N);
        letters.push_back(O);
        letters.push_back(P);
        letters.push_back(Q);
        letters.push_back(R);
        letters.push_back(S);
        letters.push_back(T);
        letters.push_back(U);
        letters.push_back(V);
        letters.push_back(W);
        letters.push_back(X);
        letters.push_back(Y);
        letters.push_back(Z);
    
        return letters;
    }

    //returns letter based on number from 0-25
    char getLetter(int index){
        switch(index){
        case 0:
                return 'A';
                break;
        case 1:
                return 'B';
                break;
        case 2:
                return 'C';
                break;
        case 3:
                return 'D';
                break;
        case 4:
                return 'E';
                break;
        case 5:
                return 'F';
                break;
        case 6:
                return 'G';
                break;
        case 7:
                return 'H';
                break;
        case 8:
                return 'I';
                break;
        case 9:
                return 'J';
                break;
        case 10:
                return 'K';
                break;
        case 11:
                return 'L';
                break;
        case 12:
                return 'M';
                break;
        case 13:
                return 'N';
                break;
        case 14:
                return 'O';
                break;
        case 15:
                return 'P';
                break;
        case 16:
                return 'Q';
                break;
        case 17:
                return 'R';
                break;
        case 18:
                return 'S';
                break;
        case 19:
                return 'T';
                break;
        case 20:
                return 'U';
                break;
        case 21:
                return 'V';
                break;
        case 22:
                return 'W';
                break;
        case 23:
                return 'X';
                break;
        case 24:
                return 'Y';
                break;
        case 25:
                return 'Z';
                break;  


        }
    }

    //returns letter as a vector<int>  based on number from 0-25
    vector<int> returnLetter(int num){
        switch(num){
        case 0:
                return A;
                break;
        case 1:
                return B;
                break;
        case 2:
                return C;
                break;
        case 3:
                return D;
                break;
        case 4:
                return E;
                break;
        case 5:
                return F;
                break;
        case 6:
                return G;
                break;
        case 7:
                return H;
                break;
        case 8:
                return I;
                break;
        case 9:
                return J;
                break;
        case 10:
                return K;
                break;
        case 11:
                return L;
                break;
        case 12:
                return M;
                   break;
        case 13:
                return N;
                break;
        case 14:
                return O;
                break;
        case 15:
                return P;
                break;
        case 16:
                return Q;
                break;
        case 17:
                return R;
                break;
        case 18:
                return S;
                break;
        case 19:
                return T;
                break;
        case 20:
                return U;
                break;
        case 21:
                return V;
                break;
        case 22:
                return W;
                break;
        case 23:
                return X;
                break;
        case 24:
                return Y;
                break;
        case 25:
                return Z;
                break;  
        }
    }

    //prints letter in matrix form
    void printLetter(vector<int> l){
        int counter = 0;

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 7; j++){
            if(l.at(counter) == 1){
                cout << l.at(counter);
            }
            else{
                cout << " ";
            }
            counter++;
            }
            cout << endl;
        }
    
    }

    //prints letter in string form
    void printAsString(vector<int> l){
        for(int i = 0; i < l.size(); i++){
            cout << l.at(i);
        }

    }

};

int main(){
	srand(time(NULL));
	string line;
	Letters l;
	vector<float> desiredOutput;
	vector<float> accuracyPlots;
    int loops = 1000;
    float tempCounter = 0.0;
    vector<float>acc;
	//initialize the output vector
	for(int i = 0; i < 26;i++){
	    desiredOutput.push_back(0.0);
	}

	//35 inputs, 35 neurons for the hidden layer, 26 neurons for the output layer
	Network* network = new Network(35, 35, 26);
	vector<float> input;

	//runs the algorithm alphabetically, it runs A, B, C,...,Y,Z n number of times. Here n is 1000
	vector<vector<int>> testLetters = l.returnAll();
	cout << "Training.. " << endl;
	float error;
	for(int k = 0; k < loops; k++){
        tempCounter = 0.0;
	    for(int i = 0; i < testLetters.size(); i++){
		    vector<int> test = testLetters.at(i);
		    input.clear();

		    //initialize the input vector according the letter
		    for(int j = 0; j < 35; j++){
		        input.push_back((float)test.at(j));
		    }
		

		    int counter = 0;

            //set the desired output according to the letter
		    for(int j = 0; j < 26; j++){
		        if(j == i){
		            desiredOutput.at(j) = 1;
		        }
		        else{
		            desiredOutput.at(j) = 0;
		        }
		    }

            //runs trains the network with the given input and returns the loss fo that run
            //parameters are network object, input vector, learning rate, epoch, desired output vector
		    error = network->trainNetwork(network, input, 0.1, 1, desiredOutput);

            if(i == network->predict(network, input)){
                    tempCounter += 1.0;
            }

		    accuracyPlots.push_back(error);
	    }
        acc.push_back(tempCounter/26.0);
	}

    //this next section tests for accuracy of the neural network by running the program on the
    //each letter 100 times, thus making 26000 tests
    float accuracyCounter = 0.0;
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 26; j++){
            vector<int> test = testLetters.at(j);

            input.clear();
            for(int k = 0; k < 35; k++){
                input.push_back((float)test.at(k));
            }

            for(int k = 0; k < 26; k++){
		        if(j == k){
		            desiredOutput.at(k) = 1;
		        }
		        else{
		            desiredOutput.at(k) = 0;
		        }
    		}


            if(j == network->predict(network, input)){
                accuracyCounter += 1.0;
            }

        }
    }
    float accuracy = accuracyCounter/(1000.0*26.0);

    //The files that were used to plot are commendted out if you want to 
    //test them, uncomment them. What ti does is that it sends the accuracy
    //and loss points to output files
    /*****************OUTPUTS ACCURACY TO FILE TO PLOT***********
    ofstream myfile("accuracyPoints.csv");
    for(int i = 0; i < acc.size();i++){
        myfile << acc.at(i) << endl;
    }
    myfile.close();

    ofstream myfile2("loss.csv");
    for(int i = 0; i < accuracyPlots.size(); i++){
        myfile2 << accuracyPlots.at(i) << endl;
    }
    myfile2.close();

    /*************************************************************/


    /**THIS CODE GETS THE BIT FLIPS TOLERATED FOR EACH RUN: UNCOMMENT IT IF YOU WANT TO SEE
    vector<int> maxBitFlips;
    bool outerLoop = false;
    bool innerLoop = false;

    for(int i = 0; i < testLetters.size();i++){
        vector<int> bitsFlipped;        
        vector<int> realInput = testLetters.at(i);
        vector<int> modifiedInput = testLetters.at(i);
        int randomBit = rand() % 26;
        cout << i << endl;
        outerLoop = false;

        while(!outerLoop){
            innerLoop = false;
            while(!innerLoop){
                randomBit = rand() % 26;
                if(bitsFlipped.size() == 0){
                    bitsFlipped.push_back(randomBit);

                    if(modifiedInput.at(randomBit) == 1){
                        modifiedInput.at(randomBit) = 0;
                    }
                    else{
                        modifiedInput.at(randomBit) = 1;
                    }
                    break;
                }

                for(int k = 0; k < bitsFlipped.size(); k++){
                        if(randomBit == bitsFlipped.at(k)){
                            innerLoop = false;
                            break;
                        }
                        else{
                            innerLoop = true;
                        }
                }
                if(innerLoop){
                    bitsFlipped.push_back(randomBit);

                    if(modifiedInput.at(randomBit) == 1){
                        modifiedInput.at(randomBit) = 0;
                    }
                    else{
                        modifiedInput.at(randomBit) = 1;
                    }
                }
            }

            input.clear();
            for(int k = 0; k < 35; k++){
                input.push_back((float)modifiedInput.at(k));
            }


            if(network->predict(network, input) == i){
                cout << "correct " << endl;
                continue;
            }
            else{
                cout << "incorrect" << endl;
                maxBitFlips.push_back(bitsFlipped.size());
                bitsFlipped.clear();
                outerLoop = true;
            }

        }
        
    }   

    for(int i = 0; i < maxBitFlips.size(); i++){
        cout << i << ": " << maxBitFlips.at(i) << endl;
    }

**************************************************/
    cout << "done training" << endl;
    cout << "Loss of Neural Net: " << error << endl;
    cout << "Hypothetical Accuracy: " << accuracy*100 << "%" <<  endl;
    cout << "_________________________________________________"<< endl;
    cout << "Enter the input string for the Neural Net to pedict(press q to quit):" << endl;
   
        //ask the user for input
        while(true){
        cout << ">>> ";
        getline(cin,line);

        //quit conditino
        if(line == "q" && line.size() == 1){
            break;
        }
        //checks for correct string size
        if(line.size() != 35){
            cout << "The string you entered is not the correct size. Try again:" << endl;
            continue;
        }

        //if the size is correct it checks that its valid input
        for(int i = 0; i < line.size(); i++){
            if(line.at(i) == '0' || line.at(i) == '1'){
                
            }
            else{
                cout << "You entered the correct size, but no the correct values. Only 1's and 0's are allowed as input. Try again: " << endl;
                continue;
            }
        }


        vector<int>tempInput;
        input.clear();
        //once all of the input is correct it passes it to a vector of int to make a prediction
        for(int i = 0; i < line.size(); i++){
            tempInput.push_back((int)line.at(i) - 48);
        }

        for(int j = 0; j < 35; j++){
            input.push_back((float)tempInput.at(j));
        }

        //the letter the neural net guessed is printed on the console
        cout << "The letter you inputted was an: " <<  l.getLetter(network->predict(network, input)) << endl;

    }

}

