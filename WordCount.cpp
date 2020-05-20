#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cword=0;  //单词数
int cchar=0;  //字符数
int aword=0;  //记录单词状态
void wordcount(char *file)//计算单词数 
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
	printf("单词数：%d ",cword);
}

void charcount(char *file) //计算字符数 
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
	printf("字符数：%d ",cchar);
}

int main(int argc, char* argv[])             
{
    FILE *fp;
    if((fp=fopen(argv[2],"r"))==NULL) 
		printf("文件错误无法打开！");
    else if(!strcmp(argv[1],"-w")) 
		wordcount(argv[2]);                
    else if(!strcmp(argv[1],"-c"))  
		charcount(argv[2]);               
	else
        printf("没有此指令！");
	return 0;
}