#ifndef ctrdrv_h
    #define ctrdrv_h
    #define QNTD_DRV 20
    char initCtrDrv(void);
    char callDriver(char drv_id, char func_id, void *parameters);
    char initDriver(char newDriver);

// Drivers conhecidos estáticamente
enum {
    DRV_LED,              /*1st driver*/
    DRV_END /*DRV_END must always be the last*/
};
//the functions to get the drivers should be put in the same order as in the enum
static ptrGetDrv drvGetFunc[DRV_END] = {
    getLedDriver,    /*1st driver*/
};
#endif // ctrdrv_h