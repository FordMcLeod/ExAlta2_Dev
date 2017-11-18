//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS

// $[Library includes]
#include "em_system.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_assert.h"
#include "em_burtc.h"
#include "em_rmu.h"
#include "em_gpio.h"
#include "em_i2c.h"
#include "em_leuart.h"
#include "em_usart.h"
// [Library includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void enter_DefaultMode_from_RESET(void) {
	// $[Config Calls]
	HFXO_enter_DefaultMode_from_RESET();
	LFXO_enter_DefaultMode_from_RESET();
	CMU_enter_DefaultMode_from_RESET();
	BURTC_enter_DefaultMode_from_RESET();
	USART0_enter_DefaultMode_from_RESET();
	USART1_enter_DefaultMode_from_RESET();
	USART2_enter_DefaultMode_from_RESET();
	UART0_enter_DefaultMode_from_RESET();
	UART1_enter_DefaultMode_from_RESET();
	LEUART1_enter_DefaultMode_from_RESET();
	I2C0_enter_DefaultMode_from_RESET();
	PORTIO_enter_DefaultMode_from_RESET();
	// [Config Calls]$

}

//================================================================================
// HFXO_enter_DefaultMode_from_RESET
//================================================================================
extern void HFXO_enter_DefaultMode_from_RESET(void) {

	// $[HFXO]
	CMU->CTRL = (CMU->CTRL & ~_CMU_CTRL_HFXOMODE_MASK)
			| CMU_CTRL_HFXOMODE_BUFEXTCLK;

	CMU->CTRL = (CMU->CTRL & ~_CMU_CTRL_HFXOBOOST_MASK)
			| CMU_CTRL_HFXOBOOST_50PCENT;

	SystemHFXOClockSet(48000000);
	// [HFXO]$

}

//================================================================================
// LFXO_enter_DefaultMode_from_RESET
//================================================================================
extern void LFXO_enter_DefaultMode_from_RESET(void) {

	// $[Use oscillator source]
	CMU->CTRL = (CMU->CTRL & ~_CMU_CTRL_LFXOMODE_MASK)
			| CMU_CTRL_LFXOMODE_DIGEXTCLK;
	// [Use oscillator source]$

	// $[LFXO Boost Percent]
	CMU->CTRL = (CMU->CTRL & ~_CMU_CTRL_LFXOBOOST_MASK)
			| CMU_CTRL_LFXOBOOST_100PCENT;
	// [LFXO Boost Percent]$

	// $[REDLFXO Boost]
	// [REDLFXO Boost]$

}

//================================================================================
// CMU_enter_DefaultMode_from_RESET
//================================================================================
extern void CMU_enter_DefaultMode_from_RESET(void) {

	// $[LFXO enable]
	CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
	// [LFXO enable]$

	// $[HFXO enable]
	CMU_OscillatorEnable(cmuOsc_HFXO, true, true);
	// [HFXO enable]$

	// $[LFACLK Setup]
	// [LFACLK Setup]$

	// $[High Frequency Clock select]
	/* Using HFXO as high frequency clock, HFCLK */
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);

	/* Enable peripheral clock */
	CMU_ClockEnable(cmuClock_HFPER, true);

	// [High Frequency Clock select]$

	// $[LF clock tree setup]
	/* Enable LF clocks */
	CMU_ClockEnable(cmuClock_CORELE, true);
	CMU_ClockSelectSet(cmuClock_LFB, cmuSelect_LFXO);
	// [LF clock tree setup]$
	// $[Peripheral Clock enables]
	/* Enable clock for I2C0 */
	CMU_ClockEnable(cmuClock_I2C0, true);

	/* Enable clock for LEUART1 */
	CMU_ClockEnable(cmuClock_LEUART1, true);

	/* Enable clock for UART0 */
	CMU_ClockEnable(cmuClock_UART0, true);

	/* Enable clock for UART1 */
	CMU_ClockEnable(cmuClock_UART1, true);

	/* Enable clock for USART0 */
	CMU_ClockEnable(cmuClock_USART0, true);

	/* Enable clock for USART1 */
	CMU_ClockEnable(cmuClock_USART1, true);

	/* Enable clock for USART2 */
	CMU_ClockEnable(cmuClock_USART2, true);

	/* Enable clock for GPIO by default */
	CMU_ClockEnable(cmuClock_GPIO, true);

	// [Peripheral Clock enables]$

}

//================================================================================
// ADC0_enter_DefaultMode_from_RESET
//================================================================================
extern void ADC0_enter_DefaultMode_from_RESET(void) {

	// $[ADC_Init]
	// [ADC_Init]$

	// $[ADC_InitSingle]
	// [ADC_InitSingle]$

	// $[ADC_InitScan]
	// [ADC_InitScan]$

}

//================================================================================
// ACMP0_enter_DefaultMode_from_RESET
//================================================================================
extern void ACMP0_enter_DefaultMode_from_RESET(void) {

	// $[ACMP Initialization]
	// [ACMP Initialization]$

	// $[ACMP Channel config]
	// [ACMP Channel config]$

}

//================================================================================
// ACMP1_enter_DefaultMode_from_RESET
//================================================================================
extern void ACMP1_enter_DefaultMode_from_RESET(void) {

	// $[ACMP Initialization]
	// [ACMP Initialization]$

	// $[ACMP Channel config]
	// [ACMP Channel config]$

}

//================================================================================
// DAC0_enter_DefaultMode_from_RESET
//================================================================================
extern void DAC0_enter_DefaultMode_from_RESET(void) {

	// $[DAC Initialization]
	// [DAC Initialization]$

	// $[DAC Channel 0 config]
	// [DAC Channel 0 config]$

	// $[DAC Channel 1 config]
	// [DAC Channel 1 config]$

}

//================================================================================
// BURTC_enter_DefaultMode_from_RESET
//================================================================================
extern void BURTC_enter_DefaultMode_from_RESET(void) {

	// $[CMU_ClockEnable]
	/* Enable LE clock for CPU access to BURTC registers */
	CMU_ClockEnable(cmuClock_CORELE, true);
	// [CMU_ClockEnable]$

	// $[CMU_OscillatorEnable]
	CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
	// [CMU_OscillatorEnable]$

	// $[RMU_ResetControl]
	/* Release reset line to backup domain. This is needed before the CPU can access
	 * BURTC registers */
	RMU_ResetControl(rmuResetBU, false);
	// [RMU_ResetControl]$

	// $[BURTC_Init]
	BURTC_Init_TypeDef init = BURTC_INIT_DEFAULT;

	init.enable = false;
	init.mode = burtcModeEM4;
	init.debugRun = false;
	init.clkSel = burtcClkSelLFXO;
	init.clkDiv = burtcClkDiv_16;
	init.timeStamp = false;
	init.compare0Top = false;
	init.lowPowerMode = burtcLPDisable;
	init.lowPowerComp = 0;
	BURTC_Init(&init);
	// [BURTC_Init]$

	// $[BURTC_CompareSet]
	/* Set compare value */
	BURTC_CompareSet(0, 0);
	// [BURTC_CompareSet]$

}

//================================================================================
// RTC_enter_DefaultMode_from_RESET
//================================================================================
extern void RTC_enter_DefaultMode_from_RESET(void) {

	// $[RTC_Init]
	// [RTC_Init]$

}

//================================================================================
// OPAMP0_enter_DefaultMode_from_RESET
//================================================================================
extern void OPAMP0_enter_DefaultMode_from_RESET(void) {

	// $[DAC Output]
	// [DAC Output]$

	// $[OPAMP_Enable]
	// [OPAMP_Enable]$

}

//================================================================================
// OPAMP1_enter_DefaultMode_from_RESET
//================================================================================
extern void OPAMP1_enter_DefaultMode_from_RESET(void) {

	// $[DAC Output]
	// [DAC Output]$

	// $[OPAMP_Enable]
	// [OPAMP_Enable]$

}

//================================================================================
// OPAMP2_enter_DefaultMode_from_RESET
//================================================================================
extern void OPAMP2_enter_DefaultMode_from_RESET(void) {

	// $[DAC Output]
	// [DAC Output]$

	// $[OPAMP_Enable]
	// [OPAMP_Enable]$

}

//================================================================================
// USART0_enter_DefaultMode_from_RESET
//================================================================================
extern void USART0_enter_DefaultMode_from_RESET(void) {

	// $[USART_InitAsync]
	USART_InitAsync_TypeDef initasync = USART_INITASYNC_DEFAULT;

	initasync.baudrate = 921600;
	initasync.databits = usartDatabits8;
	initasync.parity = usartNoParity;
	initasync.stopbits = usartStopbits1;
	initasync.oversampling = usartOVS16;
#if defined( USART_INPUT_RXPRS ) && defined( USART_CTRL_MVDIS )
	initasync.mvdis = 0;
	initasync.prsRxEnable = 0;
	initasync.prsRxCh = 0;
#endif

	USART_InitAsync(USART0, &initasync);
	// [USART_InitAsync]$

	// $[USART_InitSync]
	// [USART_InitSync]$

	// $[USART_InitPrsTrigger]
	USART_PrsTriggerInit_TypeDef initprs = USART_INITPRSTRIGGER_DEFAULT;

	initprs.rxTriggerEnable = 0;
	initprs.txTriggerEnable = 0;
	initprs.prsTriggerChannel = usartPrsTriggerCh0;

	USART_InitPrsTrigger(USART0, &initprs);
	// [USART_InitPrsTrigger]$

}

//================================================================================
// USART1_enter_DefaultMode_from_RESET
//================================================================================
extern void USART1_enter_DefaultMode_from_RESET(void) {

	// $[USART_InitAsync]
	USART_InitAsync_TypeDef initasync = USART_INITASYNC_DEFAULT;

	initasync.baudrate = 921600;
	initasync.databits = usartDatabits8;
	initasync.parity = usartNoParity;
	initasync.stopbits = usartStopbits1;
	initasync.oversampling = usartOVS16;
#if defined( USART_INPUT_RXPRS ) && defined( USART_CTRL_MVDIS )
	initasync.mvdis = 0;
	initasync.prsRxEnable = 0;
	initasync.prsRxCh = 0;
#endif

	USART_InitAsync(USART1, &initasync);
	// [USART_InitAsync]$

	// $[USART_InitSync]
	// [USART_InitSync]$

	// $[USART_InitPrsTrigger]
	USART_PrsTriggerInit_TypeDef initprs = USART_INITPRSTRIGGER_DEFAULT;

	initprs.rxTriggerEnable = 0;
	initprs.txTriggerEnable = 0;
	initprs.prsTriggerChannel = usartPrsTriggerCh0;

	USART_InitPrsTrigger(USART1, &initprs);
	// [USART_InitPrsTrigger]$

}

//================================================================================
// USART2_enter_DefaultMode_from_RESET
//================================================================================
extern void USART2_enter_DefaultMode_from_RESET(void) {

	// $[USART_InitAsync]
	// [USART_InitAsync]$

	// $[USART_InitSync]
	USART_InitSync_TypeDef initsync = USART_INITSYNC_DEFAULT;

	initsync.baudrate = 115200;
	initsync.databits = usartDatabits8;
	initsync.master = 1;
	initsync.msbf = 1;
	initsync.clockMode = usartClockMode0;
#if defined( USART_INPUT_RXPRS ) && defined( USART_TRIGCTRL_AUTOTXTEN )
	initsync.prsRxEnable = 0;
	initsync.prsRxCh = 0;
	initsync.autoTx = 0;
#endif

	USART_InitSync(USART2, &initsync);
	// [USART_InitSync]$

	// $[USART_InitPrsTrigger]
	USART_PrsTriggerInit_TypeDef initprs = USART_INITPRSTRIGGER_DEFAULT;

	initprs.rxTriggerEnable = 0;
	initprs.txTriggerEnable = 0;
	initprs.prsTriggerChannel = usartPrsTriggerCh0;

	USART_InitPrsTrigger(USART2, &initprs);
	// [USART_InitPrsTrigger]$

}

//================================================================================
// UART0_enter_DefaultMode_from_RESET
//================================================================================
extern void UART0_enter_DefaultMode_from_RESET(void) {

	// $[UART_InitAsync]
	USART_InitAsync_TypeDef initasync = USART_INITASYNC_DEFAULT;

	initasync.baudrate = 921600;
	initasync.databits = usartDatabits8;
	initasync.parity = usartNoParity;
	initasync.stopbits = usartStopbits1;
	initasync.oversampling = usartOVS16;
#if defined( USART_INPUT_RXPRS ) && defined( USART_CTRL_MVDIS )
	initasync.mvdis = 0;
	initasync.prsRxEnable = 0;
	initasync.prsRxCh = 0;
#endif

	USART_InitAsync(UART0, &initasync);
	// [UART_InitAsync]$

	// $[USART_InitPrsTrigger]
	USART_PrsTriggerInit_TypeDef initprs = USART_INITPRSTRIGGER_DEFAULT;

	initprs.rxTriggerEnable = 0;
	initprs.txTriggerEnable = 0;
	initprs.prsTriggerChannel = usartPrsTriggerCh0;

	USART_InitPrsTrigger(UART0, &initprs);
	// [USART_InitPrsTrigger]$

}

//================================================================================
// UART1_enter_DefaultMode_from_RESET
//================================================================================
extern void UART1_enter_DefaultMode_from_RESET(void) {

	// $[UART_InitAsync]
	USART_InitAsync_TypeDef initasync = USART_INITASYNC_DEFAULT;

	initasync.baudrate = 921600;
	initasync.databits = usartDatabits8;
	initasync.parity = usartNoParity;
	initasync.stopbits = usartStopbits1;
	initasync.oversampling = usartOVS16;
#if defined( USART_INPUT_RXPRS ) && defined( USART_CTRL_MVDIS )
	initasync.mvdis = 0;
	initasync.prsRxEnable = 0;
	initasync.prsRxCh = 0;
#endif

	USART_InitAsync(UART1, &initasync);
	// [UART_InitAsync]$

	// $[USART_InitPrsTrigger]
	USART_PrsTriggerInit_TypeDef initprs = USART_INITPRSTRIGGER_DEFAULT;

	initprs.rxTriggerEnable = 0;
	initprs.txTriggerEnable = 0;
	initprs.prsTriggerChannel = usartPrsTriggerCh0;

	USART_InitPrsTrigger(UART1, &initprs);
	// [USART_InitPrsTrigger]$

}

//================================================================================
// LEUART0_enter_DefaultMode_from_RESET
//================================================================================
extern void LEUART0_enter_DefaultMode_from_RESET(void) {

	// $[LEUART0 initialization]
	// [LEUART0 initialization]$

}

//================================================================================
// LEUART1_enter_DefaultMode_from_RESET
//================================================================================
extern void LEUART1_enter_DefaultMode_from_RESET(void) {

	// $[LEUART1 initialization]
	LEUART_Init_TypeDef initleuart = LEUART_INIT_DEFAULT;

	initleuart.enable = leuartEnable;
	initleuart.baudrate = 9600;
	initleuart.databits = leuartDatabits8;
	initleuart.parity = leuartNoParity;
	initleuart.stopbits = leuartStopbits1;
	LEUART_Init(LEUART1, &initleuart);

	/* Configuring non-standard properties */
	LEUART_TxDmaInEM2Enable(LEUART1, 0);
	LEUART_RxDmaInEM2Enable(LEUART1, 0);

	// [LEUART1 initialization]$

}

//================================================================================
// VCMP_enter_DefaultMode_from_RESET
//================================================================================
extern void VCMP_enter_DefaultMode_from_RESET(void) {

	// $[VCMP_Init]
	// [VCMP_Init]$

}

//================================================================================
// WDOG_enter_DefaultMode_from_RESET
//================================================================================
extern void WDOG_enter_DefaultMode_from_RESET(void) {

	// $[CMU_ClockEnable]
	// [CMU_ClockEnable]$

	// $[CMU_OscillatorEnable]
	// [CMU_OscillatorEnable]$

	// $[WDOG_Init]
	// [WDOG_Init]$

}

//================================================================================
// I2C0_enter_DefaultMode_from_RESET
//================================================================================
extern void I2C0_enter_DefaultMode_from_RESET(void) {

	// $[I2C0 initialization]
	I2C_Init_TypeDef init = I2C_INIT_DEFAULT;

	init.enable = 1;
	init.master = 1;
	init.freq = I2C_FREQ_FAST_MAX;
	init.clhr = i2cClockHLRStandard;
	I2C_Init(I2C0, &init);
	// [I2C0 initialization]$

}

//================================================================================
// I2C1_enter_DefaultMode_from_RESET
//================================================================================
extern void I2C1_enter_DefaultMode_from_RESET(void) {

	// $[I2C1 initialization]
	// [I2C1 initialization]$

}

//================================================================================
// TIMER0_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER0_enter_DefaultMode_from_RESET(void) {

	// $[TIMER0 initialization]
	// [TIMER0 initialization]$

	// $[TIMER0 CC0 init]
	// [TIMER0 CC0 init]$

	// $[TIMER0 CC1 init]
	// [TIMER0 CC1 init]$

	// $[TIMER0 CC2 init]
	// [TIMER0 CC2 init]$

	// $[TIMER0 DTI init]
	// [TIMER0 DTI init]$

}

//================================================================================
// TIMER1_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER1_enter_DefaultMode_from_RESET(void) {

	// $[TIMER1 initialization]
	// [TIMER1 initialization]$

	// $[TIMER1 CC0 init]
	// [TIMER1 CC0 init]$

	// $[TIMER1 CC1 init]
	// [TIMER1 CC1 init]$

	// $[TIMER1 CC2 init]
	// [TIMER1 CC2 init]$

}

//================================================================================
// TIMER2_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER2_enter_DefaultMode_from_RESET(void) {

	// $[TIMER2 initialization]
	// [TIMER2 initialization]$

	// $[TIMER2 CC0 init]
	// [TIMER2 CC0 init]$

	// $[TIMER2 CC1 init]
	// [TIMER2 CC1 init]$

	// $[TIMER2 CC2 init]
	// [TIMER2 CC2 init]$

}

//================================================================================
// TIMER3_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER3_enter_DefaultMode_from_RESET(void) {

	// $[TIMER3 initialization]
	// [TIMER3 initialization]$

	// $[TIMER3 CC0 init]
	// [TIMER3 CC0 init]$

	// $[TIMER3 CC1 init]
	// [TIMER3 CC1 init]$

	// $[TIMER3 CC2 init]
	// [TIMER3 CC2 init]$

}

//================================================================================
// LETIMER0_enter_DefaultMode_from_RESET
//================================================================================
extern void LETIMER0_enter_DefaultMode_from_RESET(void) {

	// $[LETIMER0_Init]
	// [LETIMER0_Init]$

}

//================================================================================
// PCNT0_enter_DefaultMode_from_RESET
//================================================================================
extern void PCNT0_enter_DefaultMode_from_RESET(void) {

	// $[PCNT0 initialization]
	// [PCNT0 initialization]$

}

//================================================================================
// PCNT1_enter_DefaultMode_from_RESET
//================================================================================
extern void PCNT1_enter_DefaultMode_from_RESET(void) {

	// $[PCNT1 initialization]
	// [PCNT1 initialization]$

}

//================================================================================
// PCNT2_enter_DefaultMode_from_RESET
//================================================================================
extern void PCNT2_enter_DefaultMode_from_RESET(void) {

	// $[PCNT2 initialization]
	// [PCNT2 initialization]$

}

//================================================================================
// PRS_enter_DefaultMode_from_RESET
//================================================================================
extern void PRS_enter_DefaultMode_from_RESET(void) {

	// $[PRS initialization]
	// [PRS initialization]$

}

//================================================================================
// ETM_enter_DefaultMode_from_RESET
//================================================================================
extern void ETM_enter_DefaultMode_from_RESET(void) {

	// $[ETM initialization]
	// [ETM initialization]$

}

//================================================================================
// EBI_enter_DefaultMode_from_RESET
//================================================================================
extern void EBI_enter_DefaultMode_from_RESET(void) {

	// $[EBI initialization]
	// [EBI initialization]$

}

//================================================================================
// PORTIO_enter_DefaultMode_from_RESET
//================================================================================
extern void PORTIO_enter_DefaultMode_from_RESET(void) {

	// $[Port A Configuration]

	/* Pin PA3 is configured to Input enabled */
	GPIO->P[0].MODEL = (GPIO->P[0].MODEL & ~_GPIO_P_MODEL_MODE3_MASK)
			| GPIO_P_MODEL_MODE3_INPUT;
	// [Port A Configuration]$

	// $[Port B Configuration]

	/* Pin PB1 is configured to Push-pull */
	GPIO->P[1].MODEL = (GPIO->P[1].MODEL & ~_GPIO_P_MODEL_MODE1_MASK)
			| GPIO_P_MODEL_MODE1_PUSHPULL;

	/* Pin PB3 is configured to Push-pull */
	GPIO->P[1].MODEL = (GPIO->P[1].MODEL & ~_GPIO_P_MODEL_MODE3_MASK)
			| GPIO_P_MODEL_MODE3_PUSHPULL;

	/* Pin PB4 is configured to Input enabled */
	GPIO->P[1].MODEL = (GPIO->P[1].MODEL & ~_GPIO_P_MODEL_MODE4_MASK)
			| GPIO_P_MODEL_MODE4_INPUT;

	/* Pin PB5 is configured to Push-pull */
	GPIO->P[1].MODEL = (GPIO->P[1].MODEL & ~_GPIO_P_MODEL_MODE5_MASK)
			| GPIO_P_MODEL_MODE5_PUSHPULL;

	/* Pin PB6 is configured to Push-pull */
	GPIO->P[1].MODEL = (GPIO->P[1].MODEL & ~_GPIO_P_MODEL_MODE6_MASK)
			| GPIO_P_MODEL_MODE6_PUSHPULL;
	// [Port B Configuration]$

	// $[Port C Configuration]

	/* Pin PC0 is configured to Open-drain with pull-up and filter */
	GPIO->P[2].MODEL = (GPIO->P[2].MODEL & ~_GPIO_P_MODEL_MODE0_MASK)
			| GPIO_P_MODEL_MODE0_WIREDANDPULLUPFILTER;

	/* Pin PC1 is configured to Open-drain with pull-up and filter */
	GPIO->P[2].MODEL = (GPIO->P[2].MODEL & ~_GPIO_P_MODEL_MODE1_MASK)
			| GPIO_P_MODEL_MODE1_WIREDANDPULLUPFILTER;

	/* Pin PC6 is configured to Push-pull */
	GPIO->P[2].MODEL = (GPIO->P[2].MODEL & ~_GPIO_P_MODEL_MODE6_MASK)
			| GPIO_P_MODEL_MODE6_PUSHPULL;

	/* Pin PC7 is configured to Input enabled */
	GPIO->P[2].MODEL = (GPIO->P[2].MODEL & ~_GPIO_P_MODEL_MODE7_MASK)
			| GPIO_P_MODEL_MODE7_INPUT;

	/* Pin PC8 is configured to Input enabled */
	GPIO->P[2].MODEH = (GPIO->P[2].MODEH & ~_GPIO_P_MODEH_MODE8_MASK)
			| GPIO_P_MODEH_MODE8_INPUT;

	/* Pin PC9 is configured to Input enabled */
	GPIO->P[2].MODEH = (GPIO->P[2].MODEH & ~_GPIO_P_MODEH_MODE9_MASK)
			| GPIO_P_MODEH_MODE9_INPUT;

	/* Pin PC10 is configured to Push-pull */
	GPIO->P[2].MODEH = (GPIO->P[2].MODEH & ~_GPIO_P_MODEH_MODE10_MASK)
			| GPIO_P_MODEH_MODE10_PUSHPULL;

	/* Pin PC11 is configured to Push-pull */
	GPIO->P[2].MODEH = (GPIO->P[2].MODEH & ~_GPIO_P_MODEH_MODE11_MASK)
			| GPIO_P_MODEH_MODE11_PUSHPULL;
	// [Port C Configuration]$

	// $[Port D Configuration]

	/* Pin PD6 is configured to Input enabled */
	GPIO->P[3].MODEL = (GPIO->P[3].MODEL & ~_GPIO_P_MODEL_MODE6_MASK)
			| GPIO_P_MODEL_MODE6_INPUT;

	/* Pin PD7 is configured to Push-pull */
	GPIO->P[3].MODEL = (GPIO->P[3].MODEL & ~_GPIO_P_MODEL_MODE7_MASK)
			| GPIO_P_MODEL_MODE7_PUSHPULL;
	// [Port D Configuration]$

	// $[Port E Configuration]

	/* Pin PE0 is configured to Push-pull */
	GPIO->P[4].MODEL = (GPIO->P[4].MODEL & ~_GPIO_P_MODEL_MODE0_MASK)
			| GPIO_P_MODEL_MODE0_PUSHPULL;

	/* Pin PE1 is configured to Input enabled */
	GPIO->P[4].MODEL = (GPIO->P[4].MODEL & ~_GPIO_P_MODEL_MODE1_MASK)
			| GPIO_P_MODEL_MODE1_INPUT;

	/* Pin PE2 is configured to Push-pull */
	GPIO->P[4].MODEL = (GPIO->P[4].MODEL & ~_GPIO_P_MODEL_MODE2_MASK)
			| GPIO_P_MODEL_MODE2_PUSHPULL;

	/* Pin PE3 is configured to Input enabled */
	GPIO->P[4].MODEL = (GPIO->P[4].MODEL & ~_GPIO_P_MODEL_MODE3_MASK)
			| GPIO_P_MODEL_MODE3_INPUT;

	/* Pin PE4 is configured to Input enabled */
	GPIO->P[4].MODEL = (GPIO->P[4].MODEL & ~_GPIO_P_MODEL_MODE4_MASK)
			| GPIO_P_MODEL_MODE4_INPUT;

	/* Pin PE5 is configured to Input enabled */
	GPIO->P[4].MODEL = (GPIO->P[4].MODEL & ~_GPIO_P_MODEL_MODE5_MASK)
			| GPIO_P_MODEL_MODE5_INPUT;

	/* Pin PE6 is configured to Push-pull */
	GPIO->P[4].MODEL = (GPIO->P[4].MODEL & ~_GPIO_P_MODEL_MODE6_MASK)
			| GPIO_P_MODEL_MODE6_PUSHPULL;

	/* Pin PE7 is configured to Push-pull */
	GPIO->P[4].MODEL = (GPIO->P[4].MODEL & ~_GPIO_P_MODEL_MODE7_MASK)
			| GPIO_P_MODEL_MODE7_PUSHPULL;

	/* Pin PE10 is configured to Push-pull with alt. drive strength */
	GPIO->P[4].MODEH = (GPIO->P[4].MODEH & ~_GPIO_P_MODEH_MODE10_MASK)
			| GPIO_P_MODEH_MODE10_PUSHPULLDRIVE;

	/* Pin PE11 is configured to Input enabled */
	GPIO->P[4].MODEH = (GPIO->P[4].MODEH & ~_GPIO_P_MODEH_MODE11_MASK)
			| GPIO_P_MODEH_MODE11_INPUT;
	// [Port E Configuration]$

	// $[Port F Configuration]
	// [Port F Configuration]$

	// $[Route Configuration]

	/* Module I2C0 is configured to location 4 */
	I2C0->ROUTE = (I2C0->ROUTE & ~_I2C_ROUTE_LOCATION_MASK)
			| I2C_ROUTE_LOCATION_LOC4;

	/* Enable signals SCL, SDA */
	I2C0->ROUTE |= I2C_ROUTE_SCLPEN | I2C_ROUTE_SDAPEN;

	/* Enable signals RX, TX */
	LEUART1->ROUTE |= LEUART_ROUTE_RXPEN | LEUART_ROUTE_TXPEN;

	/* Module UART0 is configured to location 1 */
	UART0->ROUTE = (UART0->ROUTE & ~_UART_ROUTE_LOCATION_MASK)
			| UART_ROUTE_LOCATION_LOC1;

	/* Enable signals RX, TX */
	UART0->ROUTE |= UART_ROUTE_RXPEN | UART_ROUTE_TXPEN;

	/* Module UART1 is configured to location 3 */
	UART1->ROUTE = (UART1->ROUTE & ~_UART_ROUTE_LOCATION_MASK)
			| UART_ROUTE_LOCATION_LOC3;

	/* Enable signals RX, TX */
	UART1->ROUTE |= UART_ROUTE_RXPEN | UART_ROUTE_TXPEN;

	/* Enable signals RX, TX */
	USART0->ROUTE |= USART_ROUTE_RXPEN | USART_ROUTE_TXPEN;

	/* Module USART1 is configured to location 2 */
	USART1->ROUTE = (USART1->ROUTE & ~_USART_ROUTE_LOCATION_MASK)
			| USART_ROUTE_LOCATION_LOC2;

	/* Enable signals RX, TX */
	USART1->ROUTE |= USART_ROUTE_RXPEN | USART_ROUTE_TXPEN;

	/* Module USART2 is configured to location 1 */
	USART2->ROUTE = (USART2->ROUTE & ~_USART_ROUTE_LOCATION_MASK)
			| USART_ROUTE_LOCATION_LOC1;

	/* Enable signals CLK, CS, RX, TX */
	USART2->ROUTE |= USART_ROUTE_CLKPEN | USART_ROUTE_RXPEN
			| USART_ROUTE_TXPEN;
	// [Route Configuration]$

}

