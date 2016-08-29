#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include "shared/rendering/Color.h"

using namespace std;

class Image {
public:
	vector<vector<Color>> pixels;

	Image(unsigned long width, unsigned long height);
	Image(vector<vector<Color>> pixels);

	void saveToFile(const char * filename, int dpi);
};