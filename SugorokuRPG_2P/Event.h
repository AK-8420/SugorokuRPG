#pragma once

class EventClass {
private:
	int IDmax;
	int* ID;		//�C�x���gID�̔z��
	int head = 0;	//�C�x���gID�̎��o���ʒu�|�C���^
public:
	const char* path;

	EventClass(int EvSUM, const char* txtFile);
	EventClass(int EvSUM, const char* txtFile, const char* csvFile);
	void shuffle();	//�C�x���gID�̏��Ԃ��V���b�t������
	int getNextID();//ID���o��
};