#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

int main(int argc, char** argv){
    (void) argc;
    
    std::string str = argv[1];
    std::stack <std::string> stack;   

    std::istringstream ss(str);

    std::string token;

    while(ss >> token){

        if (token == "("){
            stack.push(token);
        }
        else if ((token == "+" || token == "-" || token == "*" || token == "/" || token == "^")){
            while (!stack.empty() && (((stack.top() == "^" && token != "^")  ||  ((stack.top() == "*" || stack.top() == "/") && (token == "+" || token == "-")) )   ||   ( (token != "^") && (((stack.top() == "*" || stack.top() == "/") && (token == "*" || token == "/"))  || ((stack.top() == "+" || stack.top() == "-") && (token == "+" || token == "-")) )))){
                std::cout << stack.top() << ' ';               
                stack.pop();              
            }
            stack.push(token);
        } 
        else if (token == ")"){
            while( !stack.empty() && stack.top() != "("){
                std::cout << stack.top() << ' ';
                stack.pop();
            }
            if (!stack.empty() && stack.top() == "(")
                stack.pop();
        } 
        else if (token != "+" && token != "-" && token != "*" && token != "/" && token != "^" && token != "(" && token != ")"){
            std::cout << token << " ";
        } 
    }
    while (!stack.empty() && stack.top() != "(" ){
            std::cout << stack.top() << ' ';
            stack.pop();
    }
}
