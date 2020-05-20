#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

int wordcount(char file[]) {
	FILE* fp = NULL;
	int wcount = 1;
	char c;
	if (fopen_s(&fp, file, "r")) {
		printf("没有找到文件\n");
		exit(-1);

	}
	c = fgetc(fp);
	char temp = 'a';
	while ((c = fgetc(fp)) != EOF)
	{

		if ((c == ' ' || c == ',') && (temp != ' ' && temp != ','))
		{
			wcount++;
		}
		temp = c;
	}
	fclose(fp);


	return wcount;

}
int charcount(char file[]) {
	FILE* fp = NULL;
	int ccount = 0;
	char c;
	if (fopen_s(&fp, file, "r")) {
		printf("没有找到文件\n");
		exit(-1);
	}
	c = fgetc(fp);
	while (c != EOF) {
		c = fgetc(fp);
		ccount++;
	}
	fclose(fp);
	return ccount;
}

int main() {
	char order[100], file[100];
	printf("输入命令：c:字符数  w:单词数 e:退出系统 \n");
	while (1) {
		printf("请输入用户命令: wordCount.exe -");
		scanf_s("%s", &order, 100);
		if (order[0] == 'c') {
			printf("请输入文件名: ");
			scanf_s("%s", &file, 100);
			printf("文件的字符数为： %d\n", charcount(file));
			continue;

		}
		if (order[0] == 'w') {
			printf("请输入文件名: ");
			scanf_s("%s", &file, 100);
			printf("文件的单词数为： %d\n", wordcount(file));
			continue;

		}

		if (order[0] == 'e') {
			break;

		}

	}
	return 0;

}
