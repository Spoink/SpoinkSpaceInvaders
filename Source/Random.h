#pragma once

class Random
{
	public:
		static int Range(int start, int end);

	private:
		static bool isInitialized;
};

