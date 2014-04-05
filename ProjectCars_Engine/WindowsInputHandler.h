#pragma once

#include "GameObject.h"
#include <unordered_map>
#include "Utilities.h"

#define KEYSCOUT 256



enum EInputKey
{
	Key_None, Key_W, Key_S, Key_A, Key_D, Key_Left, Key_Right, Key_Up, Key_Down
};



typedef std::vector<CallBackInfo> CallBackContainer;
typedef std::unordered_map<EInputKey, CallBackContainer  >  RegisterContainer;
typedef std::unordered_map<BYTE, EInputKey> KeyMap;

class WindowsInputHandler
{
public:
	WindowsInputHandler();
	~WindowsInputHandler();

	void Update(float dt);

	void RegisterOnPressKey(GameObject* _object, EInputKey _key, inputCallBack _callBack);
	void RegisterOnReleaseKey(GameObject* _object, EInputKey _key, inputCallBack _callBack);
private:
	void OnPressCallBackForKey(EInputKey _key);
	void OnReleaseCallBackForKey(EInputKey _key);

	void InitialKeyMap();

	EInputKey ConvertToKey(BYTE _keycode);
private:
	RegisterContainer onPressContainer;
	RegisterContainer onReleaseContainer;

	KeyMap keyMap;

	BYTE keysState[KEYSCOUT];
	BYTE lastFrameKeysState[KEYSCOUT];
	BYTE keyChanges[KEYSCOUT];

	BYTE pressedKeysState[KEYSCOUT];
	BYTE releasedKeysState[KEYSCOUT];
};

