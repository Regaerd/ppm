#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include "Pixel.h"

class Image{
public:
	int w, h;
	vector<Pixel>p;
	
	Pixel get(int x, int y){return p[(x*h)+y];}
	Pixel *get_p(int x, int y){return &p[(x*h)+y];}
	void setRGBA(int x, int y, double color){p[(x*h)+y].r=color; p[(x*h)+y].g=color; p[(x*h)+y].b=color; p[(x*h)+y].a=color;}
	void setRGB(int x, int y, double color){p[(x*h)+y].r=color; p[(x*h)+y].g=color; p[(x*h)+y].b=color;}
	void setA(int x, int y, double color){p[(x*h)+y].a=color;}
	void push_back(Pixel newP){p.push_back(newP);}
};

#endif
