#include "LedDriver.h"
#include "RuntimeError.h"

static uint16_t * ledsAddress;
static uint16_t ledsState;

enum
{
	ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON
};

void LedDriver_Create(uint16_t * address)
{
	ledsAddress = address;
	ledsState = ALL_LEDS_OFF;
	*ledsAddress = ledsState;
}

static void update_leds_state()
{
	*ledsAddress = ledsState;
}

static int convert_led_number_to_bit(int ledNumber)
{
	return 1 << (ledNumber - 1);
}

static BOOL is_led_number_out_of_bound(int ledNumber)
{
	if(ledNumber <= 0 || ledNumber > 16)
	{
		RUNTIME_ERROR("LED Driver: out-of-bounds LED", ledNumber);
		return TRUE;
	}
	return FALSE;
}

void LedDriver_TurnOn(int ledNumber)
{
	if(is_led_number_out_of_bound(ledNumber)) return;
	
	ledsState |= convert_led_number_to_bit(ledNumber);
	update_leds_state();
}

void LedDriver_TurnOnAll()
{
	ledsState = ALL_LEDS_ON;
	update_leds_state();
}

void LedDriver_TurnOff(int ledNumber)
{
	if(is_led_number_out_of_bound(ledNumber)) return;
	
	ledsState &= ~(convert_led_number_to_bit(ledNumber));
	update_leds_state();
}

