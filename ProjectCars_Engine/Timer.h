#pragma once
#include "GameObject.h"

struct TimerRegisterInfo
{
	CallBackInfo callBackInfo;
	
	double elapsedTime;
	double duration;
};
typedef std::vector<TimerRegisterInfo> TimerRegisterContainer;

class Timer :
	public GameObject
{
public:
	Timer();
	~Timer();

	void Update(float dt) override;

	void RegisterTimer(GameObject* _object, inputCallBack _callBack, float _durationInSec );

private:
	void CheckTimers(float dt);
	void CheckTimer(int registerIndex, float dt);
private:
	TimerRegisterContainer timerRegisters;

};

