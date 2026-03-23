# Encoder demo

Simple ESP32 + rotary encoder demo based on PlatformIO and EncButton.

## Functionality

- Normal rotation changes `val` by `+1` or `-1`
- Rotation while the encoder button is pressed changes `val` by `+5` or `-5`
- Short button click resets `val` to `0`
- All events are printed to Serial at `115200`

## Wiring

Board: `esp32doit-devkit-v1`

- Encoder `CLK` -> GPIO `18`
- Encoder `DT` -> GPIO `19`
- Encoder `SW` -> GPIO `5`
- Encoder `VCC` -> `3.3V`
- Encoder `GND` -> `GND`

The code uses internal pull-up resistors.

## Build

```bash
pio run
```

## Upload

```bash
pio run --target upload --upload-port COM4
```

## Serial monitor

```bash
pio device monitor --baud 115200
```

## Main logic

The encoder handling code is in `src/main.cpp`.

Current behavior summary:

- `EB_STEP4_LOW` mode is used for one detent per step on a typical mechanical encoder
- `EB_TURN` handles rotation events
- `EB_CLICK` resets the counter
