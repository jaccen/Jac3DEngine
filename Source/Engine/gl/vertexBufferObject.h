#ifndef VERTEXBUFFEROBJECT_H__
#define VERTEXBUFFEROBJECT_H__


#include "../Util.hpp"
#include <GLES3/gl3.h>
/********************************

Class:		CVertexBufferObject

Purpose:	Wraps OpenGL vertex buffer
			object.

********************************/

class CVertexBufferObject
{
public:
	void CreateVBO(int a_iSize = 0);
	void DeleteVBO();

	void* MapBufferToMemory(int iUsageHint);
	void* MapSubBufferToMemory(int iUsageHint, uint32 uiOffset, uint32 uiLength);
	void UnmapBuffer();

	void BindVBO(int a_iBufferType = GL_ARRAY_BUFFER);
	void UploadDataToGPU(int iUsageHint);
	
	void AddData(void* ptrData, uint32 uiDataSize);

	void* GetDataPointer();
	uint32 GetBufferID();

	CVertexBufferObject();

private:
	uint32 uiBuffer;
	int iSize;
	int iBufferType;
	vector<BYTE> data;

	bool bDataUploaded;
};
#endif