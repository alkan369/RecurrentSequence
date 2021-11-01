#include <iostream>
#include <cmath>

double recurrentSequence(double lambda){
    return (3*(pow(lambda,2)) + lambda + 2) / (lambda + 5);
}

double findIndex(size_t index, double lambda){
    for(int i = 0; i < index; ++i){
        lambda = recurrentSequence(lambda);
    }
    return lambda;
}

void lambdaCase(double lambda){
    if(lambda == -5){
        std::cout << "Sequence is not defined for lambda = -5" << std::endl;
    }
    else if(lambda < -5){
        std::cout << "Sequence goes to -infinity for lambda < -5" << std::endl;
    }
    else if(lambda > -5 && lambda < -1){
        std::cout << "Sequence goes to +infinity for lambda between -5 and -1" << std::endl;
    }
    else if(lambda == -1 || lambda > -1 && lambda < 1 || lambda == 1){
         std::cout << "Sequence goes to 1 for lambda = -1 or lambda = 1 or lambda between -1 and 1" << std::endl;
    }
    else{
         std::cout << "Sequence goes to +infinity for lambda > 1" << std::endl;
    }
}

void sequenceFunc(){
    std::cout << "Enter lambda : ";
    double lambda;
    std::cin >> lambda;
    lambdaCase(lambda);
    if(lambda == -5){
        return;
    }
    size_t cnt = 0;
    while(cnt != 5){
       std::cout << "Enter index : ";
       size_t index;
       std::cin >> index;
       std::cout << "a" << index  << " = " <<  findIndex(index, lambda) << std::endl; 
        ++cnt;
    }
}

int main(){

    sequenceFunc();
    std::cout << "Exitting" << std::endl;
    system("pause");
    
    return 0;
}