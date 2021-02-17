#pragma once

typedef enum {
	e_Object = 0,	//アイテム拾う
	e_Card,			//カード拾う
	e_Enemy,		//敵
	e_Talk,			//友好な会話
	e_Weapon,		//武器を拾う
	e_Armor,		//防具を拾う
	e_Heal,			//回復
	e_Shop,			//店
	e_Game,			//ミニゲーム
} eEventID;

class EventClass {
private:
	int IDmax;
	int* ID;		//イベントIDの配列
	int head = 0;	//イベントIDの取り出し位置ポインタ
public:
	const char* path;

	void init_noChoice(int EvSUM, const char* txtFile); //分岐なしイベントの初期化
	void init(int EvSUM, const char* txtFile, const char* csvFile);//イベントの初期化
	void shuffle();	//イベントIDの順番をシャッフルする
	int getNextID();//ID取り出し
};

void Event_init();