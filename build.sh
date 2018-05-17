#!/bin/bash
ARDUINO_CMD="~/arduino-1.8.5/arduino"
BOARD="arduino:avr:uno"
PORT="/dev/ttyACM0"
SKETCH="Blinky.ino"

eval $ARDUINO_CMD --upload --board $BOARD --port $PORT $SKETCH
