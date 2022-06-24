#pragma once
#include <chrono>

class Timer
{
private:
	bool mStopped{};
	std::chrono::duration<float> mDeltaTime{};
	std::chrono::time_point<std::chrono::steady_clock> mBaseTime{};
	std::chrono::time_point<std::chrono::steady_clock> mPausedTime{};
	std::chrono::time_point<std::chrono::steady_clock> mStopTime{};
	std::chrono::time_point<std::chrono::steady_clock> mPreviousTime{};
	std::chrono::time_point<std::chrono::steady_clock> mCurrentTime{};
public:
	Timer();
	~Timer();
	void Tick();
	void Reset();
	void Start();
	void Stop();
	std::chrono::duration<float> DeltaTime();
	float TotalTime();
	uint32_t RunTime();
};
