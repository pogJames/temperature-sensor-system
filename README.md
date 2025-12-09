# TEMPERATURE-SENSOR-SYSTEM
A complete implementation of Modbus RTU communication between two Arduino UNO boards for remote temperature monitoring over RS-485. The master Arduino reads temperature data from a slave Arduino equipped with a temperature sensor.

## RS-485
It's a physical wiring standard, using electrical connections: D+/A and D-/B
> like wires on a telephone line

**IMPORTANT**: A connects to A, B connects to B, can be found in the device's RS-485 section

## Modbus
It's a client/server data communication protocol in the application layer
> like the words spoken during a call

**Input Registers**: read-only data
> usually sensor data, like current temperature value or current humidity value

**Holding Registers**: Read and write data
> like a notebook, maybe to set a target temperature or to write a configuration value for a sensor

### 1. Slave ID
pretty self-explanatory

### 2. Baud Rate
It's the speed at which two devices talk to each other, both devices **must use the same baud rate**, or the data becomes unreadable
> like talking speed; if you speak too fast, I can't keep up; If I talk too slow while you talk fast, we can't understand each other

### 3. Data bit
Length of actual information, if data bit is 8, then:
```bash
[Start Bit] [8 Data Bits] [Parity Bit] [Stop Bit]
```

### 4. Parity Bit
**Purpose**: error detection<br>
- It's a **single extra bit** added to each byte of data
- It helps the receiver know if the byte got corrupted during transmission
> like a **checksum or “spell check”** in your message — it tells the receiver

**Even Parity (E)**: the total number of `1`s in the binary message + parity bit = even
> Data: `101100` -> Parity Bit: `1` -> `1011001` (Total `1`s = 4, even)

**Odd Parity (O)**: the total number of `1`s in the binary message + parity bit = odd
> Data: `101100` -> Parity Bit: `0` -> `1011000` (Total `1`s = 3, odd)

**No Parity (N)**: no parity, no error check

### 5. Stop Bit
**Purpose**: mark the end of a byte<br>
- It’s a bit (or two) sent after the data byte to signal that the byte is finished
- It tells the receiver: “You can start reading the next byte now”
> like a **period at the end of a sentence** — it separates one byte from the next so the receiver doesn’t get confused
