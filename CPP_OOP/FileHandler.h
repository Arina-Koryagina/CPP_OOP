#pragma once

#include"String.h"

class File
{
	String path;

public:
	File(const char* p) : path(p) {}

	virtual void Display(const char* path);
};

class ASCIIFile : public File
{

};

class BinFile : public File
{

};