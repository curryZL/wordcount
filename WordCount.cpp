#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cword=0;  //������
int cchar=0;  //�ַ���
int aword=0;  //��¼����״̬
void wordcount(char *file)//���㵥���� 
{   
	FILE *fp;
	fp=fopen(file,"r");
	char ch;
	while(!feof(fp))
	{
		ch=fgetc(fp);
		if((ch >= 'a'&&ch <= 'z')||(ch>='A'&&ch<='Z'))
			aword=1;
		else if(aword)
		{
			cword++;
			aword=0;
		}
	}
	fclose(fp); 
	printf("��������%d ",cword);
}

void charcount(char *file) //�����ַ��� 
{   
	FILE *fp;
	fp=fopen(file, "r");
	char a;
	while (!feof(fp))
	{
		a=fgetc(fp);
		if (a != ' '&&a != '\n'&&a != '\t')
		cchar++;
	}
	fclose(fp);
	printf("�ַ�����%d ",cchar);
}

int main(int argc, char* argv[])             
{
    FILE *fp;
    if((fp=fopen(argv[2],"r"))==NULL) 
		printf("�ļ������޷��򿪣�");
    else if(!strcmp(argv[1],"-w")) 
		wordcount(argv[2]);                
    else if(!strcmp(argv[1],"-c"))  
		charcount(argv[2]);               
	else
        printf("û�д�ָ�");
	return 0;
}