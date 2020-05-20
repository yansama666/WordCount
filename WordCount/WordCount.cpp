#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

int wordcount(char file[]) {
	FILE* fp = NULL;
	int wcount = 1;
	char c;
	if (fopen_s(&fp, file, "r")) {
		printf("û���ҵ��ļ�\n");
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
		printf("û���ҵ��ļ�\n");
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
	printf("�������c:�ַ���  w:������ e:�˳�ϵͳ \n");
	while (1) {
		printf("�������û�����: wordCount.exe -");
		scanf_s("%s", &order, 100);
		if (order[0] == 'c') {
			printf("�������ļ���: ");
			scanf_s("%s", &file, 100);
			printf("�ļ����ַ���Ϊ�� %d\n", charcount(file));
			continue;

		}
		if (order[0] == 'w') {
			printf("�������ļ���: ");
			scanf_s("%s", &file, 100);
			printf("�ļ��ĵ�����Ϊ�� %d\n", wordcount(file));
			continue;

		}

		if (order[0] == 'e') {
			break;

		}

	}
	return 0;

}
