/* Lecture Code 2.0
 *
 * Basic use of the STL stack type for RPN CALCULATOR.
 */

#include <iostream>
#include <stack>
#include <cctype>
#include <sstream>

using namespace std;

void calculator(std::string prompt) ;
double applyOperator(char op,  stack<double>& _stack ) ;
void helpCommand();


int main() {
	stack<int> myStack;
    std::string linea="";
   
    calculator("ingrese numero o operador >");

    // std::cout << number;

	return 0;
}





void calculator(std::string prompt) {

    stack<double> stackNumbers;
     stack<std::string> stackOperators;

    double value=0.0;
    std::string line="";
    std::string valueSigno="";

    while(true) {
        std::cout << prompt;
        getline(std::cin, line);

        istringstream stream(line);
        stream >> value ;
        
        istringstream streamLetra(line);
        streamLetra >> valueSigno ;

        if (line.length()==0) line = "Q";
        char dataIn = toupper(line[0]);
        
        
        if(dataIn == 'Q'){
            break;
        }else if(dataIn == 'C') {
            std::cout <<"clearing the stack";
            std::stack<double>  emptyStack ;
            stackNumbers.swap (emptyStack);
            break;
        }else if(dataIn == 'H') {
            helpCommand();
            //  break;
        }else if(isdigit(dataIn)) {

             if (!stream.fail()  &&  stream.eof()) {
                std::cout <<"es un numero\n";
                stackNumbers.push(value);
            } 

        }else {

            if (!streamLetra.fail()  &&  streamLetra.eof()) {
                double resultado = 0.0;
                resultado = applyOperator(dataIn , stackNumbers);
                std::cout <<"resultado de la operacion :> " << resultado << "\n";
            }

        }

    }
   
   
}


double applyOperator(char op,  stack<double>& _stack ) {
    double resultado = 0.0;

    if( op == '+' || op == '-' || op == '*'||op == '/'){
         
        double numberR= _stack.top();
        _stack.pop();
        
        double numberL= _stack.top();
        _stack.pop();

        

            if (op == '+') {
                    resultado = numberR + numberL;
            }else  if (op == '-') {
                      resultado = numberL - numberR;
            }else  if (op == '*') {
                      resultado = numberR * numberL;
            }else  if (op == '/') {
                    //   std::cout <<"es una division \n"<< numberL<<" / " << numberR << "\n";
                      resultado = numberL / numberR;
            }
    }else{
                std::cout <<"incorrect operator, please enter a valid operator +, -, /, * \n";
                resultado=0.0;
    }
  

    return resultado;
}


void helpCommand(){
    std::cout <<"ENTER EXPRESSIONS IN REVERSE POLISH NOTATION,\n";
     std::cout <<"IN WICH OPERATORS FOLLOW THE OPERANDS TO WHICH\n";
      std::cout <<"THEY APPLY. EACH LINE CONSISTS OF A NUMBER, an\n";
       std::cout <<"OPERATOR,  OR ONE OF THE FOLLOWING COMMANDS \n\n";
        std::cout <<"Q -- Quit the program \n";
         std::cout <<"H -- Display this help message \n";
          std::cout <<"C -- Clear the calculator stack \n";
}