#include "Windows.h"
#include "windowsx.h"
#include "tchar.h"

#include <ctime>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	WCHAR className[] = L"FirstWindow";

	WNDCLASSEX wndClass;
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wndClass.hInstance = hInstance;
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hIconSm = NULL;
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = className;

	wndClass.lpfnWndProc = WindowProc;

	//task1
	/*WCHAR name[] = L"My name is Michalis";
	WCHAR LastName[] = L"My lastname is Fastakovskiy";
	WCHAR age[] = L"My age is 19 y o";*/

	

	if (!RegisterClassEx(&wndClass)) {
		return 0;
	}

	HWND hWnd = CreateWindowEx(
		0,
		className,
		L"My first window",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, //x,y
		CW_USEDEFAULT, CW_USEDEFAULT, //width, height
		NULL,
		NULL,
		hInstance,
		NULL
	);

	//task1
	/*MessageBox(0, name, L"NameWindow", MB_OK | MB_ICONINFORMATION);
	MessageBox(0, LastName, L"LastNameWindow", MB_OK | MB_ICONINFORMATION);
	MessageBox(0, age, L"AgeWindow", MB_OK | MB_ICONINFORMATION);
	int symbls = (wcslen(name) + wcslen(LastName) + wcslen(age))/3;
	
	TCHAR symblsStr[16];
	_stprintf_s(symblsStr, _T("%d"), symbls);
	MessageBox(0, symblsStr, L"RESULT", MB_OK | MB_ICONINFORMATION);*/


	//task2
      srand(time(nullptr));
	 
	  int counter;
	  int result;
	  TCHAR CounterSTR[16];
	  int res1;
	  do {
		  counter = 0;
		  do {
			  counter++;
			  int random = rand() % 100 + 1;
			  TCHAR RandomSTR[16];
			  _stprintf_s(RandomSTR, _T("%d"), random);
			  result = MessageBox(0, RandomSTR, L"Its your value?", MB_OKCANCEL | MB_ICONQUESTION);
		  } while (result != IDOK);
		  if (result == IDOK) {
			  _stprintf_s(CounterSTR, _T("%d"), counter);
			  TCHAR Message[256];
			  _tcscpy_s(Message, _T("Your try is "));
			  _tcscat_s(Message, CounterSTR);
			 res1= MessageBox(0, L"Continue?", Message, MB_OKCANCEL | MB_ICONQUESTION);
		  }
	  } while (res1 == IDOK);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0); //WM_QUIT
		break;


	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}
