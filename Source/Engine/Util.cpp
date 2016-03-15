#include "Util.hpp"

#include <iostream>
#include <fstream>
//#include "gl/glew.h"
std::string GetFileContent(const std::string& path) {
	std::ifstream fin(path);
	if (!fin) {
		std::cerr << "Open file failed: " << path << std::endl;
		return nullptr;
	}

	std::string content;
	std::string line;
	while (fin.good()) {
		std::getline(fin, line);
		content += line + '\n';
	}

	return std::move(content);
}

GPUTimer::GPUTimer() : u_numQueries(0), u_queryFrame(0), f_time(0), b_activeQuery(false)
{
	Reset();
}

GPUTimer::~GPUTimer()
{
	if (!v_queryPool.empty())
	{
		//glDeleteQueries((uint32)v_queryPool.size(), &v_queryPool[0]);
	}
	
}

void GPUTimer::BeginQuery(uint32 frameID)
{

}

void GPUTimer::EndQuery()
{

}

bool GPUTimer::UpdateResults()
{
	return true;
}

void GPUTimer::Reset()
{

}
