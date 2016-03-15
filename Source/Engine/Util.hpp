#ifndef UTIL_HPP
#define UTIL_HPP


/*#include <gl/glew.h>*/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Shortcuts for common types
typedef unsigned char BYTE;
typedef signed char int8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;

std::string GetFileContent(const std::string& path);


class GPUTimer{
public:
	GPUTimer();
	~GPUTimer();

	void BeginQuery(uint32 frameID);
	void EndQuery();

	bool UpdateResults();

	void Reset();
	float GetTimeMS() { return f_time; }

private:

	std::vector< uint32> v_queryPool;
	uint32               u_numQueries;
	uint32               u_queryFrame;
	float                f_time;
	bool                 b_activeQuery;
};

#endif // UTIL_HPP