#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void wcexe(char *filename,char choose){
	FILE *fp;
	char buffer[1000];
	char c;
	int bufferlen;
	int isLastBlank = 0; // �ϸ��ַ��Ƿ��ǿո�(1��ʾ��  0��ʾ����)
	int charCount=0;
	int wordCount=0;
	int i;
 
	if((fp=fopen(filename,"rb"))==NULL){
		printf("�ļ����ܴ�\n");
		exit(0);
	}
	while(fgets(buffer,1000,fp)!=NULL){
		bufferlen=strlen(buffer);
		for(i=0;i<bufferlen;i++){
			c=buffer[i];
			if(c==' ' || c=='\t'){
				if(isLastBlank==0){
					wordCount++;
				}
				isLastBlank=1;
			}else if(c!='\n'&&c!='\r'){
				charCount++;
				isLastBlank=0;
			}
 
		}
		if(isLastBlank==0)
			wordCount++;
		isLastBlank=1;	
	}
	fclose(fp);
	if(choose == 'c')
		printf("�ַ�����%d\n",charCount);
	else if (choose=='w')
		printf("��������%d\n",wordCount);
	else 
		printf("ѡ���������");	
}
int main(int argc, char ** argv){
	char filename[]="C://Users//dell//Desktop//";
	char choose;
	char file[100];
	for(int i=1;i<argc;i++)
	{
		if(i==1)
			choose=*argv[i];
		if(i==2)
			strcat(filename,argv[i]);	
	}
	wcexe(filename,choose);
	return 0;
}
