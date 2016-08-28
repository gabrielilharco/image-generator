#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include "shared/rendering/Color.h"

using namespace std;

class Image {
public:
	vector<vector<Color> > pixels;

	Image (unsigned long , unsigned long );
	Image (vector<vector<Color> >);

	void saveToFile(const char * , int);
};