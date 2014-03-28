#ifndef TIME_H
#define TIME_H

class Time
{
	public:
		static void Initialize();
		static void UpdateDeltaTime();
		static float GetTime();
		static int GetRealTime();
		static float GetDeltaTime();

	private:
		static float oldTime;
		static float deltaTime;
};

#endif TIME_H