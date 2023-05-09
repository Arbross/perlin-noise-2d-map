#pragma once
#include <iostream>
#include <windows.h>

class PerlinNoise
{
public:
	// Print info about generation of perlin noise
	void print();

	// ������� ����� ������������ �� a0 � a1
	// ���� w �� ���� � ����� [0.0, 1.0]
	float lerp(float a, float b, float t);

	// ���������� ��������� ������� �� �������� � ���䳺����� ��������.
	float dotGridGradient(int ix, int iy, float x, float y);

	// O��������� ���� ������ ��� ��������� x, y
	float perlin(float x, float y);
private:
	static const int height = 10;
	static const int width = 10;
};

inline void PerlinNoise::print()
{
	while (true)
	{
		float n1 = rand() % 10;
		n1 /= 10;

		float n2 = rand() % 10;
		n2 /= 10;

		std::cout << "Perlin : " << perlin(n1, n2) << std::endl;
		Sleep(1000);
	}
}

inline float PerlinNoise::lerp(float a, float b, float t)
{
	return (1.0 - t) * a + t * b;
}

inline float PerlinNoise::dotGridGradient(int ix, int iy, float x, float y)
{
	// ���������� �������� ���䳺��� �������
	float Gradient[height][width][2];

	// ���������� ������� ������
	float dx = x - (double)ix;
	float dy = y - (double)iy;

	// ���������� ���������� �������
	return (dx * Gradient[iy][ix][0] + dy * Gradient[iy][ix][1]);
}

inline float PerlinNoise::perlin(float x, float y)
{
	// ���������� ��������� ������ ����
	int x0 = (x > 0.0 ? (int)x : (int)x - 1);
	int x1 = x0 + 1;
	int y0 = (y > 0.0 ? (int)y : (int)y - 1);
	int y1 = y0 + 1;

	// ���������� ��� ������������
	// ����� ����� ����������� ����������� ����� ������ �������
	float sx = x - (double)x0;
	float sy = y - (double)y0;

	// ������������ �� ���䳺�����
	float n0, n1, ix0, ix1, value;
	n0 = dotGridGradient(x0, y0, x, y);
	n1 = dotGridGradient(x1, y0, x, y);
	ix0 = lerp(n0, n1, sx);
	n0 = dotGridGradient(x0, y1, x, y);
	n1 = dotGridGradient(x1, y1, x, y);
	ix1 = lerp(n0, n1, sx);
	value = lerp(ix0, ix1, sy);

	return value;
}
