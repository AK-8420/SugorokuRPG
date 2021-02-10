#pragma once
#include "DxLib.h"

class Graphics {
private:
	int width, height;
	int numSliceX, numSliceY;
	int* handle;
public:
	int x = 0, y = 0;
	int index = 0;
	double exRate = 1; //�g�嗦
	double Angle = 0; //��]��

	Graphics(const TCHAR* path, int w, int h, int sx, int sy) {
		width = w;
		height = h;
		numSliceX = sx;
		numSliceY = sy;

		const int num = numSliceX * numSliceY;
		//�T�C�Y���̉摜�n���h�����m��
		handle = (int*)malloc(sizeof(int) * num);
		if (num == 1) {
			handle[0] = LoadGraph(path);
		}
		else {
			LoadDivGraph(path, num, numSliceX, numSliceY, width / numSliceX, height / numSliceY, handle);
		}
	}
	void draw() {
		DrawRotaGraph(x, y, exRate, Angle, handle[index], 1);
	}
	// �C���f�b�N�X���w�肵�ĕ`��
	void draw(int i) {
		DrawRotaGraph(x, y, exRate, Angle, handle[i], 1);
	}
	void setPos(int X, int Y) {
		x = X;
		y = Y;
	}
};