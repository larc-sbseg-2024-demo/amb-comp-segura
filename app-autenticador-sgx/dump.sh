#!/bin/bash

APP_PID=$(pidof app)
echo "PID de App: $APP_PID"

gcore -a -o dump.bin $APP_PID
