#include "DxLib.h"
#include "Event.h"

// イベントIDの総数（1～999)
#define EvSUM_Card 0
#define EvSUM_Enemy 0
#define EvSUM_Talk 6
#define EvSUM_Weapon 3
#define EvSUM_Armor 3
#define EvSUM_Object 3
#define EvSUM_Heal 7
#define EvSUM_Shop 0
#define EvSUM_Game 0

EventClass Card(EvSUM_Card, "text/Event_Card.txt");
EventClass Enemy(EvSUM_Enemy, "text/Event_Enemy.txt");
EventClass Talk(EvSUM_Talk, "text/Event_Talk.txt");
EventClass Weapon(EvSUM_Weapon, "text/Event_Weapon.txt");
EventClass Armor(EvSUM_Armor, "text/Event_Armor.txt");
EventClass Object(EvSUM_Object, "text/Event_Object.txt");
EventClass Heal(EvSUM_Heal, "text/Event_Heal.txt");
EventClass Shop(EvSUM_Shop, "text/Event_Shop.txt");
EventClass Game(EvSUM_Game, "text/Event_Game.txt");


EventClass::EventClass(int EvSUM, const char* txtFile) {
	path = txtFile;
	IDmax = EvSUM;
	ID = (int*)malloc(sizeof(int) * IDmax);
	for (int i = 0; i < IDmax; i++) ID[i] = i + 1;
	shuffle();
}
EventClass::EventClass(int EvSUM, const char* txtFile, const char* csvFile) {
	path = txtFile;
	IDmax = EvSUM;
	ID = (int*)malloc(sizeof(int) * IDmax);

	int fp = FileRead_open(csvFile);
	for (int i = 0; i < IDmax; i++) {
		FileRead_scanf(fp, "%d,", &ID[i]);
	}
	FileRead_close(fp);

	shuffle();
}
void EventClass::shuffle() {
	int tmp, rand;

	for (int i = 0; i < IDmax - 1; i++) {
		rand = GetRand(IDmax - i);
		tmp = ID[IDmax - i - 1];
		ID[IDmax - i - 1] = ID[rand];
		ID[rand] = tmp;
	}
}
int EventClass::getNextID() {
	if (head == IDmax) {
		head = 0;
		shuffle();
	}
	int ans = ID[head];
	head++;
	return ans;
}