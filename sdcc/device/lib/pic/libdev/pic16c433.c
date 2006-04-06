/* Register definitions for pic16c433.
 * This file was automatically generated by:
 *   inc2h.pl V1.6
 *   Copyright (c) 2002, Kevin L. Pauba, All Rights Reserved
 */
#include <pic16c433.h>

data __at (INDF_ADDR) volatile char      INDF;
sfr  __at (TMR0_ADDR)                    TMR0;
data __at (PCL_ADDR) volatile char       PCL;
sfr  __at (STATUS_ADDR)                  STATUS;
sfr  __at (FSR_ADDR)                     FSR;
sfr  __at (GPIO_ADDR)                    GPIO;
sfr  __at (PCLATH_ADDR)                  PCLATH;
sfr  __at (INTCON_ADDR)                  INTCON;
sfr  __at (PIR1_ADDR)                    PIR1;
sfr  __at (ADRES_ADDR)                   ADRES;
sfr  __at (ADCON0_ADDR)                  ADCON0;
sfr  __at (OPTION_REG_ADDR)              OPTION_REG;
sfr  __at (TRISIO_ADDR)                  TRISIO;
sfr  __at (PIE1_ADDR)                    PIE1;
sfr  __at (PCON_ADDR)                    PCON;
sfr  __at (OSCCAL_ADDR)                  OSCCAL;
sfr  __at (ADCON1_ADDR)                  ADCON1;

// 
// bitfield definitions
// 
volatile __ADCON0_bits_t __at(ADCON0_ADDR) ADCON0_bits;
volatile __ADCON1_bits_t __at(ADCON1_ADDR) ADCON1_bits;
volatile __INTCON_bits_t __at(INTCON_ADDR) INTCON_bits;
volatile __OPTION_REG_bits_t __at(OPTION_REG_ADDR) OPTION_REG_bits;
volatile __OSCCAL_bits_t __at(OSCCAL_ADDR) OSCCAL_bits;
volatile __PCON_bits_t __at(PCON_ADDR) PCON_bits;
volatile __PIE1_bits_t __at(PIE1_ADDR) PIE1_bits;
volatile __PIR1_bits_t __at(PIR1_ADDR) PIR1_bits;
volatile __STATUS_bits_t __at(STATUS_ADDR) STATUS_bits;

