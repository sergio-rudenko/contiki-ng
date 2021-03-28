#ifndef CONTIKI_CONF_H
#define CONTIKI_CONF_H

/* Possibly standard includes here, e.g. stdint.h */
/*---------------------------------------------------------------------------*/
/* Include Project Specific conf */
#ifdef PROJECT_CONF_PATH
#include PROJECT_CONF_PATH
#endif /* PROJECT_CONF_PATH */
/*---------------------------------------------------------------------------*/
#include "nucleo-def.h"
#include "stm32f091-def.h"
/*---------------------------------------------------------------------------*/
/* 
 * All user configuration to go here
 */
/*---------------------------------------------------------------------------*/
/* Include CPU-related configuration */
#include "stm32f091-conf.h"
/*---------------------------------------------------------------------------*/
#endif /* CONTIKI_CONF_H */
