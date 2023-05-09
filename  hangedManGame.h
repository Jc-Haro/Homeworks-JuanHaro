
/*
#include<iostream>
#include"./drawHangdeMan.h"
#include<string>
#include<vector>
#include<time.h>
#include <algorithm>   



const int MAX_NUMBER_OF_ERRORS = 5;
std::vector<std::string> randomWords = {"hypnothize", "responsibility", "flex", "union", "pursuit", "conception", "bridge" , "assignment","package", "aquarium"};

void checkWord(std::string realWord, std::string &wordShown,std::string playerGuess, int &errors, bool &hasWin);



void  hangedManGameMain(){
    
    bool isRunning = true;
    bool hasWin = false;
    do{
        int errors = 0;
        std::cout<<"\nWelcome to the hanged man game\n";

        srand(static_cast<unsigned int>(time(NULL)));
        int randomIndex = rand()%randomWords.size();

        std::string wordToGuess = randomWords[randomIndex];
        std::string wordToShow(wordToGuess.size(),'_');


        while (errors<MAX_NUMBER_OF_ERRORS || !hasWin){
            std::string playerGuess{};
            std::cout<<"Try to guess my word"<<std::endl;
            std::cout<<"You can guess one letter at the time or go for the full word"<<std::endl;
            DrawHangedMan(errors);
            std::cout<<std::endl<<wordToShow<<std::endl;
            std::getline(std::cin, playerGuess);


        }
        

    }while(isRunning);


 }


 void checkWord(std::string realWord, std::string &wordShown,std::string playerGuess, int &errors, bool &hasWin){

    if (playerGuess.size()==1){
     
        std::string::iterator iterationRealWord = std::find(realWord.begin(),realWord.end(),playerGuess);
        std::string::iterator iterationWordShown;
        int i;
        
        if(iterationRealWord!=realWord.end()){
            for (iterationRealWord = realWord.begin(), iterationWordShown = wordShown.begin(), i=0; iterationRealWord!= realWord.end(); iterationRealWord++, iterationWordShown++, i++){
            wordShown.replace(i,playerGuess.size(),playerGuess);
            }
            if(realWord ==wordShown){
                hasWin = true;
                //call a win pharase
            }
        }
        else{
            errors++;
            //call a fail phrase
        }

        
        
    }   
    else{
         if(realWord == playerGuess){
                hasWin = true;
                //call a win pharase
            }
            else{
                errors++;
                //call a fail phrase
            }
    }
 }

*/
 