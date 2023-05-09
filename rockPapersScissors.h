#include<iostream>
#include<conio.h>
#include<time.h>



int getRPS();
std::string rpsWinner(int player, int computer, int &playerWin, int &computerWin);
std::string win(int &playerWin);
std::string lose(int &computerWin);
std::string draw();


void rpsMain(){

    srand(static_cast<unsigned int>(time(0)));

    int playerRPS{};
    int computerRPS{}; 
    int computerWins=0;
    int playerWins =0;

    std::cout<<"\nWelcome to rock paper scissors lets play\nBest of 3 wins";

    while (playerWins<2 && computerWins<2){
        computerRPS= ((rand()%3)+1);
        std::cout<<std::endl<<computerRPS<<std::endl;
        
        std::cout<<"\nPlayer wins: "<<playerWins<<"\nComputer wins: "<<computerWins<<std::endl;
        playerRPS= getRPS();
        std::cout<<playerRPS<<std::endl;
        std::cout<< rpsWinner(playerRPS, computerRPS, playerWins, computerWins);
    }
    
    if(playerWins>computerWins){
        std::cout<<"\nCongratulationsm you win\n";
    } 
    else{
        std::cout<<"Sorry but I never lose\n";  
    } 
    sleep(3);


}

int getRPS(){
    int temporalRPS{};

    do{
        std::cout<<"Chose:\n1.-Rock\n2.-Paper\n3.-Scizzor ";
        std::cin>>temporalRPS;
    }while (temporalRPS<1 || temporalRPS>3);
   
    return temporalRPS;
}

std::string rpsWinner(int player, int computer, int &playerWin, int &computerWin){

    if (player==computer){
        return draw();
    }
    else{
    switch (player)
    {
    case 1: 
        return computer==3? win(playerWin) : computer==2? lose(computerWin) : "Error case 1";
        break;
    case 2: 
        /*switch (computer){
        case '3': return lose(computerWin);
            break;
        case '1': return win(playerWin);
            break;
        default: return "Error";
            break;
        }*/
        return computer==1? win(playerWin) : computer==3? lose(computerWin) : "Error case 2";

        break;
    case 3: 
        return computer==2? win(playerWin) : computer==1? lose(computerWin) : "Error case 3";
        break;
    default: return "Error player S";
        break;
    }
    }
    return "Error else"; 
}
std::string win(int &playerWin){
   playerWin++;
   //WIP feature
   std::string winPhrases[] = {"I'll win next time", "No, I can be deafeted","GG WP", "Pure luck","But can you do it again?"};

    return  "You win ";

}
std::string lose(int &computerWin){
    computerWin++;
    //WIP Feature
    std::string losePharases[] = {"Try harder net time", "Machines always win","GG WP", "Pure strategy","And you will do it again"};

    return "You lose ";

}
std::string draw(){
    //WIP Feature
    std::string drawPharases[] = {"Your luck ends now", "Almost","GG WP", "Did you read my code?","Did I read your mind?"};

    return "It's a draw, ";;
}
