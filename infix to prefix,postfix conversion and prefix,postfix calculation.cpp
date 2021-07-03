#include<bits/stdc++.h>
//#define SIZE 5
using namespace std ;

class stackk
{
private:
    char data [50];
    int top;
public :
    stackk()
    {
        top=0;
    }
    void push(char item)
    {

        data [top]=item;
        top++;
    }
    char getTop()
    {
        return data[top-1];
    }
    char pop()
    {
        if(top==0)
            return '0';
        top--;
        char item=data[top];
        return item;
    }
    int isEmpty()
    {
        if (top==0)
            return 1;
        else
            return 0;
    }
    int getLength()
    {
        return top;
    }
};


void infix_postfix(char * str)
{
    stackk st;
    char temp[30];
    int j=-1;
    int size = strlen(str);

    for(int i=0; i<size; i++)
    {
        if(str[i]!='(' && str[i]!=')' && str[i]!='{' && str[i]!='}' && str[i]!='[' && str[i]!=']' && str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/')
        {
            temp[++j] = str[i];
        }
        else if(str[i]=='+' || str[i]=='-')
        {
            st.push(str[i]);
        }
        else if(str[i]=='(')
        {
            st.push(str[i]);
        }
        else if(str[i]=='*' || str[i]=='/')
        {
            st.push(str[i]);
        }
        else if(str[i]==')')
        {
            while(1)
            {
                if(st.getTop()=='(')
                {
                    st.pop();
                    break;
                }
                temp[++j] = st.getTop();
                st.pop();
            }
        }
    }
    while(!st.isEmpty())
    {
        temp[++j] = st.getTop();
        st.pop();
    }

    int i=-1;
    for(j=0; j<size; j++)
    {
        str[++i]=temp[j];
    }
}
int postfixCalculation(char *exp)
{
    stackk st;
    char *e;
    int n1,n2,n3,num;
    e = exp;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            st.push(num);
        }
        else
        {
            n1=st.pop();
            n2=st.pop();
            switch(*e)
            {
            case '+':
            {
                n3=n1+n2;
                break;
            }
            case '-':
            {
                n3=n2-n1;
                break;
            }
            case '*':
            {
                n3=n1*n2;
                break;
            }
            case '/':
            {
                n3=n2/n1;
                break;
            }
            }
            st.push(n3);
        }
        e++;
    }
    printf("Postfix Calculation : %d\n",st.pop());
    return 0;
}


void reverse(char *exp)
{

    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}
void brackets(char * exp)
{
    int i = 0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}


void infix_prefix(char *exp)
{

    reverse(exp);
    brackets(exp);
    infix_postfix(exp);
    reverse(exp);

}

class Queue
{
private:
    char items[30];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enQueue(int element,int s)
    {
        Queue q;
        if (rear == s - 1)
        {
            for(int i=front; i<rear; i++)
            {
                items[i]=items[i+1];
            }
            rear--;
        }
        if (front == -1)
            front = 0;
        rear++;
        items[rear] = element;
    }

    int deQueue()
    {
        Queue q;
        int element;
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        else
        {
            element = items[front];
            if (front >= rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front++;
            }

        }
        return element;
    }
    int prefixCalculation(char *e)
    {
        Queue q;

        int n1,n2,n3,num;
        int size = strlen(e);

        while(*e != '\0')
        {
            if(isdigit(*e))
            {
                num=*e - 48;
            }
            else
            {
                /*if (*e!='/0')
                {
                    num = *e;
                }*/
                switch(*e)
                {
                case '+':
                {
                  num = '+';
                  break;
                }
                case '-':
                {
                  num = '-';
                  break;
                }
                case '*':
                {
                  num = '*';
                  break;
                }
                case '/':
                {
                  num = '/';
                  break;
                }
                }
            }
            //cout<<num;
            q.enQueue(num,size);

            e++;
            //cout<<num;
        }
        //while(items != '\0')
        for(int i=0; i!='\0'; i++)
        {
            if(items[i] >=0 && items[i]<=9)
            {
                //num = *items - '0';
                //cout<<num;
                num = items[i];
                q.enQueue(num,size);
                q.deQueue();

            }
            else if(items[i]=='+' || items[i]=='-'|| items[i]=='*'|| items[i]=='/')
            {
                if((items[i+1]>=0 && items[i+1]<=9)&&(items[i+2]>=0 && items[i+2]<=9))
                {
                    int simble=q.deQueue();
                    n1=q.deQueue();
                    n2=q.deQueue();
                    front--;
                    switch(simble)
                    {
                    case '+':
                    {
                        n3=n1+n2;
                        break;
                    }
                    case '-':
                    {
                        n3=n2-n1;
                        break;
                    }
                    case '*':
                    {
                        n3=n1*n2;
                        break;
                    }
                    case '/':
                    {
                        n3=n2/n1;
                        break;
                    }
                    }
                    q.enQueue(n3,size);
                }
                else
                {
                    num = items[i];
                    q.enQueue(num,size);
                }
            }
        }
        printf("Prefix Calculation : %d\n",q.deQueue());
        return 0;
    }
};

int main (void)
{
    Queue q;
    while(1)
    {
        printf("1.Infix to Prefix.  2.Infix to POSTFIX.\n3.Prefix Calculation. 4.POSTfix Calculation \n5.Exit\n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            char str[30];
            printf("Infix Expression : ");
            cin >> str;
            infix_prefix(str);

            printf("Prefix Expression : ");
            cout<<str;
            printf("\n");
        }
        else if(ch==2)
        {
            char exp[30];
            printf("Infix Expression : ");
            cin >> exp;

            infix_postfix(exp);
            printf("Postfix Expression : ");
            cout<<exp;
            printf("\n");
        }
        else if(ch==3)
        {
            char exp[30];
            printf("prefix Expression : ");
            cin >> exp;
            q.prefixCalculation(exp);
        }
        else if(ch==4)
        {
            char exp[50];
            printf("Postfix Expression : ");
            cin >> exp;
            postfixCalculation(exp);
        }
        else if(ch==5)
            break;
    }
}
