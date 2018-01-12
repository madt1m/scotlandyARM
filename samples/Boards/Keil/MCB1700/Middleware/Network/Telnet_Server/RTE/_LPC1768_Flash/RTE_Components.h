
/*
 * Auto generated Run-Time-Environment Component Configuration File
 *      *** Do not modify ! ***
 *
 * Project: 'Telnet_Server' 
 * Target:  'LPC1768 Flash' 
 */

#ifndef RTE_COMPONENTS_H
#define RTE_COMPONENTS_H


/*
 * Define the Device Header File: 
 */
#define CMSIS_device_header "LPC17xx.h"

#define RTE_CMSIS_RTOS                  /* CMSIS-RTOS */
        #define RTE_CMSIS_RTOS_RTX              /* CMSIS-RTOS Keil RTX */
#define RTE_DEVICE_STARTUP_LPC17XX      /* Device Startup for NXP17XX */
#define RTE_Drivers_ETH_MAC0            /* Driver ETH_MAC0 */
#define RTE_Drivers_PHY_DP83848C        /* Driver PHY DP83848C */
#define RTE_Drivers_SPI0                /* Driver SPI0 */
        #define RTE_Drivers_SPI1                /* Driver SPI1 */
#define RTE_Network_Core                /* Network Core */
          #define RTE_Network_Release             /* Network Release Version */
#define RTE_Network_Interface_ETH_0     /* Network Interface ETH 0 */
#define RTE_Network_Socket_TCP          /* Network Socket TCP */
#define RTE_Network_Socket_UDP          /* Network Socket UDP */
#define RTE_Network_Telnet_Server       /* Network Telnet Server */

#endif /* RTE_COMPONENTS_H */
