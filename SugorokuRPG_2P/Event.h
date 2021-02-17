#pragma once

typedef enum {
	e_Object = 0,	//�A�C�e���E��
	e_Card,			//�J�[�h�E��
	e_Enemy,		//�G
	e_Talk,			//�F�D�ȉ�b
	e_Weapon,		//������E��
	e_Armor,		//�h����E��
	e_Heal,			//��
	e_Shop,			//�X
	e_Game,			//�~�j�Q�[��
} eEventID;

class EventClass {
private:
	int IDmax;
	int* ID;		//�C�x���gID�̔z��
	int head = 0;	//�C�x���gID�̎��o���ʒu�|�C���^
public:
	const char* path;

	void init_noChoice(int EvSUM, const char* txtFile); //����Ȃ��C�x���g�̏�����
	void init(int EvSUM, const char* txtFile, const char* csvFile);//�C�x���g�̏�����
	void shuffle();	//�C�x���gID�̏��Ԃ��V���b�t������
	int getNextID();//ID���o��
};

void Event_init();