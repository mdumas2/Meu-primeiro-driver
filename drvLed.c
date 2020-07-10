#include "drvLed.h"
static driver ledDriver;
static DriverFunctionType led_funcs[LED_END];

char initLed(void *parameters)
{
    ledDriver.id = (char)parameters;
    return SUCCESS;
}
char ledOn(void *parameters)
{
    switch ((char)parameters)
    {
    case LED1:
        HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, SET);
        break;
    case LED2:
        HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, SET);
        break;
    default:
        break;
    }
    return SUCCESS;
}
char ledOff(void *parameters)
{
    switch ((char)parameters)
    {
    case LED1:
        HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, RESET);
        break;
    case LED2:
        HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, RESET);
        break;
    default:
        break;
    }
    return SUCCESS;
}
char ledBlink(void *parameters)
{
    switch ((char)parameters)
    {
    case LED1:
        HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
        break;
    case LED2:
        HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
        break;
    default:
        break;
    }
    return SUCCESS;
}
driver *getLedDriver(void)
{
    ledDriver.init = initLed;
    led_funcs[LED_ON] = ledOn;
    led_funcs[LED_OFF] = ledOff;
    led_funcs[LED_BLK] = ledBlink;
    ledDriver.funcoes = led_funcs;
    return &ledDriver;
}