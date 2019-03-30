#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

#define buffsize 16

//read file 1
void readText1()
{
	//define
	int fd;
	int a,b,c;
	int sum=0;
	char buff[buffsize];
	char *ch1;

	//
	//read file
	printf("=========File 1==========\n");
	memset(buff,0,buffsize);
	fd = open("test1.dat",O_RDONLY);
	read(fd,&a,4);
	read(fd,&b,1);
	read(fd,&c,4);
	sum=a+c;
	printf("%d\n",sum);
	close(fd);
}

//read file 2
void readText2()
{
	//define
	int fd;
	int sum=0;
	char buff[buffsize];
	char delim[]=" ";
	char *pch;
	char *pNum2;

	//read file
	memset(buff,0,buffsize);
	printf("=========File 2==========\n");
	fd = open("test2.dat",O_RDONLY);
	read(fd,buff,buffsize);
	//printf(buff);
	pch = strtok(buff, " ");
	//printf(pch);
	pNum2 = strtok(NULL, "");
	//printf(pNum2);
	sum = atoi(pch) + atoi(pNum2);
	printf("\nget %s + %s =%d\n",pch, pNum2, sum);
	printf("==========================\n");

	close(fd);
	printf("\n");
}

//main
main()
{
	readText1();
	readText2();
	return 0;
}
