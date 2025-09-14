---
layout: default
title: "Hardware - WattIsIt"
permalink: /hardware/
---

## WattIsIt Hardware

A battery watt meter using ADS1115 and a shunt to measure power usage. The Arduino sketch is located in `Arduino/WattIsIt`. Been using the DOIT ESP32 DEVKIT V1 board.

## Wiring Diagram

**+** Positive battery terminal

**-** Negative battery terminal

**L** Low side of current shunt resistor

**H** High side of current shunt resistor

<img src="../images/wiring_diagram.png" width="500" />

## Bill of Materials (BOM)

AHT21 is optional, was used for humidity but also has a temperature sensor.

| Item             | Link                                             |
| ---------------- | ------------------------------------------------ |
| U2 ESP32         | [https://a.co/d/88cG9Z5](https://a.co/d/88cG9Z5) |
| M1 ADS1115       | [https://a.co/d/gfCO6jt](https://a.co/d/gfCO6jt) |
| U1 Voltage Reg   | [https://a.co/d/cpmFpuU](https://a.co/d/cpmFpuU) |
| U4 AHT21         | [https://a.co/d/6xBWBLx](https://a.co/d/6xBWBLx) |
| U3 BMP280        | [https://a.co/d/1HV9oyw](https://a.co/d/1HV9oyw) |
| J1 Terminals     | [https://a.co/d/8nVocXb](https://a.co/d/8nVocXb) |
| J1 JST Connector | [https://a.co/d/0xq4sMO](https://a.co/d/0xq4sMO) |
| Shunt            | [https://a.co/d/7QWWK5O](https://a.co/d/7QWWK5O) |
| R1 10k Ohm       | [https://a.co/d/6f4wvqz](https://a.co/d/6f4wvqz) |
| R2 5.1k Ohm      | [https://a.co/d/adCeki6](https://a.co/d/adCeki6) |

## Version 1.0

|                KiCad Model                |                 In Use                  |
| :---------------------------------------: | :-------------------------------------: |
| <img src="../images/proto1.png" width="300"> | <img src="../images/pcb.jpeg" width="300"> |

## Arduino Code

The Arduino sketch for the WattIsIt module is available in the `Arduino/WattIsIt/` directory. This code handles:

- Reading voltage and current measurements from the ADS1115 ADC
- Calculating power and energy usage
- Bluetooth communication with the mobile app
- Optional temperature and humidity sensing
