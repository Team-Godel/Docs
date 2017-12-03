#include <windows.h>
#include <tchar.h>

HINSTANCE instance;

LRESULT CALLBACK windowsProcedure(HWND, UINT, WPARAM, LPARAM);

int WinMain(HINSTANCE handlerInstance,
                     HINSTANCE handlerPreviousInstance,
                     LPSTR commandLine,
                     int commandLineShow)
{
    // Here is populated the WNDCLASSEX structure, just for make the same window
    WNDCLASSEX window;
    window.cbSize = sizeof(WNDCLASSEX);
    window.style = CS_HREDRAW | CS_VREDRAW;
    window.lpfnWndProc = windowsProcedure;
    window.cbClsExtra = 0;
    window.cbWndExtra = 0;
    window.hInstance = handlerInstance;
    window.hIcon = LoadIcon(NULL, IDC_ARROW);
    window.hCursor = LoadCursor(NULL, IDC_ARROW);
    window.hbrBackground = (HBRUSH)(COLOR_WINDOW);
    window.lpszMenuName = NULL;
    window.lpszClassName = "windowClass";
    window.hIconSm = LoadIcon(NULL, IDC_ARROW);

    if(!RegisterClassEx(&window))
    {
        MessageBox(NULL,"Register class failed!","Window test!",0);
        return 1;
    }

    HWND handler = CreateWindow("windowClass",
                                "This is my Title",
                                WS_OVERLAPPEDWINDOW,
                                CW_USEDEFAULT,
                                CW_USEDEFAULT,
                                500,
                                100,
                                NULL,
                                NULL,
                                handlerInstance,
                                NULL);

    if(!handler)
    {
        MessageBox(NULL,
                "Failed to create the window",
                "Is just it, the window could not be created",
                0);
        return 1;
    }

    ShowWindow(handler, commandLineShow);
    UpdateWindow(handler);

    MSG message;

    while (GetMessage(&message, NULL, 0, 0))  // Recovers the events of all the windows of the instance in "message"
    {
        TranslateMessage(&message);  // Traduction of the event
        DispatchMessage(&message);   // Send the message to the window
    }
};

LRESULT CALLBACK windowsProcedure(HWND handler,
                                  UINT message,
                                  WPARAM wParam,
                                  LPARAM lParam)
{
    switch (message)   // Events
    {
        case WM_CREATE:
            HWND button = CreateWindow(TEXT("button"),
                                       TEXT("LOL"),
                                       WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                       0, 0, 100, 20,
                                       handler,
                                       (HMENU) button,
                                       NULL,
                                       NULL);
            SetMenu(handler, LoadMenu(instance, "ID_MENU"));  // Associate the menu with the window
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);   // Exit the window
            return 0;
        default:
            return DefWindowProc(handler, message, wParam, lParam);   // If there is no message, return the windows default procedur
    }
};

