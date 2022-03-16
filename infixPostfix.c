/* This program converts an infix expression into its post fix format.
   It uses a stack implemented as ADT and defined in 'stackC.h' file.
   Operator precedence is also impmented in the said header file.
   DEsigned by Nitul Dutta. The code is found in */
#include<stdio.h>
#include<ctype.h>
#include "stackC.h"
#define SIZE 100
int main()
{
    char infix[SIZE]  /* stores infix expression   */,
         post[SIZE]   /* stores postfix expression */,
         symbol /* stores individual symbols*/,
         ele    /*stores poped element */;     
    printf("\nEnter an infix expression : ");
    scanf("%s",infix);
    int i=0 /* index to infix */,
        j=0 /* index for postfix */; 
    while(infix[i] != '\0')
       {  //scan element of the infix expression
        symbol=infix[i];
        if(isalnum(symbol))
            post[j++]=symbol;
        else if(symbol == '(')
            push(symbol);
        else if(symbol == ')')
        {
            ele = pop();
            while(ele != '(')
               {
                 post[j++]=ele;
                 ele=pop();
               }//end while  
        }
        else
        {
            while(priority(stack[tos-1]) >= priority(symbol))
                {
                  ele=pop();
                  post[j++]=ele;
                }
            push(symbol);
        }
        i++; //controlling while loop(), scan next element of th input string
    }//end of while
    while(tos != 0)
    { //pop all elements and add it to postfix expression
        ele=pop();
        post[j++]=ele;
    }//end of while()
    post[j]='\0';  //terminate the postfix string
    printf("\nThe postfix representation of given %s is %s \n",infix,post);
    return 0;
}//end of main()