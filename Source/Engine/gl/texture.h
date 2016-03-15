#ifndef TEXTURE_H__
#define TEXTURE_H__

#include "../Util.hpp"
#include <GLES3/gl3.h>
enum ETextureFiltering
{
	TEXTURE_FILTER_MAG_NEAREST = 0, // Nearest criterion for magnification
	TEXTURE_FILTER_MAG_BILINEAR, // Bilinear criterion for magnification
	TEXTURE_FILTER_MIN_NEAREST, // Nearest criterion for minification
	TEXTURE_FILTER_MIN_BILINEAR, // Bilinear criterion for minification
	TEXTURE_FILTER_MIN_NEAREST_MIPMAP, // Nearest criterion for minification, but on closest mipmap
	TEXTURE_FILTER_MIN_BILINEAR_MIPMAP, // Bilinear criterion for minification, but on closest mipmap
	TEXTURE_FILTER_MIN_TRILINEAR, // Bilinear criterion for minification on two closest mipmaps, then averaged
};

/********************************

Class:		CTexture

Purpose:	Wraps OpenGL texture
			object and performs
			their loading.

********************************/

class CTexture
{
public:
	void CreateEmptyTexture(int a_iWidth, int a_iHeight, int a_iBPP, GLenum format);
	void CreateFromData(BYTE* bData, int a_iWidth, int a_iHeight, int a_iBPP, GLenum format, bool bGenerateMipMaps = false);
	
	bool LoadTexture2D(string a_sPath, bool bGenerateMipMaps = false);
	void BindTexture(int iTextureUnit = 0);

	void SetFiltering(int a_tfMagnification, int a_tfMinification);

	void SetSamplerParameter(GLenum parameter, GLenum value);

	int GetMinificationFilter();
	int GetMagnificationFilter();

	int GetWidth();
	int GetHeight();
	int GetBPP();

	uint32 GetTextureID();

	void DeleteTexture();

	bool SaveImage(const unsigned char* ptr, std::string& filename, int flag, int w = 640, int h = 480, int dpp = 24);

	CTexture();
public:
	BYTE* GetPixData(){
		return pdata;
	}
private:

	int iWidth, iHeight, iBPP; // Texture width, height, and bytes per pixel
	uint32 uiTexture; // Texture name
	uint32 uiSampler; // Sampler name
	bool bMipMapsGenerated;

	int tfMinification, tfMagnification;

	string sPath;

	BYTE* pdata;
};

#endif