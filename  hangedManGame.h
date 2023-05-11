#include<iostream>
#include"./drawHangdeMan.h"
#include<string>
#include<vector>
#include<time.h>
#include <algorithm>   
#include<cctype>



const int MAX_NUMBER_OF_ERRORS = 5;
std::vector<std::string> randomWords = {"hypnothize", "responsibility", "flex", "union", "pursuit", "conception", "bridge" , "assignment","package", "aquarium"};

void checkWord(std::string realWord, std::string &wordShown, char playerGuess, int &errors, bool &hasWin);
bool AlreadyUsedLetter(char guess, std::vector<char> &alreadyUSed);
std::string WinPharase();
std::string LosePharase();

void  hangedManGameMain(){
    
    std::vector<char> usedLetters;

    bool isRunning = true;
    bool hasWin = false;
    do{
        int errors = 0;
        std::cout<<"\nWelcome to the hanged man game\n";

        srand(static_cast<unsigned int>(time(NULL)));
        int randomIndex = rand()%randomWords.size();

        std::string wordToGuess = randomWords[randomIndex];
        std::string wordToShow(wordToGuess.size(),'-');


        while (errors<MAX_NUMBER_OF_ERRORS && !hasWin){
            
            std::string playerGuess{};
            std::cout<<"Try to guess my word"<<std::endl;
            std::cout<<"You can guess one letter at the time"<<std::endl;
            if(usedLetters.size()>0){
                std::cout<<"You have already try these letters: "<<std::endl;
                for(int i = 0; i<= usedLetters.size() - 1; i++){
                std::cout<<usedLetters[i]<<", ";
            }
                std::cout<<std::endl;
            }
            
            DrawHangedMan(errors);

            //std::cout<<std::endl<<wordToGuess<<std::endl;
            std::cout<<std::endl<<wordToShow<<std::endl;
            do{
               
                //playerGuess = {};
               std::cin>>playerGuess;
            }while(AlreadyUsedLetter(playerGuess[0], usedLetters));
            checkWord(wordToGuess,wordToShow,playerGuess[0], errors,hasWin);

        }
        
        if(hasWin){
            winState();
            std::cout<<"\nYou win"<<std::endl;
            std::cout<<"The word was: "<<wordToGuess<<std::endl;
            std::cout<<WinPharase()<<std::endl;
            std::cout<<"\n\n\n";          

        }
        else{
            DrawFinalState();
            std::cout<<"\nYou lose"<<std::endl;
            std::cout<<"The word was: "<<wordToGuess<<std::endl;
            std::cout<<LosePharase()<<std::endl; 
            std::cout<<"\n\n\n";          

        }
        
        isRunning= false;

    }while(isRunning);
    


 }


 void checkWord(std::string realWord, std::string &wordShown, char playerGuess, int &errors, bool &hasWin){

    std::string::iterator wordIter;

    wordIter = std::find(realWord.begin(),realWord.end(),tolower(playerGuess));
    if( wordIter != realWord.end()){
        
        for(int i = 0; i<= realWord.size(); i++){
            if(realWord[i]== tolower(playerGuess)){
                std::string finalGuess(1,tolower(playerGuess));
                wordShown.replace(i,1,finalGuess);                
            }
        }

        if(realWord==wordShown){
            hasWin=true;
        }
    }
    else{
        errors++;

    }

    

 }


bool AlreadyUsedLetter(char guess, std::vector<char> &alreadyUSed){
    std::vector<char>::iterator iter;

    iter =  std::find(alreadyUSed.begin(),alreadyUSed.end(),tolower(guess));
    if(guess=='0'|| guess =='1' || guess == '2' || guess == '3' || guess == '4' || guess == '5' || guess == '6' || guess == '7' || guess == '8' || guess == '9'){
        std::cout<<"Numbers are not allowed"<<std::endl;
        return true;
    }
    if(iter != alreadyUSed.end()){

        std::cout<<"You have already used that letter"<<std::endl;
        return true;
    }
    else{
        alreadyUSed.push_back(tolower(guess));
        return false;
    }
}

std::string WinPharase(){
    std::vector<std::string> phrase = {"Next time you will not be so lucky", "Impossible, no one can defeat me", "Enjoy this win, next will be mine", "Well played my human friend", "A well deserved victory"};
    int randomIndex = rand()%phrase.size();
    
    return phrase[randomIndex];

}
std::string LosePharase(){
    std::vector<std::string> phrase = {"Better luck nex time", "So close, yet so far", "You really toyght you can win?", "Another confirmation that no one can defeat me", "You think you will be the winner but i have won", "Another victim to my list","I think you have some skill issues",  "Hahahahaha"};
    int randomIndex = rand()%phrase.size();
    
    return phrase[randomIndex];
}
 