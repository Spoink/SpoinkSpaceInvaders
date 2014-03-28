#pragma once

#include <string>

class FileIO
{
	public:
		static FILE* OpenReadableFile(std::string path);
		static FILE* OpenWriteableFile(std::string path);
		static void CloseFile(FILE* file);

		static std::string ReadStringFromFile(FILE* file, int stringLength);
		static int ReadIntFromFile(FILE* file);

		static void WriteStringToFile(FILE* file, std::string text);
		static void WriteIntToFile(FILE* file, int number);

	private:
		FileIO();
		~FileIO();
};

