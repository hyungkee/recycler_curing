#include<stdio.h>
#include<afx.h>
#define MAX 1000
int main(int argc, char **argv){
	printf("\n\n\n\n본 프로그램은 실행 경로에서 리사이클러로 사라진 폴더들을 복구하고, 모든 드라이브에 설치된 바이러스를 잡습니다.\n\n\n\n");
	printf("※유의사항※\n");
	printf("바로가기가 왕창 생성된 폴더에서 실행하시면 됩니다.\n");
	printf("xp는 걍 실행하시면 됩니다.\n");
	printf("vista는 꼭 파일 오른쪽 클릭 후 관리자 권한으로 실행해 주세요.");
	printf("								-By Heuristy\n\n\n");

	printf("※바로가기 폴더를 실행시 바이러스가 퍼질 수 있습니다. 사용하지 말아주세요.\n");
	printf("※구동후 바로가기 파일은 삭제되지 않습니다. 꼭 실행후 바로 삭제해 주세요!\n\n\n\n\n");
	system("pause");
	printf("\n구동중...");

	int i;
//경로생성 - 현재 드라이브 경로
	for(i=strlen(argv[0])-1;i>=0;i--){
		if(argv[0][i]=='\\')
			break;
		argv[0][i]=NULL;
	}

//RECYCLER 복원 - 현재 드라이브에 한해서만

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



//recycler 제거 및 생성

	char T='C'-1;
	while(T<='Z'-1){
		T++;

		//제거
		{
			char ADDRESS[MAX];
			char addr[MAX];
			sprintf(ADDRESS,"%c:\\recycler",T);
			sprintf(addr,"rd /s /q \"%s\"",ADDRESS);
			system(addr);

			
		}


		//생성
		{
			char ADDRESS[MAX];
			char addr[MAX];

			sprintf(ADDRESS,"%c:\\recycler",T);
			sprintf(addr,"attrib -s -h \"%s\"",ADDRESS);
			system(addr);
			if(!fopen(ADDRESS,"w+"))
				continue;
			FILE* cure=fopen(ADDRESS,"w+");

			fprintf(cure,"이 파일은 recycler 바이러스를 방지하기 위한 파일입니다.\n 지우지 말아 주세요.\n -By Heuristy-");
			fclose(cure);


			sprintf(addr,"attrib +s +h \"%s\"",ADDRESS);
			system(addr);
		}
	}


	printf("\n모든 작업이 완료되었습니다.\n이제 컴퓨터와 USB의 모든 Recycler 바이러스는 제거되었습니다.\n-By Heuristy-\n\n\n\n");
	system("PAUSE");
	return 0;
}