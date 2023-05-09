#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>

std::string randomVictoryPharase();
std::string randomAttemptPhrase();
std::string RandomDefeatPharase();

void guessMyWordMain(){



bool isPlaying = true;
bool keepPlaying = true;

int lives = 3;

std::vector<std::string> randomWords = {"craft","guitar", "monarch", "graduate", "thought", "statement"};

//Random choices
srand(static_cast<unsigned int>(time(0)));
int randomIndex = rand()%randomWords.size();
std::string wordToGuess = randomWords[randomIndex];

//Shuflong the word an saving the original
std::string shuffledWord = wordToGuess;
std::random_shuffle(shuffledWord.begin(), shuffledWord.end());





while(keepPlaying){

    std::cout<<"Welcome to order my word";
    lives = 3;
    while (isPlaying)
    {
        std::string playerWordGuess{};
        std::cout<<"You have "<<lives<<" lives"<<std::endl;
        std::cout<<"\nTry to order this word: "<<shuffledWord<<std::endl;
        std::cin>>playerWordGuess;
        
        if(playerWordGuess == wordToGuess){
            isPlaying = false;
            std::cout<<"\nCongratulations you win!!!"<<std::endl;
            std::cout<<randomVictoryPharase();
            
        }
        else if(lives>0)
        {
            lives--;
            std::cout<<std::endl<<randomAttemptPhrase()<<std::endl;
            
        }
        else{
            isPlaying = false;
            std::cout<<"Sorry, you loose"<<std::endl;
            std::cout<<"The word was: "<<wordToGuess<<std::endl;
            std::cout<<RandomDefeatPharase()<<std::endl;
        }

    }
    
    char keepPlayingChoice;
    std::cout<<"\nDo you want to play again? y/n\n";
    std::cin>>keepPlayingChoice;
    keepPlaying =  keepPlayingChoice == 'y';
        
}
    std::cout<<"Thank you for playing!!!\n\n\n";
}


std::string randomVictoryPharase(){
    std::vector<std::string> phrase = {"Better than i expected","You're truly the best", "Perfection must be your last name", "Imposible no one can defeat me", "thought"};

//Random choices
srand(static_cast<unsigned int>(time(0)));
int randomIndex = rand()%phrase.size();
return phrase[randomIndex];
}

std::string randomAttemptPhrase(){
    std::vector<std::string> phrase = {"Nop, try again","Try thinking harder", "Ready to surrender?", "Almost but, no one can defeat me", "Get good, and try again", "This isn't my even final form"};

//Random choices
srand(static_cast<unsigned int>(time(0)));
int randomIndex = rand()%phrase.size();
return phrase[randomIndex];
}

std::string RandomDefeatPharase(){
    std::vector<std::string> phrase = {"Machines has surpased humans","You never have an opportunity", "You tried, but I winr haha", "No one can defeat me", "Just surrender"};

//Random choices
srand(static_cast<unsigned int>(time(0)));
int randomIndex = rand()%phrase.size();
return phrase[randomIndex];
}