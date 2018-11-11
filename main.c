#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
void dcl(void);
void dirdcl(void);
int gettoken(void);
int tokentype; /* type of last token */
char token[MAXTOKEN]; /* last token string */
char name[MAXTOKEN]; /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
char out[1000];

main()
{
    int type;
    char temp[MAXTOKEN];

    while (gettoken()!=EOF){
        strcpy(out,token);
        printf("!=EOF");

        while((type=gettoken())!='\n')

            if(type==PARENS||type==BRACKETS){

                strcat(out,token);
            }
            else if(type==NAME){
                printf("here");
                sprintf(temp,"%s %s",token,out);
                strcpy(out,temp);
            }else
                printf("invalid input at %s\n",token);
    }
    return 0;

}

/*
int main(int argc,char* argv[])
{
    int counter;
    printf("Program Name Is: %s",argv[0]);
    if(argc==1)
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name");
    if(argc>=2)
    {
        printf("\nNumber Of Arguments Passed: %d",argc);
        printf("\n----Following Are The Command Line Arguments Passed----");
        for(counter=0;counter<argc;counter++)
            printf("\nargv[%d]: %s",counter,argv[counter]);
    }
    return 0;
}
*/



void dcl(void)
{
    int ns;

    for (ns=0; gettoken()=='*';)
        ns++;
    dirdcl();
    while(ns-->0)
        strcat(out,"point to");
}

void dirdcl(void)
{
    int type;

    if(tokentype=='('){
        dcl();
       }
}

int gettoken(void)
{
    int c, getch(void);
    void ungetch(int);
    char *p=token;

    while ((c=getch())==' '||c=='\t')
        ;
    printf ("\n c:%d \n",c);
    if (c=='('){
            if((c=getch())==')'){
                strcpy(token,"()");
                return tokentype=PARENS;
            }else{
            ungetch(c);
            printf("1 \n");
            return tokentype='(';
            }
        }else if(c=='['){
            for(*p++=c;(*p++=getch())!=']';)
                ;
            *p='\0';
            printf("2 \n");
            return tokentype=BRACKETS;
        }else if (isalpha(c)){
            for(*p++=c;isalnum(c=getch());)
                *p++=c;
            *p='\0';
            ungetch(c);
            printf("3 \n");
            return tokentype=NAME;
        }
        else{
            printf("4:%d \n",c);

            return tokentype=c;}
}


