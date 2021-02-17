#pragma once

class EventClass {
private:
	int IDmax;
	int* ID;		//イベントIDの配列
	int head = 0;	//イベントIDの取り出し位置ポインタ
public:
	const char* path;

	EventClass(int EvSUM, const char* txtFile);
	EventClass(int EvSUM, const char* txtFile, const char* csvFile);
	void shuffle();	//イベントIDの順番をシャッフルする
	int getNextID();//ID取り出し
};