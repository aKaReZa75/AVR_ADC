This document describes all ADC input channels, multiplexer usage, and differential measurement options available on the ATmega328 microcontroller.

---

## **ADMUX – ADC Multiplexer Selection Register**

The **ADMUX** register selects the input channel for the ADC and the reference voltage for the conversion.

| Bit  | Name       | Description                                                     |
|------|------------|---------------------------------------------------------------|
| 7    | **REFS1**  | Reference Voltage Selection Bit 1                             |
| 6    | **REFS0**  | Reference Voltage Selection Bit 0                             |
| 5    | **ADLAR**  | ADC Left Adjust Result (Adjusts result alignment)              |
| 4    | -          | Reserved (Not used)                                             |
| 3    | **MUX3**   | ADC Channel Select Bit 3                                       |
| 2    | **MUX2**   | ADC Channel Select Bit 2                                       |
| 1    | **MUX1**   | ADC Channel Select Bit 1                                       |
| 0    | **MUX0**   | ADC Channel Select Bit 0                                       |

- **REFS1..0 (Reference Voltage Selection Bits)**:  
  These bits determine the reference voltage used for ADC conversion. The available settings are:
  - **00**: AREF, with the internal reference voltage turned off.
  - **01**: AVCC with an external capacitor at the AREF pin.
  - **10**: Internal 1.1V reference voltage with an external capacitor at the AREF pin.
  - **11**: Reserved (not commonly used).

- **MUX3..0 (ADC Channel Select Bits)**:  
  These bits select the input channel for the ADC. The ATMEGA328 provides up to 8 channels (0–7), which are used for reading analog signals. Example:

| **MUX3** | **MUX2** | **MUX1** | **MUX0** | **Channel Description**                                |
|----------|----------|----------|----------|--------------------------------------------------------|
| 0        | 0        | 0        | 0        | ADC Channel 0 (Analog input pin 0)                     |
| 0        | 0        | 0        | 1        | ADC Channel 1 (Analog input pin 1)                     |
| 0        | 0        | 1        | 0        | ADC Channel 2 (Analog input pin 2)                     |
| 0        | 0        | 1        | 1        | ADC Channel 3 (Analog input pin 3)                     |
| 0        | 1        | 0        | 0        | ADC Channel 4 (Analog input pin 4)                     |
| 0        | 1        | 0        | 1        | ADC Channel 5 (Analog input pin 5)                     |
| 0        | 1        | 1        | 0        | ADC Channel 6 (Analog input pin 6)                     |
| 0        | 1        | 1        | 1        | ADC Channel 7 (Analog input pin 7)                     |
| 1        | 0        | 0        | 0        | Internal 1.1V reference (used for measuring internal 1.1V reference against the selected channel) |
| 1        | 0        | 0        | 1        | Reserved (Not typically used)                          |
| 1        | 0        | 1        | 0        | Reserved (Not typically used)                          |
| 1        | 0        | 1        | 1        | Reserved (Not typically used)                          |
| 1        | 1        | 0        | 0        | Internal temperature sensor (used for measuring the internal temperature of the microcontroller) |
| 1        | 1        | 0        | 1        | Reserved (Not typically used)                          |
| 1        | 1        | 1        | 0        | Reserved (Not typically used)                          |
| 1        | 1        | 1        | 1        | Reserved (Not typically used)                          |


- **ADLAR (ADC Left Adjust Result)**:  
  This bit controls the alignment of the ADC result. When set to **1**, the result is left-aligned in the ADC Data Registers (i.e., the 10-bit result is placed in the high byte **ADCH**). If cleared to **0**, the result is right-aligned (i.e., the 10-bit result is placed in the low byte **ADCL**).

To provide a clearer visualization of how the 10-bit ADC result is stored in the **ADCL** and **ADCH** registers based on the **ADLAR** setting, here's a table showing both **left-alignment** and **right-alignment** for the example ADC result of **963**.

- **ADC Result (963 Decimal) = 0x03C3 (Hexadecimal)**
- **Binary Representation**: **0000001111000011** (10 bits)

#### **Left Alignment (ADLAR = 1)**
When **ADLAR** is set to **1**, the 10-bit result is **left-aligned**, so the most significant bits (MSBs) are placed in **ADCH** (high byte) and the least significant bits (LSBs) in **ADCL** (low byte).

| Register  | Bit Position | 7    | 6    | 5    | 4    | 3    | 2    | 1    | 0    |
|-----------|--------------|------|------|------|------|------|------|------|------|
| **ADCH**  | High Byte    | **0**  | **0**  | **0**  | **0**  | **0**  | **1**  | **1**  | **0**  |
| **ADCL**  | Low Byte     | **1**  | **1**  | **1**  | **1**  | **0**  | **0**  | **0**  | **1**  |

##### Explanation:
- **ADCH**: Contains the 2 most significant bits (**00** from the higher part of the result `0x03C3` → 0x03).
- **ADCL**: Contains the 8 least significant bits (**11110001** from the lower part of the result `0x03C3` → 0xF1).

#### **Right Alignment (ADLAR = 0)**
When **ADLAR** is cleared to **0**, the 10-bit result is **right-aligned**, meaning the least significant bits (LSBs) are placed in **ADCL** and the most significant bits (MSBs) in **ADCH**.

| Register  | Bit Position | 7    | 6    | 5    | 4    | 3    | 2    | 1    | 0    |
|-----------|--------------|------|------|------|------|------|------|------|------|
| **ADCH**  | High Byte    | **0**  | **0**  | **0**  | **0**  | **1**  | **1**  | **1**  | **1**  |
| **ADCL**  | Low Byte     | **0**  | **0**  | **0**  | **1**  | **1**  | **0**  | **0**  | **1**  |

##### Explanation:
- **ADCH**: Contains the 2 most significant bits (**11110000** from the higher part of the result `0x03C3` → 0xF0).
- **ADCL**: Contains the 8 least significant bits (**00000011** from the lower part of the result `0x03C3` → 0x03).


### **Example: Select ADC2**

```c
/* Select ADC2 as input channel */
bitClear(ADMUX, MUX4);
bitSet(ADMUX, MUX1);
bitClear(ADMUX, MUX0);
```


# 🌟 Support Me
If you found this repository useful:
- Subscribe to my [YouTube Channel](https://www.youtube.com/@aKaReZa75).
- Share this repository with others.
- Give this repository and my other repositories a star.
- Follow my [GitHub account](https://github.com/aKaReZa75).

# ✉️ Contact Me
Feel free to reach out to me through any of the following platforms:
- 📧 [Email: aKaReZa75@gmail.com](mailto:aKaReZa75@gmail.com)
- 🎥 [YouTube: @aKaReZa75](https://www.youtube.com/@aKaReZa75)
- 💼 [LinkedIn: @akareza75](https://www.linkedin.com/in/akareza75)
