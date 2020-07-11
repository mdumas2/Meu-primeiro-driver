#ifndef drvLed_h
#define drvLed_h
#include "drvDefinitions.h"
//lista de funções do driver
enum
{
    LED_ON,
    LED_OFF,
    LED_BLK,
    LED_END
};

//função de acesso ao driver
driver *getLedDriver(void);

#endif // drvLed_h
