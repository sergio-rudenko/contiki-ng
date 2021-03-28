/* Includes ------------------------------------------------------------------*/
#include "clock.h"
#include "Core/Inc/tim.h"

#define CLOCK_TIMER htim6

static volatile clock_time_t current_clock = 0;
static volatile unsigned long current_seconds = 0;
static unsigned int second_countdown = CLOCK_SECOND;

/*---------------------------------------------------------------------------*/
/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == CLOCK_TIMER.Instance)
    {
        current_clock++;
        if (etimer_pending() && etimer_next_expiration_time() <= current_clock)
        {
            etimer_request_poll();
            /* printf("%d,%d\n", clock_time(),etimer_next_expiration_time  	()); */
        }

        if (--second_countdown == 0)
        {
            current_seconds++;
            second_countdown = CLOCK_SECOND;
        }
    }
}
/*---------------------------------------------------------------------------*/
void clock_init()
{
    const uint16_t psc = (uint16_t)(SystemCoreClock / 8 / CLOCK_SECOND) - 1U;
    const uint16_t prd = (uint16_t)(CLOCK_SECOND)-1U;

    /* Update timer prescaler and period */
    CLOCK_TIMER.Init.Prescaler = psc;
    CLOCK_TIMER.Init.Period = prd;

    /* Apply and start */
    if (HAL_TIM_Base_Init(&CLOCK_TIMER) != HAL_OK ||
        HAL_TIM_Base_Start_IT(&CLOCK_TIMER) != HAL_OK)
    {
        Error_Handler();
    }
}
/*---------------------------------------------------------------------------*/
clock_time_t clock_time(void)
{
    return current_clock;
}
/*---------------------------------------------------------------------------*/
unsigned long clock_seconds(void)
{
    return current_seconds;
}
/*---------------------------------------------------------------------------*/
