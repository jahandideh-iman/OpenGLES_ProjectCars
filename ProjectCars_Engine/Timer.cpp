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

void Timer::RegisterTimer(GameObject* _object, inputCallBack _callBack, float _durationInSec)
{
	TimerRegisterInfo registerInfo;

	registerInfo.elapsedTime = 0.0;
	registerInfo.duration = _durationInSec;

	registerInfo.callBackInfo.first = _object;
	registerInfo.callBackInfo.second = _callBack;

	timerRegisters.push_back(registerInfo);


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
		CALL_MEMBER_FN(timerRegister.callBackInfo.first, timerRegister.callBackInfo.second);
		timerRegisters.erase(timerRegisters.begin() + registerIndex);
	}

	
}

