// hogemalloc.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

//新しく構造体hogeを作る(malloc版)
typedef struct hoge{
	char string[40];
	int number;
}hoge;

//hogeの動的生成
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

	//とりあえずhogeのポインタ100個
	hoge* hogearray[100];

	for( int i = 0; i < 100; i++ ){
		hogearray[i] = createHoge( "hogehoge" );

		//生成した内容を表示してみる
		printf( "%d : %s\n", hogearray[i]->number, hogearray[i]->string );
	}

	//ポイする
	for( int i = 0; i < 100; i++ ){
		free( hogearray[i] );
	}
	return 0;
}

