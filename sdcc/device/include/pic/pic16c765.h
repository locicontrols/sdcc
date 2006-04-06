//
// Register Declarations for Microchip 16C765 Processor
//
//
// This header file was automatically generated by:
//
//	inc2h.pl V1.6
//
//	Copyright (c) 2002, Kevin L. Pauba, All Rights Reserved
//
//	SDCC is licensed under the GNU Public license (GPL) v2.  Note that
//	this license covers the code to the compiler and other executables,
//	but explicitly does not cover any code or objects generated by sdcc.
//	We have not yet decided on a license for the run time libraries, but
//	it will not put any requirements on code linked against it. See:
// 
//	http://www.gnu.org/copyleft/gpl/html
//
//	See http://sdcc.sourceforge.net/ for the latest information on sdcc.
//
// 
#ifndef P16C765_H
#define P16C765_H

//
// Register addresses.
//
#define INDF_ADDR	0x0000
#define TMR0_ADDR	0x0001
#define PCL_ADDR	0x0002
#define STATUS_ADDR	0x0003
#define FSR_ADDR	0x0004
#define PORTA_ADDR	0x0005
#define PORTB_ADDR	0x0006
#define PORTC_ADDR	0x0007
#define PORTD_ADDR	0x0008
#define PORTE_ADDR	0x0009
#define PCLATH_ADDR	0x000A
#define INTCON_ADDR	0x000B
#define PIR1_ADDR	0x000C
#define PIR2_ADDR	0x000D
#define TMR1L_ADDR	0x000E
#define TMR1H_ADDR	0x000F
#define T1CON_ADDR	0x0010
#define TMR2_ADDR	0x0011
#define T2CON_ADDR	0x0012
#define CCPR1L_ADDR	0x0015
#define CCPR1H_ADDR	0x0016
#define CCP1CON_ADDR	0x0017
#define RCSTA_ADDR	0x0018
#define TXREG_ADDR	0x0019
#define RCREG_ADDR	0x001A
#define CCPR2L_ADDR	0x001B
#define CCPR2H_ADDR	0x001C
#define CCP2CON_ADDR	0x001D
#define ADRES_ADDR	0x001E
#define ADCON0_ADDR	0x001F
#define OPTION_REG_ADDR	0x0081
#define TRISA_ADDR	0x0085
#define TRISB_ADDR	0x0086
#define TRISC_ADDR	0x0087
#define TRISD_ADDR	0x0088
#define TRISE_ADDR	0x0089
#define PIE1_ADDR	0x008C
#define PIE2_ADDR	0x008D
#define PCON_ADDR	0x008E
#define PR2_ADDR	0x0092
#define TXSTA_ADDR	0x0098
#define SPBRG_ADDR	0x0099
#define ADCON1_ADDR	0x009F
#define UIR_ADDR	0x0190
#define UIE_ADDR	0x0191
#define UEIR_ADDR	0x0192
#define UEIE_ADDR	0x0193
#define USTAT_ADDR	0x0194
#define UCTRL_ADDR	0x0195
#define UADDR_ADDR	0x0196
#define USWSTAT_ADDR	0x0197
#define UEP0_ADDR	0x0198
#define UEP1_ADDR	0x0199
#define UEP2_ADDR	0x019A
#define BD0OST_ADDR	0x01A0
#define BD0OBC_ADDR	0x01A1
#define BD0OAL_ADDR	0x01A2
#define BD0IST_ADDR	0x01A4
#define BD0IBC_ADDR	0x01A5
#define BD0IAL_ADDR	0x01A6
#define BD1OST_ADDR	0x01A8
#define BD1OBC_ADDR	0x01A9
#define BD1OAL_ADDR	0x01AA
#define BD1IST_ADDR	0x01AC
#define BD1IBC_ADDR	0x01AD
#define BD1IAL_ADDR	0x01AE
#define BD2OST_ADDR	0x01B0
#define BD2OBC_ADDR	0x01B1
#define BD2OAL_ADDR	0x01B2
#define BD2IST_ADDR	0x01B4
#define BD2IBC_ADDR	0x01B5
#define BD2IAL_ADDR	0x01B6

//
// Memory organization.
//

#pragma memmap INDF_ADDR INDF_ADDR SFR 0x000	// INDF
#pragma memmap TMR0_ADDR TMR0_ADDR SFR 0x000	// TMR0
#pragma memmap PCL_ADDR PCL_ADDR SFR 0x000	// PCL
#pragma memmap STATUS_ADDR STATUS_ADDR SFR 0x000	// STATUS
#pragma memmap FSR_ADDR FSR_ADDR SFR 0x000	// FSR
#pragma memmap PORTA_ADDR PORTA_ADDR SFR 0x000	// PORTA
#pragma memmap PORTB_ADDR PORTB_ADDR SFR 0x000	// PORTB
#pragma memmap PORTC_ADDR PORTC_ADDR SFR 0x000	// PORTC
#pragma memmap PORTD_ADDR PORTD_ADDR SFR 0x000	// PORTD
#pragma memmap PORTE_ADDR PORTE_ADDR SFR 0x000	// PORTE
#pragma memmap PCLATH_ADDR PCLATH_ADDR SFR 0x000	// PCLATH
#pragma memmap INTCON_ADDR INTCON_ADDR SFR 0x000	// INTCON
#pragma memmap PIR1_ADDR PIR1_ADDR SFR 0x000	// PIR1
#pragma memmap PIR2_ADDR PIR2_ADDR SFR 0x000	// PIR2
#pragma memmap TMR1L_ADDR TMR1L_ADDR SFR 0x000	// TMR1L
#pragma memmap TMR1H_ADDR TMR1H_ADDR SFR 0x000	// TMR1H
#pragma memmap T1CON_ADDR T1CON_ADDR SFR 0x000	// T1CON
#pragma memmap TMR2_ADDR TMR2_ADDR SFR 0x000	// TMR2
#pragma memmap T2CON_ADDR T2CON_ADDR SFR 0x000	// T2CON
#pragma memmap CCPR1L_ADDR CCPR1L_ADDR SFR 0x000	// CCPR1L
#pragma memmap CCPR1H_ADDR CCPR1H_ADDR SFR 0x000	// CCPR1H
#pragma memmap CCP1CON_ADDR CCP1CON_ADDR SFR 0x000	// CCP1CON
#pragma memmap RCSTA_ADDR RCSTA_ADDR SFR 0x000	// RCSTA
#pragma memmap TXREG_ADDR TXREG_ADDR SFR 0x000	// TXREG
#pragma memmap RCREG_ADDR RCREG_ADDR SFR 0x000	// RCREG
#pragma memmap CCPR2L_ADDR CCPR2L_ADDR SFR 0x000	// CCPR2L
#pragma memmap CCPR2H_ADDR CCPR2H_ADDR SFR 0x000	// CCPR2H
#pragma memmap CCP2CON_ADDR CCP2CON_ADDR SFR 0x000	// CCP2CON
#pragma memmap ADRES_ADDR ADRES_ADDR SFR 0x000	// ADRES
#pragma memmap ADCON0_ADDR ADCON0_ADDR SFR 0x000	// ADCON0
#pragma memmap OPTION_REG_ADDR OPTION_REG_ADDR SFR 0x000	// OPTION_REG
#pragma memmap TRISA_ADDR TRISA_ADDR SFR 0x000	// TRISA
#pragma memmap TRISB_ADDR TRISB_ADDR SFR 0x000	// TRISB
#pragma memmap TRISC_ADDR TRISC_ADDR SFR 0x000	// TRISC
#pragma memmap TRISD_ADDR TRISD_ADDR SFR 0x000	// TRISD
#pragma memmap TRISE_ADDR TRISE_ADDR SFR 0x000	// TRISE
#pragma memmap PIE1_ADDR PIE1_ADDR SFR 0x000	// PIE1
#pragma memmap PIE2_ADDR PIE2_ADDR SFR 0x000	// PIE2
#pragma memmap PCON_ADDR PCON_ADDR SFR 0x000	// PCON
#pragma memmap PR2_ADDR PR2_ADDR SFR 0x000	// PR2
#pragma memmap TXSTA_ADDR TXSTA_ADDR SFR 0x000	// TXSTA
#pragma memmap SPBRG_ADDR SPBRG_ADDR SFR 0x000	// SPBRG
#pragma memmap ADCON1_ADDR ADCON1_ADDR SFR 0x000	// ADCON1
#pragma memmap UIR_ADDR UIR_ADDR SFR 0x000	// UIR
#pragma memmap UIE_ADDR UIE_ADDR SFR 0x000	// UIE
#pragma memmap UEIR_ADDR UEIR_ADDR SFR 0x000	// UEIR
#pragma memmap UEIE_ADDR UEIE_ADDR SFR 0x000	// UEIE
#pragma memmap USTAT_ADDR USTAT_ADDR SFR 0x000	// USTAT
#pragma memmap UCTRL_ADDR UCTRL_ADDR SFR 0x000	// UCTRL
#pragma memmap UADDR_ADDR UADDR_ADDR SFR 0x000	// UADDR
#pragma memmap USWSTAT_ADDR USWSTAT_ADDR SFR 0x000	// USWSTAT
#pragma memmap UEP0_ADDR UEP0_ADDR SFR 0x000	// UEP0
#pragma memmap UEP1_ADDR UEP1_ADDR SFR 0x000	// UEP1
#pragma memmap UEP2_ADDR UEP2_ADDR SFR 0x000	// UEP2
#pragma memmap BD0OST_ADDR BD0OST_ADDR SFR 0x000	// BD0OST
#pragma memmap BD0OBC_ADDR BD0OBC_ADDR SFR 0x000	// BD0OBC
#pragma memmap BD0OAL_ADDR BD0OAL_ADDR SFR 0x000	// BD0OAL
#pragma memmap BD0IST_ADDR BD0IST_ADDR SFR 0x000	// BD0IST
#pragma memmap BD0IBC_ADDR BD0IBC_ADDR SFR 0x000	// BD0IBC
#pragma memmap BD0IAL_ADDR BD0IAL_ADDR SFR 0x000	// BD0IAL
#pragma memmap BD1OST_ADDR BD1OST_ADDR SFR 0x000	// BD1OST
#pragma memmap BD1OBC_ADDR BD1OBC_ADDR SFR 0x000	// BD1OBC
#pragma memmap BD1OAL_ADDR BD1OAL_ADDR SFR 0x000	// BD1OAL
#pragma memmap BD1IST_ADDR BD1IST_ADDR SFR 0x000	// BD1IST
#pragma memmap BD1IBC_ADDR BD1IBC_ADDR SFR 0x000	// BD1IBC
#pragma memmap BD1IAL_ADDR BD1IAL_ADDR SFR 0x000	// BD1IAL
#pragma memmap BD2OST_ADDR BD2OST_ADDR SFR 0x000	// BD2OST
#pragma memmap BD2OBC_ADDR BD2OBC_ADDR SFR 0x000	// BD2OBC
#pragma memmap BD2OAL_ADDR BD2OAL_ADDR SFR 0x000	// BD2OAL
#pragma memmap BD2IST_ADDR BD2IST_ADDR SFR 0x000	// BD2IST
#pragma memmap BD2IBC_ADDR BD2IBC_ADDR SFR 0x000	// BD2IBC
#pragma memmap BD2IAL_ADDR BD2IAL_ADDR SFR 0x000	// BD2IAL


//         LIST
// P16C765.INC  Standard Header File, Version 1.00    Microchip Technology, Inc.
//         NOLIST

// This header file defines configurations, registers, and other useful bits of
// information for the PIC16C765 microcontroller.  These names are taken to match 
// the data sheets as closely as possible.  

// Note that the processor must be selected before this file is 
// included.  The processor may be selected the following ways:

//       1. Command line switch:
//               C:\ MPASM MYFILE.ASM /PIC16C765
//       2. LIST directive in the source file
//               LIST   P=PIC16C765
//       3. Processor Type entry in the MPASM full-screen interface

//==========================================================================
//
//       Revision History
//
//==========================================================================

//Rev:   Date:    Reason:

//1.00   28 Sep 99 Initial Release

//==========================================================================
//
//       Verify Processor
//
//==========================================================================

//        IFNDEF __16C765
//            MESSG "Processor-header file mismatch.  Verify selected processor."
//         ENDIF

//==========================================================================
//
//       Register Definitions
//
//==========================================================================

#define W                    0x0000
#define F                    0x0001

//----- Register Files------------------------------------------------------

extern data __at (INDF_ADDR) volatile char      INDF;
extern sfr  __at (TMR0_ADDR)                    TMR0;
extern data __at (PCL_ADDR) volatile char       PCL;
extern sfr  __at (STATUS_ADDR)                  STATUS;
extern sfr  __at (FSR_ADDR)                     FSR;
extern sfr  __at (PORTA_ADDR)                   PORTA;
extern sfr  __at (PORTB_ADDR)                   PORTB;
extern sfr  __at (PORTC_ADDR)                   PORTC;
extern sfr  __at (PORTD_ADDR)                   PORTD;
extern sfr  __at (PORTE_ADDR)                   PORTE;
extern sfr  __at (PCLATH_ADDR)                  PCLATH;
extern sfr  __at (INTCON_ADDR)                  INTCON;
extern sfr  __at (PIR1_ADDR)                    PIR1;
extern sfr  __at (PIR2_ADDR)                    PIR2;
extern sfr  __at (TMR1L_ADDR)                   TMR1L;
extern sfr  __at (TMR1H_ADDR)                   TMR1H;
extern sfr  __at (T1CON_ADDR)                   T1CON;
extern sfr  __at (TMR2_ADDR)                    TMR2;
extern sfr  __at (T2CON_ADDR)                   T2CON;
extern sfr  __at (CCPR1L_ADDR)                  CCPR1L;
extern sfr  __at (CCPR1H_ADDR)                  CCPR1H;
extern sfr  __at (CCP1CON_ADDR)                 CCP1CON;
extern sfr  __at (RCSTA_ADDR)                   RCSTA;
extern sfr  __at (TXREG_ADDR)                   TXREG;
extern sfr  __at (RCREG_ADDR)                   RCREG;
extern sfr  __at (CCPR2L_ADDR)                  CCPR2L;
extern sfr  __at (CCPR2H_ADDR)                  CCPR2H;
extern sfr  __at (CCP2CON_ADDR)                 CCP2CON;
extern sfr  __at (ADRES_ADDR)                   ADRES;
extern sfr  __at (ADCON0_ADDR)                  ADCON0;

extern sfr  __at (OPTION_REG_ADDR)              OPTION_REG;
extern sfr  __at (TRISA_ADDR)                   TRISA;
extern sfr  __at (TRISB_ADDR)                   TRISB;
extern sfr  __at (TRISC_ADDR)                   TRISC;
extern sfr  __at (TRISD_ADDR)                   TRISD;
extern sfr  __at (TRISE_ADDR)                   TRISE;
extern sfr  __at (PIE1_ADDR)                    PIE1;
extern sfr  __at (PIE2_ADDR)                    PIE2;
extern sfr  __at (PCON_ADDR)                    PCON;
extern sfr  __at (PR2_ADDR)                     PR2;
extern sfr  __at (TXSTA_ADDR)                   TXSTA;
extern sfr  __at (SPBRG_ADDR)                   SPBRG;
extern sfr  __at (ADCON1_ADDR)                  ADCON1;
extern sfr  __at (UIR_ADDR)                     UIR;
extern sfr  __at (UIE_ADDR)                     UIE;
extern sfr  __at (UEIR_ADDR)                    UEIR;
extern sfr  __at (UEIE_ADDR)                    UEIE;
extern sfr  __at (USTAT_ADDR)                   USTAT;
extern sfr  __at (UCTRL_ADDR)                   UCTRL;
extern sfr  __at (UADDR_ADDR)                   UADDR;
extern sfr  __at (USWSTAT_ADDR)                 USWSTAT;
extern sfr  __at (UEP0_ADDR)                    UEP0;
extern sfr  __at (UEP1_ADDR)                    UEP1;
extern sfr  __at (UEP2_ADDR)                    UEP2;

extern sfr  __at (BD0OST_ADDR)                  BD0OST;
extern sfr  __at (BD0OBC_ADDR)                  BD0OBC;
extern sfr  __at (BD0OAL_ADDR)                  BD0OAL;
extern sfr  __at (BD0IST_ADDR)                  BD0IST;
extern sfr  __at (BD0IBC_ADDR)                  BD0IBC;
extern sfr  __at (BD0IAL_ADDR)                  BD0IAL;

extern sfr  __at (BD1OST_ADDR)                  BD1OST;
extern sfr  __at (BD1OBC_ADDR)                  BD1OBC;
extern sfr  __at (BD1OAL_ADDR)                  BD1OAL;
extern sfr  __at (BD1IST_ADDR)                  BD1IST;
extern sfr  __at (BD1IBC_ADDR)                  BD1IBC;
extern sfr  __at (BD1IAL_ADDR)                  BD1IAL;

extern sfr  __at (BD2OST_ADDR)                  BD2OST;
extern sfr  __at (BD2OBC_ADDR)                  BD2OBC;
extern sfr  __at (BD2OAL_ADDR)                  BD2OAL;
extern sfr  __at (BD2IST_ADDR)                  BD2IST;
extern sfr  __at (BD2IBC_ADDR)                  BD2IBC;
extern sfr  __at (BD2IAL_ADDR)                  BD2IAL;


//----- STATUS Bits --------------------------------------------------------


//----- INTCON Bits --------------------------------------------------------


//----- PIR1 Bits ----------------------------------------------------------


//----- PIR2 Bits ----------------------------------------------------------


//----- T1CON Bits ---------------------------------------------------------


//----- T2CON Bits ---------------------------------------------------------


//----- CCP1CON Bits -------------------------------------------------------


//----- RCSTA Bits ---------------------------------------------------------


//----- CCP2CON Bits -------------------------------------------------------


//----- ADCON0 Bits --------------------------------------------------------


//----- OPTION Bits --------------------------------------------------------


//----- TRISE Bits ---------------------------------------------------------


//----- PIE1 Bits ----------------------------------------------------------


//----- PIE2 Bits ----------------------------------------------------------


//----- PCON Bits ----------------------------------------------------------


//----- TXSTA Bits ---------------------------------------------------------


//----- ADCON1 Bits --------------------------------------------------------


//----- UIR/UIE Bits -----------------------------------------------------


//----- UEIR/UEIE Bits -----------------------------------------------------


//----- USTAT Bits ---------------------------------------------------------


//----- UCTRL Bits ---------------------------------------------------------

//----- UEP0/UEP1/UEP2 Bits ------------------------------------------------


//----- Buffer descriptor Bits ---------------------------------------------

//==========================================================================
//
//       RAM Definition
//
//==========================================================================

//         __MAXRAM H'01FF'
//         __BADRAM H'13', H'14', H'8F'-H'91'
// 	__BADRAM H'93'-H'97', H'9A'-H'9E'
// 	__BADRAM H'105', H'107'-H'109', H'10C'-H'11F'
// 	__BADRAM H'185', H'187'-H'189', H'18C'-H'18F', H'19B'-H'19F'
// 	__BADRAM H'1E0'-H'1EF'
//==========================================================================
//
//       Configuration Bits
//
//==========================================================================

#define _CP_ALL              0x00CF
#define _CP_75               0x15DF
#define _CP_50               0x2AEF
#define _CP_OFF              0x3FFF
#define _PWRTE_OFF           0x3FFF
#define _PWRTE_ON            0x3FF7
#define _WDT_ON              0x3FFF
#define _WDT_OFF             0x3FFB
#define _HS_OSC              0x3FFC
#define _EC_OSC              0x3FFD
#define _H4_OSC              0x3FFE
#define _E4_OSC              0x3FFF

//         LIST

// ----- ADCON0 bits --------------------
typedef union {
  struct {
    unsigned char ADON:1;
    unsigned char :1;
    unsigned char GO:1;
    unsigned char CHS0:1;
    unsigned char CHS1:1;
    unsigned char CHS2:1;
    unsigned char ADCS0:1;
    unsigned char ADCS1:1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char NOT_DONE:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char GO_DONE:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __ADCON0_bits_t;
extern volatile __ADCON0_bits_t __at(ADCON0_ADDR) ADCON0_bits;

#define ADON                 ADCON0_bits.ADON
#define GO                   ADCON0_bits.GO
#define NOT_DONE             ADCON0_bits.NOT_DONE
#define GO_DONE              ADCON0_bits.GO_DONE
#define CHS0                 ADCON0_bits.CHS0
#define CHS1                 ADCON0_bits.CHS1
#define CHS2                 ADCON0_bits.CHS2
#define ADCS0                ADCON0_bits.ADCS0
#define ADCS1                ADCON0_bits.ADCS1

// ----- ADCON1 bits --------------------
typedef union {
  struct {
    unsigned char PCFG0:1;
    unsigned char PCFG1:1;
    unsigned char PCFG2:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __ADCON1_bits_t;
extern volatile __ADCON1_bits_t __at(ADCON1_ADDR) ADCON1_bits;

#define PCFG0                ADCON1_bits.PCFG0
#define PCFG1                ADCON1_bits.PCFG1
#define PCFG2                ADCON1_bits.PCFG2

// ----- CCP1CON bits --------------------
typedef union {
  struct {
    unsigned char CCP1M0:1;
    unsigned char CCP1M1:1;
    unsigned char CCP1M2:1;
    unsigned char CCP1M3:1;
    unsigned char DC1B0:1;
    unsigned char DC1B1:1;
    unsigned char :1;
    unsigned char :1;
  };
} __CCP1CON_bits_t;
extern volatile __CCP1CON_bits_t __at(CCP1CON_ADDR) CCP1CON_bits;

#define CCP1M0               CCP1CON_bits.CCP1M0
#define CCP1M1               CCP1CON_bits.CCP1M1
#define CCP1M2               CCP1CON_bits.CCP1M2
#define CCP1M3               CCP1CON_bits.CCP1M3
#define DC1B0                CCP1CON_bits.DC1B0
#define DC1B1                CCP1CON_bits.DC1B1

// ----- CCP2CON bits --------------------
typedef union {
  struct {
    unsigned char CCP2M0:1;
    unsigned char CCP2M1:1;
    unsigned char CCP2M2:1;
    unsigned char CCP2M3:1;
    unsigned char DC2B0:1;
    unsigned char DC2B1:1;
    unsigned char :1;
    unsigned char :1;
  };
} __CCP2CON_bits_t;
extern volatile __CCP2CON_bits_t __at(CCP2CON_ADDR) CCP2CON_bits;

#define CCP2M0               CCP2CON_bits.CCP2M0
#define CCP2M1               CCP2CON_bits.CCP2M1
#define CCP2M2               CCP2CON_bits.CCP2M2
#define CCP2M3               CCP2CON_bits.CCP2M3
#define DC2B0                CCP2CON_bits.DC2B0
#define DC2B1                CCP2CON_bits.DC2B1

// ----- INTCON bits --------------------
typedef union {
  struct {
    unsigned char RBIF:1;
    unsigned char INTF:1;
    unsigned char T0IF:1;
    unsigned char RBIE:1;
    unsigned char INTE:1;
    unsigned char T0IE:1;
    unsigned char PEIE:1;
    unsigned char GIE:1;
  };
} __INTCON_bits_t;
extern volatile __INTCON_bits_t __at(INTCON_ADDR) INTCON_bits;

#define RBIF                 INTCON_bits.RBIF
#define INTF                 INTCON_bits.INTF
#define T0IF                 INTCON_bits.T0IF
#define RBIE                 INTCON_bits.RBIE
#define INTE                 INTCON_bits.INTE
#define T0IE                 INTCON_bits.T0IE
#define PEIE                 INTCON_bits.PEIE
#define GIE                  INTCON_bits.GIE

// ----- OPTION_REG bits --------------------
typedef union {
  struct {
    unsigned char PS0:1;
    unsigned char PS1:1;
    unsigned char PS2:1;
    unsigned char PSA:1;
    unsigned char T0SE:1;
    unsigned char T0CS:1;
    unsigned char INTEDG:1;
    unsigned char NOT_RBPU:1;
  };
} __OPTION_REG_bits_t;
extern volatile __OPTION_REG_bits_t __at(OPTION_REG_ADDR) OPTION_REG_bits;

#define PS0                  OPTION_REG_bits.PS0
#define PS1                  OPTION_REG_bits.PS1
#define PS2                  OPTION_REG_bits.PS2
#define PSA                  OPTION_REG_bits.PSA
#define T0SE                 OPTION_REG_bits.T0SE
#define T0CS                 OPTION_REG_bits.T0CS
#define INTEDG               OPTION_REG_bits.INTEDG
#define NOT_RBPU             OPTION_REG_bits.NOT_RBPU

// ----- PCON bits --------------------
typedef union {
  struct {
    unsigned char NOT_BO:1;
    unsigned char NOT_POR:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char NOT_BOR:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __PCON_bits_t;
extern volatile __PCON_bits_t __at(PCON_ADDR) PCON_bits;

#define NOT_BO               PCON_bits.NOT_BO
#define NOT_BOR              PCON_bits.NOT_BOR
#define NOT_POR              PCON_bits.NOT_POR

// ----- PIE1 bits --------------------
typedef union {
  struct {
    unsigned char TMR1IE:1;
    unsigned char TMR2IE:1;
    unsigned char CCP1IE:1;
    unsigned char USBIE:1;
    unsigned char TXIE:1;
    unsigned char RCIE:1;
    unsigned char ADIE:1;
    unsigned char PSPIE:1;
  };
} __PIE1_bits_t;
extern volatile __PIE1_bits_t __at(PIE1_ADDR) PIE1_bits;

#define TMR1IE               PIE1_bits.TMR1IE
#define TMR2IE               PIE1_bits.TMR2IE
#define CCP1IE               PIE1_bits.CCP1IE
#define USBIE                PIE1_bits.USBIE
#define TXIE                 PIE1_bits.TXIE
#define RCIE                 PIE1_bits.RCIE
#define ADIE                 PIE1_bits.ADIE
#define PSPIE                PIE1_bits.PSPIE

// ----- PIE2 bits --------------------
typedef union {
  struct {
    unsigned char CCP2IE:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __PIE2_bits_t;
extern volatile __PIE2_bits_t __at(PIE2_ADDR) PIE2_bits;

#define CCP2IE               PIE2_bits.CCP2IE

// ----- PIR1 bits --------------------
typedef union {
  struct {
    unsigned char TMR1IF:1;
    unsigned char TMR2IF:1;
    unsigned char CCP1IF:1;
    unsigned char USBIF:1;
    unsigned char TXIF:1;
    unsigned char RCIF:1;
    unsigned char ADIF:1;
    unsigned char PSPIF:1;
  };
} __PIR1_bits_t;
extern volatile __PIR1_bits_t __at(PIR1_ADDR) PIR1_bits;

#define TMR1IF               PIR1_bits.TMR1IF
#define TMR2IF               PIR1_bits.TMR2IF
#define CCP1IF               PIR1_bits.CCP1IF
#define USBIF                PIR1_bits.USBIF
#define TXIF                 PIR1_bits.TXIF
#define RCIF                 PIR1_bits.RCIF
#define ADIF                 PIR1_bits.ADIF
#define PSPIF                PIR1_bits.PSPIF

// ----- PIR2 bits --------------------
typedef union {
  struct {
    unsigned char CCP2IF:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __PIR2_bits_t;
extern volatile __PIR2_bits_t __at(PIR2_ADDR) PIR2_bits;

#define CCP2IF               PIR2_bits.CCP2IF

// ----- RCSTA bits --------------------
typedef union {
  struct {
    unsigned char RX9D:1;
    unsigned char OERR:1;
    unsigned char FERR:1;
    unsigned char :1;
    unsigned char CREN:1;
    unsigned char SREN:1;
    unsigned char RX9:1;
    unsigned char SPEN:1;
  };
  struct {
    unsigned char RCD8:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char RC9:1;
    unsigned char :1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char NOT_RC8:1;
    unsigned char :1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char RC8_9:1;
    unsigned char :1;
  };
} __RCSTA_bits_t;
extern volatile __RCSTA_bits_t __at(RCSTA_ADDR) RCSTA_bits;

#define RX9D                 RCSTA_bits.RX9D
#define RCD8                 RCSTA_bits.RCD8
#define OERR                 RCSTA_bits.OERR
#define FERR                 RCSTA_bits.FERR
#define CREN                 RCSTA_bits.CREN
#define SREN                 RCSTA_bits.SREN
#define RX9                  RCSTA_bits.RX9
#define RC9                  RCSTA_bits.RC9
#define NOT_RC8              RCSTA_bits.NOT_RC8
#define RC8_9                RCSTA_bits.RC8_9
#define SPEN                 RCSTA_bits.SPEN

// ----- STATUS bits --------------------
typedef union {
  struct {
    unsigned char C:1;
    unsigned char DC:1;
    unsigned char Z:1;
    unsigned char NOT_PD:1;
    unsigned char NOT_TO:1;
    unsigned char RP0:1;
    unsigned char RP1:1;
    unsigned char IRP:1;
  };
} __STATUS_bits_t;
extern volatile __STATUS_bits_t __at(STATUS_ADDR) STATUS_bits;

#define C                    STATUS_bits.C
#define DC                   STATUS_bits.DC
#define Z                    STATUS_bits.Z
#define NOT_PD               STATUS_bits.NOT_PD
#define NOT_TO               STATUS_bits.NOT_TO
#define RP0                  STATUS_bits.RP0
#define RP1                  STATUS_bits.RP1
#define IRP                  STATUS_bits.IRP

// ----- T1CON bits --------------------
typedef union {
  struct {
    unsigned char TMR1ON:1;
    unsigned char TMR1CS:1;
    unsigned char NOT_T1SYNC:1;
    unsigned char T1OSCEN:1;
    unsigned char T1CKPS0:1;
    unsigned char T1CKPS1:1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char T1INSYNC:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __T1CON_bits_t;
extern volatile __T1CON_bits_t __at(T1CON_ADDR) T1CON_bits;

#define TMR1ON               T1CON_bits.TMR1ON
#define TMR1CS               T1CON_bits.TMR1CS
#define NOT_T1SYNC           T1CON_bits.NOT_T1SYNC
#define T1INSYNC             T1CON_bits.T1INSYNC
#define T1OSCEN              T1CON_bits.T1OSCEN
#define T1CKPS0              T1CON_bits.T1CKPS0
#define T1CKPS1              T1CON_bits.T1CKPS1

// ----- T2CON bits --------------------
typedef union {
  struct {
    unsigned char T2CKPS0:1;
    unsigned char T2CKPS1:1;
    unsigned char TMR2ON:1;
    unsigned char TOUTPS0:1;
    unsigned char TOUTPS1:1;
    unsigned char TOUTPS2:1;
    unsigned char TOUTPS3:1;
    unsigned char :1;
  };
} __T2CON_bits_t;
extern volatile __T2CON_bits_t __at(T2CON_ADDR) T2CON_bits;

#define T2CKPS0              T2CON_bits.T2CKPS0
#define T2CKPS1              T2CON_bits.T2CKPS1
#define TMR2ON               T2CON_bits.TMR2ON
#define TOUTPS0              T2CON_bits.TOUTPS0
#define TOUTPS1              T2CON_bits.TOUTPS1
#define TOUTPS2              T2CON_bits.TOUTPS2
#define TOUTPS3              T2CON_bits.TOUTPS3

// ----- TRISE bits --------------------
typedef union {
  struct {
    unsigned char TRISE0:1;
    unsigned char TRISE1:1;
    unsigned char TRISE2:1;
    unsigned char :1;
    unsigned char PSPMODE:1;
    unsigned char IBOV:1;
    unsigned char OBF:1;
    unsigned char IBF:1;
  };
} __TRISE_bits_t;
extern volatile __TRISE_bits_t __at(TRISE_ADDR) TRISE_bits;

#define TRISE0               TRISE_bits.TRISE0
#define TRISE1               TRISE_bits.TRISE1
#define TRISE2               TRISE_bits.TRISE2
#define PSPMODE              TRISE_bits.PSPMODE
#define IBOV                 TRISE_bits.IBOV
#define OBF                  TRISE_bits.OBF
#define IBF                  TRISE_bits.IBF

// ----- TXSTA bits --------------------
typedef union {
  struct {
    unsigned char TX9D:1;
    unsigned char TRMT:1;
    unsigned char BRGH:1;
    unsigned char :1;
    unsigned char SYNC:1;
    unsigned char TXEN:1;
    unsigned char TX9:1;
    unsigned char CSRC:1;
  };
  struct {
    unsigned char TXD8:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char NOT_TX8:1;
    unsigned char :1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char TX8_9:1;
    unsigned char :1;
  };
} __TXSTA_bits_t;
extern volatile __TXSTA_bits_t __at(TXSTA_ADDR) TXSTA_bits;

#define TX9D                 TXSTA_bits.TX9D
#define TXD8                 TXSTA_bits.TXD8
#define TRMT                 TXSTA_bits.TRMT
#define BRGH                 TXSTA_bits.BRGH
#define SYNC                 TXSTA_bits.SYNC
#define TXEN                 TXSTA_bits.TXEN
#define TX9                  TXSTA_bits.TX9
#define NOT_TX8              TXSTA_bits.NOT_TX8
#define TX8_9                TXSTA_bits.TX8_9
#define CSRC                 TXSTA_bits.CSRC

// ----- UCTRL bits --------------------
typedef union {
  struct {
    unsigned char :1;
    unsigned char SUSPND:1;
    unsigned char RESUME:1;
    unsigned char DEV_ATT:1;
    unsigned char PKT_DIS:1;
    unsigned char SE0:1;
    unsigned char :1;
    unsigned char :1;
  };
} __UCTRL_bits_t;
extern volatile __UCTRL_bits_t __at(UCTRL_ADDR) UCTRL_bits;

#define SUSPND               UCTRL_bits.SUSPND
#define RESUME               UCTRL_bits.RESUME
#define DEV_ATT              UCTRL_bits.DEV_ATT
#define PKT_DIS              UCTRL_bits.PKT_DIS
#define SE0                  UCTRL_bits.SE0

// ----- UEIE bits --------------------
typedef union {
  struct {
    unsigned char PID_ERR:1;
    unsigned char CRC5:1;
    unsigned char CRC16:1;
    unsigned char DFN8:1;
    unsigned char BTO_ERR:1;
    unsigned char WRT_ERR:1;
    unsigned char OWN_ERR:1;
    unsigned char BTS_ERR:1;
  };
} __UEIE_bits_t;
extern volatile __UEIE_bits_t __at(UEIE_ADDR) UEIE_bits;

#define PID_ERR              UEIE_bits.PID_ERR
#define CRC5                 UEIE_bits.CRC5
#define CRC16                UEIE_bits.CRC16
#define DFN8                 UEIE_bits.DFN8
#define BTO_ERR              UEIE_bits.BTO_ERR
#define WRT_ERR              UEIE_bits.WRT_ERR
#define OWN_ERR              UEIE_bits.OWN_ERR
#define BTS_ERR              UEIE_bits.BTS_ERR

// ----- UEP2 bits --------------------
typedef union {
  struct {
    unsigned char EP_STALL:1;
    unsigned char EP_IN_EN:1;
    unsigned char EP_OUT_EN:1;
    unsigned char EP_CTL_DIS:1;
    unsigned char PID2:1;
    unsigned char PID3:1;
    unsigned char DATA01:1;
    unsigned char UOWN:1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char BSTALL:1;
    unsigned char DTS:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char OWN:1;
  };
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char PID0:1;
    unsigned char PID1:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __UEP2_bits_t;
extern volatile __UEP2_bits_t __at(UEP2_ADDR) UEP2_bits;

#define EP_STALL             UEP2_bits.EP_STALL
#define EP_IN_EN             UEP2_bits.EP_IN_EN
#define EP_OUT_EN            UEP2_bits.EP_OUT_EN
#define BSTALL               UEP2_bits.BSTALL
#define PID0                 UEP2_bits.PID0
#define EP_CTL_DIS           UEP2_bits.EP_CTL_DIS
#define DTS                  UEP2_bits.DTS
#define PID1                 UEP2_bits.PID1
#define PID2                 UEP2_bits.PID2
#define PID3                 UEP2_bits.PID3
#define DATA01               UEP2_bits.DATA01
#define UOWN                 UEP2_bits.UOWN
#define OWN                  UEP2_bits.OWN

// ----- UIE bits --------------------
typedef union {
  struct {
    unsigned char USB_RST:1;
    unsigned char UERR:1;
    unsigned char ACTIVITY:1;
    unsigned char TOK_DNE:1;
    unsigned char UIDLE:1;
    unsigned char STALL:1;
    unsigned char :1;
    unsigned char :1;
  };
} __UIE_bits_t;
extern volatile __UIE_bits_t __at(UIE_ADDR) UIE_bits;

#define USB_RST              UIE_bits.USB_RST
#define UERR                 UIE_bits.UERR
#define ACTIVITY             UIE_bits.ACTIVITY
#define TOK_DNE              UIE_bits.TOK_DNE
#define UIDLE                UIE_bits.UIDLE
#define STALL                UIE_bits.STALL

// ----- USTAT bits --------------------
typedef union {
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char IN:1;
    unsigned char ENDP0:1;
    unsigned char ENDP1:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __USTAT_bits_t;
extern volatile __USTAT_bits_t __at(USTAT_ADDR) USTAT_bits;

#define IN                   USTAT_bits.IN
#define ENDP0                USTAT_bits.ENDP0
#define ENDP1                USTAT_bits.ENDP1

#endif
