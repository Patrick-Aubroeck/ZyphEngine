#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <string>
#include <windows.h>

#include "i_window.h"

class WWindow : I_Window
{
private:
	bool m_fullScreenMode;
	int m_screenWidth;
	int m_screenHeight;
	HWND m_hwnd;
	std::string m_windowName;
	HINSTANCE m_hInstance;

public:
	WWindow(std::string windowName);
	virtual ~WWindow();

	bool Initialize(int screenWidth, int screenHeight, bool fullScreen);

	const int GetScreenWidth() const; 
	const int GetScreenHeight() const;
	const bool GetIsFullScreenModeOn() const; 
	const bool GetIsForegroundWindow() const;  
	const HWND GetWindowHandleInstance() const; 
	const std::string GetWindowName() const; 

protected:
private:
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam); // ?? maybe not static member ?? 
};

#endif
