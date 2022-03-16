#define MAX 100
char stack[MAX];
int tos = 0;  //top of stack

void push(char ele)
{
    stack[tos] = ele;
    tos=tos+1;
}

char pop()
{
    int ele; 
    if(tos == 0)
        return 1;
    else
        { //pop the element
          tos=tos-1;
          ele=stack[tos];   
        return (ele);
        }//end else 
}

int priority(char oper)
{
    if(oper == '(')
        return 0;
    if(oper == '+' || oper == '-')
        return 1;
    if(oper == '*' || oper == '/')
        return 2;
    if(oper == '^' )
        return 3;
    return 0;
}
