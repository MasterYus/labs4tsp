#pragma once

class Figure {

private:
	float x1, x2, x3, x4;
	float y1, y2, y3, y4;
	
	float a;	// AB
	float b;	// BC
	float c;	// CD
	float d;	// DA
	float P;
	float S;

	float const PI_M_DELTA = 3.1415925;
	float const PI_P_DELTA  = 3.1415927;

public:
	Figure(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
	void show();
	float square();
	bool is_prug();
	bool is_rectangle();
	bool is_square();
	bool is_romb();
	bool is_in_circle();
	bool is_out_circle();
};
