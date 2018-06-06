#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char bit[20];

void convert(char mask[12])
{
strcpy(bit,"");
for(int i=0;i<strlen(mask);i++)
{
switch(mask[i])
{
case '1':strcat(bit,"0001");
	break;
case '2':strcat(bit,"0010");
	break;
case '3':strcat(bit,"0011");
	break;
case '4':strcat(bit,"0100");
	break;
case '5':strcat(bit,"0101");
	break;
case '6':strcat(bit,"0110");
	break;
case '7':strcat(bit,"0111");
	break;
case '8':strcat(bit,"1000");
	break;
case '9':strcat(bit,"1001");
	break;
case 'A':strcat(bit,"1010");
	break;
case 'B':strcat(bit,"1011");
	break;
case 'C':strcat(bit,"1100");
	break;
case 'D':strcat(bit,"1101");
	break;
case 'E':strcat(bit,"1110");
	break;
case 'F':strcat(bit,"1111");
	break;
}
}
}

void main()
{
FILE *f1;
f1=fopen("input.txt","r");
char type,progname[20],input[20],mask[20];
int len,addr,sa,psa,c;

printf("Enter starting address\n");
scanf("%x",&sa);

fscanf(f1,"%c %s %x %x",&type,progname,&psa,&len);
printf("Loading program %s of len %06X starting at %06X\n",progname,len,psa+sa);

fscanf(f1,"%s",input);

while(strcmp(input,"E")!=0)
{
if(strcmp(input,"T")==0)
{
c=0;
fscanf(f1,"%X",&addr);
fscanf(f1,"%s",mask);
addr=addr+sa;
}
convert(mask);
fscanf(f1,"%s",input);
if(strcmp(input,"T")==0)
continue;
if(strcmp(input,"E")==0)
break;
char sub[20];
strcpy(sub,&input[2]);

int add=strtol(sub,NULL,16);
if(bit[c]=='1')
add=add+sa;

printf("%06X\t%c%c%X\n",addr,input[0],input[1],add);
c++;
addr=addr+3;
}
fclose(f1);
}

