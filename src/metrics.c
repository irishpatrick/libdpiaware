#include "metrics.h"

#if defined _WIN32

#include <WinUser.h>
#include <libloaderapi.h>

#elif defined __linux__

#include <Xlib.h>
#include <unistd.h>

#endif

#define REFERENCE_PIXEL_HEIGHT 1080.0

static double scale = 1.0;
static uint32_t resolution_x;
static uint32_t resolution_y;

int dpi_gather_metrics(void)
{

#if defined _WIN32

    resolution_x = GetSystemMetrics(SM_CXSCREEN);
    resolution_y = GetSystemMetrics(SM_CYSCREEN);

#elif defined __linux__

    Display* disp = XOpenDisplay(NULL);
    if (!disp)
    {
        return 1;
    }

    Screen* scrn = DefaultScreenOfDisplay(disp);
    if (!scrn)
    {
        return 2;
    }

    resolution_x = scrn->width;
    resolution_y = scrn->height;

#endif
    
    scale = (double)resolution_y / REFERENCE_PIXEL_HEIGHT;
    if (scale < 1.0)
    {
        scale = 1.0;
    }

    return 0;
}

double dpi_get_monitor_scale(void)
{
    return scale;
}

uint32_t dpi_get_resolution_x(void)
{
    return resolution_x;
}

uint32_t dpi_get_resolution_y(void)
{
    return resolution_y;
}

