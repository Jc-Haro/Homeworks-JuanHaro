#include<iostream>
#include<vector>

std::string positiveOrNegative(int numbertoEvaluate);
int getNumber(int intToSave);
int digitAdd(int numberToAdd);//10-99
std::string pairDigit(int numberToCheck);//10-99
int highNumber(int number1, int number2, int number3);
void getRange(int &minRange, int &maxRange);
void numRange(int minRange, int maxRange);

void consoleNumbersMain(){




}


std::string positiveOrNegative(int numbertoEvaluate){

    return numbertoEvaluate>0? "\nThe number is positive\n" : numbertoEvaluate<0? "\nThe number is negative\n" : "\nThe number is 0\n";
}

int getNumber(int intToSave){
    std::cout<<"Type a number ";
    std::cin>>intToSave;
}
int digitAdd(int numberToAdd){
 int digitAdded{};
 digitAdded=numberToAdd%10;
 numberToAdd/=10;
 digitAdded=numberToAdd%10;

 return digitAdded;
}
std::string pairDigit(int numberToCheck){

}
int highNumber(int number1, int number2, int number3){
int maxNumber{};
    if(number1>number2){
        maxNumber=number1;
    }
    else{
        maxNumber=number2;
    }
    if (number3>maxNumber){
        maxNumber=number3;
    }
    

return maxNumber;
}
void getRange(int &minRange, int &maxRange){

    do{
    std::cout<<"Type the minimun Range: ";
    std::cin>>minRange;
    std::cout<<"Type maximum Range: ";
    std::cin>>minRange;
    if(minRange>=maxRange){
        std::cout<<"Minimum range have to be lower than Maximun range\n";
    }
    }while (minRange>=maxRange);
}
void numRange(int minRange, int maxRange){
    for(int i = minRange; i<maxRange; i++){
        std::cout<<i<<", ";
    }
    std::cout<<maxRange<<std::endl;
}
