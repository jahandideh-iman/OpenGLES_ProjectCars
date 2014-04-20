#include "Timer.h"


Timer::Timer() : GameObject()
{
}


Timer::~Timer()
{
}

void Timer::Update(float dt)
{
	GameObject::Update(dt);
	CheckTimers(dt);
}

void Timer::RegisterTimer(GameObject* _object, CallBack _callBack, float _durationInSec)
{
	TimerRegisterInfo registerInfo;

	registerInfo.elapsedTime = 0.0;
	registerInfo.duration = _durationInSec;

	registerInfo.callBackInfo.first = _object;
	registerInfo.callBackInfo.second = _callBack;

	timerRegisters.push_back(registerInfo);


}

void Timer::UnRegisterTimer(GameObject* _object, CallBack _callBack)
{
	for (int i = 0; i < timerRegisters.size(); ++i)
	{
		if (timerRegisters[i].callBackInfo.first == _object \
			&& timerRegisters[i].callBackInfo.second == _callBack)
		{
			timerRegisters.erase(timerRegisters.begin() + i);
			break;
		}
	}
}
void Timer::CheckTimers(float dt)
{
	for (int i = 0; i < timerRegisters.size(); ++i)
		CheckTimer(i,dt);
}

void Timer::CheckTimer(int registerIndex, float dt)
{
	TimerRegisterInfo& timerRegister = timerRegisters[registerIndex];
	timerRegister.elapsedTime += dt;
	if (timerRegister.elapsedTime >= timerRegister.duration)
	{
		CALL_MEMBER_FN(timerRegister.callBackInfo.first, timerRegister.callBackInfo.second)();
		timerRegisters.erase(timerRegisters.begin() + registerIndex);
	}
}

