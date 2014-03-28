#include "FileIO.h"

FILE* FileIO::OpenReadableFile(std::string path)
{
	FILE* filePtr = NULL;
	fopen_s(&filePtr, path.c_str(), "rb");
	return filePtr;
}

FILE* FileIO::OpenWriteableFile(std::string path)
{
	FILE* filePtr = NULL;
	fopen_s(&filePtr, path.c_str(), "wb");
	return filePtr;
}

void FileIO::CloseFile(FILE* file)
{ fclose(file); }

std::string FileIO::ReadStringFromFile(FILE* file, int stringLength)
{ 
	char* charArray = new char[stringLength];
	size_t length = fread(charArray, sizeof(char), stringLength, file);
	charArray[length] = '\0';
	std::string newString = charArray;
	return newString;
}

int FileIO::ReadIntFromFile(FILE* file)
{ 
	int intValue = 0;
	fread(&intValue, sizeof(int), 1, file);
	return intValue;
}

void FileIO::WriteStringToFile(FILE* file, std::string text)
{ fwrite(text.c_str(), sizeof(char), text.length(), file); }

void FileIO::WriteIntToFile(FILE* file, int number)
{ fwrite(&number, sizeof(int), 1, file); }

FileIO::FileIO() {}

FileIO::~FileIO() {}
