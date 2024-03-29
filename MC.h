/* Based on CPU DB MC9S12C32_80, version 2.87.410 (RegistersPrg V2.32) */
/*
** ###################################################################
**     Filename  : mc9s12c128.h
**     Processor : MC9S12C128CFU16
**     FileFormat: V2.32
**     DataSheet : MC9S12C128 Rev 01.23 05/2007
**     Compiler  : CodeWarrior compiler
**     Date/Time : 8.6.2010, 8:59
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**      - 08.12.2006, V2.87.396:
**              - Added bit CRGFLG_LVRF. REASON: Bug-fix (#4020 in Issue Manager)
**
**     File-Format-Revisions:
**      - 14.11.2005, V2.00 :
**               - Deprecated symbols added for backward compatibility (section at the end of this file)
**      - 15.11.2005, V2.01 :
**               - Fixed invalid instruction in macro __RESET_WATCHDOG for HCS12 family.
**      - 17.12.2005, V2.02 :
**               - Arrays (symbols xx_ARR) are defined as pointer to volatile, see issue #2778
**      - 16.01.2006, V2.03 :
**               - Fixed declaration of non volatile registers. Now it does not require (but allows) their initialization, see issue #2920.
**               - "volatile" modifier removed from declaration of non volatile registers (that contain modifier "const")
**      - 08.03.2006, V2.04 :
**               - Support for bit(s) names duplicated with any register name in .h header files
**      - 24.03.2006, V2.05 :
**               - Fixed macro __RESET_WATCHDOG for HCS12 family - address and correct write order.
**      - 26.04.2006, V2.06 :
**               - Changes have not affected this file (because they are related to another family)
**      - 27.04.2006, V2.07 :
**               - Fixed macro __RESET_WATCHDOG for HCS12, HCS12X ,HCS08 DZ and HCS08 EN derivatives (write 0x55,0xAA).
**      - 07.06.2006, V2.08 :
**               - Changes have not affected this file (because they are related to another family)
**      - 03.07.2006, V2.09 :
**               - Changes have not affected this file (because they are related to another family)
**      - 27.10.2006, V2.10 :
**               - __RESET_WATCHDOG improved formating and re-definition
**      - 23.11.2006, V2.11 :
**               - Changes have not affected this file (because they are related to another family)
**      - 22.01.2007, V2.12 :
**               - Fixed declaration of non volatile registers. Now it does not require (but allows) their initialization, see issue #4086.
**      - 01.03.2007, V2.13 :
**               - Flash commands constants values converted to HEX format
**      - 02.03.2007, V2.14 :
**               - Interrupt vector numbers added into .H, see VectorNumber_*
**      - 26.03.2007, V2.15 :
**               - Changes have not affected this file (because they are related to another family)
**      - 10.05.2007, V2.16 :
**               - Changes have not affected this file (because they are related to another family)
**      - 05.06.2007, V2.17 :
**               - Changes have not affected this file (because they are related to another family)
**      - 19.07.2007, V2.18 :
**               - Improved number of blanked lines inside register structures
**      - 06.08.2007, V2.19 :
**               - CPUDB revisions generated ahead of the file-format revisions.
**      - 11.09.2007, V2.20 :
**               - Added comment about initialization of unbonded pins.
**      - 02.01.2008, V2.21 :
**               - Changes have not affected this file (because they are related to another family)
**      - 13.02.2008, V2.22 :
**               - Changes have not affected this file (because they are related to another family)
**      - 20.02.2008, V2.23 :
**               - Termination of pragma V30toV31Compatible added, #5708
**      - 03.07.2008, V2.24 :
**               - Added support for bits with name starting with number (like "1HZ")
**      - 28.11.2008, V2.25 :
**               - StandBy RAM array declaration for ANSI-C added
**      - 1.12.2008, V2.26 :
**               - Duplication of bit (or bit-group) name with register name is not marked as a problem, is register is internal only and it is not displayed in I/O map.
**      - 17.3.2009, V2.27 :
**               - Merged bit-group is not generated, if the name matches with another bit name in the register
**      - 6.4.2009, V2.28 :
**               - Fixed generation of merged bits for bit-groups with a digit at the end, if group-name is defined in CPUDB
**      - 3.8.2009, V2.29 :
**               - If there is just one bits group matching register name, single bits are not generated
**      - 10.9.2009, V2.30 :
**               - Fixed generation of registers arrays.
**      - 15.10.2009, V2.31 :
**               - Changes have not affected this file (because they are related to another family)
**      - 18.05.2010, V2.32 :
**               - MISRA compliance: U/UL suffixes added to all numbers (_MASK,_BITNUM and addresses)
**
**     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
**     derivative device. To avoid extra current drain from floating input pins, the user’s reset
**     initialization routine in the application program must either enable on-chip pull-up devices
**     or change the direction of unconnected pins to outputs so the pins do not float.
** ###################################################################
*/

#ifndef _MC9S12C128_H
#define _MC9S12C128_H

/*lint -save  -e950 -esym(960,18.4) -e46 -esym(961,19.7) Disable MISRA rule (1.1,18.4,6.4,19.7) checking. */
/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */
#pragma OPTION ADD V30toV31Compatible "-BfaGapLimitBits4294967295" /*this guarantee correct bitfield positions*/

/**************** interrupt vector numbers ****************/
#define VectorNumber_VReserved63        63U
#define VectorNumber_VReserved62        62U
#define VectorNumber_VReserved61        61U
#define VectorNumber_VReserved60        60U
#define VectorNumber_VReserved59        59U
#define VectorNumber_Vvreglvi           58U
#define VectorNumber_Vpwmesdn           57U
#define VectorNumber_Vportp             56U
#define VectorNumber_VReserved55        55U
#define VectorNumber_VReserved54        54U
#define VectorNumber_VReserved53        53U
#define VectorNumber_VReserved52        52U
#define VectorNumber_VReserved51        51U
#define VectorNumber_VReserved50        50U
#define VectorNumber_VReserved49        49U
#define VectorNumber_VReserved48        48U
#define VectorNumber_VReserved47        47U
#define VectorNumber_VReserved46        46U
#define VectorNumber_VReserved45        45U
#define VectorNumber_VReserved44        44U
#define VectorNumber_VReserved43        43U
#define VectorNumber_VReserved42        42U
#define VectorNumber_VReserved41        41U
#define VectorNumber_VReserved40        40U
#define VectorNumber_Vcantx             39U
#define VectorNumber_Vcanrx             38U
#define VectorNumber_Vcanerr            37U
#define VectorNumber_Vcanwkup           36U
#define VectorNumber_Vflash             35U
#define VectorNumber_VReserved34        34U
#define VectorNumber_VReserved33        33U
#define VectorNumber_VReserved32        32U
#define VectorNumber_VReserved31        31U
#define VectorNumber_VReserved30        30U
#define VectorNumber_Vcrgscm            29U
#define VectorNumber_Vcrgplllck         28U
#define VectorNumber_VReserved27        27U
#define VectorNumber_VReserved26        26U
#define VectorNumber_VReserved25        25U
#define VectorNumber_Vportj             24U
#define VectorNumber_VReserved23        23U
#define VectorNumber_Vatd0              22U
#define VectorNumber_VReserved21        21U
#define VectorNumber_Vsci               20U
#define VectorNumber_Vspi               19U
#define VectorNumber_Vtimpaie           18U
#define VectorNumber_Vtimpaovf          17U
#define VectorNumber_Vtimovf            16U
#define VectorNumber_Vtimch7            15U
#define VectorNumber_Vtimch6            14U
#define VectorNumber_Vtimch5            13U
#define VectorNumber_Vtimch4            12U
#define VectorNumber_Vtimch3            11U
#define VectorNumber_Vtimch2            10U
#define VectorNumber_Vtimch1            9U
#define VectorNumber_Vtimch0            8U
#define VectorNumber_Vrti               7U
#define VectorNumber_Virq               6U
#define VectorNumber_Vxirq              5U
#define VectorNumber_Vswi               4U
#define VectorNumber_Vtrap              3U
#define VectorNumber_Vcop               2U
#define VectorNumber_Vclkmon            1U
#define VectorNumber_Vreset             0U

/**************** interrupt vector table ****************/
#define VReserved63                     0xFF80U
#define VReserved62                     0xFF82U
#define VReserved61                     0xFF84U
#define VReserved60                     0xFF86U
#define VReserved59                     0xFF88U
#define Vvreglvi                        0xFF8AU
#define Vpwmesdn                        0xFF8CU
#define Vportp                          0xFF8EU
#define VReserved55                     0xFF90U
#define VReserved54                     0xFF92U
#define VReserved53                     0xFF94U
#define VReserved52                     0xFF96U
#define VReserved51                     0xFF98U
#define VReserved50                     0xFF9AU
#define VReserved49                     0xFF9CU
#define VReserved48                     0xFF9EU
#define VReserved47                     0xFFA0U
#define VReserved46                     0xFFA2U
#define VReserved45                     0xFFA4U
#define VReserved44                     0xFFA6U
#define VReserved43                     0xFFA8U
#define VReserved42                     0xFFAAU
#define VReserved41                     0xFFACU
#define VReserved40                     0xFFAEU
#define Vcantx                          0xFFB0U
#define Vcanrx                          0xFFB2U
#define Vcanerr                         0xFFB4U
#define Vcanwkup                        0xFFB6U
#define Vflash                          0xFFB8U
#define VReserved34                     0xFFBAU
#define VReserved33                     0xFFBCU
#define VReserved32                     0xFFBEU
#define VReserved31                     0xFFC0U
#define VReserved30                     0xFFC2U
#define Vcrgscm                         0xFFC4U
#define Vcrgplllck                      0xFFC6U
#define VReserved27                     0xFFC8U
#define VReserved26                     0xFFCAU
#define VReserved25                     0xFFCCU
#define Vportj                          0xFFCEU
#define VReserved23                     0xFFD0U
#define Vatd0                           0xFFD2U
#define VReserved21                     0xFFD4U
#define Vsci                            0xFFD6U
#define Vspi                            0xFFD8U
#define Vtimpaie                        0xFFDAU
#define Vtimpaovf                       0xFFDCU
#define Vtimovf                         0xFFDEU
#define Vtimch7                         0xFFE0U
#define Vtimch6                         0xFFE2U
#define Vtimch5                         0xFFE4U
#define Vtimch4                         0xFFE6U
#define Vtimch3                         0xFFE8U
#define Vtimch2                         0xFFEAU
#define Vtimch1                         0xFFECU
#define Vtimch0                         0xFFEEU
#define Vrti                            0xFFF0U
#define Virq                            0xFFF2U
#define Vxirq                           0xFFF4U
#define Vswi                            0xFFF6U
#define Vtrap                           0xFFF8U
#define Vcop                            0xFFFAU
#define Vclkmon                         0xFFFCU
#define Vreset                          0xFFFEU

/**************** registers I/O map ****************/

/*** PORTAB - Port AB Register; 0x00000000 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PORTA - Port A Register; 0x00000000 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Port A Bit 0 */
        byte BIT1        :1;                                       /* Port A Bit 1 */
        byte BIT2        :1;                                       /* Port A Bit 2 */
        byte BIT3        :1;                                       /* Port A Bit 3 */
        byte BIT4        :1;                                       /* Port A Bit 4 */
        byte BIT5        :1;                                       /* Port A Bit 5 */
        byte BIT6        :1;                                       /* Port A Bit 6 */
        byte BIT7        :1;                                       /* Port A Bit 7 */
      } Bits;
    } PORTASTR;
    #define PORTA                       _PORTAB.Overlap_STR.PORTASTR.Byte
    #define PORTA_BIT0                  _PORTAB.Overlap_STR.PORTASTR.Bits.BIT0
    #define PORTA_BIT1                  _PORTAB.Overlap_STR.PORTASTR.Bits.BIT1
    #define PORTA_BIT2                  _PORTAB.Overlap_STR.PORTASTR.Bits.BIT2
    #define PORTA_BIT3                  _PORTAB.Overlap_STR.PORTASTR.Bits.BIT3
    #define PORTA_BIT4                  _PORTAB.Overlap_STR.PORTASTR.Bits.BIT4
    #define PORTA_BIT5                  _PORTAB.Overlap_STR.PORTASTR.Bits.BIT5
    #define PORTA_BIT6                  _PORTAB.Overlap_STR.PORTASTR.Bits.BIT6
    #define PORTA_BIT7                  _PORTAB.Overlap_STR.PORTASTR.Bits.BIT7
    
    #define PORTA_BIT0_MASK             1U
    #define PORTA_BIT1_MASK             2U
    #define PORTA_BIT2_MASK             4U
    #define PORTA_BIT3_MASK             8U
    #define PORTA_BIT4_MASK             16U
    #define PORTA_BIT5_MASK             32U
    #define PORTA_BIT6_MASK             64U
    #define PORTA_BIT7_MASK             128U
    

    /*** PORTB - Port B Register; 0x00000001 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Port B Bit 0 */
        byte BIT1        :1;                                       /* Port B Bit 1 */
        byte BIT2        :1;                                       /* Port B Bit 2 */
        byte BIT3        :1;                                       /* Port B Bit 3 */
        byte BIT4        :1;                                       /* Port B Bit 4 */
        byte BIT5        :1;                                       /* Port B Bit 5 */
        byte BIT6        :1;                                       /* Port B Bit 6 */
        byte BIT7        :1;                                       /* Port B Bit 7 */
      } Bits;
    } PORTBSTR;
    #define PORTB                       _PORTAB.Overlap_STR.PORTBSTR.Byte
    #define PORTB_BIT0                  _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT0
    #define PORTB_BIT1                  _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT1
    #define PORTB_BIT2                  _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT2
    #define PORTB_BIT3                  _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT3
    #define PORTB_BIT4                  _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT4
    #define PORTB_BIT5                  _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT5
    #define PORTB_BIT6                  _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT6
    #define PORTB_BIT7                  _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT7
    
    #define PORTB_BIT0_MASK             1U
    #define PORTB_BIT1_MASK             2U
    #define PORTB_BIT2_MASK             4U
    #define PORTB_BIT3_MASK             8U
    #define PORTB_BIT4_MASK             16U
    #define PORTB_BIT5_MASK             32U
    #define PORTB_BIT6_MASK             64U
    #define PORTB_BIT7_MASK             128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Port AB Bit 0 */
    word BIT1        :1;                                       /* Port AB Bit 1 */
    word BIT2        :1;                                       /* Port AB Bit 2 */
    word BIT3        :1;                                       /* Port AB Bit 3 */
    word BIT4        :1;                                       /* Port AB Bit 4 */
    word BIT5        :1;                                       /* Port AB Bit 5 */
    word BIT6        :1;                                       /* Port AB Bit 6 */
    word BIT7        :1;                                       /* Port AB Bit 7 */
    word BIT8        :1;                                       /* Port AB Bit 8 */
    word BIT9        :1;                                       /* Port AB Bit 9 */
    word BIT10       :1;                                       /* Port AB Bit 10 */
    word BIT11       :1;                                       /* Port AB Bit 11 */
    word BIT12       :1;                                       /* Port AB Bit 12 */
    word BIT13       :1;                                       /* Port AB Bit 13 */
    word BIT14       :1;                                       /* Port AB Bit 14 */
    word BIT15       :1;                                       /* Port AB Bit 15 */
  } Bits;
} PORTABSTR;
extern volatile PORTABSTR _PORTAB @(REG_BASE + 0x00000000UL);
#define PORTAB                          _PORTAB.Word
#define PORTAB_BIT0                     _PORTAB.Bits.BIT0
#define PORTAB_BIT1                     _PORTAB.Bits.BIT1
#define PORTAB_BIT2                     _PORTAB.Bits.BIT2
#define PORTAB_BIT3                     _PORTAB.Bits.BIT3
#define PORTAB_BIT4                     _PORTAB.Bits.BIT4
#define PORTAB_BIT5                     _PORTAB.Bits.BIT5
#define PORTAB_BIT6                     _PORTAB.Bits.BIT6
#define PORTAB_BIT7                     _PORTAB.Bits.BIT7
#define PORTAB_BIT8                     _PORTAB.Bits.BIT8
#define PORTAB_BIT9                     _PORTAB.Bits.BIT9
#define PORTAB_BIT10                    _PORTAB.Bits.BIT10
#define PORTAB_BIT11                    _PORTAB.Bits.BIT11
#define PORTAB_BIT12                    _PORTAB.Bits.BIT12
#define PORTAB_BIT13                    _PORTAB.Bits.BIT13
#define PORTAB_BIT14                    _PORTAB.Bits.BIT14
#define PORTAB_BIT15                    _PORTAB.Bits.BIT15

#define PORTAB_BIT0_MASK                1U
#define PORTAB_BIT1_MASK                2U
#define PORTAB_BIT2_MASK                4U
#define PORTAB_BIT3_MASK                8U
#define PORTAB_BIT4_MASK                16U
#define PORTAB_BIT5_MASK                32U
#define PORTAB_BIT6_MASK                64U
#define PORTAB_BIT7_MASK                128U
#define PORTAB_BIT8_MASK                256U
#define PORTAB_BIT9_MASK                512U
#define PORTAB_BIT10_MASK               1024U
#define PORTAB_BIT11_MASK               2048U
#define PORTAB_BIT12_MASK               4096U
#define PORTAB_BIT13_MASK               8192U
#define PORTAB_BIT14_MASK               16384U
#define PORTAB_BIT15_MASK               32768U


/*** DDRAB - Port AB Data Direction Register; 0x00000002 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DDRA - Port A Data Direction Register; 0x00000002 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Data Direction Port A Bit 0 */
        byte BIT1        :1;                                       /* Data Direction Port A Bit 1 */
        byte BIT2        :1;                                       /* Data Direction Port A Bit 2 */
        byte BIT3        :1;                                       /* Data Direction Port A Bit 3 */
        byte BIT4        :1;                                       /* Data Direction Port A Bit 4 */
        byte BIT5        :1;                                       /* Data Direction Port A Bit 5 */
        byte BIT6        :1;                                       /* Data Direction Port A Bit 6 */
        byte BIT7        :1;                                       /* Data Direction Port A Bit 7 */
      } Bits;
    } DDRASTR;
    #define DDRA                        _DDRAB.Overlap_STR.DDRASTR.Byte
    #define DDRA_BIT0                   _DDRAB.Overlap_STR.DDRASTR.Bits.BIT0
    #define DDRA_BIT1                   _DDRAB.Overlap_STR.DDRASTR.Bits.BIT1
    #define DDRA_BIT2                   _DDRAB.Overlap_STR.DDRASTR.Bits.BIT2
    #define DDRA_BIT3                   _DDRAB.Overlap_STR.DDRASTR.Bits.BIT3
    #define DDRA_BIT4                   _DDRAB.Overlap_STR.DDRASTR.Bits.BIT4
    #define DDRA_BIT5                   _DDRAB.Overlap_STR.DDRASTR.Bits.BIT5
    #define DDRA_BIT6                   _DDRAB.Overlap_STR.DDRASTR.Bits.BIT6
    #define DDRA_BIT7                   _DDRAB.Overlap_STR.DDRASTR.Bits.BIT7
    
    #define DDRA_BIT0_MASK              1U
    #define DDRA_BIT1_MASK              2U
    #define DDRA_BIT2_MASK              4U
    #define DDRA_BIT3_MASK              8U
    #define DDRA_BIT4_MASK              16U
    #define DDRA_BIT5_MASK              32U
    #define DDRA_BIT6_MASK              64U
    #define DDRA_BIT7_MASK              128U
    

    /*** DDRB - Port B Data Direction Register; 0x00000003 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Data Direction Port B Bit 0 */
        byte BIT1        :1;                                       /* Data Direction Port B Bit 1 */
        byte BIT2        :1;                                       /* Data Direction Port B Bit 2 */
        byte BIT3        :1;                                       /* Data Direction Port B Bit 3 */
        byte BIT4        :1;                                       /* Data Direction Port B Bit 4 */
        byte BIT5        :1;                                       /* Data Direction Port B Bit 5 */
        byte BIT6        :1;                                       /* Data Direction Port B Bit 6 */
        byte BIT7        :1;                                       /* Data Direction Port B Bit 7 */
      } Bits;
    } DDRBSTR;
    #define DDRB                        _DDRAB.Overlap_STR.DDRBSTR.Byte
    #define DDRB_BIT0                   _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT0
    #define DDRB_BIT1                   _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT1
    #define DDRB_BIT2                   _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT2
    #define DDRB_BIT3                   _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT3
    #define DDRB_BIT4                   _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT4
    #define DDRB_BIT5                   _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT5
    #define DDRB_BIT6                   _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT6
    #define DDRB_BIT7                   _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT7
    
    #define DDRB_BIT0_MASK              1U
    #define DDRB_BIT1_MASK              2U
    #define DDRB_BIT2_MASK              4U
    #define DDRB_BIT3_MASK              8U
    #define DDRB_BIT4_MASK              16U
    #define DDRB_BIT5_MASK              32U
    #define DDRB_BIT6_MASK              64U
    #define DDRB_BIT7_MASK              128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Data Direction Port AB Bit 0 */
    word BIT1        :1;                                       /* Data Direction Port AB Bit 1 */
    word BIT2        :1;                                       /* Data Direction Port AB Bit 2 */
    word BIT3        :1;                                       /* Data Direction Port AB Bit 3 */
    word BIT4        :1;                                       /* Data Direction Port AB Bit 4 */
    word BIT5        :1;                                       /* Data Direction Port AB Bit 5 */
    word BIT6        :1;                                       /* Data Direction Port AB Bit 6 */
    word BIT7        :1;                                       /* Data Direction Port AB Bit 7 */
    word BIT8        :1;                                       /* Data Direction Port AB Bit 8 */
    word BIT9        :1;                                       /* Data Direction Port AB Bit 9 */
    word BIT10       :1;                                       /* Data Direction Port AB Bit 10 */
    word BIT11       :1;                                       /* Data Direction Port AB Bit 11 */
    word BIT12       :1;                                       /* Data Direction Port AB Bit 12 */
    word BIT13       :1;                                       /* Data Direction Port AB Bit 13 */
    word BIT14       :1;                                       /* Data Direction Port AB Bit 14 */
    word BIT15       :1;                                       /* Data Direction Port AB Bit 15 */
  } Bits;
} DDRABSTR;
extern volatile DDRABSTR _DDRAB @(REG_BASE + 0x00000002UL);
#define DDRAB                           _DDRAB.Word
#define DDRAB_BIT0                      _DDRAB.Bits.BIT0
#define DDRAB_BIT1                      _DDRAB.Bits.BIT1
#define DDRAB_BIT2                      _DDRAB.Bits.BIT2
#define DDRAB_BIT3                      _DDRAB.Bits.BIT3
#define DDRAB_BIT4                      _DDRAB.Bits.BIT4
#define DDRAB_BIT5                      _DDRAB.Bits.BIT5
#define DDRAB_BIT6                      _DDRAB.Bits.BIT6
#define DDRAB_BIT7                      _DDRAB.Bits.BIT7
#define DDRAB_BIT8                      _DDRAB.Bits.BIT8
#define DDRAB_BIT9                      _DDRAB.Bits.BIT9
#define DDRAB_BIT10                     _DDRAB.Bits.BIT10
#define DDRAB_BIT11                     _DDRAB.Bits.BIT11
#define DDRAB_BIT12                     _DDRAB.Bits.BIT12
#define DDRAB_BIT13                     _DDRAB.Bits.BIT13
#define DDRAB_BIT14                     _DDRAB.Bits.BIT14
#define DDRAB_BIT15                     _DDRAB.Bits.BIT15

#define DDRAB_BIT0_MASK                 1U
#define DDRAB_BIT1_MASK                 2U
#define DDRAB_BIT2_MASK                 4U
#define DDRAB_BIT3_MASK                 8U
#define DDRAB_BIT4_MASK                 16U
#define DDRAB_BIT5_MASK                 32U
#define DDRAB_BIT6_MASK                 64U
#define DDRAB_BIT7_MASK                 128U
#define DDRAB_BIT8_MASK                 256U
#define DDRAB_BIT9_MASK                 512U
#define DDRAB_BIT10_MASK                1024U
#define DDRAB_BIT11_MASK                2048U
#define DDRAB_BIT12_MASK                4096U
#define DDRAB_BIT13_MASK                8192U
#define DDRAB_BIT14_MASK                16384U
#define DDRAB_BIT15_MASK                32768U


/*** PORTE - Port E Register; 0x00000008 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Port E Bit 0 */
    byte BIT1        :1;                                       /* Port E Bit 1 */
    byte BIT2        :1;                                       /* Port E Bit 2 */
    byte BIT3        :1;                                       /* Port E Bit 3 */
    byte BIT4        :1;                                       /* Port E Bit 4 */
    byte BIT5        :1;                                       /* Port E Bit 5 */
    byte BIT6        :1;                                       /* Port E Bit 6 */
    byte BIT7        :1;                                       /* Port E Bit 7 */
  } Bits;
} PORTESTR;
extern volatile PORTESTR _PORTE @(REG_BASE + 0x00000008UL);
#define PORTE                           _PORTE.Byte
#define PORTE_BIT0                      _PORTE.Bits.BIT0
#define PORTE_BIT1                      _PORTE.Bits.BIT1
#define PORTE_BIT2                      _PORTE.Bits.BIT2
#define PORTE_BIT3                      _PORTE.Bits.BIT3
#define PORTE_BIT4                      _PORTE.Bits.BIT4
#define PORTE_BIT5                      _PORTE.Bits.BIT5
#define PORTE_BIT6                      _PORTE.Bits.BIT6
#define PORTE_BIT7                      _PORTE.Bits.BIT7

#define PORTE_BIT0_MASK                 1U
#define PORTE_BIT1_MASK                 2U
#define PORTE_BIT2_MASK                 4U
#define PORTE_BIT3_MASK                 8U
#define PORTE_BIT4_MASK                 16U
#define PORTE_BIT5_MASK                 32U
#define PORTE_BIT6_MASK                 64U
#define PORTE_BIT7_MASK                 128U


/*** DDRE - Port E Data Direction Register; 0x00000009 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte BIT2        :1;                                       /* Data Direction Port E Bit 2 */
    byte BIT3        :1;                                       /* Data Direction Port E Bit 3 */
    byte BIT4        :1;                                       /* Data Direction Port E Bit 4 */
    byte BIT5        :1;                                       /* Data Direction Port E Bit 5 */
    byte BIT6        :1;                                       /* Data Direction Port E Bit 6 */
    byte BIT7        :1;                                       /* Data Direction Port E Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpBIT_2 :6;
  } MergedBits;
} DDRESTR;
extern volatile DDRESTR _DDRE @(REG_BASE + 0x00000009UL);
#define DDRE                            _DDRE.Byte
#define DDRE_BIT2                       _DDRE.Bits.BIT2
#define DDRE_BIT3                       _DDRE.Bits.BIT3
#define DDRE_BIT4                       _DDRE.Bits.BIT4
#define DDRE_BIT5                       _DDRE.Bits.BIT5
#define DDRE_BIT6                       _DDRE.Bits.BIT6
#define DDRE_BIT7                       _DDRE.Bits.BIT7
#define DDRE_BIT_2                      _DDRE.MergedBits.grpBIT_2
#define DDRE_BIT                        DDRE_BIT_2

#define DDRE_BIT2_MASK                  4U
#define DDRE_BIT3_MASK                  8U
#define DDRE_BIT4_MASK                  16U
#define DDRE_BIT5_MASK                  32U
#define DDRE_BIT6_MASK                  64U
#define DDRE_BIT7_MASK                  128U
#define DDRE_BIT_2_MASK                 252U
#define DDRE_BIT_2_BITNUM               2U


/*** PEAR - Port E Assignment Register; 0x0000000A ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte RDWE        :1;                                       /* Read / Write Enable */
    byte LSTRE       :1;                                       /* Low Strobe (LSTRB) Enable */
    byte NECLK       :1;                                       /* No External E Clock */
    byte PIPOE       :1;                                       /* Pipe Status Signal Output Enable */
    byte             :1; 
    byte NOACCE      :1;                                       /* CPU No Access Output Enable */
  } Bits;
} PEARSTR;
extern volatile PEARSTR _PEAR @(REG_BASE + 0x0000000AUL);
#define PEAR                            _PEAR.Byte
#define PEAR_RDWE                       _PEAR.Bits.RDWE
#define PEAR_LSTRE                      _PEAR.Bits.LSTRE
#define PEAR_NECLK                      _PEAR.Bits.NECLK
#define PEAR_PIPOE                      _PEAR.Bits.PIPOE
#define PEAR_NOACCE                     _PEAR.Bits.NOACCE

#define PEAR_RDWE_MASK                  4U
#define PEAR_LSTRE_MASK                 8U
#define PEAR_NECLK_MASK                 16U
#define PEAR_PIPOE_MASK                 32U
#define PEAR_NOACCE_MASK                128U


/*** MODE - Mode Register; 0x0000000B ***/
typedef union {
  byte Byte;
  struct {
    byte EME         :1;                                       /* Emulate Port E */
    byte EMK         :1;                                       /* Emulate Port K */
    byte             :1; 
    byte IVIS        :1;                                       /* Internal Visibility */
    byte             :1; 
    byte MODA        :1;                                       /* Mode Select Bit A */
    byte MODB        :1;                                       /* Mode Select Bit B */
    byte MODC        :1;                                       /* Mode Select Bit C */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpMODx :3;
  } MergedBits;
} MODESTR;
extern volatile MODESTR _MODE @(REG_BASE + 0x0000000BUL);
#define MODE                            _MODE.Byte
#define MODE_EME                        _MODE.Bits.EME
#define MODE_EMK                        _MODE.Bits.EMK
#define MODE_IVIS                       _MODE.Bits.IVIS
#define MODE_MODA                       _MODE.Bits.MODA
#define MODE_MODB                       _MODE.Bits.MODB
#define MODE_MODC                       _MODE.Bits.MODC
#define MODE_MODx                       _MODE.MergedBits.grpMODx

#define MODE_EME_MASK                   1U
#define MODE_EMK_MASK                   2U
#define MODE_IVIS_MASK                  8U
#define MODE_MODA_MASK                  32U
#define MODE_MODB_MASK                  64U
#define MODE_MODC_MASK                  128U
#define MODE_MODx_MASK                  224U
#define MODE_MODx_BITNUM                5U


/*** PUCR - Pull-Up Control Register; 0x0000000C ***/
typedef union {
  byte Byte;
  struct {
    byte PUPAE       :1;                                       /* Pull-Up Port A Enable */
    byte PUPBE       :1;                                       /* Pull-Up Port B Enable */
    byte             :1; 
    byte             :1; 
    byte PUPEE       :1;                                       /* Pull-Up Port E Enable */
    byte             :1; 
    byte             :1; 
    byte PUPKE       :1;                                       /* Pull-Up Port K Enable */
  } Bits;
} PUCRSTR;
extern volatile PUCRSTR _PUCR @(REG_BASE + 0x0000000CUL);
#define PUCR                            _PUCR.Byte
#define PUCR_PUPAE                      _PUCR.Bits.PUPAE
#define PUCR_PUPBE                      _PUCR.Bits.PUPBE
#define PUCR_PUPEE                      _PUCR.Bits.PUPEE
#define PUCR_PUPKE                      _PUCR.Bits.PUPKE

#define PUCR_PUPAE_MASK                 1U
#define PUCR_PUPBE_MASK                 2U
#define PUCR_PUPEE_MASK                 16U
#define PUCR_PUPKE_MASK                 128U


/*** RDRIV - Reduced Drive of I/O Lines; 0x0000000D ***/
typedef union {
  byte Byte;
  struct {
    byte RDPA        :1;                                       /* Reduced Drive of Port A */
    byte RDPB        :1;                                       /* Reduced Drive of Port B */
    byte             :1; 
    byte             :1; 
    byte RDPE        :1;                                       /* Reduced Drive of Port E */
    byte             :1; 
    byte             :1; 
    byte RDPK        :1;                                       /* Reduced Drive of Port K */
  } Bits;
  struct {
    byte grpRDPx :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} RDRIVSTR;
extern volatile RDRIVSTR _RDRIV @(REG_BASE + 0x0000000DUL);
#define RDRIV                           _RDRIV.Byte
#define RDRIV_RDPA                      _RDRIV.Bits.RDPA
#define RDRIV_RDPB                      _RDRIV.Bits.RDPB
#define RDRIV_RDPE                      _RDRIV.Bits.RDPE
#define RDRIV_RDPK                      _RDRIV.Bits.RDPK
#define RDRIV_RDPx                      _RDRIV.MergedBits.grpRDPx

#define RDRIV_RDPA_MASK                 1U
#define RDRIV_RDPB_MASK                 2U
#define RDRIV_RDPE_MASK                 16U
#define RDRIV_RDPK_MASK                 128U
#define RDRIV_RDPx_MASK                 3U
#define RDRIV_RDPx_BITNUM               0U


/*** EBICTL - External Bus Interface Control; 0x0000000E ***/
typedef union {
  byte Byte;
  struct {
    byte ESTR        :1;                                       /* E Stretches */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} EBICTLSTR;
extern volatile EBICTLSTR _EBICTL @(REG_BASE + 0x0000000EUL);
#define EBICTL                          _EBICTL.Byte
#define EBICTL_ESTR                     _EBICTL.Bits.ESTR

#define EBICTL_ESTR_MASK                1U


/*** INITRM - Initialization of Internal RAM Position Register; 0x00000010 ***/
typedef union {
  byte Byte;
  struct {
    byte RAMHAL      :1;                                       /* Internal RAM map alignment */
    byte             :1; 
    byte             :1; 
    byte RAM11       :1;                                       /* Internal RAM map position Bit 11 */
    byte RAM12       :1;                                       /* Internal RAM map position Bit 12 */
    byte RAM13       :1;                                       /* Internal RAM map position Bit 13 */
    byte RAM14       :1;                                       /* Internal RAM map position Bit 14 */
    byte RAM15       :1;                                       /* Internal RAM map position Bit 15 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpRAM_11 :5;
  } MergedBits;
} INITRMSTR;
extern volatile INITRMSTR _INITRM @(REG_BASE + 0x00000010UL);
#define INITRM                          _INITRM.Byte
#define INITRM_RAMHAL                   _INITRM.Bits.RAMHAL
#define INITRM_RAM11                    _INITRM.Bits.RAM11
#define INITRM_RAM12                    _INITRM.Bits.RAM12
#define INITRM_RAM13                    _INITRM.Bits.RAM13
#define INITRM_RAM14                    _INITRM.Bits.RAM14
#define INITRM_RAM15                    _INITRM.Bits.RAM15
#define INITRM_RAM_11                   _INITRM.MergedBits.grpRAM_11
#define INITRM_RAM                      INITRM_RAM_11

#define INITRM_RAMHAL_MASK              1U
#define INITRM_RAM11_MASK               8U
#define INITRM_RAM12_MASK               16U
#define INITRM_RAM13_MASK               32U
#define INITRM_RAM14_MASK               64U
#define INITRM_RAM15_MASK               128U
#define INITRM_RAM_11_MASK              248U
#define INITRM_RAM_11_BITNUM            3U


/*** INITRG - Initialization of Internal Registers Position Register; 0x00000011 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte REG11       :1;                                       /* Internal Registers Map Position Bit 11 */
    byte REG12       :1;                                       /* Internal Registers Map Position Bit 12 */
    byte REG13       :1;                                       /* Internal Registers Map Position Bit 13 */
    byte REG14       :1;                                       /* Internal Registers Map Position Bit 14 */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpREG_11 :4;
    byte         :1;
  } MergedBits;
} INITRGSTR;
extern volatile INITRGSTR _INITRG @(REG_BASE + 0x00000011UL);
#define INITRG                          _INITRG.Byte
#define INITRG_REG11                    _INITRG.Bits.REG11
#define INITRG_REG12                    _INITRG.Bits.REG12
#define INITRG_REG13                    _INITRG.Bits.REG13
#define INITRG_REG14                    _INITRG.Bits.REG14
#define INITRG_REG_11                   _INITRG.MergedBits.grpREG_11
#define INITRG_REG                      INITRG_REG_11

#define INITRG_REG11_MASK               8U
#define INITRG_REG12_MASK               16U
#define INITRG_REG13_MASK               32U
#define INITRG_REG14_MASK               64U
#define INITRG_REG_11_MASK              120U
#define INITRG_REG_11_BITNUM            3U


/*** MISC - Miscellaneous System Control Register; 0x00000013 ***/
typedef union {
  byte Byte;
  struct {
    byte ROMON       :1;                                       /* Enable Flash EEPROM */
    byte ROMHM       :1;                                       /* Flash EEPROM only in second half of memory map */
    byte EXSTR0      :1;                                       /* External Access Stretch Bit 0 */
    byte EXSTR1      :1;                                       /* External Access Stretch Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpEXSTR :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MISCSTR;
extern volatile MISCSTR _MISC @(REG_BASE + 0x00000013UL);
#define MISC                            _MISC.Byte
#define MISC_ROMON                      _MISC.Bits.ROMON
#define MISC_ROMHM                      _MISC.Bits.ROMHM
#define MISC_EXSTR0                     _MISC.Bits.EXSTR0
#define MISC_EXSTR1                     _MISC.Bits.EXSTR1
#define MISC_EXSTR                      _MISC.MergedBits.grpEXSTR

#define MISC_ROMON_MASK                 1U
#define MISC_ROMHM_MASK                 2U
#define MISC_EXSTR0_MASK                4U
#define MISC_EXSTR1_MASK                8U
#define MISC_EXSTR_MASK                 12U
#define MISC_EXSTR_BITNUM               2U


/*** ITCR - Interrupt Test Control Register; 0x00000015 ***/
typedef union {
  byte Byte;
  struct {
    byte ADR0        :1;                                       /* Test register select Bit 0 */
    byte ADR1        :1;                                       /* Test register select Bit 1 */
    byte ADR2        :1;                                       /* Test register select Bit 2 */
    byte ADR3        :1;                                       /* Test register select Bit 3 */
    byte WRTINT      :1;                                       /* Write to the Interrupt Test Registers */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpADR  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ITCRSTR;
extern volatile ITCRSTR _ITCR @(REG_BASE + 0x00000015UL);
#define ITCR                            _ITCR.Byte
#define ITCR_ADR0                       _ITCR.Bits.ADR0
#define ITCR_ADR1                       _ITCR.Bits.ADR1
#define ITCR_ADR2                       _ITCR.Bits.ADR2
#define ITCR_ADR3                       _ITCR.Bits.ADR3
#define ITCR_WRTINT                     _ITCR.Bits.WRTINT
#define ITCR_ADR                        _ITCR.MergedBits.grpADR

#define ITCR_ADR0_MASK                  1U
#define ITCR_ADR1_MASK                  2U
#define ITCR_ADR2_MASK                  4U
#define ITCR_ADR3_MASK                  8U
#define ITCR_WRTINT_MASK                16U
#define ITCR_ADR_MASK                   15U
#define ITCR_ADR_BITNUM                 0U


/*** ITEST - Interrupt Test Register; 0x00000016 ***/
typedef union {
  byte Byte;
  struct {
    byte INT0        :1;                                       /* Interrupt Test Register Bit 0 */
    byte INT2        :1;                                       /* Interrupt Test Register Bit 1 */
    byte INT4        :1;                                       /* Interrupt Test Register Bit 2 */
    byte INT6        :1;                                       /* Interrupt Test Register Bit 3 */
    byte INT8        :1;                                       /* Interrupt Test Register Bit 4 */
    byte INTA        :1;                                       /* Interrupt Test Register Bit 5 */
    byte INTC        :1;                                       /* Interrupt Test Register Bit 6 */
    byte INTE        :1;                                       /* Interrupt Test Register Bit 7 */
  } Bits;
} ITESTSTR;
extern volatile ITESTSTR _ITEST @(REG_BASE + 0x00000016UL);
#define ITEST                           _ITEST.Byte
#define ITEST_INT0                      _ITEST.Bits.INT0
#define ITEST_INT2                      _ITEST.Bits.INT2
#define ITEST_INT4                      _ITEST.Bits.INT4
#define ITEST_INT6                      _ITEST.Bits.INT6
#define ITEST_INT8                      _ITEST.Bits.INT8
#define ITEST_INTA                      _ITEST.Bits.INTA
#define ITEST_INTC                      _ITEST.Bits.INTC
#define ITEST_INTE                      _ITEST.Bits.INTE

#define ITEST_INT0_MASK                 1U
#define ITEST_INT2_MASK                 2U
#define ITEST_INT4_MASK                 4U
#define ITEST_INT6_MASK                 8U
#define ITEST_INT8_MASK                 16U
#define ITEST_INTA_MASK                 32U
#define ITEST_INTC_MASK                 64U
#define ITEST_INTE_MASK                 128U


/*** VREGCTRL - VREG_3V3 - Control Register; 0x00000019 ***/
typedef union {
  byte Byte;
  struct {
    byte LVIF        :1;                                       /* Low Voltage Interrupt Flag */
    byte LVIE        :1;                                       /* Low Voltage Interrupt Enable Bit */
    byte LVDS        :1;                                       /* Low Voltage Detect Status Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} VREGCTRLSTR;
extern volatile VREGCTRLSTR _VREGCTRL @(REG_BASE + 0x00000019UL);
#define VREGCTRL                        _VREGCTRL.Byte
#define VREGCTRL_LVIF                   _VREGCTRL.Bits.LVIF
#define VREGCTRL_LVIE                   _VREGCTRL.Bits.LVIE
#define VREGCTRL_LVDS                   _VREGCTRL.Bits.LVDS

#define VREGCTRL_LVIF_MASK              1U
#define VREGCTRL_LVIE_MASK              2U
#define VREGCTRL_LVDS_MASK              4U


/*** PARTID - Part ID Register; 0x0000001A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PARTIDH - Part ID Register High; 0x0000001A ***/
    union {
      byte Byte;
      struct {
        byte ID8         :1;                                       /* Part ID Register Bit 8 */
        byte ID9         :1;                                       /* Part ID Register Bit 9 */
        byte ID10        :1;                                       /* Part ID Register Bit 10 */
        byte ID11        :1;                                       /* Part ID Register Bit 11 */
        byte ID12        :1;                                       /* Part ID Register Bit 12 */
        byte ID13        :1;                                       /* Part ID Register Bit 13 */
        byte ID14        :1;                                       /* Part ID Register Bit 14 */
        byte ID15        :1;                                       /* Part ID Register Bit 15 */
      } Bits;
    } PARTIDHSTR;
    #define PARTIDH                     _PARTID.Overlap_STR.PARTIDHSTR.Byte
    #define PARTIDH_ID8                 _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID8
    #define PARTIDH_ID9                 _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID9
    #define PARTIDH_ID10                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID10
    #define PARTIDH_ID11                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID11
    #define PARTIDH_ID12                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID12
    #define PARTIDH_ID13                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID13
    #define PARTIDH_ID14                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID14
    #define PARTIDH_ID15                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID15
    
    #define PARTIDH_ID8_MASK            1U
    #define PARTIDH_ID9_MASK            2U
    #define PARTIDH_ID10_MASK           4U
    #define PARTIDH_ID11_MASK           8U
    #define PARTIDH_ID12_MASK           16U
    #define PARTIDH_ID13_MASK           32U
    #define PARTIDH_ID14_MASK           64U
    #define PARTIDH_ID15_MASK           128U
    

    /*** PARTIDL - Part ID Register Low; 0x0000001B ***/
    union {
      byte Byte;
      struct {
        byte ID0         :1;                                       /* Part ID Register Bit 0 */
        byte ID1         :1;                                       /* Part ID Register Bit 1 */
        byte ID2         :1;                                       /* Part ID Register Bit 2 */
        byte ID3         :1;                                       /* Part ID Register Bit 3 */
        byte ID4         :1;                                       /* Part ID Register Bit 4 */
        byte ID5         :1;                                       /* Part ID Register Bit 5 */
        byte ID6         :1;                                       /* Part ID Register Bit 6 */
        byte ID7         :1;                                       /* Part ID Register Bit 7 */
      } Bits;
    } PARTIDLSTR;
    #define PARTIDL                     _PARTID.Overlap_STR.PARTIDLSTR.Byte
    #define PARTIDL_ID0                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID0
    #define PARTIDL_ID1                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID1
    #define PARTIDL_ID2                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID2
    #define PARTIDL_ID3                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID3
    #define PARTIDL_ID4                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID4
    #define PARTIDL_ID5                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID5
    #define PARTIDL_ID6                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID6
    #define PARTIDL_ID7                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID7
    
    #define PARTIDL_ID0_MASK            1U
    #define PARTIDL_ID1_MASK            2U
    #define PARTIDL_ID2_MASK            4U
    #define PARTIDL_ID3_MASK            8U
    #define PARTIDL_ID4_MASK            16U
    #define PARTIDL_ID5_MASK            32U
    #define PARTIDL_ID6_MASK            64U
    #define PARTIDL_ID7_MASK            128U
    
  } Overlap_STR;

  struct {
    word ID0         :1;                                       /* Part ID Register Bit 0 */
    word ID1         :1;                                       /* Part ID Register Bit 1 */
    word ID2         :1;                                       /* Part ID Register Bit 2 */
    word ID3         :1;                                       /* Part ID Register Bit 3 */
    word ID4         :1;                                       /* Part ID Register Bit 4 */
    word ID5         :1;                                       /* Part ID Register Bit 5 */
    word ID6         :1;                                       /* Part ID Register Bit 6 */
    word ID7         :1;                                       /* Part ID Register Bit 7 */
    word ID8         :1;                                       /* Part ID Register Bit 8 */
    word ID9         :1;                                       /* Part ID Register Bit 9 */
    word ID10        :1;                                       /* Part ID Register Bit 10 */
    word ID11        :1;                                       /* Part ID Register Bit 11 */
    word ID12        :1;                                       /* Part ID Register Bit 12 */
    word ID13        :1;                                       /* Part ID Register Bit 13 */
    word ID14        :1;                                       /* Part ID Register Bit 14 */
    word ID15        :1;                                       /* Part ID Register Bit 15 */
  } Bits;
} PARTIDSTR;
extern volatile PARTIDSTR _PARTID @(REG_BASE + 0x0000001AUL);
#define PARTID                          _PARTID.Word
#define PARTID_ID0                      _PARTID.Bits.ID0
#define PARTID_ID1                      _PARTID.Bits.ID1
#define PARTID_ID2                      _PARTID.Bits.ID2
#define PARTID_ID3                      _PARTID.Bits.ID3
#define PARTID_ID4                      _PARTID.Bits.ID4
#define PARTID_ID5                      _PARTID.Bits.ID5
#define PARTID_ID6                      _PARTID.Bits.ID6
#define PARTID_ID7                      _PARTID.Bits.ID7
#define PARTID_ID8                      _PARTID.Bits.ID8
#define PARTID_ID9                      _PARTID.Bits.ID9
#define PARTID_ID10                     _PARTID.Bits.ID10
#define PARTID_ID11                     _PARTID.Bits.ID11
#define PARTID_ID12                     _PARTID.Bits.ID12
#define PARTID_ID13                     _PARTID.Bits.ID13
#define PARTID_ID14                     _PARTID.Bits.ID14
#define PARTID_ID15                     _PARTID.Bits.ID15

#define PARTID_ID0_MASK                 1U
#define PARTID_ID1_MASK                 2U
#define PARTID_ID2_MASK                 4U
#define PARTID_ID3_MASK                 8U
#define PARTID_ID4_MASK                 16U
#define PARTID_ID5_MASK                 32U
#define PARTID_ID6_MASK                 64U
#define PARTID_ID7_MASK                 128U
#define PARTID_ID8_MASK                 256U
#define PARTID_ID9_MASK                 512U
#define PARTID_ID10_MASK                1024U
#define PARTID_ID11_MASK                2048U
#define PARTID_ID12_MASK                4096U
#define PARTID_ID13_MASK                8192U
#define PARTID_ID14_MASK                16384U
#define PARTID_ID15_MASK                32768U


/*** MEMSIZ0 - Memory Size Register Zero; 0x0000001C ***/
typedef union {
  byte Byte;
  struct {
    byte ram_sw0     :1;                                       /* Allocated System RAM Memory Space Bit 0 */
    byte ram_sw1     :1;                                       /* Allocated System RAM Memory Space Bit 1 */
    byte ram_sw2     :1;                                       /* Allocated System RAM Memory Space Bit 2 */
    byte             :1; 
    byte eep_sw0     :1;                                       /* Allocated EEPROM Memory Space Bit 0 */
    byte eep_sw1     :1;                                       /* Allocated EEPROM Memory Space Bit 1 */
    byte             :1; 
    byte reg_sw0     :1;                                       /* Allocated System Register Space */
  } Bits;
  struct {
    byte grpram_sw :3;
    byte         :1;
    byte grpeep_sw :2;
    byte         :1;
    byte grpreg_sw :1;
  } MergedBits;
} MEMSIZ0STR;
extern volatile MEMSIZ0STR _MEMSIZ0 @(REG_BASE + 0x0000001CUL);
#define MEMSIZ0                         _MEMSIZ0.Byte
#define MEMSIZ0_ram_sw0                 _MEMSIZ0.Bits.ram_sw0
#define MEMSIZ0_ram_sw1                 _MEMSIZ0.Bits.ram_sw1
#define MEMSIZ0_ram_sw2                 _MEMSIZ0.Bits.ram_sw2
#define MEMSIZ0_eep_sw0                 _MEMSIZ0.Bits.eep_sw0
#define MEMSIZ0_eep_sw1                 _MEMSIZ0.Bits.eep_sw1
#define MEMSIZ0_reg_sw0                 _MEMSIZ0.Bits.reg_sw0
/* MEMSIZ_ARR: Access 2 MEMSIZx registers in an array */
#define MEMSIZ_ARR                      ((volatile byte *) &MEMSIZ0)
#define MEMSIZ0_ram_sw                  _MEMSIZ0.MergedBits.grpram_sw
#define MEMSIZ0_eep_sw                  _MEMSIZ0.MergedBits.grpeep_sw

#define MEMSIZ0_ram_sw0_MASK            1U
#define MEMSIZ0_ram_sw1_MASK            2U
#define MEMSIZ0_ram_sw2_MASK            4U
#define MEMSIZ0_eep_sw0_MASK            16U
#define MEMSIZ0_eep_sw1_MASK            32U
#define MEMSIZ0_reg_sw0_MASK            128U
#define MEMSIZ0_ram_sw_MASK             7U
#define MEMSIZ0_ram_sw_BITNUM           0U
#define MEMSIZ0_eep_sw_MASK             48U
#define MEMSIZ0_eep_sw_BITNUM           4U


/*** MEMSIZ1 - Memory Size Register One; 0x0000001D ***/
typedef union {
  byte Byte;
  struct {
    byte pag_sw0     :1;                                       /* Allocated Off-Chip Memory Options Bit 0 */
    byte pag_sw1     :1;                                       /* Allocated Off-Chip Memory Options Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte rom_sw0     :1;                                       /* Allocated Flash EEPROM/ROM Physical Memory Space Bit 0 */
    byte rom_sw1     :1;                                       /* Allocated Flash EEPROM/ROM Physical Memory Space Bit 1 */
  } Bits;
  struct {
    byte grppag_sw :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grprom_sw :2;
  } MergedBits;
} MEMSIZ1STR;
extern volatile MEMSIZ1STR _MEMSIZ1 @(REG_BASE + 0x0000001DUL);
#define MEMSIZ1                         _MEMSIZ1.Byte
#define MEMSIZ1_pag_sw0                 _MEMSIZ1.Bits.pag_sw0
#define MEMSIZ1_pag_sw1                 _MEMSIZ1.Bits.pag_sw1
#define MEMSIZ1_rom_sw0                 _MEMSIZ1.Bits.rom_sw0
#define MEMSIZ1_rom_sw1                 _MEMSIZ1.Bits.rom_sw1
#define MEMSIZ1_pag_sw                  _MEMSIZ1.MergedBits.grppag_sw
#define MEMSIZ1_rom_sw                  _MEMSIZ1.MergedBits.grprom_sw

#define MEMSIZ1_pag_sw0_MASK            1U
#define MEMSIZ1_pag_sw1_MASK            2U
#define MEMSIZ1_rom_sw0_MASK            64U
#define MEMSIZ1_rom_sw1_MASK            128U
#define MEMSIZ1_pag_sw_MASK             3U
#define MEMSIZ1_pag_sw_BITNUM           0U
#define MEMSIZ1_rom_sw_MASK             192U
#define MEMSIZ1_rom_sw_BITNUM           6U


/*** INTCR - Interrupt Control Register; 0x0000001E ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte IRQEN       :1;                                       /* External IRQ Enable */
    byte IRQE        :1;                                       /* IRQ Select Edge Sensitive Only */
  } Bits;
} INTCRSTR;
extern volatile INTCRSTR _INTCR @(REG_BASE + 0x0000001EUL);
#define INTCR                           _INTCR.Byte
#define INTCR_IRQEN                     _INTCR.Bits.IRQEN
#define INTCR_IRQE                      _INTCR.Bits.IRQE

#define INTCR_IRQEN_MASK                64U
#define INTCR_IRQE_MASK                 128U


/*** HPRIO - Highest Priority I Interrupt; 0x0000001F ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte PSEL1       :1;                                       /* Highest Priority I Interrupt Bit 1 */
    byte PSEL2       :1;                                       /* Highest Priority I Interrupt Bit 2 */
    byte PSEL3       :1;                                       /* Highest Priority I Interrupt Bit 3 */
    byte PSEL4       :1;                                       /* Highest Priority I Interrupt Bit 4 */
    byte PSEL5       :1;                                       /* Highest Priority I Interrupt Bit 5 */
    byte PSEL6       :1;                                       /* Highest Priority I Interrupt Bit 6 */
    byte PSEL7       :1;                                       /* Highest Priority I Interrupt Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpPSEL_1 :7;
  } MergedBits;
} HPRIOSTR;
extern volatile HPRIOSTR _HPRIO @(REG_BASE + 0x0000001FUL);
#define HPRIO                           _HPRIO.Byte
#define HPRIO_PSEL1                     _HPRIO.Bits.PSEL1
#define HPRIO_PSEL2                     _HPRIO.Bits.PSEL2
#define HPRIO_PSEL3                     _HPRIO.Bits.PSEL3
#define HPRIO_PSEL4                     _HPRIO.Bits.PSEL4
#define HPRIO_PSEL5                     _HPRIO.Bits.PSEL5
#define HPRIO_PSEL6                     _HPRIO.Bits.PSEL6
#define HPRIO_PSEL7                     _HPRIO.Bits.PSEL7
#define HPRIO_PSEL_1                    _HPRIO.MergedBits.grpPSEL_1
#define HPRIO_PSEL                      HPRIO_PSEL_1

#define HPRIO_PSEL1_MASK                2U
#define HPRIO_PSEL2_MASK                4U
#define HPRIO_PSEL3_MASK                8U
#define HPRIO_PSEL4_MASK                16U
#define HPRIO_PSEL5_MASK                32U
#define HPRIO_PSEL6_MASK                64U
#define HPRIO_PSEL7_MASK                128U
#define HPRIO_PSEL_1_MASK               254U
#define HPRIO_PSEL_1_BITNUM             1U


/*** DBGC1 - Debug Control Register 1; 0x00000020 ***/
typedef union {
  byte Byte;
  struct {
    byte CAPMOD0     :1;                                       /* Capture Mode Field, bit 0 */
    byte CAPMOD1     :1;                                       /* Capture Mode Field, bit 1 */
    byte             :1; 
    byte DBGBRK      :1;                                       /* DBG Breakpoint Enable Bit */
    byte BEGIN       :1;                                       /* Begin/End Trigger Bit */
    byte TRGSEL      :1;                                       /* Trigger Selection Bit */
    byte ARM         :1;                                       /* Arm Bit */
    byte DBGEN       :1;                                       /* DBG Mode Enable Bit */
  } Bits;
  struct {
    byte grpCAPMOD :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGC1STR;
extern volatile DBGC1STR _DBGC1 @(REG_BASE + 0x00000020UL);
#define DBGC1                           _DBGC1.Byte
#define DBGC1_CAPMOD0                   _DBGC1.Bits.CAPMOD0
#define DBGC1_CAPMOD1                   _DBGC1.Bits.CAPMOD1
#define DBGC1_DBGBRK                    _DBGC1.Bits.DBGBRK
#define DBGC1_BEGIN                     _DBGC1.Bits.BEGIN
#define DBGC1_TRGSEL                    _DBGC1.Bits.TRGSEL
#define DBGC1_ARM                       _DBGC1.Bits.ARM
#define DBGC1_DBGEN                     _DBGC1.Bits.DBGEN
#define DBGC1_CAPMOD                    _DBGC1.MergedBits.grpCAPMOD

#define DBGC1_CAPMOD0_MASK              1U
#define DBGC1_CAPMOD1_MASK              2U
#define DBGC1_DBGBRK_MASK               8U
#define DBGC1_BEGIN_MASK                16U
#define DBGC1_TRGSEL_MASK               32U
#define DBGC1_ARM_MASK                  64U
#define DBGC1_DBGEN_MASK                128U
#define DBGC1_CAPMOD_MASK               3U
#define DBGC1_CAPMOD_BITNUM             0U


/*** DBGSC - Debug Status and Control Register; 0x00000021 ***/
typedef union {
  byte Byte;
  struct {
    byte TRG0        :1;                                       /* Trigger Mode Bits, bit 0 */
    byte TRG1        :1;                                       /* Trigger Mode Bits, bit 1 */
    byte TRG2        :1;                                       /* Trigger Mode Bits, bit 2 */
    byte TRG3        :1;                                       /* Trigger Mode Bits, bit 3 */
    byte             :1; 
    byte CF          :1;                                       /* Comparator C Match Flag */
    byte BF          :1;                                       /* Trigger B Match Flag */
    byte AF          :1;                                       /* Trigger A Match Flag */
  } Bits;
  struct {
    byte grpTRG  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGSCSTR;
extern volatile DBGSCSTR _DBGSC @(REG_BASE + 0x00000021UL);
#define DBGSC                           _DBGSC.Byte
#define DBGSC_TRG0                      _DBGSC.Bits.TRG0
#define DBGSC_TRG1                      _DBGSC.Bits.TRG1
#define DBGSC_TRG2                      _DBGSC.Bits.TRG2
#define DBGSC_TRG3                      _DBGSC.Bits.TRG3
#define DBGSC_CF                        _DBGSC.Bits.CF
#define DBGSC_BF                        _DBGSC.Bits.BF
#define DBGSC_AF                        _DBGSC.Bits.AF
#define DBGSC_TRG                       _DBGSC.MergedBits.grpTRG

#define DBGSC_TRG0_MASK                 1U
#define DBGSC_TRG1_MASK                 2U
#define DBGSC_TRG2_MASK                 4U
#define DBGSC_TRG3_MASK                 8U
#define DBGSC_CF_MASK                   32U
#define DBGSC_BF_MASK                   64U
#define DBGSC_AF_MASK                   128U
#define DBGSC_TRG_MASK                  15U
#define DBGSC_TRG_BITNUM                0U


/*** DBGTB - Debug Trace Buffer Register; 0x00000022 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGTBH - Debug Trace Buffer Register High; 0x00000022 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Trace Buffer Data Bit 8 */
        byte BIT9        :1;                                       /* Trace Buffer Data Bit 9 */
        byte BIT10       :1;                                       /* Trace Buffer Data Bit 10 */
        byte BIT11       :1;                                       /* Trace Buffer Data Bit 11 */
        byte BIT12       :1;                                       /* Trace Buffer Data Bit 12 */
        byte BIT13       :1;                                       /* Trace Buffer Data Bit 13 */
        byte BIT14       :1;                                       /* Trace Buffer Data Bit 14 */
        byte BIT15       :1;                                       /* Trace Buffer Data Bit 15 */
      } Bits;
    } DBGTBHSTR;
    #define DBGTBH                      _DBGTB.Overlap_STR.DBGTBHSTR.Byte
    #define DBGTBH_BIT8                 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT8
    #define DBGTBH_BIT9                 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT9
    #define DBGTBH_BIT10                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT10
    #define DBGTBH_BIT11                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT11
    #define DBGTBH_BIT12                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT12
    #define DBGTBH_BIT13                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT13
    #define DBGTBH_BIT14                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT14
    #define DBGTBH_BIT15                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT15
    
    #define DBGTBH_BIT8_MASK            1U
    #define DBGTBH_BIT9_MASK            2U
    #define DBGTBH_BIT10_MASK           4U
    #define DBGTBH_BIT11_MASK           8U
    #define DBGTBH_BIT12_MASK           16U
    #define DBGTBH_BIT13_MASK           32U
    #define DBGTBH_BIT14_MASK           64U
    #define DBGTBH_BIT15_MASK           128U
    

    /*** DBGTBL - Debug Trace Buffer Register Low; 0x00000023 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Trace Buffer Data Bit 0 */
        byte BIT1        :1;                                       /* Trace Buffer Data Bit 1 */
        byte BIT2        :1;                                       /* Trace Buffer Data Bit 2 */
        byte BIT3        :1;                                       /* Trace Buffer Data Bit 3 */
        byte BIT4        :1;                                       /* Trace Buffer Data Bit 4 */
        byte BIT5        :1;                                       /* Trace Buffer Data Bit 5 */
        byte BIT6        :1;                                       /* Trace Buffer Data Bit 6 */
        byte BIT7        :1;                                       /* Trace Buffer Data Bit 7 */
      } Bits;
    } DBGTBLSTR;
    #define DBGTBL                      _DBGTB.Overlap_STR.DBGTBLSTR.Byte
    #define DBGTBL_BIT0                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT0
    #define DBGTBL_BIT1                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT1
    #define DBGTBL_BIT2                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT2
    #define DBGTBL_BIT3                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT3
    #define DBGTBL_BIT4                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT4
    #define DBGTBL_BIT5                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT5
    #define DBGTBL_BIT6                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT6
    #define DBGTBL_BIT7                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT7
    
    #define DBGTBL_BIT0_MASK            1U
    #define DBGTBL_BIT1_MASK            2U
    #define DBGTBL_BIT2_MASK            4U
    #define DBGTBL_BIT3_MASK            8U
    #define DBGTBL_BIT4_MASK            16U
    #define DBGTBL_BIT5_MASK            32U
    #define DBGTBL_BIT6_MASK            64U
    #define DBGTBL_BIT7_MASK            128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Trace Buffer Data Bit 0 */
    word BIT1        :1;                                       /* Trace Buffer Data Bit 1 */
    word BIT2        :1;                                       /* Trace Buffer Data Bit 2 */
    word BIT3        :1;                                       /* Trace Buffer Data Bit 3 */
    word BIT4        :1;                                       /* Trace Buffer Data Bit 4 */
    word BIT5        :1;                                       /* Trace Buffer Data Bit 5 */
    word BIT6        :1;                                       /* Trace Buffer Data Bit 6 */
    word BIT7        :1;                                       /* Trace Buffer Data Bit 7 */
    word BIT8        :1;                                       /* Trace Buffer Data Bit 8 */
    word BIT9        :1;                                       /* Trace Buffer Data Bit 9 */
    word BIT10       :1;                                       /* Trace Buffer Data Bit 10 */
    word BIT11       :1;                                       /* Trace Buffer Data Bit 11 */
    word BIT12       :1;                                       /* Trace Buffer Data Bit 12 */
    word BIT13       :1;                                       /* Trace Buffer Data Bit 13 */
    word BIT14       :1;                                       /* Trace Buffer Data Bit 14 */
    word BIT15       :1;                                       /* Trace Buffer Data Bit 15 */
  } Bits;
} DBGTBSTR;
extern volatile DBGTBSTR _DBGTB @(REG_BASE + 0x00000022UL);
#define DBGTB                           _DBGTB.Word
#define DBGTB_BIT0                      _DBGTB.Bits.BIT0
#define DBGTB_BIT1                      _DBGTB.Bits.BIT1
#define DBGTB_BIT2                      _DBGTB.Bits.BIT2
#define DBGTB_BIT3                      _DBGTB.Bits.BIT3
#define DBGTB_BIT4                      _DBGTB.Bits.BIT4
#define DBGTB_BIT5                      _DBGTB.Bits.BIT5
#define DBGTB_BIT6                      _DBGTB.Bits.BIT6
#define DBGTB_BIT7                      _DBGTB.Bits.BIT7
#define DBGTB_BIT8                      _DBGTB.Bits.BIT8
#define DBGTB_BIT9                      _DBGTB.Bits.BIT9
#define DBGTB_BIT10                     _DBGTB.Bits.BIT10
#define DBGTB_BIT11                     _DBGTB.Bits.BIT11
#define DBGTB_BIT12                     _DBGTB.Bits.BIT12
#define DBGTB_BIT13                     _DBGTB.Bits.BIT13
#define DBGTB_BIT14                     _DBGTB.Bits.BIT14
#define DBGTB_BIT15                     _DBGTB.Bits.BIT15

#define DBGTB_BIT0_MASK                 1U
#define DBGTB_BIT1_MASK                 2U
#define DBGTB_BIT2_MASK                 4U
#define DBGTB_BIT3_MASK                 8U
#define DBGTB_BIT4_MASK                 16U
#define DBGTB_BIT5_MASK                 32U
#define DBGTB_BIT6_MASK                 64U
#define DBGTB_BIT7_MASK                 128U
#define DBGTB_BIT8_MASK                 256U
#define DBGTB_BIT9_MASK                 512U
#define DBGTB_BIT10_MASK                1024U
#define DBGTB_BIT11_MASK                2048U
#define DBGTB_BIT12_MASK                4096U
#define DBGTB_BIT13_MASK                8192U
#define DBGTB_BIT14_MASK                16384U
#define DBGTB_BIT15_MASK                32768U


/*** DBGCNT - Debug Count Register; 0x00000024 ***/
typedef union {
  byte Byte;
  struct {
    byte CNT0        :1;                                       /* Count Value, bit 0 */
    byte CNT1        :1;                                       /* Count Value, bit 1 */
    byte CNT2        :1;                                       /* Count Value, bit 2 */
    byte CNT3        :1;                                       /* Count Value, bit 3 */
    byte CNT4        :1;                                       /* Count Value, bit 4 */
    byte CNT5        :1;                                       /* Count Value, bit 5 */
    byte             :1; 
    byte TBF         :1;                                       /* Trace Buffer Full */
  } Bits;
  struct {
    byte grpCNT  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGCNTSTR;
extern volatile DBGCNTSTR _DBGCNT @(REG_BASE + 0x00000024UL);
#define DBGCNT                          _DBGCNT.Byte
#define DBGCNT_CNT0                     _DBGCNT.Bits.CNT0
#define DBGCNT_CNT1                     _DBGCNT.Bits.CNT1
#define DBGCNT_CNT2                     _DBGCNT.Bits.CNT2
#define DBGCNT_CNT3                     _DBGCNT.Bits.CNT3
#define DBGCNT_CNT4                     _DBGCNT.Bits.CNT4
#define DBGCNT_CNT5                     _DBGCNT.Bits.CNT5
#define DBGCNT_TBF                      _DBGCNT.Bits.TBF
#define DBGCNT_CNT                      _DBGCNT.MergedBits.grpCNT

#define DBGCNT_CNT0_MASK                1U
#define DBGCNT_CNT1_MASK                2U
#define DBGCNT_CNT2_MASK                4U
#define DBGCNT_CNT3_MASK                8U
#define DBGCNT_CNT4_MASK                16U
#define DBGCNT_CNT5_MASK                32U
#define DBGCNT_TBF_MASK                 128U
#define DBGCNT_CNT_MASK                 63U
#define DBGCNT_CNT_BITNUM               0U


/*** DBGCCX - Debug Comparator C Extended Register; 0x00000025 ***/
typedef union {
  byte Byte;
  struct {
    byte EXTCMP0     :1;                                       /* Comparator C Extended Compare Bits, bit 0 */
    byte EXTCMP1     :1;                                       /* Comparator C Extended Compare Bits, bit 1 */
    byte EXTCMP2     :1;                                       /* Comparator C Extended Compare Bits, bit 2 */
    byte EXTCMP3     :1;                                       /* Comparator C Extended Compare Bits, bit 3 */
    byte EXTCMP4     :1;                                       /* Comparator C Extended Compare Bits, bit 4 */
    byte EXTCMP5     :1;                                       /* Comparator C Extended Compare Bits, bit 5 */
    byte PAGSEL0     :1;                                       /* Page Selector Field, bit 0 */
    byte PAGSEL1     :1;                                       /* Page Selector Field, bit 1 */
  } Bits;
  struct {
    byte grpEXTCMP :6;
    byte grpPAGSEL :2;
  } MergedBits;
} DBGCCXSTR;
extern volatile DBGCCXSTR _DBGCCX @(REG_BASE + 0x00000025UL);
#define DBGCCX                          _DBGCCX.Byte
#define DBGCCX_EXTCMP0                  _DBGCCX.Bits.EXTCMP0
#define DBGCCX_EXTCMP1                  _DBGCCX.Bits.EXTCMP1
#define DBGCCX_EXTCMP2                  _DBGCCX.Bits.EXTCMP2
#define DBGCCX_EXTCMP3                  _DBGCCX.Bits.EXTCMP3
#define DBGCCX_EXTCMP4                  _DBGCCX.Bits.EXTCMP4
#define DBGCCX_EXTCMP5                  _DBGCCX.Bits.EXTCMP5
#define DBGCCX_PAGSEL0                  _DBGCCX.Bits.PAGSEL0
#define DBGCCX_PAGSEL1                  _DBGCCX.Bits.PAGSEL1
#define DBGCCX_EXTCMP                   _DBGCCX.MergedBits.grpEXTCMP
#define DBGCCX_PAGSEL                   _DBGCCX.MergedBits.grpPAGSEL

#define DBGCCX_EXTCMP0_MASK             1U
#define DBGCCX_EXTCMP1_MASK             2U
#define DBGCCX_EXTCMP2_MASK             4U
#define DBGCCX_EXTCMP3_MASK             8U
#define DBGCCX_EXTCMP4_MASK             16U
#define DBGCCX_EXTCMP5_MASK             32U
#define DBGCCX_PAGSEL0_MASK             64U
#define DBGCCX_PAGSEL1_MASK             128U
#define DBGCCX_EXTCMP_MASK              63U
#define DBGCCX_EXTCMP_BITNUM            0U
#define DBGCCX_PAGSEL_MASK              192U
#define DBGCCX_PAGSEL_BITNUM            6U


/*** DBGCC - Debug Comparator C Register; 0x00000026 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCCH - Debug Comparator C Register High; 0x00000026 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Comparator C Compare Bit 8 */
        byte BIT9        :1;                                       /* Comparator C Compare Bit 9 */
        byte BIT10       :1;                                       /* Comparator C Compare Bit 10 */
        byte BIT11       :1;                                       /* Comparator C Compare Bit 11 */
        byte BIT12       :1;                                       /* Comparator C Compare Bit 12 */
        byte BIT13       :1;                                       /* Comparator C Compare Bit 13 */
        byte BIT14       :1;                                       /* Comparator C Compare Bit 14 */
        byte BIT15       :1;                                       /* Comparator C Compare Bit 15 */
      } Bits;
    } DBGCCHSTR;
    #define DBGCCH                      _DBGCC.Overlap_STR.DBGCCHSTR.Byte
    #define DBGCCH_BIT8                 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.BIT8
    #define DBGCCH_BIT9                 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.BIT9
    #define DBGCCH_BIT10                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.BIT10
    #define DBGCCH_BIT11                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.BIT11
    #define DBGCCH_BIT12                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.BIT12
    #define DBGCCH_BIT13                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.BIT13
    #define DBGCCH_BIT14                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.BIT14
    #define DBGCCH_BIT15                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.BIT15
    
    #define DBGCCH_BIT8_MASK            1U
    #define DBGCCH_BIT9_MASK            2U
    #define DBGCCH_BIT10_MASK           4U
    #define DBGCCH_BIT11_MASK           8U
    #define DBGCCH_BIT12_MASK           16U
    #define DBGCCH_BIT13_MASK           32U
    #define DBGCCH_BIT14_MASK           64U
    #define DBGCCH_BIT15_MASK           128U
    

    /*** DBGCCL - Debug Comparator C Register Low; 0x00000027 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Comparator C Compare Bit 0 */
        byte BIT1        :1;                                       /* Comparator C Compare Bit 1 */
        byte BIT2        :1;                                       /* Comparator C Compare Bit 2 */
        byte BIT3        :1;                                       /* Comparator C Compare Bit 3 */
        byte BIT4        :1;                                       /* Comparator C Compare Bit 4 */
        byte BIT5        :1;                                       /* Comparator C Compare Bit 5 */
        byte BIT6        :1;                                       /* Comparator C Compare Bit 6 */
        byte BIT7        :1;                                       /* Comparator C Compare Bit 7 */
      } Bits;
    } DBGCCLSTR;
    #define DBGCCL                      _DBGCC.Overlap_STR.DBGCCLSTR.Byte
    #define DBGCCL_BIT0                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.BIT0
    #define DBGCCL_BIT1                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.BIT1
    #define DBGCCL_BIT2                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.BIT2
    #define DBGCCL_BIT3                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.BIT3
    #define DBGCCL_BIT4                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.BIT4
    #define DBGCCL_BIT5                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.BIT5
    #define DBGCCL_BIT6                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.BIT6
    #define DBGCCL_BIT7                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.BIT7
    
    #define DBGCCL_BIT0_MASK            1U
    #define DBGCCL_BIT1_MASK            2U
    #define DBGCCL_BIT2_MASK            4U
    #define DBGCCL_BIT3_MASK            8U
    #define DBGCCL_BIT4_MASK            16U
    #define DBGCCL_BIT5_MASK            32U
    #define DBGCCL_BIT6_MASK            64U
    #define DBGCCL_BIT7_MASK            128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Comparator C Compare Bit 0 */
    word BIT1        :1;                                       /* Comparator C Compare Bit 1 */
    word BIT2        :1;                                       /* Comparator C Compare Bit 2 */
    word BIT3        :1;                                       /* Comparator C Compare Bit 3 */
    word BIT4        :1;                                       /* Comparator C Compare Bit 4 */
    word BIT5        :1;                                       /* Comparator C Compare Bit 5 */
    word BIT6        :1;                                       /* Comparator C Compare Bit 6 */
    word BIT7        :1;                                       /* Comparator C Compare Bit 7 */
    word BIT8        :1;                                       /* Comparator C Compare Bit 8 */
    word BIT9        :1;                                       /* Comparator C Compare Bit 9 */
    word BIT10       :1;                                       /* Comparator C Compare Bit 10 */
    word BIT11       :1;                                       /* Comparator C Compare Bit 11 */
    word BIT12       :1;                                       /* Comparator C Compare Bit 12 */
    word BIT13       :1;                                       /* Comparator C Compare Bit 13 */
    word BIT14       :1;                                       /* Comparator C Compare Bit 14 */
    word BIT15       :1;                                       /* Comparator C Compare Bit 15 */
  } Bits;
} DBGCCSTR;
extern volatile DBGCCSTR _DBGCC @(REG_BASE + 0x00000026UL);
#define DBGCC                           _DBGCC.Word
#define DBGCC_BIT0                      _DBGCC.Bits.BIT0
#define DBGCC_BIT1                      _DBGCC.Bits.BIT1
#define DBGCC_BIT2                      _DBGCC.Bits.BIT2
#define DBGCC_BIT3                      _DBGCC.Bits.BIT3
#define DBGCC_BIT4                      _DBGCC.Bits.BIT4
#define DBGCC_BIT5                      _DBGCC.Bits.BIT5
#define DBGCC_BIT6                      _DBGCC.Bits.BIT6
#define DBGCC_BIT7                      _DBGCC.Bits.BIT7
#define DBGCC_BIT8                      _DBGCC.Bits.BIT8
#define DBGCC_BIT9                      _DBGCC.Bits.BIT9
#define DBGCC_BIT10                     _DBGCC.Bits.BIT10
#define DBGCC_BIT11                     _DBGCC.Bits.BIT11
#define DBGCC_BIT12                     _DBGCC.Bits.BIT12
#define DBGCC_BIT13                     _DBGCC.Bits.BIT13
#define DBGCC_BIT14                     _DBGCC.Bits.BIT14
#define DBGCC_BIT15                     _DBGCC.Bits.BIT15

#define DBGCC_BIT0_MASK                 1U
#define DBGCC_BIT1_MASK                 2U
#define DBGCC_BIT2_MASK                 4U
#define DBGCC_BIT3_MASK                 8U
#define DBGCC_BIT4_MASK                 16U
#define DBGCC_BIT5_MASK                 32U
#define DBGCC_BIT6_MASK                 64U
#define DBGCC_BIT7_MASK                 128U
#define DBGCC_BIT8_MASK                 256U
#define DBGCC_BIT9_MASK                 512U
#define DBGCC_BIT10_MASK                1024U
#define DBGCC_BIT11_MASK                2048U
#define DBGCC_BIT12_MASK                4096U
#define DBGCC_BIT13_MASK                8192U
#define DBGCC_BIT14_MASK                16384U
#define DBGCC_BIT15_MASK                32768U


/*** DBGC2 - Debug Control Register 2; 0x00000028 ***/
typedef union {
  byte Byte;
  struct {
    byte RWC         :1;                                       /* Read/Write Comparator C Value Bit */
    byte RWCEN       :1;                                       /* Read/Write Comparator C Enable Bit */
    byte TAGC        :1;                                       /* Comparator C Tag Select */
    byte BKCEN       :1;                                       /* Breakpoint Comparator C Enable Bit */
    byte TAGAB       :1;                                       /* Comparator A/B Tag Select */
    byte BDM         :1;                                       /* Background Debug Mode Enable */
    byte FULL        :1;                                       /* Full Breakpoint Mode Enable */
    byte BKABEN      :1;                                       /* Breakpoint Using Comparator A and B Enable */
  } Bits;
} DBGC2STR;
extern volatile DBGC2STR _DBGC2 @(REG_BASE + 0x00000028UL);
#define DBGC2                           _DBGC2.Byte
#define DBGC2_RWC                       _DBGC2.Bits.RWC
#define DBGC2_RWCEN                     _DBGC2.Bits.RWCEN
#define DBGC2_TAGC                      _DBGC2.Bits.TAGC
#define DBGC2_BKCEN                     _DBGC2.Bits.BKCEN
#define DBGC2_TAGAB                     _DBGC2.Bits.TAGAB
#define DBGC2_BDM                       _DBGC2.Bits.BDM
#define DBGC2_FULL                      _DBGC2.Bits.FULL
#define DBGC2_BKABEN                    _DBGC2.Bits.BKABEN

#define DBGC2_RWC_MASK                  1U
#define DBGC2_RWCEN_MASK                2U
#define DBGC2_TAGC_MASK                 4U
#define DBGC2_BKCEN_MASK                8U
#define DBGC2_TAGAB_MASK                16U
#define DBGC2_BDM_MASK                  32U
#define DBGC2_FULL_MASK                 64U
#define DBGC2_BKABEN_MASK               128U


/*** DBGC3 - Debug Control Register 3; 0x00000029 ***/
typedef union {
  byte Byte;
  struct {
    byte RWB         :1;                                       /* Read/Write Comparator B Value Bit */
    byte RWBEN       :1;                                       /* Read/Write Comparator B Enable Bit */
    byte RWA         :1;                                       /* Read/Write Comparator A Value Bit */
    byte RWAEN       :1;                                       /* Read/Write Comparator A Enable Bit */
    byte BKBMBL      :1;                                       /* Breakpoint Mask Low Byte for Second Address */
    byte BKBMBH      :1;                                       /* Breakpoint Mask High Byte for Second Address */
    byte BKAMBL      :1;                                       /* Breakpoint Mask Low Byte for First Address */
    byte BKAMBH      :1;                                       /* Breakpoint Mask High Byte for First Address */
  } Bits;
} DBGC3STR;
extern volatile DBGC3STR _DBGC3 @(REG_BASE + 0x00000029UL);
#define DBGC3                           _DBGC3.Byte
#define DBGC3_RWB                       _DBGC3.Bits.RWB
#define DBGC3_RWBEN                     _DBGC3.Bits.RWBEN
#define DBGC3_RWA                       _DBGC3.Bits.RWA
#define DBGC3_RWAEN                     _DBGC3.Bits.RWAEN
#define DBGC3_BKBMBL                    _DBGC3.Bits.BKBMBL
#define DBGC3_BKBMBH                    _DBGC3.Bits.BKBMBH
#define DBGC3_BKAMBL                    _DBGC3.Bits.BKAMBL
#define DBGC3_BKAMBH                    _DBGC3.Bits.BKAMBH

#define DBGC3_RWB_MASK                  1U
#define DBGC3_RWBEN_MASK                2U
#define DBGC3_RWA_MASK                  4U
#define DBGC3_RWAEN_MASK                8U
#define DBGC3_BKBMBL_MASK               16U
#define DBGC3_BKBMBH_MASK               32U
#define DBGC3_BKAMBL_MASK               64U
#define DBGC3_BKAMBH_MASK               128U


/*** DBGCAX - Debug Comparator A Extended Register; 0x0000002A ***/
typedef union {
  byte Byte;
  struct {
    byte EXTCMP0     :1;                                       /* Comparator A Extended Compare Bits, bit 0 */
    byte EXTCMP1     :1;                                       /* Comparator A Extended Compare Bits, bit 1 */
    byte EXTCMP2     :1;                                       /* Comparator A Extended Compare Bits, bit 2 */
    byte EXTCMP3     :1;                                       /* Comparator A Extended Compare Bits, bit 3 */
    byte EXTCMP4     :1;                                       /* Comparator A Extended Compare Bits, bit 4 */
    byte EXTCMP5     :1;                                       /* Comparator A Extended Compare Bits, bit 5 */
    byte PAGSEL0     :1;                                       /* Page Selector Field, bit 0 */
    byte PAGSEL1     :1;                                       /* Page Selector Field, bit 1 */
  } Bits;
  struct {
    byte grpEXTCMP :6;
    byte grpPAGSEL :2;
  } MergedBits;
} DBGCAXSTR;
extern volatile DBGCAXSTR _DBGCAX @(REG_BASE + 0x0000002AUL);
#define DBGCAX                          _DBGCAX.Byte
#define DBGCAX_EXTCMP0                  _DBGCAX.Bits.EXTCMP0
#define DBGCAX_EXTCMP1                  _DBGCAX.Bits.EXTCMP1
#define DBGCAX_EXTCMP2                  _DBGCAX.Bits.EXTCMP2
#define DBGCAX_EXTCMP3                  _DBGCAX.Bits.EXTCMP3
#define DBGCAX_EXTCMP4                  _DBGCAX.Bits.EXTCMP4
#define DBGCAX_EXTCMP5                  _DBGCAX.Bits.EXTCMP5
#define DBGCAX_PAGSEL0                  _DBGCAX.Bits.PAGSEL0
#define DBGCAX_PAGSEL1                  _DBGCAX.Bits.PAGSEL1
#define DBGCAX_EXTCMP                   _DBGCAX.MergedBits.grpEXTCMP
#define DBGCAX_PAGSEL                   _DBGCAX.MergedBits.grpPAGSEL

#define DBGCAX_EXTCMP0_MASK             1U
#define DBGCAX_EXTCMP1_MASK             2U
#define DBGCAX_EXTCMP2_MASK             4U
#define DBGCAX_EXTCMP3_MASK             8U
#define DBGCAX_EXTCMP4_MASK             16U
#define DBGCAX_EXTCMP5_MASK             32U
#define DBGCAX_PAGSEL0_MASK             64U
#define DBGCAX_PAGSEL1_MASK             128U
#define DBGCAX_EXTCMP_MASK              63U
#define DBGCAX_EXTCMP_BITNUM            0U
#define DBGCAX_PAGSEL_MASK              192U
#define DBGCAX_PAGSEL_BITNUM            6U


/*** DBGCA - Debug Comparator A Register; 0x0000002B ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCAH - Debug Comparator A Register High; 0x0000002B ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Comparator A Compare Bit 8 */
        byte BIT9        :1;                                       /* Comparator A Compare Bit 9 */
        byte BIT10       :1;                                       /* Comparator A Compare Bit 10 */
        byte BIT11       :1;                                       /* Comparator A Compare Bit 11 */
        byte BIT12       :1;                                       /* Comparator A Compare Bit 12 */
        byte BIT13       :1;                                       /* Comparator A Compare Bit 13 */
        byte BIT14       :1;                                       /* Comparator A Compare Bit 14 */
        byte BIT15       :1;                                       /* Comparator A Compare Bit 15 */
      } Bits;
    } DBGCAHSTR;
    #define DBGCAH                      _DBGCA.Overlap_STR.DBGCAHSTR.Byte
    #define DBGCAH_BIT8                 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.BIT8
    #define DBGCAH_BIT9                 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.BIT9
    #define DBGCAH_BIT10                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.BIT10
    #define DBGCAH_BIT11                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.BIT11
    #define DBGCAH_BIT12                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.BIT12
    #define DBGCAH_BIT13                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.BIT13
    #define DBGCAH_BIT14                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.BIT14
    #define DBGCAH_BIT15                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.BIT15
    
    #define DBGCAH_BIT8_MASK            1U
    #define DBGCAH_BIT9_MASK            2U
    #define DBGCAH_BIT10_MASK           4U
    #define DBGCAH_BIT11_MASK           8U
    #define DBGCAH_BIT12_MASK           16U
    #define DBGCAH_BIT13_MASK           32U
    #define DBGCAH_BIT14_MASK           64U
    #define DBGCAH_BIT15_MASK           128U
    

    /*** DBGCAL - Debug Comparator A Register Low; 0x0000002C ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Comparator A Compare Bit 0 */
        byte BIT1        :1;                                       /* Comparator A Compare Bit 1 */
        byte BIT2        :1;                                       /* Comparator A Compare Bit 2 */
        byte BIT3        :1;                                       /* Comparator A Compare Bit 3 */
        byte BIT4        :1;                                       /* Comparator A Compare Bit 4 */
        byte BIT5        :1;                                       /* Comparator A Compare Bit 5 */
        byte BIT6        :1;                                       /* Comparator A Compare Bit 6 */
        byte BIT7        :1;                                       /* Comparator A Compare Bit 7 */
      } Bits;
    } DBGCALSTR;
    #define DBGCAL                      _DBGCA.Overlap_STR.DBGCALSTR.Byte
    #define DBGCAL_BIT0                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.BIT0
    #define DBGCAL_BIT1                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.BIT1
    #define DBGCAL_BIT2                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.BIT2
    #define DBGCAL_BIT3                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.BIT3
    #define DBGCAL_BIT4                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.BIT4
    #define DBGCAL_BIT5                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.BIT5
    #define DBGCAL_BIT6                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.BIT6
    #define DBGCAL_BIT7                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.BIT7
    
    #define DBGCAL_BIT0_MASK            1U
    #define DBGCAL_BIT1_MASK            2U
    #define DBGCAL_BIT2_MASK            4U
    #define DBGCAL_BIT3_MASK            8U
    #define DBGCAL_BIT4_MASK            16U
    #define DBGCAL_BIT5_MASK            32U
    #define DBGCAL_BIT6_MASK            64U
    #define DBGCAL_BIT7_MASK            128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Comparator A Compare Bit 0 */
    word BIT1        :1;                                       /* Comparator A Compare Bit 1 */
    word BIT2        :1;                                       /* Comparator A Compare Bit 2 */
    word BIT3        :1;                                       /* Comparator A Compare Bit 3 */
    word BIT4        :1;                                       /* Comparator A Compare Bit 4 */
    word BIT5        :1;                                       /* Comparator A Compare Bit 5 */
    word BIT6        :1;                                       /* Comparator A Compare Bit 6 */
    word BIT7        :1;                                       /* Comparator A Compare Bit 7 */
    word BIT8        :1;                                       /* Comparator A Compare Bit 8 */
    word BIT9        :1;                                       /* Comparator A Compare Bit 9 */
    word BIT10       :1;                                       /* Comparator A Compare Bit 10 */
    word BIT11       :1;                                       /* Comparator A Compare Bit 11 */
    word BIT12       :1;                                       /* Comparator A Compare Bit 12 */
    word BIT13       :1;                                       /* Comparator A Compare Bit 13 */
    word BIT14       :1;                                       /* Comparator A Compare Bit 14 */
    word BIT15       :1;                                       /* Comparator A Compare Bit 15 */
  } Bits;
} DBGCASTR;
extern volatile DBGCASTR _DBGCA @(REG_BASE + 0x0000002BUL);
#define DBGCA                           _DBGCA.Word
#define DBGCA_BIT0                      _DBGCA.Bits.BIT0
#define DBGCA_BIT1                      _DBGCA.Bits.BIT1
#define DBGCA_BIT2                      _DBGCA.Bits.BIT2
#define DBGCA_BIT3                      _DBGCA.Bits.BIT3
#define DBGCA_BIT4                      _DBGCA.Bits.BIT4
#define DBGCA_BIT5                      _DBGCA.Bits.BIT5
#define DBGCA_BIT6                      _DBGCA.Bits.BIT6
#define DBGCA_BIT7                      _DBGCA.Bits.BIT7
#define DBGCA_BIT8                      _DBGCA.Bits.BIT8
#define DBGCA_BIT9                      _DBGCA.Bits.BIT9
#define DBGCA_BIT10                     _DBGCA.Bits.BIT10
#define DBGCA_BIT11                     _DBGCA.Bits.BIT11
#define DBGCA_BIT12                     _DBGCA.Bits.BIT12
#define DBGCA_BIT13                     _DBGCA.Bits.BIT13
#define DBGCA_BIT14                     _DBGCA.Bits.BIT14
#define DBGCA_BIT15                     _DBGCA.Bits.BIT15

#define DBGCA_BIT0_MASK                 1U
#define DBGCA_BIT1_MASK                 2U
#define DBGCA_BIT2_MASK                 4U
#define DBGCA_BIT3_MASK                 8U
#define DBGCA_BIT4_MASK                 16U
#define DBGCA_BIT5_MASK                 32U
#define DBGCA_BIT6_MASK                 64U
#define DBGCA_BIT7_MASK                 128U
#define DBGCA_BIT8_MASK                 256U
#define DBGCA_BIT9_MASK                 512U
#define DBGCA_BIT10_MASK                1024U
#define DBGCA_BIT11_MASK                2048U
#define DBGCA_BIT12_MASK                4096U
#define DBGCA_BIT13_MASK                8192U
#define DBGCA_BIT14_MASK                16384U
#define DBGCA_BIT15_MASK                32768U


/*** DBGCBX - Debug Comparator B Extended Register; 0x0000002D ***/
typedef union {
  byte Byte;
  struct {
    byte EXTCMP0     :1;                                       /* Comparator B Extended Compare Bits, bit 0 */
    byte EXTCMP1     :1;                                       /* Comparator B Extended Compare Bits, bit 1 */
    byte EXTCMP2     :1;                                       /* Comparator B Extended Compare Bits, bit 2 */
    byte EXTCMP3     :1;                                       /* Comparator B Extended Compare Bits, bit 3 */
    byte EXTCMP4     :1;                                       /* Comparator B Extended Compare Bits, bit 4 */
    byte EXTCMP5     :1;                                       /* Comparator B Extended Compare Bits, bit 5 */
    byte PAGSEL0     :1;                                       /* Page Selector Field, bit 0 */
    byte PAGSEL1     :1;                                       /* Page Selector Field, bit 1 */
  } Bits;
  struct {
    byte grpEXTCMP :6;
    byte grpPAGSEL :2;
  } MergedBits;
} DBGCBXSTR;
extern volatile DBGCBXSTR _DBGCBX @(REG_BASE + 0x0000002DUL);
#define DBGCBX                          _DBGCBX.Byte
#define DBGCBX_EXTCMP0                  _DBGCBX.Bits.EXTCMP0
#define DBGCBX_EXTCMP1                  _DBGCBX.Bits.EXTCMP1
#define DBGCBX_EXTCMP2                  _DBGCBX.Bits.EXTCMP2
#define DBGCBX_EXTCMP3                  _DBGCBX.Bits.EXTCMP3
#define DBGCBX_EXTCMP4                  _DBGCBX.Bits.EXTCMP4
#define DBGCBX_EXTCMP5                  _DBGCBX.Bits.EXTCMP5
#define DBGCBX_PAGSEL0                  _DBGCBX.Bits.PAGSEL0
#define DBGCBX_PAGSEL1                  _DBGCBX.Bits.PAGSEL1
#define DBGCBX_EXTCMP                   _DBGCBX.MergedBits.grpEXTCMP
#define DBGCBX_PAGSEL                   _DBGCBX.MergedBits.grpPAGSEL

#define DBGCBX_EXTCMP0_MASK             1U
#define DBGCBX_EXTCMP1_MASK             2U
#define DBGCBX_EXTCMP2_MASK             4U
#define DBGCBX_EXTCMP3_MASK             8U
#define DBGCBX_EXTCMP4_MASK             16U
#define DBGCBX_EXTCMP5_MASK             32U
#define DBGCBX_PAGSEL0_MASK             64U
#define DBGCBX_PAGSEL1_MASK             128U
#define DBGCBX_EXTCMP_MASK              63U
#define DBGCBX_EXTCMP_BITNUM            0U
#define DBGCBX_PAGSEL_MASK              192U
#define DBGCBX_PAGSEL_BITNUM            6U


/*** DBGCB - Debug Comparator B Register; 0x0000002E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCBH - Debug Comparator B Register High; 0x0000002E ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Comparator B High Compare Bit 8 */
        byte BIT9        :1;                                       /* Comparator B High Compare Bit 9 */
        byte BIT10       :1;                                       /* Comparator B High Compare Bit 10 */
        byte BIT11       :1;                                       /* Comparator B High Compare Bit 11 */
        byte BIT12       :1;                                       /* Comparator B High Compare Bit 12 */
        byte BIT13       :1;                                       /* Comparator B High Compare Bit 13 */
        byte BIT14       :1;                                       /* Comparator B High Compare Bit 14 */
        byte BIT15       :1;                                       /* Comparator B High Compare Bit 15 */
      } Bits;
    } DBGCBHSTR;
    #define DBGCBH                      _DBGCB.Overlap_STR.DBGCBHSTR.Byte
    #define DBGCBH_BIT8                 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.BIT8
    #define DBGCBH_BIT9                 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.BIT9
    #define DBGCBH_BIT10                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.BIT10
    #define DBGCBH_BIT11                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.BIT11
    #define DBGCBH_BIT12                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.BIT12
    #define DBGCBH_BIT13                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.BIT13
    #define DBGCBH_BIT14                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.BIT14
    #define DBGCBH_BIT15                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.BIT15
    
    #define DBGCBH_BIT8_MASK            1U
    #define DBGCBH_BIT9_MASK            2U
    #define DBGCBH_BIT10_MASK           4U
    #define DBGCBH_BIT11_MASK           8U
    #define DBGCBH_BIT12_MASK           16U
    #define DBGCBH_BIT13_MASK           32U
    #define DBGCBH_BIT14_MASK           64U
    #define DBGCBH_BIT15_MASK           128U
    

    /*** DBGCBL - Debug Comparator B Register Low; 0x0000002F ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Comparator B High Compare Bit 0 */
        byte BIT1        :1;                                       /* Comparator B High Compare Bit 1 */
        byte BIT2        :1;                                       /* Comparator B High Compare Bit 2 */
        byte BIT3        :1;                                       /* Comparator B High Compare Bit 3 */
        byte BIT4        :1;                                       /* Comparator B High Compare Bit 4 */
        byte BIT5        :1;                                       /* Comparator B High Compare Bit 5 */
        byte BIT6        :1;                                       /* Comparator B High Compare Bit 6 */
        byte BIT7        :1;                                       /* Comparator B High Compare Bit 7 */
      } Bits;
    } DBGCBLSTR;
    #define DBGCBL                      _DBGCB.Overlap_STR.DBGCBLSTR.Byte
    #define DBGCBL_BIT0                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.BIT0
    #define DBGCBL_BIT1                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.BIT1
    #define DBGCBL_BIT2                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.BIT2
    #define DBGCBL_BIT3                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.BIT3
    #define DBGCBL_BIT4                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.BIT4
    #define DBGCBL_BIT5                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.BIT5
    #define DBGCBL_BIT6                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.BIT6
    #define DBGCBL_BIT7                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.BIT7
    
    #define DBGCBL_BIT0_MASK            1U
    #define DBGCBL_BIT1_MASK            2U
    #define DBGCBL_BIT2_MASK            4U
    #define DBGCBL_BIT3_MASK            8U
    #define DBGCBL_BIT4_MASK            16U
    #define DBGCBL_BIT5_MASK            32U
    #define DBGCBL_BIT6_MASK            64U
    #define DBGCBL_BIT7_MASK            128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Comparator B High Compare Bit 0 */
    word BIT1        :1;                                       /* Comparator B High Compare Bit 1 */
    word BIT2        :1;                                       /* Comparator B High Compare Bit 2 */
    word BIT3        :1;                                       /* Comparator B High Compare Bit 3 */
    word BIT4        :1;                                       /* Comparator B High Compare Bit 4 */
    word BIT5        :1;                                       /* Comparator B High Compare Bit 5 */
    word BIT6        :1;                                       /* Comparator B High Compare Bit 6 */
    word BIT7        :1;                                       /* Comparator B High Compare Bit 7 */
    word BIT8        :1;                                       /* Comparator B High Compare Bit 8 */
    word BIT9        :1;                                       /* Comparator B High Compare Bit 9 */
    word BIT10       :1;                                       /* Comparator B High Compare Bit 10 */
    word BIT11       :1;                                       /* Comparator B High Compare Bit 11 */
    word BIT12       :1;                                       /* Comparator B High Compare Bit 12 */
    word BIT13       :1;                                       /* Comparator B High Compare Bit 13 */
    word BIT14       :1;                                       /* Comparator B High Compare Bit 14 */
    word BIT15       :1;                                       /* Comparator B High Compare Bit 15 */
  } Bits;
} DBGCBSTR;
extern volatile DBGCBSTR _DBGCB @(REG_BASE + 0x0000002EUL);
#define DBGCB                           _DBGCB.Word
#define DBGCB_BIT0                      _DBGCB.Bits.BIT0
#define DBGCB_BIT1                      _DBGCB.Bits.BIT1
#define DBGCB_BIT2                      _DBGCB.Bits.BIT2
#define DBGCB_BIT3                      _DBGCB.Bits.BIT3
#define DBGCB_BIT4                      _DBGCB.Bits.BIT4
#define DBGCB_BIT5                      _DBGCB.Bits.BIT5
#define DBGCB_BIT6                      _DBGCB.Bits.BIT6
#define DBGCB_BIT7                      _DBGCB.Bits.BIT7
#define DBGCB_BIT8                      _DBGCB.Bits.BIT8
#define DBGCB_BIT9                      _DBGCB.Bits.BIT9
#define DBGCB_BIT10                     _DBGCB.Bits.BIT10
#define DBGCB_BIT11                     _DBGCB.Bits.BIT11
#define DBGCB_BIT12                     _DBGCB.Bits.BIT12
#define DBGCB_BIT13                     _DBGCB.Bits.BIT13
#define DBGCB_BIT14                     _DBGCB.Bits.BIT14
#define DBGCB_BIT15                     _DBGCB.Bits.BIT15

#define DBGCB_BIT0_MASK                 1U
#define DBGCB_BIT1_MASK                 2U
#define DBGCB_BIT2_MASK                 4U
#define DBGCB_BIT3_MASK                 8U
#define DBGCB_BIT4_MASK                 16U
#define DBGCB_BIT5_MASK                 32U
#define DBGCB_BIT6_MASK                 64U
#define DBGCB_BIT7_MASK                 128U
#define DBGCB_BIT8_MASK                 256U
#define DBGCB_BIT9_MASK                 512U
#define DBGCB_BIT10_MASK                1024U
#define DBGCB_BIT11_MASK                2048U
#define DBGCB_BIT12_MASK                4096U
#define DBGCB_BIT13_MASK                8192U
#define DBGCB_BIT14_MASK                16384U
#define DBGCB_BIT15_MASK                32768U


/*** PPAGE - Page Index Register; 0x00000030 ***/
typedef union {
  byte Byte;
  struct {
    byte PIX0        :1;                                       /* Page Index Register Bit 0 */
    byte PIX1        :1;                                       /* Page Index Register Bit 1 */
    byte PIX2        :1;                                       /* Page Index Register Bit 2 */
    byte PIX3        :1;                                       /* Page Index Register Bit 3 */
    byte PIX4        :1;                                       /* Page Index Register Bit 4 */
    byte PIX5        :1;                                       /* Page Index Register Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPIX  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPAGESTR;
extern volatile PPAGESTR _PPAGE @(REG_BASE + 0x00000030UL);
#define PPAGE                           _PPAGE.Byte
#define PPAGE_PIX0                      _PPAGE.Bits.PIX0
#define PPAGE_PIX1                      _PPAGE.Bits.PIX1
#define PPAGE_PIX2                      _PPAGE.Bits.PIX2
#define PPAGE_PIX3                      _PPAGE.Bits.PIX3
#define PPAGE_PIX4                      _PPAGE.Bits.PIX4
#define PPAGE_PIX5                      _PPAGE.Bits.PIX5
#define PPAGE_PIX                       _PPAGE.MergedBits.grpPIX

#define PPAGE_PIX0_MASK                 1U
#define PPAGE_PIX1_MASK                 2U
#define PPAGE_PIX2_MASK                 4U
#define PPAGE_PIX3_MASK                 8U
#define PPAGE_PIX4_MASK                 16U
#define PPAGE_PIX5_MASK                 32U
#define PPAGE_PIX_MASK                  63U
#define PPAGE_PIX_BITNUM                0U


/*** SYNR - CRG Synthesizer Register; 0x00000034 ***/
typedef union {
  byte Byte;
  struct {
    byte SYN0        :1;                                       /* CRG Synthesizer Bit 0 */
    byte SYN1        :1;                                       /* CRG Synthesizer Bit 1 */
    byte SYN2        :1;                                       /* CRG Synthesizer Bit 2 */
    byte SYN3        :1;                                       /* CRG Synthesizer Bit 3 */
    byte SYN4        :1;                                       /* CRG Synthesizer Bit 4 */
    byte SYN5        :1;                                       /* CRG Synthesizer Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpSYN  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} SYNRSTR;
extern volatile SYNRSTR _SYNR @(REG_BASE + 0x00000034UL);
#define SYNR                            _SYNR.Byte
#define SYNR_SYN0                       _SYNR.Bits.SYN0
#define SYNR_SYN1                       _SYNR.Bits.SYN1
#define SYNR_SYN2                       _SYNR.Bits.SYN2
#define SYNR_SYN3                       _SYNR.Bits.SYN3
#define SYNR_SYN4                       _SYNR.Bits.SYN4
#define SYNR_SYN5                       _SYNR.Bits.SYN5
#define SYNR_SYN                        _SYNR.MergedBits.grpSYN

#define SYNR_SYN0_MASK                  1U
#define SYNR_SYN1_MASK                  2U
#define SYNR_SYN2_MASK                  4U
#define SYNR_SYN3_MASK                  8U
#define SYNR_SYN4_MASK                  16U
#define SYNR_SYN5_MASK                  32U
#define SYNR_SYN_MASK                   63U
#define SYNR_SYN_BITNUM                 0U


/*** REFDV - CRG Reference Divider Register; 0x00000035 ***/
typedef union {
  byte Byte;
  struct {
    byte REFDV0      :1;                                       /* CRG Reference Divider Bit 0 */
    byte REFDV1      :1;                                       /* CRG Reference Divider Bit 1 */
    byte REFDV2      :1;                                       /* CRG Reference Divider Bit 2 */
    byte REFDV3      :1;                                       /* CRG Reference Divider Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpREFDV :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} REFDVSTR;
extern volatile REFDVSTR _REFDV @(REG_BASE + 0x00000035UL);
#define REFDV                           _REFDV.Byte
#define REFDV_REFDV0                    _REFDV.Bits.REFDV0
#define REFDV_REFDV1                    _REFDV.Bits.REFDV1
#define REFDV_REFDV2                    _REFDV.Bits.REFDV2
#define REFDV_REFDV3                    _REFDV.Bits.REFDV3
#define REFDV_REFDV                     _REFDV.MergedBits.grpREFDV

#define REFDV_REFDV0_MASK               1U
#define REFDV_REFDV1_MASK               2U
#define REFDV_REFDV2_MASK               4U
#define REFDV_REFDV3_MASK               8U
#define REFDV_REFDV_MASK                15U
#define REFDV_REFDV_BITNUM              0U


/*** CRGFLG - CRG Flags Register; 0x00000037 ***/
typedef union {
  byte Byte;
  struct {
    byte SCM         :1;                                       /* Self-clock mode Status */
    byte SCMIF       :1;                                       /* Self-clock mode Interrupt Flag */
    byte TRACK       :1;                                       /* Track Status */
    byte LOCK        :1;                                       /* Lock Status */
    byte LOCKIF      :1;                                       /* PLL Lock Interrupt Flag */
    byte LVRF        :1;                                       /* Self-clock mode Status */
    byte PORF        :1;                                       /* Power on Reset Flag */
    byte RTIF        :1;                                       /* Real Time Interrupt Flag */
  } Bits;
} CRGFLGSTR;
extern volatile CRGFLGSTR _CRGFLG @(REG_BASE + 0x00000037UL);
#define CRGFLG                          _CRGFLG.Byte
#define CRGFLG_SCM                      _CRGFLG.Bits.SCM
#define CRGFLG_SCMIF                    _CRGFLG.Bits.SCMIF
#define CRGFLG_TRACK                    _CRGFLG.Bits.TRACK
#define CRGFLG_LOCK                     _CRGFLG.Bits.LOCK
#define CRGFLG_LOCKIF                   _CRGFLG.Bits.LOCKIF
#define CRGFLG_LVRF                     _CRGFLG.Bits.LVRF
#define CRGFLG_PORF                     _CRGFLG.Bits.PORF
#define CRGFLG_RTIF                     _CRGFLG.Bits.RTIF

#define CRGFLG_SCM_MASK                 1U
#define CRGFLG_SCMIF_MASK               2U
#define CRGFLG_TRACK_MASK               4U
#define CRGFLG_LOCK_MASK                8U
#define CRGFLG_LOCKIF_MASK              16U
#define CRGFLG_LVRF_MASK                32U
#define CRGFLG_PORF_MASK                64U
#define CRGFLG_RTIF_MASK                128U


/*** CRGINT - CRG Interrupt Enable Register; 0x00000038 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte SCMIE       :1;                                       /* Self-clock mode Interrupt Enable */
    byte             :1; 
    byte             :1; 
    byte LOCKIE      :1;                                       /* Lock Interrupt Enable */
    byte             :1; 
    byte             :1; 
    byte RTIE        :1;                                       /* Real Time Interrupt Enable */
  } Bits;
} CRGINTSTR;
extern volatile CRGINTSTR _CRGINT @(REG_BASE + 0x00000038UL);
#define CRGINT                          _CRGINT.Byte
#define CRGINT_SCMIE                    _CRGINT.Bits.SCMIE
#define CRGINT_LOCKIE                   _CRGINT.Bits.LOCKIE
#define CRGINT_RTIE                     _CRGINT.Bits.RTIE

#define CRGINT_SCMIE_MASK               2U
#define CRGINT_LOCKIE_MASK              16U
#define CRGINT_RTIE_MASK                128U


/*** CLKSEL - CRG Clock Select Register; 0x00000039 ***/
typedef union {
  byte Byte;
  struct {
    byte COPWAI      :1;                                       /* COP stops in WAIT mode */
    byte RTIWAI      :1;                                       /* RTI stops in WAIT mode */
    byte CWAI        :1;                                       /* CLK24 and CLK23 stop in WAIT mode */
    byte PLLWAI      :1;                                       /* PLL stops in WAIT mode */
    byte ROAWAI      :1;                                       /* Reduced Oscillator Amplitude in WAIT mode */
    byte SYSWAI      :1;                                       /* System clocks stop in WAIT mode */
    byte PSTP        :1;                                       /* Pseudo Stop */
    byte PLLSEL      :1;                                       /* PLL selected for system clock */
  } Bits;
} CLKSELSTR;
extern volatile CLKSELSTR _CLKSEL @(REG_BASE + 0x00000039UL);
#define CLKSEL                          _CLKSEL.Byte
#define CLKSEL_COPWAI                   _CLKSEL.Bits.COPWAI
#define CLKSEL_RTIWAI                   _CLKSEL.Bits.RTIWAI
#define CLKSEL_CWAI                     _CLKSEL.Bits.CWAI
#define CLKSEL_PLLWAI                   _CLKSEL.Bits.PLLWAI
#define CLKSEL_ROAWAI                   _CLKSEL.Bits.ROAWAI
#define CLKSEL_SYSWAI                   _CLKSEL.Bits.SYSWAI
#define CLKSEL_PSTP                     _CLKSEL.Bits.PSTP
#define CLKSEL_PLLSEL                   _CLKSEL.Bits.PLLSEL

#define CLKSEL_COPWAI_MASK              1U
#define CLKSEL_RTIWAI_MASK              2U
#define CLKSEL_CWAI_MASK                4U
#define CLKSEL_PLLWAI_MASK              8U
#define CLKSEL_ROAWAI_MASK              16U
#define CLKSEL_SYSWAI_MASK              32U
#define CLKSEL_PSTP_MASK                64U
#define CLKSEL_PLLSEL_MASK              128U


/*** PLLCTL - CRG PLL Control Register; 0x0000003A ***/
typedef union {
  byte Byte;
  struct {
    byte SCME        :1;                                       /* Self-clock mode enable */
    byte PCE         :1;                                       /* COP Enable during Pseudo Stop Bit */
    byte PRE         :1;                                       /* RTI Enable during Pseudo Stop Bit */
    byte             :1; 
    byte ACQ         :1;                                       /* Acquisition */
    byte AUTO        :1;                                       /* Automatic Bandwidth Control */
    byte PLLON       :1;                                       /* Phase Lock Loop On */
    byte CME         :1;                                       /* Clock Monitor Enable */
  } Bits;
} PLLCTLSTR;
extern volatile PLLCTLSTR _PLLCTL @(REG_BASE + 0x0000003AUL);
#define PLLCTL                          _PLLCTL.Byte
#define PLLCTL_SCME                     _PLLCTL.Bits.SCME
#define PLLCTL_PCE                      _PLLCTL.Bits.PCE
#define PLLCTL_PRE                      _PLLCTL.Bits.PRE
#define PLLCTL_ACQ                      _PLLCTL.Bits.ACQ
#define PLLCTL_AUTO                     _PLLCTL.Bits.AUTO
#define PLLCTL_PLLON                    _PLLCTL.Bits.PLLON
#define PLLCTL_CME                      _PLLCTL.Bits.CME

#define PLLCTL_SCME_MASK                1U
#define PLLCTL_PCE_MASK                 2U
#define PLLCTL_PRE_MASK                 4U
#define PLLCTL_ACQ_MASK                 16U
#define PLLCTL_AUTO_MASK                32U
#define PLLCTL_PLLON_MASK               64U
#define PLLCTL_CME_MASK                 128U


/*** RTICTL - CRG RTI Control Register; 0x0000003B ***/
typedef union {
  byte Byte;
  struct {
    byte RTR0        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 0 */
    byte RTR1        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 1 */
    byte RTR2        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 2 */
    byte RTR3        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 3 */
    byte RTR4        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 4 */
    byte RTR5        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 5 */
    byte RTR6        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpRTR  :7;
    byte         :1;
  } MergedBits;
} RTICTLSTR;
extern volatile RTICTLSTR _RTICTL @(REG_BASE + 0x0000003BUL);
#define RTICTL                          _RTICTL.Byte
#define RTICTL_RTR0                     _RTICTL.Bits.RTR0
#define RTICTL_RTR1                     _RTICTL.Bits.RTR1
#define RTICTL_RTR2                     _RTICTL.Bits.RTR2
#define RTICTL_RTR3                     _RTICTL.Bits.RTR3
#define RTICTL_RTR4                     _RTICTL.Bits.RTR4
#define RTICTL_RTR5                     _RTICTL.Bits.RTR5
#define RTICTL_RTR6                     _RTICTL.Bits.RTR6
#define RTICTL_RTR                      _RTICTL.MergedBits.grpRTR

#define RTICTL_RTR0_MASK                1U
#define RTICTL_RTR1_MASK                2U
#define RTICTL_RTR2_MASK                4U
#define RTICTL_RTR3_MASK                8U
#define RTICTL_RTR4_MASK                16U
#define RTICTL_RTR5_MASK                32U
#define RTICTL_RTR6_MASK                64U
#define RTICTL_RTR_MASK                 127U
#define RTICTL_RTR_BITNUM               0U


/*** COPCTL - CRG COP Control Register; 0x0000003C ***/
typedef union {
  byte Byte;
  struct {
    byte CR0         :1;                                       /* COP Watchdog Timer Rate select Bit 0 */
    byte CR1         :1;                                       /* COP Watchdog Timer Rate select Bit 1 */
    byte CR2         :1;                                       /* COP Watchdog Timer Rate select Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RSBCK       :1;                                       /* COP and RTI stop in Active BDM mode Bit */
    byte WCOP        :1;                                       /* Window COP mode */
  } Bits;
  struct {
    byte grpCR   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} COPCTLSTR;
extern volatile COPCTLSTR _COPCTL @(REG_BASE + 0x0000003CUL);
#define COPCTL                          _COPCTL.Byte
#define COPCTL_CR0                      _COPCTL.Bits.CR0
#define COPCTL_CR1                      _COPCTL.Bits.CR1
#define COPCTL_CR2                      _COPCTL.Bits.CR2
#define COPCTL_RSBCK                    _COPCTL.Bits.RSBCK
#define COPCTL_WCOP                     _COPCTL.Bits.WCOP
#define COPCTL_CR                       _COPCTL.MergedBits.grpCR

#define COPCTL_CR0_MASK                 1U
#define COPCTL_CR1_MASK                 2U
#define COPCTL_CR2_MASK                 4U
#define COPCTL_RSBCK_MASK               64U
#define COPCTL_WCOP_MASK                128U
#define COPCTL_CR_MASK                  7U
#define COPCTL_CR_BITNUM                0U


/*** ARMCOP - CRG COP Timer Arm/Reset Register; 0x0000003F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* CRG COP Timer Arm/Reset Bit 0 */
    byte BIT1        :1;                                       /* CRG COP Timer Arm/Reset Bit 1 */
    byte BIT2        :1;                                       /* CRG COP Timer Arm/Reset Bit 2 */
    byte BIT3        :1;                                       /* CRG COP Timer Arm/Reset Bit 3 */
    byte BIT4        :1;                                       /* CRG COP Timer Arm/Reset Bit 4 */
    byte BIT5        :1;                                       /* CRG COP Timer Arm/Reset Bit 5 */
    byte BIT6        :1;                                       /* CRG COP Timer Arm/Reset Bit 6 */
    byte BIT7        :1;                                       /* CRG COP Timer Arm/Reset Bit 7 */
  } Bits;
} ARMCOPSTR;
extern volatile ARMCOPSTR _ARMCOP @(REG_BASE + 0x0000003FUL);
#define ARMCOP                          _ARMCOP.Byte
#define ARMCOP_BIT0                     _ARMCOP.Bits.BIT0
#define ARMCOP_BIT1                     _ARMCOP.Bits.BIT1
#define ARMCOP_BIT2                     _ARMCOP.Bits.BIT2
#define ARMCOP_BIT3                     _ARMCOP.Bits.BIT3
#define ARMCOP_BIT4                     _ARMCOP.Bits.BIT4
#define ARMCOP_BIT5                     _ARMCOP.Bits.BIT5
#define ARMCOP_BIT6                     _ARMCOP.Bits.BIT6
#define ARMCOP_BIT7                     _ARMCOP.Bits.BIT7

#define ARMCOP_BIT0_MASK                1U
#define ARMCOP_BIT1_MASK                2U
#define ARMCOP_BIT2_MASK                4U
#define ARMCOP_BIT3_MASK                8U
#define ARMCOP_BIT4_MASK                16U
#define ARMCOP_BIT5_MASK                32U
#define ARMCOP_BIT6_MASK                64U
#define ARMCOP_BIT7_MASK                128U


/*** TIOS - Timer Input Capture/Output Compare Select; 0x00000040 ***/
typedef union {
  byte Byte;
  struct {
    byte IOS0        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 0 */
    byte IOS1        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 1 */
    byte IOS2        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 2 */
    byte IOS3        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 3 */
    byte IOS4        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 4 */
    byte IOS5        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 5 */
    byte IOS6        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 6 */
    byte IOS7        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 7 */
  } Bits;
} TIOSSTR;
extern volatile TIOSSTR _TIOS @(REG_BASE + 0x00000040UL);
#define TIOS                            _TIOS.Byte
#define TIOS_IOS0                       _TIOS.Bits.IOS0
#define TIOS_IOS1                       _TIOS.Bits.IOS1
#define TIOS_IOS2                       _TIOS.Bits.IOS2
#define TIOS_IOS3                       _TIOS.Bits.IOS3
#define TIOS_IOS4                       _TIOS.Bits.IOS4
#define TIOS_IOS5                       _TIOS.Bits.IOS5
#define TIOS_IOS6                       _TIOS.Bits.IOS6
#define TIOS_IOS7                       _TIOS.Bits.IOS7

#define TIOS_IOS0_MASK                  1U
#define TIOS_IOS1_MASK                  2U
#define TIOS_IOS2_MASK                  4U
#define TIOS_IOS3_MASK                  8U
#define TIOS_IOS4_MASK                  16U
#define TIOS_IOS5_MASK                  32U
#define TIOS_IOS6_MASK                  64U
#define TIOS_IOS7_MASK                  128U


/*** CFORC - Timer Compare Force Register; 0x00000041 ***/
typedef union {
  byte Byte;
  struct {
    byte FOC0        :1;                                       /* Force Output Compare Action for Channel 0 */
    byte FOC1        :1;                                       /* Force Output Compare Action for Channel 1 */
    byte FOC2        :1;                                       /* Force Output Compare Action for Channel 2 */
    byte FOC3        :1;                                       /* Force Output Compare Action for Channel 3 */
    byte FOC4        :1;                                       /* Force Output Compare Action for Channel 4 */
    byte FOC5        :1;                                       /* Force Output Compare Action for Channel 5 */
    byte FOC6        :1;                                       /* Force Output Compare Action for Channel 6 */
    byte FOC7        :1;                                       /* Force Output Compare Action for Channel 7 */
  } Bits;
} CFORCSTR;
extern volatile CFORCSTR _CFORC @(REG_BASE + 0x00000041UL);
#define CFORC                           _CFORC.Byte
#define CFORC_FOC0                      _CFORC.Bits.FOC0
#define CFORC_FOC1                      _CFORC.Bits.FOC1
#define CFORC_FOC2                      _CFORC.Bits.FOC2
#define CFORC_FOC3                      _CFORC.Bits.FOC3
#define CFORC_FOC4                      _CFORC.Bits.FOC4
#define CFORC_FOC5                      _CFORC.Bits.FOC5
#define CFORC_FOC6                      _CFORC.Bits.FOC6
#define CFORC_FOC7                      _CFORC.Bits.FOC7

#define CFORC_FOC0_MASK                 1U
#define CFORC_FOC1_MASK                 2U
#define CFORC_FOC2_MASK                 4U
#define CFORC_FOC3_MASK                 8U
#define CFORC_FOC4_MASK                 16U
#define CFORC_FOC5_MASK                 32U
#define CFORC_FOC6_MASK                 64U
#define CFORC_FOC7_MASK                 128U


/*** OC7M - Output Compare 7 Mask Register; 0x00000042 ***/
typedef union {
  byte Byte;
  struct {
    byte OC7M0       :1;                                       /* Output Compare 7 Mask Bit 0 */
    byte OC7M1       :1;                                       /* Output Compare 7 Mask Bit 1 */
    byte OC7M2       :1;                                       /* Output Compare 7 Mask Bit 2 */
    byte OC7M3       :1;                                       /* Output Compare 7 Mask Bit 3 */
    byte OC7M4       :1;                                       /* Output Compare 7 Mask Bit 4 */
    byte OC7M5       :1;                                       /* Output Compare 7 Mask Bit 5 */
    byte OC7M6       :1;                                       /* Output Compare 7 Mask Bit 6 */
    byte OC7M7       :1;                                       /* Output Compare 7 Mask Bit 7 */
  } Bits;
} OC7MSTR;
extern volatile OC7MSTR _OC7M @(REG_BASE + 0x00000042UL);
#define OC7M                            _OC7M.Byte
#define OC7M_OC7M0                      _OC7M.Bits.OC7M0
#define OC7M_OC7M1                      _OC7M.Bits.OC7M1
#define OC7M_OC7M2                      _OC7M.Bits.OC7M2
#define OC7M_OC7M3                      _OC7M.Bits.OC7M3
#define OC7M_OC7M4                      _OC7M.Bits.OC7M4
#define OC7M_OC7M5                      _OC7M.Bits.OC7M5
#define OC7M_OC7M6                      _OC7M.Bits.OC7M6
#define OC7M_OC7M7                      _OC7M.Bits.OC7M7

#define OC7M_OC7M0_MASK                 1U
#define OC7M_OC7M1_MASK                 2U
#define OC7M_OC7M2_MASK                 4U
#define OC7M_OC7M3_MASK                 8U
#define OC7M_OC7M4_MASK                 16U
#define OC7M_OC7M5_MASK                 32U
#define OC7M_OC7M6_MASK                 64U
#define OC7M_OC7M7_MASK                 128U


/*** OC7D - Output Compare 7 Data Register; 0x00000043 ***/
typedef union {
  byte Byte;
  struct {
    byte OC7D0       :1;                                       /* Output Compare 7 Bit 0 */
    byte OC7D1       :1;                                       /* Output Compare 7 Bit 1 */
    byte OC7D2       :1;                                       /* Output Compare 7 Bit 2 */
    byte OC7D3       :1;                                       /* Output Compare 7 Bit 3 */
    byte OC7D4       :1;                                       /* Output Compare 7 Bit 4 */
    byte OC7D5       :1;                                       /* Output Compare 7 Bit 5 */
    byte OC7D6       :1;                                       /* Output Compare 7 Bit 6 */
    byte OC7D7       :1;                                       /* Output Compare 7 Bit 7 */
  } Bits;
} OC7DSTR;
extern volatile OC7DSTR _OC7D @(REG_BASE + 0x00000043UL);
#define OC7D                            _OC7D.Byte
#define OC7D_OC7D0                      _OC7D.Bits.OC7D0
#define OC7D_OC7D1                      _OC7D.Bits.OC7D1
#define OC7D_OC7D2                      _OC7D.Bits.OC7D2
#define OC7D_OC7D3                      _OC7D.Bits.OC7D3
#define OC7D_OC7D4                      _OC7D.Bits.OC7D4
#define OC7D_OC7D5                      _OC7D.Bits.OC7D5
#define OC7D_OC7D6                      _OC7D.Bits.OC7D6
#define OC7D_OC7D7                      _OC7D.Bits.OC7D7

#define OC7D_OC7D0_MASK                 1U
#define OC7D_OC7D1_MASK                 2U
#define OC7D_OC7D2_MASK                 4U
#define OC7D_OC7D3_MASK                 8U
#define OC7D_OC7D4_MASK                 16U
#define OC7D_OC7D5_MASK                 32U
#define OC7D_OC7D6_MASK                 64U
#define OC7D_OC7D7_MASK                 128U


/*** TCNT - Timer Count Register; 0x00000044 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TCNTHi - Timer Count Register High; 0x00000044 ***/
    union {
      byte Byte;
    } TCNTHiSTR;
    #define TCNTHi                      _TCNT.Overlap_STR.TCNTHiSTR.Byte
    

    /*** TCNTLo - Timer Count Register Low; 0x00000045 ***/
    union {
      byte Byte;
    } TCNTLoSTR;
    #define TCNTLo                      _TCNT.Overlap_STR.TCNTLoSTR.Byte
    
  } Overlap_STR;

} TCNTSTR;
extern volatile TCNTSTR _TCNT @(REG_BASE + 0x00000044UL);
#define TCNT                            _TCNT.Word


/*** TSCR1 - Timer System Control Register1; 0x00000046 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TFFCA       :1;                                       /* Timer Fast Flag Clear All */
    byte TSFRZ       :1;                                       /* Timer and Modulus Counter Stop While in Freeze Mode */
    byte TSWAI       :1;                                       /* Timer Module Stops While in Wait */
    byte TEN         :1;                                       /* Timer Enable */
  } Bits;
} TSCR1STR;
extern volatile TSCR1STR _TSCR1 @(REG_BASE + 0x00000046UL);
#define TSCR1                           _TSCR1.Byte
#define TSCR1_TFFCA                     _TSCR1.Bits.TFFCA
#define TSCR1_TSFRZ                     _TSCR1.Bits.TSFRZ
#define TSCR1_TSWAI                     _TSCR1.Bits.TSWAI
#define TSCR1_TEN                       _TSCR1.Bits.TEN

#define TSCR1_TFFCA_MASK                16U
#define TSCR1_TSFRZ_MASK                32U
#define TSCR1_TSWAI_MASK                64U
#define TSCR1_TEN_MASK                  128U


/*** TTOV - Timer Toggle On Overflow Register; 0x00000047 ***/
typedef union {
  byte Byte;
  struct {
    byte TOV0        :1;                                       /* Toggle On Overflow Bit 0 */
    byte TOV1        :1;                                       /* Toggle On Overflow Bit 1 */
    byte TOV2        :1;                                       /* Toggle On Overflow Bit 2 */
    byte TOV3        :1;                                       /* Toggle On Overflow Bit 3 */
    byte TOV4        :1;                                       /* Toggle On Overflow Bit 4 */
    byte TOV5        :1;                                       /* Toggle On Overflow Bit 5 */
    byte TOV6        :1;                                       /* Toggle On Overflow Bit 6 */
    byte TOV7        :1;                                       /* Toggle On Overflow Bit 7 */
  } Bits;
} TTOVSTR;
extern volatile TTOVSTR _TTOV @(REG_BASE + 0x00000047UL);
#define TTOV                            _TTOV.Byte
#define TTOV_TOV0                       _TTOV.Bits.TOV0
#define TTOV_TOV1                       _TTOV.Bits.TOV1
#define TTOV_TOV2                       _TTOV.Bits.TOV2
#define TTOV_TOV3                       _TTOV.Bits.TOV3
#define TTOV_TOV4                       _TTOV.Bits.TOV4
#define TTOV_TOV5                       _TTOV.Bits.TOV5
#define TTOV_TOV6                       _TTOV.Bits.TOV6
#define TTOV_TOV7                       _TTOV.Bits.TOV7

#define TTOV_TOV0_MASK                  1U
#define TTOV_TOV1_MASK                  2U
#define TTOV_TOV2_MASK                  4U
#define TTOV_TOV3_MASK                  8U
#define TTOV_TOV4_MASK                  16U
#define TTOV_TOV5_MASK                  32U
#define TTOV_TOV6_MASK                  64U
#define TTOV_TOV7_MASK                  128U


/*** TCTL1 - Timer Control Register 1; 0x00000048 ***/
typedef union {
  byte Byte;
  struct {
    byte OL4         :1;                                       /* Output Level Bit 4 */
    byte OM4         :1;                                       /* Output Mode Bit 4 */
    byte OL5         :1;                                       /* Output Level Bit 5 */
    byte OM5         :1;                                       /* Output Mode Bit 5 */
    byte OL6         :1;                                       /* Output Level Bit 6 */
    byte OM6         :1;                                       /* Output Mode Bit 6 */
    byte OL7         :1;                                       /* Output Level Bit 7 */
    byte OM7         :1;                                       /* Output Mode Bit 7 */
  } Bits;
} TCTL1STR;
extern volatile TCTL1STR _TCTL1 @(REG_BASE + 0x00000048UL);
#define TCTL1                           _TCTL1.Byte
#define TCTL1_OL4                       _TCTL1.Bits.OL4
#define TCTL1_OM4                       _TCTL1.Bits.OM4
#define TCTL1_OL5                       _TCTL1.Bits.OL5
#define TCTL1_OM5                       _TCTL1.Bits.OM5
#define TCTL1_OL6                       _TCTL1.Bits.OL6
#define TCTL1_OM6                       _TCTL1.Bits.OM6
#define TCTL1_OL7                       _TCTL1.Bits.OL7
#define TCTL1_OM7                       _TCTL1.Bits.OM7

#define TCTL1_OL4_MASK                  1U
#define TCTL1_OM4_MASK                  2U
#define TCTL1_OL5_MASK                  4U
#define TCTL1_OM5_MASK                  8U
#define TCTL1_OL6_MASK                  16U
#define TCTL1_OM6_MASK                  32U
#define TCTL1_OL7_MASK                  64U
#define TCTL1_OM7_MASK                  128U


/*** TCTL2 - Timer Control Register 2; 0x00000049 ***/
typedef union {
  byte Byte;
  struct {
    byte OL0         :1;                                       /* Output Level Bit 0 */
    byte OM0         :1;                                       /* Output Mode Bit 0 */
    byte OL1         :1;                                       /* Output Level Bit 1 */
    byte OM1         :1;                                       /* Output Mode Bit 1 */
    byte OL2         :1;                                       /* Output Level Bit 2 */
    byte OM2         :1;                                       /* Output Mode Bit 2 */
    byte OL3         :1;                                       /* Output Level Bit 3 */
    byte OM3         :1;                                       /* Output Mode Bit 3 */
  } Bits;
} TCTL2STR;
extern volatile TCTL2STR _TCTL2 @(REG_BASE + 0x00000049UL);
#define TCTL2                           _TCTL2.Byte
#define TCTL2_OL0                       _TCTL2.Bits.OL0
#define TCTL2_OM0                       _TCTL2.Bits.OM0
#define TCTL2_OL1                       _TCTL2.Bits.OL1
#define TCTL2_OM1                       _TCTL2.Bits.OM1
#define TCTL2_OL2                       _TCTL2.Bits.OL2
#define TCTL2_OM2                       _TCTL2.Bits.OM2
#define TCTL2_OL3                       _TCTL2.Bits.OL3
#define TCTL2_OM3                       _TCTL2.Bits.OM3

#define TCTL2_OL0_MASK                  1U
#define TCTL2_OM0_MASK                  2U
#define TCTL2_OL1_MASK                  4U
#define TCTL2_OM1_MASK                  8U
#define TCTL2_OL2_MASK                  16U
#define TCTL2_OM2_MASK                  32U
#define TCTL2_OL3_MASK                  64U
#define TCTL2_OM3_MASK                  128U


/*** TCTL3 - Timer Control Register 3; 0x0000004A ***/
typedef union {
  byte Byte;
  struct {
    byte EDG4A       :1;                                       /* Input Capture Edge Control 4A */
    byte EDG4B       :1;                                       /* Input Capture Edge Control 4B */
    byte EDG5A       :1;                                       /* Input Capture Edge Control 5A */
    byte EDG5B       :1;                                       /* Input Capture Edge Control 5B */
    byte EDG6A       :1;                                       /* Input Capture Edge Control 6A */
    byte EDG6B       :1;                                       /* Input Capture Edge Control 6B */
    byte EDG7A       :1;                                       /* Input Capture Edge Control 7A */
    byte EDG7B       :1;                                       /* Input Capture Edge Control 7B */
  } Bits;
  struct {
    byte grpEDG4x :2;
    byte grpEDG5x :2;
    byte grpEDG6x :2;
    byte grpEDG7x :2;
  } MergedBits;
} TCTL3STR;
extern volatile TCTL3STR _TCTL3 @(REG_BASE + 0x0000004AUL);
#define TCTL3                           _TCTL3.Byte
#define TCTL3_EDG4A                     _TCTL3.Bits.EDG4A
#define TCTL3_EDG4B                     _TCTL3.Bits.EDG4B
#define TCTL3_EDG5A                     _TCTL3.Bits.EDG5A
#define TCTL3_EDG5B                     _TCTL3.Bits.EDG5B
#define TCTL3_EDG6A                     _TCTL3.Bits.EDG6A
#define TCTL3_EDG6B                     _TCTL3.Bits.EDG6B
#define TCTL3_EDG7A                     _TCTL3.Bits.EDG7A
#define TCTL3_EDG7B                     _TCTL3.Bits.EDG7B
#define TCTL3_EDG4x                     _TCTL3.MergedBits.grpEDG4x
#define TCTL3_EDG5x                     _TCTL3.MergedBits.grpEDG5x
#define TCTL3_EDG6x                     _TCTL3.MergedBits.grpEDG6x
#define TCTL3_EDG7x                     _TCTL3.MergedBits.grpEDG7x

#define TCTL3_EDG4A_MASK                1U
#define TCTL3_EDG4B_MASK                2U
#define TCTL3_EDG5A_MASK                4U
#define TCTL3_EDG5B_MASK                8U
#define TCTL3_EDG6A_MASK                16U
#define TCTL3_EDG6B_MASK                32U
#define TCTL3_EDG7A_MASK                64U
#define TCTL3_EDG7B_MASK                128U
#define TCTL3_EDG4x_MASK                3U
#define TCTL3_EDG4x_BITNUM              0U
#define TCTL3_EDG5x_MASK                12U
#define TCTL3_EDG5x_BITNUM              2U
#define TCTL3_EDG6x_MASK                48U
#define TCTL3_EDG6x_BITNUM              4U
#define TCTL3_EDG7x_MASK                192U
#define TCTL3_EDG7x_BITNUM              6U


/*** TCTL4 - Timer Control Register 4; 0x0000004B ***/
typedef union {
  byte Byte;
  struct {
    byte EDG0A       :1;                                       /* Input Capture Edge Control 0A */
    byte EDG0B       :1;                                       /* Input Capture Edge Control 0B */
    byte EDG1A       :1;                                       /* Input Capture Edge Control 1A */
    byte EDG1B       :1;                                       /* Input Capture Edge Control 1B */
    byte EDG2A       :1;                                       /* Input Capture Edge Control 2A */
    byte EDG2B       :1;                                       /* Input Capture Edge Control 2B */
    byte EDG3A       :1;                                       /* Input Capture Edge Control 3A */
    byte EDG3B       :1;                                       /* Input Capture Edge Control 3B */
  } Bits;
  struct {
    byte grpEDG0x :2;
    byte grpEDG1x :2;
    byte grpEDG2x :2;
    byte grpEDG3x :2;
  } MergedBits;
} TCTL4STR;
extern volatile TCTL4STR _TCTL4 @(REG_BASE + 0x0000004BUL);
#define TCTL4                           _TCTL4.Byte
#define TCTL4_EDG0A                     _TCTL4.Bits.EDG0A
#define TCTL4_EDG0B                     _TCTL4.Bits.EDG0B
#define TCTL4_EDG1A                     _TCTL4.Bits.EDG1A
#define TCTL4_EDG1B                     _TCTL4.Bits.EDG1B
#define TCTL4_EDG2A                     _TCTL4.Bits.EDG2A
#define TCTL4_EDG2B                     _TCTL4.Bits.EDG2B
#define TCTL4_EDG3A                     _TCTL4.Bits.EDG3A
#define TCTL4_EDG3B                     _TCTL4.Bits.EDG3B
#define TCTL4_EDG0x                     _TCTL4.MergedBits.grpEDG0x
#define TCTL4_EDG1x                     _TCTL4.MergedBits.grpEDG1x
#define TCTL4_EDG2x                     _TCTL4.MergedBits.grpEDG2x
#define TCTL4_EDG3x                     _TCTL4.MergedBits.grpEDG3x

#define TCTL4_EDG0A_MASK                1U
#define TCTL4_EDG0B_MASK                2U
#define TCTL4_EDG1A_MASK                4U
#define TCTL4_EDG1B_MASK                8U
#define TCTL4_EDG2A_MASK                16U
#define TCTL4_EDG2B_MASK                32U
#define TCTL4_EDG3A_MASK                64U
#define TCTL4_EDG3B_MASK                128U
#define TCTL4_EDG0x_MASK                3U
#define TCTL4_EDG0x_BITNUM              0U
#define TCTL4_EDG1x_MASK                12U
#define TCTL4_EDG1x_BITNUM              2U
#define TCTL4_EDG2x_MASK                48U
#define TCTL4_EDG2x_BITNUM              4U
#define TCTL4_EDG3x_MASK                192U
#define TCTL4_EDG3x_BITNUM              6U


/*** TIE - Timer Interrupt Enable Register; 0x0000004C ***/
typedef union {
  byte Byte;
  struct {
    byte C0I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 0 */
    byte C1I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 1 */
    byte C2I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 2 */
    byte C3I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 3 */
    byte C4I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 4 */
    byte C5I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 5 */
    byte C6I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 6 */
    byte C7I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 7 */
  } Bits;
} TIESTR;
extern volatile TIESTR _TIE @(REG_BASE + 0x0000004CUL);
#define TIE                             _TIE.Byte
#define TIE_C0I                         _TIE.Bits.C0I
#define TIE_C1I                         _TIE.Bits.C1I
#define TIE_C2I                         _TIE.Bits.C2I
#define TIE_C3I                         _TIE.Bits.C3I
#define TIE_C4I                         _TIE.Bits.C4I
#define TIE_C5I                         _TIE.Bits.C5I
#define TIE_C6I                         _TIE.Bits.C6I
#define TIE_C7I                         _TIE.Bits.C7I

#define TIE_C0I_MASK                    1U
#define TIE_C1I_MASK                    2U
#define TIE_C2I_MASK                    4U
#define TIE_C3I_MASK                    8U
#define TIE_C4I_MASK                    16U
#define TIE_C5I_MASK                    32U
#define TIE_C6I_MASK                    64U
#define TIE_C7I_MASK                    128U


/*** TSCR2 - Timer System Control Register 2; 0x0000004D ***/
typedef union {
  byte Byte;
  struct {
    byte PR0         :1;                                       /* Timer Prescaler Select Bit 0 */
    byte PR1         :1;                                       /* Timer Prescaler Select Bit 1 */
    byte PR2         :1;                                       /* Timer Prescaler Select Bit 2 */
    byte TCRE        :1;                                       /* Timer Counter Reset Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOI         :1;                                       /* Timer Overflow Interrupt Enable */
  } Bits;
  struct {
    byte grpPR   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TSCR2STR;
extern volatile TSCR2STR _TSCR2 @(REG_BASE + 0x0000004DUL);
#define TSCR2                           _TSCR2.Byte
#define TSCR2_PR0                       _TSCR2.Bits.PR0
#define TSCR2_PR1                       _TSCR2.Bits.PR1
#define TSCR2_PR2                       _TSCR2.Bits.PR2
#define TSCR2_TCRE                      _TSCR2.Bits.TCRE
#define TSCR2_TOI                       _TSCR2.Bits.TOI
#define TSCR2_PR                        _TSCR2.MergedBits.grpPR

#define TSCR2_PR0_MASK                  1U
#define TSCR2_PR1_MASK                  2U
#define TSCR2_PR2_MASK                  4U
#define TSCR2_TCRE_MASK                 8U
#define TSCR2_TOI_MASK                  128U
#define TSCR2_PR_MASK                   7U
#define TSCR2_PR_BITNUM                 0U


/*** TFLG1 - Main Timer Interrupt Flag 1; 0x0000004E ***/
typedef union {
  byte Byte;
  struct {
    byte C0F         :1;                                       /* Input Capture/Output Compare Channel Flag 0 */
    byte C1F         :1;                                       /* Input Capture/Output Compare Channel Flag 1 */
    byte C2F         :1;                                       /* Input Capture/Output Compare Channel Flag 2 */
    byte C3F         :1;                                       /* Input Capture/Output Compare Channel Flag 3 */
    byte C4F         :1;                                       /* Input Capture/Output Compare Channel Flag 4 */
    byte C5F         :1;                                       /* Input Capture/Output Compare Channel Flag 5 */
    byte C6F         :1;                                       /* Input Capture/Output Compare Channel Flag 6 */
    byte C7F         :1;                                       /* Input Capture/Output Compare Channel Flag 7 */
  } Bits;
} TFLG1STR;
extern volatile TFLG1STR _TFLG1 @(REG_BASE + 0x0000004EUL);
#define TFLG1                           _TFLG1.Byte
#define TFLG1_C0F                       _TFLG1.Bits.C0F
#define TFLG1_C1F                       _TFLG1.Bits.C1F
#define TFLG1_C2F                       _TFLG1.Bits.C2F
#define TFLG1_C3F                       _TFLG1.Bits.C3F
#define TFLG1_C4F                       _TFLG1.Bits.C4F
#define TFLG1_C5F                       _TFLG1.Bits.C5F
#define TFLG1_C6F                       _TFLG1.Bits.C6F
#define TFLG1_C7F                       _TFLG1.Bits.C7F

#define TFLG1_C0F_MASK                  1U
#define TFLG1_C1F_MASK                  2U
#define TFLG1_C2F_MASK                  4U
#define TFLG1_C3F_MASK                  8U
#define TFLG1_C4F_MASK                  16U
#define TFLG1_C5F_MASK                  32U
#define TFLG1_C6F_MASK                  64U
#define TFLG1_C7F_MASK                  128U


/*** TFLG2 - Main Timer Interrupt Flag 2; 0x0000004F ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
} TFLG2STR;
extern volatile TFLG2STR _TFLG2 @(REG_BASE + 0x0000004FUL);
#define TFLG2                           _TFLG2.Byte
#define TFLG2_TOF                       _TFLG2.Bits.TOF

#define TFLG2_TOF_MASK                  128U


/*** TC0 - Timer Input Capture/Output Compare Register 0; 0x00000050 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC0Hi - Timer Input Capture/Output Compare Register 0 High; 0x00000050 ***/
    union {
      byte Byte;
    } TC0HiSTR;
    #define TC0Hi                       _TC0.Overlap_STR.TC0HiSTR.Byte
    

    /*** TC0Lo - Timer Input Capture/Output Compare Register 0 Low; 0x00000051 ***/
    union {
      byte Byte;
    } TC0LoSTR;
    #define TC0Lo                       _TC0.Overlap_STR.TC0LoSTR.Byte
    
  } Overlap_STR;

} TC0STR;
extern volatile TC0STR _TC0 @(REG_BASE + 0x00000050UL);
#define TC0                             _TC0.Word
/* TC_ARR: Access 8 TCx registers in an array */
#define TC_ARR                          ((volatile word *) &TC0)


/*** TC1 - Timer Input Capture/Output Compare Register 1; 0x00000052 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC1Hi - Timer Input Capture/Output Compare Register 1 High; 0x00000052 ***/
    union {
      byte Byte;
    } TC1HiSTR;
    #define TC1Hi                       _TC1.Overlap_STR.TC1HiSTR.Byte
    

    /*** TC1Lo - Timer Input Capture/Output Compare Register 1 Low; 0x00000053 ***/
    union {
      byte Byte;
    } TC1LoSTR;
    #define TC1Lo                       _TC1.Overlap_STR.TC1LoSTR.Byte
    
  } Overlap_STR;

} TC1STR;
extern volatile TC1STR _TC1 @(REG_BASE + 0x00000052UL);
#define TC1                             _TC1.Word


/*** TC2 - Timer Input Capture/Output Compare Register 2; 0x00000054 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC2Hi - Timer Input Capture/Output Compare Register 2 High; 0x00000054 ***/
    union {
      byte Byte;
    } TC2HiSTR;
    #define TC2Hi                       _TC2.Overlap_STR.TC2HiSTR.Byte
    

    /*** TC2Lo - Timer Input Capture/Output Compare Register 2 Low; 0x00000055 ***/
    union {
      byte Byte;
    } TC2LoSTR;
    #define TC2Lo                       _TC2.Overlap_STR.TC2LoSTR.Byte
    
  } Overlap_STR;

} TC2STR;
extern volatile TC2STR _TC2 @(REG_BASE + 0x00000054UL);
#define TC2                             _TC2.Word


/*** TC3 - Timer Input Capture/Output Compare Register 3; 0x00000056 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC3Hi - Timer Input Capture/Output Compare Register 3 High; 0x00000056 ***/
    union {
      byte Byte;
    } TC3HiSTR;
    #define TC3Hi                       _TC3.Overlap_STR.TC3HiSTR.Byte
    

    /*** TC3Lo - Timer Input Capture/Output Compare Register 3 Low; 0x00000057 ***/
    union {
      byte Byte;
    } TC3LoSTR;
    #define TC3Lo                       _TC3.Overlap_STR.TC3LoSTR.Byte
    
  } Overlap_STR;

} TC3STR;
extern volatile TC3STR _TC3 @(REG_BASE + 0x00000056UL);
#define TC3                             _TC3.Word


/*** TC4 - Timer Input Capture/Output Compare Register 4; 0x00000058 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC4Hi - Timer Input Capture/Output Compare Register 4 High; 0x00000058 ***/
    union {
      byte Byte;
    } TC4HiSTR;
    #define TC4Hi                       _TC4.Overlap_STR.TC4HiSTR.Byte
    

    /*** TC4Lo - Timer Input Capture/Output Compare Register 4 Low; 0x00000059 ***/
    union {
      byte Byte;
    } TC4LoSTR;
    #define TC4Lo                       _TC4.Overlap_STR.TC4LoSTR.Byte
    
  } Overlap_STR;

} TC4STR;
extern volatile TC4STR _TC4 @(REG_BASE + 0x00000058UL);
#define TC4                             _TC4.Word


/*** TC5 - Timer Input Capture/Output Compare Register 5; 0x0000005A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC5Hi - Timer Input Capture/Output Compare Register 5 High; 0x0000005A ***/
    union {
      byte Byte;
    } TC5HiSTR;
    #define TC5Hi                       _TC5.Overlap_STR.TC5HiSTR.Byte
    

    /*** TC5Lo - Timer Input Capture/Output Compare Register 5 Low; 0x0000005B ***/
    union {
      byte Byte;
    } TC5LoSTR;
    #define TC5Lo                       _TC5.Overlap_STR.TC5LoSTR.Byte
    
  } Overlap_STR;

} TC5STR;
extern volatile TC5STR _TC5 @(REG_BASE + 0x0000005AUL);
#define TC5                             _TC5.Word


/*** TC6 - Timer Input Capture/Output Compare Register 6; 0x0000005C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC6Hi - Timer Input Capture/Output Compare Register 6 High; 0x0000005C ***/
    union {
      byte Byte;
    } TC6HiSTR;
    #define TC6Hi                       _TC6.Overlap_STR.TC6HiSTR.Byte
    

    /*** TC6Lo - Timer Input Capture/Output Compare Register 6 Low; 0x0000005D ***/
    union {
      byte Byte;
    } TC6LoSTR;
    #define TC6Lo                       _TC6.Overlap_STR.TC6LoSTR.Byte
    
  } Overlap_STR;

} TC6STR;
extern volatile TC6STR _TC6 @(REG_BASE + 0x0000005CUL);
#define TC6                             _TC6.Word


/*** TC7 - Timer Input Capture/Output Compare Register 7; 0x0000005E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC7Hi - Timer Input Capture/Output Compare Register 7 High; 0x0000005E ***/
    union {
      byte Byte;
    } TC7HiSTR;
    #define TC7Hi                       _TC7.Overlap_STR.TC7HiSTR.Byte
    

    /*** TC7Lo - Timer Input Capture/Output Compare Register 7 Low; 0x0000005F ***/
    union {
      byte Byte;
    } TC7LoSTR;
    #define TC7Lo                       _TC7.Overlap_STR.TC7LoSTR.Byte
    
  } Overlap_STR;

} TC7STR;
extern volatile TC7STR _TC7 @(REG_BASE + 0x0000005EUL);
#define TC7                             _TC7.Word


/*** PACTL - 16-Bit Pulse Accumulator A Control Register; 0x00000060 ***/
typedef union {
  byte Byte;
  struct {
    byte PAI         :1;                                       /* Pulse Accumulator Input Interrupt enable */
    byte PAOVI       :1;                                       /* Pulse Accumulator A Overflow Interrupt enable */
    byte CLK0        :1;                                       /* Clock Select Bit 0 */
    byte CLK1        :1;                                       /* Clock Select Bit 1 */
    byte PEDGE       :1;                                       /* Pulse Accumulator Edge Control */
    byte PAMOD       :1;                                       /* Pulse Accumulator Mode */
    byte PAEN        :1;                                       /* Pulse Accumulator A System Enable */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpCLK  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PACTLSTR;
extern volatile PACTLSTR _PACTL @(REG_BASE + 0x00000060UL);
#define PACTL                           _PACTL.Byte
#define PACTL_PAI                       _PACTL.Bits.PAI
#define PACTL_PAOVI                     _PACTL.Bits.PAOVI
#define PACTL_CLK0                      _PACTL.Bits.CLK0
#define PACTL_CLK1                      _PACTL.Bits.CLK1
#define PACTL_PEDGE                     _PACTL.Bits.PEDGE
#define PACTL_PAMOD                     _PACTL.Bits.PAMOD
#define PACTL_PAEN                      _PACTL.Bits.PAEN
#define PACTL_CLK                       _PACTL.MergedBits.grpCLK

#define PACTL_PAI_MASK                  1U
#define PACTL_PAOVI_MASK                2U
#define PACTL_CLK0_MASK                 4U
#define PACTL_CLK1_MASK                 8U
#define PACTL_PEDGE_MASK                16U
#define PACTL_PAMOD_MASK                32U
#define PACTL_PAEN_MASK                 64U
#define PACTL_CLK_MASK                  12U
#define PACTL_CLK_BITNUM                2U


/*** PAFLG - Pulse Accumulator A Flag Register; 0x00000061 ***/
typedef union {
  byte Byte;
  struct {
    byte PAIF        :1;                                       /* Pulse Accumulator Input edge Flag */
    byte PAOVF       :1;                                       /* Pulse Accumulator A Overflow Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PAFLGSTR;
extern volatile PAFLGSTR _PAFLG @(REG_BASE + 0x00000061UL);
#define PAFLG                           _PAFLG.Byte
#define PAFLG_PAIF                      _PAFLG.Bits.PAIF
#define PAFLG_PAOVF                     _PAFLG.Bits.PAOVF

#define PAFLG_PAIF_MASK                 1U
#define PAFLG_PAOVF_MASK                2U


/*** PACNT - Pulse Accumulators Count Register; 0x00000062 ***/
typedef union {
  word Word;
} PACNTSTR;
extern volatile PACNTSTR _PACNT @(REG_BASE + 0x00000062UL);
#define PACNT                           _PACNT.Word


/*** ATDCTL23 - ATD Control Register 23; 0x00000082 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDCTL2 - ATD Control Register 2; 0x00000082 ***/
    union {
      byte Byte;
      struct {
        byte ASCIF       :1;                                       /* ATD Sequence Complete Interrupt Flag */
        byte ASCIE       :1;                                       /* ATD Sequence Complete Interrupt Enable */
        byte ETRIGE      :1;                                       /* External Trigger Mode enable */
        byte ETRIGP      :1;                                       /* External Trigger Polarity */
        byte ETRIGLE     :1;                                       /* External Trigger Level/Edge control */
        byte AWAI        :1;                                       /* ATD Power Down in Wait Mode */
        byte AFFC        :1;                                       /* ATD Fast Conversion Complete Flag Clear */
        byte ADPU        :1;                                       /* ATD Disable / Power Down */
      } Bits;
    } ATDCTL2STR;
    #define ATDCTL2                     _ATDCTL23.Overlap_STR.ATDCTL2STR.Byte
    #define ATDCTL2_ASCIF               _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ASCIF
    #define ATDCTL2_ASCIE               _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ASCIE
    #define ATDCTL2_ETRIGE              _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ETRIGE
    #define ATDCTL2_ETRIGP              _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ETRIGP
    #define ATDCTL2_ETRIGLE             _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ETRIGLE
    #define ATDCTL2_AWAI                _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.AWAI
    #define ATDCTL2_AFFC                _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.AFFC
    #define ATDCTL2_ADPU                _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ADPU
    
    #define ATDCTL2_ASCIF_MASK          1U
    #define ATDCTL2_ASCIE_MASK          2U
    #define ATDCTL2_ETRIGE_MASK         4U
    #define ATDCTL2_ETRIGP_MASK         8U
    #define ATDCTL2_ETRIGLE_MASK        16U
    #define ATDCTL2_AWAI_MASK           32U
    #define ATDCTL2_AFFC_MASK           64U
    #define ATDCTL2_ADPU_MASK           128U
    

    /*** ATDCTL3 - ATD Control Register 3; 0x00000083 ***/
    union {
      byte Byte;
      struct {
        byte FRZ0        :1;                                       /* Background Debug Freeze Enable Bit 0 */
        byte FRZ1        :1;                                       /* Background Debug Freeze Enable Bit 1 */
        byte FIFO        :1;                                       /* Result Register FIFO Mode */
        byte S1C         :1;                                       /* Conversion Sequence Length 1 */
        byte S2C         :1;                                       /* Conversion Sequence Length 2 */
        byte S4C         :1;                                       /* Conversion Sequence Length 4 */
        byte S8C         :1;                                       /* Conversion Sequence Length 8 */
        byte             :1; 
      } Bits;
      struct {
        byte grpFRZ :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATDCTL3STR;
    #define ATDCTL3                     _ATDCTL23.Overlap_STR.ATDCTL3STR.Byte
    #define ATDCTL3_FRZ0                _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.FRZ0
    #define ATDCTL3_FRZ1                _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.FRZ1
    #define ATDCTL3_FIFO                _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.FIFO
    #define ATDCTL3_S1C                 _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.S1C
    #define ATDCTL3_S2C                 _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.S2C
    #define ATDCTL3_S4C                 _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.S4C
    #define ATDCTL3_S8C                 _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.S8C
    #define ATDCTL3_FRZ                 _ATDCTL23.Overlap_STR.ATDCTL3STR.MergedBits.grpFRZ
    
    #define ATDCTL3_FRZ0_MASK           1U
    #define ATDCTL3_FRZ1_MASK           2U
    #define ATDCTL3_FIFO_MASK           4U
    #define ATDCTL3_S1C_MASK            8U
    #define ATDCTL3_S2C_MASK            16U
    #define ATDCTL3_S4C_MASK            32U
    #define ATDCTL3_S8C_MASK            64U
    #define ATDCTL3_FRZ_MASK            3U
    #define ATDCTL3_FRZ_BITNUM          0U
    
  } Overlap_STR;

  struct {
    word FRZ0        :1;                                       /* Background Debug Freeze Enable Bit 0 */
    word FRZ1        :1;                                       /* Background Debug Freeze Enable Bit 1 */
    word FIFO        :1;                                       /* Result Register FIFO Mode */
    word S1C         :1;                                       /* Conversion Sequence Length 1 */
    word S2C         :1;                                       /* Conversion Sequence Length 2 */
    word S4C         :1;                                       /* Conversion Sequence Length 4 */
    word S8C         :1;                                       /* Conversion Sequence Length 8 */
    word             :1; 
    word ASCIF       :1;                                       /* ATD Sequence Complete Interrupt Flag */
    word ASCIE       :1;                                       /* ATD Sequence Complete Interrupt Enable */
    word ETRIGE      :1;                                       /* External Trigger Mode enable */
    word ETRIGP      :1;                                       /* External Trigger Polarity */
    word ETRIGLE     :1;                                       /* External Trigger Level/Edge control */
    word AWAI        :1;                                       /* ATD Power Down in Wait Mode */
    word AFFC        :1;                                       /* ATD Fast Conversion Complete Flag Clear */
    word ADPU        :1;                                       /* ATD Disable / Power Down */
  } Bits;
  struct {
    word grpFRZ  :2;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ATDCTL23STR;
extern volatile ATDCTL23STR _ATDCTL23 @(REG_BASE + 0x00000082UL);
#define ATDCTL23                        _ATDCTL23.Word
#define ATDCTL23_FRZ0                   _ATDCTL23.Bits.FRZ0
#define ATDCTL23_FRZ1                   _ATDCTL23.Bits.FRZ1
#define ATDCTL23_FIFO                   _ATDCTL23.Bits.FIFO
#define ATDCTL23_S1C                    _ATDCTL23.Bits.S1C
#define ATDCTL23_S2C                    _ATDCTL23.Bits.S2C
#define ATDCTL23_S4C                    _ATDCTL23.Bits.S4C
#define ATDCTL23_S8C                    _ATDCTL23.Bits.S8C
#define ATDCTL23_ASCIF                  _ATDCTL23.Bits.ASCIF
#define ATDCTL23_ASCIE                  _ATDCTL23.Bits.ASCIE
#define ATDCTL23_ETRIGE                 _ATDCTL23.Bits.ETRIGE
#define ATDCTL23_ETRIGP                 _ATDCTL23.Bits.ETRIGP
#define ATDCTL23_ETRIGLE                _ATDCTL23.Bits.ETRIGLE
#define ATDCTL23_AWAI                   _ATDCTL23.Bits.AWAI
#define ATDCTL23_AFFC                   _ATDCTL23.Bits.AFFC
#define ATDCTL23_ADPU                   _ATDCTL23.Bits.ADPU
#define ATDCTL23_FRZ                    _ATDCTL23.MergedBits.grpFRZ

#define ATDCTL23_FRZ0_MASK              1U
#define ATDCTL23_FRZ1_MASK              2U
#define ATDCTL23_FIFO_MASK              4U
#define ATDCTL23_S1C_MASK               8U
#define ATDCTL23_S2C_MASK               16U
#define ATDCTL23_S4C_MASK               32U
#define ATDCTL23_S8C_MASK               64U
#define ATDCTL23_ASCIF_MASK             256U
#define ATDCTL23_ASCIE_MASK             512U
#define ATDCTL23_ETRIGE_MASK            1024U
#define ATDCTL23_ETRIGP_MASK            2048U
#define ATDCTL23_ETRIGLE_MASK           4096U
#define ATDCTL23_AWAI_MASK              8192U
#define ATDCTL23_AFFC_MASK              16384U
#define ATDCTL23_ADPU_MASK              32768U
#define ATDCTL23_FRZ_MASK               3U
#define ATDCTL23_FRZ_BITNUM             0U


/*** ATDCTL45 - ATD Control Register 45; 0x00000084 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDCTL4 - ATD Control Register 4; 0x00000084 ***/
    union {
      byte Byte;
      struct {
        byte PRS0        :1;                                       /* ATD Clock Prescaler 0 */
        byte PRS1        :1;                                       /* ATD Clock Prescaler 1 */
        byte PRS2        :1;                                       /* ATD Clock Prescaler 2 */
        byte PRS3        :1;                                       /* ATD Clock Prescaler 3 */
        byte PRS4        :1;                                       /* ATD Clock Prescaler 4 */
        byte SMP0        :1;                                       /* Sample Time Select 0 */
        byte SMP1        :1;                                       /* Sample Time Select 1 */
        byte SRES8       :1;                                       /* ATD Resolution Select */
      } Bits;
      struct {
        byte grpPRS :5;
        byte grpSMP :2;
        byte grpSRES_8 :1;
      } MergedBits;
    } ATDCTL4STR;
    #define ATDCTL4                     _ATDCTL45.Overlap_STR.ATDCTL4STR.Byte
    #define ATDCTL4_PRS0                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS0
    #define ATDCTL4_PRS1                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS1
    #define ATDCTL4_PRS2                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS2
    #define ATDCTL4_PRS3                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS3
    #define ATDCTL4_PRS4                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS4
    #define ATDCTL4_SMP0                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.SMP0
    #define ATDCTL4_SMP1                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.SMP1
    #define ATDCTL4_SRES8               _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.SRES8
    #define ATDCTL4_PRS                 _ATDCTL45.Overlap_STR.ATDCTL4STR.MergedBits.grpPRS
    #define ATDCTL4_SMP                 _ATDCTL45.Overlap_STR.ATDCTL4STR.MergedBits.grpSMP
    
    #define ATDCTL4_PRS0_MASK           1U
    #define ATDCTL4_PRS1_MASK           2U
    #define ATDCTL4_PRS2_MASK           4U
    #define ATDCTL4_PRS3_MASK           8U
    #define ATDCTL4_PRS4_MASK           16U
    #define ATDCTL4_SMP0_MASK           32U
    #define ATDCTL4_SMP1_MASK           64U
    #define ATDCTL4_SRES8_MASK          128U
    #define ATDCTL4_PRS_MASK            31U
    #define ATDCTL4_PRS_BITNUM          0U
    #define ATDCTL4_SMP_MASK            96U
    #define ATDCTL4_SMP_BITNUM          5U
    

    /*** ATDCTL5 - ATD Control Register 5; 0x00000085 ***/
    union {
      byte Byte;
      struct {
        byte CA          :1;                                       /* Analog Input Channel Select Code A */
        byte CB          :1;                                       /* Analog Input Channel Select Code B */
        byte CC          :1;                                       /* Analog Input Channel Select Code C */
        byte             :1; 
        byte MULT        :1;                                       /* Multi-Channel Sample Mode */
        byte SCAN        :1;                                       /* Continuous Conversion Sequence Mode */
        byte DSGN        :1;                                       /* Signed/Unsigned Result Data Mode */
        byte DJM         :1;                                       /* Result Register Data Justification Mode */
      } Bits;
      struct {
        byte grpCx :3;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATDCTL5STR;
    #define ATDCTL5                     _ATDCTL45.Overlap_STR.ATDCTL5STR.Byte
    #define ATDCTL5_CA                  _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.CA
    #define ATDCTL5_CB                  _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.CB
    #define ATDCTL5_CC                  _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.CC
    #define ATDCTL5_MULT                _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.MULT
    #define ATDCTL5_SCAN                _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.SCAN
    #define ATDCTL5_DSGN                _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.DSGN
    #define ATDCTL5_DJM                 _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.DJM
    #define ATDCTL5_Cx                  _ATDCTL45.Overlap_STR.ATDCTL5STR.MergedBits.grpCx
    
    #define ATDCTL5_CA_MASK             1U
    #define ATDCTL5_CB_MASK             2U
    #define ATDCTL5_CC_MASK             4U
    #define ATDCTL5_MULT_MASK           16U
    #define ATDCTL5_SCAN_MASK           32U
    #define ATDCTL5_DSGN_MASK           64U
    #define ATDCTL5_DJM_MASK            128U
    #define ATDCTL5_Cx_MASK             7U
    #define ATDCTL5_Cx_BITNUM           0U
    
  } Overlap_STR;

  struct {
    word CA          :1;                                       /* Analog Input Channel Select Code A */
    word CB          :1;                                       /* Analog Input Channel Select Code B */
    word CC          :1;                                       /* Analog Input Channel Select Code C */
    word             :1; 
    word MULT        :1;                                       /* Multi-Channel Sample Mode */
    word SCAN        :1;                                       /* Continuous Conversion Sequence Mode */
    word DSGN        :1;                                       /* Signed/Unsigned Result Data Mode */
    word DJM         :1;                                       /* Result Register Data Justification Mode */
    word PRS0        :1;                                       /* ATD Clock Prescaler 0 */
    word PRS1        :1;                                       /* ATD Clock Prescaler 1 */
    word PRS2        :1;                                       /* ATD Clock Prescaler 2 */
    word PRS3        :1;                                       /* ATD Clock Prescaler 3 */
    word PRS4        :1;                                       /* ATD Clock Prescaler 4 */
    word SMP0        :1;                                       /* Sample Time Select 0 */
    word SMP1        :1;                                       /* Sample Time Select 1 */
    word SRES8       :1;                                       /* ATD Resolution Select */
  } Bits;
  struct {
    word grpCx   :3;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpPRS  :5;
    word grpSMP  :2;
    word grpSRES_8 :1;
  } MergedBits;
} ATDCTL45STR;
extern volatile ATDCTL45STR _ATDCTL45 @(REG_BASE + 0x00000084UL);
#define ATDCTL45                        _ATDCTL45.Word
#define ATDCTL45_CA                     _ATDCTL45.Bits.CA
#define ATDCTL45_CB                     _ATDCTL45.Bits.CB
#define ATDCTL45_CC                     _ATDCTL45.Bits.CC
#define ATDCTL45_MULT                   _ATDCTL45.Bits.MULT
#define ATDCTL45_SCAN                   _ATDCTL45.Bits.SCAN
#define ATDCTL45_DSGN                   _ATDCTL45.Bits.DSGN
#define ATDCTL45_DJM                    _ATDCTL45.Bits.DJM
#define ATDCTL45_PRS0                   _ATDCTL45.Bits.PRS0
#define ATDCTL45_PRS1                   _ATDCTL45.Bits.PRS1
#define ATDCTL45_PRS2                   _ATDCTL45.Bits.PRS2
#define ATDCTL45_PRS3                   _ATDCTL45.Bits.PRS3
#define ATDCTL45_PRS4                   _ATDCTL45.Bits.PRS4
#define ATDCTL45_SMP0                   _ATDCTL45.Bits.SMP0
#define ATDCTL45_SMP1                   _ATDCTL45.Bits.SMP1
#define ATDCTL45_SRES8                  _ATDCTL45.Bits.SRES8
#define ATDCTL45_Cx                     _ATDCTL45.MergedBits.grpCx
#define ATDCTL45_PRS                    _ATDCTL45.MergedBits.grpPRS
#define ATDCTL45_SMP                    _ATDCTL45.MergedBits.grpSMP

#define ATDCTL45_CA_MASK                1U
#define ATDCTL45_CB_MASK                2U
#define ATDCTL45_CC_MASK                4U
#define ATDCTL45_MULT_MASK              16U
#define ATDCTL45_SCAN_MASK              32U
#define ATDCTL45_DSGN_MASK              64U
#define ATDCTL45_DJM_MASK               128U
#define ATDCTL45_PRS0_MASK              256U
#define ATDCTL45_PRS1_MASK              512U
#define ATDCTL45_PRS2_MASK              1024U
#define ATDCTL45_PRS3_MASK              2048U
#define ATDCTL45_PRS4_MASK              4096U
#define ATDCTL45_SMP0_MASK              8192U
#define ATDCTL45_SMP1_MASK              16384U
#define ATDCTL45_SRES8_MASK             32768U
#define ATDCTL45_Cx_MASK                7U
#define ATDCTL45_Cx_BITNUM              0U
#define ATDCTL45_PRS_MASK               7936U
#define ATDCTL45_PRS_BITNUM             8U
#define ATDCTL45_SMP_MASK               24576U
#define ATDCTL45_SMP_BITNUM             13U


/*** ATDSTAT0 - ATD Status Register 0; 0x00000086 ***/
typedef union {
  byte Byte;
  struct {
    byte CC0         :1;                                       /* Conversion Counter 0 */
    byte CC1         :1;                                       /* Conversion Counter 1 */
    byte CC2         :1;                                       /* Conversion Counter 2 */
    byte             :1; 
    byte FIFOR       :1;                                       /* FIFO Over Run Flag */
    byte ETORF       :1;                                       /* External Trigger Overrun Flag */
    byte             :1; 
    byte SCF         :1;                                       /* Sequence Complete Flag */
  } Bits;
  struct {
    byte grpCC   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ATDSTAT0STR;
extern volatile ATDSTAT0STR _ATDSTAT0 @(REG_BASE + 0x00000086UL);
#define ATDSTAT0                        _ATDSTAT0.Byte
#define ATDSTAT0_CC0                    _ATDSTAT0.Bits.CC0
#define ATDSTAT0_CC1                    _ATDSTAT0.Bits.CC1
#define ATDSTAT0_CC2                    _ATDSTAT0.Bits.CC2
#define ATDSTAT0_FIFOR                  _ATDSTAT0.Bits.FIFOR
#define ATDSTAT0_ETORF                  _ATDSTAT0.Bits.ETORF
#define ATDSTAT0_SCF                    _ATDSTAT0.Bits.SCF
#define ATDSTAT0_CC                     _ATDSTAT0.MergedBits.grpCC

#define ATDSTAT0_CC0_MASK               1U
#define ATDSTAT0_CC1_MASK               2U
#define ATDSTAT0_CC2_MASK               4U
#define ATDSTAT0_FIFOR_MASK             16U
#define ATDSTAT0_ETORF_MASK             32U
#define ATDSTAT0_SCF_MASK               128U
#define ATDSTAT0_CC_MASK                7U
#define ATDSTAT0_CC_BITNUM              0U


/*** ATDTEST1 - ATD Test Register; 0x00000089 ***/
typedef union {
  byte Byte;
  struct {
    byte SC          :1;                                       /* Special Channel Conversion Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} ATDTEST1STR;
extern volatile ATDTEST1STR _ATDTEST1 @(REG_BASE + 0x00000089UL);
#define ATDTEST1                        _ATDTEST1.Byte
#define ATDTEST1_SC                     _ATDTEST1.Bits.SC

#define ATDTEST1_SC_MASK                1U


/*** ATDSTAT1 - ATD Status Register 1; 0x0000008B ***/
typedef union {
  byte Byte;
  struct {
    byte CCF0        :1;                                       /* Conversion Complete Flag 0 */
    byte CCF1        :1;                                       /* Conversion Complete Flag 1 */
    byte CCF2        :1;                                       /* Conversion Complete Flag 2 */
    byte CCF3        :1;                                       /* Conversion Complete Flag 3 */
    byte CCF4        :1;                                       /* Conversion Complete Flag 4 */
    byte CCF5        :1;                                       /* Conversion Complete Flag 5 */
    byte CCF6        :1;                                       /* Conversion Complete Flag 6 */
    byte CCF7        :1;                                       /* Conversion Complete Flag 7 */
  } Bits;
} ATDSTAT1STR;
extern volatile ATDSTAT1STR _ATDSTAT1 @(REG_BASE + 0x0000008BUL);
#define ATDSTAT1                        _ATDSTAT1.Byte
#define ATDSTAT1_CCF0                   _ATDSTAT1.Bits.CCF0
#define ATDSTAT1_CCF1                   _ATDSTAT1.Bits.CCF1
#define ATDSTAT1_CCF2                   _ATDSTAT1.Bits.CCF2
#define ATDSTAT1_CCF3                   _ATDSTAT1.Bits.CCF3
#define ATDSTAT1_CCF4                   _ATDSTAT1.Bits.CCF4
#define ATDSTAT1_CCF5                   _ATDSTAT1.Bits.CCF5
#define ATDSTAT1_CCF6                   _ATDSTAT1.Bits.CCF6
#define ATDSTAT1_CCF7                   _ATDSTAT1.Bits.CCF7

#define ATDSTAT1_CCF0_MASK              1U
#define ATDSTAT1_CCF1_MASK              2U
#define ATDSTAT1_CCF2_MASK              4U
#define ATDSTAT1_CCF3_MASK              8U
#define ATDSTAT1_CCF4_MASK              16U
#define ATDSTAT1_CCF5_MASK              32U
#define ATDSTAT1_CCF6_MASK              64U
#define ATDSTAT1_CCF7_MASK              128U


/*** ATDDIEN - ATD Input Enable Register; 0x0000008D ***/
typedef union {
  byte Byte;
  struct {
    byte IEN0        :1;                                       /* ATD Digital Input Enable on channel 0 */
    byte IEN1        :1;                                       /* ATD Digital Input Enable on channel 1 */
    byte IEN2        :1;                                       /* ATD Digital Input Enable on channel 2 */
    byte IEN3        :1;                                       /* ATD Digital Input Enable on channel 3 */
    byte IEN4        :1;                                       /* ATD Digital Input Enable on channel 4 */
    byte IEN5        :1;                                       /* ATD Digital Input Enable on channel 5 */
    byte IEN6        :1;                                       /* ATD Digital Input Enable on channel 6 */
    byte IEN7        :1;                                       /* ATD Digital Input Enable on channel 7 */
  } Bits;
} ATDDIENSTR;
extern volatile ATDDIENSTR _ATDDIEN @(REG_BASE + 0x0000008DUL);
#define ATDDIEN                         _ATDDIEN.Byte
#define ATDDIEN_IEN0                    _ATDDIEN.Bits.IEN0
#define ATDDIEN_IEN1                    _ATDDIEN.Bits.IEN1
#define ATDDIEN_IEN2                    _ATDDIEN.Bits.IEN2
#define ATDDIEN_IEN3                    _ATDDIEN.Bits.IEN3
#define ATDDIEN_IEN4                    _ATDDIEN.Bits.IEN4
#define ATDDIEN_IEN5                    _ATDDIEN.Bits.IEN5
#define ATDDIEN_IEN6                    _ATDDIEN.Bits.IEN6
#define ATDDIEN_IEN7                    _ATDDIEN.Bits.IEN7

#define ATDDIEN_IEN0_MASK               1U
#define ATDDIEN_IEN1_MASK               2U
#define ATDDIEN_IEN2_MASK               4U
#define ATDDIEN_IEN3_MASK               8U
#define ATDDIEN_IEN4_MASK               16U
#define ATDDIEN_IEN5_MASK               32U
#define ATDDIEN_IEN6_MASK               64U
#define ATDDIEN_IEN7_MASK               128U


/*** PORTAD0 - Port AD0 Register; 0x0000008F ***/
typedef union {
  byte Byte;
  struct {
    byte PTAD0       :1;                                       /* A/D Channel 0 (AN0) Digital Input */
    byte PTAD1       :1;                                       /* A/D Channel 1 (AN1) Digital Input */
    byte PTAD2       :1;                                       /* A/D Channel 2 (AN2) Digital Input */
    byte PTAD3       :1;                                       /* A/D Channel 3 (AN3) Digital Input */
    byte PTAD4       :1;                                       /* A/D Channel 4 (AN4) Digital Input */
    byte PTAD5       :1;                                       /* A/D Channel 5 (AN5) Digital Input */
    byte PTAD6       :1;                                       /* A/D Channel 6 (AN6) Digital Input */
    byte PTAD7       :1;                                       /* A/D Channel 7 (AN7) Digital Input */
  } Bits;
} PORTAD0STR;
extern volatile PORTAD0STR _PORTAD0 @(REG_BASE + 0x0000008FUL);
#define PORTAD0                         _PORTAD0.Byte
#define PORTAD0_PTAD0                   _PORTAD0.Bits.PTAD0
#define PORTAD0_PTAD1                   _PORTAD0.Bits.PTAD1
#define PORTAD0_PTAD2                   _PORTAD0.Bits.PTAD2
#define PORTAD0_PTAD3                   _PORTAD0.Bits.PTAD3
#define PORTAD0_PTAD4                   _PORTAD0.Bits.PTAD4
#define PORTAD0_PTAD5                   _PORTAD0.Bits.PTAD5
#define PORTAD0_PTAD6                   _PORTAD0.Bits.PTAD6
#define PORTAD0_PTAD7                   _PORTAD0.Bits.PTAD7

#define PORTAD0_PTAD0_MASK              1U
#define PORTAD0_PTAD1_MASK              2U
#define PORTAD0_PTAD2_MASK              4U
#define PORTAD0_PTAD3_MASK              8U
#define PORTAD0_PTAD4_MASK              16U
#define PORTAD0_PTAD5_MASK              32U
#define PORTAD0_PTAD6_MASK              64U
#define PORTAD0_PTAD7_MASK              128U


/*** ATDDR0 - ATD Conversion Result Register 0; 0x00000090 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR0H - ATD Conversion Result Register 0 High; 0x00000090 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR0HSTR;
    #define ATDDR0H                     _ATDDR0.Overlap_STR.ATDDR0HSTR.Byte
    #define ATDDR0H_BIT8                _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT8
    #define ATDDR0H_BIT9                _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT9
    #define ATDDR0H_BIT10               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT10
    #define ATDDR0H_BIT11               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT11
    #define ATDDR0H_BIT12               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT12
    #define ATDDR0H_BIT13               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT13
    #define ATDDR0H_BIT14               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT14
    #define ATDDR0H_BIT15               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT15
    
    #define ATDDR0H_BIT8_MASK           1U
    #define ATDDR0H_BIT9_MASK           2U
    #define ATDDR0H_BIT10_MASK          4U
    #define ATDDR0H_BIT11_MASK          8U
    #define ATDDR0H_BIT12_MASK          16U
    #define ATDDR0H_BIT13_MASK          32U
    #define ATDDR0H_BIT14_MASK          64U
    #define ATDDR0H_BIT15_MASK          128U
    

    /*** ATDDR0L - ATD Conversion Result Register 0 Low; 0x00000091 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATDDR0LSTR;
    #define ATDDR0L                     _ATDDR0.Overlap_STR.ATDDR0LSTR.Byte
    #define ATDDR0L_BIT6                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT6
    #define ATDDR0L_BIT7                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT7
    #define ATDDR0L_BIT_6               _ATDDR0.Overlap_STR.ATDDR0LSTR.MergedBits.grpBIT_6
    #define ATDDR0L_BIT                 ATDDR0L_BIT_6
    
    #define ATDDR0L_BIT6_MASK           64U
    #define ATDDR0L_BIT7_MASK           128U
    #define ATDDR0L_BIT_6_MASK          192U
    #define ATDDR0L_BIT_6_BITNUM        6U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATDDR0STR;
extern volatile ATDDR0STR _ATDDR0 @(REG_BASE + 0x00000090UL);
#define ATDDR0                          _ATDDR0.Word
#define ATDDR0_BIT6                     _ATDDR0.Bits.BIT6
#define ATDDR0_BIT7                     _ATDDR0.Bits.BIT7
#define ATDDR0_BIT8                     _ATDDR0.Bits.BIT8
#define ATDDR0_BIT9                     _ATDDR0.Bits.BIT9
#define ATDDR0_BIT10                    _ATDDR0.Bits.BIT10
#define ATDDR0_BIT11                    _ATDDR0.Bits.BIT11
#define ATDDR0_BIT12                    _ATDDR0.Bits.BIT12
#define ATDDR0_BIT13                    _ATDDR0.Bits.BIT13
#define ATDDR0_BIT14                    _ATDDR0.Bits.BIT14
#define ATDDR0_BIT15                    _ATDDR0.Bits.BIT15
/* ATDDR_ARR: Access 8 ATDDRx registers in an array */
#define ATDDR_ARR                       ((volatile word *) &ATDDR0)
#define ATDDR0_BIT_6                    _ATDDR0.MergedBits.grpBIT_6
#define ATDDR0_BIT                      ATDDR0_BIT_6

#define ATDDR0_BIT6_MASK                64U
#define ATDDR0_BIT7_MASK                128U
#define ATDDR0_BIT8_MASK                256U
#define ATDDR0_BIT9_MASK                512U
#define ATDDR0_BIT10_MASK               1024U
#define ATDDR0_BIT11_MASK               2048U
#define ATDDR0_BIT12_MASK               4096U
#define ATDDR0_BIT13_MASK               8192U
#define ATDDR0_BIT14_MASK               16384U
#define ATDDR0_BIT15_MASK               32768U
#define ATDDR0_BIT_6_MASK               65472U
#define ATDDR0_BIT_6_BITNUM             6U


/*** ATDDR1 - ATD Conversion Result Register 1; 0x00000092 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR1H - ATD Conversion Result Register 1 High; 0x00000092 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR1HSTR;
    #define ATDDR1H                     _ATDDR1.Overlap_STR.ATDDR1HSTR.Byte
    #define ATDDR1H_BIT8                _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT8
    #define ATDDR1H_BIT9                _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT9
    #define ATDDR1H_BIT10               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT10
    #define ATDDR1H_BIT11               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT11
    #define ATDDR1H_BIT12               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT12
    #define ATDDR1H_BIT13               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT13
    #define ATDDR1H_BIT14               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT14
    #define ATDDR1H_BIT15               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT15
    
    #define ATDDR1H_BIT8_MASK           1U
    #define ATDDR1H_BIT9_MASK           2U
    #define ATDDR1H_BIT10_MASK          4U
    #define ATDDR1H_BIT11_MASK          8U
    #define ATDDR1H_BIT12_MASK          16U
    #define ATDDR1H_BIT13_MASK          32U
    #define ATDDR1H_BIT14_MASK          64U
    #define ATDDR1H_BIT15_MASK          128U
    

    /*** ATDDR1L - ATD Conversion Result Register 1 Low; 0x00000093 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATDDR1LSTR;
    #define ATDDR1L                     _ATDDR1.Overlap_STR.ATDDR1LSTR.Byte
    #define ATDDR1L_BIT6                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT6
    #define ATDDR1L_BIT7                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT7
    #define ATDDR1L_BIT_6               _ATDDR1.Overlap_STR.ATDDR1LSTR.MergedBits.grpBIT_6
    #define ATDDR1L_BIT                 ATDDR1L_BIT_6
    
    #define ATDDR1L_BIT6_MASK           64U
    #define ATDDR1L_BIT7_MASK           128U
    #define ATDDR1L_BIT_6_MASK          192U
    #define ATDDR1L_BIT_6_BITNUM        6U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATDDR1STR;
extern volatile ATDDR1STR _ATDDR1 @(REG_BASE + 0x00000092UL);
#define ATDDR1                          _ATDDR1.Word
#define ATDDR1_BIT6                     _ATDDR1.Bits.BIT6
#define ATDDR1_BIT7                     _ATDDR1.Bits.BIT7
#define ATDDR1_BIT8                     _ATDDR1.Bits.BIT8
#define ATDDR1_BIT9                     _ATDDR1.Bits.BIT9
#define ATDDR1_BIT10                    _ATDDR1.Bits.BIT10
#define ATDDR1_BIT11                    _ATDDR1.Bits.BIT11
#define ATDDR1_BIT12                    _ATDDR1.Bits.BIT12
#define ATDDR1_BIT13                    _ATDDR1.Bits.BIT13
#define ATDDR1_BIT14                    _ATDDR1.Bits.BIT14
#define ATDDR1_BIT15                    _ATDDR1.Bits.BIT15
#define ATDDR1_BIT_6                    _ATDDR1.MergedBits.grpBIT_6
#define ATDDR1_BIT                      ATDDR1_BIT_6

#define ATDDR1_BIT6_MASK                64U
#define ATDDR1_BIT7_MASK                128U
#define ATDDR1_BIT8_MASK                256U
#define ATDDR1_BIT9_MASK                512U
#define ATDDR1_BIT10_MASK               1024U
#define ATDDR1_BIT11_MASK               2048U
#define ATDDR1_BIT12_MASK               4096U
#define ATDDR1_BIT13_MASK               8192U
#define ATDDR1_BIT14_MASK               16384U
#define ATDDR1_BIT15_MASK               32768U
#define ATDDR1_BIT_6_MASK               65472U
#define ATDDR1_BIT_6_BITNUM             6U


/*** ATDDR2 - ATD Conversion Result Register 2; 0x00000094 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR2H - ATD Conversion Result Register 2 High; 0x00000094 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR2HSTR;
    #define ATDDR2H                     _ATDDR2.Overlap_STR.ATDDR2HSTR.Byte
    #define ATDDR2H_BIT8                _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT8
    #define ATDDR2H_BIT9                _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT9
    #define ATDDR2H_BIT10               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT10
    #define ATDDR2H_BIT11               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT11
    #define ATDDR2H_BIT12               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT12
    #define ATDDR2H_BIT13               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT13
    #define ATDDR2H_BIT14               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT14
    #define ATDDR2H_BIT15               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT15
    
    #define ATDDR2H_BIT8_MASK           1U
    #define ATDDR2H_BIT9_MASK           2U
    #define ATDDR2H_BIT10_MASK          4U
    #define ATDDR2H_BIT11_MASK          8U
    #define ATDDR2H_BIT12_MASK          16U
    #define ATDDR2H_BIT13_MASK          32U
    #define ATDDR2H_BIT14_MASK          64U
    #define ATDDR2H_BIT15_MASK          128U
    

    /*** ATDDR2L - ATD Conversion Result Register 2 Low; 0x00000095 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATDDR2LSTR;
    #define ATDDR2L                     _ATDDR2.Overlap_STR.ATDDR2LSTR.Byte
    #define ATDDR2L_BIT6                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT6
    #define ATDDR2L_BIT7                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT7
    #define ATDDR2L_BIT_6               _ATDDR2.Overlap_STR.ATDDR2LSTR.MergedBits.grpBIT_6
    #define ATDDR2L_BIT                 ATDDR2L_BIT_6
    
    #define ATDDR2L_BIT6_MASK           64U
    #define ATDDR2L_BIT7_MASK           128U
    #define ATDDR2L_BIT_6_MASK          192U
    #define ATDDR2L_BIT_6_BITNUM        6U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATDDR2STR;
extern volatile ATDDR2STR _ATDDR2 @(REG_BASE + 0x00000094UL);
#define ATDDR2                          _ATDDR2.Word
#define ATDDR2_BIT6                     _ATDDR2.Bits.BIT6
#define ATDDR2_BIT7                     _ATDDR2.Bits.BIT7
#define ATDDR2_BIT8                     _ATDDR2.Bits.BIT8
#define ATDDR2_BIT9                     _ATDDR2.Bits.BIT9
#define ATDDR2_BIT10                    _ATDDR2.Bits.BIT10
#define ATDDR2_BIT11                    _ATDDR2.Bits.BIT11
#define ATDDR2_BIT12                    _ATDDR2.Bits.BIT12
#define ATDDR2_BIT13                    _ATDDR2.Bits.BIT13
#define ATDDR2_BIT14                    _ATDDR2.Bits.BIT14
#define ATDDR2_BIT15                    _ATDDR2.Bits.BIT15
#define ATDDR2_BIT_6                    _ATDDR2.MergedBits.grpBIT_6
#define ATDDR2_BIT                      ATDDR2_BIT_6

#define ATDDR2_BIT6_MASK                64U
#define ATDDR2_BIT7_MASK                128U
#define ATDDR2_BIT8_MASK                256U
#define ATDDR2_BIT9_MASK                512U
#define ATDDR2_BIT10_MASK               1024U
#define ATDDR2_BIT11_MASK               2048U
#define ATDDR2_BIT12_MASK               4096U
#define ATDDR2_BIT13_MASK               8192U
#define ATDDR2_BIT14_MASK               16384U
#define ATDDR2_BIT15_MASK               32768U
#define ATDDR2_BIT_6_MASK               65472U
#define ATDDR2_BIT_6_BITNUM             6U


/*** ATDDR3 - ATD Conversion Result Register 3; 0x00000096 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR3H - ATD Conversion Result Register 3 High; 0x00000096 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR3HSTR;
    #define ATDDR3H                     _ATDDR3.Overlap_STR.ATDDR3HSTR.Byte
    #define ATDDR3H_BIT8                _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT8
    #define ATDDR3H_BIT9                _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT9
    #define ATDDR3H_BIT10               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT10
    #define ATDDR3H_BIT11               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT11
    #define ATDDR3H_BIT12               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT12
    #define ATDDR3H_BIT13               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT13
    #define ATDDR3H_BIT14               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT14
    #define ATDDR3H_BIT15               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT15
    
    #define ATDDR3H_BIT8_MASK           1U
    #define ATDDR3H_BIT9_MASK           2U
    #define ATDDR3H_BIT10_MASK          4U
    #define ATDDR3H_BIT11_MASK          8U
    #define ATDDR3H_BIT12_MASK          16U
    #define ATDDR3H_BIT13_MASK          32U
    #define ATDDR3H_BIT14_MASK          64U
    #define ATDDR3H_BIT15_MASK          128U
    

    /*** ATDDR3L - ATD Conversion Result Register 3 Low; 0x00000097 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATDDR3LSTR;
    #define ATDDR3L                     _ATDDR3.Overlap_STR.ATDDR3LSTR.Byte
    #define ATDDR3L_BIT6                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT6
    #define ATDDR3L_BIT7                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT7
    #define ATDDR3L_BIT_6               _ATDDR3.Overlap_STR.ATDDR3LSTR.MergedBits.grpBIT_6
    #define ATDDR3L_BIT                 ATDDR3L_BIT_6
    
    #define ATDDR3L_BIT6_MASK           64U
    #define ATDDR3L_BIT7_MASK           128U
    #define ATDDR3L_BIT_6_MASK          192U
    #define ATDDR3L_BIT_6_BITNUM        6U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATDDR3STR;
extern volatile ATDDR3STR _ATDDR3 @(REG_BASE + 0x00000096UL);
#define ATDDR3                          _ATDDR3.Word
#define ATDDR3_BIT6                     _ATDDR3.Bits.BIT6
#define ATDDR3_BIT7                     _ATDDR3.Bits.BIT7
#define ATDDR3_BIT8                     _ATDDR3.Bits.BIT8
#define ATDDR3_BIT9                     _ATDDR3.Bits.BIT9
#define ATDDR3_BIT10                    _ATDDR3.Bits.BIT10
#define ATDDR3_BIT11                    _ATDDR3.Bits.BIT11
#define ATDDR3_BIT12                    _ATDDR3.Bits.BIT12
#define ATDDR3_BIT13                    _ATDDR3.Bits.BIT13
#define ATDDR3_BIT14                    _ATDDR3.Bits.BIT14
#define ATDDR3_BIT15                    _ATDDR3.Bits.BIT15
#define ATDDR3_BIT_6                    _ATDDR3.MergedBits.grpBIT_6
#define ATDDR3_BIT                      ATDDR3_BIT_6

#define ATDDR3_BIT6_MASK                64U
#define ATDDR3_BIT7_MASK                128U
#define ATDDR3_BIT8_MASK                256U
#define ATDDR3_BIT9_MASK                512U
#define ATDDR3_BIT10_MASK               1024U
#define ATDDR3_BIT11_MASK               2048U
#define ATDDR3_BIT12_MASK               4096U
#define ATDDR3_BIT13_MASK               8192U
#define ATDDR3_BIT14_MASK               16384U
#define ATDDR3_BIT15_MASK               32768U
#define ATDDR3_BIT_6_MASK               65472U
#define ATDDR3_BIT_6_BITNUM             6U


/*** ATDDR4 - ATD Conversion Result Register 4; 0x00000098 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR4H - ATD Conversion Result Register 4 High; 0x00000098 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR4HSTR;
    #define ATDDR4H                     _ATDDR4.Overlap_STR.ATDDR4HSTR.Byte
    #define ATDDR4H_BIT8                _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT8
    #define ATDDR4H_BIT9                _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT9
    #define ATDDR4H_BIT10               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT10
    #define ATDDR4H_BIT11               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT11
    #define ATDDR4H_BIT12               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT12
    #define ATDDR4H_BIT13               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT13
    #define ATDDR4H_BIT14               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT14
    #define ATDDR4H_BIT15               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT15
    
    #define ATDDR4H_BIT8_MASK           1U
    #define ATDDR4H_BIT9_MASK           2U
    #define ATDDR4H_BIT10_MASK          4U
    #define ATDDR4H_BIT11_MASK          8U
    #define ATDDR4H_BIT12_MASK          16U
    #define ATDDR4H_BIT13_MASK          32U
    #define ATDDR4H_BIT14_MASK          64U
    #define ATDDR4H_BIT15_MASK          128U
    

    /*** ATDDR4L - ATD Conversion Result Register 4 Low; 0x00000099 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATDDR4LSTR;
    #define ATDDR4L                     _ATDDR4.Overlap_STR.ATDDR4LSTR.Byte
    #define ATDDR4L_BIT6                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT6
    #define ATDDR4L_BIT7                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT7
    #define ATDDR4L_BIT_6               _ATDDR4.Overlap_STR.ATDDR4LSTR.MergedBits.grpBIT_6
    #define ATDDR4L_BIT                 ATDDR4L_BIT_6
    
    #define ATDDR4L_BIT6_MASK           64U
    #define ATDDR4L_BIT7_MASK           128U
    #define ATDDR4L_BIT_6_MASK          192U
    #define ATDDR4L_BIT_6_BITNUM        6U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATDDR4STR;
extern volatile ATDDR4STR _ATDDR4 @(REG_BASE + 0x00000098UL);
#define ATDDR4                          _ATDDR4.Word
#define ATDDR4_BIT6                     _ATDDR4.Bits.BIT6
#define ATDDR4_BIT7                     _ATDDR4.Bits.BIT7
#define ATDDR4_BIT8                     _ATDDR4.Bits.BIT8
#define ATDDR4_BIT9                     _ATDDR4.Bits.BIT9
#define ATDDR4_BIT10                    _ATDDR4.Bits.BIT10
#define ATDDR4_BIT11                    _ATDDR4.Bits.BIT11
#define ATDDR4_BIT12                    _ATDDR4.Bits.BIT12
#define ATDDR4_BIT13                    _ATDDR4.Bits.BIT13
#define ATDDR4_BIT14                    _ATDDR4.Bits.BIT14
#define ATDDR4_BIT15                    _ATDDR4.Bits.BIT15
#define ATDDR4_BIT_6                    _ATDDR4.MergedBits.grpBIT_6
#define ATDDR4_BIT                      ATDDR4_BIT_6

#define ATDDR4_BIT6_MASK                64U
#define ATDDR4_BIT7_MASK                128U
#define ATDDR4_BIT8_MASK                256U
#define ATDDR4_BIT9_MASK                512U
#define ATDDR4_BIT10_MASK               1024U
#define ATDDR4_BIT11_MASK               2048U
#define ATDDR4_BIT12_MASK               4096U
#define ATDDR4_BIT13_MASK               8192U
#define ATDDR4_BIT14_MASK               16384U
#define ATDDR4_BIT15_MASK               32768U
#define ATDDR4_BIT_6_MASK               65472U
#define ATDDR4_BIT_6_BITNUM             6U


/*** ATDDR5 - ATD Conversion Result Register 5; 0x0000009A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR5H - ATD Conversion Result Register 5 High; 0x0000009A ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR5HSTR;
    #define ATDDR5H                     _ATDDR5.Overlap_STR.ATDDR5HSTR.Byte
    #define ATDDR5H_BIT8                _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT8
    #define ATDDR5H_BIT9                _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT9
    #define ATDDR5H_BIT10               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT10
    #define ATDDR5H_BIT11               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT11
    #define ATDDR5H_BIT12               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT12
    #define ATDDR5H_BIT13               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT13
    #define ATDDR5H_BIT14               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT14
    #define ATDDR5H_BIT15               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT15
    
    #define ATDDR5H_BIT8_MASK           1U
    #define ATDDR5H_BIT9_MASK           2U
    #define ATDDR5H_BIT10_MASK          4U
    #define ATDDR5H_BIT11_MASK          8U
    #define ATDDR5H_BIT12_MASK          16U
    #define ATDDR5H_BIT13_MASK          32U
    #define ATDDR5H_BIT14_MASK          64U
    #define ATDDR5H_BIT15_MASK          128U
    

    /*** ATDDR5L - ATD Conversion Result Register 5 Low; 0x0000009B ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATDDR5LSTR;
    #define ATDDR5L                     _ATDDR5.Overlap_STR.ATDDR5LSTR.Byte
    #define ATDDR5L_BIT6                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT6
    #define ATDDR5L_BIT7                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT7
    #define ATDDR5L_BIT_6               _ATDDR5.Overlap_STR.ATDDR5LSTR.MergedBits.grpBIT_6
    #define ATDDR5L_BIT                 ATDDR5L_BIT_6
    
    #define ATDDR5L_BIT6_MASK           64U
    #define ATDDR5L_BIT7_MASK           128U
    #define ATDDR5L_BIT_6_MASK          192U
    #define ATDDR5L_BIT_6_BITNUM        6U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATDDR5STR;
extern volatile ATDDR5STR _ATDDR5 @(REG_BASE + 0x0000009AUL);
#define ATDDR5                          _ATDDR5.Word
#define ATDDR5_BIT6                     _ATDDR5.Bits.BIT6
#define ATDDR5_BIT7                     _ATDDR5.Bits.BIT7
#define ATDDR5_BIT8                     _ATDDR5.Bits.BIT8
#define ATDDR5_BIT9                     _ATDDR5.Bits.BIT9
#define ATDDR5_BIT10                    _ATDDR5.Bits.BIT10
#define ATDDR5_BIT11                    _ATDDR5.Bits.BIT11
#define ATDDR5_BIT12                    _ATDDR5.Bits.BIT12
#define ATDDR5_BIT13                    _ATDDR5.Bits.BIT13
#define ATDDR5_BIT14                    _ATDDR5.Bits.BIT14
#define ATDDR5_BIT15                    _ATDDR5.Bits.BIT15
#define ATDDR5_BIT_6                    _ATDDR5.MergedBits.grpBIT_6
#define ATDDR5_BIT                      ATDDR5_BIT_6

#define ATDDR5_BIT6_MASK                64U
#define ATDDR5_BIT7_MASK                128U
#define ATDDR5_BIT8_MASK                256U
#define ATDDR5_BIT9_MASK                512U
#define ATDDR5_BIT10_MASK               1024U
#define ATDDR5_BIT11_MASK               2048U
#define ATDDR5_BIT12_MASK               4096U
#define ATDDR5_BIT13_MASK               8192U
#define ATDDR5_BIT14_MASK               16384U
#define ATDDR5_BIT15_MASK               32768U
#define ATDDR5_BIT_6_MASK               65472U
#define ATDDR5_BIT_6_BITNUM             6U


/*** ATDDR6 - ATD Conversion Result Register 6; 0x0000009C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR6H - ATD Conversion Result Register 6 High; 0x0000009C ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR6HSTR;
    #define ATDDR6H                     _ATDDR6.Overlap_STR.ATDDR6HSTR.Byte
    #define ATDDR6H_BIT8                _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT8
    #define ATDDR6H_BIT9                _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT9
    #define ATDDR6H_BIT10               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT10
    #define ATDDR6H_BIT11               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT11
    #define ATDDR6H_BIT12               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT12
    #define ATDDR6H_BIT13               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT13
    #define ATDDR6H_BIT14               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT14
    #define ATDDR6H_BIT15               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT15
    
    #define ATDDR6H_BIT8_MASK           1U
    #define ATDDR6H_BIT9_MASK           2U
    #define ATDDR6H_BIT10_MASK          4U
    #define ATDDR6H_BIT11_MASK          8U
    #define ATDDR6H_BIT12_MASK          16U
    #define ATDDR6H_BIT13_MASK          32U
    #define ATDDR6H_BIT14_MASK          64U
    #define ATDDR6H_BIT15_MASK          128U
    

    /*** ATDDR6L - ATD Conversion Result Register 6 Low; 0x0000009D ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATDDR6LSTR;
    #define ATDDR6L                     _ATDDR6.Overlap_STR.ATDDR6LSTR.Byte
    #define ATDDR6L_BIT6                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT6
    #define ATDDR6L_BIT7                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT7
    #define ATDDR6L_BIT_6               _ATDDR6.Overlap_STR.ATDDR6LSTR.MergedBits.grpBIT_6
    #define ATDDR6L_BIT                 ATDDR6L_BIT_6
    
    #define ATDDR6L_BIT6_MASK           64U
    #define ATDDR6L_BIT7_MASK           128U
    #define ATDDR6L_BIT_6_MASK          192U
    #define ATDDR6L_BIT_6_BITNUM        6U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATDDR6STR;
extern volatile ATDDR6STR _ATDDR6 @(REG_BASE + 0x0000009CUL);
#define ATDDR6                          _ATDDR6.Word
#define ATDDR6_BIT6                     _ATDDR6.Bits.BIT6
#define ATDDR6_BIT7                     _ATDDR6.Bits.BIT7
#define ATDDR6_BIT8                     _ATDDR6.Bits.BIT8
#define ATDDR6_BIT9                     _ATDDR6.Bits.BIT9
#define ATDDR6_BIT10                    _ATDDR6.Bits.BIT10
#define ATDDR6_BIT11                    _ATDDR6.Bits.BIT11
#define ATDDR6_BIT12                    _ATDDR6.Bits.BIT12
#define ATDDR6_BIT13                    _ATDDR6.Bits.BIT13
#define ATDDR6_BIT14                    _ATDDR6.Bits.BIT14
#define ATDDR6_BIT15                    _ATDDR6.Bits.BIT15
#define ATDDR6_BIT_6                    _ATDDR6.MergedBits.grpBIT_6
#define ATDDR6_BIT                      ATDDR6_BIT_6

#define ATDDR6_BIT6_MASK                64U
#define ATDDR6_BIT7_MASK                128U
#define ATDDR6_BIT8_MASK                256U
#define ATDDR6_BIT9_MASK                512U
#define ATDDR6_BIT10_MASK               1024U
#define ATDDR6_BIT11_MASK               2048U
#define ATDDR6_BIT12_MASK               4096U
#define ATDDR6_BIT13_MASK               8192U
#define ATDDR6_BIT14_MASK               16384U
#define ATDDR6_BIT15_MASK               32768U
#define ATDDR6_BIT_6_MASK               65472U
#define ATDDR6_BIT_6_BITNUM             6U


/*** ATDDR7 - ATD Conversion Result Register 7; 0x0000009E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR7H - ATD Conversion Result Register 7 High; 0x0000009E ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR7HSTR;
    #define ATDDR7H                     _ATDDR7.Overlap_STR.ATDDR7HSTR.Byte
    #define ATDDR7H_BIT8                _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT8
    #define ATDDR7H_BIT9                _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT9
    #define ATDDR7H_BIT10               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT10
    #define ATDDR7H_BIT11               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT11
    #define ATDDR7H_BIT12               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT12
    #define ATDDR7H_BIT13               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT13
    #define ATDDR7H_BIT14               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT14
    #define ATDDR7H_BIT15               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT15
    
    #define ATDDR7H_BIT8_MASK           1U
    #define ATDDR7H_BIT9_MASK           2U
    #define ATDDR7H_BIT10_MASK          4U
    #define ATDDR7H_BIT11_MASK          8U
    #define ATDDR7H_BIT12_MASK          16U
    #define ATDDR7H_BIT13_MASK          32U
    #define ATDDR7H_BIT14_MASK          64U
    #define ATDDR7H_BIT15_MASK          128U
    

    /*** ATDDR7L - ATD Conversion Result Register 7 Low; 0x0000009F ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATDDR7LSTR;
    #define ATDDR7L                     _ATDDR7.Overlap_STR.ATDDR7LSTR.Byte
    #define ATDDR7L_BIT6                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT6
    #define ATDDR7L_BIT7                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT7
    #define ATDDR7L_BIT_6               _ATDDR7.Overlap_STR.ATDDR7LSTR.MergedBits.grpBIT_6
    #define ATDDR7L_BIT                 ATDDR7L_BIT_6
    
    #define ATDDR7L_BIT6_MASK           64U
    #define ATDDR7L_BIT7_MASK           128U
    #define ATDDR7L_BIT_6_MASK          192U
    #define ATDDR7L_BIT_6_BITNUM        6U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATDDR7STR;
extern volatile ATDDR7STR _ATDDR7 @(REG_BASE + 0x0000009EUL);
#define ATDDR7                          _ATDDR7.Word
#define ATDDR7_BIT6                     _ATDDR7.Bits.BIT6
#define ATDDR7_BIT7                     _ATDDR7.Bits.BIT7
#define ATDDR7_BIT8                     _ATDDR7.Bits.BIT8
#define ATDDR7_BIT9                     _ATDDR7.Bits.BIT9
#define ATDDR7_BIT10                    _ATDDR7.Bits.BIT10
#define ATDDR7_BIT11                    _ATDDR7.Bits.BIT11
#define ATDDR7_BIT12                    _ATDDR7.Bits.BIT12
#define ATDDR7_BIT13                    _ATDDR7.Bits.BIT13
#define ATDDR7_BIT14                    _ATDDR7.Bits.BIT14
#define ATDDR7_BIT15                    _ATDDR7.Bits.BIT15
#define ATDDR7_BIT_6                    _ATDDR7.MergedBits.grpBIT_6
#define ATDDR7_BIT                      ATDDR7_BIT_6

#define ATDDR7_BIT6_MASK                64U
#define ATDDR7_BIT7_MASK                128U
#define ATDDR7_BIT8_MASK                256U
#define ATDDR7_BIT9_MASK                512U
#define ATDDR7_BIT10_MASK               1024U
#define ATDDR7_BIT11_MASK               2048U
#define ATDDR7_BIT12_MASK               4096U
#define ATDDR7_BIT13_MASK               8192U
#define ATDDR7_BIT14_MASK               16384U
#define ATDDR7_BIT15_MASK               32768U
#define ATDDR7_BIT_6_MASK               65472U
#define ATDDR7_BIT_6_BITNUM             6U


/*** SCIBD - SCI Baud Rate Register; 0x000000C8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCIBDH - SCI Baud Rate Register High; 0x000000C8 ***/
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       /* SCI Baud Rate Bit 8 */
        byte SBR9        :1;                                       /* SCI Baud Rate Bit 9 */
        byte SBR10       :1;                                       /* SCI Baud Rate Bit 10 */
        byte SBR11       :1;                                       /* SCI Baud Rate Bit 11 */
        byte SBR12       :1;                                       /* SCI Baud Rate Bit 12 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCIBDHSTR;
    #define SCIBDH                      _SCIBD.Overlap_STR.SCIBDHSTR.Byte
    #define SCIBDH_SBR8                 _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR8
    #define SCIBDH_SBR9                 _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR9
    #define SCIBDH_SBR10                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR10
    #define SCIBDH_SBR11                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR11
    #define SCIBDH_SBR12                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR12
    #define SCIBDH_SBR_8                _SCIBD.Overlap_STR.SCIBDHSTR.MergedBits.grpSBR_8
    #define SCIBDH_SBR                  SCIBDH_SBR_8
    
    #define SCIBDH_SBR8_MASK            1U
    #define SCIBDH_SBR9_MASK            2U
    #define SCIBDH_SBR10_MASK           4U
    #define SCIBDH_SBR11_MASK           8U
    #define SCIBDH_SBR12_MASK           16U
    #define SCIBDH_SBR_8_MASK           31U
    #define SCIBDH_SBR_8_BITNUM         0U
    

    /*** SCIBDL - SCI Baud Rate Register Low; 0x000000C9 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* SCI Baud Rate Bit 0 */
        byte SBR1        :1;                                       /* SCI Baud Rate Bit 1 */
        byte SBR2        :1;                                       /* SCI Baud Rate Bit 2 */
        byte SBR3        :1;                                       /* SCI Baud Rate Bit 3 */
        byte SBR4        :1;                                       /* SCI Baud Rate Bit 4 */
        byte SBR5        :1;                                       /* SCI Baud Rate Bit 5 */
        byte SBR6        :1;                                       /* SCI Baud Rate Bit 6 */
        byte SBR7        :1;                                       /* SCI Baud Rate Bit 7 */
      } Bits;
    } SCIBDLSTR;
    #define SCIBDL                      _SCIBD.Overlap_STR.SCIBDLSTR.Byte
    #define SCIBDL_SBR0                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR0
    #define SCIBDL_SBR1                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR1
    #define SCIBDL_SBR2                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR2
    #define SCIBDL_SBR3                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR3
    #define SCIBDL_SBR4                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR4
    #define SCIBDL_SBR5                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR5
    #define SCIBDL_SBR6                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR6
    #define SCIBDL_SBR7                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR7
    
    #define SCIBDL_SBR0_MASK            1U
    #define SCIBDL_SBR1_MASK            2U
    #define SCIBDL_SBR2_MASK            4U
    #define SCIBDL_SBR3_MASK            8U
    #define SCIBDL_SBR4_MASK            16U
    #define SCIBDL_SBR5_MASK            32U
    #define SCIBDL_SBR6_MASK            64U
    #define SCIBDL_SBR7_MASK            128U
    
  } Overlap_STR;

  struct {
    word SBR0        :1;                                       /* SCI Baud Rate Bit 0 */
    word SBR1        :1;                                       /* SCI Baud Rate Bit 1 */
    word SBR2        :1;                                       /* SCI Baud Rate Bit 2 */
    word SBR3        :1;                                       /* SCI Baud Rate Bit 3 */
    word SBR4        :1;                                       /* SCI Baud Rate Bit 4 */
    word SBR5        :1;                                       /* SCI Baud Rate Bit 5 */
    word SBR6        :1;                                       /* SCI Baud Rate Bit 6 */
    word SBR7        :1;                                       /* SCI Baud Rate Bit 7 */
    word SBR8        :1;                                       /* SCI Baud Rate Bit 8 */
    word SBR9        :1;                                       /* SCI Baud Rate Bit 9 */
    word SBR10       :1;                                       /* SCI Baud Rate Bit 10 */
    word SBR11       :1;                                       /* SCI Baud Rate Bit 11 */
    word SBR12       :1;                                       /* SCI Baud Rate Bit 12 */
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpSBR  :13;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} SCIBDSTR;
extern volatile SCIBDSTR _SCIBD @(REG_BASE + 0x000000C8UL);
#define SCIBD                           _SCIBD.Word
#define SCIBD_SBR0                      _SCIBD.Bits.SBR0
#define SCIBD_SBR1                      _SCIBD.Bits.SBR1
#define SCIBD_SBR2                      _SCIBD.Bits.SBR2
#define SCIBD_SBR3                      _SCIBD.Bits.SBR3
#define SCIBD_SBR4                      _SCIBD.Bits.SBR4
#define SCIBD_SBR5                      _SCIBD.Bits.SBR5
#define SCIBD_SBR6                      _SCIBD.Bits.SBR6
#define SCIBD_SBR7                      _SCIBD.Bits.SBR7
#define SCIBD_SBR8                      _SCIBD.Bits.SBR8
#define SCIBD_SBR9                      _SCIBD.Bits.SBR9
#define SCIBD_SBR10                     _SCIBD.Bits.SBR10
#define SCIBD_SBR11                     _SCIBD.Bits.SBR11
#define SCIBD_SBR12                     _SCIBD.Bits.SBR12
#define SCIBD_SBR                       _SCIBD.MergedBits.grpSBR

#define SCIBD_SBR0_MASK                 1U
#define SCIBD_SBR1_MASK                 2U
#define SCIBD_SBR2_MASK                 4U
#define SCIBD_SBR3_MASK                 8U
#define SCIBD_SBR4_MASK                 16U
#define SCIBD_SBR5_MASK                 32U
#define SCIBD_SBR6_MASK                 64U
#define SCIBD_SBR7_MASK                 128U
#define SCIBD_SBR8_MASK                 256U
#define SCIBD_SBR9_MASK                 512U
#define SCIBD_SBR10_MASK                1024U
#define SCIBD_SBR11_MASK                2048U
#define SCIBD_SBR12_MASK                4096U
#define SCIBD_SBR_MASK                  8191U
#define SCIBD_SBR_BITNUM                0U


/*** SCICR1 - SCI Control Register 1; 0x000000CA ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type Bit */
    byte PE          :1;                                       /* Parity Enable Bit */
    byte ILT         :1;                                       /* Idle Line Type Bit */
    byte WAKE        :1;                                       /* Wakeup Condition Bit */
    byte M           :1;                                       /* Data Format Mode Bit */
    byte RSRC        :1;                                       /* Receiver Source Bit */
    byte SCISWAI     :1;                                       /* SCI Stop in Wait Mode Bit */
    byte LOOPS       :1;                                       /* Loop Select Bit */
  } Bits;
} SCICR1STR;
extern volatile SCICR1STR _SCICR1 @(REG_BASE + 0x000000CAUL);
#define SCICR1                          _SCICR1.Byte
#define SCICR1_PT                       _SCICR1.Bits.PT
#define SCICR1_PE                       _SCICR1.Bits.PE
#define SCICR1_ILT                      _SCICR1.Bits.ILT
#define SCICR1_WAKE                     _SCICR1.Bits.WAKE
#define SCICR1_M                        _SCICR1.Bits.M
#define SCICR1_RSRC                     _SCICR1.Bits.RSRC
#define SCICR1_SCISWAI                  _SCICR1.Bits.SCISWAI
#define SCICR1_LOOPS                    _SCICR1.Bits.LOOPS

#define SCICR1_PT_MASK                  1U
#define SCICR1_PE_MASK                  2U
#define SCICR1_ILT_MASK                 4U
#define SCICR1_WAKE_MASK                8U
#define SCICR1_M_MASK                   16U
#define SCICR1_RSRC_MASK                32U
#define SCICR1_SCISWAI_MASK             64U
#define SCICR1_LOOPS_MASK               128U


/*** SCICR2 - SCI Control Register 2; 0x000000CB ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break Bit */
    byte RWU         :1;                                       /* Receiver Wakeup Bit */
    byte RE          :1;                                       /* Receiver Enable Bit */
    byte TE          :1;                                       /* Transmitter Enable Bit */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable Bit */
    byte RIE         :1;                                       /* Receiver Full Interrupt Enable Bit */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable Bit */
    byte SCTIE       :1;                                       /* Transmitter Interrupt Enable Bit */
  } Bits;
} SCICR2STR;
extern volatile SCICR2STR _SCICR2 @(REG_BASE + 0x000000CBUL);
#define SCICR2                          _SCICR2.Byte
#define SCICR2_SBK                      _SCICR2.Bits.SBK
#define SCICR2_RWU                      _SCICR2.Bits.RWU
#define SCICR2_RE                       _SCICR2.Bits.RE
#define SCICR2_TE                       _SCICR2.Bits.TE
#define SCICR2_ILIE                     _SCICR2.Bits.ILIE
#define SCICR2_RIE                      _SCICR2.Bits.RIE
#define SCICR2_TCIE                     _SCICR2.Bits.TCIE
#define SCICR2_SCTIE                    _SCICR2.Bits.SCTIE

#define SCICR2_SBK_MASK                 1U
#define SCICR2_RWU_MASK                 2U
#define SCICR2_RE_MASK                  4U
#define SCICR2_TE_MASK                  8U
#define SCICR2_ILIE_MASK                16U
#define SCICR2_RIE_MASK                 32U
#define SCICR2_TCIE_MASK                64U
#define SCICR2_SCTIE_MASK               128U


/*** SCISR1 - SCI Status Register 1; 0x000000CC ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmit Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCISR1STR;
extern volatile SCISR1STR _SCISR1 @(REG_BASE + 0x000000CCUL);
#define SCISR1                          _SCISR1.Byte
#define SCISR1_PF                       _SCISR1.Bits.PF
#define SCISR1_FE                       _SCISR1.Bits.FE
#define SCISR1_NF                       _SCISR1.Bits.NF
#define SCISR1_OR                       _SCISR1.Bits.OR
#define SCISR1_IDLE                     _SCISR1.Bits.IDLE
#define SCISR1_RDRF                     _SCISR1.Bits.RDRF
#define SCISR1_TC                       _SCISR1.Bits.TC
#define SCISR1_TDRE                     _SCISR1.Bits.TDRE

#define SCISR1_PF_MASK                  1U
#define SCISR1_FE_MASK                  2U
#define SCISR1_NF_MASK                  4U
#define SCISR1_OR_MASK                  8U
#define SCISR1_IDLE_MASK                16U
#define SCISR1_RDRF_MASK                32U
#define SCISR1_TC_MASK                  64U
#define SCISR1_TDRE_MASK                128U


/*** SCISR2 - SCI Status Register 2; 0x000000CD ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte TXDIR       :1;                                       /* Transmitter pin data direction in Single-Wire mode */
    byte BRK13       :1;                                       /* Break Transmit character length */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SCISR2STR;
extern volatile SCISR2STR _SCISR2 @(REG_BASE + 0x000000CDUL);
#define SCISR2                          _SCISR2.Byte
#define SCISR2_RAF                      _SCISR2.Bits.RAF
#define SCISR2_TXDIR                    _SCISR2.Bits.TXDIR
#define SCISR2_BRK13                    _SCISR2.Bits.BRK13

#define SCISR2_RAF_MASK                 1U
#define SCISR2_TXDIR_MASK               2U
#define SCISR2_BRK13_MASK               4U


/*** SCIDRH - SCI Data Register High; 0x000000CE ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte T8          :1;                                       /* Transmit Bit 8 */
    byte R8          :1;                                       /* Received Bit 8 */
  } Bits;
} SCIDRHSTR;
extern volatile SCIDRHSTR _SCIDRH @(REG_BASE + 0x000000CEUL);
#define SCIDRH                          _SCIDRH.Byte
#define SCIDRH_T8                       _SCIDRH.Bits.T8
#define SCIDRH_R8                       _SCIDRH.Bits.R8

#define SCIDRH_T8_MASK                  64U
#define SCIDRH_R8_MASK                  128U


/*** SCIDRL - SCI Data Register Low; 0x000000CF ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Received bit 0 or Transmit bit 0 */
    byte R1_T1       :1;                                       /* Received bit 1 or Transmit bit 1 */
    byte R2_T2       :1;                                       /* Received bit 2 or Transmit bit 2 */
    byte R3_T3       :1;                                       /* Received bit 3 or Transmit bit 3 */
    byte R4_T4       :1;                                       /* Received bit 4 or Transmit bit 4 */
    byte R5_T5       :1;                                       /* Received bit 5 or Transmit bit 5 */
    byte R6_T6       :1;                                       /* Received bit 6 or Transmit bit 6 */
    byte R7_T7       :1;                                       /* Received bit 7 or Transmit bit 7 */
  } Bits;
} SCIDRLSTR;
extern volatile SCIDRLSTR _SCIDRL @(REG_BASE + 0x000000CFUL);
#define SCIDRL                          _SCIDRL.Byte
#define SCIDRL_R0_T0                    _SCIDRL.Bits.R0_T0
#define SCIDRL_R1_T1                    _SCIDRL.Bits.R1_T1
#define SCIDRL_R2_T2                    _SCIDRL.Bits.R2_T2
#define SCIDRL_R3_T3                    _SCIDRL.Bits.R3_T3
#define SCIDRL_R4_T4                    _SCIDRL.Bits.R4_T4
#define SCIDRL_R5_T5                    _SCIDRL.Bits.R5_T5
#define SCIDRL_R6_T6                    _SCIDRL.Bits.R6_T6
#define SCIDRL_R7_T7                    _SCIDRL.Bits.R7_T7

#define SCIDRL_R0_T0_MASK               1U
#define SCIDRL_R1_T1_MASK               2U
#define SCIDRL_R2_T2_MASK               4U
#define SCIDRL_R3_T3_MASK               8U
#define SCIDRL_R4_T4_MASK               16U
#define SCIDRL_R5_T5_MASK               32U
#define SCIDRL_R6_T6_MASK               64U
#define SCIDRL_R7_T7_MASK               128U


/*** SPICR1 - SPI Control Register; 0x000000D8 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* SPI LSB-First Enable */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* SPI Clock Phase Bit */
    byte CPOL        :1;                                       /* SPI Clock Polarity Bit */
    byte MSTR        :1;                                       /* SPI Master/Slave Mode Select Bit */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable Bit */
    byte SPIE        :1;                                       /* SPI Interrupt Enable Bit */
  } Bits;
} SPICR1STR;
extern volatile SPICR1STR _SPICR1 @(REG_BASE + 0x000000D8UL);
#define SPICR1                          _SPICR1.Byte
#define SPICR1_LSBFE                    _SPICR1.Bits.LSBFE
#define SPICR1_SSOE                     _SPICR1.Bits.SSOE
#define SPICR1_CPHA                     _SPICR1.Bits.CPHA
#define SPICR1_CPOL                     _SPICR1.Bits.CPOL
#define SPICR1_MSTR                     _SPICR1.Bits.MSTR
#define SPICR1_SPTIE                    _SPICR1.Bits.SPTIE
#define SPICR1_SPE                      _SPICR1.Bits.SPE
#define SPICR1_SPIE                     _SPICR1.Bits.SPIE

#define SPICR1_LSBFE_MASK               1U
#define SPICR1_SSOE_MASK                2U
#define SPICR1_CPHA_MASK                4U
#define SPICR1_CPOL_MASK                8U
#define SPICR1_MSTR_MASK                16U
#define SPICR1_SPTIE_MASK               32U
#define SPICR1_SPE_MASK                 64U
#define SPICR1_SPIE_MASK                128U


/*** SPICR2 - SPI Control Register 2; 0x000000D9 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* Serial Pin Control Bit 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode Bit */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Output enable in the Bidirectional mode of operation */
    byte MODFEN      :1;                                       /* Mode Fault Enable Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SPICR2STR;
extern volatile SPICR2STR _SPICR2 @(REG_BASE + 0x000000D9UL);
#define SPICR2                          _SPICR2.Byte
#define SPICR2_SPC0                     _SPICR2.Bits.SPC0
#define SPICR2_SPISWAI                  _SPICR2.Bits.SPISWAI
#define SPICR2_BIDIROE                  _SPICR2.Bits.BIDIROE
#define SPICR2_MODFEN                   _SPICR2.Bits.MODFEN

#define SPICR2_SPC0_MASK                1U
#define SPICR2_SPISWAI_MASK             2U
#define SPICR2_BIDIROE_MASK             8U
#define SPICR2_MODFEN_MASK              16U


/*** SPIBR - SPI Baud Rate Register; 0x000000DA ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Selection Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Selection Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Selection Bit 2 */
    byte             :1; 
    byte SPPR0       :1;                                       /* SPI Baud Rate Preselection Bits 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Preselection Bits 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Preselection Bits 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPIBRSTR;
extern volatile SPIBRSTR _SPIBR @(REG_BASE + 0x000000DAUL);
#define SPIBR                           _SPIBR.Byte
#define SPIBR_SPR0                      _SPIBR.Bits.SPR0
#define SPIBR_SPR1                      _SPIBR.Bits.SPR1
#define SPIBR_SPR2                      _SPIBR.Bits.SPR2
#define SPIBR_SPPR0                     _SPIBR.Bits.SPPR0
#define SPIBR_SPPR1                     _SPIBR.Bits.SPPR1
#define SPIBR_SPPR2                     _SPIBR.Bits.SPPR2
#define SPIBR_SPR                       _SPIBR.MergedBits.grpSPR
#define SPIBR_SPPR                      _SPIBR.MergedBits.grpSPPR

#define SPIBR_SPR0_MASK                 1U
#define SPIBR_SPR1_MASK                 2U
#define SPIBR_SPR2_MASK                 4U
#define SPIBR_SPPR0_MASK                16U
#define SPIBR_SPPR1_MASK                32U
#define SPIBR_SPPR2_MASK                64U
#define SPIBR_SPR_MASK                  7U
#define SPIBR_SPR_BITNUM                0U
#define SPIBR_SPPR_MASK                 112U
#define SPIBR_SPPR_BITNUM               4U


/*** SPISR - SPI Status Register; 0x000000DB ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Empty Interrupt Flag */
    byte             :1; 
    byte SPIF        :1;                                       /* SPIF Receive Interrupt Flag */
  } Bits;
} SPISRSTR;
extern volatile SPISRSTR _SPISR @(REG_BASE + 0x000000DBUL);
#define SPISR                           _SPISR.Byte
#define SPISR_MODF                      _SPISR.Bits.MODF
#define SPISR_SPTEF                     _SPISR.Bits.SPTEF
#define SPISR_SPIF                      _SPISR.Bits.SPIF

#define SPISR_MODF_MASK                 16U
#define SPISR_SPTEF_MASK                32U
#define SPISR_SPIF_MASK                 128U


/*** SPIDR - SPI Data Register; 0x000000DD ***/
typedef union {
  byte Byte;
} SPIDRSTR;
extern volatile SPIDRSTR _SPIDR @(REG_BASE + 0x000000DDUL);
#define SPIDR                           _SPIDR.Byte


/*** PWME - PWM Enable Register; 0x000000E0 ***/
typedef union {
  byte Byte;
  struct {
    byte PWME0       :1;                                       /* Pulse Width Channel 0 Enable */
    byte PWME1       :1;                                       /* Pulse Width Channel 1 Enable */
    byte PWME2       :1;                                       /* Pulse Width Channel 2 Enable */
    byte PWME3       :1;                                       /* Pulse Width Channel 3 Enable */
    byte PWME4       :1;                                       /* Pulse Width Channel 4 Enable */
    byte PWME5       :1;                                       /* Pulse Width Channel 5 Enable */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPWME :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PWMESTR;
extern volatile PWMESTR _PWME @(REG_BASE + 0x000000E0UL);
#define PWME                            _PWME.Byte
#define PWME_PWME0                      _PWME.Bits.PWME0
#define PWME_PWME1                      _PWME.Bits.PWME1
#define PWME_PWME2                      _PWME.Bits.PWME2
#define PWME_PWME3                      _PWME.Bits.PWME3
#define PWME_PWME4                      _PWME.Bits.PWME4
#define PWME_PWME5                      _PWME.Bits.PWME5
#define PWME_PWME                       _PWME.MergedBits.grpPWME

#define PWME_PWME0_MASK                 1U
#define PWME_PWME1_MASK                 2U
#define PWME_PWME2_MASK                 4U
#define PWME_PWME3_MASK                 8U
#define PWME_PWME4_MASK                 16U
#define PWME_PWME5_MASK                 32U
#define PWME_PWME_MASK                  63U
#define PWME_PWME_BITNUM                0U


/*** PWMPOL - PWM Polarity Register; 0x000000E1 ***/
typedef union {
  byte Byte;
  struct {
    byte PPOL0       :1;                                       /* Pulse Width Channel 0 Polarity */
    byte PPOL1       :1;                                       /* Pulse Width Channel 1 Polarity */
    byte PPOL2       :1;                                       /* Pulse Width Channel 2 Polarity */
    byte PPOL3       :1;                                       /* Pulse Width Channel 3 Polarity */
    byte PPOL4       :1;                                       /* Pulse Width Channel 4 Polarity */
    byte PPOL5       :1;                                       /* Pulse Width Channel 5 Polarity */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPPOL :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PWMPOLSTR;
extern volatile PWMPOLSTR _PWMPOL @(REG_BASE + 0x000000E1UL);
#define PWMPOL                          _PWMPOL.Byte
#define PWMPOL_PPOL0                    _PWMPOL.Bits.PPOL0
#define PWMPOL_PPOL1                    _PWMPOL.Bits.PPOL1
#define PWMPOL_PPOL2                    _PWMPOL.Bits.PPOL2
#define PWMPOL_PPOL3                    _PWMPOL.Bits.PPOL3
#define PWMPOL_PPOL4                    _PWMPOL.Bits.PPOL4
#define PWMPOL_PPOL5                    _PWMPOL.Bits.PPOL5
#define PWMPOL_PPOL                     _PWMPOL.MergedBits.grpPPOL

#define PWMPOL_PPOL0_MASK               1U
#define PWMPOL_PPOL1_MASK               2U
#define PWMPOL_PPOL2_MASK               4U
#define PWMPOL_PPOL3_MASK               8U
#define PWMPOL_PPOL4_MASK               16U
#define PWMPOL_PPOL5_MASK               32U
#define PWMPOL_PPOL_MASK                63U
#define PWMPOL_PPOL_BITNUM              0U


/*** PWMCLK - PWM Clock Select Register; 0x000000E2 ***/
typedef union {
  byte Byte;
  struct {
    byte PCLK0       :1;                                       /* Pulse Width Channel 0 Clock Select */
    byte PCLK1       :1;                                       /* Pulse Width Channel 1 Clock Select */
    byte PCLK2       :1;                                       /* Pulse Width Channel 2 Clock Select */
    byte PCLK3       :1;                                       /* Pulse Width Channel 3 Clock Select */
    byte PCLK4       :1;                                       /* Pulse Width Channel 4 Clock Select */
    byte PCLK5       :1;                                       /* Pulse Width Channel 5 Clock Select */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPCLK :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PWMCLKSTR;
extern volatile PWMCLKSTR _PWMCLK @(REG_BASE + 0x000000E2UL);
#define PWMCLK                          _PWMCLK.Byte
#define PWMCLK_PCLK0                    _PWMCLK.Bits.PCLK0
#define PWMCLK_PCLK1                    _PWMCLK.Bits.PCLK1
#define PWMCLK_PCLK2                    _PWMCLK.Bits.PCLK2
#define PWMCLK_PCLK3                    _PWMCLK.Bits.PCLK3
#define PWMCLK_PCLK4                    _PWMCLK.Bits.PCLK4
#define PWMCLK_PCLK5                    _PWMCLK.Bits.PCLK5
#define PWMCLK_PCLK                     _PWMCLK.MergedBits.grpPCLK

#define PWMCLK_PCLK0_MASK               1U
#define PWMCLK_PCLK1_MASK               2U
#define PWMCLK_PCLK2_MASK               4U
#define PWMCLK_PCLK3_MASK               8U
#define PWMCLK_PCLK4_MASK               16U
#define PWMCLK_PCLK5_MASK               32U
#define PWMCLK_PCLK_MASK                63U
#define PWMCLK_PCLK_BITNUM              0U


/*** PWMPRCLK - PWM Prescale Clock Select Register; 0x000000E3 ***/
typedef union {
  byte Byte;
  struct {
    byte PCKA0       :1;                                       /* Prescaler Select for Clock A 0 */
    byte PCKA1       :1;                                       /* Prescaler Select for Clock A 1 */
    byte PCKA2       :1;                                       /* Prescaler Select for Clock A 2 */
    byte             :1; 
    byte PCKB0       :1;                                       /* Prescaler Select for Clock B 0 */
    byte PCKB1       :1;                                       /* Prescaler Select for Clock B 1 */
    byte PCKB2       :1;                                       /* Prescaler Select for Clock B 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPCKA :3;
    byte         :1;
    byte grpPCKB :3;
    byte         :1;
  } MergedBits;
} PWMPRCLKSTR;
extern volatile PWMPRCLKSTR _PWMPRCLK @(REG_BASE + 0x000000E3UL);
#define PWMPRCLK                        _PWMPRCLK.Byte
#define PWMPRCLK_PCKA0                  _PWMPRCLK.Bits.PCKA0
#define PWMPRCLK_PCKA1                  _PWMPRCLK.Bits.PCKA1
#define PWMPRCLK_PCKA2                  _PWMPRCLK.Bits.PCKA2
#define PWMPRCLK_PCKB0                  _PWMPRCLK.Bits.PCKB0
#define PWMPRCLK_PCKB1                  _PWMPRCLK.Bits.PCKB1
#define PWMPRCLK_PCKB2                  _PWMPRCLK.Bits.PCKB2
#define PWMPRCLK_PCKA                   _PWMPRCLK.MergedBits.grpPCKA
#define PWMPRCLK_PCKB                   _PWMPRCLK.MergedBits.grpPCKB

#define PWMPRCLK_PCKA0_MASK             1U
#define PWMPRCLK_PCKA1_MASK             2U
#define PWMPRCLK_PCKA2_MASK             4U
#define PWMPRCLK_PCKB0_MASK             16U
#define PWMPRCLK_PCKB1_MASK             32U
#define PWMPRCLK_PCKB2_MASK             64U
#define PWMPRCLK_PCKA_MASK              7U
#define PWMPRCLK_PCKA_BITNUM            0U
#define PWMPRCLK_PCKB_MASK              112U
#define PWMPRCLK_PCKB_BITNUM            4U


/*** PWMCAE - PWM Center Align Enable Register; 0x000000E4 ***/
typedef union {
  byte Byte;
  struct {
    byte CAE0        :1;                                       /* Center Aligned Output Mode on channel 0 */
    byte CAE1        :1;                                       /* Center Aligned Output Mode on channel 1 */
    byte CAE2        :1;                                       /* Center Aligned Output Mode on channel 2 */
    byte CAE3        :1;                                       /* Center Aligned Output Mode on channel 3 */
    byte CAE4        :1;                                       /* Center Aligned Output Mode on channel 4 */
    byte CAE5        :1;                                       /* Center Aligned Output Mode on channel 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCAE  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PWMCAESTR;
extern volatile PWMCAESTR _PWMCAE @(REG_BASE + 0x000000E4UL);
#define PWMCAE                          _PWMCAE.Byte
#define PWMCAE_CAE0                     _PWMCAE.Bits.CAE0
#define PWMCAE_CAE1                     _PWMCAE.Bits.CAE1
#define PWMCAE_CAE2                     _PWMCAE.Bits.CAE2
#define PWMCAE_CAE3                     _PWMCAE.Bits.CAE3
#define PWMCAE_CAE4                     _PWMCAE.Bits.CAE4
#define PWMCAE_CAE5                     _PWMCAE.Bits.CAE5
#define PWMCAE_CAE                      _PWMCAE.MergedBits.grpCAE

#define PWMCAE_CAE0_MASK                1U
#define PWMCAE_CAE1_MASK                2U
#define PWMCAE_CAE2_MASK                4U
#define PWMCAE_CAE3_MASK                8U
#define PWMCAE_CAE4_MASK                16U
#define PWMCAE_CAE5_MASK                32U
#define PWMCAE_CAE_MASK                 63U
#define PWMCAE_CAE_BITNUM               0U


/*** PWMCTL - PWM Control Register; 0x000000E5 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte PFRZ        :1;                                       /* PWM Counters Stop in Freeze Mode */
    byte PSWAI       :1;                                       /* PWM Stops in Wait Mode */
    byte CON01       :1;                                       /* Concatenate channels 0 and 1 */
    byte CON23       :1;                                       /* Concatenate channels 2 and 3 */
    byte CON45       :1;                                       /* Concatenate channels 4 and 5 */
    byte             :1; 
  } Bits;
} PWMCTLSTR;
extern volatile PWMCTLSTR _PWMCTL @(REG_BASE + 0x000000E5UL);
#define PWMCTL                          _PWMCTL.Byte
#define PWMCTL_PFRZ                     _PWMCTL.Bits.PFRZ
#define PWMCTL_PSWAI                    _PWMCTL.Bits.PSWAI
#define PWMCTL_CON01                    _PWMCTL.Bits.CON01
#define PWMCTL_CON23                    _PWMCTL.Bits.CON23
#define PWMCTL_CON45                    _PWMCTL.Bits.CON45

#define PWMCTL_PFRZ_MASK                4U
#define PWMCTL_PSWAI_MASK               8U
#define PWMCTL_CON01_MASK               16U
#define PWMCTL_CON23_MASK               32U
#define PWMCTL_CON45_MASK               64U


/*** PWMSCLA - PWM Scale A Register; 0x000000E8 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* PWM Scale A Bit 0 */
    byte BIT1        :1;                                       /* PWM Scale A Bit 1 */
    byte BIT2        :1;                                       /* PWM Scale A Bit 2 */
    byte BIT3        :1;                                       /* PWM Scale A Bit 3 */
    byte BIT4        :1;                                       /* PWM Scale A Bit 4 */
    byte BIT5        :1;                                       /* PWM Scale A Bit 5 */
    byte BIT6        :1;                                       /* PWM Scale A Bit 6 */
    byte BIT7        :1;                                       /* PWM Scale A Bit 7 */
  } Bits;
} PWMSCLASTR;
extern volatile PWMSCLASTR _PWMSCLA @(REG_BASE + 0x000000E8UL);
#define PWMSCLA                         _PWMSCLA.Byte
#define PWMSCLA_BIT0                    _PWMSCLA.Bits.BIT0
#define PWMSCLA_BIT1                    _PWMSCLA.Bits.BIT1
#define PWMSCLA_BIT2                    _PWMSCLA.Bits.BIT2
#define PWMSCLA_BIT3                    _PWMSCLA.Bits.BIT3
#define PWMSCLA_BIT4                    _PWMSCLA.Bits.BIT4
#define PWMSCLA_BIT5                    _PWMSCLA.Bits.BIT5
#define PWMSCLA_BIT6                    _PWMSCLA.Bits.BIT6
#define PWMSCLA_BIT7                    _PWMSCLA.Bits.BIT7

#define PWMSCLA_BIT0_MASK               1U
#define PWMSCLA_BIT1_MASK               2U
#define PWMSCLA_BIT2_MASK               4U
#define PWMSCLA_BIT3_MASK               8U
#define PWMSCLA_BIT4_MASK               16U
#define PWMSCLA_BIT5_MASK               32U
#define PWMSCLA_BIT6_MASK               64U
#define PWMSCLA_BIT7_MASK               128U


/*** PWMSCLB - PWM Scale B Register; 0x000000E9 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* PWM Scale B Bit 0 */
    byte BIT1        :1;                                       /* PWM Scale B Bit 1 */
    byte BIT2        :1;                                       /* PWM Scale B Bit 2 */
    byte BIT3        :1;                                       /* PWM Scale B Bit 3 */
    byte BIT4        :1;                                       /* PWM Scale B Bit 4 */
    byte BIT5        :1;                                       /* PWM Scale B Bit 5 */
    byte BIT6        :1;                                       /* PWM Scale B Bit 6 */
    byte BIT7        :1;                                       /* PWM Scale B Bit 7 */
  } Bits;
} PWMSCLBSTR;
extern volatile PWMSCLBSTR _PWMSCLB @(REG_BASE + 0x000000E9UL);
#define PWMSCLB                         _PWMSCLB.Byte
#define PWMSCLB_BIT0                    _PWMSCLB.Bits.BIT0
#define PWMSCLB_BIT1                    _PWMSCLB.Bits.BIT1
#define PWMSCLB_BIT2                    _PWMSCLB.Bits.BIT2
#define PWMSCLB_BIT3                    _PWMSCLB.Bits.BIT3
#define PWMSCLB_BIT4                    _PWMSCLB.Bits.BIT4
#define PWMSCLB_BIT5                    _PWMSCLB.Bits.BIT5
#define PWMSCLB_BIT6                    _PWMSCLB.Bits.BIT6
#define PWMSCLB_BIT7                    _PWMSCLB.Bits.BIT7

#define PWMSCLB_BIT0_MASK               1U
#define PWMSCLB_BIT1_MASK               2U
#define PWMSCLB_BIT2_MASK               4U
#define PWMSCLB_BIT3_MASK               8U
#define PWMSCLB_BIT4_MASK               16U
#define PWMSCLB_BIT5_MASK               32U
#define PWMSCLB_BIT6_MASK               64U
#define PWMSCLB_BIT7_MASK               128U


/*** PWMCNT01 - PWM Channel Counter 01 Register; 0x000000EC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMCNT0 - PWM Channel Counter 0 Register; 0x000000EC ***/
    union {
      byte Byte;
    } PWMCNT0STR;
    #define PWMCNT0                     _PWMCNT01.Overlap_STR.PWMCNT0STR.Byte
    /* PWMCNT_ARR: Access 6 PWMCNTx registers in an array */
    #define PWMCNT_ARR                  ((volatile byte *) &PWMCNT0)
    

    /*** PWMCNT1 - PWM Channel Counter 1 Register; 0x000000ED ***/
    union {
      byte Byte;
    } PWMCNT1STR;
    #define PWMCNT1                     _PWMCNT01.Overlap_STR.PWMCNT1STR.Byte
    
  } Overlap_STR;

} PWMCNT01STR;
extern volatile PWMCNT01STR _PWMCNT01 @(REG_BASE + 0x000000ECUL);
#define PWMCNT01                        _PWMCNT01.Word


/*** PWMCNT23 - PWM Channel Counter 23 Register; 0x000000EE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMCNT2 - PWM Channel Counter 2 Register; 0x000000EE ***/
    union {
      byte Byte;
    } PWMCNT2STR;
    #define PWMCNT2                     _PWMCNT23.Overlap_STR.PWMCNT2STR.Byte
    

    /*** PWMCNT3 - PWM Channel Counter 3 Register; 0x000000EF ***/
    union {
      byte Byte;
    } PWMCNT3STR;
    #define PWMCNT3                     _PWMCNT23.Overlap_STR.PWMCNT3STR.Byte
    
  } Overlap_STR;

} PWMCNT23STR;
extern volatile PWMCNT23STR _PWMCNT23 @(REG_BASE + 0x000000EEUL);
#define PWMCNT23                        _PWMCNT23.Word


/*** PWMCNT45 - PWM Channel Counter 45 Register; 0x000000F0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMCNT4 - PWM Channel Counter 4 Register; 0x000000F0 ***/
    union {
      byte Byte;
    } PWMCNT4STR;
    #define PWMCNT4                     _PWMCNT45.Overlap_STR.PWMCNT4STR.Byte
    

    /*** PWMCNT5 - PWM Channel Counter 5 Register; 0x000000F1 ***/
    union {
      byte Byte;
    } PWMCNT5STR;
    #define PWMCNT5                     _PWMCNT45.Overlap_STR.PWMCNT5STR.Byte
    
  } Overlap_STR;

} PWMCNT45STR;
extern volatile PWMCNT45STR _PWMCNT45 @(REG_BASE + 0x000000F0UL);
#define PWMCNT45                        _PWMCNT45.Word


/*** PWMPER01 - PWM Channel Period 01 Register; 0x000000F2 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMPER0 - PWM Channel Period 0 Register; 0x000000F2 ***/
    union {
      byte Byte;
    } PWMPER0STR;
    #define PWMPER0                     _PWMPER01.Overlap_STR.PWMPER0STR.Byte
    /* PWMPER_ARR: Access 6 PWMPERx registers in an array */
    #define PWMPER_ARR                  ((volatile byte *) &PWMPER0)
    

    /*** PWMPER1 - PWM Channel Period 1 Register; 0x000000F3 ***/
    union {
      byte Byte;
    } PWMPER1STR;
    #define PWMPER1                     _PWMPER01.Overlap_STR.PWMPER1STR.Byte
    
  } Overlap_STR;

} PWMPER01STR;
extern volatile PWMPER01STR _PWMPER01 @(REG_BASE + 0x000000F2UL);
#define PWMPER01                        _PWMPER01.Word


/*** PWMPER23 - PWM Channel Period 23 Register; 0x000000F4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMPER2 - PWM Channel Period 2 Register; 0x000000F4 ***/
    union {
      byte Byte;
    } PWMPER2STR;
    #define PWMPER2                     _PWMPER23.Overlap_STR.PWMPER2STR.Byte
    

    /*** PWMPER3 - PWM Channel Period 3 Register; 0x000000F5 ***/
    union {
      byte Byte;
    } PWMPER3STR;
    #define PWMPER3                     _PWMPER23.Overlap_STR.PWMPER3STR.Byte
    
  } Overlap_STR;

} PWMPER23STR;
extern volatile PWMPER23STR _PWMPER23 @(REG_BASE + 0x000000F4UL);
#define PWMPER23                        _PWMPER23.Word


/*** PWMPER45 - PWM Channel Period 45 Register; 0x000000F6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMPER4 - PWM Channel Period 4 Register; 0x000000F6 ***/
    union {
      byte Byte;
    } PWMPER4STR;
    #define PWMPER4                     _PWMPER45.Overlap_STR.PWMPER4STR.Byte
    

    /*** PWMPER5 - PWM Channel Period 5 Register; 0x000000F7 ***/
    union {
      byte Byte;
    } PWMPER5STR;
    #define PWMPER5                     _PWMPER45.Overlap_STR.PWMPER5STR.Byte
    
  } Overlap_STR;

} PWMPER45STR;
extern volatile PWMPER45STR _PWMPER45 @(REG_BASE + 0x000000F6UL);
#define PWMPER45                        _PWMPER45.Word


/*** PWMDTY01 - PWM Channel Duty 01 Register; 0x000000F8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMDTY0 - PWM Channel Duty 0 Register; 0x000000F8 ***/
    union {
      byte Byte;
    } PWMDTY0STR;
    #define PWMDTY0                     _PWMDTY01.Overlap_STR.PWMDTY0STR.Byte
    /* PWMDTY_ARR: Access 6 PWMDTYx registers in an array */
    #define PWMDTY_ARR                  ((volatile byte *) &PWMDTY0)
    

    /*** PWMDTY1 - PWM Channel Duty 1 Register; 0x000000F9 ***/
    union {
      byte Byte;
    } PWMDTY1STR;
    #define PWMDTY1                     _PWMDTY01.Overlap_STR.PWMDTY1STR.Byte
    
  } Overlap_STR;

} PWMDTY01STR;
extern volatile PWMDTY01STR _PWMDTY01 @(REG_BASE + 0x000000F8UL);
#define PWMDTY01                        _PWMDTY01.Word


/*** PWMDTY23 - PWM Channel Duty 23 Register; 0x000000FA ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMDTY2 - PWM Channel Duty 2 Register; 0x000000FA ***/
    union {
      byte Byte;
    } PWMDTY2STR;
    #define PWMDTY2                     _PWMDTY23.Overlap_STR.PWMDTY2STR.Byte
    

    /*** PWMDTY3 - PWM Channel Duty 3 Register; 0x000000FB ***/
    union {
      byte Byte;
    } PWMDTY3STR;
    #define PWMDTY3                     _PWMDTY23.Overlap_STR.PWMDTY3STR.Byte
    
  } Overlap_STR;

} PWMDTY23STR;
extern volatile PWMDTY23STR _PWMDTY23 @(REG_BASE + 0x000000FAUL);
#define PWMDTY23                        _PWMDTY23.Word


/*** PWMDTY45 - PWM Channel Duty 45 Register; 0x000000FC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMDTY4 - PWM Channel Duty 4 Register; 0x000000FC ***/
    union {
      byte Byte;
    } PWMDTY4STR;
    #define PWMDTY4                     _PWMDTY45.Overlap_STR.PWMDTY4STR.Byte
    

    /*** PWMDTY5 - PWM Channel Duty 5 Register; 0x000000FD ***/
    union {
      byte Byte;
    } PWMDTY5STR;
    #define PWMDTY5                     _PWMDTY45.Overlap_STR.PWMDTY5STR.Byte
    
  } Overlap_STR;

} PWMDTY45STR;
extern volatile PWMDTY45STR _PWMDTY45 @(REG_BASE + 0x000000FCUL);
#define PWMDTY45                        _PWMDTY45.Word


/*** PWMSDN - PWM Shutdown Register; 0x000000FE ***/
typedef union {
  byte Byte;
  struct {
    byte PWM5ENA     :1;                                       /* PWM emergency shutdown Enable */
    byte PWM5INL     :1;                                       /* PWM shutdown active input level for ch. 5 */
    byte PWM5IN      :1;                                       /* PWM channel 5 input status */
    byte             :1; 
    byte PWMLVL      :1;                                       /* PWM shutdown output Level */
    byte PWMRSTRT    :1;                                       /* PWM Restart */
    byte PWMIE       :1;                                       /* PWM Interrupt Enable */
    byte PWMIF       :1;                                       /* PWM Interrupt Flag */
  } Bits;
} PWMSDNSTR;
extern volatile PWMSDNSTR _PWMSDN @(REG_BASE + 0x000000FEUL);
#define PWMSDN                          _PWMSDN.Byte
#define PWMSDN_PWM5ENA                  _PWMSDN.Bits.PWM5ENA
#define PWMSDN_PWM5INL                  _PWMSDN.Bits.PWM5INL
#define PWMSDN_PWM5IN                   _PWMSDN.Bits.PWM5IN
#define PWMSDN_PWMLVL                   _PWMSDN.Bits.PWMLVL
#define PWMSDN_PWMRSTRT                 _PWMSDN.Bits.PWMRSTRT
#define PWMSDN_PWMIE                    _PWMSDN.Bits.PWMIE
#define PWMSDN_PWMIF                    _PWMSDN.Bits.PWMIF

#define PWMSDN_PWM5ENA_MASK             1U
#define PWMSDN_PWM5INL_MASK             2U
#define PWMSDN_PWM5IN_MASK              4U
#define PWMSDN_PWMLVL_MASK              16U
#define PWMSDN_PWMRSTRT_MASK            32U
#define PWMSDN_PWMIE_MASK               64U
#define PWMSDN_PWMIF_MASK               128U


/*** FCLKDIV - Flash Clock Divider Register; 0x00000100 ***/
typedef union {
  byte Byte;
  struct {
    byte FDIV0       :1;                                       /* Flash Clock Divider Bit 0 */
    byte FDIV1       :1;                                       /* Flash Clock Divider Bit 1 */
    byte FDIV2       :1;                                       /* Flash Clock Divider Bit 2 */
    byte FDIV3       :1;                                       /* Flash Clock Divider Bit 3 */
    byte FDIV4       :1;                                       /* Flash Clock Divider Bit 4 */
    byte FDIV5       :1;                                       /* Flash Clock Divider Bit 5 */
    byte PRDIV8      :1;                                       /* Enable Prescaler by 8 */
    byte FDIVLD      :1;                                       /* Flash Clock Divider Loaded */
  } Bits;
  struct {
    byte grpFDIV :6;
    byte grpPRDIV_8 :1;
    byte         :1;
  } MergedBits;
} FCLKDIVSTR;
extern volatile FCLKDIVSTR _FCLKDIV @(REG_BASE + 0x00000100UL);
#define FCLKDIV                         _FCLKDIV.Byte
#define FCLKDIV_FDIV0                   _FCLKDIV.Bits.FDIV0
#define FCLKDIV_FDIV1                   _FCLKDIV.Bits.FDIV1
#define FCLKDIV_FDIV2                   _FCLKDIV.Bits.FDIV2
#define FCLKDIV_FDIV3                   _FCLKDIV.Bits.FDIV3
#define FCLKDIV_FDIV4                   _FCLKDIV.Bits.FDIV4
#define FCLKDIV_FDIV5                   _FCLKDIV.Bits.FDIV5
#define FCLKDIV_PRDIV8                  _FCLKDIV.Bits.PRDIV8
#define FCLKDIV_FDIVLD                  _FCLKDIV.Bits.FDIVLD
#define FCLKDIV_FDIV                    _FCLKDIV.MergedBits.grpFDIV

#define FCLKDIV_FDIV0_MASK              1U
#define FCLKDIV_FDIV1_MASK              2U
#define FCLKDIV_FDIV2_MASK              4U
#define FCLKDIV_FDIV3_MASK              8U
#define FCLKDIV_FDIV4_MASK              16U
#define FCLKDIV_FDIV5_MASK              32U
#define FCLKDIV_PRDIV8_MASK             64U
#define FCLKDIV_FDIVLD_MASK             128U
#define FCLKDIV_FDIV_MASK               63U
#define FCLKDIV_FDIV_BITNUM             0U


/*** FSEC - Flash Security Register; 0x00000101 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Memory security bit 0 */
    byte SEC1        :1;                                       /* Memory security bit 1 */
    byte NV2         :1;                                       /* Non Volatile flag bit 2 */
    byte NV3         :1;                                       /* Non Volatile flag bit 3 */
    byte NV4         :1;                                       /* Non Volatile flag bit 4 */
    byte NV5         :1;                                       /* Non Volatile flag bit 5 */
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte grpNV_2 :4;
    byte grpKEYEN :2;
  } MergedBits;
} FSECSTR;
extern volatile FSECSTR _FSEC @(REG_BASE + 0x00000101UL);
#define FSEC                            _FSEC.Byte
#define FSEC_SEC0                       _FSEC.Bits.SEC0
#define FSEC_SEC1                       _FSEC.Bits.SEC1
#define FSEC_NV2                        _FSEC.Bits.NV2
#define FSEC_NV3                        _FSEC.Bits.NV3
#define FSEC_NV4                        _FSEC.Bits.NV4
#define FSEC_NV5                        _FSEC.Bits.NV5
#define FSEC_KEYEN0                     _FSEC.Bits.KEYEN0
#define FSEC_KEYEN1                     _FSEC.Bits.KEYEN1
#define FSEC_SEC                        _FSEC.MergedBits.grpSEC
#define FSEC_NV_2                       _FSEC.MergedBits.grpNV_2
#define FSEC_KEYEN                      _FSEC.MergedBits.grpKEYEN
#define FSEC_NV                         FSEC_NV_2

#define FSEC_SEC0_MASK                  1U
#define FSEC_SEC1_MASK                  2U
#define FSEC_NV2_MASK                   4U
#define FSEC_NV3_MASK                   8U
#define FSEC_NV4_MASK                   16U
#define FSEC_NV5_MASK                   32U
#define FSEC_KEYEN0_MASK                64U
#define FSEC_KEYEN1_MASK                128U
#define FSEC_SEC_MASK                   3U
#define FSEC_SEC_BITNUM                 0U
#define FSEC_NV_2_MASK                  60U
#define FSEC_NV_2_BITNUM                2U
#define FSEC_KEYEN_MASK                 192U
#define FSEC_KEYEN_BITNUM               6U


/*** FCNFG - Flash Configuration Register; 0x00000103 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYACC      :1;                                       /* Enable Security Key Writing */
    byte CCIE        :1;                                       /* Command Complete Interrupt Enable */
    byte CBEIE       :1;                                       /* Command Buffers Empty Interrupt Enable */
  } Bits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG @(REG_BASE + 0x00000103UL);
#define FCNFG                           _FCNFG.Byte
#define FCNFG_KEYACC                    _FCNFG.Bits.KEYACC
#define FCNFG_CCIE                      _FCNFG.Bits.CCIE
#define FCNFG_CBEIE                     _FCNFG.Bits.CBEIE

#define FCNFG_KEYACC_MASK               32U
#define FCNFG_CCIE_MASK                 64U
#define FCNFG_CBEIE_MASK                128U


/*** FPROT - Flash Protection Register; 0x00000104 ***/
typedef union {
  byte Byte;
  struct {
    byte FPLS0       :1;                                       /* Flash Protection Lower Address size 0 */
    byte FPLS1       :1;                                       /* Flash Protection Lower Address size 1 */
    byte FPLDIS      :1;                                       /* Flash Protection Lower address range disable */
    byte FPHS0       :1;                                       /* Flash Protection Higher address size 0 */
    byte FPHS1       :1;                                       /* Flash Protection Higher address size 1 */
    byte FPHDIS      :1;                                       /* Flash Protection Higher address range disable */
    byte NV6         :1;                                       /* Non Volatile Flag Bit */
    byte FPOPEN      :1;                                       /* Opens the flash block or subsections of it for program or erase */
  } Bits;
  struct {
    byte grpFPLS :2;
    byte         :1;
    byte grpFPHS :2;
    byte         :1;
    byte grpNV_6 :1;
    byte         :1;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT @(REG_BASE + 0x00000104UL);
#define FPROT                           _FPROT.Byte
#define FPROT_FPLS0                     _FPROT.Bits.FPLS0
#define FPROT_FPLS1                     _FPROT.Bits.FPLS1
#define FPROT_FPLDIS                    _FPROT.Bits.FPLDIS
#define FPROT_FPHS0                     _FPROT.Bits.FPHS0
#define FPROT_FPHS1                     _FPROT.Bits.FPHS1
#define FPROT_FPHDIS                    _FPROT.Bits.FPHDIS
#define FPROT_NV6                       _FPROT.Bits.NV6
#define FPROT_FPOPEN                    _FPROT.Bits.FPOPEN
#define FPROT_FPLS                      _FPROT.MergedBits.grpFPLS
#define FPROT_FPHS                      _FPROT.MergedBits.grpFPHS

#define FPROT_FPLS0_MASK                1U
#define FPROT_FPLS1_MASK                2U
#define FPROT_FPLDIS_MASK               4U
#define FPROT_FPHS0_MASK                8U
#define FPROT_FPHS1_MASK                16U
#define FPROT_FPHDIS_MASK               32U
#define FPROT_NV6_MASK                  64U
#define FPROT_FPOPEN_MASK               128U
#define FPROT_FPLS_MASK                 3U
#define FPROT_FPLS_BITNUM               0U
#define FPROT_FPHS_MASK                 24U
#define FPROT_FPHS_BITNUM               3U


/*** FSTAT - Flash Status Register; 0x00000105 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte BLANK       :1;                                       /* Blank Verify Flag */
    byte             :1; 
    byte ACCERR      :1;                                       /* Access error */
    byte PVIOL       :1;                                       /* Protection violation */
    byte CCIF        :1;                                       /* Command Complete Interrupt Flag */
    byte CBEIF       :1;                                       /* Command Buffers Empty Interrupt Flag */
  } Bits;
} FSTATSTR;
extern volatile FSTATSTR _FSTAT @(REG_BASE + 0x00000105UL);
#define FSTAT                           _FSTAT.Byte
#define FSTAT_BLANK                     _FSTAT.Bits.BLANK
#define FSTAT_ACCERR                    _FSTAT.Bits.ACCERR
#define FSTAT_PVIOL                     _FSTAT.Bits.PVIOL
#define FSTAT_CCIF                      _FSTAT.Bits.CCIF
#define FSTAT_CBEIF                     _FSTAT.Bits.CBEIF

#define FSTAT_BLANK_MASK                4U
#define FSTAT_ACCERR_MASK               16U
#define FSTAT_PVIOL_MASK                32U
#define FSTAT_CCIF_MASK                 64U
#define FSTAT_CBEIF_MASK                128U


/*** FCMD - Flash Command Buffer and Register; 0x00000106 ***/
typedef union {
  byte Byte;
  struct {
    byte CMDB0       :1;                                       /* NVM User Mode Command Bit 0 */
    byte             :1; 
    byte CMDB2       :1;                                       /* NVM User Mode Command Bit 2 */
    byte             :1; 
    byte             :1; 
    byte CMDB5       :1;                                       /* NVM User Mode Command Bit 5 */
    byte CMDB6       :1;                                       /* NVM User Mode Command Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpCMDB :1;
    byte         :1;
    byte grpCMDB_2 :1;
    byte         :1;
    byte         :1;
    byte grpCMDB_5 :2;
    byte         :1;
  } MergedBits;
} FCMDSTR;
extern volatile FCMDSTR _FCMD @(REG_BASE + 0x00000106UL);
#define FCMD                            _FCMD.Byte
#define FCMD_CMDB0                      _FCMD.Bits.CMDB0
#define FCMD_CMDB2                      _FCMD.Bits.CMDB2
#define FCMD_CMDB5                      _FCMD.Bits.CMDB5
#define FCMD_CMDB6                      _FCMD.Bits.CMDB6
#define FCMD_CMDB_5                     _FCMD.MergedBits.grpCMDB_5
#define FCMD_CMDB                       FCMD_CMDB_5

#define FCMD_CMDB0_MASK                 1U
#define FCMD_CMDB2_MASK                 4U
#define FCMD_CMDB5_MASK                 32U
#define FCMD_CMDB6_MASK                 64U
#define FCMD_CMDB_5_MASK                96U
#define FCMD_CMDB_5_BITNUM              5U


/*** CANCTL0 - MSCAN Control 0 Register; 0x00000140 ***/
typedef union {
  byte Byte;
  struct {
    byte INITRQ      :1;                                       /* Initialization Mode Request */
    byte SLPRQ       :1;                                       /* Sleep Mode Request */
    byte WUPE        :1;                                       /* Wake-Up Enable */
    byte TIME        :1;                                       /* Timer Enable */
    byte SYNCH       :1;                                       /* Synchronized Status */
    byte CSWAI       :1;                                       /* CAN Stops in Wait Mode */
    byte RXACT       :1;                                       /* Receiver Active Status */
    byte RXFRM       :1;                                       /* Received Frame Flag */
  } Bits;
} CANCTL0STR;
extern volatile CANCTL0STR _CANCTL0 @(REG_BASE + 0x00000140UL);
#define CANCTL0                         _CANCTL0.Byte
#define CANCTL0_INITRQ                  _CANCTL0.Bits.INITRQ
#define CANCTL0_SLPRQ                   _CANCTL0.Bits.SLPRQ
#define CANCTL0_WUPE                    _CANCTL0.Bits.WUPE
#define CANCTL0_TIME                    _CANCTL0.Bits.TIME
#define CANCTL0_SYNCH                   _CANCTL0.Bits.SYNCH
#define CANCTL0_CSWAI                   _CANCTL0.Bits.CSWAI
#define CANCTL0_RXACT                   _CANCTL0.Bits.RXACT
#define CANCTL0_RXFRM                   _CANCTL0.Bits.RXFRM
/* CANCTL_ARR: Access 2 CANCTLx registers in an array */
#define CANCTL_ARR                      ((volatile byte *) &CANCTL0)

#define CANCTL0_INITRQ_MASK             1U
#define CANCTL0_SLPRQ_MASK              2U
#define CANCTL0_WUPE_MASK               4U
#define CANCTL0_TIME_MASK               8U
#define CANCTL0_SYNCH_MASK              16U
#define CANCTL0_CSWAI_MASK              32U
#define CANCTL0_RXACT_MASK              64U
#define CANCTL0_RXFRM_MASK              128U


/*** CANCTL1 - MSCAN Control 1 Register; 0x00000141 ***/
typedef union {
  byte Byte;
  struct {
    byte INITAK      :1;                                       /* Initialization Mode Acknowledge */
    byte SLPAK       :1;                                       /* Sleep Mode Acknowledge */
    byte WUPM        :1;                                       /* Wake-Up Mode */
    byte             :1; 
    byte LISTEN      :1;                                       /* Listen Only Mode */
    byte LOOPB       :1;                                       /* Loop Back Self Test Mode */
    byte CLKSRC      :1;                                       /* MSCAN Clock Source */
    byte CANE        :1;                                       /* MSCAN Enable */
  } Bits;
} CANCTL1STR;
extern volatile CANCTL1STR _CANCTL1 @(REG_BASE + 0x00000141UL);
#define CANCTL1                         _CANCTL1.Byte
#define CANCTL1_INITAK                  _CANCTL1.Bits.INITAK
#define CANCTL1_SLPAK                   _CANCTL1.Bits.SLPAK
#define CANCTL1_WUPM                    _CANCTL1.Bits.WUPM
#define CANCTL1_LISTEN                  _CANCTL1.Bits.LISTEN
#define CANCTL1_LOOPB                   _CANCTL1.Bits.LOOPB
#define CANCTL1_CLKSRC                  _CANCTL1.Bits.CLKSRC
#define CANCTL1_CANE                    _CANCTL1.Bits.CANE

#define CANCTL1_INITAK_MASK             1U
#define CANCTL1_SLPAK_MASK              2U
#define CANCTL1_WUPM_MASK               4U
#define CANCTL1_LISTEN_MASK             16U
#define CANCTL1_LOOPB_MASK              32U
#define CANCTL1_CLKSRC_MASK             64U
#define CANCTL1_CANE_MASK               128U


/*** CANBTR0 - MSCAN Bus Timing Register 0; 0x00000142 ***/
typedef union {
  byte Byte;
  struct {
    byte BRP0        :1;                                       /* Baud Rate Prescaler 0 */
    byte BRP1        :1;                                       /* Baud Rate Prescaler 1 */
    byte BRP2        :1;                                       /* Baud Rate Prescaler 2 */
    byte BRP3        :1;                                       /* Baud Rate Prescaler 3 */
    byte BRP4        :1;                                       /* Baud Rate Prescaler 4 */
    byte BRP5        :1;                                       /* Baud Rate Prescaler 5 */
    byte SJW0        :1;                                       /* Synchronization Jump Width 0 */
    byte SJW1        :1;                                       /* Synchronization Jump Width 1 */
  } Bits;
  struct {
    byte grpBRP  :6;
    byte grpSJW  :2;
  } MergedBits;
} CANBTR0STR;
extern volatile CANBTR0STR _CANBTR0 @(REG_BASE + 0x00000142UL);
#define CANBTR0                         _CANBTR0.Byte
#define CANBTR0_BRP0                    _CANBTR0.Bits.BRP0
#define CANBTR0_BRP1                    _CANBTR0.Bits.BRP1
#define CANBTR0_BRP2                    _CANBTR0.Bits.BRP2
#define CANBTR0_BRP3                    _CANBTR0.Bits.BRP3
#define CANBTR0_BRP4                    _CANBTR0.Bits.BRP4
#define CANBTR0_BRP5                    _CANBTR0.Bits.BRP5
#define CANBTR0_SJW0                    _CANBTR0.Bits.SJW0
#define CANBTR0_SJW1                    _CANBTR0.Bits.SJW1
/* CANBTR_ARR: Access 2 CANBTRx registers in an array */
#define CANBTR_ARR                      ((volatile byte *) &CANBTR0)
#define CANBTR0_BRP                     _CANBTR0.MergedBits.grpBRP
#define CANBTR0_SJW                     _CANBTR0.MergedBits.grpSJW

#define CANBTR0_BRP0_MASK               1U
#define CANBTR0_BRP1_MASK               2U
#define CANBTR0_BRP2_MASK               4U
#define CANBTR0_BRP3_MASK               8U
#define CANBTR0_BRP4_MASK               16U
#define CANBTR0_BRP5_MASK               32U
#define CANBTR0_SJW0_MASK               64U
#define CANBTR0_SJW1_MASK               128U
#define CANBTR0_BRP_MASK                63U
#define CANBTR0_BRP_BITNUM              0U
#define CANBTR0_SJW_MASK                192U
#define CANBTR0_SJW_BITNUM              6U


/*** CANBTR1 - MSCAN Bus Timing Register 1; 0x00000143 ***/
typedef union {
  byte Byte;
  struct {
    byte TSEG10      :1;                                       /* Time Segment 10 */
    byte TSEG11      :1;                                       /* Time Segment 11 */
    byte TSEG12      :1;                                       /* Time Segment 12 */
    byte TSEG13      :1;                                       /* Time Segment 13 */
    byte TSEG20      :1;                                       /* Time Segment 20 */
    byte TSEG21      :1;                                       /* Time Segment 21 */
    byte TSEG22      :1;                                       /* Time Segment 22 */
    byte SAMP        :1;                                       /* Sampling */
  } Bits;
  struct {
    byte grpTSEG_10 :4;
    byte grpTSEG_20 :3;
    byte         :1;
  } MergedBits;
} CANBTR1STR;
extern volatile CANBTR1STR _CANBTR1 @(REG_BASE + 0x00000143UL);
#define CANBTR1                         _CANBTR1.Byte
#define CANBTR1_TSEG10                  _CANBTR1.Bits.TSEG10
#define CANBTR1_TSEG11                  _CANBTR1.Bits.TSEG11
#define CANBTR1_TSEG12                  _CANBTR1.Bits.TSEG12
#define CANBTR1_TSEG13                  _CANBTR1.Bits.TSEG13
#define CANBTR1_TSEG20                  _CANBTR1.Bits.TSEG20
#define CANBTR1_TSEG21                  _CANBTR1.Bits.TSEG21
#define CANBTR1_TSEG22                  _CANBTR1.Bits.TSEG22
#define CANBTR1_SAMP                    _CANBTR1.Bits.SAMP
#define CANBTR1_TSEG_10                 _CANBTR1.MergedBits.grpTSEG_10
#define CANBTR1_TSEG_20                 _CANBTR1.MergedBits.grpTSEG_20
#define CANBTR1_TSEG                    CANBTR1_TSEG_10

#define CANBTR1_TSEG10_MASK             1U
#define CANBTR1_TSEG11_MASK             2U
#define CANBTR1_TSEG12_MASK             4U
#define CANBTR1_TSEG13_MASK             8U
#define CANBTR1_TSEG20_MASK             16U
#define CANBTR1_TSEG21_MASK             32U
#define CANBTR1_TSEG22_MASK             64U
#define CANBTR1_SAMP_MASK               128U
#define CANBTR1_TSEG_10_MASK            15U
#define CANBTR1_TSEG_10_BITNUM          0U
#define CANBTR1_TSEG_20_MASK            112U
#define CANBTR1_TSEG_20_BITNUM          4U


/*** CANRFLG - MSCAN Receiver Flag Register; 0x00000144 ***/
typedef union {
  byte Byte;
  struct {
    byte RXF         :1;                                       /* Receive Buffer Full */
    byte OVRIF       :1;                                       /* Overrun Interrupt Flag */
    byte TSTAT0      :1;                                       /* Transmitter Status Bit 0 */
    byte TSTAT1      :1;                                       /* Transmitter Status Bit 1 */
    byte RSTAT0      :1;                                       /* Receiver Status Bit 0 */
    byte RSTAT1      :1;                                       /* Receiver Status Bit 1 */
    byte CSCIF       :1;                                       /* CAN Status Change Interrupt Flag */
    byte WUPIF       :1;                                       /* Wake-up Interrupt Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTSTAT :2;
    byte grpRSTAT :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRFLGSTR;
extern volatile CANRFLGSTR _CANRFLG @(REG_BASE + 0x00000144UL);
#define CANRFLG                         _CANRFLG.Byte
#define CANRFLG_RXF                     _CANRFLG.Bits.RXF
#define CANRFLG_OVRIF                   _CANRFLG.Bits.OVRIF
#define CANRFLG_TSTAT0                  _CANRFLG.Bits.TSTAT0
#define CANRFLG_TSTAT1                  _CANRFLG.Bits.TSTAT1
#define CANRFLG_RSTAT0                  _CANRFLG.Bits.RSTAT0
#define CANRFLG_RSTAT1                  _CANRFLG.Bits.RSTAT1
#define CANRFLG_CSCIF                   _CANRFLG.Bits.CSCIF
#define CANRFLG_WUPIF                   _CANRFLG.Bits.WUPIF
#define CANRFLG_TSTAT                   _CANRFLG.MergedBits.grpTSTAT
#define CANRFLG_RSTAT                   _CANRFLG.MergedBits.grpRSTAT

#define CANRFLG_RXF_MASK                1U
#define CANRFLG_OVRIF_MASK              2U
#define CANRFLG_TSTAT0_MASK             4U
#define CANRFLG_TSTAT1_MASK             8U
#define CANRFLG_RSTAT0_MASK             16U
#define CANRFLG_RSTAT1_MASK             32U
#define CANRFLG_CSCIF_MASK              64U
#define CANRFLG_WUPIF_MASK              128U
#define CANRFLG_TSTAT_MASK              12U
#define CANRFLG_TSTAT_BITNUM            2U
#define CANRFLG_RSTAT_MASK              48U
#define CANRFLG_RSTAT_BITNUM            4U


/*** CANRIER - MSCAN Receiver Interrupt Enable Register; 0x00000145 ***/
typedef union {
  byte Byte;
  struct {
    byte RXFIE       :1;                                       /* Receiver Full Interrupt Enable */
    byte OVRIE       :1;                                       /* Overrun Interrupt Enable */
    byte TSTATE0     :1;                                       /* Transmitter Status Change Enable 0 */
    byte TSTATE1     :1;                                       /* Transmitter Status Change Enable 1 */
    byte RSTATE0     :1;                                       /* Receiver Status Change Enable 0 */
    byte RSTATE1     :1;                                       /* Receiver Status Change Enable 1 */
    byte CSCIE       :1;                                       /* CAN Status Change Interrupt Enable */
    byte WUPIE       :1;                                       /* Wake-up Interrupt Enable */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTSTATE :2;
    byte grpRSTATE :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRIERSTR;
extern volatile CANRIERSTR _CANRIER @(REG_BASE + 0x00000145UL);
#define CANRIER                         _CANRIER.Byte
#define CANRIER_RXFIE                   _CANRIER.Bits.RXFIE
#define CANRIER_OVRIE                   _CANRIER.Bits.OVRIE
#define CANRIER_TSTATE0                 _CANRIER.Bits.TSTATE0
#define CANRIER_TSTATE1                 _CANRIER.Bits.TSTATE1
#define CANRIER_RSTATE0                 _CANRIER.Bits.RSTATE0
#define CANRIER_RSTATE1                 _CANRIER.Bits.RSTATE1
#define CANRIER_CSCIE                   _CANRIER.Bits.CSCIE
#define CANRIER_WUPIE                   _CANRIER.Bits.WUPIE
#define CANRIER_TSTATE                  _CANRIER.MergedBits.grpTSTATE
#define CANRIER_RSTATE                  _CANRIER.MergedBits.grpRSTATE

#define CANRIER_RXFIE_MASK              1U
#define CANRIER_OVRIE_MASK              2U
#define CANRIER_TSTATE0_MASK            4U
#define CANRIER_TSTATE1_MASK            8U
#define CANRIER_RSTATE0_MASK            16U
#define CANRIER_RSTATE1_MASK            32U
#define CANRIER_CSCIE_MASK              64U
#define CANRIER_WUPIE_MASK              128U
#define CANRIER_TSTATE_MASK             12U
#define CANRIER_TSTATE_BITNUM           2U
#define CANRIER_RSTATE_MASK             48U
#define CANRIER_RSTATE_BITNUM           4U


/*** CANTFLG - MSCAN Transmitter Flag Register; 0x00000146 ***/
typedef union {
  byte Byte;
  struct {
    byte TXE0        :1;                                       /* Transmitter Buffer Empty 0 */
    byte TXE1        :1;                                       /* Transmitter Buffer Empty 1 */
    byte TXE2        :1;                                       /* Transmitter Buffer Empty 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTXE  :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTFLGSTR;
extern volatile CANTFLGSTR _CANTFLG @(REG_BASE + 0x00000146UL);
#define CANTFLG                         _CANTFLG.Byte
#define CANTFLG_TXE0                    _CANTFLG.Bits.TXE0
#define CANTFLG_TXE1                    _CANTFLG.Bits.TXE1
#define CANTFLG_TXE2                    _CANTFLG.Bits.TXE2
#define CANTFLG_TXE                     _CANTFLG.MergedBits.grpTXE

#define CANTFLG_TXE0_MASK               1U
#define CANTFLG_TXE1_MASK               2U
#define CANTFLG_TXE2_MASK               4U
#define CANTFLG_TXE_MASK                7U
#define CANTFLG_TXE_BITNUM              0U


/*** CANTIER - MSCAN Transmitter Interrupt Enable Register; 0x00000147 ***/
typedef union {
  byte Byte;
  struct {
    byte TXEIE0      :1;                                       /* Transmitter Empty Interrupt Enable 0 */
    byte TXEIE1      :1;                                       /* Transmitter Empty Interrupt Enable 1 */
    byte TXEIE2      :1;                                       /* Transmitter Empty Interrupt Enable 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTXEIE :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTIERSTR;
extern volatile CANTIERSTR _CANTIER @(REG_BASE + 0x00000147UL);
#define CANTIER                         _CANTIER.Byte
#define CANTIER_TXEIE0                  _CANTIER.Bits.TXEIE0
#define CANTIER_TXEIE1                  _CANTIER.Bits.TXEIE1
#define CANTIER_TXEIE2                  _CANTIER.Bits.TXEIE2
#define CANTIER_TXEIE                   _CANTIER.MergedBits.grpTXEIE

#define CANTIER_TXEIE0_MASK             1U
#define CANTIER_TXEIE1_MASK             2U
#define CANTIER_TXEIE2_MASK             4U
#define CANTIER_TXEIE_MASK              7U
#define CANTIER_TXEIE_BITNUM            0U


/*** CANTARQ - MSCAN Transmitter Message Abort Request; 0x00000148 ***/
typedef union {
  byte Byte;
  struct {
    byte ABTRQ0      :1;                                       /* Abort Request 0 */
    byte ABTRQ1      :1;                                       /* Abort Request 1 */
    byte ABTRQ2      :1;                                       /* Abort Request 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpABTRQ :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTARQSTR;
extern volatile CANTARQSTR _CANTARQ @(REG_BASE + 0x00000148UL);
#define CANTARQ                         _CANTARQ.Byte
#define CANTARQ_ABTRQ0                  _CANTARQ.Bits.ABTRQ0
#define CANTARQ_ABTRQ1                  _CANTARQ.Bits.ABTRQ1
#define CANTARQ_ABTRQ2                  _CANTARQ.Bits.ABTRQ2
#define CANTARQ_ABTRQ                   _CANTARQ.MergedBits.grpABTRQ

#define CANTARQ_ABTRQ0_MASK             1U
#define CANTARQ_ABTRQ1_MASK             2U
#define CANTARQ_ABTRQ2_MASK             4U
#define CANTARQ_ABTRQ_MASK              7U
#define CANTARQ_ABTRQ_BITNUM            0U


/*** CANTAAK - MSCAN Transmitter Message Abort Control; 0x00000149 ***/
typedef union {
  byte Byte;
  struct {
    byte ABTAK0      :1;                                       /* Abort Acknowledge 0 */
    byte ABTAK1      :1;                                       /* Abort Acknowledge 1 */
    byte ABTAK2      :1;                                       /* Abort Acknowledge 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpABTAK :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTAAKSTR;
extern volatile CANTAAKSTR _CANTAAK @(REG_BASE + 0x00000149UL);
#define CANTAAK                         _CANTAAK.Byte
#define CANTAAK_ABTAK0                  _CANTAAK.Bits.ABTAK0
#define CANTAAK_ABTAK1                  _CANTAAK.Bits.ABTAK1
#define CANTAAK_ABTAK2                  _CANTAAK.Bits.ABTAK2
#define CANTAAK_ABTAK                   _CANTAAK.MergedBits.grpABTAK

#define CANTAAK_ABTAK0_MASK             1U
#define CANTAAK_ABTAK1_MASK             2U
#define CANTAAK_ABTAK2_MASK             4U
#define CANTAAK_ABTAK_MASK              7U
#define CANTAAK_ABTAK_BITNUM            0U


/*** CANTBSEL - MSCAN Transmit Buffer Selection; 0x0000014A ***/
typedef union {
  byte Byte;
  struct {
    byte TX0         :1;                                       /* Transmit Buffer Select 0 */
    byte TX1         :1;                                       /* Transmit Buffer Select 1 */
    byte TX2         :1;                                       /* Transmit Buffer Select 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTX   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTBSELSTR;
extern volatile CANTBSELSTR _CANTBSEL @(REG_BASE + 0x0000014AUL);
#define CANTBSEL                        _CANTBSEL.Byte
#define CANTBSEL_TX0                    _CANTBSEL.Bits.TX0
#define CANTBSEL_TX1                    _CANTBSEL.Bits.TX1
#define CANTBSEL_TX2                    _CANTBSEL.Bits.TX2
#define CANTBSEL_TX                     _CANTBSEL.MergedBits.grpTX

#define CANTBSEL_TX0_MASK               1U
#define CANTBSEL_TX1_MASK               2U
#define CANTBSEL_TX2_MASK               4U
#define CANTBSEL_TX_MASK                7U
#define CANTBSEL_TX_BITNUM              0U


/*** CANIDAC - MSCAN Identifier Acceptance Control Register; 0x0000014B ***/
typedef union {
  byte Byte;
  struct {
    byte IDHIT0      :1;                                       /* Identifier Acceptance Hit Indicator 0 */
    byte IDHIT1      :1;                                       /* Identifier Acceptance Hit Indicator 1 */
    byte IDHIT2      :1;                                       /* Identifier Acceptance Hit Indicator 2 */
    byte             :1; 
    byte IDAM0       :1;                                       /* Identifier Acceptance Mode 0 */
    byte IDAM1       :1;                                       /* Identifier Acceptance Mode 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpIDHIT :3;
    byte         :1;
    byte grpIDAM :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANIDACSTR;
extern volatile CANIDACSTR _CANIDAC @(REG_BASE + 0x0000014BUL);
#define CANIDAC                         _CANIDAC.Byte
#define CANIDAC_IDHIT0                  _CANIDAC.Bits.IDHIT0
#define CANIDAC_IDHIT1                  _CANIDAC.Bits.IDHIT1
#define CANIDAC_IDHIT2                  _CANIDAC.Bits.IDHIT2
#define CANIDAC_IDAM0                   _CANIDAC.Bits.IDAM0
#define CANIDAC_IDAM1                   _CANIDAC.Bits.IDAM1
#define CANIDAC_IDHIT                   _CANIDAC.MergedBits.grpIDHIT
#define CANIDAC_IDAM                    _CANIDAC.MergedBits.grpIDAM

#define CANIDAC_IDHIT0_MASK             1U
#define CANIDAC_IDHIT1_MASK             2U
#define CANIDAC_IDHIT2_MASK             4U
#define CANIDAC_IDAM0_MASK              16U
#define CANIDAC_IDAM1_MASK              32U
#define CANIDAC_IDHIT_MASK              7U
#define CANIDAC_IDHIT_BITNUM            0U
#define CANIDAC_IDAM_MASK               48U
#define CANIDAC_IDAM_BITNUM             4U


/*** CANRXERR - MSCAN Receive Error Counter Register; 0x0000014E ***/
typedef union {
  byte Byte;
  struct {
    byte RXERR0      :1;                                       /* Bit 0 */
    byte RXERR1      :1;                                       /* Bit 1 */
    byte RXERR2      :1;                                       /* Bit 2 */
    byte RXERR3      :1;                                       /* Bit 3 */
    byte RXERR4      :1;                                       /* Bit 4 */
    byte RXERR5      :1;                                       /* Bit 5 */
    byte RXERR6      :1;                                       /* Bit 6 */
    byte RXERR7      :1;                                       /* Bit 7 */
  } Bits;
} CANRXERRSTR;
extern volatile CANRXERRSTR _CANRXERR @(REG_BASE + 0x0000014EUL);
#define CANRXERR                        _CANRXERR.Byte
#define CANRXERR_RXERR0                 _CANRXERR.Bits.RXERR0
#define CANRXERR_RXERR1                 _CANRXERR.Bits.RXERR1
#define CANRXERR_RXERR2                 _CANRXERR.Bits.RXERR2
#define CANRXERR_RXERR3                 _CANRXERR.Bits.RXERR3
#define CANRXERR_RXERR4                 _CANRXERR.Bits.RXERR4
#define CANRXERR_RXERR5                 _CANRXERR.Bits.RXERR5
#define CANRXERR_RXERR6                 _CANRXERR.Bits.RXERR6
#define CANRXERR_RXERR7                 _CANRXERR.Bits.RXERR7

#define CANRXERR_RXERR0_MASK            1U
#define CANRXERR_RXERR1_MASK            2U
#define CANRXERR_RXERR2_MASK            4U
#define CANRXERR_RXERR3_MASK            8U
#define CANRXERR_RXERR4_MASK            16U
#define CANRXERR_RXERR5_MASK            32U
#define CANRXERR_RXERR6_MASK            64U
#define CANRXERR_RXERR7_MASK            128U


/*** CANTXERR - MSCAN Transmit Error Counter Register; 0x0000014F ***/
typedef union {
  byte Byte;
  struct {
    byte TXERR0      :1;                                       /* Bit 0 */
    byte TXERR1      :1;                                       /* Bit 1 */
    byte TXERR2      :1;                                       /* Bit 2 */
    byte TXERR3      :1;                                       /* Bit 3 */
    byte TXERR4      :1;                                       /* Bit 4 */
    byte TXERR5      :1;                                       /* Bit 5 */
    byte TXERR6      :1;                                       /* Bit 6 */
    byte TXERR7      :1;                                       /* Bit 7 */
  } Bits;
} CANTXERRSTR;
extern volatile CANTXERRSTR _CANTXERR @(REG_BASE + 0x0000014FUL);
#define CANTXERR                        _CANTXERR.Byte
#define CANTXERR_TXERR0                 _CANTXERR.Bits.TXERR0
#define CANTXERR_TXERR1                 _CANTXERR.Bits.TXERR1
#define CANTXERR_TXERR2                 _CANTXERR.Bits.TXERR2
#define CANTXERR_TXERR3                 _CANTXERR.Bits.TXERR3
#define CANTXERR_TXERR4                 _CANTXERR.Bits.TXERR4
#define CANTXERR_TXERR5                 _CANTXERR.Bits.TXERR5
#define CANTXERR_TXERR6                 _CANTXERR.Bits.TXERR6
#define CANTXERR_TXERR7                 _CANTXERR.Bits.TXERR7

#define CANTXERR_TXERR0_MASK            1U
#define CANTXERR_TXERR1_MASK            2U
#define CANTXERR_TXERR2_MASK            4U
#define CANTXERR_TXERR3_MASK            8U
#define CANTXERR_TXERR4_MASK            16U
#define CANTXERR_TXERR5_MASK            32U
#define CANTXERR_TXERR6_MASK            64U
#define CANTXERR_TXERR7_MASK            128U


/*** CANIDAR0 - MSCAN Identifier Acceptance Register 0; 0x00000150 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR0STR;
extern volatile CANIDAR0STR _CANIDAR0 @(REG_BASE + 0x00000150UL);
#define CANIDAR0                        _CANIDAR0.Byte
#define CANIDAR0_AC0                    _CANIDAR0.Bits.AC0
#define CANIDAR0_AC1                    _CANIDAR0.Bits.AC1
#define CANIDAR0_AC2                    _CANIDAR0.Bits.AC2
#define CANIDAR0_AC3                    _CANIDAR0.Bits.AC3
#define CANIDAR0_AC4                    _CANIDAR0.Bits.AC4
#define CANIDAR0_AC5                    _CANIDAR0.Bits.AC5
#define CANIDAR0_AC6                    _CANIDAR0.Bits.AC6
#define CANIDAR0_AC7                    _CANIDAR0.Bits.AC7
/* CANIDAR_ARR: Access 4 CANIDARx registers in an array */
#define CANIDAR_ARR                     ((volatile byte *) &CANIDAR0)

#define CANIDAR0_AC0_MASK               1U
#define CANIDAR0_AC1_MASK               2U
#define CANIDAR0_AC2_MASK               4U
#define CANIDAR0_AC3_MASK               8U
#define CANIDAR0_AC4_MASK               16U
#define CANIDAR0_AC5_MASK               32U
#define CANIDAR0_AC6_MASK               64U
#define CANIDAR0_AC7_MASK               128U


/*** CANIDAR1 - MSCAN Identifier Acceptance Register 1; 0x00000151 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR1STR;
extern volatile CANIDAR1STR _CANIDAR1 @(REG_BASE + 0x00000151UL);
#define CANIDAR1                        _CANIDAR1.Byte
#define CANIDAR1_AC0                    _CANIDAR1.Bits.AC0
#define CANIDAR1_AC1                    _CANIDAR1.Bits.AC1
#define CANIDAR1_AC2                    _CANIDAR1.Bits.AC2
#define CANIDAR1_AC3                    _CANIDAR1.Bits.AC3
#define CANIDAR1_AC4                    _CANIDAR1.Bits.AC4
#define CANIDAR1_AC5                    _CANIDAR1.Bits.AC5
#define CANIDAR1_AC6                    _CANIDAR1.Bits.AC6
#define CANIDAR1_AC7                    _CANIDAR1.Bits.AC7

#define CANIDAR1_AC0_MASK               1U
#define CANIDAR1_AC1_MASK               2U
#define CANIDAR1_AC2_MASK               4U
#define CANIDAR1_AC3_MASK               8U
#define CANIDAR1_AC4_MASK               16U
#define CANIDAR1_AC5_MASK               32U
#define CANIDAR1_AC6_MASK               64U
#define CANIDAR1_AC7_MASK               128U


/*** CANIDAR2 - MSCAN Identifier Acceptance Register 2; 0x00000152 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR2STR;
extern volatile CANIDAR2STR _CANIDAR2 @(REG_BASE + 0x00000152UL);
#define CANIDAR2                        _CANIDAR2.Byte
#define CANIDAR2_AC0                    _CANIDAR2.Bits.AC0
#define CANIDAR2_AC1                    _CANIDAR2.Bits.AC1
#define CANIDAR2_AC2                    _CANIDAR2.Bits.AC2
#define CANIDAR2_AC3                    _CANIDAR2.Bits.AC3
#define CANIDAR2_AC4                    _CANIDAR2.Bits.AC4
#define CANIDAR2_AC5                    _CANIDAR2.Bits.AC5
#define CANIDAR2_AC6                    _CANIDAR2.Bits.AC6
#define CANIDAR2_AC7                    _CANIDAR2.Bits.AC7

#define CANIDAR2_AC0_MASK               1U
#define CANIDAR2_AC1_MASK               2U
#define CANIDAR2_AC2_MASK               4U
#define CANIDAR2_AC3_MASK               8U
#define CANIDAR2_AC4_MASK               16U
#define CANIDAR2_AC5_MASK               32U
#define CANIDAR2_AC6_MASK               64U
#define CANIDAR2_AC7_MASK               128U


/*** CANIDAR3 - MSCAN Identifier Acceptance Register 3; 0x00000153 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR3STR;
extern volatile CANIDAR3STR _CANIDAR3 @(REG_BASE + 0x00000153UL);
#define CANIDAR3                        _CANIDAR3.Byte
#define CANIDAR3_AC0                    _CANIDAR3.Bits.AC0
#define CANIDAR3_AC1                    _CANIDAR3.Bits.AC1
#define CANIDAR3_AC2                    _CANIDAR3.Bits.AC2
#define CANIDAR3_AC3                    _CANIDAR3.Bits.AC3
#define CANIDAR3_AC4                    _CANIDAR3.Bits.AC4
#define CANIDAR3_AC5                    _CANIDAR3.Bits.AC5
#define CANIDAR3_AC6                    _CANIDAR3.Bits.AC6
#define CANIDAR3_AC7                    _CANIDAR3.Bits.AC7

#define CANIDAR3_AC0_MASK               1U
#define CANIDAR3_AC1_MASK               2U
#define CANIDAR3_AC2_MASK               4U
#define CANIDAR3_AC3_MASK               8U
#define CANIDAR3_AC4_MASK               16U
#define CANIDAR3_AC5_MASK               32U
#define CANIDAR3_AC6_MASK               64U
#define CANIDAR3_AC7_MASK               128U


/*** CANIDMR0 - MSCAN Identifier Mask Register 0; 0x00000154 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR0STR;
extern volatile CANIDMR0STR _CANIDMR0 @(REG_BASE + 0x00000154UL);
#define CANIDMR0                        _CANIDMR0.Byte
#define CANIDMR0_AM0                    _CANIDMR0.Bits.AM0
#define CANIDMR0_AM1                    _CANIDMR0.Bits.AM1
#define CANIDMR0_AM2                    _CANIDMR0.Bits.AM2
#define CANIDMR0_AM3                    _CANIDMR0.Bits.AM3
#define CANIDMR0_AM4                    _CANIDMR0.Bits.AM4
#define CANIDMR0_AM5                    _CANIDMR0.Bits.AM5
#define CANIDMR0_AM6                    _CANIDMR0.Bits.AM6
#define CANIDMR0_AM7                    _CANIDMR0.Bits.AM7
/* CANIDMR_ARR: Access 4 CANIDMRx registers in an array */
#define CANIDMR_ARR                     ((volatile byte *) &CANIDMR0)

#define CANIDMR0_AM0_MASK               1U
#define CANIDMR0_AM1_MASK               2U
#define CANIDMR0_AM2_MASK               4U
#define CANIDMR0_AM3_MASK               8U
#define CANIDMR0_AM4_MASK               16U
#define CANIDMR0_AM5_MASK               32U
#define CANIDMR0_AM6_MASK               64U
#define CANIDMR0_AM7_MASK               128U


/*** CANIDMR1 - MSCAN Identifier Mask Register 1; 0x00000155 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR1STR;
extern volatile CANIDMR1STR _CANIDMR1 @(REG_BASE + 0x00000155UL);
#define CANIDMR1                        _CANIDMR1.Byte
#define CANIDMR1_AM0                    _CANIDMR1.Bits.AM0
#define CANIDMR1_AM1                    _CANIDMR1.Bits.AM1
#define CANIDMR1_AM2                    _CANIDMR1.Bits.AM2
#define CANIDMR1_AM3                    _CANIDMR1.Bits.AM3
#define CANIDMR1_AM4                    _CANIDMR1.Bits.AM4
#define CANIDMR1_AM5                    _CANIDMR1.Bits.AM5
#define CANIDMR1_AM6                    _CANIDMR1.Bits.AM6
#define CANIDMR1_AM7                    _CANIDMR1.Bits.AM7

#define CANIDMR1_AM0_MASK               1U
#define CANIDMR1_AM1_MASK               2U
#define CANIDMR1_AM2_MASK               4U
#define CANIDMR1_AM3_MASK               8U
#define CANIDMR1_AM4_MASK               16U
#define CANIDMR1_AM5_MASK               32U
#define CANIDMR1_AM6_MASK               64U
#define CANIDMR1_AM7_MASK               128U


/*** CANIDMR2 - MSCAN Identifier Mask Register 2; 0x00000156 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR2STR;
extern volatile CANIDMR2STR _CANIDMR2 @(REG_BASE + 0x00000156UL);
#define CANIDMR2                        _CANIDMR2.Byte
#define CANIDMR2_AM0                    _CANIDMR2.Bits.AM0
#define CANIDMR2_AM1                    _CANIDMR2.Bits.AM1
#define CANIDMR2_AM2                    _CANIDMR2.Bits.AM2
#define CANIDMR2_AM3                    _CANIDMR2.Bits.AM3
#define CANIDMR2_AM4                    _CANIDMR2.Bits.AM4
#define CANIDMR2_AM5                    _CANIDMR2.Bits.AM5
#define CANIDMR2_AM6                    _CANIDMR2.Bits.AM6
#define CANIDMR2_AM7                    _CANIDMR2.Bits.AM7

#define CANIDMR2_AM0_MASK               1U
#define CANIDMR2_AM1_MASK               2U
#define CANIDMR2_AM2_MASK               4U
#define CANIDMR2_AM3_MASK               8U
#define CANIDMR2_AM4_MASK               16U
#define CANIDMR2_AM5_MASK               32U
#define CANIDMR2_AM6_MASK               64U
#define CANIDMR2_AM7_MASK               128U


/*** CANIDMR3 - MSCAN Identifier Mask Register 3; 0x00000157 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR3STR;
extern volatile CANIDMR3STR _CANIDMR3 @(REG_BASE + 0x00000157UL);
#define CANIDMR3                        _CANIDMR3.Byte
#define CANIDMR3_AM0                    _CANIDMR3.Bits.AM0
#define CANIDMR3_AM1                    _CANIDMR3.Bits.AM1
#define CANIDMR3_AM2                    _CANIDMR3.Bits.AM2
#define CANIDMR3_AM3                    _CANIDMR3.Bits.AM3
#define CANIDMR3_AM4                    _CANIDMR3.Bits.AM4
#define CANIDMR3_AM5                    _CANIDMR3.Bits.AM5
#define CANIDMR3_AM6                    _CANIDMR3.Bits.AM6
#define CANIDMR3_AM7                    _CANIDMR3.Bits.AM7

#define CANIDMR3_AM0_MASK               1U
#define CANIDMR3_AM1_MASK               2U
#define CANIDMR3_AM2_MASK               4U
#define CANIDMR3_AM3_MASK               8U
#define CANIDMR3_AM4_MASK               16U
#define CANIDMR3_AM5_MASK               32U
#define CANIDMR3_AM6_MASK               64U
#define CANIDMR3_AM7_MASK               128U


/*** CANIDAR4 - MSCAN Identifier Acceptance Register 4; 0x00000158 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR4STR;
extern volatile CANIDAR4STR _CANIDAR4 @(REG_BASE + 0x00000158UL);
#define CANIDAR4                        _CANIDAR4.Byte
#define CANIDAR4_AC0                    _CANIDAR4.Bits.AC0
#define CANIDAR4_AC1                    _CANIDAR4.Bits.AC1
#define CANIDAR4_AC2                    _CANIDAR4.Bits.AC2
#define CANIDAR4_AC3                    _CANIDAR4.Bits.AC3
#define CANIDAR4_AC4                    _CANIDAR4.Bits.AC4
#define CANIDAR4_AC5                    _CANIDAR4.Bits.AC5
#define CANIDAR4_AC6                    _CANIDAR4.Bits.AC6
#define CANIDAR4_AC7                    _CANIDAR4.Bits.AC7

#define CANIDAR4_AC0_MASK               1U
#define CANIDAR4_AC1_MASK               2U
#define CANIDAR4_AC2_MASK               4U
#define CANIDAR4_AC3_MASK               8U
#define CANIDAR4_AC4_MASK               16U
#define CANIDAR4_AC5_MASK               32U
#define CANIDAR4_AC6_MASK               64U
#define CANIDAR4_AC7_MASK               128U


/*** CANIDAR5 - MSCAN Identifier Acceptance Register 5; 0x00000159 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR5STR;
extern volatile CANIDAR5STR _CANIDAR5 @(REG_BASE + 0x00000159UL);
#define CANIDAR5                        _CANIDAR5.Byte
#define CANIDAR5_AC0                    _CANIDAR5.Bits.AC0
#define CANIDAR5_AC1                    _CANIDAR5.Bits.AC1
#define CANIDAR5_AC2                    _CANIDAR5.Bits.AC2
#define CANIDAR5_AC3                    _CANIDAR5.Bits.AC3
#define CANIDAR5_AC4                    _CANIDAR5.Bits.AC4
#define CANIDAR5_AC5                    _CANIDAR5.Bits.AC5
#define CANIDAR5_AC6                    _CANIDAR5.Bits.AC6
#define CANIDAR5_AC7                    _CANIDAR5.Bits.AC7

#define CANIDAR5_AC0_MASK               1U
#define CANIDAR5_AC1_MASK               2U
#define CANIDAR5_AC2_MASK               4U
#define CANIDAR5_AC3_MASK               8U
#define CANIDAR5_AC4_MASK               16U
#define CANIDAR5_AC5_MASK               32U
#define CANIDAR5_AC6_MASK               64U
#define CANIDAR5_AC7_MASK               128U


/*** CANIDAR6 - MSCAN Identifier Acceptance Register 6; 0x0000015A ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR6STR;
extern volatile CANIDAR6STR _CANIDAR6 @(REG_BASE + 0x0000015AUL);
#define CANIDAR6                        _CANIDAR6.Byte
#define CANIDAR6_AC0                    _CANIDAR6.Bits.AC0
#define CANIDAR6_AC1                    _CANIDAR6.Bits.AC1
#define CANIDAR6_AC2                    _CANIDAR6.Bits.AC2
#define CANIDAR6_AC3                    _CANIDAR6.Bits.AC3
#define CANIDAR6_AC4                    _CANIDAR6.Bits.AC4
#define CANIDAR6_AC5                    _CANIDAR6.Bits.AC5
#define CANIDAR6_AC6                    _CANIDAR6.Bits.AC6
#define CANIDAR6_AC7                    _CANIDAR6.Bits.AC7

#define CANIDAR6_AC0_MASK               1U
#define CANIDAR6_AC1_MASK               2U
#define CANIDAR6_AC2_MASK               4U
#define CANIDAR6_AC3_MASK               8U
#define CANIDAR6_AC4_MASK               16U
#define CANIDAR6_AC5_MASK               32U
#define CANIDAR6_AC6_MASK               64U
#define CANIDAR6_AC7_MASK               128U


/*** CANIDAR7 - MSCAN Identifier Acceptance Register 7; 0x0000015B ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR7STR;
extern volatile CANIDAR7STR _CANIDAR7 @(REG_BASE + 0x0000015BUL);
#define CANIDAR7                        _CANIDAR7.Byte
#define CANIDAR7_AC0                    _CANIDAR7.Bits.AC0
#define CANIDAR7_AC1                    _CANIDAR7.Bits.AC1
#define CANIDAR7_AC2                    _CANIDAR7.Bits.AC2
#define CANIDAR7_AC3                    _CANIDAR7.Bits.AC3
#define CANIDAR7_AC4                    _CANIDAR7.Bits.AC4
#define CANIDAR7_AC5                    _CANIDAR7.Bits.AC5
#define CANIDAR7_AC6                    _CANIDAR7.Bits.AC6
#define CANIDAR7_AC7                    _CANIDAR7.Bits.AC7

#define CANIDAR7_AC0_MASK               1U
#define CANIDAR7_AC1_MASK               2U
#define CANIDAR7_AC2_MASK               4U
#define CANIDAR7_AC3_MASK               8U
#define CANIDAR7_AC4_MASK               16U
#define CANIDAR7_AC5_MASK               32U
#define CANIDAR7_AC6_MASK               64U
#define CANIDAR7_AC7_MASK               128U


/*** CANIDMR4 - MSCAN Identifier Mask Register 4; 0x0000015C ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR4STR;
extern volatile CANIDMR4STR _CANIDMR4 @(REG_BASE + 0x0000015CUL);
#define CANIDMR4                        _CANIDMR4.Byte
#define CANIDMR4_AM0                    _CANIDMR4.Bits.AM0
#define CANIDMR4_AM1                    _CANIDMR4.Bits.AM1
#define CANIDMR4_AM2                    _CANIDMR4.Bits.AM2
#define CANIDMR4_AM3                    _CANIDMR4.Bits.AM3
#define CANIDMR4_AM4                    _CANIDMR4.Bits.AM4
#define CANIDMR4_AM5                    _CANIDMR4.Bits.AM5
#define CANIDMR4_AM6                    _CANIDMR4.Bits.AM6
#define CANIDMR4_AM7                    _CANIDMR4.Bits.AM7

#define CANIDMR4_AM0_MASK               1U
#define CANIDMR4_AM1_MASK               2U
#define CANIDMR4_AM2_MASK               4U
#define CANIDMR4_AM3_MASK               8U
#define CANIDMR4_AM4_MASK               16U
#define CANIDMR4_AM5_MASK               32U
#define CANIDMR4_AM6_MASK               64U
#define CANIDMR4_AM7_MASK               128U


/*** CANIDMR5 - MSCAN Identifier Mask Register 5; 0x0000015D ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR5STR;
extern volatile CANIDMR5STR _CANIDMR5 @(REG_BASE + 0x0000015DUL);
#define CANIDMR5                        _CANIDMR5.Byte
#define CANIDMR5_AM0                    _CANIDMR5.Bits.AM0
#define CANIDMR5_AM1                    _CANIDMR5.Bits.AM1
#define CANIDMR5_AM2                    _CANIDMR5.Bits.AM2
#define CANIDMR5_AM3                    _CANIDMR5.Bits.AM3
#define CANIDMR5_AM4                    _CANIDMR5.Bits.AM4
#define CANIDMR5_AM5                    _CANIDMR5.Bits.AM5
#define CANIDMR5_AM6                    _CANIDMR5.Bits.AM6
#define CANIDMR5_AM7                    _CANIDMR5.Bits.AM7

#define CANIDMR5_AM0_MASK               1U
#define CANIDMR5_AM1_MASK               2U
#define CANIDMR5_AM2_MASK               4U
#define CANIDMR5_AM3_MASK               8U
#define CANIDMR5_AM4_MASK               16U
#define CANIDMR5_AM5_MASK               32U
#define CANIDMR5_AM6_MASK               64U
#define CANIDMR5_AM7_MASK               128U


/*** CANIDMR6 - MSCAN Identifier Mask Register 6; 0x0000015E ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR6STR;
extern volatile CANIDMR6STR _CANIDMR6 @(REG_BASE + 0x0000015EUL);
#define CANIDMR6                        _CANIDMR6.Byte
#define CANIDMR6_AM0                    _CANIDMR6.Bits.AM0
#define CANIDMR6_AM1                    _CANIDMR6.Bits.AM1
#define CANIDMR6_AM2                    _CANIDMR6.Bits.AM2
#define CANIDMR6_AM3                    _CANIDMR6.Bits.AM3
#define CANIDMR6_AM4                    _CANIDMR6.Bits.AM4
#define CANIDMR6_AM5                    _CANIDMR6.Bits.AM5
#define CANIDMR6_AM6                    _CANIDMR6.Bits.AM6
#define CANIDMR6_AM7                    _CANIDMR6.Bits.AM7

#define CANIDMR6_AM0_MASK               1U
#define CANIDMR6_AM1_MASK               2U
#define CANIDMR6_AM2_MASK               4U
#define CANIDMR6_AM3_MASK               8U
#define CANIDMR6_AM4_MASK               16U
#define CANIDMR6_AM5_MASK               32U
#define CANIDMR6_AM6_MASK               64U
#define CANIDMR6_AM7_MASK               128U


/*** CANIDMR7 - MSCAN Identifier Mask Register 7; 0x0000015F ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR7STR;
extern volatile CANIDMR7STR _CANIDMR7 @(REG_BASE + 0x0000015FUL);
#define CANIDMR7                        _CANIDMR7.Byte
#define CANIDMR7_AM0                    _CANIDMR7.Bits.AM0
#define CANIDMR7_AM1                    _CANIDMR7.Bits.AM1
#define CANIDMR7_AM2                    _CANIDMR7.Bits.AM2
#define CANIDMR7_AM3                    _CANIDMR7.Bits.AM3
#define CANIDMR7_AM4                    _CANIDMR7.Bits.AM4
#define CANIDMR7_AM5                    _CANIDMR7.Bits.AM5
#define CANIDMR7_AM6                    _CANIDMR7.Bits.AM6
#define CANIDMR7_AM7                    _CANIDMR7.Bits.AM7

#define CANIDMR7_AM0_MASK               1U
#define CANIDMR7_AM1_MASK               2U
#define CANIDMR7_AM2_MASK               4U
#define CANIDMR7_AM3_MASK               8U
#define CANIDMR7_AM4_MASK               16U
#define CANIDMR7_AM5_MASK               32U
#define CANIDMR7_AM6_MASK               64U
#define CANIDMR7_AM7_MASK               128U


/*** CANRXIDR0 - MSCAN Receive Identifier Register 0; 0x00000160 ***/
typedef union {
  byte Byte;
  struct {
    byte ID21        :1;                                       /* Extended format identifier Bit 21 */
    byte ID22        :1;                                       /* Extended format identifier Bit 22 */
    byte ID23        :1;                                       /* Extended format identifier Bit 23 */
    byte ID24        :1;                                       /* Extended format identifier Bit 24 */
    byte ID25        :1;                                       /* Extended format identifier Bit 25 */
    byte ID26        :1;                                       /* Extended format identifier Bit 26 */
    byte ID27        :1;                                       /* Extended format identifier Bit 27 */
    byte ID28        :1;                                       /* Extended format identifier Bit 28 */
  } Bits;
} CANRXIDR0STR;
extern volatile CANRXIDR0STR _CANRXIDR0 @(REG_BASE + 0x00000160UL);
#define CANRXIDR0                       _CANRXIDR0.Byte
#define CANRXIDR0_ID21                  _CANRXIDR0.Bits.ID21
#define CANRXIDR0_ID22                  _CANRXIDR0.Bits.ID22
#define CANRXIDR0_ID23                  _CANRXIDR0.Bits.ID23
#define CANRXIDR0_ID24                  _CANRXIDR0.Bits.ID24
#define CANRXIDR0_ID25                  _CANRXIDR0.Bits.ID25
#define CANRXIDR0_ID26                  _CANRXIDR0.Bits.ID26
#define CANRXIDR0_ID27                  _CANRXIDR0.Bits.ID27
#define CANRXIDR0_ID28                  _CANRXIDR0.Bits.ID28
/* CANRXIDR_ARR: Access 4 CANRXIDRx registers in an array */
#define CANRXIDR_ARR                    ((volatile byte *) &CANRXIDR0)

#define CANRXIDR0_ID21_MASK             1U
#define CANRXIDR0_ID22_MASK             2U
#define CANRXIDR0_ID23_MASK             4U
#define CANRXIDR0_ID24_MASK             8U
#define CANRXIDR0_ID25_MASK             16U
#define CANRXIDR0_ID26_MASK             32U
#define CANRXIDR0_ID27_MASK             64U
#define CANRXIDR0_ID28_MASK             128U


/*** CANRXIDR1 - MSCAN Receive Identifier Register 1; 0x00000161 ***/
typedef union {
  byte Byte;
  struct {
    byte ID15        :1;                                       /* Extended format identifier Bit 15 */
    byte ID16        :1;                                       /* Extended format identifier Bit 16 */
    byte ID17        :1;                                       /* Extended format identifier Bit 17 */
    byte IDE         :1;                                       /* ID Extended */
    byte SRR         :1;                                       /* Substitute Remote Request */
    byte ID18        :1;                                       /* Extended format identifier Bit 18 */
    byte ID19        :1;                                       /* Extended format identifier Bit 19 */
    byte ID20        :1;                                       /* Extended format identifier Bit 20 */
  } Bits;
  struct {
    byte grpID_15 :3;
    byte         :1;
    byte         :1;
    byte grpID_18 :3;
  } MergedBits;
} CANRXIDR1STR;
extern volatile CANRXIDR1STR _CANRXIDR1 @(REG_BASE + 0x00000161UL);
#define CANRXIDR1                       _CANRXIDR1.Byte
#define CANRXIDR1_ID15                  _CANRXIDR1.Bits.ID15
#define CANRXIDR1_ID16                  _CANRXIDR1.Bits.ID16
#define CANRXIDR1_ID17                  _CANRXIDR1.Bits.ID17
#define CANRXIDR1_IDE                   _CANRXIDR1.Bits.IDE
#define CANRXIDR1_SRR                   _CANRXIDR1.Bits.SRR
#define CANRXIDR1_ID18                  _CANRXIDR1.Bits.ID18
#define CANRXIDR1_ID19                  _CANRXIDR1.Bits.ID19
#define CANRXIDR1_ID20                  _CANRXIDR1.Bits.ID20
#define CANRXIDR1_ID_15                 _CANRXIDR1.MergedBits.grpID_15
#define CANRXIDR1_ID_18                 _CANRXIDR1.MergedBits.grpID_18
#define CANRXIDR1_ID                    CANRXIDR1_ID_15

#define CANRXIDR1_ID15_MASK             1U
#define CANRXIDR1_ID16_MASK             2U
#define CANRXIDR1_ID17_MASK             4U
#define CANRXIDR1_IDE_MASK              8U
#define CANRXIDR1_SRR_MASK              16U
#define CANRXIDR1_ID18_MASK             32U
#define CANRXIDR1_ID19_MASK             64U
#define CANRXIDR1_ID20_MASK             128U
#define CANRXIDR1_ID_15_MASK            7U
#define CANRXIDR1_ID_15_BITNUM          0U
#define CANRXIDR1_ID_18_MASK            224U
#define CANRXIDR1_ID_18_BITNUM          5U


/*** CANRXIDR2 - MSCAN Receive Identifier Register 2; 0x00000162 ***/
typedef union {
  byte Byte;
  struct {
    byte ID7         :1;                                       /* Extended format identifier Bit 7 */
    byte ID8         :1;                                       /* Extended format identifier Bit 8 */
    byte ID9         :1;                                       /* Extended format identifier Bit 9 */
    byte ID10        :1;                                       /* Extended format identifier Bit 10 */
    byte ID11        :1;                                       /* Extended format identifier Bit 11 */
    byte ID12        :1;                                       /* Extended format identifier Bit 12 */
    byte ID13        :1;                                       /* Extended format identifier Bit 13 */
    byte ID14        :1;                                       /* Extended format identifier Bit 14 */
  } Bits;
} CANRXIDR2STR;
extern volatile CANRXIDR2STR _CANRXIDR2 @(REG_BASE + 0x00000162UL);
#define CANRXIDR2                       _CANRXIDR2.Byte
#define CANRXIDR2_ID7                   _CANRXIDR2.Bits.ID7
#define CANRXIDR2_ID8                   _CANRXIDR2.Bits.ID8
#define CANRXIDR2_ID9                   _CANRXIDR2.Bits.ID9
#define CANRXIDR2_ID10                  _CANRXIDR2.Bits.ID10
#define CANRXIDR2_ID11                  _CANRXIDR2.Bits.ID11
#define CANRXIDR2_ID12                  _CANRXIDR2.Bits.ID12
#define CANRXIDR2_ID13                  _CANRXIDR2.Bits.ID13
#define CANRXIDR2_ID14                  _CANRXIDR2.Bits.ID14

#define CANRXIDR2_ID7_MASK              1U
#define CANRXIDR2_ID8_MASK              2U
#define CANRXIDR2_ID9_MASK              4U
#define CANRXIDR2_ID10_MASK             8U
#define CANRXIDR2_ID11_MASK             16U
#define CANRXIDR2_ID12_MASK             32U
#define CANRXIDR2_ID13_MASK             64U
#define CANRXIDR2_ID14_MASK             128U


/*** CANRXIDR3 - MSCAN Receive Identifier Register 3; 0x00000163 ***/
typedef union {
  byte Byte;
  struct {
    byte RTR         :1;                                       /* Remote Transmission Request */
    byte ID0         :1;                                       /* Extended format identifier Bit 0 */
    byte ID1         :1;                                       /* Extended format identifier Bit 1 */
    byte ID2         :1;                                       /* Extended format identifier Bit 2 */
    byte ID3         :1;                                       /* Extended format identifier Bit 3 */
    byte ID4         :1;                                       /* Extended format identifier Bit 4 */
    byte ID5         :1;                                       /* Extended format identifier Bit 5 */
    byte ID6         :1;                                       /* Extended format identifier Bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpID   :7;
  } MergedBits;
} CANRXIDR3STR;
extern volatile CANRXIDR3STR _CANRXIDR3 @(REG_BASE + 0x00000163UL);
#define CANRXIDR3                       _CANRXIDR3.Byte
#define CANRXIDR3_RTR                   _CANRXIDR3.Bits.RTR
#define CANRXIDR3_ID0                   _CANRXIDR3.Bits.ID0
#define CANRXIDR3_ID1                   _CANRXIDR3.Bits.ID1
#define CANRXIDR3_ID2                   _CANRXIDR3.Bits.ID2
#define CANRXIDR3_ID3                   _CANRXIDR3.Bits.ID3
#define CANRXIDR3_ID4                   _CANRXIDR3.Bits.ID4
#define CANRXIDR3_ID5                   _CANRXIDR3.Bits.ID5
#define CANRXIDR3_ID6                   _CANRXIDR3.Bits.ID6
#define CANRXIDR3_ID                    _CANRXIDR3.MergedBits.grpID

#define CANRXIDR3_RTR_MASK              1U
#define CANRXIDR3_ID0_MASK              2U
#define CANRXIDR3_ID1_MASK              4U
#define CANRXIDR3_ID2_MASK              8U
#define CANRXIDR3_ID3_MASK              16U
#define CANRXIDR3_ID4_MASK              32U
#define CANRXIDR3_ID5_MASK              64U
#define CANRXIDR3_ID6_MASK              128U
#define CANRXIDR3_ID_MASK               254U
#define CANRXIDR3_ID_BITNUM             1U


/*** CANRXDSR0 - MSCAN Receive Data Segment Register 0; 0x00000164 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR0STR;
extern volatile CANRXDSR0STR _CANRXDSR0 @(REG_BASE + 0x00000164UL);
#define CANRXDSR0                       _CANRXDSR0.Byte
#define CANRXDSR0_DB0                   _CANRXDSR0.Bits.DB0
#define CANRXDSR0_DB1                   _CANRXDSR0.Bits.DB1
#define CANRXDSR0_DB2                   _CANRXDSR0.Bits.DB2
#define CANRXDSR0_DB3                   _CANRXDSR0.Bits.DB3
#define CANRXDSR0_DB4                   _CANRXDSR0.Bits.DB4
#define CANRXDSR0_DB5                   _CANRXDSR0.Bits.DB5
#define CANRXDSR0_DB6                   _CANRXDSR0.Bits.DB6
#define CANRXDSR0_DB7                   _CANRXDSR0.Bits.DB7
/* CANRXDSR_ARR: Access 8 CANRXDSRx registers in an array */
#define CANRXDSR_ARR                    ((volatile byte *) &CANRXDSR0)

#define CANRXDSR0_DB0_MASK              1U
#define CANRXDSR0_DB1_MASK              2U
#define CANRXDSR0_DB2_MASK              4U
#define CANRXDSR0_DB3_MASK              8U
#define CANRXDSR0_DB4_MASK              16U
#define CANRXDSR0_DB5_MASK              32U
#define CANRXDSR0_DB6_MASK              64U
#define CANRXDSR0_DB7_MASK              128U


/*** CANRXDSR1 - MSCAN Receive Data Segment Register 1; 0x00000165 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR1STR;
extern volatile CANRXDSR1STR _CANRXDSR1 @(REG_BASE + 0x00000165UL);
#define CANRXDSR1                       _CANRXDSR1.Byte
#define CANRXDSR1_DB0                   _CANRXDSR1.Bits.DB0
#define CANRXDSR1_DB1                   _CANRXDSR1.Bits.DB1
#define CANRXDSR1_DB2                   _CANRXDSR1.Bits.DB2
#define CANRXDSR1_DB3                   _CANRXDSR1.Bits.DB3
#define CANRXDSR1_DB4                   _CANRXDSR1.Bits.DB4
#define CANRXDSR1_DB5                   _CANRXDSR1.Bits.DB5
#define CANRXDSR1_DB6                   _CANRXDSR1.Bits.DB6
#define CANRXDSR1_DB7                   _CANRXDSR1.Bits.DB7

#define CANRXDSR1_DB0_MASK              1U
#define CANRXDSR1_DB1_MASK              2U
#define CANRXDSR1_DB2_MASK              4U
#define CANRXDSR1_DB3_MASK              8U
#define CANRXDSR1_DB4_MASK              16U
#define CANRXDSR1_DB5_MASK              32U
#define CANRXDSR1_DB6_MASK              64U
#define CANRXDSR1_DB7_MASK              128U


/*** CANRXDSR2 - MSCAN Receive Data Segment Register 2; 0x00000166 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR2STR;
extern volatile CANRXDSR2STR _CANRXDSR2 @(REG_BASE + 0x00000166UL);
#define CANRXDSR2                       _CANRXDSR2.Byte
#define CANRXDSR2_DB0                   _CANRXDSR2.Bits.DB0
#define CANRXDSR2_DB1                   _CANRXDSR2.Bits.DB1
#define CANRXDSR2_DB2                   _CANRXDSR2.Bits.DB2
#define CANRXDSR2_DB3                   _CANRXDSR2.Bits.DB3
#define CANRXDSR2_DB4                   _CANRXDSR2.Bits.DB4
#define CANRXDSR2_DB5                   _CANRXDSR2.Bits.DB5
#define CANRXDSR2_DB6                   _CANRXDSR2.Bits.DB6
#define CANRXDSR2_DB7                   _CANRXDSR2.Bits.DB7

#define CANRXDSR2_DB0_MASK              1U
#define CANRXDSR2_DB1_MASK              2U
#define CANRXDSR2_DB2_MASK              4U
#define CANRXDSR2_DB3_MASK              8U
#define CANRXDSR2_DB4_MASK              16U
#define CANRXDSR2_DB5_MASK              32U
#define CANRXDSR2_DB6_MASK              64U
#define CANRXDSR2_DB7_MASK              128U


/*** CANRXDSR3 - MSCAN Receive Data Segment Register 3; 0x00000167 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR3STR;
extern volatile CANRXDSR3STR _CANRXDSR3 @(REG_BASE + 0x00000167UL);
#define CANRXDSR3                       _CANRXDSR3.Byte
#define CANRXDSR3_DB0                   _CANRXDSR3.Bits.DB0
#define CANRXDSR3_DB1                   _CANRXDSR3.Bits.DB1
#define CANRXDSR3_DB2                   _CANRXDSR3.Bits.DB2
#define CANRXDSR3_DB3                   _CANRXDSR3.Bits.DB3
#define CANRXDSR3_DB4                   _CANRXDSR3.Bits.DB4
#define CANRXDSR3_DB5                   _CANRXDSR3.Bits.DB5
#define CANRXDSR3_DB6                   _CANRXDSR3.Bits.DB6
#define CANRXDSR3_DB7                   _CANRXDSR3.Bits.DB7

#define CANRXDSR3_DB0_MASK              1U
#define CANRXDSR3_DB1_MASK              2U
#define CANRXDSR3_DB2_MASK              4U
#define CANRXDSR3_DB3_MASK              8U
#define CANRXDSR3_DB4_MASK              16U
#define CANRXDSR3_DB5_MASK              32U
#define CANRXDSR3_DB6_MASK              64U
#define CANRXDSR3_DB7_MASK              128U


/*** CANRXDSR4 - MSCAN Receive Data Segment Register 4; 0x00000168 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR4STR;
extern volatile CANRXDSR4STR _CANRXDSR4 @(REG_BASE + 0x00000168UL);
#define CANRXDSR4                       _CANRXDSR4.Byte
#define CANRXDSR4_DB0                   _CANRXDSR4.Bits.DB0
#define CANRXDSR4_DB1                   _CANRXDSR4.Bits.DB1
#define CANRXDSR4_DB2                   _CANRXDSR4.Bits.DB2
#define CANRXDSR4_DB3                   _CANRXDSR4.Bits.DB3
#define CANRXDSR4_DB4                   _CANRXDSR4.Bits.DB4
#define CANRXDSR4_DB5                   _CANRXDSR4.Bits.DB5
#define CANRXDSR4_DB6                   _CANRXDSR4.Bits.DB6
#define CANRXDSR4_DB7                   _CANRXDSR4.Bits.DB7

#define CANRXDSR4_DB0_MASK              1U
#define CANRXDSR4_DB1_MASK              2U
#define CANRXDSR4_DB2_MASK              4U
#define CANRXDSR4_DB3_MASK              8U
#define CANRXDSR4_DB4_MASK              16U
#define CANRXDSR4_DB5_MASK              32U
#define CANRXDSR4_DB6_MASK              64U
#define CANRXDSR4_DB7_MASK              128U


/*** CANRXDSR5 - MSCAN Receive Data Segment Register 5; 0x00000169 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR5STR;
extern volatile CANRXDSR5STR _CANRXDSR5 @(REG_BASE + 0x00000169UL);
#define CANRXDSR5                       _CANRXDSR5.Byte
#define CANRXDSR5_DB0                   _CANRXDSR5.Bits.DB0
#define CANRXDSR5_DB1                   _CANRXDSR5.Bits.DB1
#define CANRXDSR5_DB2                   _CANRXDSR5.Bits.DB2
#define CANRXDSR5_DB3                   _CANRXDSR5.Bits.DB3
#define CANRXDSR5_DB4                   _CANRXDSR5.Bits.DB4
#define CANRXDSR5_DB5                   _CANRXDSR5.Bits.DB5
#define CANRXDSR5_DB6                   _CANRXDSR5.Bits.DB6
#define CANRXDSR5_DB7                   _CANRXDSR5.Bits.DB7

#define CANRXDSR5_DB0_MASK              1U
#define CANRXDSR5_DB1_MASK              2U
#define CANRXDSR5_DB2_MASK              4U
#define CANRXDSR5_DB3_MASK              8U
#define CANRXDSR5_DB4_MASK              16U
#define CANRXDSR5_DB5_MASK              32U
#define CANRXDSR5_DB6_MASK              64U
#define CANRXDSR5_DB7_MASK              128U


/*** CANRXDSR6 - MSCAN Receive Data Segment Register 6; 0x0000016A ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR6STR;
extern volatile CANRXDSR6STR _CANRXDSR6 @(REG_BASE + 0x0000016AUL);
#define CANRXDSR6                       _CANRXDSR6.Byte
#define CANRXDSR6_DB0                   _CANRXDSR6.Bits.DB0
#define CANRXDSR6_DB1                   _CANRXDSR6.Bits.DB1
#define CANRXDSR6_DB2                   _CANRXDSR6.Bits.DB2
#define CANRXDSR6_DB3                   _CANRXDSR6.Bits.DB3
#define CANRXDSR6_DB4                   _CANRXDSR6.Bits.DB4
#define CANRXDSR6_DB5                   _CANRXDSR6.Bits.DB5
#define CANRXDSR6_DB6                   _CANRXDSR6.Bits.DB6
#define CANRXDSR6_DB7                   _CANRXDSR6.Bits.DB7

#define CANRXDSR6_DB0_MASK              1U
#define CANRXDSR6_DB1_MASK              2U
#define CANRXDSR6_DB2_MASK              4U
#define CANRXDSR6_DB3_MASK              8U
#define CANRXDSR6_DB4_MASK              16U
#define CANRXDSR6_DB5_MASK              32U
#define CANRXDSR6_DB6_MASK              64U
#define CANRXDSR6_DB7_MASK              128U


/*** CANRXDSR7 - MSCAN Receive Data Segment Register 7; 0x0000016B ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR7STR;
extern volatile CANRXDSR7STR _CANRXDSR7 @(REG_BASE + 0x0000016BUL);
#define CANRXDSR7                       _CANRXDSR7.Byte
#define CANRXDSR7_DB0                   _CANRXDSR7.Bits.DB0
#define CANRXDSR7_DB1                   _CANRXDSR7.Bits.DB1
#define CANRXDSR7_DB2                   _CANRXDSR7.Bits.DB2
#define CANRXDSR7_DB3                   _CANRXDSR7.Bits.DB3
#define CANRXDSR7_DB4                   _CANRXDSR7.Bits.DB4
#define CANRXDSR7_DB5                   _CANRXDSR7.Bits.DB5
#define CANRXDSR7_DB6                   _CANRXDSR7.Bits.DB6
#define CANRXDSR7_DB7                   _CANRXDSR7.Bits.DB7

#define CANRXDSR7_DB0_MASK              1U
#define CANRXDSR7_DB1_MASK              2U
#define CANRXDSR7_DB2_MASK              4U
#define CANRXDSR7_DB3_MASK              8U
#define CANRXDSR7_DB4_MASK              16U
#define CANRXDSR7_DB5_MASK              32U
#define CANRXDSR7_DB6_MASK              64U
#define CANRXDSR7_DB7_MASK              128U


/*** CANRXDLR - MSCAN Receive Data Length Register; 0x0000016C ***/
typedef union {
  byte Byte;
  struct {
    byte DLC0        :1;                                       /* Data Length Code Bit 0 */
    byte DLC1        :1;                                       /* Data Length Code Bit 1 */
    byte DLC2        :1;                                       /* Data Length Code Bit 2 */
    byte DLC3        :1;                                       /* Data Length Code Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDLC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRXDLRSTR;
extern volatile CANRXDLRSTR _CANRXDLR @(REG_BASE + 0x0000016CUL);
#define CANRXDLR                        _CANRXDLR.Byte
#define CANRXDLR_DLC0                   _CANRXDLR.Bits.DLC0
#define CANRXDLR_DLC1                   _CANRXDLR.Bits.DLC1
#define CANRXDLR_DLC2                   _CANRXDLR.Bits.DLC2
#define CANRXDLR_DLC3                   _CANRXDLR.Bits.DLC3
#define CANRXDLR_DLC                    _CANRXDLR.MergedBits.grpDLC

#define CANRXDLR_DLC0_MASK              1U
#define CANRXDLR_DLC1_MASK              2U
#define CANRXDLR_DLC2_MASK              4U
#define CANRXDLR_DLC3_MASK              8U
#define CANRXDLR_DLC_MASK               15U
#define CANRXDLR_DLC_BITNUM             0U


/*** CANRXTSR - MSCAN Receive Time Stamp Register; 0x0000016E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CANRXTSRH - MSCAN Receive Time Stamp Register High; 0x0000016E ***/
    union {
      byte Byte;
      struct {
        byte TSR8        :1;                                       /* Time Stamp Bit 8 */
        byte TSR9        :1;                                       /* Time Stamp Bit 9 */
        byte TSR10       :1;                                       /* Time Stamp Bit 10 */
        byte TSR11       :1;                                       /* Time Stamp Bit 11 */
        byte TSR12       :1;                                       /* Time Stamp Bit 12 */
        byte TSR13       :1;                                       /* Time Stamp Bit 13 */
        byte TSR14       :1;                                       /* Time Stamp Bit 14 */
        byte TSR15       :1;                                       /* Time Stamp Bit 15 */
      } Bits;
    } CANRXTSRHSTR;
    #define CANRXTSRH                   _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Byte
    #define CANRXTSRH_TSR8              _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR8
    #define CANRXTSRH_TSR9              _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR9
    #define CANRXTSRH_TSR10             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR10
    #define CANRXTSRH_TSR11             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR11
    #define CANRXTSRH_TSR12             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR12
    #define CANRXTSRH_TSR13             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR13
    #define CANRXTSRH_TSR14             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR14
    #define CANRXTSRH_TSR15             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR15
    
    #define CANRXTSRH_TSR8_MASK         1U
    #define CANRXTSRH_TSR9_MASK         2U
    #define CANRXTSRH_TSR10_MASK        4U
    #define CANRXTSRH_TSR11_MASK        8U
    #define CANRXTSRH_TSR12_MASK        16U
    #define CANRXTSRH_TSR13_MASK        32U
    #define CANRXTSRH_TSR14_MASK        64U
    #define CANRXTSRH_TSR15_MASK        128U
    

    /*** CANRXTSRL - MSCAN Receive Time Stamp Register Low; 0x0000016F ***/
    union {
      byte Byte;
      struct {
        byte TSR0        :1;                                       /* Time Stamp Bit 0 */
        byte TSR1        :1;                                       /* Time Stamp Bit 1 */
        byte TSR2        :1;                                       /* Time Stamp Bit 2 */
        byte TSR3        :1;                                       /* Time Stamp Bit 3 */
        byte TSR4        :1;                                       /* Time Stamp Bit 4 */
        byte TSR5        :1;                                       /* Time Stamp Bit 5 */
        byte TSR6        :1;                                       /* Time Stamp Bit 6 */
        byte TSR7        :1;                                       /* Time Stamp Bit 7 */
      } Bits;
    } CANRXTSRLSTR;
    #define CANRXTSRL                   _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Byte
    #define CANRXTSRL_TSR0              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR0
    #define CANRXTSRL_TSR1              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR1
    #define CANRXTSRL_TSR2              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR2
    #define CANRXTSRL_TSR3              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR3
    #define CANRXTSRL_TSR4              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR4
    #define CANRXTSRL_TSR5              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR5
    #define CANRXTSRL_TSR6              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR6
    #define CANRXTSRL_TSR7              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR7
    
    #define CANRXTSRL_TSR0_MASK         1U
    #define CANRXTSRL_TSR1_MASK         2U
    #define CANRXTSRL_TSR2_MASK         4U
    #define CANRXTSRL_TSR3_MASK         8U
    #define CANRXTSRL_TSR4_MASK         16U
    #define CANRXTSRL_TSR5_MASK         32U
    #define CANRXTSRL_TSR6_MASK         64U
    #define CANRXTSRL_TSR7_MASK         128U
    
  } Overlap_STR;

  struct {
    word TSR0        :1;                                       /* Time Stamp Bit 0 */
    word TSR1        :1;                                       /* Time Stamp Bit 1 */
    word TSR2        :1;                                       /* Time Stamp Bit 2 */
    word TSR3        :1;                                       /* Time Stamp Bit 3 */
    word TSR4        :1;                                       /* Time Stamp Bit 4 */
    word TSR5        :1;                                       /* Time Stamp Bit 5 */
    word TSR6        :1;                                       /* Time Stamp Bit 6 */
    word TSR7        :1;                                       /* Time Stamp Bit 7 */
    word TSR8        :1;                                       /* Time Stamp Bit 8 */
    word TSR9        :1;                                       /* Time Stamp Bit 9 */
    word TSR10       :1;                                       /* Time Stamp Bit 10 */
    word TSR11       :1;                                       /* Time Stamp Bit 11 */
    word TSR12       :1;                                       /* Time Stamp Bit 12 */
    word TSR13       :1;                                       /* Time Stamp Bit 13 */
    word TSR14       :1;                                       /* Time Stamp Bit 14 */
    word TSR15       :1;                                       /* Time Stamp Bit 15 */
  } Bits;
} CANRXTSRSTR;
extern volatile CANRXTSRSTR _CANRXTSR @(REG_BASE + 0x0000016EUL);
#define CANRXTSR                        _CANRXTSR.Word
#define CANRXTSR_TSR0                   _CANRXTSR.Bits.TSR0
#define CANRXTSR_TSR1                   _CANRXTSR.Bits.TSR1
#define CANRXTSR_TSR2                   _CANRXTSR.Bits.TSR2
#define CANRXTSR_TSR3                   _CANRXTSR.Bits.TSR3
#define CANRXTSR_TSR4                   _CANRXTSR.Bits.TSR4
#define CANRXTSR_TSR5                   _CANRXTSR.Bits.TSR5
#define CANRXTSR_TSR6                   _CANRXTSR.Bits.TSR6
#define CANRXTSR_TSR7                   _CANRXTSR.Bits.TSR7
#define CANRXTSR_TSR8                   _CANRXTSR.Bits.TSR8
#define CANRXTSR_TSR9                   _CANRXTSR.Bits.TSR9
#define CANRXTSR_TSR10                  _CANRXTSR.Bits.TSR10
#define CANRXTSR_TSR11                  _CANRXTSR.Bits.TSR11
#define CANRXTSR_TSR12                  _CANRXTSR.Bits.TSR12
#define CANRXTSR_TSR13                  _CANRXTSR.Bits.TSR13
#define CANRXTSR_TSR14                  _CANRXTSR.Bits.TSR14
#define CANRXTSR_TSR15                  _CANRXTSR.Bits.TSR15

#define CANRXTSR_TSR0_MASK              1U
#define CANRXTSR_TSR1_MASK              2U
#define CANRXTSR_TSR2_MASK              4U
#define CANRXTSR_TSR3_MASK              8U
#define CANRXTSR_TSR4_MASK              16U
#define CANRXTSR_TSR5_MASK              32U
#define CANRXTSR_TSR6_MASK              64U
#define CANRXTSR_TSR7_MASK              128U
#define CANRXTSR_TSR8_MASK              256U
#define CANRXTSR_TSR9_MASK              512U
#define CANRXTSR_TSR10_MASK             1024U
#define CANRXTSR_TSR11_MASK             2048U
#define CANRXTSR_TSR12_MASK             4096U
#define CANRXTSR_TSR13_MASK             8192U
#define CANRXTSR_TSR14_MASK             16384U
#define CANRXTSR_TSR15_MASK             32768U


/*** CANTXIDR0 - MSCAN Transmit Identifier Register 0; 0x00000170 ***/
typedef union {
  byte Byte;
  struct {
    byte ID21        :1;                                       /* Extended format identifier Bit 21 */
    byte ID22        :1;                                       /* Extended format identifier Bit 22 */
    byte ID23        :1;                                       /* Extended format identifier Bit 23 */
    byte ID24        :1;                                       /* Extended format identifier Bit 24 */
    byte ID25        :1;                                       /* Extended format identifier Bit 25 */
    byte ID26        :1;                                       /* Extended format identifier Bit 26 */
    byte ID27        :1;                                       /* Extended format identifier Bit 27 */
    byte ID28        :1;                                       /* Extended format identifier Bit 28 */
  } Bits;
} CANTXIDR0STR;
extern volatile CANTXIDR0STR _CANTXIDR0 @(REG_BASE + 0x00000170UL);
#define CANTXIDR0                       _CANTXIDR0.Byte
#define CANTXIDR0_ID21                  _CANTXIDR0.Bits.ID21
#define CANTXIDR0_ID22                  _CANTXIDR0.Bits.ID22
#define CANTXIDR0_ID23                  _CANTXIDR0.Bits.ID23
#define CANTXIDR0_ID24                  _CANTXIDR0.Bits.ID24
#define CANTXIDR0_ID25                  _CANTXIDR0.Bits.ID25
#define CANTXIDR0_ID26                  _CANTXIDR0.Bits.ID26
#define CANTXIDR0_ID27                  _CANTXIDR0.Bits.ID27
#define CANTXIDR0_ID28                  _CANTXIDR0.Bits.ID28
/* CANTXIDR_ARR: Access 4 CANTXIDRx registers in an array */
#define CANTXIDR_ARR                    ((volatile byte *) &CANTXIDR0)

#define CANTXIDR0_ID21_MASK             1U
#define CANTXIDR0_ID22_MASK             2U
#define CANTXIDR0_ID23_MASK             4U
#define CANTXIDR0_ID24_MASK             8U
#define CANTXIDR0_ID25_MASK             16U
#define CANTXIDR0_ID26_MASK             32U
#define CANTXIDR0_ID27_MASK             64U
#define CANTXIDR0_ID28_MASK             128U


/*** CANTXIDR1 - MSCAN Transmit Identifier Register 1; 0x00000171 ***/
typedef union {
  byte Byte;
  struct {
    byte ID15        :1;                                       /* Extended format identifier Bit 15 */
    byte ID16        :1;                                       /* Extended format identifier Bit 16 */
    byte ID17        :1;                                       /* Extended format identifier Bit 17 */
    byte IDE         :1;                                       /* ID Extended */
    byte SRR         :1;                                       /* Substitute Remote Request */
    byte ID18        :1;                                       /* Extended format identifier Bit 18 */
    byte ID19        :1;                                       /* Extended format identifier Bit 19 */
    byte ID20        :1;                                       /* Extended format identifier Bit 20 */
  } Bits;
  struct {
    byte grpID_15 :3;
    byte         :1;
    byte         :1;
    byte grpID_18 :3;
  } MergedBits;
} CANTXIDR1STR;
extern volatile CANTXIDR1STR _CANTXIDR1 @(REG_BASE + 0x00000171UL);
#define CANTXIDR1                       _CANTXIDR1.Byte
#define CANTXIDR1_ID15                  _CANTXIDR1.Bits.ID15
#define CANTXIDR1_ID16                  _CANTXIDR1.Bits.ID16
#define CANTXIDR1_ID17                  _CANTXIDR1.Bits.ID17
#define CANTXIDR1_IDE                   _CANTXIDR1.Bits.IDE
#define CANTXIDR1_SRR                   _CANTXIDR1.Bits.SRR
#define CANTXIDR1_ID18                  _CANTXIDR1.Bits.ID18
#define CANTXIDR1_ID19                  _CANTXIDR1.Bits.ID19
#define CANTXIDR1_ID20                  _CANTXIDR1.Bits.ID20
#define CANTXIDR1_ID_15                 _CANTXIDR1.MergedBits.grpID_15
#define CANTXIDR1_ID_18                 _CANTXIDR1.MergedBits.grpID_18
#define CANTXIDR1_ID                    CANTXIDR1_ID_15

#define CANTXIDR1_ID15_MASK             1U
#define CANTXIDR1_ID16_MASK             2U
#define CANTXIDR1_ID17_MASK             4U
#define CANTXIDR1_IDE_MASK              8U
#define CANTXIDR1_SRR_MASK              16U
#define CANTXIDR1_ID18_MASK             32U
#define CANTXIDR1_ID19_MASK             64U
#define CANTXIDR1_ID20_MASK             128U
#define CANTXIDR1_ID_15_MASK            7U
#define CANTXIDR1_ID_15_BITNUM          0U
#define CANTXIDR1_ID_18_MASK            224U
#define CANTXIDR1_ID_18_BITNUM          5U


/*** CANTXIDR2 - MSCAN Transmit Identifier Register 2; 0x00000172 ***/
typedef union {
  byte Byte;
  struct {
    byte ID7         :1;                                       /* Extended format identifier Bit 7 */
    byte ID8         :1;                                       /* Extended format identifier Bit 8 */
    byte ID9         :1;                                       /* Extended format identifier Bit 9 */
    byte ID10        :1;                                       /* Extended format identifier Bit 10 */
    byte ID11        :1;                                       /* Extended format identifier Bit 11 */
    byte ID12        :1;                                       /* Extended format identifier Bit 12 */
    byte ID13        :1;                                       /* Extended format identifier Bit 13 */
    byte ID14        :1;                                       /* Extended format identifier Bit 14 */
  } Bits;
} CANTXIDR2STR;
extern volatile CANTXIDR2STR _CANTXIDR2 @(REG_BASE + 0x00000172UL);
#define CANTXIDR2                       _CANTXIDR2.Byte
#define CANTXIDR2_ID7                   _CANTXIDR2.Bits.ID7
#define CANTXIDR2_ID8                   _CANTXIDR2.Bits.ID8
#define CANTXIDR2_ID9                   _CANTXIDR2.Bits.ID9
#define CANTXIDR2_ID10                  _CANTXIDR2.Bits.ID10
#define CANTXIDR2_ID11                  _CANTXIDR2.Bits.ID11
#define CANTXIDR2_ID12                  _CANTXIDR2.Bits.ID12
#define CANTXIDR2_ID13                  _CANTXIDR2.Bits.ID13
#define CANTXIDR2_ID14                  _CANTXIDR2.Bits.ID14

#define CANTXIDR2_ID7_MASK              1U
#define CANTXIDR2_ID8_MASK              2U
#define CANTXIDR2_ID9_MASK              4U
#define CANTXIDR2_ID10_MASK             8U
#define CANTXIDR2_ID11_MASK             16U
#define CANTXIDR2_ID12_MASK             32U
#define CANTXIDR2_ID13_MASK             64U
#define CANTXIDR2_ID14_MASK             128U


/*** CANTXIDR3 - MSCAN Transmit Identifier Register 3; 0x00000173 ***/
typedef union {
  byte Byte;
  struct {
    byte RTR         :1;                                       /* Remote Transmission Request */
    byte ID0         :1;                                       /* Extended format identifier Bit 0 */
    byte ID1         :1;                                       /* Extended format identifier Bit 1 */
    byte ID2         :1;                                       /* Extended format identifier Bit 2 */
    byte ID3         :1;                                       /* Extended format identifier Bit 3 */
    byte ID4         :1;                                       /* Extended format identifier Bit 4 */
    byte ID5         :1;                                       /* Extended format identifier Bit 5 */
    byte ID6         :1;                                       /* Extended format identifier Bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpID   :7;
  } MergedBits;
} CANTXIDR3STR;
extern volatile CANTXIDR3STR _CANTXIDR3 @(REG_BASE + 0x00000173UL);
#define CANTXIDR3                       _CANTXIDR3.Byte
#define CANTXIDR3_RTR                   _CANTXIDR3.Bits.RTR
#define CANTXIDR3_ID0                   _CANTXIDR3.Bits.ID0
#define CANTXIDR3_ID1                   _CANTXIDR3.Bits.ID1
#define CANTXIDR3_ID2                   _CANTXIDR3.Bits.ID2
#define CANTXIDR3_ID3                   _CANTXIDR3.Bits.ID3
#define CANTXIDR3_ID4                   _CANTXIDR3.Bits.ID4
#define CANTXIDR3_ID5                   _CANTXIDR3.Bits.ID5
#define CANTXIDR3_ID6                   _CANTXIDR3.Bits.ID6
#define CANTXIDR3_ID                    _CANTXIDR3.MergedBits.grpID

#define CANTXIDR3_RTR_MASK              1U
#define CANTXIDR3_ID0_MASK              2U
#define CANTXIDR3_ID1_MASK              4U
#define CANTXIDR3_ID2_MASK              8U
#define CANTXIDR3_ID3_MASK              16U
#define CANTXIDR3_ID4_MASK              32U
#define CANTXIDR3_ID5_MASK              64U
#define CANTXIDR3_ID6_MASK              128U
#define CANTXIDR3_ID_MASK               254U
#define CANTXIDR3_ID_BITNUM             1U


/*** CANTXDSR0 - MSCAN Transmit Data Segment Register 0; 0x00000174 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR0STR;
extern volatile CANTXDSR0STR _CANTXDSR0 @(REG_BASE + 0x00000174UL);
#define CANTXDSR0                       _CANTXDSR0.Byte
#define CANTXDSR0_DB0                   _CANTXDSR0.Bits.DB0
#define CANTXDSR0_DB1                   _CANTXDSR0.Bits.DB1
#define CANTXDSR0_DB2                   _CANTXDSR0.Bits.DB2
#define CANTXDSR0_DB3                   _CANTXDSR0.Bits.DB3
#define CANTXDSR0_DB4                   _CANTXDSR0.Bits.DB4
#define CANTXDSR0_DB5                   _CANTXDSR0.Bits.DB5
#define CANTXDSR0_DB6                   _CANTXDSR0.Bits.DB6
#define CANTXDSR0_DB7                   _CANTXDSR0.Bits.DB7
/* CANTXDSR_ARR: Access 8 CANTXDSRx registers in an array */
#define CANTXDSR_ARR                    ((volatile byte *) &CANTXDSR0)

#define CANTXDSR0_DB0_MASK              1U
#define CANTXDSR0_DB1_MASK              2U
#define CANTXDSR0_DB2_MASK              4U
#define CANTXDSR0_DB3_MASK              8U
#define CANTXDSR0_DB4_MASK              16U
#define CANTXDSR0_DB5_MASK              32U
#define CANTXDSR0_DB6_MASK              64U
#define CANTXDSR0_DB7_MASK              128U


/*** CANTXDSR1 - MSCAN Transmit Data Segment Register 1; 0x00000175 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR1STR;
extern volatile CANTXDSR1STR _CANTXDSR1 @(REG_BASE + 0x00000175UL);
#define CANTXDSR1                       _CANTXDSR1.Byte
#define CANTXDSR1_DB0                   _CANTXDSR1.Bits.DB0
#define CANTXDSR1_DB1                   _CANTXDSR1.Bits.DB1
#define CANTXDSR1_DB2                   _CANTXDSR1.Bits.DB2
#define CANTXDSR1_DB3                   _CANTXDSR1.Bits.DB3
#define CANTXDSR1_DB4                   _CANTXDSR1.Bits.DB4
#define CANTXDSR1_DB5                   _CANTXDSR1.Bits.DB5
#define CANTXDSR1_DB6                   _CANTXDSR1.Bits.DB6
#define CANTXDSR1_DB7                   _CANTXDSR1.Bits.DB7

#define CANTXDSR1_DB0_MASK              1U
#define CANTXDSR1_DB1_MASK              2U
#define CANTXDSR1_DB2_MASK              4U
#define CANTXDSR1_DB3_MASK              8U
#define CANTXDSR1_DB4_MASK              16U
#define CANTXDSR1_DB5_MASK              32U
#define CANTXDSR1_DB6_MASK              64U
#define CANTXDSR1_DB7_MASK              128U


/*** CANTXDSR2 - MSCAN Transmit Data Segment Register 2; 0x00000176 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR2STR;
extern volatile CANTXDSR2STR _CANTXDSR2 @(REG_BASE + 0x00000176UL);
#define CANTXDSR2                       _CANTXDSR2.Byte
#define CANTXDSR2_DB0                   _CANTXDSR2.Bits.DB0
#define CANTXDSR2_DB1                   _CANTXDSR2.Bits.DB1
#define CANTXDSR2_DB2                   _CANTXDSR2.Bits.DB2
#define CANTXDSR2_DB3                   _CANTXDSR2.Bits.DB3
#define CANTXDSR2_DB4                   _CANTXDSR2.Bits.DB4
#define CANTXDSR2_DB5                   _CANTXDSR2.Bits.DB5
#define CANTXDSR2_DB6                   _CANTXDSR2.Bits.DB6
#define CANTXDSR2_DB7                   _CANTXDSR2.Bits.DB7

#define CANTXDSR2_DB0_MASK              1U
#define CANTXDSR2_DB1_MASK              2U
#define CANTXDSR2_DB2_MASK              4U
#define CANTXDSR2_DB3_MASK              8U
#define CANTXDSR2_DB4_MASK              16U
#define CANTXDSR2_DB5_MASK              32U
#define CANTXDSR2_DB6_MASK              64U
#define CANTXDSR2_DB7_MASK              128U


/*** CANTXDSR3 - MSCAN Transmit Data Segment Register 3; 0x00000177 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR3STR;
extern volatile CANTXDSR3STR _CANTXDSR3 @(REG_BASE + 0x00000177UL);
#define CANTXDSR3                       _CANTXDSR3.Byte
#define CANTXDSR3_DB0                   _CANTXDSR3.Bits.DB0
#define CANTXDSR3_DB1                   _CANTXDSR3.Bits.DB1
#define CANTXDSR3_DB2                   _CANTXDSR3.Bits.DB2
#define CANTXDSR3_DB3                   _CANTXDSR3.Bits.DB3
#define CANTXDSR3_DB4                   _CANTXDSR3.Bits.DB4
#define CANTXDSR3_DB5                   _CANTXDSR3.Bits.DB5
#define CANTXDSR3_DB6                   _CANTXDSR3.Bits.DB6
#define CANTXDSR3_DB7                   _CANTXDSR3.Bits.DB7

#define CANTXDSR3_DB0_MASK              1U
#define CANTXDSR3_DB1_MASK              2U
#define CANTXDSR3_DB2_MASK              4U
#define CANTXDSR3_DB3_MASK              8U
#define CANTXDSR3_DB4_MASK              16U
#define CANTXDSR3_DB5_MASK              32U
#define CANTXDSR3_DB6_MASK              64U
#define CANTXDSR3_DB7_MASK              128U


/*** CANTXDSR4 - MSCAN Transmit Data Segment Register 4; 0x00000178 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR4STR;
extern volatile CANTXDSR4STR _CANTXDSR4 @(REG_BASE + 0x00000178UL);
#define CANTXDSR4                       _CANTXDSR4.Byte
#define CANTXDSR4_DB0                   _CANTXDSR4.Bits.DB0
#define CANTXDSR4_DB1                   _CANTXDSR4.Bits.DB1
#define CANTXDSR4_DB2                   _CANTXDSR4.Bits.DB2
#define CANTXDSR4_DB3                   _CANTXDSR4.Bits.DB3
#define CANTXDSR4_DB4                   _CANTXDSR4.Bits.DB4
#define CANTXDSR4_DB5                   _CANTXDSR4.Bits.DB5
#define CANTXDSR4_DB6                   _CANTXDSR4.Bits.DB6
#define CANTXDSR4_DB7                   _CANTXDSR4.Bits.DB7

#define CANTXDSR4_DB0_MASK              1U
#define CANTXDSR4_DB1_MASK              2U
#define CANTXDSR4_DB2_MASK              4U
#define CANTXDSR4_DB3_MASK              8U
#define CANTXDSR4_DB4_MASK              16U
#define CANTXDSR4_DB5_MASK              32U
#define CANTXDSR4_DB6_MASK              64U
#define CANTXDSR4_DB7_MASK              128U


/*** CANTXDSR5 - MSCAN Transmit Data Segment Register 5; 0x00000179 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR5STR;
extern volatile CANTXDSR5STR _CANTXDSR5 @(REG_BASE + 0x00000179UL);
#define CANTXDSR5                       _CANTXDSR5.Byte
#define CANTXDSR5_DB0                   _CANTXDSR5.Bits.DB0
#define CANTXDSR5_DB1                   _CANTXDSR5.Bits.DB1
#define CANTXDSR5_DB2                   _CANTXDSR5.Bits.DB2
#define CANTXDSR5_DB3                   _CANTXDSR5.Bits.DB3
#define CANTXDSR5_DB4                   _CANTXDSR5.Bits.DB4
#define CANTXDSR5_DB5                   _CANTXDSR5.Bits.DB5
#define CANTXDSR5_DB6                   _CANTXDSR5.Bits.DB6
#define CANTXDSR5_DB7                   _CANTXDSR5.Bits.DB7

#define CANTXDSR5_DB0_MASK              1U
#define CANTXDSR5_DB1_MASK              2U
#define CANTXDSR5_DB2_MASK              4U
#define CANTXDSR5_DB3_MASK              8U
#define CANTXDSR5_DB4_MASK              16U
#define CANTXDSR5_DB5_MASK              32U
#define CANTXDSR5_DB6_MASK              64U
#define CANTXDSR5_DB7_MASK              128U


/*** CANTXDSR6 - MSCAN Transmit Data Segment Register 6; 0x0000017A ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR6STR;
extern volatile CANTXDSR6STR _CANTXDSR6 @(REG_BASE + 0x0000017AUL);
#define CANTXDSR6                       _CANTXDSR6.Byte
#define CANTXDSR6_DB0                   _CANTXDSR6.Bits.DB0
#define CANTXDSR6_DB1                   _CANTXDSR6.Bits.DB1
#define CANTXDSR6_DB2                   _CANTXDSR6.Bits.DB2
#define CANTXDSR6_DB3                   _CANTXDSR6.Bits.DB3
#define CANTXDSR6_DB4                   _CANTXDSR6.Bits.DB4
#define CANTXDSR6_DB5                   _CANTXDSR6.Bits.DB5
#define CANTXDSR6_DB6                   _CANTXDSR6.Bits.DB6
#define CANTXDSR6_DB7                   _CANTXDSR6.Bits.DB7

#define CANTXDSR6_DB0_MASK              1U
#define CANTXDSR6_DB1_MASK              2U
#define CANTXDSR6_DB2_MASK              4U
#define CANTXDSR6_DB3_MASK              8U
#define CANTXDSR6_DB4_MASK              16U
#define CANTXDSR6_DB5_MASK              32U
#define CANTXDSR6_DB6_MASK              64U
#define CANTXDSR6_DB7_MASK              128U


/*** CANTXDSR7 - MSCAN Transmit Data Segment Register 7; 0x0000017B ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR7STR;
extern volatile CANTXDSR7STR _CANTXDSR7 @(REG_BASE + 0x0000017BUL);
#define CANTXDSR7                       _CANTXDSR7.Byte
#define CANTXDSR7_DB0                   _CANTXDSR7.Bits.DB0
#define CANTXDSR7_DB1                   _CANTXDSR7.Bits.DB1
#define CANTXDSR7_DB2                   _CANTXDSR7.Bits.DB2
#define CANTXDSR7_DB3                   _CANTXDSR7.Bits.DB3
#define CANTXDSR7_DB4                   _CANTXDSR7.Bits.DB4
#define CANTXDSR7_DB5                   _CANTXDSR7.Bits.DB5
#define CANTXDSR7_DB6                   _CANTXDSR7.Bits.DB6
#define CANTXDSR7_DB7                   _CANTXDSR7.Bits.DB7

#define CANTXDSR7_DB0_MASK              1U
#define CANTXDSR7_DB1_MASK              2U
#define CANTXDSR7_DB2_MASK              4U
#define CANTXDSR7_DB3_MASK              8U
#define CANTXDSR7_DB4_MASK              16U
#define CANTXDSR7_DB5_MASK              32U
#define CANTXDSR7_DB6_MASK              64U
#define CANTXDSR7_DB7_MASK              128U


/*** CANTXDLR - MSCAN Transmit Data Length Register; 0x0000017C ***/
typedef union {
  byte Byte;
  struct {
    byte DLC0        :1;                                       /* Data Length Code Bit 0 */
    byte DLC1        :1;                                       /* Data Length Code Bit 1 */
    byte DLC2        :1;                                       /* Data Length Code Bit 2 */
    byte DLC3        :1;                                       /* Data Length Code Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDLC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTXDLRSTR;
extern volatile CANTXDLRSTR _CANTXDLR @(REG_BASE + 0x0000017CUL);
#define CANTXDLR                        _CANTXDLR.Byte
#define CANTXDLR_DLC0                   _CANTXDLR.Bits.DLC0
#define CANTXDLR_DLC1                   _CANTXDLR.Bits.DLC1
#define CANTXDLR_DLC2                   _CANTXDLR.Bits.DLC2
#define CANTXDLR_DLC3                   _CANTXDLR.Bits.DLC3
#define CANTXDLR_DLC                    _CANTXDLR.MergedBits.grpDLC

#define CANTXDLR_DLC0_MASK              1U
#define CANTXDLR_DLC1_MASK              2U
#define CANTXDLR_DLC2_MASK              4U
#define CANTXDLR_DLC3_MASK              8U
#define CANTXDLR_DLC_MASK               15U
#define CANTXDLR_DLC_BITNUM             0U


/*** CANTXTBPR - MSCAN Transmit Buffer Priority; 0x0000017D ***/
typedef union {
  byte Byte;
  struct {
    byte PRIO0       :1;                                       /* Transmit Buffer Priority Bit 0 */
    byte PRIO1       :1;                                       /* Transmit Buffer Priority Bit 1 */
    byte PRIO2       :1;                                       /* Transmit Buffer Priority Bit 2 */
    byte PRIO3       :1;                                       /* Transmit Buffer Priority Bit 3 */
    byte PRIO4       :1;                                       /* Transmit Buffer Priority Bit 4 */
    byte PRIO5       :1;                                       /* Transmit Buffer Priority Bit 5 */
    byte PRIO6       :1;                                       /* Transmit Buffer Priority Bit 6 */
    byte PRIO7       :1;                                       /* Transmit Buffer Priority Bit 7 */
  } Bits;
} CANTXTBPRSTR;
extern volatile CANTXTBPRSTR _CANTXTBPR @(REG_BASE + 0x0000017DUL);
#define CANTXTBPR                       _CANTXTBPR.Byte
#define CANTXTBPR_PRIO0                 _CANTXTBPR.Bits.PRIO0
#define CANTXTBPR_PRIO1                 _CANTXTBPR.Bits.PRIO1
#define CANTXTBPR_PRIO2                 _CANTXTBPR.Bits.PRIO2
#define CANTXTBPR_PRIO3                 _CANTXTBPR.Bits.PRIO3
#define CANTXTBPR_PRIO4                 _CANTXTBPR.Bits.PRIO4
#define CANTXTBPR_PRIO5                 _CANTXTBPR.Bits.PRIO5
#define CANTXTBPR_PRIO6                 _CANTXTBPR.Bits.PRIO6
#define CANTXTBPR_PRIO7                 _CANTXTBPR.Bits.PRIO7

#define CANTXTBPR_PRIO0_MASK            1U
#define CANTXTBPR_PRIO1_MASK            2U
#define CANTXTBPR_PRIO2_MASK            4U
#define CANTXTBPR_PRIO3_MASK            8U
#define CANTXTBPR_PRIO4_MASK            16U
#define CANTXTBPR_PRIO5_MASK            32U
#define CANTXTBPR_PRIO6_MASK            64U
#define CANTXTBPR_PRIO7_MASK            128U


/*** CANTXTSR - MSCAN Transmit Time Stamp Register; 0x0000017E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CANTXTSRH - MSCAN Transmit Time Stamp Register High; 0x0000017E ***/
    union {
      byte Byte;
      struct {
        byte TSR8        :1;                                       /* Time Stamp Bit 8 */
        byte TSR9        :1;                                       /* Time Stamp Bit 9 */
        byte TSR10       :1;                                       /* Time Stamp Bit 10 */
        byte TSR11       :1;                                       /* Time Stamp Bit 11 */
        byte TSR12       :1;                                       /* Time Stamp Bit 12 */
        byte TSR13       :1;                                       /* Time Stamp Bit 13 */
        byte TSR14       :1;                                       /* Time Stamp Bit 14 */
        byte TSR15       :1;                                       /* Time Stamp Bit 15 */
      } Bits;
    } CANTXTSRHSTR;
    #define CANTXTSRH                   _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Byte
    #define CANTXTSRH_TSR8              _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR8
    #define CANTXTSRH_TSR9              _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR9
    #define CANTXTSRH_TSR10             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR10
    #define CANTXTSRH_TSR11             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR11
    #define CANTXTSRH_TSR12             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR12
    #define CANTXTSRH_TSR13             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR13
    #define CANTXTSRH_TSR14             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR14
    #define CANTXTSRH_TSR15             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR15
    
    #define CANTXTSRH_TSR8_MASK         1U
    #define CANTXTSRH_TSR9_MASK         2U
    #define CANTXTSRH_TSR10_MASK        4U
    #define CANTXTSRH_TSR11_MASK        8U
    #define CANTXTSRH_TSR12_MASK        16U
    #define CANTXTSRH_TSR13_MASK        32U
    #define CANTXTSRH_TSR14_MASK        64U
    #define CANTXTSRH_TSR15_MASK        128U
    

    /*** CANTXTSRL - MSCAN Transmit Time Stamp Register Low; 0x0000017F ***/
    union {
      byte Byte;
      struct {
        byte TSR0        :1;                                       /* Time Stamp Bit 0 */
        byte TSR1        :1;                                       /* Time Stamp Bit 1 */
        byte TSR2        :1;                                       /* Time Stamp Bit 2 */
        byte TSR3        :1;                                       /* Time Stamp Bit 3 */
        byte TSR4        :1;                                       /* Time Stamp Bit 4 */
        byte TSR5        :1;                                       /* Time Stamp Bit 5 */
        byte TSR6        :1;                                       /* Time Stamp Bit 6 */
        byte TSR7        :1;                                       /* Time Stamp Bit 7 */
      } Bits;
    } CANTXTSRLSTR;
    #define CANTXTSRL                   _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Byte
    #define CANTXTSRL_TSR0              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR0
    #define CANTXTSRL_TSR1              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR1
    #define CANTXTSRL_TSR2              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR2
    #define CANTXTSRL_TSR3              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR3
    #define CANTXTSRL_TSR4              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR4
    #define CANTXTSRL_TSR5              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR5
    #define CANTXTSRL_TSR6              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR6
    #define CANTXTSRL_TSR7              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR7
    
    #define CANTXTSRL_TSR0_MASK         1U
    #define CANTXTSRL_TSR1_MASK         2U
    #define CANTXTSRL_TSR2_MASK         4U
    #define CANTXTSRL_TSR3_MASK         8U
    #define CANTXTSRL_TSR4_MASK         16U
    #define CANTXTSRL_TSR5_MASK         32U
    #define CANTXTSRL_TSR6_MASK         64U
    #define CANTXTSRL_TSR7_MASK         128U
    
  } Overlap_STR;

  struct {
    word TSR0        :1;                                       /* Time Stamp Bit 0 */
    word TSR1        :1;                                       /* Time Stamp Bit 1 */
    word TSR2        :1;                                       /* Time Stamp Bit 2 */
    word TSR3        :1;                                       /* Time Stamp Bit 3 */
    word TSR4        :1;                                       /* Time Stamp Bit 4 */
    word TSR5        :1;                                       /* Time Stamp Bit 5 */
    word TSR6        :1;                                       /* Time Stamp Bit 6 */
    word TSR7        :1;                                       /* Time Stamp Bit 7 */
    word TSR8        :1;                                       /* Time Stamp Bit 8 */
    word TSR9        :1;                                       /* Time Stamp Bit 9 */
    word TSR10       :1;                                       /* Time Stamp Bit 10 */
    word TSR11       :1;                                       /* Time Stamp Bit 11 */
    word TSR12       :1;                                       /* Time Stamp Bit 12 */
    word TSR13       :1;                                       /* Time Stamp Bit 13 */
    word TSR14       :1;                                       /* Time Stamp Bit 14 */
    word TSR15       :1;                                       /* Time Stamp Bit 15 */
  } Bits;
} CANTXTSRSTR;
extern volatile CANTXTSRSTR _CANTXTSR @(REG_BASE + 0x0000017EUL);
#define CANTXTSR                        _CANTXTSR.Word
#define CANTXTSR_TSR0                   _CANTXTSR.Bits.TSR0
#define CANTXTSR_TSR1                   _CANTXTSR.Bits.TSR1
#define CANTXTSR_TSR2                   _CANTXTSR.Bits.TSR2
#define CANTXTSR_TSR3                   _CANTXTSR.Bits.TSR3
#define CANTXTSR_TSR4                   _CANTXTSR.Bits.TSR4
#define CANTXTSR_TSR5                   _CANTXTSR.Bits.TSR5
#define CANTXTSR_TSR6                   _CANTXTSR.Bits.TSR6
#define CANTXTSR_TSR7                   _CANTXTSR.Bits.TSR7
#define CANTXTSR_TSR8                   _CANTXTSR.Bits.TSR8
#define CANTXTSR_TSR9                   _CANTXTSR.Bits.TSR9
#define CANTXTSR_TSR10                  _CANTXTSR.Bits.TSR10
#define CANTXTSR_TSR11                  _CANTXTSR.Bits.TSR11
#define CANTXTSR_TSR12                  _CANTXTSR.Bits.TSR12
#define CANTXTSR_TSR13                  _CANTXTSR.Bits.TSR13
#define CANTXTSR_TSR14                  _CANTXTSR.Bits.TSR14
#define CANTXTSR_TSR15                  _CANTXTSR.Bits.TSR15

#define CANTXTSR_TSR0_MASK              1U
#define CANTXTSR_TSR1_MASK              2U
#define CANTXTSR_TSR2_MASK              4U
#define CANTXTSR_TSR3_MASK              8U
#define CANTXTSR_TSR4_MASK              16U
#define CANTXTSR_TSR5_MASK              32U
#define CANTXTSR_TSR6_MASK              64U
#define CANTXTSR_TSR7_MASK              128U
#define CANTXTSR_TSR8_MASK              256U
#define CANTXTSR_TSR9_MASK              512U
#define CANTXTSR_TSR10_MASK             1024U
#define CANTXTSR_TSR11_MASK             2048U
#define CANTXTSR_TSR12_MASK             4096U
#define CANTXTSR_TSR13_MASK             8192U
#define CANTXTSR_TSR14_MASK             16384U
#define CANTXTSR_TSR15_MASK             32768U


/*** PTT - Port T I/O Register; 0x00000240 ***/
typedef union {
  byte Byte;
  struct {
    byte PTT0        :1;                                       /* Port T Bit 0 */
    byte PTT1        :1;                                       /* Port T Bit 1 */
    byte PTT2        :1;                                       /* Port T Bit 2 */
    byte PTT3        :1;                                       /* Port T Bit 3 */
    byte PTT4        :1;                                       /* Port T Bit 4 */
    byte PTT5        :1;                                       /* Port T Bit 5 */
    byte PTT6        :1;                                       /* Port T Bit 6 */
    byte PTT7        :1;                                       /* Port T Bit 7 */
  } Bits;
} PTTSTR;
extern volatile PTTSTR _PTT @(REG_BASE + 0x00000240UL);
#define PTT                             _PTT.Byte
#define PTT_PTT0                        _PTT.Bits.PTT0
#define PTT_PTT1                        _PTT.Bits.PTT1
#define PTT_PTT2                        _PTT.Bits.PTT2
#define PTT_PTT3                        _PTT.Bits.PTT3
#define PTT_PTT4                        _PTT.Bits.PTT4
#define PTT_PTT5                        _PTT.Bits.PTT5
#define PTT_PTT6                        _PTT.Bits.PTT6
#define PTT_PTT7                        _PTT.Bits.PTT7

#define PTT_PTT0_MASK                   1U
#define PTT_PTT1_MASK                   2U
#define PTT_PTT2_MASK                   4U
#define PTT_PTT3_MASK                   8U
#define PTT_PTT4_MASK                   16U
#define PTT_PTT5_MASK                   32U
#define PTT_PTT6_MASK                   64U
#define PTT_PTT7_MASK                   128U


/*** PTIT - Port T Input Register; 0x00000241 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIT0       :1;                                       /* Port T Bit 0 */
    byte PTIT1       :1;                                       /* Port T Bit 1 */
    byte PTIT2       :1;                                       /* Port T Bit 2 */
    byte PTIT3       :1;                                       /* Port T Bit 3 */
    byte PTIT4       :1;                                       /* Port T Bit 4 */
    byte PTIT5       :1;                                       /* Port T Bit 5 */
    byte PTIT6       :1;                                       /* Port T Bit 6 */
    byte PTIT7       :1;                                       /* Port T Bit 7 */
  } Bits;
} PTITSTR;
extern volatile PTITSTR _PTIT @(REG_BASE + 0x00000241UL);
#define PTIT                            _PTIT.Byte
#define PTIT_PTIT0                      _PTIT.Bits.PTIT0
#define PTIT_PTIT1                      _PTIT.Bits.PTIT1
#define PTIT_PTIT2                      _PTIT.Bits.PTIT2
#define PTIT_PTIT3                      _PTIT.Bits.PTIT3
#define PTIT_PTIT4                      _PTIT.Bits.PTIT4
#define PTIT_PTIT5                      _PTIT.Bits.PTIT5
#define PTIT_PTIT6                      _PTIT.Bits.PTIT6
#define PTIT_PTIT7                      _PTIT.Bits.PTIT7

#define PTIT_PTIT0_MASK                 1U
#define PTIT_PTIT1_MASK                 2U
#define PTIT_PTIT2_MASK                 4U
#define PTIT_PTIT3_MASK                 8U
#define PTIT_PTIT4_MASK                 16U
#define PTIT_PTIT5_MASK                 32U
#define PTIT_PTIT6_MASK                 64U
#define PTIT_PTIT7_MASK                 128U


/*** DDRT - Port T Data Direction Register; 0x00000242 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRT0       :1;                                       /* Data Direction Port T Bit 0 */
    byte DDRT1       :1;                                       /* Data Direction Port T Bit 1 */
    byte DDRT2       :1;                                       /* Data Direction Port T Bit 2 */
    byte DDRT3       :1;                                       /* Data Direction Port T Bit 3 */
    byte DDRT4       :1;                                       /* Data Direction Port T Bit 4 */
    byte DDRT5       :1;                                       /* Data Direction Port T Bit 5 */
    byte DDRT6       :1;                                       /* Data Direction Port T Bit 6 */
    byte DDRT7       :1;                                       /* Data Direction Port T Bit 7 */
  } Bits;
} DDRTSTR;
extern volatile DDRTSTR _DDRT @(REG_BASE + 0x00000242UL);
#define DDRT                            _DDRT.Byte
#define DDRT_DDRT0                      _DDRT.Bits.DDRT0
#define DDRT_DDRT1                      _DDRT.Bits.DDRT1
#define DDRT_DDRT2                      _DDRT.Bits.DDRT2
#define DDRT_DDRT3                      _DDRT.Bits.DDRT3
#define DDRT_DDRT4                      _DDRT.Bits.DDRT4
#define DDRT_DDRT5                      _DDRT.Bits.DDRT5
#define DDRT_DDRT6                      _DDRT.Bits.DDRT6
#define DDRT_DDRT7                      _DDRT.Bits.DDRT7

#define DDRT_DDRT0_MASK                 1U
#define DDRT_DDRT1_MASK                 2U
#define DDRT_DDRT2_MASK                 4U
#define DDRT_DDRT3_MASK                 8U
#define DDRT_DDRT4_MASK                 16U
#define DDRT_DDRT5_MASK                 32U
#define DDRT_DDRT6_MASK                 64U
#define DDRT_DDRT7_MASK                 128U


/*** RDRT - Port T Reduced Drive Register; 0x00000243 ***/
typedef union {
  byte Byte;
  struct {
    byte RDRT0       :1;                                       /* Reduced Drive Port T Bit 0 */
    byte RDRT1       :1;                                       /* Reduced Drive Port T Bit 1 */
    byte RDRT2       :1;                                       /* Reduced Drive Port T Bit 2 */
    byte RDRT3       :1;                                       /* Reduced Drive Port T Bit 3 */
    byte RDRT4       :1;                                       /* Reduced Drive Port T Bit 4 */
    byte RDRT5       :1;                                       /* Reduced Drive Port T Bit 5 */
    byte RDRT6       :1;                                       /* Reduced Drive Port T Bit 6 */
    byte RDRT7       :1;                                       /* Reduced Drive Port T Bit 7 */
  } Bits;
} RDRTSTR;
extern volatile RDRTSTR _RDRT @(REG_BASE + 0x00000243UL);
#define RDRT                            _RDRT.Byte
#define RDRT_RDRT0                      _RDRT.Bits.RDRT0
#define RDRT_RDRT1                      _RDRT.Bits.RDRT1
#define RDRT_RDRT2                      _RDRT.Bits.RDRT2
#define RDRT_RDRT3                      _RDRT.Bits.RDRT3
#define RDRT_RDRT4                      _RDRT.Bits.RDRT4
#define RDRT_RDRT5                      _RDRT.Bits.RDRT5
#define RDRT_RDRT6                      _RDRT.Bits.RDRT6
#define RDRT_RDRT7                      _RDRT.Bits.RDRT7

#define RDRT_RDRT0_MASK                 1U
#define RDRT_RDRT1_MASK                 2U
#define RDRT_RDRT2_MASK                 4U
#define RDRT_RDRT3_MASK                 8U
#define RDRT_RDRT4_MASK                 16U
#define RDRT_RDRT5_MASK                 32U
#define RDRT_RDRT6_MASK                 64U
#define RDRT_RDRT7_MASK                 128U


/*** PERT - Port T Pull Device Enable Register; 0x00000244 ***/
typedef union {
  byte Byte;
  struct {
    byte PERT0       :1;                                       /* Pull Device Enable Port T Bit 0 */
    byte PERT1       :1;                                       /* Pull Device Enable Port T Bit 1 */
    byte PERT2       :1;                                       /* Pull Device Enable Port T Bit 2 */
    byte PERT3       :1;                                       /* Pull Device Enable Port T Bit 3 */
    byte PERT4       :1;                                       /* Pull Device Enable Port T Bit 4 */
    byte PERT5       :1;                                       /* Pull Device Enable Port T Bit 5 */
    byte PERT6       :1;                                       /* Pull Device Enable Port T Bit 6 */
    byte PERT7       :1;                                       /* Pull Device Enable Port T Bit 7 */
  } Bits;
} PERTSTR;
extern volatile PERTSTR _PERT @(REG_BASE + 0x00000244UL);
#define PERT                            _PERT.Byte
#define PERT_PERT0                      _PERT.Bits.PERT0
#define PERT_PERT1                      _PERT.Bits.PERT1
#define PERT_PERT2                      _PERT.Bits.PERT2
#define PERT_PERT3                      _PERT.Bits.PERT3
#define PERT_PERT4                      _PERT.Bits.PERT4
#define PERT_PERT5                      _PERT.Bits.PERT5
#define PERT_PERT6                      _PERT.Bits.PERT6
#define PERT_PERT7                      _PERT.Bits.PERT7

#define PERT_PERT0_MASK                 1U
#define PERT_PERT1_MASK                 2U
#define PERT_PERT2_MASK                 4U
#define PERT_PERT3_MASK                 8U
#define PERT_PERT4_MASK                 16U
#define PERT_PERT5_MASK                 32U
#define PERT_PERT6_MASK                 64U
#define PERT_PERT7_MASK                 128U


/*** PPST - Port T Polarity Select Register; 0x00000245 ***/
typedef union {
  byte Byte;
  struct {
    byte PPST0       :1;                                       /* Pull Select Port T Bit 0 */
    byte PPST1       :1;                                       /* Pull Select Port T Bit 1 */
    byte PPST2       :1;                                       /* Pull Select Port T Bit 2 */
    byte PPST3       :1;                                       /* Pull Select Port T Bit 3 */
    byte PPST4       :1;                                       /* Pull Select Port T Bit 4 */
    byte PPST5       :1;                                       /* Pull Select Port T Bit 5 */
    byte PPST6       :1;                                       /* Pull Select Port T Bit 6 */
    byte PPST7       :1;                                       /* Pull Select Port T Bit 7 */
  } Bits;
} PPSTSTR;
extern volatile PPSTSTR _PPST @(REG_BASE + 0x00000245UL);
#define PPST                            _PPST.Byte
#define PPST_PPST0                      _PPST.Bits.PPST0
#define PPST_PPST1                      _PPST.Bits.PPST1
#define PPST_PPST2                      _PPST.Bits.PPST2
#define PPST_PPST3                      _PPST.Bits.PPST3
#define PPST_PPST4                      _PPST.Bits.PPST4
#define PPST_PPST5                      _PPST.Bits.PPST5
#define PPST_PPST6                      _PPST.Bits.PPST6
#define PPST_PPST7                      _PPST.Bits.PPST7

#define PPST_PPST0_MASK                 1U
#define PPST_PPST1_MASK                 2U
#define PPST_PPST2_MASK                 4U
#define PPST_PPST3_MASK                 8U
#define PPST_PPST4_MASK                 16U
#define PPST_PPST5_MASK                 32U
#define PPST_PPST6_MASK                 64U
#define PPST_PPST7_MASK                 128U


/*** MODRR - Module Routing Register; 0x00000247 ***/
typedef union {
  byte Byte;
  struct {
    byte MODRR0      :1;                                       /* Module Routing Bit 0 */
    byte MODRR1      :1;                                       /* Module Routing Bit 1 */
    byte MODRR2      :1;                                       /* Module Routing Bit 2 */
    byte MODRR3      :1;                                       /* Module Routing Bit 3 */
    byte MODRR4      :1;                                       /* Module Routing Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpMODRR :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MODRRSTR;
extern volatile MODRRSTR _MODRR @(REG_BASE + 0x00000247UL);
#define MODRR                           _MODRR.Byte
#define MODRR_MODRR0                    _MODRR.Bits.MODRR0
#define MODRR_MODRR1                    _MODRR.Bits.MODRR1
#define MODRR_MODRR2                    _MODRR.Bits.MODRR2
#define MODRR_MODRR3                    _MODRR.Bits.MODRR3
#define MODRR_MODRR4                    _MODRR.Bits.MODRR4
#define MODRR_MODRR                     _MODRR.MergedBits.grpMODRR

#define MODRR_MODRR0_MASK               1U
#define MODRR_MODRR1_MASK               2U
#define MODRR_MODRR2_MASK               4U
#define MODRR_MODRR3_MASK               8U
#define MODRR_MODRR4_MASK               16U
#define MODRR_MODRR_MASK                31U
#define MODRR_MODRR_BITNUM              0U


/*** PTS - Port S I/O Register; 0x00000248 ***/
typedef union {
  byte Byte;
  struct {
    byte PTS0        :1;                                       /* Port S Bit 0 */
    byte PTS1        :1;                                       /* Port S Bit 1 */
    byte PTS2        :1;                                       /* Port S Bit 2 */
    byte PTS3        :1;                                       /* Port S Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTS  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTSSTR;
extern volatile PTSSTR _PTS @(REG_BASE + 0x00000248UL);
#define PTS                             _PTS.Byte
#define PTS_PTS0                        _PTS.Bits.PTS0
#define PTS_PTS1                        _PTS.Bits.PTS1
#define PTS_PTS2                        _PTS.Bits.PTS2
#define PTS_PTS3                        _PTS.Bits.PTS3
#define PTS_PTS                         _PTS.MergedBits.grpPTS

#define PTS_PTS0_MASK                   1U
#define PTS_PTS1_MASK                   2U
#define PTS_PTS2_MASK                   4U
#define PTS_PTS3_MASK                   8U
#define PTS_PTS_MASK                    15U
#define PTS_PTS_BITNUM                  0U


/*** PTIS - Port S Input Register; 0x00000249 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIS0       :1;                                       /* Port S Bit 0 */
    byte PTIS1       :1;                                       /* Port S Bit 1 */
    byte PTIS2       :1;                                       /* Port S Bit 2 */
    byte PTIS3       :1;                                       /* Port S Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTIS :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTISSTR;
extern volatile PTISSTR _PTIS @(REG_BASE + 0x00000249UL);
#define PTIS                            _PTIS.Byte
#define PTIS_PTIS0                      _PTIS.Bits.PTIS0
#define PTIS_PTIS1                      _PTIS.Bits.PTIS1
#define PTIS_PTIS2                      _PTIS.Bits.PTIS2
#define PTIS_PTIS3                      _PTIS.Bits.PTIS3
#define PTIS_PTIS                       _PTIS.MergedBits.grpPTIS

#define PTIS_PTIS0_MASK                 1U
#define PTIS_PTIS1_MASK                 2U
#define PTIS_PTIS2_MASK                 4U
#define PTIS_PTIS3_MASK                 8U
#define PTIS_PTIS_MASK                  15U
#define PTIS_PTIS_BITNUM                0U


/*** DDRS - Port S Data Direction Register; 0x0000024A ***/
typedef union {
  byte Byte;
  struct {
    byte DDRS0       :1;                                       /* Data Direction Port S Bit 0 */
    byte DDRS1       :1;                                       /* Data Direction Port S Bit 1 */
    byte DDRS2       :1;                                       /* Data Direction Port S Bit 2 */
    byte DDRS3       :1;                                       /* Data Direction Port S Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDDRS :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DDRSSTR;
extern volatile DDRSSTR _DDRS @(REG_BASE + 0x0000024AUL);
#define DDRS                            _DDRS.Byte
#define DDRS_DDRS0                      _DDRS.Bits.DDRS0
#define DDRS_DDRS1                      _DDRS.Bits.DDRS1
#define DDRS_DDRS2                      _DDRS.Bits.DDRS2
#define DDRS_DDRS3                      _DDRS.Bits.DDRS3
#define DDRS_DDRS                       _DDRS.MergedBits.grpDDRS

#define DDRS_DDRS0_MASK                 1U
#define DDRS_DDRS1_MASK                 2U
#define DDRS_DDRS2_MASK                 4U
#define DDRS_DDRS3_MASK                 8U
#define DDRS_DDRS_MASK                  15U
#define DDRS_DDRS_BITNUM                0U


/*** RDRS - Port S Reduced Drive Register; 0x0000024B ***/
typedef union {
  byte Byte;
  struct {
    byte RDRS0       :1;                                       /* Reduced Drive Port S Bit 0 */
    byte RDRS1       :1;                                       /* Reduced Drive Port S Bit 1 */
    byte RDRS2       :1;                                       /* Reduced Drive Port S Bit 2 */
    byte RDRS3       :1;                                       /* Reduced Drive Port S Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpRDRS :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} RDRSSTR;
extern volatile RDRSSTR _RDRS @(REG_BASE + 0x0000024BUL);
#define RDRS                            _RDRS.Byte
#define RDRS_RDRS0                      _RDRS.Bits.RDRS0
#define RDRS_RDRS1                      _RDRS.Bits.RDRS1
#define RDRS_RDRS2                      _RDRS.Bits.RDRS2
#define RDRS_RDRS3                      _RDRS.Bits.RDRS3
#define RDRS_RDRS                       _RDRS.MergedBits.grpRDRS

#define RDRS_RDRS0_MASK                 1U
#define RDRS_RDRS1_MASK                 2U
#define RDRS_RDRS2_MASK                 4U
#define RDRS_RDRS3_MASK                 8U
#define RDRS_RDRS_MASK                  15U
#define RDRS_RDRS_BITNUM                0U


/*** PERS - Port S Pull Device Enable Register; 0x0000024C ***/
typedef union {
  byte Byte;
  struct {
    byte PERS0       :1;                                       /* Pull Device Enable Port S Bit 0 */
    byte PERS1       :1;                                       /* Pull Device Enable Port S Bit 1 */
    byte PERS2       :1;                                       /* Pull Device Enable Port S Bit 2 */
    byte PERS3       :1;                                       /* Pull Device Enable Port S Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPERS :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PERSSTR;
extern volatile PERSSTR _PERS @(REG_BASE + 0x0000024CUL);
#define PERS                            _PERS.Byte
#define PERS_PERS0                      _PERS.Bits.PERS0
#define PERS_PERS1                      _PERS.Bits.PERS1
#define PERS_PERS2                      _PERS.Bits.PERS2
#define PERS_PERS3                      _PERS.Bits.PERS3
#define PERS_PERS                       _PERS.MergedBits.grpPERS

#define PERS_PERS0_MASK                 1U
#define PERS_PERS1_MASK                 2U
#define PERS_PERS2_MASK                 4U
#define PERS_PERS3_MASK                 8U
#define PERS_PERS_MASK                  15U
#define PERS_PERS_BITNUM                0U


/*** PPSS - Port S Polarity Select Register; 0x0000024D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSS0       :1;                                       /* Pull Select Port S Bit 0 */
    byte PPSS1       :1;                                       /* Pull Select Port S Bit 1 */
    byte PPSS2       :1;                                       /* Pull Select Port S Bit 2 */
    byte PPSS3       :1;                                       /* Pull Select Port S Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPPSS :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPSSSTR;
extern volatile PPSSSTR _PPSS @(REG_BASE + 0x0000024DUL);
#define PPSS                            _PPSS.Byte
#define PPSS_PPSS0                      _PPSS.Bits.PPSS0
#define PPSS_PPSS1                      _PPSS.Bits.PPSS1
#define PPSS_PPSS2                      _PPSS.Bits.PPSS2
#define PPSS_PPSS3                      _PPSS.Bits.PPSS3
#define PPSS_PPSS                       _PPSS.MergedBits.grpPPSS

#define PPSS_PPSS0_MASK                 1U
#define PPSS_PPSS1_MASK                 2U
#define PPSS_PPSS2_MASK                 4U
#define PPSS_PPSS3_MASK                 8U
#define PPSS_PPSS_MASK                  15U
#define PPSS_PPSS_BITNUM                0U


/*** WOMS - Port S Wired-Or Mode Register; 0x0000024E ***/
typedef union {
  byte Byte;
  struct {
    byte WOMS0       :1;                                       /* Wired-Or Mode Port S Bit 0 */
    byte WOMS1       :1;                                       /* Wired-Or Mode Port S Bit 1 */
    byte WOMS2       :1;                                       /* Wired-Or Mode Port S Bit 2 */
    byte WOMS3       :1;                                       /* Wired-Or Mode Port S Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpWOMS :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} WOMSSTR;
extern volatile WOMSSTR _WOMS @(REG_BASE + 0x0000024EUL);
#define WOMS                            _WOMS.Byte
#define WOMS_WOMS0                      _WOMS.Bits.WOMS0
#define WOMS_WOMS1                      _WOMS.Bits.WOMS1
#define WOMS_WOMS2                      _WOMS.Bits.WOMS2
#define WOMS_WOMS3                      _WOMS.Bits.WOMS3
#define WOMS_WOMS                       _WOMS.MergedBits.grpWOMS

#define WOMS_WOMS0_MASK                 1U
#define WOMS_WOMS1_MASK                 2U
#define WOMS_WOMS2_MASK                 4U
#define WOMS_WOMS3_MASK                 8U
#define WOMS_WOMS_MASK                  15U
#define WOMS_WOMS_BITNUM                0U


/*** PTM - Port M I/O Register; 0x00000250 ***/
typedef union {
  byte Byte;
  struct {
    byte PTM0        :1;                                       /* Port M Bit 0 */
    byte PTM1        :1;                                       /* Port M Bit 1 */
    byte PTM2        :1;                                       /* Port M Bit 2 */
    byte PTM3        :1;                                       /* Port M Bit 3 */
    byte PTM4        :1;                                       /* Port M Bit 4 */
    byte PTM5        :1;                                       /* Port M Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTM  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTMSTR;
extern volatile PTMSTR _PTM @(REG_BASE + 0x00000250UL);
#define PTM                             _PTM.Byte
#define PTM_PTM0                        _PTM.Bits.PTM0
#define PTM_PTM1                        _PTM.Bits.PTM1
#define PTM_PTM2                        _PTM.Bits.PTM2
#define PTM_PTM3                        _PTM.Bits.PTM3
#define PTM_PTM4                        _PTM.Bits.PTM4
#define PTM_PTM5                        _PTM.Bits.PTM5
#define PTM_PTM                         _PTM.MergedBits.grpPTM

#define PTM_PTM0_MASK                   1U
#define PTM_PTM1_MASK                   2U
#define PTM_PTM2_MASK                   4U
#define PTM_PTM3_MASK                   8U
#define PTM_PTM4_MASK                   16U
#define PTM_PTM5_MASK                   32U
#define PTM_PTM_MASK                    63U
#define PTM_PTM_BITNUM                  0U


/*** PTIM - Port M Input Register; 0x00000251 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIM0       :1;                                       /* Port M Bit 0 */
    byte PTIM1       :1;                                       /* Port M Bit 1 */
    byte PTIM2       :1;                                       /* Port M Bit 2 */
    byte PTIM3       :1;                                       /* Port M Bit 3 */
    byte PTIM4       :1;                                       /* Port M Bit 4 */
    byte PTIM5       :1;                                       /* Port M Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTIM :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTIMSTR;
extern volatile PTIMSTR _PTIM @(REG_BASE + 0x00000251UL);
#define PTIM                            _PTIM.Byte
#define PTIM_PTIM0                      _PTIM.Bits.PTIM0
#define PTIM_PTIM1                      _PTIM.Bits.PTIM1
#define PTIM_PTIM2                      _PTIM.Bits.PTIM2
#define PTIM_PTIM3                      _PTIM.Bits.PTIM3
#define PTIM_PTIM4                      _PTIM.Bits.PTIM4
#define PTIM_PTIM5                      _PTIM.Bits.PTIM5
#define PTIM_PTIM                       _PTIM.MergedBits.grpPTIM

#define PTIM_PTIM0_MASK                 1U
#define PTIM_PTIM1_MASK                 2U
#define PTIM_PTIM2_MASK                 4U
#define PTIM_PTIM3_MASK                 8U
#define PTIM_PTIM4_MASK                 16U
#define PTIM_PTIM5_MASK                 32U
#define PTIM_PTIM_MASK                  63U
#define PTIM_PTIM_BITNUM                0U


/*** DDRM - Port M Data Direction Register; 0x00000252 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRM0       :1;                                       /* Data Direction Port M Bit 0 */
    byte DDRM1       :1;                                       /* Data Direction Port M Bit 1 */
    byte DDRM2       :1;                                       /* Data Direction Port M Bit 2 */
    byte DDRM3       :1;                                       /* Data Direction Port M Bit 3 */
    byte DDRM4       :1;                                       /* Data Direction Port M Bit 4 */
    byte DDRM5       :1;                                       /* Data Direction Port M Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDDRM :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} DDRMSTR;
extern volatile DDRMSTR _DDRM @(REG_BASE + 0x00000252UL);
#define DDRM                            _DDRM.Byte
#define DDRM_DDRM0                      _DDRM.Bits.DDRM0
#define DDRM_DDRM1                      _DDRM.Bits.DDRM1
#define DDRM_DDRM2                      _DDRM.Bits.DDRM2
#define DDRM_DDRM3                      _DDRM.Bits.DDRM3
#define DDRM_DDRM4                      _DDRM.Bits.DDRM4
#define DDRM_DDRM5                      _DDRM.Bits.DDRM5
#define DDRM_DDRM                       _DDRM.MergedBits.grpDDRM

#define DDRM_DDRM0_MASK                 1U
#define DDRM_DDRM1_MASK                 2U
#define DDRM_DDRM2_MASK                 4U
#define DDRM_DDRM3_MASK                 8U
#define DDRM_DDRM4_MASK                 16U
#define DDRM_DDRM5_MASK                 32U
#define DDRM_DDRM_MASK                  63U
#define DDRM_DDRM_BITNUM                0U


/*** RDRM - Port M Reduced Drive Register; 0x00000253 ***/
typedef union {
  byte Byte;
  struct {
    byte RDRM0       :1;                                       /* Reduced Drive Port M Bit 0 */
    byte RDRM1       :1;                                       /* Reduced Drive Port M Bit 1 */
    byte RDRM2       :1;                                       /* Reduced Drive Port M Bit 2 */
    byte RDRM3       :1;                                       /* Reduced Drive Port M Bit 3 */
    byte RDRM4       :1;                                       /* Reduced Drive Port M Bit 4 */
    byte RDRM5       :1;                                       /* Reduced Drive Port M Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpRDRM :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} RDRMSTR;
extern volatile RDRMSTR _RDRM @(REG_BASE + 0x00000253UL);
#define RDRM                            _RDRM.Byte
#define RDRM_RDRM0                      _RDRM.Bits.RDRM0
#define RDRM_RDRM1                      _RDRM.Bits.RDRM1
#define RDRM_RDRM2                      _RDRM.Bits.RDRM2
#define RDRM_RDRM3                      _RDRM.Bits.RDRM3
#define RDRM_RDRM4                      _RDRM.Bits.RDRM4
#define RDRM_RDRM5                      _RDRM.Bits.RDRM5
#define RDRM_RDRM                       _RDRM.MergedBits.grpRDRM

#define RDRM_RDRM0_MASK                 1U
#define RDRM_RDRM1_MASK                 2U
#define RDRM_RDRM2_MASK                 4U
#define RDRM_RDRM3_MASK                 8U
#define RDRM_RDRM4_MASK                 16U
#define RDRM_RDRM5_MASK                 32U
#define RDRM_RDRM_MASK                  63U
#define RDRM_RDRM_BITNUM                0U


/*** PERM - Port M Pull Device Enable Register; 0x00000254 ***/
typedef union {
  byte Byte;
  struct {
    byte PERM0       :1;                                       /* Pull Device Enable Port M Bit 0 */
    byte PERM1       :1;                                       /* Pull Device Enable Port M Bit 1 */
    byte PERM2       :1;                                       /* Pull Device Enable Port M Bit 2 */
    byte PERM3       :1;                                       /* Pull Device Enable Port M Bit 3 */
    byte PERM4       :1;                                       /* Pull Device Enable Port M Bit 4 */
    byte PERM5       :1;                                       /* Pull Device Enable Port M Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPERM :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PERMSTR;
extern volatile PERMSTR _PERM @(REG_BASE + 0x00000254UL);
#define PERM                            _PERM.Byte
#define PERM_PERM0                      _PERM.Bits.PERM0
#define PERM_PERM1                      _PERM.Bits.PERM1
#define PERM_PERM2                      _PERM.Bits.PERM2
#define PERM_PERM3                      _PERM.Bits.PERM3
#define PERM_PERM4                      _PERM.Bits.PERM4
#define PERM_PERM5                      _PERM.Bits.PERM5
#define PERM_PERM                       _PERM.MergedBits.grpPERM

#define PERM_PERM0_MASK                 1U
#define PERM_PERM1_MASK                 2U
#define PERM_PERM2_MASK                 4U
#define PERM_PERM3_MASK                 8U
#define PERM_PERM4_MASK                 16U
#define PERM_PERM5_MASK                 32U
#define PERM_PERM_MASK                  63U
#define PERM_PERM_BITNUM                0U


/*** PPSM - Port M Polarity Select Register; 0x00000255 ***/
typedef union {
  byte Byte;
  struct {
    byte PPSM0       :1;                                       /* Pull Select Port M Bit 0 */
    byte PPSM1       :1;                                       /* Pull Select Port M Bit 1 */
    byte PPSM2       :1;                                       /* Pull Select Port M Bit 2 */
    byte PPSM3       :1;                                       /* Pull Select Port M Bit 3 */
    byte PPSM4       :1;                                       /* Pull Select Port M Bit 4 */
    byte PPSM5       :1;                                       /* Pull Select Port M Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPPSM :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPSMSTR;
extern volatile PPSMSTR _PPSM @(REG_BASE + 0x00000255UL);
#define PPSM                            _PPSM.Byte
#define PPSM_PPSM0                      _PPSM.Bits.PPSM0
#define PPSM_PPSM1                      _PPSM.Bits.PPSM1
#define PPSM_PPSM2                      _PPSM.Bits.PPSM2
#define PPSM_PPSM3                      _PPSM.Bits.PPSM3
#define PPSM_PPSM4                      _PPSM.Bits.PPSM4
#define PPSM_PPSM5                      _PPSM.Bits.PPSM5
#define PPSM_PPSM                       _PPSM.MergedBits.grpPPSM

#define PPSM_PPSM0_MASK                 1U
#define PPSM_PPSM1_MASK                 2U
#define PPSM_PPSM2_MASK                 4U
#define PPSM_PPSM3_MASK                 8U
#define PPSM_PPSM4_MASK                 16U
#define PPSM_PPSM5_MASK                 32U
#define PPSM_PPSM_MASK                  63U
#define PPSM_PPSM_BITNUM                0U


/*** WOMM - Port M Wired-Or Mode Register; 0x00000256 ***/
typedef union {
  byte Byte;
  struct {
    byte WOMM0       :1;                                       /* Wired-Or Mode Port M Bit 0 */
    byte WOMM1       :1;                                       /* Wired-Or Mode Port M Bit 1 */
    byte WOMM2       :1;                                       /* Wired-Or Mode Port M Bit 2 */
    byte WOMM3       :1;                                       /* Wired-Or Mode Port M Bit 3 */
    byte WOMM4       :1;                                       /* Wired-Or Mode Port M Bit 4 */
    byte WOMM5       :1;                                       /* Wired-Or Mode Port M Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpWOMM :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} WOMMSTR;
extern volatile WOMMSTR _WOMM @(REG_BASE + 0x00000256UL);
#define WOMM                            _WOMM.Byte
#define WOMM_WOMM0                      _WOMM.Bits.WOMM0
#define WOMM_WOMM1                      _WOMM.Bits.WOMM1
#define WOMM_WOMM2                      _WOMM.Bits.WOMM2
#define WOMM_WOMM3                      _WOMM.Bits.WOMM3
#define WOMM_WOMM4                      _WOMM.Bits.WOMM4
#define WOMM_WOMM5                      _WOMM.Bits.WOMM5
#define WOMM_WOMM                       _WOMM.MergedBits.grpWOMM

#define WOMM_WOMM0_MASK                 1U
#define WOMM_WOMM1_MASK                 2U
#define WOMM_WOMM2_MASK                 4U
#define WOMM_WOMM3_MASK                 8U
#define WOMM_WOMM4_MASK                 16U
#define WOMM_WOMM5_MASK                 32U
#define WOMM_WOMM_MASK                  63U
#define WOMM_WOMM_BITNUM                0U


/*** PTP - Port P I/O Register; 0x00000258 ***/
typedef union {
  byte Byte;
  struct {
    byte PTP0        :1;                                       /* Port P Bit 0 */
    byte PTP1        :1;                                       /* Port P Bit 1 */
    byte PTP2        :1;                                       /* Port P Bit 2 */
    byte PTP3        :1;                                       /* Port P Bit 3 */
    byte PTP4        :1;                                       /* Port P Bit 4 */
    byte PTP5        :1;                                       /* Port P Bit 5 */
    byte PTP6        :1;                                       /* Port P Bit 6 */
    byte PTP7        :1;                                       /* Port P Bit 7 */
  } Bits;
} PTPSTR;
extern volatile PTPSTR _PTP @(REG_BASE + 0x00000258UL);
#define PTP                             _PTP.Byte
#define PTP_PTP0                        _PTP.Bits.PTP0
#define PTP_PTP1                        _PTP.Bits.PTP1
#define PTP_PTP2                        _PTP.Bits.PTP2
#define PTP_PTP3                        _PTP.Bits.PTP3
#define PTP_PTP4                        _PTP.Bits.PTP4
#define PTP_PTP5                        _PTP.Bits.PTP5
#define PTP_PTP6                        _PTP.Bits.PTP6
#define PTP_PTP7                        _PTP.Bits.PTP7

#define PTP_PTP0_MASK                   1U
#define PTP_PTP1_MASK                   2U
#define PTP_PTP2_MASK                   4U
#define PTP_PTP3_MASK                   8U
#define PTP_PTP4_MASK                   16U
#define PTP_PTP5_MASK                   32U
#define PTP_PTP6_MASK                   64U
#define PTP_PTP7_MASK                   128U


/*** PTIP - Port P Input Register; 0x00000259 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIP0       :1;                                       /* Port P Bit 0 */
    byte PTIP1       :1;                                       /* Port P Bit 1 */
    byte PTIP2       :1;                                       /* Port P Bit 2 */
    byte PTIP3       :1;                                       /* Port P Bit 3 */
    byte PTIP4       :1;                                       /* Port P Bit 4 */
    byte PTIP5       :1;                                       /* Port P Bit 5 */
    byte PTIP6       :1;                                       /* Port P Bit 6 */
    byte PTIP7       :1;                                       /* Port P Bit 7 */
  } Bits;
} PTIPSTR;
extern volatile PTIPSTR _PTIP @(REG_BASE + 0x00000259UL);
#define PTIP                            _PTIP.Byte
#define PTIP_PTIP0                      _PTIP.Bits.PTIP0
#define PTIP_PTIP1                      _PTIP.Bits.PTIP1
#define PTIP_PTIP2                      _PTIP.Bits.PTIP2
#define PTIP_PTIP3                      _PTIP.Bits.PTIP3
#define PTIP_PTIP4                      _PTIP.Bits.PTIP4
#define PTIP_PTIP5                      _PTIP.Bits.PTIP5
#define PTIP_PTIP6                      _PTIP.Bits.PTIP6
#define PTIP_PTIP7                      _PTIP.Bits.PTIP7

#define PTIP_PTIP0_MASK                 1U
#define PTIP_PTIP1_MASK                 2U
#define PTIP_PTIP2_MASK                 4U
#define PTIP_PTIP3_MASK                 8U
#define PTIP_PTIP4_MASK                 16U
#define PTIP_PTIP5_MASK                 32U
#define PTIP_PTIP6_MASK                 64U
#define PTIP_PTIP7_MASK                 128U


/*** DDRP - Port P Data Direction Register; 0x0000025A ***/
typedef union {
  byte Byte;
  struct {
    byte DDRP0       :1;                                       /* Data Direction Port P Bit 0 */
    byte DDRP1       :1;                                       /* Data Direction Port P Bit 1 */
    byte DDRP2       :1;                                       /* Data Direction Port P Bit 2 */
    byte DDRP3       :1;                                       /* Data Direction Port P Bit 3 */
    byte DDRP4       :1;                                       /* Data Direction Port P Bit 4 */
    byte DDRP5       :1;                                       /* Data Direction Port P Bit 5 */
    byte DDRP6       :1;                                       /* Data Direction Port P Bit 6 */
    byte DDRP7       :1;                                       /* Data Direction Port P Bit 7 */
  } Bits;
} DDRPSTR;
extern volatile DDRPSTR _DDRP @(REG_BASE + 0x0000025AUL);
#define DDRP                            _DDRP.Byte
#define DDRP_DDRP0                      _DDRP.Bits.DDRP0
#define DDRP_DDRP1                      _DDRP.Bits.DDRP1
#define DDRP_DDRP2                      _DDRP.Bits.DDRP2
#define DDRP_DDRP3                      _DDRP.Bits.DDRP3
#define DDRP_DDRP4                      _DDRP.Bits.DDRP4
#define DDRP_DDRP5                      _DDRP.Bits.DDRP5
#define DDRP_DDRP6                      _DDRP.Bits.DDRP6
#define DDRP_DDRP7                      _DDRP.Bits.DDRP7

#define DDRP_DDRP0_MASK                 1U
#define DDRP_DDRP1_MASK                 2U
#define DDRP_DDRP2_MASK                 4U
#define DDRP_DDRP3_MASK                 8U
#define DDRP_DDRP4_MASK                 16U
#define DDRP_DDRP5_MASK                 32U
#define DDRP_DDRP6_MASK                 64U
#define DDRP_DDRP7_MASK                 128U


/*** RDRP - Port P Reduced Drive Register; 0x0000025B ***/
typedef union {
  byte Byte;
  struct {
    byte RDRP0       :1;                                       /* Reduced Drive Port P Bit 0 */
    byte RDRP1       :1;                                       /* Reduced Drive Port P Bit 1 */
    byte RDRP2       :1;                                       /* Reduced Drive Port P Bit 2 */
    byte RDRP3       :1;                                       /* Reduced Drive Port P Bit 3 */
    byte RDRP4       :1;                                       /* Reduced Drive Port P Bit 4 */
    byte RDRP5       :1;                                       /* Reduced Drive Port P Bit 5 */
    byte RDRP6       :1;                                       /* Reduced Drive Port P Bit 6 */
    byte RDRP7       :1;                                       /* Reduced Drive Port P Bit 7 */
  } Bits;
} RDRPSTR;
extern volatile RDRPSTR _RDRP @(REG_BASE + 0x0000025BUL);
#define RDRP                            _RDRP.Byte
#define RDRP_RDRP0                      _RDRP.Bits.RDRP0
#define RDRP_RDRP1                      _RDRP.Bits.RDRP1
#define RDRP_RDRP2                      _RDRP.Bits.RDRP2
#define RDRP_RDRP3                      _RDRP.Bits.RDRP3
#define RDRP_RDRP4                      _RDRP.Bits.RDRP4
#define RDRP_RDRP5                      _RDRP.Bits.RDRP5
#define RDRP_RDRP6                      _RDRP.Bits.RDRP6
#define RDRP_RDRP7                      _RDRP.Bits.RDRP7

#define RDRP_RDRP0_MASK                 1U
#define RDRP_RDRP1_MASK                 2U
#define RDRP_RDRP2_MASK                 4U
#define RDRP_RDRP3_MASK                 8U
#define RDRP_RDRP4_MASK                 16U
#define RDRP_RDRP5_MASK                 32U
#define RDRP_RDRP6_MASK                 64U
#define RDRP_RDRP7_MASK                 128U


/*** PERP - Port P Pull Device Enable Register; 0x0000025C ***/
typedef union {
  byte Byte;
  struct {
    byte PERP0       :1;                                       /* Pull Device Enable Port P Bit 0 */
    byte PERP1       :1;                                       /* Pull Device Enable Port P Bit 1 */
    byte PERP2       :1;                                       /* Pull Device Enable Port P Bit 2 */
    byte PERP3       :1;                                       /* Pull Device Enable Port P Bit 3 */
    byte PERP4       :1;                                       /* Pull Device Enable Port P Bit 4 */
    byte PERP5       :1;                                       /* Pull Device Enable Port P Bit 5 */
    byte PERP6       :1;                                       /* Pull Device Enable Port P Bit 6 */
    byte PERP7       :1;                                       /* Pull Device Enable Port P Bit 7 */
  } Bits;
} PERPSTR;
extern volatile PERPSTR _PERP @(REG_BASE + 0x0000025CUL);
#define PERP                            _PERP.Byte
#define PERP_PERP0                      _PERP.Bits.PERP0
#define PERP_PERP1                      _PERP.Bits.PERP1
#define PERP_PERP2                      _PERP.Bits.PERP2
#define PERP_PERP3                      _PERP.Bits.PERP3
#define PERP_PERP4                      _PERP.Bits.PERP4
#define PERP_PERP5                      _PERP.Bits.PERP5
#define PERP_PERP6                      _PERP.Bits.PERP6
#define PERP_PERP7                      _PERP.Bits.PERP7

#define PERP_PERP0_MASK                 1U
#define PERP_PERP1_MASK                 2U
#define PERP_PERP2_MASK                 4U
#define PERP_PERP3_MASK                 8U
#define PERP_PERP4_MASK                 16U
#define PERP_PERP5_MASK                 32U
#define PERP_PERP6_MASK                 64U
#define PERP_PERP7_MASK                 128U


/*** PPSP - Port P Polarity Select Register; 0x0000025D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSP0       :1;                                       /* Pull Select Port P Bit 0 */
    byte PPSP1       :1;                                       /* Pull Select Port P Bit 1 */
    byte PPSP2       :1;                                       /* Pull Select Port P Bit 2 */
    byte PPSP3       :1;                                       /* Pull Select Port P Bit 3 */
    byte PPSP4       :1;                                       /* Pull Select Port P Bit 4 */
    byte PPSP5       :1;                                       /* Pull Select Port P Bit 5 */
    byte PPSP6       :1;                                       /* Pull Select Port P Bit 6 */
    byte PPSP7       :1;                                       /* Pull Select Port P Bit 7 */
  } Bits;
} PPSPSTR;
extern volatile PPSPSTR _PPSP @(REG_BASE + 0x0000025DUL);
#define PPSP                            _PPSP.Byte
#define PPSP_PPSP0                      _PPSP.Bits.PPSP0
#define PPSP_PPSP1                      _PPSP.Bits.PPSP1
#define PPSP_PPSP2                      _PPSP.Bits.PPSP2
#define PPSP_PPSP3                      _PPSP.Bits.PPSP3
#define PPSP_PPSP4                      _PPSP.Bits.PPSP4
#define PPSP_PPSP5                      _PPSP.Bits.PPSP5
#define PPSP_PPSP6                      _PPSP.Bits.PPSP6
#define PPSP_PPSP7                      _PPSP.Bits.PPSP7

#define PPSP_PPSP0_MASK                 1U
#define PPSP_PPSP1_MASK                 2U
#define PPSP_PPSP2_MASK                 4U
#define PPSP_PPSP3_MASK                 8U
#define PPSP_PPSP4_MASK                 16U
#define PPSP_PPSP5_MASK                 32U
#define PPSP_PPSP6_MASK                 64U
#define PPSP_PPSP7_MASK                 128U


/*** PIEP - Port P Interrupt Enable Register; 0x0000025E ***/
typedef union {
  byte Byte;
  struct {
    byte PIEP0       :1;                                       /* Interrupt Enable Port P Bit 0 */
    byte PIEP1       :1;                                       /* Interrupt Enable Port P Bit 1 */
    byte PIEP2       :1;                                       /* Interrupt Enable Port P Bit 2 */
    byte PIEP3       :1;                                       /* Interrupt Enable Port P Bit 3 */
    byte PIEP4       :1;                                       /* Interrupt Enable Port P Bit 4 */
    byte PIEP5       :1;                                       /* Interrupt Enable Port P Bit 5 */
    byte PIEP6       :1;                                       /* Interrupt Enable Port P Bit 6 */
    byte PIEP7       :1;                                       /* Interrupt Enable Port P Bit 7 */
  } Bits;
} PIEPSTR;
extern volatile PIEPSTR _PIEP @(REG_BASE + 0x0000025EUL);
#define PIEP                            _PIEP.Byte
#define PIEP_PIEP0                      _PIEP.Bits.PIEP0
#define PIEP_PIEP1                      _PIEP.Bits.PIEP1
#define PIEP_PIEP2                      _PIEP.Bits.PIEP2
#define PIEP_PIEP3                      _PIEP.Bits.PIEP3
#define PIEP_PIEP4                      _PIEP.Bits.PIEP4
#define PIEP_PIEP5                      _PIEP.Bits.PIEP5
#define PIEP_PIEP6                      _PIEP.Bits.PIEP6
#define PIEP_PIEP7                      _PIEP.Bits.PIEP7

#define PIEP_PIEP0_MASK                 1U
#define PIEP_PIEP1_MASK                 2U
#define PIEP_PIEP2_MASK                 4U
#define PIEP_PIEP3_MASK                 8U
#define PIEP_PIEP4_MASK                 16U
#define PIEP_PIEP5_MASK                 32U
#define PIEP_PIEP6_MASK                 64U
#define PIEP_PIEP7_MASK                 128U


/*** PIFP - Port P Interrupt Flag Register; 0x0000025F ***/
typedef union {
  byte Byte;
  struct {
    byte PIFP0       :1;                                       /* Interrupt Flags Port P Bit 0 */
    byte PIFP1       :1;                                       /* Interrupt Flags Port P Bit 1 */
    byte PIFP2       :1;                                       /* Interrupt Flags Port P Bit 2 */
    byte PIFP3       :1;                                       /* Interrupt Flags Port P Bit 3 */
    byte PIFP4       :1;                                       /* Interrupt Flags Port P Bit 4 */
    byte PIFP5       :1;                                       /* Interrupt Flags Port P Bit 5 */
    byte PIFP6       :1;                                       /* Interrupt Flags Port P Bit 6 */
    byte PIFP7       :1;                                       /* Interrupt Flags Port P Bit 7 */
  } Bits;
} PIFPSTR;
extern volatile PIFPSTR _PIFP @(REG_BASE + 0x0000025FUL);
#define PIFP                            _PIFP.Byte
#define PIFP_PIFP0                      _PIFP.Bits.PIFP0
#define PIFP_PIFP1                      _PIFP.Bits.PIFP1
#define PIFP_PIFP2                      _PIFP.Bits.PIFP2
#define PIFP_PIFP3                      _PIFP.Bits.PIFP3
#define PIFP_PIFP4                      _PIFP.Bits.PIFP4
#define PIFP_PIFP5                      _PIFP.Bits.PIFP5
#define PIFP_PIFP6                      _PIFP.Bits.PIFP6
#define PIFP_PIFP7                      _PIFP.Bits.PIFP7

#define PIFP_PIFP0_MASK                 1U
#define PIFP_PIFP1_MASK                 2U
#define PIFP_PIFP2_MASK                 4U
#define PIFP_PIFP3_MASK                 8U
#define PIFP_PIFP4_MASK                 16U
#define PIFP_PIFP5_MASK                 32U
#define PIFP_PIFP6_MASK                 64U
#define PIFP_PIFP7_MASK                 128U


/*** PTJ - Port J I/O Register; 0x00000268 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PTJ6        :1;                                       /* Port J Bit 6 */
    byte PTJ7        :1;                                       /* Port J Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPTJ_6 :2;
  } MergedBits;
} PTJSTR;
extern volatile PTJSTR _PTJ @(REG_BASE + 0x00000268UL);
#define PTJ                             _PTJ.Byte
#define PTJ_PTJ6                        _PTJ.Bits.PTJ6
#define PTJ_PTJ7                        _PTJ.Bits.PTJ7
#define PTJ_PTJ_6                       _PTJ.MergedBits.grpPTJ_6

#define PTJ_PTJ6_MASK                   64U
#define PTJ_PTJ7_MASK                   128U
#define PTJ_PTJ_6_MASK                  192U
#define PTJ_PTJ_6_BITNUM                6U


/*** PTIJ - Port J Input Register; 0x00000269 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PTIJ6       :1;                                       /* Port J Bit 6 */
    byte PTIJ7       :1;                                       /* Port J Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPTIJ_6 :2;
  } MergedBits;
} PTIJSTR;
extern volatile PTIJSTR _PTIJ @(REG_BASE + 0x00000269UL);
#define PTIJ                            _PTIJ.Byte
#define PTIJ_PTIJ6                      _PTIJ.Bits.PTIJ6
#define PTIJ_PTIJ7                      _PTIJ.Bits.PTIJ7
#define PTIJ_PTIJ_6                     _PTIJ.MergedBits.grpPTIJ_6

#define PTIJ_PTIJ6_MASK                 64U
#define PTIJ_PTIJ7_MASK                 128U
#define PTIJ_PTIJ_6_MASK                192U
#define PTIJ_PTIJ_6_BITNUM              6U


/*** DDRJ - Port J Data Direction Register; 0x0000026A ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DDRJ6       :1;                                       /* Data Direction Port J Bit 6 */
    byte DDRJ7       :1;                                       /* Data Direction Port J Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpDDRJ_6 :2;
  } MergedBits;
} DDRJSTR;
extern volatile DDRJSTR _DDRJ @(REG_BASE + 0x0000026AUL);
#define DDRJ                            _DDRJ.Byte
#define DDRJ_DDRJ6                      _DDRJ.Bits.DDRJ6
#define DDRJ_DDRJ7                      _DDRJ.Bits.DDRJ7
#define DDRJ_DDRJ_6                     _DDRJ.MergedBits.grpDDRJ_6

#define DDRJ_DDRJ6_MASK                 64U
#define DDRJ_DDRJ7_MASK                 128U
#define DDRJ_DDRJ_6_MASK                192U
#define DDRJ_DDRJ_6_BITNUM              6U


/*** RDRJ - Port J Reduced Drive Register; 0x0000026B ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RDRJ6       :1;                                       /* Reduced Drive Port J Bit 6 */
    byte RDRJ7       :1;                                       /* Reduced Drive Port J Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpRDRJ_6 :2;
  } MergedBits;
} RDRJSTR;
extern volatile RDRJSTR _RDRJ @(REG_BASE + 0x0000026BUL);
#define RDRJ                            _RDRJ.Byte
#define RDRJ_RDRJ6                      _RDRJ.Bits.RDRJ6
#define RDRJ_RDRJ7                      _RDRJ.Bits.RDRJ7
#define RDRJ_RDRJ_6                     _RDRJ.MergedBits.grpRDRJ_6

#define RDRJ_RDRJ6_MASK                 64U
#define RDRJ_RDRJ7_MASK                 128U
#define RDRJ_RDRJ_6_MASK                192U
#define RDRJ_RDRJ_6_BITNUM              6U


/*** PERJ - Port J Pull Device Enable Register; 0x0000026C ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PERJ6       :1;                                       /* Pull Device Enable Port J Bit 6 */
    byte PERJ7       :1;                                       /* Pull Device Enable Port J Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPERJ_6 :2;
  } MergedBits;
} PERJSTR;
extern volatile PERJSTR _PERJ @(REG_BASE + 0x0000026CUL);
#define PERJ                            _PERJ.Byte
#define PERJ_PERJ6                      _PERJ.Bits.PERJ6
#define PERJ_PERJ7                      _PERJ.Bits.PERJ7
#define PERJ_PERJ_6                     _PERJ.MergedBits.grpPERJ_6

#define PERJ_PERJ6_MASK                 64U
#define PERJ_PERJ7_MASK                 128U
#define PERJ_PERJ_6_MASK                192U
#define PERJ_PERJ_6_BITNUM              6U


/*** PPSJ - Port J Polarity Select Register; 0x0000026D ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PPSJ6       :1;                                       /* Pull Select Port J Bit 6 */
    byte PPSJ7       :1;                                       /* Pull Select Port J Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPPSJ_6 :2;
  } MergedBits;
} PPSJSTR;
extern volatile PPSJSTR _PPSJ @(REG_BASE + 0x0000026DUL);
#define PPSJ                            _PPSJ.Byte
#define PPSJ_PPSJ6                      _PPSJ.Bits.PPSJ6
#define PPSJ_PPSJ7                      _PPSJ.Bits.PPSJ7
#define PPSJ_PPSJ_6                     _PPSJ.MergedBits.grpPPSJ_6

#define PPSJ_PPSJ6_MASK                 64U
#define PPSJ_PPSJ7_MASK                 128U
#define PPSJ_PPSJ_6_MASK                192U
#define PPSJ_PPSJ_6_BITNUM              6U


/*** PIEJ - Port J Interrupt Enable Register; 0x0000026E ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PIEJ6       :1;                                       /* Interrupt Enable Port J Bit 6 */
    byte PIEJ7       :1;                                       /* Interrupt Enable Port J Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPIEJ_6 :2;
  } MergedBits;
} PIEJSTR;
extern volatile PIEJSTR _PIEJ @(REG_BASE + 0x0000026EUL);
#define PIEJ                            _PIEJ.Byte
#define PIEJ_PIEJ6                      _PIEJ.Bits.PIEJ6
#define PIEJ_PIEJ7                      _PIEJ.Bits.PIEJ7
#define PIEJ_PIEJ_6                     _PIEJ.MergedBits.grpPIEJ_6

#define PIEJ_PIEJ6_MASK                 64U
#define PIEJ_PIEJ7_MASK                 128U
#define PIEJ_PIEJ_6_MASK                192U
#define PIEJ_PIEJ_6_BITNUM              6U


/*** PIFJ - Port J Interrupt Flag Register; 0x0000026F ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PIFJ6       :1;                                       /* Interrupt Flags Port J Bit 6 */
    byte PIFJ7       :1;                                       /* Interrupt Flags Port J Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPIFJ_6 :2;
  } MergedBits;
} PIFJSTR;
extern volatile PIFJSTR _PIFJ @(REG_BASE + 0x0000026FUL);
#define PIFJ                            _PIFJ.Byte
#define PIFJ_PIFJ6                      _PIFJ.Bits.PIFJ6
#define PIFJ_PIFJ7                      _PIFJ.Bits.PIFJ7
#define PIFJ_PIFJ_6                     _PIFJ.MergedBits.grpPIFJ_6

#define PIFJ_PIFJ6_MASK                 64U
#define PIFJ_PIFJ7_MASK                 128U
#define PIFJ_PIFJ_6_MASK                192U
#define PIFJ_PIFJ_6_BITNUM              6U


/*** PTAD - Port AD I/O Register; 0x00000270 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAD0       :1;                                       /* Port AD Bit 0 */
    byte PTAD1       :1;                                       /* Port AD Bit 1 */
    byte PTAD2       :1;                                       /* Port AD Bit 2 */
    byte PTAD3       :1;                                       /* Port AD Bit 3 */
    byte PTAD4       :1;                                       /* Port AD Bit 4 */
    byte PTAD5       :1;                                       /* Port AD Bit 5 */
    byte PTAD6       :1;                                       /* Port AD Bit 6 */
    byte PTAD7       :1;                                       /* Port AD Bit 7 */
  } Bits;
} PTADSTR;
extern volatile PTADSTR _PTAD @(REG_BASE + 0x00000270UL);
#define PTAD                            _PTAD.Byte
#define PTAD_PTAD0                      _PTAD.Bits.PTAD0
#define PTAD_PTAD1                      _PTAD.Bits.PTAD1
#define PTAD_PTAD2                      _PTAD.Bits.PTAD2
#define PTAD_PTAD3                      _PTAD.Bits.PTAD3
#define PTAD_PTAD4                      _PTAD.Bits.PTAD4
#define PTAD_PTAD5                      _PTAD.Bits.PTAD5
#define PTAD_PTAD6                      _PTAD.Bits.PTAD6
#define PTAD_PTAD7                      _PTAD.Bits.PTAD7

#define PTAD_PTAD0_MASK                 1U
#define PTAD_PTAD1_MASK                 2U
#define PTAD_PTAD2_MASK                 4U
#define PTAD_PTAD3_MASK                 8U
#define PTAD_PTAD4_MASK                 16U
#define PTAD_PTAD5_MASK                 32U
#define PTAD_PTAD6_MASK                 64U
#define PTAD_PTAD7_MASK                 128U


/*** PTIAD - Port AD Input Register; 0x00000271 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIAD0      :1;                                       /* Port AD Bit 0 */
    byte PTIAD1      :1;                                       /* Port AD Bit 1 */
    byte PTIAD2      :1;                                       /* Port AD Bit 2 */
    byte PTIAD3      :1;                                       /* Port AD Bit 3 */
    byte PTIAD4      :1;                                       /* Port AD Bit 4 */
    byte PTIAD5      :1;                                       /* Port AD Bit 5 */
    byte PTIAD6      :1;                                       /* Port AD Bit 6 */
    byte PTIAD7      :1;                                       /* Port AD Bit 7 */
  } Bits;
} PTIADSTR;
extern volatile PTIADSTR _PTIAD @(REG_BASE + 0x00000271UL);
#define PTIAD                           _PTIAD.Byte
#define PTIAD_PTIAD0                    _PTIAD.Bits.PTIAD0
#define PTIAD_PTIAD1                    _PTIAD.Bits.PTIAD1
#define PTIAD_PTIAD2                    _PTIAD.Bits.PTIAD2
#define PTIAD_PTIAD3                    _PTIAD.Bits.PTIAD3
#define PTIAD_PTIAD4                    _PTIAD.Bits.PTIAD4
#define PTIAD_PTIAD5                    _PTIAD.Bits.PTIAD5
#define PTIAD_PTIAD6                    _PTIAD.Bits.PTIAD6
#define PTIAD_PTIAD7                    _PTIAD.Bits.PTIAD7

#define PTIAD_PTIAD0_MASK               1U
#define PTIAD_PTIAD1_MASK               2U
#define PTIAD_PTIAD2_MASK               4U
#define PTIAD_PTIAD3_MASK               8U
#define PTIAD_PTIAD4_MASK               16U
#define PTIAD_PTIAD5_MASK               32U
#define PTIAD_PTIAD6_MASK               64U
#define PTIAD_PTIAD7_MASK               128U


/*** DDRAD - Port AD Data Direction Register; 0x00000272 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRAD0      :1;                                       /* Port AD Data Direction Bit 0 */
    byte DDRAD1      :1;                                       /* Port AD Data Direction Bit 1 */
    byte DDRAD2      :1;                                       /* Port AD Data Direction Bit 2 */
    byte DDRAD3      :1;                                       /* Port AD Data Direction Bit 3 */
    byte DDRAD4      :1;                                       /* Port AD Data Direction Bit 4 */
    byte DDRAD5      :1;                                       /* Port AD Data Direction Bit 5 */
    byte DDRAD6      :1;                                       /* Port AD Data Direction Bit 6 */
    byte DDRAD7      :1;                                       /* Port AD Data Direction Bit 7 */
  } Bits;
} DDRADSTR;
extern volatile DDRADSTR _DDRAD @(REG_BASE + 0x00000272UL);
#define DDRAD                           _DDRAD.Byte
#define DDRAD_DDRAD0                    _DDRAD.Bits.DDRAD0
#define DDRAD_DDRAD1                    _DDRAD.Bits.DDRAD1
#define DDRAD_DDRAD2                    _DDRAD.Bits.DDRAD2
#define DDRAD_DDRAD3                    _DDRAD.Bits.DDRAD3
#define DDRAD_DDRAD4                    _DDRAD.Bits.DDRAD4
#define DDRAD_DDRAD5                    _DDRAD.Bits.DDRAD5
#define DDRAD_DDRAD6                    _DDRAD.Bits.DDRAD6
#define DDRAD_DDRAD7                    _DDRAD.Bits.DDRAD7

#define DDRAD_DDRAD0_MASK               1U
#define DDRAD_DDRAD1_MASK               2U
#define DDRAD_DDRAD2_MASK               4U
#define DDRAD_DDRAD3_MASK               8U
#define DDRAD_DDRAD4_MASK               16U
#define DDRAD_DDRAD5_MASK               32U
#define DDRAD_DDRAD6_MASK               64U
#define DDRAD_DDRAD7_MASK               128U


/*** RDRAD - Port AD Reduced Drive Register; 0x00000273 ***/
typedef union {
  byte Byte;
  struct {
    byte RDRAD0      :1;                                       /* Port AD Reduced Drive Bit 0 */
    byte RDRAD1      :1;                                       /* Port AD Reduced Drive Bit 1 */
    byte RDRAD2      :1;                                       /* Port AD Reduced Drive Bit 2 */
    byte RDRAD3      :1;                                       /* Port AD Reduced Drive Bit 3 */
    byte RDRAD4      :1;                                       /* Port AD Reduced Drive Bit 4 */
    byte RDRAD5      :1;                                       /* Port AD Reduced Drive Bit 5 */
    byte RDRAD6      :1;                                       /* Port AD Reduced Drive Bit 6 */
    byte RDRAD7      :1;                                       /* Port AD Reduced Drive Bit 7 */
  } Bits;
} RDRADSTR;
extern volatile RDRADSTR _RDRAD @(REG_BASE + 0x00000273UL);
#define RDRAD                           _RDRAD.Byte
#define RDRAD_RDRAD0                    _RDRAD.Bits.RDRAD0
#define RDRAD_RDRAD1                    _RDRAD.Bits.RDRAD1
#define RDRAD_RDRAD2                    _RDRAD.Bits.RDRAD2
#define RDRAD_RDRAD3                    _RDRAD.Bits.RDRAD3
#define RDRAD_RDRAD4                    _RDRAD.Bits.RDRAD4
#define RDRAD_RDRAD5                    _RDRAD.Bits.RDRAD5
#define RDRAD_RDRAD6                    _RDRAD.Bits.RDRAD6
#define RDRAD_RDRAD7                    _RDRAD.Bits.RDRAD7

#define RDRAD_RDRAD0_MASK               1U
#define RDRAD_RDRAD1_MASK               2U
#define RDRAD_RDRAD2_MASK               4U
#define RDRAD_RDRAD3_MASK               8U
#define RDRAD_RDRAD4_MASK               16U
#define RDRAD_RDRAD5_MASK               32U
#define RDRAD_RDRAD6_MASK               64U
#define RDRAD_RDRAD7_MASK               128U


/*** PERAD - Port AD Pull Device Enable Register; 0x00000274 ***/
typedef union {
  byte Byte;
  struct {
    byte PERAD0      :1;                                       /* Port AD Pull Device Enable Bit 0 */
    byte PERAD1      :1;                                       /* Port AD Pull Device Enable Bit 1 */
    byte PERAD2      :1;                                       /* Port AD Pull Device Enable Bit 2 */
    byte PERAD3      :1;                                       /* Port AD Pull Device Enable Bit 3 */
    byte PERAD4      :1;                                       /* Port AD Pull Device Enable Bit 4 */
    byte PERAD5      :1;                                       /* Port AD Pull Device Enable Bit 5 */
    byte PERAD6      :1;                                       /* Port AD Pull Device Enable Bit 6 */
    byte PERAD7      :1;                                       /* Port AD Pull Device Enable Bit 7 */
  } Bits;
} PERADSTR;
extern volatile PERADSTR _PERAD @(REG_BASE + 0x00000274UL);
#define PERAD                           _PERAD.Byte
#define PERAD_PERAD0                    _PERAD.Bits.PERAD0
#define PERAD_PERAD1                    _PERAD.Bits.PERAD1
#define PERAD_PERAD2                    _PERAD.Bits.PERAD2
#define PERAD_PERAD3                    _PERAD.Bits.PERAD3
#define PERAD_PERAD4                    _PERAD.Bits.PERAD4
#define PERAD_PERAD5                    _PERAD.Bits.PERAD5
#define PERAD_PERAD6                    _PERAD.Bits.PERAD6
#define PERAD_PERAD7                    _PERAD.Bits.PERAD7

#define PERAD_PERAD0_MASK               1U
#define PERAD_PERAD1_MASK               2U
#define PERAD_PERAD2_MASK               4U
#define PERAD_PERAD3_MASK               8U
#define PERAD_PERAD4_MASK               16U
#define PERAD_PERAD5_MASK               32U
#define PERAD_PERAD6_MASK               64U
#define PERAD_PERAD7_MASK               128U


/*** PPSAD - Port AD Polarity Select Register; 0x00000275 ***/
typedef union {
  byte Byte;
  struct {
    byte PPSAD0      :1;                                       /* Port AD Polarity Select Bit 0 */
    byte PPSAD1      :1;                                       /* Port AD Polarity Select Bit 1 */
    byte PPSAD2      :1;                                       /* Port AD Polarity Select Bit 2 */
    byte PPSAD3      :1;                                       /* Port AD Polarity Select Bit 3 */
    byte PPSAD4      :1;                                       /* Port AD Polarity Select Bit 4 */
    byte PPSAD5      :1;                                       /* Port AD Polarity Select Bit 5 */
    byte PPSAD6      :1;                                       /* Port AD Polarity Select Bit 6 */
    byte PPSAD7      :1;                                       /* Port AD Polarity Select Bit 7 */
  } Bits;
} PPSADSTR;
extern volatile PPSADSTR _PPSAD @(REG_BASE + 0x00000275UL);
#define PPSAD                           _PPSAD.Byte
#define PPSAD_PPSAD0                    _PPSAD.Bits.PPSAD0
#define PPSAD_PPSAD1                    _PPSAD.Bits.PPSAD1
#define PPSAD_PPSAD2                    _PPSAD.Bits.PPSAD2
#define PPSAD_PPSAD3                    _PPSAD.Bits.PPSAD3
#define PPSAD_PPSAD4                    _PPSAD.Bits.PPSAD4
#define PPSAD_PPSAD5                    _PPSAD.Bits.PPSAD5
#define PPSAD_PPSAD6                    _PPSAD.Bits.PPSAD6
#define PPSAD_PPSAD7                    _PPSAD.Bits.PPSAD7

#define PPSAD_PPSAD0_MASK               1U
#define PPSAD_PPSAD1_MASK               2U
#define PPSAD_PPSAD2_MASK               4U
#define PPSAD_PPSAD3_MASK               8U
#define PPSAD_PPSAD4_MASK               16U
#define PPSAD_PPSAD5_MASK               32U
#define PPSAD_PPSAD6_MASK               64U
#define PPSAD_PPSAD7_MASK               128U


/*** BAKEY0 - Backdoor Access Key 0; 0x0000FF00 ***/
typedef union {
  word Word;
  struct {
    word KEY0        :1;                                       /* Backdoor Access Key bits, bit 0 */
    word KEY1        :1;                                       /* Backdoor Access Key bits, bit 1 */
    word KEY2        :1;                                       /* Backdoor Access Key bits, bit 2 */
    word KEY3        :1;                                       /* Backdoor Access Key bits, bit 3 */
    word KEY4        :1;                                       /* Backdoor Access Key bits, bit 4 */
    word KEY5        :1;                                       /* Backdoor Access Key bits, bit 5 */
    word KEY6        :1;                                       /* Backdoor Access Key bits, bit 6 */
    word KEY7        :1;                                       /* Backdoor Access Key bits, bit 7 */
    word KEY8        :1;                                       /* Backdoor Access Key bits, bit 8 */
    word KEY9        :1;                                       /* Backdoor Access Key bits, bit 9 */
    word KEY10       :1;                                       /* Backdoor Access Key bits, bit 10 */
    word KEY11       :1;                                       /* Backdoor Access Key bits, bit 11 */
    word KEY12       :1;                                       /* Backdoor Access Key bits, bit 12 */
    word KEY13       :1;                                       /* Backdoor Access Key bits, bit 13 */
    word KEY14       :1;                                       /* Backdoor Access Key bits, bit 14 */
    word KEY15       :1;                                       /* Backdoor Access Key bits, bit 15 */
  } Bits;
} BAKEY0STR;
/* Tip for register initialization in the user code:  const word BAKEY0_INIT @0x0000FF00 = <BAKEY0_INITVAL>; */
#define _BAKEY0 (*(const BAKEY0STR *)0x0000FF00)
#define BAKEY0                          _BAKEY0.Word
#define BAKEY0_KEY0                     _BAKEY0.Bits.KEY0
#define BAKEY0_KEY1                     _BAKEY0.Bits.KEY1
#define BAKEY0_KEY2                     _BAKEY0.Bits.KEY2
#define BAKEY0_KEY3                     _BAKEY0.Bits.KEY3
#define BAKEY0_KEY4                     _BAKEY0.Bits.KEY4
#define BAKEY0_KEY5                     _BAKEY0.Bits.KEY5
#define BAKEY0_KEY6                     _BAKEY0.Bits.KEY6
#define BAKEY0_KEY7                     _BAKEY0.Bits.KEY7
#define BAKEY0_KEY8                     _BAKEY0.Bits.KEY8
#define BAKEY0_KEY9                     _BAKEY0.Bits.KEY9
#define BAKEY0_KEY10                    _BAKEY0.Bits.KEY10
#define BAKEY0_KEY11                    _BAKEY0.Bits.KEY11
#define BAKEY0_KEY12                    _BAKEY0.Bits.KEY12
#define BAKEY0_KEY13                    _BAKEY0.Bits.KEY13
#define BAKEY0_KEY14                    _BAKEY0.Bits.KEY14
#define BAKEY0_KEY15                    _BAKEY0.Bits.KEY15
/* BAKEY_ARR: Access 4 BAKEYx registers in an array */
#define BAKEY_ARR                       ((volatile word *) &BAKEY0)

#define BAKEY0_KEY0_MASK                1U
#define BAKEY0_KEY1_MASK                2U
#define BAKEY0_KEY2_MASK                4U
#define BAKEY0_KEY3_MASK                8U
#define BAKEY0_KEY4_MASK                16U
#define BAKEY0_KEY5_MASK                32U
#define BAKEY0_KEY6_MASK                64U
#define BAKEY0_KEY7_MASK                128U
#define BAKEY0_KEY8_MASK                256U
#define BAKEY0_KEY9_MASK                512U
#define BAKEY0_KEY10_MASK               1024U
#define BAKEY0_KEY11_MASK               2048U
#define BAKEY0_KEY12_MASK               4096U
#define BAKEY0_KEY13_MASK               8192U
#define BAKEY0_KEY14_MASK               16384U
#define BAKEY0_KEY15_MASK               32768U


/*** BAKEY1 - Backdoor Access Key 1; 0x0000FF02 ***/
typedef union {
  word Word;
  struct {
    word KEY0        :1;                                       /* Backdoor Access Key bits, bit 0 */
    word KEY1        :1;                                       /* Backdoor Access Key bits, bit 1 */
    word KEY2        :1;                                       /* Backdoor Access Key bits, bit 2 */
    word KEY3        :1;                                       /* Backdoor Access Key bits, bit 3 */
    word KEY4        :1;                                       /* Backdoor Access Key bits, bit 4 */
    word KEY5        :1;                                       /* Backdoor Access Key bits, bit 5 */
    word KEY6        :1;                                       /* Backdoor Access Key bits, bit 6 */
    word KEY7        :1;                                       /* Backdoor Access Key bits, bit 7 */
    word KEY8        :1;                                       /* Backdoor Access Key bits, bit 8 */
    word KEY9        :1;                                       /* Backdoor Access Key bits, bit 9 */
    word KEY10       :1;                                       /* Backdoor Access Key bits, bit 10 */
    word KEY11       :1;                                       /* Backdoor Access Key bits, bit 11 */
    word KEY12       :1;                                       /* Backdoor Access Key bits, bit 12 */
    word KEY13       :1;                                       /* Backdoor Access Key bits, bit 13 */
    word KEY14       :1;                                       /* Backdoor Access Key bits, bit 14 */
    word KEY15       :1;                                       /* Backdoor Access Key bits, bit 15 */
  } Bits;
} BAKEY1STR;
/* Tip for register initialization in the user code:  const word BAKEY1_INIT @0x0000FF02 = <BAKEY1_INITVAL>; */
#define _BAKEY1 (*(const BAKEY1STR *)0x0000FF02)
#define BAKEY1                          _BAKEY1.Word
#define BAKEY1_KEY0                     _BAKEY1.Bits.KEY0
#define BAKEY1_KEY1                     _BAKEY1.Bits.KEY1
#define BAKEY1_KEY2                     _BAKEY1.Bits.KEY2
#define BAKEY1_KEY3                     _BAKEY1.Bits.KEY3
#define BAKEY1_KEY4                     _BAKEY1.Bits.KEY4
#define BAKEY1_KEY5                     _BAKEY1.Bits.KEY5
#define BAKEY1_KEY6                     _BAKEY1.Bits.KEY6
#define BAKEY1_KEY7                     _BAKEY1.Bits.KEY7
#define BAKEY1_KEY8                     _BAKEY1.Bits.KEY8
#define BAKEY1_KEY9                     _BAKEY1.Bits.KEY9
#define BAKEY1_KEY10                    _BAKEY1.Bits.KEY10
#define BAKEY1_KEY11                    _BAKEY1.Bits.KEY11
#define BAKEY1_KEY12                    _BAKEY1.Bits.KEY12
#define BAKEY1_KEY13                    _BAKEY1.Bits.KEY13
#define BAKEY1_KEY14                    _BAKEY1.Bits.KEY14
#define BAKEY1_KEY15                    _BAKEY1.Bits.KEY15

#define BAKEY1_KEY0_MASK                1U
#define BAKEY1_KEY1_MASK                2U
#define BAKEY1_KEY2_MASK                4U
#define BAKEY1_KEY3_MASK                8U
#define BAKEY1_KEY4_MASK                16U
#define BAKEY1_KEY5_MASK                32U
#define BAKEY1_KEY6_MASK                64U
#define BAKEY1_KEY7_MASK                128U
#define BAKEY1_KEY8_MASK                256U
#define BAKEY1_KEY9_MASK                512U
#define BAKEY1_KEY10_MASK               1024U
#define BAKEY1_KEY11_MASK               2048U
#define BAKEY1_KEY12_MASK               4096U
#define BAKEY1_KEY13_MASK               8192U
#define BAKEY1_KEY14_MASK               16384U
#define BAKEY1_KEY15_MASK               32768U


/*** BAKEY2 - Backdoor Access Key 2; 0x0000FF04 ***/
typedef union {
  word Word;
  struct {
    word KEY0        :1;                                       /* Backdoor Access Key bits, bit 0 */
    word KEY1        :1;                                       /* Backdoor Access Key bits, bit 1 */
    word KEY2        :1;                                       /* Backdoor Access Key bits, bit 2 */
    word KEY3        :1;                                       /* Backdoor Access Key bits, bit 3 */
    word KEY4        :1;                                       /* Backdoor Access Key bits, bit 4 */
    word KEY5        :1;                                       /* Backdoor Access Key bits, bit 5 */
    word KEY6        :1;                                       /* Backdoor Access Key bits, bit 6 */
    word KEY7        :1;                                       /* Backdoor Access Key bits, bit 7 */
    word KEY8        :1;                                       /* Backdoor Access Key bits, bit 8 */
    word KEY9        :1;                                       /* Backdoor Access Key bits, bit 9 */
    word KEY10       :1;                                       /* Backdoor Access Key bits, bit 10 */
    word KEY11       :1;                                       /* Backdoor Access Key bits, bit 11 */
    word KEY12       :1;                                       /* Backdoor Access Key bits, bit 12 */
    word KEY13       :1;                                       /* Backdoor Access Key bits, bit 13 */
    word KEY14       :1;                                       /* Backdoor Access Key bits, bit 14 */
    word KEY15       :1;                                       /* Backdoor Access Key bits, bit 15 */
  } Bits;
} BAKEY2STR;
/* Tip for register initialization in the user code:  const word BAKEY2_INIT @0x0000FF04 = <BAKEY2_INITVAL>; */
#define _BAKEY2 (*(const BAKEY2STR *)0x0000FF04)
#define BAKEY2                          _BAKEY2.Word
#define BAKEY2_KEY0                     _BAKEY2.Bits.KEY0
#define BAKEY2_KEY1                     _BAKEY2.Bits.KEY1
#define BAKEY2_KEY2                     _BAKEY2.Bits.KEY2
#define BAKEY2_KEY3                     _BAKEY2.Bits.KEY3
#define BAKEY2_KEY4                     _BAKEY2.Bits.KEY4
#define BAKEY2_KEY5                     _BAKEY2.Bits.KEY5
#define BAKEY2_KEY6                     _BAKEY2.Bits.KEY6
#define BAKEY2_KEY7                     _BAKEY2.Bits.KEY7
#define BAKEY2_KEY8                     _BAKEY2.Bits.KEY8
#define BAKEY2_KEY9                     _BAKEY2.Bits.KEY9
#define BAKEY2_KEY10                    _BAKEY2.Bits.KEY10
#define BAKEY2_KEY11                    _BAKEY2.Bits.KEY11
#define BAKEY2_KEY12                    _BAKEY2.Bits.KEY12
#define BAKEY2_KEY13                    _BAKEY2.Bits.KEY13
#define BAKEY2_KEY14                    _BAKEY2.Bits.KEY14
#define BAKEY2_KEY15                    _BAKEY2.Bits.KEY15

#define BAKEY2_KEY0_MASK                1U
#define BAKEY2_KEY1_MASK                2U
#define BAKEY2_KEY2_MASK                4U
#define BAKEY2_KEY3_MASK                8U
#define BAKEY2_KEY4_MASK                16U
#define BAKEY2_KEY5_MASK                32U
#define BAKEY2_KEY6_MASK                64U
#define BAKEY2_KEY7_MASK                128U
#define BAKEY2_KEY8_MASK                256U
#define BAKEY2_KEY9_MASK                512U
#define BAKEY2_KEY10_MASK               1024U
#define BAKEY2_KEY11_MASK               2048U
#define BAKEY2_KEY12_MASK               4096U
#define BAKEY2_KEY13_MASK               8192U
#define BAKEY2_KEY14_MASK               16384U
#define BAKEY2_KEY15_MASK               32768U


/*** BAKEY3 - Backdoor Access Key 3; 0x0000FF06 ***/
typedef union {
  word Word;
  struct {
    word KEY0        :1;                                       /* Backdoor Access Key bits, bit 0 */
    word KEY1        :1;                                       /* Backdoor Access Key bits, bit 1 */
    word KEY2        :1;                                       /* Backdoor Access Key bits, bit 2 */
    word KEY3        :1;                                       /* Backdoor Access Key bits, bit 3 */
    word KEY4        :1;                                       /* Backdoor Access Key bits, bit 4 */
    word KEY5        :1;                                       /* Backdoor Access Key bits, bit 5 */
    word KEY6        :1;                                       /* Backdoor Access Key bits, bit 6 */
    word KEY7        :1;                                       /* Backdoor Access Key bits, bit 7 */
    word KEY8        :1;                                       /* Backdoor Access Key bits, bit 8 */
    word KEY9        :1;                                       /* Backdoor Access Key bits, bit 9 */
    word KEY10       :1;                                       /* Backdoor Access Key bits, bit 10 */
    word KEY11       :1;                                       /* Backdoor Access Key bits, bit 11 */
    word KEY12       :1;                                       /* Backdoor Access Key bits, bit 12 */
    word KEY13       :1;                                       /* Backdoor Access Key bits, bit 13 */
    word KEY14       :1;                                       /* Backdoor Access Key bits, bit 14 */
    word KEY15       :1;                                       /* Backdoor Access Key bits, bit 15 */
  } Bits;
} BAKEY3STR;
/* Tip for register initialization in the user code:  const word BAKEY3_INIT @0x0000FF06 = <BAKEY3_INITVAL>; */
#define _BAKEY3 (*(const BAKEY3STR *)0x0000FF06)
#define BAKEY3                          _BAKEY3.Word
#define BAKEY3_KEY0                     _BAKEY3.Bits.KEY0
#define BAKEY3_KEY1                     _BAKEY3.Bits.KEY1
#define BAKEY3_KEY2                     _BAKEY3.Bits.KEY2
#define BAKEY3_KEY3                     _BAKEY3.Bits.KEY3
#define BAKEY3_KEY4                     _BAKEY3.Bits.KEY4
#define BAKEY3_KEY5                     _BAKEY3.Bits.KEY5
#define BAKEY3_KEY6                     _BAKEY3.Bits.KEY6
#define BAKEY3_KEY7                     _BAKEY3.Bits.KEY7
#define BAKEY3_KEY8                     _BAKEY3.Bits.KEY8
#define BAKEY3_KEY9                     _BAKEY3.Bits.KEY9
#define BAKEY3_KEY10                    _BAKEY3.Bits.KEY10
#define BAKEY3_KEY11                    _BAKEY3.Bits.KEY11
#define BAKEY3_KEY12                    _BAKEY3.Bits.KEY12
#define BAKEY3_KEY13                    _BAKEY3.Bits.KEY13
#define BAKEY3_KEY14                    _BAKEY3.Bits.KEY14
#define BAKEY3_KEY15                    _BAKEY3.Bits.KEY15

#define BAKEY3_KEY0_MASK                1U
#define BAKEY3_KEY1_MASK                2U
#define BAKEY3_KEY2_MASK                4U
#define BAKEY3_KEY3_MASK                8U
#define BAKEY3_KEY4_MASK                16U
#define BAKEY3_KEY5_MASK                32U
#define BAKEY3_KEY6_MASK                64U
#define BAKEY3_KEY7_MASK                128U
#define BAKEY3_KEY8_MASK                256U
#define BAKEY3_KEY9_MASK                512U
#define BAKEY3_KEY10_MASK               1024U
#define BAKEY3_KEY11_MASK               2048U
#define BAKEY3_KEY12_MASK               4096U
#define BAKEY3_KEY13_MASK               8192U
#define BAKEY3_KEY14_MASK               16384U
#define BAKEY3_KEY15_MASK               32768U


/*** NVFPROT0 - Non volatile Block 0 Flash Protection Register; 0x0000FF0D ***/
typedef union {
  byte Byte;
  struct {
    byte FPLS0       :1;                                       /* Flash Protection Lower Address size 0 */
    byte FPLS1       :1;                                       /* Flash Protection Lower Address size 1 */
    byte FPLDIS      :1;                                       /* Flash Protection Lower address range disable */
    byte FPHS0       :1;                                       /* Flash Protection Higher address size 0 */
    byte FPHS1       :1;                                       /* Flash Protection Higher address size 1 */
    byte FPHDIS      :1;                                       /* Flash Protection Higher address range disable */
    byte NV6         :1;                                       /* Non Volatile Flag Bit */
    byte FPOPEN      :1;                                       /* Opens the flash block or subsections of it for program or erase */
  } Bits;
  struct {
    byte grpFPLS :2;
    byte         :1;
    byte grpFPHS :2;
    byte         :1;
    byte grpNV_6 :1;
    byte         :1;
  } MergedBits;
} NVFPROT0STR;
/* Tip for register initialization in the user code:  const byte NVFPROT0_INIT @0x0000FF0D = <NVFPROT0_INITVAL>; */
#define _NVFPROT0 (*(const NVFPROT0STR *)0x0000FF0D)
#define NVFPROT0                        _NVFPROT0.Byte
#define NVFPROT0_FPLS0                  _NVFPROT0.Bits.FPLS0
#define NVFPROT0_FPLS1                  _NVFPROT0.Bits.FPLS1
#define NVFPROT0_FPLDIS                 _NVFPROT0.Bits.FPLDIS
#define NVFPROT0_FPHS0                  _NVFPROT0.Bits.FPHS0
#define NVFPROT0_FPHS1                  _NVFPROT0.Bits.FPHS1
#define NVFPROT0_FPHDIS                 _NVFPROT0.Bits.FPHDIS
#define NVFPROT0_NV6                    _NVFPROT0.Bits.NV6
#define NVFPROT0_FPOPEN                 _NVFPROT0.Bits.FPOPEN
#define NVFPROT0_FPLS                   _NVFPROT0.MergedBits.grpFPLS
#define NVFPROT0_FPHS                   _NVFPROT0.MergedBits.grpFPHS

#define NVFPROT0_FPLS0_MASK             1U
#define NVFPROT0_FPLS1_MASK             2U
#define NVFPROT0_FPLDIS_MASK            4U
#define NVFPROT0_FPHS0_MASK             8U
#define NVFPROT0_FPHS1_MASK             16U
#define NVFPROT0_FPHDIS_MASK            32U
#define NVFPROT0_NV6_MASK               64U
#define NVFPROT0_FPOPEN_MASK            128U
#define NVFPROT0_FPLS_MASK              3U
#define NVFPROT0_FPLS_BITNUM            0U
#define NVFPROT0_FPHS_MASK              24U
#define NVFPROT0_FPHS_BITNUM            3U


/*** NVFSEC - Non volatile Flash Security Register; 0x0000FF0F ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Memory security bit 0 */
    byte SEC1        :1;                                       /* Memory security bit 1 */
    byte NV2         :1;                                       /* Non Volatile flag bit 2 */
    byte NV3         :1;                                       /* Non Volatile flag bit 3 */
    byte NV4         :1;                                       /* Non Volatile flag bit 4 */
    byte NV5         :1;                                       /* Non Volatile flag bit 5 */
    byte NV6         :1;                                       /* Non Volatile flag bit 6 */
    byte KEYEN       :1;                                       /* Backdoor Key Security Enable */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte grpNV_2 :5;
    byte         :1;
  } MergedBits;
} NVFSECSTR;
/* Tip for register initialization in the user code:  const byte NVFSEC_INIT @0x0000FF0F = <NVFSEC_INITVAL>; */
#define _NVFSEC (*(const NVFSECSTR *)0x0000FF0F)
#define NVFSEC                          _NVFSEC.Byte
#define NVFSEC_SEC0                     _NVFSEC.Bits.SEC0
#define NVFSEC_SEC1                     _NVFSEC.Bits.SEC1
#define NVFSEC_NV2                      _NVFSEC.Bits.NV2
#define NVFSEC_NV3                      _NVFSEC.Bits.NV3
#define NVFSEC_NV4                      _NVFSEC.Bits.NV4
#define NVFSEC_NV5                      _NVFSEC.Bits.NV5
#define NVFSEC_NV6                      _NVFSEC.Bits.NV6
#define NVFSEC_KEYEN                    _NVFSEC.Bits.KEYEN
#define NVFSEC_SEC                      _NVFSEC.MergedBits.grpSEC
#define NVFSEC_NV_2                     _NVFSEC.MergedBits.grpNV_2
#define NVFSEC_NV                       NVFSEC_NV_2

#define NVFSEC_SEC0_MASK                1U
#define NVFSEC_SEC1_MASK                2U
#define NVFSEC_NV2_MASK                 4U
#define NVFSEC_NV3_MASK                 8U
#define NVFSEC_NV4_MASK                 16U
#define NVFSEC_NV5_MASK                 32U
#define NVFSEC_NV6_MASK                 64U
#define NVFSEC_KEYEN_MASK               128U
#define NVFSEC_SEC_MASK                 3U
#define NVFSEC_SEC_BITNUM               0U
#define NVFSEC_NV_2_MASK                124U
#define NVFSEC_NV_2_BITNUM              2U


  /* Watchdog reset macro */
#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() (void)(ARMCOP = 0x55U, ARMCOP = 0xAAU)
#endif
#endif /* __RESET_WATCHDOG */


/***********************************************/
/**   D E P R E C I A T E D   S Y M B O L S   **/
/***********************************************/
/* --------------------------------------------------------------------------- */
/* The following symbols were removed, because they were invalid or irrelevant */
/* --------------------------------------------------------------------------- */

#ifndef __V30COMPATIBLE__
#pragma OPTION DEL V30toV31Compatible
#endif
/*lint -restore  +esym(961,18.4) +esym(961,19.7) Enable MISRA rule (1.1,18.4,6.4,19.7) checking. */

#endif
:wq

