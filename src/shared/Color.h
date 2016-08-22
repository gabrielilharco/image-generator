#ifndef _COLOR_H
#define _COLOR_H

class Color {
	public:
        unsigned char r, g, b;
		double a;
		
		Color ();
		Color (int, int, int, double);
        Color (unsigned char, unsigned char, unsigned char, double);
};

#endif