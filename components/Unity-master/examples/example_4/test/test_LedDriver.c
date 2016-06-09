#include "unity.h"
#include "LedDriver.h"
#include "RuntimeErrorStub.h"

static uint16_t virtualLeds;

void setUp(void)
{
	LedDriver_Create(&virtualLeds);
}

void tearDown(void)
{
}

void test_leds_off_after_create(void)
{
	uint16_t virtualLeds = 0xffff;
	LedDriver_Create(&virtualLeds);
	TEST_ASSERT_EQUAL_HEX16(0x0000, virtualLeds);
}

void test_turn_on_led(void)
{
	LedDriver_TurnOn(1);
	TEST_ASSERT_EQUAL_HEX16(0x0001, virtualLeds);
}

void test_turn_off_led(void)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOff(1);
	TEST_ASSERT_EQUAL_HEX16(0x0000,virtualLeds);
}

void test_turn_on_multiple_leds(void)
{
	LedDriver_TurnOn(8);
	LedDriver_TurnOn(9);
	TEST_ASSERT_EQUAL_HEX16(0x0180,virtualLeds);
}

void test_turn_on_all_leds(void)
{
	LedDriver_TurnOnAll();
	TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}

void test_turn_off_multiple_leds(void)
{
	LedDriver_TurnOnAll();
	LedDriver_TurnOff(8);
	TEST_ASSERT_EQUAL_HEX16(0xff7f, virtualLeds);
}

void test_led_state_is_readable(void)
{
	virtualLeds = 0xffff;
	LedDriver_TurnOn(8);
	TEST_ASSERT_EQUAL_HEX16(0x0080, virtualLeds);
}

void test_out_of_bound_turn_on_no_harm(void)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOn(-1);
	LedDriver_TurnOn(3141);
	TEST_ASSERT_EQUAL_HEX16(0x0001, virtualLeds);
}

void test_out_of_bound_turn_off_no_harm(void)
{
	LedDriver_TurnOnAll();
	LedDriver_TurnOff(8);
	LedDriver_TurnOff(-1);
	LedDriver_TurnOff(3141);
	TEST_ASSERT_EQUAL_HEX16(0xff7f, virtualLeds);
}

void test_out_of_bound_produce_runtime_error(void)
{
	LedDriver_TurnOn(-1);
	TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED", RuntimeErrorStub_GetLastError());
	TEST_ASSERT_EQUAL(-1, RuntimeErrorStub_GetLastParameter());
}
