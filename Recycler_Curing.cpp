#include<stdio.h>
#include<afx.h>
#define MAX 1000
int main(int argc, char **argv){
	printf("\n\n\n\n�� ���α׷��� ���� ��ο��� ������Ŭ���� ����� �������� �����ϰ�, ��� ����̺꿡 ��ġ�� ���̷����� ����ϴ�.\n\n\n\n");
	printf("�����ǻ��ס�\n");
	printf("�ٷΰ��Ⱑ ��â ������ �������� �����Ͻø� �˴ϴ�.\n");
	printf("xp�� �� �����Ͻø� �˴ϴ�.\n");
	printf("vista�� �� ���� ������ Ŭ�� �� ������ �������� ������ �ּ���.");
	printf("								-By Heuristy\n\n\n");

	printf("�عٷΰ��� ������ ����� ���̷����� ���� �� �ֽ��ϴ�. ������� �����ּ���.\n");
	printf("�ر����� �ٷΰ��� ������ �������� �ʽ��ϴ�. �� ������ �ٷ� ������ �ּ���!\n\n\n\n\n");
	system("pause");
	printf("\n������...");

	int i;
//��λ��� - ���� ����̺� ���
	for(i=strlen(argv[0])-1;i>=0;i--){
		if(argv[0][i]=='\\')
			break;
		argv[0][i]=NULL;
	}

//RECYCLER ���� - ���� ����̺꿡 ���ؼ���

	char strPath[MAX];

	sprintf(strPath,"%s*.*",argv[0]);

	CFileFind finder;

	BOOL bWorking=finder.FindFile(strPath);

	while (bWorking){
		bWorking = finder.FindNextFile();

		if (finder.IsDots())
			continue;

		if (finder.IsDirectory()){
			CString strFilePath = (LPCTSTR)finder.GetFilePath();
			memset(strPath,0,sizeof(strPath));
			sprintf(strPath,"attrib -s -h \"%s\"",strFilePath);
			system(strPath);
		}
	}
	finder.Close();



//recycler ���� �� ����

	char T='C'-1;
	while(T<='Z'-1){
		T++;

		//����
		{
			char ADDRESS[MAX];
			char addr[MAX];
			sprintf(ADDRESS,"%c:\\recycler",T);
			sprintf(addr,"rd /s /q \"%s\"",ADDRESS);
			system(addr);

			
		}


		//����
		{
			char ADDRESS[MAX];
			char addr[MAX];

			sprintf(ADDRESS,"%c:\\recycler",T);
			sprintf(addr,"attrib -s -h \"%s\"",ADDRESS);
			system(addr);
			if(!fopen(ADDRESS,"w+"))
				continue;
			FILE* cure=fopen(ADDRESS,"w+");

			fprintf(cure,"�� ������ recycler ���̷����� �����ϱ� ���� �����Դϴ�.\n ������ ���� �ּ���.\n -By Heuristy-");
			fclose(cure);


			sprintf(addr,"attrib +s +h \"%s\"",ADDRESS);
			system(addr);
		}
	}


	printf("\n��� �۾��� �Ϸ�Ǿ����ϴ�.\n���� ��ǻ�Ϳ� USB�� ��� Recycler ���̷����� ���ŵǾ����ϴ�.\n-By Heuristy-\n\n\n\n");
	system("PAUSE");
	return 0;
}