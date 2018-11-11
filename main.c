#include <stdio.h>
#include <stdlib.h>
#define SIZE 10



 #include <ctype.h>
 int getch(void);
 void ungetch(int);
 /* getint: get next integer from input into *pn */
 double getfloat(double *pn)
 {
 int c, sign=1;
 double powder=1.0, try1=0.1;
 double try2=1234567;

 while (isspace(c = getch())) /* skip white space */
    ;
 if (!isdigit(c) && c != EOF && c != '+' && c != '-'&&c!='.') {
    ungetch(c); /* it is not a number */
    printf("\n why I have to debug?: %d",c);
 return 0;
 }
 sign = (c == '-') ? -1 : 1;
 if (c == '+' || c == '-')
    c = getch();
 for (*pn = 0; isdigit(c); c = getch()){
        *pn = 10 * (*pn) + (c - '0');
        printf("\n *pn=%f",*pn);
    }
if (c==46){
        c = getch();
        for (*pn = *pn; isdigit(c); c = getch()){
                printf("\n *pn=%f",*pn);
                *pn = 10 * (*pn) + (c - '0');
                powder*=0.1;
    }


}

 printf("\n this is final *pn: %f, sign: %d, powder: %f ",*pn, sign,powder);
 *pn = sign*powder*(*pn);
  printf("\n this is final *pn: %f ", try1*try2);
 printf("\n this is final *pn: %f, ",*pn);
 /*printf("\n sign:%d, powder:%f, *pn:%f",sign,powder,*pn);*/
if (c != EOF){
        printf("\n clear c=%d",c);
    ungetch(c);

 }


 return *pn;
 }


 int main()
{
    double array1[SIZE];
    int n;
    for (n=0;n<SIZE;n++){
            array1[n]=getfloat(&array1[n]);

            printf("\n array1[%d]:%f",n,array1[n]);
    }

    return 0;
}
