// *********************** convert.cpp ****************************//
// Author : Uday Raj Subedi
// Progream to convert infix to postfix. Infix expression can
// be a string of any type. Postfix is generated as a string expression
// ********************************************************************//
#include <iostream>
#include "calculator.cpp"
using namespace std;


int main()
{

system("clear");

//....................................................................
// this function read the infix expression from user

        cout<<" Enter the infix expression: \n\n"<<endl;
        cout<<" --->"; getline(cin, infix);

//......................................................................

convert();

cout<<"******************************************************************"<<endl;
cout<<"-------------------------------------------------------------------"<<endl;
cout<<endl;
cout<<"Postfix expression is : "<<postfix<<"\n\n\n\n"<<endl;

cout<<endl<<endl;

cout<<"The answer is : " <<evaluate()<<endl;
cout<<"\n\n----------------------------------------------------------------"<<endl;
cout<<"******************************************************************"<<endl;

} 

