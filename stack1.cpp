#include <iostream>
using namespace std;
#define size 80			//Decalred size for the string expression.

	template <class T>	//template for the class.
	class stack
	{
		public:
		stack();		//constructor to fill in the array with 0.
		void pop();		//function to take out the top item in pot.
		void push(T item);	//function to push the character in the pot.
		bool full();		//To check if the pot is full.
		bool empty();		//To check if the pot is empty.
		T top();		//gets the top item from the pot.
		void clear();		//clears the pot.

		private:
		T a[size];		//array declared to store the expression in.
		int ttop;		//variable declared for top item.
	};		
 	
	template <class T>		//this is default constructor which runs by itself and  
 	stack<T>::stack()		//fills the array with 0 and initializes ttop to -1.
	{
		ttop = -1;
		for (int i=0; i<size; i++)
		a[i]=0;
	}

	template <class T>		//this function calls the empty function and then if
	void stack<T>::pop()		//possible takes out an item.
	{
		if(!empty())
		{
			ttop--;
		}
	}

	template <class T>		//this function calls the full function then if 
	void stack<T>::push(T item)	//possible pushes in the next character.
	{
		if(!full())
		{
			ttop++;
			a[ttop]=item;
		}
	}

 	template <class T>			//this function returns the truth value after 
	bool stack<T>::full()			//checking if the pot is full or not.
	{
		return ( ttop == (size-1));

	}

 	template <class T>			//this function returns the truth value after 
        bool stack<T>::empty()			//checking if the pot is empty or not.
        {
		return ( ttop == -1 );

        }

	template <class T>			//this function sets the ttop value to -1.
	void stack<T>::clear()
	{
		ttop = -1;
	}		

	template <class T>			//this function calls the empty function and depending
	T stack<T>::top()			//on the truth value it returns the top item.
	{
		if(!empty())
		return a[ttop];
	}
