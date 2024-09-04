/*
    This file contains the code for reading the sliders.
    The sliders are connected to the ESP32 through the analog pins.
    The sliders are used to control the fade in and fade out + more of the DMX signal.

    Created by theMenace, 2024 03 09
*/


#include "sliders.h"

#define FADE_IN_PIN 0
#define FADE_OUT_PIN 1
int highest = 2000;
int lowest = 2000;
byte lastValue = 0;
enum fader
{
    in,
    out
};
movingAvg fade_in_slider(10);
movingAvg fade_out_slider(10);

movingAvg test_slider(10);

void setup_sliders()
{
    pinMode(FADE_IN_PIN, INPUT_PULLDOWN);
    pinMode(FADE_OUT_PIN, INPUT_PULLDOWN);
    fade_in_slider.begin();
    fade_out_slider.begin();

    test_slider.begin();
}

// This function reads from the fade in fader and returns the value.
byte read_slider(byte slider)
{
    int value;
    int avg;

    switch (slider)
    {
    // Fade in fader
    case 0:
        value = analogRead(FADE_IN_PIN);
        avg = fade_in_slider.reading(value);
        break;

    // Fade out fader
    case 1:
        value = analogRead(FADE_OUT_PIN);
        avg = fade_in_slider.reading(value);
        break;

    case 255:
        value = 3000;
        avg = test_slider.reading(value);
        break;

    default:
        return 0;
        break;
    }

    // flip the value so that the fader works in the correct direction
    avg = 4095 - avg;

    byte data = map(avg, 0, 4095, 0, 255);
    printf("avg: %d \t Fade in value: %d\n", avg, data);

    return data;

    /*
    byte value = map(analogRead(FADE_IN_PIN), 0, 4096, 0, 255);
    printf("Fade in value: %d\n", value);
    return value;
    */
}