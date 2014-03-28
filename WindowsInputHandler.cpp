#include "WindowsInputHandler.h"
#include <Windows.h>

WindowsInputHandler::WindowsInputHandler()
{
	for (int i = 0; i < KEYSCOUT; ++i)
		lastFrameKeysState[i] = 0;
	InitialKeyMap();
}



WindowsInputHandler::~WindowsInputHandler()
{
}

void WindowsInputHandler::InitialKeyMap()
{
	keyMap[VK_LEFT] = Key_Left;
	keyMap[VK_RIGHT] = Key_Right;
	keyMap['A'] = Key_A;
	keyMap['D'] = Key_D;
}

void WindowsInputHandler::Update(float dt)
{
	//GetKeyState(0);
	if (GetKeyboardState(keysState))
	{
		for (int i = 0; i < KEYSCOUT; ++i)
		{
			if (keysState[i] != lastFrameKeysState[i])
			{
				if (keysState[i] & 128)
					OnPressCallBackForKey(ConvertToKey(i));
				else
					OnReleaseCallBackForKey(ConvertToKey(i));

				lastFrameKeysState[i] = keysState[i];
			}
			
		}
	}
}

void WindowsInputHandler::RegisterOnPressKey(GameObject* _object, EInputKey _key, inputCallBack _callBack)
{
	onPressContainer[_key].push_back(CallBackInfo(_object,_callBack));
}

void WindowsInputHandler::RegisterOnReleaseKey(GameObject* _object, EInputKey _key, inputCallBack _callBack)
{
	onReleaseContainer[_key].push_back(CallBackInfo(_object, _callBack));
}

void WindowsInputHandler::OnPressCallBackForKey(EInputKey _key)
{
	if (_key == Key_None)
		return;

	CallBackContainer callBacks = onPressContainer[_key];

	for (int i = 0; i < callBacks.size(); ++i)
		CALL_MEMBER_FN(callBacks[i].first, callBacks[i].second)();
}

void WindowsInputHandler::OnReleaseCallBackForKey(EInputKey _key)
{

	if (_key == Key_None) 
		return;

	CallBackContainer callBacks = onReleaseContainer[_key];

	for (int i = 0; i < callBacks.size(); ++i)
		CALL_MEMBER_FN(callBacks[i].first, callBacks[i].second)();

}

EInputKey WindowsInputHandler::ConvertToKey(BYTE _keycode)
{
	return keyMap[_keycode];
}