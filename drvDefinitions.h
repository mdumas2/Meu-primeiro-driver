#ifndef drvDefinitions

#define drvDefinitions

typedef char (*DriverFunctionType)(void *parameters);

typedef struct
{

    char id;

    DriverFunctionType *funcoes;

    DriverFunctionType init;

} driver;

typedef driver *(*ptrGetDrv)(void);

#endif