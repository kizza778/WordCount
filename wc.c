#include <stdio.h>
#include <stdlib.h>

//ͳ���ļ��ַ��� 
int getChar(FILE *fp){
	char ch;
	int number=0;
	while((ch=fgetc(fp))!=EOF){//��ȡ�����ַ�����ʾEOF
		if((ch!='\n')&&(ch!=' ')&&(ch!='\t')){
			number++;
		}
	}
	rewind(fp);
	return number;
}

//ͳ���ļ������� 
int getWord(FILE *fp){
	int flag=0;
	int number=0;
	char ch;
	while(feof(fp)==0)//����0��ʾ�ļ�δ����
    {
        ch = fgetc(fp);//��ȡһ���ַ��󣬹��λ�û����һ���ֽڼ�����
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') 
           ||(ch >= '0' && ch <= '9')){
             flag = 0;
        }
        else if(flag == 0 && (ch != '-' && ch != '/'&& ch != '\'')) //ch������ĸ������
        {
            number++;
            flag = 1;
        }
    }
    rewind(fp);
    return number;
}

//������ 
int main(int argc,char*argv[]){
	FILE *fp;
	int number;
	char string;

    if(argc==3){
    	//��ȡ�ļ�������
		fp = fopen(argv[2],"r");
		//��ʧ�� 
		if(fp == NULL){
			printf("�����޷���%s\n",argv[2]);
			exit(1);
		} 
			//�Բ�������ƥ�� 
		    if(!strcmp(argv[1],"-c")){//ͳ���ַ��� 
		        number = getChar(fp);
		     	printf("�ַ���Ϊ%d\n",number);
		    }
		
		    else if(!strcmp(argv[1],"-w")){//ͳ�Ƶ����� 
			    number = getWord(fp);
			    printf("������Ϊ%d\n",number); 
		   }
	}
	else {
		printf("���󣺲��������������������\n");
	}
	
} 
