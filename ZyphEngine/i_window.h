#ifndef _I_WINDOW_H_
#define _I_WINDOW_H_

class I_Window
{
public:
	virtual const int GetScreenHeight() const = 0;
	virtual const int GetScreenWidth() const = 0;
	virtual const bool GetIsFullScreenModeOn() const = 0;
	virtual const bool GetIsForegroundWindow() const = 0;
	virtual const std::string GetWindowName() const = 0;
};

#endif