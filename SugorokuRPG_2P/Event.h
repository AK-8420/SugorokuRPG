#pragma once

class EventClass {
private:
	int IDmax;
	int* ID;		//�C�x���gID�̔z��
	int head = 0;	//�C�x���gID�̎��o���ʒu�|�C���^
public:
	const char* pass;

	EventClass(int EvSUM, const char* txtFile);
	EventClass(int EvSUM, const char* txtFile, const TCHAR* csvFile);
	void shuffle();	//�C�x���gID�̏��Ԃ��V���b�t������
	int getNextID();//ID���o��
};