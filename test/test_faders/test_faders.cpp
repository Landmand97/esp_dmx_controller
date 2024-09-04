/* 
This is a test file for the sliders.cpp file.
*/

#include <unity.h>
#include <sliders.h>

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void test_read_slider(void)
{
    TEST_ASSERT_EQUAL(68, read_slider(255)); // default case
}

void setup()
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN(); // IMPORTANT LINE!
    setup_sliders();
}

void loop()
{
    RUN_TEST(test_read_slider);

    UNITY_END(); // stop unit testing
}
