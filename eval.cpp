#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <string>

int main(int argc, char** argv){
    //Sets Inputs
    string postfix = argv[1];
    vector<string> postv;
    vector<string> posthold;

    int i,k;
    string hold;

    k=0;
    while(postfix[k]!=' '&&k<postfix.size()){
        hold+=postfix[k];
        k++;
    }
    postv.push_back(hold);
    hold="";
    //cout<<postv[0];
    for(i=1; i<postfix.size(); i++){
        if(postfix[i]==' '){
            k = i+1;
            while(postfix[k]!=' '&&k<postfix.size()){
                hold+=postfix[k];
                k++;
            }
            postv.push_back(hold);
            hold="";
        }
    }
    //cout<<postv[0];
    //cout<<"size: "<<postv.size()<<"\n";
    string postarr[postv.size()];
    for(i=0; i<postv.size(); i++){
        postarr[i] = postv[i];
    }


    //cout<<postv[0];
    double num1, num2,holdnum;
    int j;
    string hold1, hold2, op;
    for(i=0;i<postv.size();i++){
        //cout<<postv.size()<<"\n";
        posthold.clear();
        if(postv[i]=="+"||postv[i]=="-"||postv[i]=="/"||postv[i]=="*"||postv[i]=="^"){
            op = postv[i];
            //cout<<postv[i]<<" ";

            hold1 = postv[i-2];
            hold2 = postv[i-1];
            //cout<<hold1<<postv[i]<<hold2<<" ";

            if(hold1[0] == '-'){
                for(j=1;j<hold1.size();j++){
                    hold+=hold1[j];
                }
                num1 = stoi(hold)*-1;
            } else {
                for(j=0;j<hold1.size();j++){
                    hold+=hold1[j];
                }
                num1 = stoi(hold);
            }
            hold="";
            if(hold2[0] == '-'){
                for(j=1;j<hold2.size();j++){
                    hold+=hold2[j];
                }
                num2 = stoi(hold)*-1;
            } else {
                for(j=0;j<hold2.size();j++){
                    hold+=hold2[j];
                }
                num2 = stoi(hold);
            }
            //cout<<num1<<postv[i]<<num2<<" ";

            hold = "";
            if(op == "+"){
                holdnum = num1 + num2;
            } else if(op == "-"){
                holdnum = num1 - num2;
            } else if(op == "*"){
                holdnum = num1 * num2;
            } else if(op == "/"){
                holdnum = floor(num1 / num2);
            } else if(op == "^"){
                holdnum = pow(num1,num2);
            }
            //cout<<holdnum<<"\n";
            stringstream ss;
            ss<<holdnum;
            hold = ss.str();
            //cout<<postv[i]<<"\n";
            for(k=0;k<postv.size();k++){
                //cout<<hold<<" ";
                if(k==i){
                    posthold.push_back(hold);
                } else
                if(k!=i-1&&k!=i-2){
                    posthold.push_back(postv[k]);
                }
            }
            hold = "";
            postv.clear();
            for(k=0;k<posthold.size();k++){
                postv.push_back(posthold[k]);
                //cout<<postv[k]<<" ";
            }
            //cout<<"\n";
            i=0;
            //cout<<"done";
        }
        //cout<<"donep";
        
    }
    cout<<postv[0];
}