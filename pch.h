#pragma once

#pragma comment(lib, "es_util")
#pragma comment(lib, "libEGL")
#pragma comment(lib, "libGLESv2")

#include <Common/esUtil.h>

#include <iostream>
#include <fstream>
#include <algorithm>
#include <memory>
#include <vector>
#include <map>

inline unsigned long GetFileLength(std::ifstream& file)
{
	using namespace std;

	if (!file.good()) return 0;

	unsigned long pos = file.tellg();
	file.seekg(0, ios::end);
	unsigned long len = file.tellg();
	file.seekg(ios::beg);

	return len;
}