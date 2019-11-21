//============================================================================
// Name        : sll.cpp
// Author      : 23125
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "lld.h"
#include "stack.h"
#include "stack.cpp"
#include<string.h>
#include<ctype.h>
#define max 50
						//including all files
class stackl
{	
	char infix[max];
	char postfix[max];
	char prefix[max];
	public:
	void infixtopostfix();
    int evaluatepostfix();
    void infixtoprefix();
    int evaluateprefix();
	void input();
	void display();	
};
void stackl::display()
{
	 cout<<"Infix equation is : ";
	 cout<<infix;
}
void stackl::input()
{
	cout<<"Input Infix Equation : ";
	cin>>infix;
}
int main() {
	int ch;
	int eva,evapre;
	stackl s;						//making class object s
	do{
		cout<<"\nMENU\n1)Input InfixExpression\n2)display\n3)IntoPostfix\n4)Evaluate Postfix\n5)IntoPrefix\n6)Evalute Prefix\nEnter your choice : ";
		cin>>ch;
		  switch(ch)
		  {
		  case 1:
		  	      s.input();
			      break;
		  case 2:
			       s.display();
			  	   break;
		  case 3:
			        s.infixtopostfix();					//calling function using object
			       break;
		  case 4:
		  	       eva=s.evaluatepostfix();
		  	       cout<<"evaluated postfix is : "<<eva;
		  	       break;
		  case 5:
		           	s.infixtoprefix();
					break;
		  case 6:
			       evapre=s.evaluateprefix();
			       cout<<"Evaluated Prefix is : "<<evapre;
			        break;
		  }
		}while(1);
}
int stackl::evaluateprefix()
{
    
   	stack<int>st;						//declaring stack containing integers only
   	Strrev(prefix);
	int n;
	int l=strlen(prefix);
	for (int i = 0; i<l; i++)  
    {  
        if (isdigit(prefix[i]))
            {
            st.push(prefix[i]-'0');				//subtracting ascii value of 0 as '0' because it will take character value
			} 
        else if(isalpha(prefix[i]))
        {
        	cout<<"Enter the Value of "<<prefix[i]<<"::";
        	cin>>n;
        	st.push(n);
		}	
		else
        {  

            int val1 = st.pop();  
            int val2 = st.pop();  
            switch (prefix[i])  
            {  
            case '+': st.push(val1 + val2); break;        
            case '-': st.push(val1 - val2); break;        //top-(top-1)
            case '*': st.push(val1 * val2); break;  
            case '/': st.push(val1/val2); break; 			//top/(top-1) 
            }  
        }  
    }  
    return st.pop();
   	
}

int stackl::evaluatepostfix()
{
	stack<int>st;
	int n;
	int l=strlen(postfix);
	for (int i = 0; i<l; i++)  
    {  
        if (isdigit(postfix[i]))
            {
            st.push(postfix[i]-'0');	
			} 
        else if(isalpha(postfix[i]))
        {
        	cout<<"Enter the Value of "<<postfix[i]<<"::";
        	cin>>n;
        	st.push(n);
		}	
		else
        {  

            int val1 = st.pop();  
            int val2 = st.pop();  
            switch (postfix[i])  
            {  
            case '+': st.push(val2 + val1); break;  
            case '-': st.push(val2 - val1); break; 				//(top-1)-top 
            case '*': st.push(val2 * val1); break;  
            case '/': st.push(val2/val1); break;  
            }  
        }  
    }  
    return st.pop();  
}  
int assoc(char c)
{
    if(c=='-' || c=='+' || c=='%' || c=='*' || c=='/')			//associativity left to right
        return 1;
    if(c=='^')													//since power(^) has reverse assoc for POSTFIX
        return 2;
    return 0;
}
int assocpre(char c)
{
    if(c=='-' || c=='+' || c=='%' || c=='*' || c=='/')			//Associativity Right to left PREFIX
        return 2;
    if(c=='^')
        return 1;
    return 0;
}
int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}
void stackl::infixtopostfix()
{
	stack<char>st;
	int k=0;
  int l=strlen(infix);
  for(int var=0;var<l;var++)
  {
	  if(infix[var]=='(')
		  st.push(infix[var]);
	  else if(infix[var] == ')')
	         {
	             while(st.peep() != '(')			//upto '(' comes pop out all
	             {
	                postfix[k++] =st.pop();
	             }
	              st.pop();
	         }
	  else if(isalpha(infix[var])||isdigit(infix[var]))
	  {
		  postfix[k++]=infix[var];
	  }
	  else
	     {
	     if(st.isEmpty() || st.peep()=='(')				//checking empty and '(' brace for  pushing 
            st.push(infix[var]);
         else if(prec(infix[var])>prec(st.peep()))		// chote ke upper bada bhaith sakta
        		 st.push(infix[var]);
         else if(prec(infix[var])<prec(st.peep()))
        		 {
        		 	while((st.peep()!='(') || (prec(infix[var])<prec(st.peep())))		
                    {
                    postfix[k++]=st.pop();
                    if(st.isEmpty()) break;						//if stack becomes empty a^b^c+d
                   }
                   if(!(st.isEmpty()) && (prec(infix[var])==prec(st.peep())))			// same priority pop out 
                      postfix[k++]=st.pop();
        	       st.push(infix[var]);				//if stack becomes empty then push it for a^b^c+d
        		 }
        else if(prec(infix[var])==prec(st.peep()))
            {
                if(assoc(infix[var])==1)
                {
                    postfix[k++]=st.pop();
                    st.push(infix[var]);
                }
                else
                    st.push(infix[var]);	 			//^ ke upper ^ bhaith sakta
        	 }
	     }
	  }
	   while(!st.isEmpty())
    {
        postfix[k++]=st.pop();
    }
    postfix[k]='\0';
   cout<<"Postfix Expression is : ";
	cout<<postfix;
}
void stackl::infixtoprefix()
{
	int l=strlen(infix);
	strrev(infix); 
	stack<char>st;
	int k=0; 
  for(int var=0;var<l;var++)
  {
	  if(infix[var]==')')
		  st.push(infix[var]);
	  else if(infix[var] == '(')
	         {
	             while(st.peep() != ')')
	             {
	                prefix[k++] =st.pop();
	             }
	              st.pop();
	         }
	  else if(isalpha(infix[var])||isdigit(infix[var]))
	  {
		  prefix[k++]=infix[var];
	  }
	  else
	     {
	     if(st.isEmpty() || st.peep()==')')
            st.push(infix[var]);
         else if(prec(infix[var])>prec(st.peep()))
        		 st.push(infix[var]);
         else if(prec(infix[var])<prec(st.peep()))
        		 {
        		 	while((st.peep()!=')') || (prec(infix[var])<prec(st.peep())))
                    {
                    prefix[k++]=st.pop();
                    if(st.isEmpty()) break;
                   }
                if(!(st.isEmpty()) && (prec(infix[var])==prec(st.peep())))
                    prefix[k++]=st.pop();
        	       st.push(infix[var]);
        		 }
        else if(prec(infix[var])==prec(st.peep()))
            {
                if(assocpre(infix[var])==1)
                {
                    prefix[k++]=st.pop();
                    st.push(infix[var]);
                }
                else
                    st.push(infix[var]);	 
        	 }
	     }
	  }
	   while(!st.isEmpty())
    {
        prefix[k++]=st.pop();
    }
    prefix[k]='\0';
   cout<<"Prefix Expression is : ";
	cout<<strrev(prefix);
}
/*MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 1
Input Infix Equation : ((a+b)+c*(d/e))+f

MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 2
Infix equation is : ((a+b)+c*(d/e))+f
MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 3
Postfix Expression is : ab+cde/*+f+
MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 4
Enter the Value of a::1
Enter the Value of b::2
Enter the Value of c::3
Enter the Value of d::4
Enter the Value of e::5
Enter the Value of f::6
evaluated postfix is : 9
MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 5
Prefix Expression is : +++ab*c/def
MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 6
Enter the Value of f::1
Enter the Value of e::2
Enter the Value of d::3
Enter the Value of c::4
Enter the Value of b::5
Enter the Value of a::6
Evaluated Prefix is : 16
MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 1
Input Infix Equation : a*(b+c)-d/e

MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 2
Infix equation is : a*(b+c)-d/e
MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 3
Postfix Expression is : abc+*de/-
MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 4
Enter the Value of a::1
Enter the Value of b::2
Enter the Value of c::3
Enter the Value of d::4
Enter the Value of e::5
evaluated postfix is : 5
MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 5
Prefix Expression is : -*a+bc/de
MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 6
Enter the Value of e::1
Enter the Value of d::2
Enter the Value of c::3
Enter the Value of b::4
Enter the Value of a::5
Evaluated Prefix is : 33
MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 1
Input Infix Equation : ((a+b)*(c+d)/(e-f))+g

MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 2
Infix equation is : ((a+b)*(c+d)/(e-f))+g
MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 3
Postfix Expression is : ab+cd+*ef-/g+
MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 4
Enter the Value of a::1
Enter the Value of b::2
Enter the Value of c::3
Enter the Value of d::4
Enter the Value of e::5
Enter the Value of f::6
Enter the Value of g::7
evaluated postfix is : -14
MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 5
Prefix Expression is : +/*+ab+cd-efg
MENU
1)Input InfixExpression
2)display
3)IntoPostfix
4)Evaluate Postfix
5)IntoPrefix
6)Evalute Prefix
Enter your choice : 6
Enter the Value of g::1
Enter the Value of f::2
Enter the Value of e::3
Enter the Value of d::4
Enter the Value of c::5
Enter the Value of b::6
Enter the Value of a::7
Evaluated Prefix is : 118*/

