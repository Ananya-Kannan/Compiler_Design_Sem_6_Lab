#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int i=0,top=0;
char stack[20],ip[20];


void push(char c){
	if(top>=20){
		printf("Stack overflow");
	}
	else{
		stack[top++] = c;
	}
}


void pop(void){
	if(top<0){
		printf("Under flow");
	}
	else{
		top--;
	}
}


void error(void){
	printf("\n\n Syntax Error!! String is invalid\n");
	exit(0);
}


int main(){
	int n;
	printf("The given Grammer is \n\n");
	printf("E -> TE'\n");
	printf("E' -> +TE' |epsilon\n");
	printf("T -> FT'\n");
	printf("T' -> *FT' | epsilon\n");
	printf("F -> (E) | i \n\n");
	printf("Enter the string to be parsed:\n");
	scanf("%s",ip);
	n=strlen(ip);
	ip[n] = '$';
	ip[n+1] = '\0';
	push('$');
	push('E');
	while(ip[i]!='\0'){
		if(ip[i]=='$' && stack[top-1]=='$'){
			printf("\n\n Sucessfully parsed the string \n");
			return 1;
		}
		else if (ip[i] == stack[top-1]){
			printf("\nmatch of %c",ip[i]);
			i++;
			pop();
		}
		else{
			if(stack[top-1]=='E' && (ip[i]=='i' || ip[i]=='(')){
				printf("\n E -> TE'");
				pop();
				push('A');
				push('T');
			}
			else if (stack[top-1]== 'A' && ip[i]=='+'){
				printf("\n E'-> +TE'");
				pop();
				push('A');
				push('T');
				push('+');
			}
			else if (stack[top-1]== 'A' && (ip[i]== ')' || ip[i] == '$')){
				printf("\n E -> epsilon");
				pop();
			}
			else if (stack[top-1]== 'T' && (ip[i] == 'i' || ip[i] == '(')){
				printf("\n T -> FT'");
				pop();
				push('B');
				push('F');
			}
			else if (stack[top-1]== 'B' && ip[i]=='*'){
				printf("\n T'-> *TF'");
				pop();
				push('B');
				push('F');
				push('*');
			}
			else if (stack[top-1]=='B' && (ip[i]== '+' || ip[i] == ')' || ip[i] == '$')){
				printf("\n T -> epsilon");
				pop();
			}
			else if (stack[top-1]== 'F' && (ip[i] == 'i')){
				printf("\n F -> i'");
				pop();
				push('i');
			}
			else if (stack[top-1]== 'F' && ip[i]=='('){
				printf("\n F-> (E)");
				pop();
				push(')');
				push('E');
				push('(');
			}
			else{
				error();
			}
		}
	}
    return 0;
}
