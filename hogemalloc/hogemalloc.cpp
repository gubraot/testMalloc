// hogemalloc.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"

//�V�����\����hoge�����(malloc��)
typedef struct hoge{
	char string[40];
	int number;
}hoge;

//hoge�̓��I����
hoge* createHoge( char* hogeString ){
	static int counter = 0;

	hoge* returnObject = (hoge*)malloc( sizeof(hoge) );
	strcpy( returnObject->string, hogeString );
	returnObject->number = counter;

	counter++;

	return returnObject;
}


int _tmain(int argc, _TCHAR* argv[])
{

	//�Ƃ肠����hoge�̃|�C���^100��
	hoge* hogearray[100];

	for( int i = 0; i < 100; i++ ){
		hogearray[i] = createHoge( "hogehoge" );

		//�����������e��\�����Ă݂�
		printf( "%d : %s\n", hogearray[i]->number, hogearray[i]->string );
	}

	//�|�C����
	for( int i = 0; i < 100; i++ ){
		free( hogearray[i] );
	}
	return 0;
}

