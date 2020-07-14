#include "ctrlDrv.h"

static driver* driversLoaded[QNTD_DRV];
static char dLoaded;

char initDriver(char newDriver) {
  char resp = FAIL;

  if(dLoaded < QNTD_DRV) {
    //get driver struct
   driversLoaded[dLoaded] = drvGetFunc[newDriver]();

    //should test if driver was loaded correcly!
    resp=driversLoaded[dLoaded]->init(&newDriver);
    dLoaded++;
  }
  return resp;
}

char callDriver(char drv_id, char func_id, void *p) {
  char i;
  for (i = 0; i < dLoaded; i++) {
    //find the right driver
    if (drv_id == driversLoaded[i]->id) {
      return driversLoaded[i]->funcoes[func_id](p);

    }
  }
  return DRV_FUNC_NOT_FOUND;
}