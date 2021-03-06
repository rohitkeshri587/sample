#include<stdio.h>
#include<string.h>
void main()
{
    FILE *f1,*f2,*f3,*f4;
    int lc,sa;
    char label[20],opcode[20],operand[20];

    f1=fopen("input1.txt","r");
    f3=fopen("symtab.txt","w");
    f4=fopen("output.txt","w");

    fscanf(f1,"%s %s %s",label,opcode,operand);

    if(strcmp(opcode,"START")==0)
    {
        sa=strtol(operand,NULL,16);
        fprintf(f4,"%X\t%s\t%s\t%s\n",sa,label,opcode,operand);
    }
    else
        sa=0;
    lc=sa;

    fscanf(f1,"%s %s %s",label,opcode,operand);

    while(strcmp(opcode,"END")!=0)
    {
        fprintf(f4,"%X\t%s\t%s\t%s\n",lc,label,opcode,operand);

        if(strcmp(label,"-")!=0)
        {
            fprintf(f3,"%s %x\n",label,lc);
        }
        char tempcode[20],tempvalue[20];
        f2=fopen("optab1.txt","r");
        fscanf(f2,"%s %s",tempcode,tempvalue);
        while(!feof(f2))
        {
            if(strcmp(opcode,tempcode)==0)
            {
                lc=lc+3;
                break;
            }
            fscanf(f2,"%s %s",tempcode,tempvalue);
        }
        fclose(f2);

        if(strcmp(opcode,"WORD")==0)
            lc=lc+3;
        if(strcmp(opcode,"RESW")==0)
            lc=lc+3*(strtol(operand,NULL,10));
        if(strcmp(opcode,"RESB")==0)
            lc=lc+strtol(operand,NULL,10);
        if(strcmp(opcode,"BYTE")==0)
            {
                if(opcode[0]=='X')
                    lc++;
                else
                    lc=lc+strlen(operand)-3;
            }
        fscanf(f1,"%s %s %s",label,opcode,operand);
    }
    fprintf(f4,"%X %s %s %s\n",lc,label,opcode,operand);
    fclose(f1);
    fclose(f3);
    fclose(f4);
    printf("output geberated as 'output.txt' and 'symtab.txt'");


}
