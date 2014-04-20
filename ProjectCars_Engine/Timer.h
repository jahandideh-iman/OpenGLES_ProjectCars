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

	void RegisterTimer(GameObject* _object, CallBack _callBack, float _durationInSec );
	void UnRegisterTimer(GameObject* _object, CallBack _callBack);

private:
	void CheckTimers(float dt);
	void CheckTimer(int registerIndex, float dt);
private:
	TimerRegisterContainer timerRegisters;

};

