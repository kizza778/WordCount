#include <stdio.h>
#include <stdlib.h>

//统计文件字符数 
int getChar(FILE *fp){
	char ch;
	int number=0;
	while((ch=fgetc(fp))!=EOF){//读取不到字符会显示EOF
		if((ch!='\n')&&(ch!=' ')&&(ch!='\t')){
			number++;
		}
	}
	rewind(fp);
	return number;
}

//统计文件单词数 
int getWord(FILE *fp){
	int flag=0;
	int number=0;
	char ch;
	while(feof(fp)==0)//等于0表示文件未结束
    {
        ch = fgetc(fp);//读取一个字符后，光标位置会后移一个字节继续读
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') 
           ||(ch >= '0' && ch <= '9')){
             flag = 0;
        }
        else if(flag == 0 && (ch != '-' && ch != '/'&& ch != '\'')) //ch不是字母和数字
        {
            number++;
            flag = 1;
        }
    }
    rewind(fp);
    return number;
}

//主函数 
int main(int argc,char*argv[]){
	FILE *fp;
	int number;
	char string;

    if(argc==3){
    	//读取文件的内容
		fp = fopen(argv[2],"r");
		//打开失败 
		if(fp == NULL){
			printf("错误：无法打开%s\n",argv[2]);
			exit(1);
		} 
			//对参数进行匹配 
		    if(!strcmp(argv[1],"-c")){//统计字符数 
		        number = getChar(fp);
		     	printf("字符数为%d\n",number);
		    }
		
		    else if(!strcmp(argv[1],"-w")){//统计单词数 
			    number = getWord(fp);
			    printf("单词数为%d\n",number); 
		   }
	}
	else {
		printf("错误：参数输入错误，请重新输入\n");
	}
	
} 
