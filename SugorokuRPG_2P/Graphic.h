#pragma once

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

	Graphics(const TCHAR* path, int w, int h, int sx, int sy);
	void draw();
	void draw(int Index);//インデックスを指定して描画
	void setPos(int X, int Y);
};