#if defined _WIN32

#include <WinUser.h>
#include <libloaderapi.h>

#elif defined __linux__

#include <Xlib.h>
#include <unistd.h>

#endif

static double scale = 1.0;

void dpi_gather_metrics(void)
{

}

double dpi_get_monitor_scale(void)
{
    return scale;
}

