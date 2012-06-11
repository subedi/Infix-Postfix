// *********************** convert.cpp ****************************//
// Author : Uday Raj Subedi , Cameron University, Fall 2010 
// Progream to convert infix to postfix. Infix expression can
// be a string of any type. Postfix is generated as a string expression
// ********************************************************************//

#include<iostream>
//#include<stack>
#include<string>
#include "stack1.cpp"
using namespace std;

string infix;		// infix exression string
char operand;		
char operate;
stack <char> mystack;	// this stack is used to push the operator
string postfix;		// postfix string where the operand is appended
bool isoper=false;


// this function checks for operator precedency in the stack
int precedence(char e)
{
int op;

if(e == ')')
	op=4;

if(e == '*' || e== '/' || e =='^')
	op = 3;

if(e == '+' || e == '-')
	op = 2;

if(e== '(' )
	op=1;

return op;
}




//....................................................................
// This function converts infix to postfix
string convert()
{	
	for(int i=0; i<infix.length(); i++)
	{	
		
	switch(infix[i]){
	
	// braces cases
	case '(': case ')':
	{	
		operate=infix[i];

		if(operate=='(')
		{
			mystack.push(operate);
			break;
		}
	

		if(operate==')')
                {
                 	while(!mystack.empty()&& mystack.top()!='(')	// pop the stack top members untill raches to (
                        {
                                postfix += mystack.top();
                                mystack.pop();
                        }
                        mystack.pop();  // remove the ( operator from stack

                        if(!mystack.empty() && precedence(mystack.top())>1) // if token at top of stack is remainin
                        {
				if(mystack.top()!='('){
                                postfix.append(mystack.top()+ " "); 	// add remaining operators in stack 
 
									//postfix string
                                mystack.pop();
				break;
				}
                        }
			break;

                }
	}



		
	// operate case start		
	case '+': case'-': case'*': case'/': case'^': case'.':
	isoper=true;
	operate=infix[i];
	{	
		// at beginning of calculation or when value of parsed operator = value of top stack operator	
		if(mystack.empty() || precedence(operate)> precedence(mystack.top()))
		{
			mystack.push(operate);				
			break;
		}							
				
		else 
		{	// when operater precedence is lesser than top stack precedence
			while(!mystack.empty() && precedence(operate)<= precedence(mystack.top()))
			{
				postfix += mystack.top();
				mystack.pop();
			}
			
			mystack.push(operate);	
			break;

		}
	}//operate case closed
		
	default:        
		{
                        operand=infix[i];
				if (isoper){
                            	   postfix.append(" ");
                                   isoper = false;
	                 	}
                        postfix += operand;
                        break;

		} // default case closed

	}//switch closed
		
	}// for loop close
	
	while(!mystack.empty()) 	// after finishing for loop, means finishing parsing infix 
					// expression, append all operator from stack to postfix string.
	{	postfix.append(" ");			 
		postfix += mystack.top();
		mystack.pop();
	}

return postfix;

} // function close braces

//.....................................................................
// this function evaluates the postfix expression

int calculate(int num1, int num2, char op)
{	int temp=1;
	switch(op)
	{
	case'+':  return num1+num2;
	case'-':  return num2-num1;
	case'*':  return num1*num2;
	case'/':  return num2/num1;
	case'^': for(int i=0; i<num1; i++)
		  temp*= num2;
		 return temp;
		
		
	default: return 0;
	}
}
//.....................................................................

bool isoperater(char c)
{
switch(c)
{
case'+':case'-':case'*':case'/':case'^':case'%':case')':case'(':
return true;
default:
return false;
}
}


//....................................................................
int evaluate()
{ //1

stack <int> numstack;
int value;
int val1;
int val2;

for(int i=0; i<postfix.length(); i++)
{ 
	value=(int)(postfix[i]);

	if(postfix[i]==' ')
	continue;

	if(isdigit(value)!=0)
	{
		value=(int)(postfix[i]-48);
		
		while(isdigit(postfix[i+1]))
		{
		value=value*10;
		i++;
		value=value+(int)(postfix[i]-48);
		}
		numstack.push(value); 
	}//^^ fn: if parsed value is digit, gets pushed at top of stack
		
	else if(isoperater(postfix[i]))
	{
		val1=numstack.top();
		numstack.pop();
		val2=numstack.top();
		numstack.pop();
	
		numstack.push(calculate(val1, val2, postfix[i]));
	}


} //  for loop closed

return numstack.top();

} // function closed
