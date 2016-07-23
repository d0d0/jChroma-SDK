#ifndef __STRUCTS
#define __STRUCTS
#pragma once


typedef struct MousematColorStruct {
	int position;
	int r;
	int g;
	int b;
} MousematColorStruct;

typedef struct BreathingEffectStruct {
	int type;
	int color1R;
	int color1G;
	int color1B;
	int color2R;
	int color2G;
	int color2B;
} BreathingEffectStruct;

#endif