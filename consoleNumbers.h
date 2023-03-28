#include<iostream>
#include<vector>

std::string positiveOrNegative(int numbertoEvaluate);
int getNumber();
int digitAdd(int numberToAdd);//10-99
void pairDigit(int numberToCheck);//10-99
int highNumber(int number1, int number2, int number3);
void getRange(int &minRange, int &maxRange);
void allPairNumRange(int minRange, int maxRange);
int getRangedNumber(int minRange, int maxRange);


void consoleNumbersMain(){

char consoleNumberDesicion;
bool runConsoleNumbers{true};

do{
    std::cout<<"Type the number of option you want to do:\n";
    std::cout<<"1.-Positive or negative"<<std::endl;
    std::cout<<"2.-2 digit number addition"<<std::endl;
    std::cout<<"3.-2 digit pair numbers"<<std::endl;
    std::cout<<"4.-Higher number of 3"<<std::endl;
    std::cout<<"5.-All pair numbers in a range"<<std::endl;
    std::cout<<"6.-Exit"<<std::endl;
    std::cin>>consoleNumberDesicion;


    switch (consoleNumberDesicion){
    case '1': {
        int ponNumber=getNumber(); 
        std::cout<<positiveOrNegative(ponNumber)<<std::endl;
    }
        break;
    case '2': {
        int digitAddNumb=getRangedNumber(10,99);
        std::cout<<"\nThe additions of the 2 digits of the number is: " <<digitAdd(digitAddNumb)<<"\n\n";
        
    }
        break;
    case '3':{
        pairDigit(getRangedNumber(10,99));
    }
        break;
    case '4':{
        int n1=getNumber(), n2=getNumber(), n3=getNumber();
       
        std::cout<<"The highest number is: "<<highNumber(n1,n2,n3)<<std::endl;
     } 
     break;
    case '5':{
        int min, max;
        getRange(min,max);
        allPairNumRange(min,max);
    }
        break;
    case '6': runConsoleNumbers=false;
        break;
    default: std::cout<<"Invalid option\n";
        break;
    }


}while(runConsoleNumbers);
}

std::string positiveOrNegative(int numbertoEvaluate){

    if(numbertoEvaluate>0){
        return "\nThe number is positive\n";
    }
    else if(numbertoEvaluate<0){
        return "\nThe number is negative\n";
    } else{
        return "\nThe number is 0\n";
    } 
}
int getNumber(){
    int intToSave;
    std::cout<<"Type a number ";
    std::cin>>intToSave;
    return intToSave;
}
int digitAdd(int numberToAdd){
 int digitAdded{0};
 digitAdded+=numberToAdd%10;
 numberToAdd/=10;
 digitAdded+=numberToAdd%10;

 return digitAdded;
}
void pairDigit(int numberToCheck){

int pairConunter{0};

if(numberToCheck%2==0){
pairConunter+=1 ;
} 
if((numberToCheck/10)%2==0){
pairConunter+=2 ;
}

switch (pairConunter){
case 1:  std::cout<<"\nSecond digit is pair: "<<numberToCheck%10<<std::endl;
    break;
case 2:  std::cout<<"\nFirst  digit is pair: "<<(numberToCheck/10)%10<<std::endl;
    break;
case 3:  std::cout<<"\nBoth digits are pair\n";
    break;
case 0:  std::cout<< "\nNone of the digits are pair\n";
    break;
default:  std::cout<<"\nError\n";
    break;
}

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
    std::cin>>maxRange;
    if(minRange>=maxRange){
        std::cout<<"Minimum range have to be lower than Maximun range\n";
    }
    }while (minRange>=maxRange);
}
void allPairNumRange(int minRange, int maxRange){
    if(minRange%2!=0){
        minRange++;
    }
    for(int i = minRange; i<=maxRange; i+=2){
        std::cout<<i<<", ";
    }
    std::cout<<std::endl;
    
}
int getRangedNumber(int minRange, int maxRange){
    
    int tempNumb;
    
    do
    {
       std::cout<<"Type a number between "<<minRange<<" and "<<maxRange<<": ";
        std::cin>>tempNumb;
    } while (tempNumb>maxRange||tempNumb<minRange);
    
    return tempNumb;
    
}