#pragma once

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

	Graphics(const TCHAR* path, int w, int h, int sx, int sy);
	void draw();
	void draw(int Index);//�C���f�b�N�X���w�肵�ĕ`��
	void setPos(int X, int Y);
};