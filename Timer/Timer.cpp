#include "Timer.h"

Timer::Timer()
{}

Timer::~Timer()
{}

void Timer::Tick()
{
    if (mStopped)
    {
        mDeltaTime = std::chrono::duration<float>();
        return;
    }

    mCurrentTime = std::chrono::steady_clock::now();

    mDeltaTime = std::chrono::duration<float>(mCurrentTime - mPreviousTime);

    mPreviousTime = mCurrentTime;
}

void Timer::Reset()
{
    mBaseTime = std::chrono::steady_clock::now();
    mPreviousTime = std::chrono::steady_clock::now();
}

void Timer::Start()
{
    auto startTime = std::chrono::steady_clock::now();

    if (mStopped)
    {
        mPreviousTime = startTime;
        mPausedTime += (startTime - mStopTime);
        mStopped = false;
    }
}

void Timer::Stop()
{
    if (!mStopped)
    {
        mStopTime = std::chrono::steady_clock::now();
        mStopped = true;
    }
}

std::chrono::duration<float> Timer::DeltaTime()
{
    return mDeltaTime;
}

float Timer::TotalTime()
{
    if (mStopped)
    {
        return std::chrono::duration<float>(mStopTime - mPausedTime - mBaseTime.time_since_epoch()).count();
    }
    else
    {
        return std::chrono::duration<float>(mCurrentTime - mPausedTime - mBaseTime.time_since_epoch()).count();
    }
}

uint32_t Timer::RunTime()
{
    // if (mStopped)
    // {
    //     return std::chrono::duration<float>(mStopTime - mPausedTime - mBaseTime.time_since_epoch());
    // }
    // else
    // {
    return uint32_t(std::chrono::duration<float>(mCurrentTime - mBaseTime).count());
    // }
}
