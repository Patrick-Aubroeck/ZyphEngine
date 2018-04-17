#include "wwindow.h"

WWindow::WWindow(std::string argWindowName) :
	m_windowName(argWindowName),
	m_hInstance(nullptr),
	m_hwnd(nullptr),
	m_fullScreenMode(false),
	m_screenHeight(0),
	m_screenWidth(0)
{
}

WWindow::~WWindow()
{
}

bool WWindow::Initialize(int argScreenWidth = 800, int argScreenHeight = 600, bool argFullScreen = false)
{
	WNDCLASSEX wc;
	DEVMODE dmScreenSettings;
	int posX;
	int posY;

	m_fullScreenMode = argFullScreen;

	// Get the instance of this application.
	m_hInstance = GetModuleHandle(nullptr);

	// Give the application a name.
	LPCSTR applicationName = "Engine";

	LPCSTR windowName = m_windowName.c_str();

	//// Setup the windows class with default settings.
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WWindow::WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = m_hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = applicationName;
	wc.cbSize = sizeof(WNDCLASSEX);

	// Register the window class.
	RegisterClassEx(&wc);

	// Determine the resolution of the clients desktop screen.
	m_screenWidth = GetSystemMetrics(SM_CXSCREEN);
	m_screenHeight = GetSystemMetrics(SM_CYSCREEN);

	// Setup the screen settings depending on whether it is running in full screen or in windowed mode.
	if (m_fullScreenMode)
	{
		// If full screen set the screen to maximum size of the users desktop and 32bit.
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long)m_screenWidth;
		dmScreenSettings.dmPelsHeight = (unsigned long)m_screenHeight;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Change the display settings to full screen.
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

		// Set the position of the window to the top left corner.
		posX = 0;
		posY = 0;
	}
	else
	{
		// If windowed then set it to the values given as param resolution.
		if (argScreenHeight == 0)
		{
			m_screenHeight = 600;
		}
		else
		{
			m_screenHeight = argScreenHeight;
		}
		if (argScreenWidth == 0)
		{
			m_screenWidth = 800;
		}
		else
		{
			m_screenWidth = argScreenWidth;
		}
		// Place the window in the middle of the screen.
		posX = (GetSystemMetrics(SM_CXSCREEN) - m_screenWidth) / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - m_screenHeight) / 2;
	}

	// Create the window with the screen settings and get the handle to it.
	m_hwnd = CreateWindowEx(WS_EX_WINDOWEDGE, applicationName, windowName,
		WS_BORDER | CW_DEFAULT,
		posX, posY, m_screenWidth, m_screenHeight, NULL, NULL, m_hInstance, NULL);

	// Bring the window up on the screen and set it as main focus.
	ShowWindow(m_hwnd, SW_SHOW);
	SetForegroundWindow(m_hwnd);
	SetFocus(m_hwnd);

	// Hide the mouse cursor.
	ShowCursor(false);

	return true;
}

const int WWindow::GetScreenWidth() const
{
	return m_screenWidth;
}

const int WWindow::GetScreenHeight() const
{
	return m_screenHeight;
}

const bool WWindow::GetIsFullScreenModeOn() const
{
	return m_fullScreenMode;
}

const bool WWindow::GetIsForegroundWindow() const
{
	HWND activeHwnd = GetForegroundWindow();
	if (m_hwnd == activeHwnd)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const HWND WWindow::GetWindowHandleInstance() const
{
	return HWND();
}

const std::string WWindow::GetWindowName() const
{
	return std::string();
}

LRESULT WWindow::WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	return DefWindowProc(hwnd, message, wparam, lparam);
}
