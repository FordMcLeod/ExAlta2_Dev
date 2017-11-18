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
#include "em_gpio.h"
#include "em_usart.h"
// [Library includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void enter_DefaultMode_from_RESET(void) {
	// $[Config Calls]
	HFXO_enter_DefaultMode_from_RESET();
	CMU_enter_DefaultMode_from_RESET();
	USART0_enter_DefaultMode_from_RESET();
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
	// [Use oscillator source]$

	// $[LFXO Boost Percent]
	// [LFXO Boost Percent]$

	// $[REDLFXO Boost]
	// [REDLFXO Boost]$

}

//================================================================================
// CMU_enter_DefaultMode_from_RESET
//================================================================================
extern void CMU_enter_DefaultMode_from_RESET(void) {

	// $[LFXO enable]
	// [LFXO enable]$

	// $[HFXO enable]
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
	/* No LF peripherals enabled */
	// [LF clock tree setup]$
	// $[Peripheral Clock enables]
	/* Enable clock for USART0 */
	CMU_ClockEnable(cmuClock_USART0, true);

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
	// [CMU_ClockEnable]$

	// $[CMU_OscillatorEnable]
	// [CMU_OscillatorEnable]$

	// $[RMU_ResetControl]
	// [RMU_ResetControl]$

	// $[BURTC_Init]
	// [BURTC_Init]$

	// $[BURTC_CompareSet]
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
	// [USART_InitAsync]$

	// $[USART_InitSync]
	// [USART_InitSync]$

	// $[USART_InitPrsTrigger]
	// [USART_InitPrsTrigger]$

}

//================================================================================
// USART2_enter_DefaultMode_from_RESET
//================================================================================
extern void USART2_enter_DefaultMode_from_RESET(void) {

	// $[USART_InitAsync]
	// [USART_InitAsync]$

	// $[USART_InitSync]
	// [USART_InitSync]$

	// $[USART_InitPrsTrigger]
	// [USART_InitPrsTrigger]$

}

//================================================================================
// UART0_enter_DefaultMode_from_RESET
//================================================================================
extern void UART0_enter_DefaultMode_from_RESET(void) {

	// $[UART_InitAsync]
	// [UART_InitAsync]$

	// $[USART_InitPrsTrigger]
	// [USART_InitPrsTrigger]$

}

//================================================================================
// UART1_enter_DefaultMode_from_RESET
//================================================================================
extern void UART1_enter_DefaultMode_from_RESET(void) {

	// $[UART_InitAsync]
	// [UART_InitAsync]$

	// $[USART_InitPrsTrigger]
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

	/* Pin PA7 is configured to Push-pull */
	GPIO->P[0].MODEL = (GPIO->P[0].MODEL & ~_GPIO_P_MODEL_MODE7_MASK)
			| GPIO_P_MODEL_MODE7_PUSHPULL;
	// [Port A Configuration]$

	// $[Port B Configuration]
	// [Port B Configuration]$

	// $[Port C Configuration]
	// [Port C Configuration]$

	// $[Port D Configuration]
	// [Port D Configuration]$

	// $[Port E Configuration]

	/* Pin PE6 is configured to Input enabled */
	GPIO->P[4].MODEL = (GPIO->P[4].MODEL & ~_GPIO_P_MODEL_MODE6_MASK)
			| GPIO_P_MODEL_MODE6_INPUT;

	/* Pin PE7 is configured to Push-pull */
	GPIO->P[4].MODEL = (GPIO->P[4].MODEL & ~_GPIO_P_MODEL_MODE7_MASK)
			| GPIO_P_MODEL_MODE7_PUSHPULL;
	// [Port E Configuration]$

	// $[Port F Configuration]
	// [Port F Configuration]$

	// $[Route Configuration]

	/* Module USART0 is configured to location 1 */
	USART0->ROUTE = (USART0->ROUTE & ~_USART_ROUTE_LOCATION_MASK)
			| USART_ROUTE_LOCATION_LOC1;

	/* Enable signals RX, TX */
	USART0->ROUTE |= USART_ROUTE_RXPEN | USART_ROUTE_TXPEN;
	// [Route Configuration]$

}

