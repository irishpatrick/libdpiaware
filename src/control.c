#include "control.h"

#ifdef _WIN32

#include <WinUser.h>

#endif

void dpi_set_proc_aware(void)
{

#ifdef _WIN32

    SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE);

#elif defined __linux__

    // do nothing

#endif

}