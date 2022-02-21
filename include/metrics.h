#ifndef METRICS_H
#define METRICS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

int dpi_gather_metrics(void);
double dpi_get_monitor_scale(void);
uint32_t dpi_get_resolution_x(void);
uint32_t dpi_get_resolution_y(void);

#ifdef __cplusplus
}
#endif

#endif /* METRICS_H */

