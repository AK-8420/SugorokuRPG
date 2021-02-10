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
	double exRate = 1; //拡大率
	double Angle = 0; //回転率

	Graphics(const TCHAR* path, int w, int h, int sx, int sy) {
		width = w;
		height = h;
		numSliceX = sx;
		numSliceY = sy;

		const int num = numSliceX * numSliceY;
		//サイズ分の画像ハンドルを確保
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
	// インデックスを指定して描画
	void draw(int i) {
		DrawRotaGraph(x, y, exRate, Angle, handle[i], 1);
	}
	void setPos(int X, int Y) {
		x = X;
		y = Y;
	}
};