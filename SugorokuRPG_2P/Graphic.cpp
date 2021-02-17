#include "DxLib.h"
#include "Graphic.h"

Graphics::Graphics(const TCHAR* path, int w, int h, int sx, int sy) {
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
void Graphics::draw() {
	DrawRotaGraph(x, y, exRate, Angle, handle[index], 1);
}
void Graphics::draw(int Index) {
	DrawRotaGraph(x, y, exRate, Angle, handle[Index], 1);
}
void Graphics::setPos(int X, int Y) {
	x = X;
	y = Y;
}