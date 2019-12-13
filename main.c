
#include "DSP28x_Project.h"
/**
 * main.c
 */
int main(void)
{
    InitSysCtrl();
    DINT;
    InitPieCtrl();
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();

    EALLOW;
    GpioCtrlRegs.GPAMUX1.all = 0x00000000;   // All GPIO
    GpioCtrlRegs.GPAMUX2.all = 0x00000000;   // All GPIO
    GpioCtrlRegs.GPBMUX1.all = 0x00000000;   // All GPIO
    GpioCtrlRegs.GPADIR.all = 0xCFFFFFFF;   // All outputs
    GpioCtrlRegs.GPBDIR.all = 0x0000000F;   // All outputs
    EDIS;
    for(;;)
    {
        GpioDataRegs.GPADAT.all    =0xffffffff; //赋值修改为0xffffffff
        GpioDataRegs.GPBDAT.all    =0xffffffff; //赋值修改为0xffffffff
        DELAY_US(1000000);
        GpioDataRegs.GPADAT.all    =0x0;  //赋值修改为0x0
        GpioDataRegs.GPBDAT.all    =0x0;  //赋值修改为0x0
        DELAY_US(1000000);
    }
}
