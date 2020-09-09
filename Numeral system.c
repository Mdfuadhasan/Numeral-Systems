#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void d_to_b(); void d_to_o(); void d_to_h();
int b_to_d(); void b_to_o(); void b_to_h();
int o_to_d(); void o_to_b();void o_to_h();
int h_to_d(); void h_to_b(); void h_to_o();
int main(){
int _1st_op();
void convertor();
void calculator();

int op1;
op1=_1st_op();
if(op1==1)
    convertor();
else if(op1==2)
    calculator();
else
    printf("Please Enter Correct Option.");
return 0;
}//End of main

/////////1st option////
int _1st_op(){
int op;
printf(".........Options.......\n");
printf("      1. Converter\n      2. Calculator\n");
printf("   Enter Option: ");
scanf("%d", &op);
return op;
}
///////Converter////
void convertor(){
int con_op();

int op;
op=con_op();
switch(op){
case 1: d_to_b(); break;
case 2: d_to_o(); break;
case 3: d_to_h(); break;
case 4: printf("Decimal = %d", b_to_d()); break;
case 5: b_to_o(); break;
case 6: b_to_h(); break;
case 7: printf("Decimal = %d", o_to_d()); break;
case 8: o_to_b(); break;
case 9: o_to_h(); break;
case 10: printf("Decimal = %d", h_to_d()); break;
case 11: h_to_b(); break;
case 12: h_to_o(); break;
default: printf("Enter right option.");
}

}
/////Converter option///
int con_op(){
int op;
printf(".........Options.......\n");
printf("    1. Decimal To Binary\n    2. Decimal To Octal\n    3. Decimal To Hexadecimal\n");
printf("    4. Binary To Decimal\n    5. Binary To Octal\n    6. Binary To Hexadecimal\n");
printf("    7. Octal To Decimal\n    8. Octal To Binary\n    9. Octal To Hexadecimal\n");
printf("    10. Hexadecimal To Decimal\n    11. Hexadecimal To Binary\n    12. Hexadecimal To Octal\n");
printf("  Enter Option: ");
scanf("%d", &op);
return op;
}
////Check num of digit/////
int ch_arr(int n, int base){
int m=0;
while(n>0){
    n/=base;
    ++m;
}
return m;
}

//////Check number Valid or not/////////
int ch_nm(int *n, int base, int e){
int i, r=0;
for(i=0; i<e; i++){
    if(*(n+i)<0 || *(n+i)>(base-1)){
        ++r;
        break;
    }
}
return r;
}

/////Decimal to Other calculation/////
void d_to(int *arr, int n, int loop, int base){
int i;
for(i=0; i<loop; ++i){
    *(arr+i)=n%base;
    n/=base;
}
}
////Decimal to binary/////
void d_to_b(){
int num, e, i;
printf("Enter Decimal number: ");
scanf("%d", &num);
e=ch_arr(num, 2);
int bin[e];
d_to(bin, num, e, 2);
printf("Binary = ");
for(i=e-1; i>=0; --i)
    printf("%d", bin[i]);
}

////////Decimal to Octal/////
void d_to_o(){
int num, e, i;
printf("Enter Decimal number: ");
scanf("%d", &num);
e=ch_arr(num, 8);
int oc[e];
d_to(oc, num, e, 8);
printf("Octal = ");
for(i=e-1; i>=0; --i)
    printf("%d", oc[i]);
}

////////Decimal to Hexadecimal/////
void d_to_h(){
int num, e, i;
printf("Enter Decimal number: ");
scanf("%d", &num);
e=ch_arr(num, 16);
int hexa[e];
d_to(hexa, num, e, 16);

printf("Hexadecimal = ");
for(i=e-1; i>=0; --i){
        if(hexa[i]<10)
    printf("%d", hexa[i]);
else
    switch(hexa[i]){
    case 10: printf("A");break;
    case 11: printf("B");break;
    case 12: printf("C");break;
    case 13: printf("D");break;
    case 14: printf("E");break;
    case 15: printf("F");
    }
}
}

//////Other to Decimal calculation////
int cal_to_d(int *n, int base, int e){
int dec=0, p=1, j, h;
for(j=e-1; j>=0; --j){
    h = *(n+j) * p;
    dec += h;
    p *= base;
}
return dec;
}
//////Binary to Decimal////
int b_to_d(){
char num[29];
printf("Enter binary number: ");
scanf("%s", &num);
int n[strlen(num)], dec, i;
for(i=0; i<strlen(num); ++i)
    n[i] = num[i] - 48;
if(ch_nm(n, 2, strlen(num))!=0){
    printf("%s is not a binary number.", num);
    exit(0);
    }
dec = cal_to_d(n, 2, strlen(num));
return dec;
}

//////Binary to Octal//////
void b_to_o(){
int dec, e, i;
dec = b_to_d();
e=ch_arr(dec, 8);
int oc[e];
d_to(oc, dec, e, 8);
printf("Octal = ");
for(i=e-1; i>=0; --i)
    printf("%d", oc[i]);
}

/////Binary to Hexadecimal/////
void b_to_h(){
int dec, e, i;
dec = b_to_d();
e=ch_arr(dec, 16);
int hexa[e];
d_to(hexa, dec, e, 16);
printf("Hexadecimal = ");
for(i=e-1; i>=0; --i){
        if(hexa[i]<10)
    printf("%d", hexa[i]);
else
    switch(hexa[i]){
    case 10: printf("A");break;
    case 11: printf("B");break;
    case 12: printf("C");break;
    case 13: printf("D");break;
    case 14: printf("E");break;
    case 15: printf("F");
    }
}
}

////////Octal to Decimal///
int o_to_d(){
char num[20];
printf("Enter Octal number: ");
scanf("%s", &num);
int n[strlen(num)], dec, i;
for(i=0; i<strlen(num); ++i)
    n[i] = num[i] - 48;
if(ch_nm(n, 8, strlen(num))!=0){
    printf("%s is not an Octal number.", num);
    exit(0);
}
dec = cal_to_d(n, 8, strlen(num));
return dec;
}

/////Octal to Binary/////
void o_to_b(){
int num, e, i;
num = o_to_d();
e=ch_arr(num, 2);
int bin[e];
d_to(bin, num, e, 2);
printf("Binary = ");
for(i=e-1; i>=0; --i)
    printf("%d", bin[i]);
}

/////Octal to Hexadecimal/////
void o_to_h(){
int num, e, i;
num = o_to_d();
e=ch_arr(num, 16);
int hexa[e];
d_to(hexa, num, e, 16);
printf("Hexadecimal = ");
for(i=e-1; i>=0; --i){
        if(hexa[i]<10)
    printf("%d", hexa[i]);
else
    switch(hexa[i]){
    case 10: printf("A");break;
    case 11: printf("B");break;
    case 12: printf("C");break;
    case 13: printf("D");break;
    case 14: printf("E");break;
    case 15: printf("F");
    }
}
}

//////Hexadecimal to Decimal////
int h_to_d(){
char num[29];
printf("Enter hexadecimal number: ");
scanf("%s", &num);
int n[strlen(num)], dec, i;
for(i=0; i<strlen(num); ++i){
    if(num[i]>64 && num[i]<71)
        n[i] = num[i] - 55;
    else
       n[i] = num[i] - 48;
}
if(ch_nm(n, 16, strlen(num))!=0){
    printf("%s is not a hexadecimal number.", num);
    exit(0);
    }
dec = cal_to_d(n, 16, strlen(num));
return dec;
}

////Hexadecimal to Binary///
void h_to_b(){
int num, e, i;
num = h_to_d();
e=ch_arr(num, 2);
int bin[e];
d_to(bin, num, e, 2);
printf("Binary = ");
for(i=e-1; i>=0; --i)
    printf("%d", bin[i]);
}

/////Hexadecimal to Octal/////
void h_to_o(){
int num, e, i;
num = h_to_d();
e=ch_arr(num, 8);
int oc[e];
d_to(oc, num, e, 8);
printf("Octal = ");
for(i=e-1; i>=0; --i)
    printf("%d", oc[i]);
}


////////CALCULATOR///////
void calculator(){
int calculation(int num[], int n, char op[]);

char num[500];
int l, i, j, res, base, n=1, m, e, en=0, ch=0, x, b[4]={2, 8, 10, 16};
char a[4][3]={"2", "8", "10", "16"};
printf("You have to enter number with base like\n      (675)10+(110)2*(AD)16/(574)8=\n\n");
scanf("%s", &num);
l=strlen(num);
for(i=0; i<l; i++)
    if(num[i]==')')
       ++en;
char op[en+1]; op[en]='\0';
int dec[en];

for(i=1; i<=en; i++){
    m=0;
    for(j=n; j<l; j++){
        if(num[j]==')'){
            break;
        }
        else{
            ++m;
        }
    }
    int nm[m];
    char cnm[m];
    x=0;
    for(j=n; j<n+m; j++){
        cnm[x] = num[j];
        if(num[j]>64 && num[j]<71)
           nm[x] = num[j] - 55;
        else
           nm[x] = num[j] - 48;
        ++x;
    }
    char bs[4];
    x=0;
    for(j=n+m+1; j<n+m+4; j++){
        if((num[j]>47)&&(num[j]<58)){
            bs[x]=num[j];
            ++x;
        }
        else{
            bs[x]='\0';
            break;
        }
    }
    n+=(x-1);
    op[i-1]=num[n+m+2];
    for(j=0; j<4; j++){
        if(strcmp(bs, a[j])==0){
            base=b[j];
            break;
        }
        else if(j==3){
            printf("Error Base.");
            exit(0);
        }
    }
    if(ch_nm(nm, base, m)!=0){
    printf("(%s)%d is not a valid number.", cnm, base);
    exit(0);
    }
    dec[i-1] = cal_to_d(nm, base, m);
    n=n+m+4;

}
if(op[en-1]!='='){
    printf("You have to include '=' sign at the last.");
    exit(0);
}
////Final Result(Output) ////////
res = calculation(dec, en, op);
printf("\nRESULT.....\n");
printf("   Decimal = %d\n", res);
e=ch_arr(res, 2);
int bin[e];
d_to(bin, res, e, 2);
printf("   Binary = ");
for(i=e-1; i>=0; --i)
    printf("%d", bin[i]);
e=ch_arr(res, 8);
int oc[e];
d_to(oc, res, e, 8);
printf("\n   Octal = ");
for(i=e-1; i>=0; --i)
    printf("%d", oc[i]);
e=ch_arr(res, 16);
int hexa[e];
d_to(hexa, res, e, 16);

printf("\n   Hexadecimal = ");
for(i=e-1; i>=0; --i){
    if(hexa[i]<10)
       printf("%d", hexa[i]);
    else
    switch(hexa[i]){
    case 10: printf("A");break;
    case 11: printf("B");break;
    case 12: printf("C");break;
    case 13: printf("D");break;
    case 14: printf("E");break;
    case 15: printf("F");
    }
}
}
/////////Final Calculation////////
int calculation(int num[], int n, char op[]){
int ch_op(char *op, int n, char s_op);

int i, j, p, m=n;
for(i=0; i<n; i++){
    p=ch_op(op, n, '*');
    if(p!=-1){
        num[p] *= num[p+1];
        for(j=p+1; j<n-1; j++)
            num[j]=num[j+1];
        for(j=p; j<n-1; j++)
            op[j]=op[j+1];
        --n;
    }
}

for(i=0; i<n; i++){
    p=ch_op(op, n, '/');
    if(p!=-1){
        num[p] /= num[p+1];
        for(j=p+1; j<n-1; j++)
            num[j]=num[j+1];
        for(j=p; j<n-1; j++)
            op[j]=op[j+1];
        --n;
    }
}

for(i=0; i<n-1; i++){
    switch(op[i]){
    case '+': num[0] += num[i+1]; break;
    case '-': num[0] -= num[i+1];
    }
}
return num[0];
}

///////Check Operator////////
int ch_op(char *op, int n, char s_op){
int i, p=-1;
for(i=0; i<n; i++){
    if(*(op+i)==s_op){
        p=i;
        break;
    }
}
return p;
}
