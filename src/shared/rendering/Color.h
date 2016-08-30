#ifndef _COLOR_H
#define _COLOR_H

class Color {
	public:
        double r, g, b;

		Color ();
        Color (double, double, double);

	    Color operator * (double);
        Color operator * (Color);
        Color operator + (Color);
		Color operator / (double);
};

#endif