#pragma once
#include "DxLib.h"

class Graphics {
private:
	int width, height;
	int numSliceX, numSliceY;
	int* handle;

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
};