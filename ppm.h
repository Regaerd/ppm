#ifndef PPM_H
#define PPM_H

#include <sstream>
#include <fstream>
#include <vector>
#include <string>
		
bool save_ppm(const char *filename, Image img){return save_ppm(filename, img, false);}
bool save_ppm(const char *filename, Image img, bool hasAlpha){
bool load_ppm(const char *filename, Image &img){
		
bool load_ppm(const char *filename, Image &img){
	ifstream in(filename, ios::in);
	if(!in){return false;}

	int c, offset = 2;
	Pixel pixel;

	for (int f=0; f<offset; f++){in.ignore(256,'\n');}
	in>>c; img.w = c;
	in>>c; img.h = c;
	for (int f=0; f<offset; f++){in.ignore(256,'\n');}

	for (int j=0; j<img.w; j++) {
		for (int i=0; i<img.h; i++) {
			in>>c; pixel.r = (GLubyte)c;
			in>>c; pixel.g = (GLubyte)c;
			in>>c; pixel.b = (GLubyte)c;
			       pixel.a = (GLubyte)1;
			img.push_back(pixel); 	
	    }
	}
	string line; in>>line;
	if (line == "#alpha"){
		for (int x=0; x<img.w; x++) {
			for (int y=0; y<img.h; y++) {
				in>>c; img.setA(x,y,(GLubyte)c);	
			}
		}
	}
	in.close();
	return true;
}

bool save_ppm(const char *filename, Image img){return save_ppm(filename, img, false);}
bool save_ppm(const char *filename, Image img, bool hasAlpha){
	ofstream out(filename);
	if (!out.is_open()){cout<<"out failed"<<endl; return false;}
	out<<"P3"<<endl;
	out<<"# CREATOR: https://github.com/Regaerd/ppm"<<endl;
	out<<img.w<<" "<<img.h<<endl;
	out<<"255"<<endl;
	Pixel *p;
	int colCount=0;
	for (int x=0; x<img.w; x++){
		for (int y=0; y<img.h; y++){
			++colCount;
			p = img.get_p(x,y);
			out<<(int)p->r<<" ";
			out<<(int)p->g<<" ";
			out<<(int)p->b;
			if (colCount == 5){out<<endl; colCount=0;}
			else{out<<"\t";}
		}
		colCount=0;
		out<<endl<<endl;
	}
	if (hasAlpha){
		out<<"#alpha"<<endl;
		for (int x=0; x<img.w; x++){
			for (int y=0; y<img.h; y++){
				out<<(int)img.get(x, y).a<<endl;
			}
		}				
	}
	out.close();
	return true;		
}
		
#endif
