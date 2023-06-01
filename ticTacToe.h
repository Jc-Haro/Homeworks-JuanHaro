#include<iostream>
#include<string>
#include <sstream>
#include<vector>


const int ROWS = 3;
const int COLUMNS = 3;
const char player1 = 'x';
const char player2 = 'o';

void ticTacToe2P();
void ticTacToeVsIA();
void DrawBoard(char board[ROWS][COLUMNS]);
int getPlayerInput(std::vector<int> & availableBoxes);
int  checkValidInput();
bool checkDigit(char check);
bool checkWin(int playerLastChoice, char board[COLUMNS][ROWS]);

void ticTacToeMain(){
    
    int gameModeInput;
    std::cout<<"***Welcome to TicTacToe***"<<std::endl;
    do{
        std::cout<<"Type the number of the gamemode you want to play:"<<std::endl;
        std::cout<<"1.- Single player Vs IA"<<std::endl;
        std::cout<<"2.- 2 Player Mode"<<std::endl;
        gameModeInput = checkValidInput();
        
    }while(gameModeInput != 1 && gameModeInput != 2);
    
    if(gameModeInput == 1){
        ticTacToeVsIA();
    }
    else{
        ticTacToe2P();
    }
}

void ticTacToeVsIA(){

    std::vector<int> availableBoxes = {0,1,2,3,4,5,6,7,8};
    char gameBoard [ROWS][COLUMNS] = {{'0','1','2'},{'3','4','5'},{'6','7','8'}};
    int turnNumber = 1;
    bool hasWin = false;
    char actualPlayer{};
    int pickedBox;

    do{
        std::cout<<"\n\n\n\n\n\n";
        DrawBoard(gameBoard);
        actualPlayer = turnNumber%2==0? player1 : player2;
        if(actualPlayer == 'x'){
            std::cout<<std::endl<<"Is your turn"<<std::endl;
            pickedBox =  getPlayerInput(availableBoxes);
            gameBoard[pickedBox/3][pickedBox%3] = actualPlayer;
        }
        else{
            std::cout<<std::endl<<"Is my turn"<<std::endl;
            int randomIAIndex = rand()%availableBoxes.size();
            pickedBox = availableBoxes[randomIAIndex];
            gameBoard[pickedBox/3][pickedBox%3] = actualPlayer;
            availableBoxes.erase(availableBoxes.begin() + randomIAIndex);
        }
        
        if(turnNumber>4){
            hasWin = checkWin(pickedBox, gameBoard);
        }
        turnNumber++;
        
    }while(turnNumber<10 && !hasWin);
    
    std::cout<<"\nFinal board"<<std::endl;
    DrawBoard(gameBoard);
    if(hasWin){
        turnNumber--;
        std::cout<<"\nAnd "<< actualPlayer << " WINS!!!"<<std::endl<<std::endl;
    }
    else{
        std::cout<<"\nAnd its a Draw!!!"<<std::endl<<std::endl;
    }
    
    
}

void ticTacToe2P(){

    std::vector<int> availableBoxes = {0,1,2,3,4,5,6,7,8};
    char gameBoard [ROWS][COLUMNS] = {{'0','1','2'},{'3','4','5'},{'6','7','8'}};
    int turnNumber = 1;
    bool hasWin = false;
    char actualPlayer{};
    int pickedBox;

    do{
        std::cout<<"\n\n\n\n\n\n";
        DrawBoard(gameBoard);
        actualPlayer = turnNumber%2==0? player1 : player2;
        std::cout<<std::endl<<"Is "<<actualPlayer<<" turn"<<std::endl;
        pickedBox =  getPlayerInput(availableBoxes);
        gameBoard[pickedBox/3][pickedBox%3] = actualPlayer;
        if(turnNumber>4){
            hasWin = checkWin(pickedBox, gameBoard);
        }
        turnNumber++;
        
    }while(turnNumber<10 && !hasWin);
    
    std::cout<<"\nFinal board"<<std::endl;
    DrawBoard(gameBoard);
    if(hasWin){
        turnNumber--;
        std::cout<<"\nAnd "<< actualPlayer << " WINS!!!"<<std::endl<<std::endl;
    }
    else{
        std::cout<<"\nAnd its a Draw!!!"<<std::endl<<std::endl;
    }
    
    

}

void DrawBoard(char board[ROWS][COLUMNS]){
    
    std::cout<<std::endl;

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){    
            std::cout<<" "<<board[i][j];
        }
        std::cout<<std::endl;
    }
}

int getPlayerInput(std::vector<int> & availableBoxes){
    
    int temporalPlayerInput{};
    bool isBoxedUsed = true;
    int spaceToErase{};

    std::cout<<"Pick a box: ";

    do{
        temporalPlayerInput = checkValidInput();
        for(int i = 0; i<availableBoxes.size(); i++){
            if(availableBoxes[i]==temporalPlayerInput){
                isBoxedUsed = false;
                spaceToErase = i;
            }
        }
        if(isBoxedUsed){
            std::cout<<"That boxed is already used"<<std::endl;
        }

    }while(isBoxedUsed);

    availableBoxes.erase(availableBoxes.begin() + spaceToErase);

    return temporalPlayerInput;
    
}

int  checkValidInput(){

    std::string temporalPlayerInput{};
    bool isValid = false;
   
    do{
        
       std::getline(std::cin,temporalPlayerInput);
       isValid = checkDigit(temporalPlayerInput[0]);
       if(!isValid){
        std::cout<<"Invalid input"<<std::endl;
       }

    }while(!isValid);

    return int(temporalPlayerInput[0]-48);
}

bool checkDigit(char check){
    return check == '0' ||check == '1' ||check == '2' ||check == '3' ||check == '4' ||check == '5' ||check == '6' ||check == '7' ||check == '8';
}

bool checkWin(int playerLastChoice, char board[COLUMNS][ROWS]){
    
    //Doe to a 3x3 matrix if we divide a the player choice into 3 we get in wich column we are as we know how many times we advanced 3 or a whole row movin into the next
    int column = playerLastChoice/3;
    //Doe to a 3x3 matrix if we get module of the player choice into 3 we get in wich row we are as we know how many spaces have we moved over 3
    int row = playerLastChoice%3;
    bool won = false;

    if(board[column][0] == board[column][1] && board[column][0] == board[column][2]){
        return  true;
    }
    if(board[0][row] == board[1][row] && board[0][row] == board[2][row]){
        return  true;
    }
    if(column==row){
        if(board[0][0]== board[1][1] && board[0][0] == board[2][2]){
            return true;
        }
    }
    if( (column + row)==2){
        if(board[2][0]== board[1][1] && board[2][0] == board[0][2]){
            return  true;
        }
    }

    return false;
}