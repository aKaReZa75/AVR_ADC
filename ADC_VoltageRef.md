This document details the available voltage reference sources for the ADC on ATmega328, including AREF, AVcc, and the internal 1.1V reference. It explains how to select each source, their trade-offs, and best practices for reliable analog conversion.

## **Reference Voltage Selection (REFS1:0)**

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


## **Available Voltage Reference Sources**

### **1. AREF (External Reference via AREF Pin)**
| REFS1 | REFS0 | Configuration |
|-------|-------|----------------|
| 0     | 0     | External voltage on AREF pin |

- Allows full control over reference voltage
- Requires external capacitor on AREF pin for stability
- Ideal for precision analog systems

```c
// Select external reference via AREF pin
bitClear(ADMUX, REFS1);
bitClear(ADMUX, REFS0); 
```

> [!CAUTION]
> Never apply voltage to AREF pin unless REFS1:0 = 00. Otherwise, internal reference may conflict.

---

### **2. AVcc (Vcc with External Capacitor)**
| REFS1 | REFS0 | Configuration |
|-------|-------|----------------|
| 0     | 1     | AVcc as reference with external cap on AREF |

- Convenient default option
- Reference voltage equals system Vcc
- Requires capacitor (typically 100nF) on AREF pin

```c
// Select AVcc as reference
bitClear(ADMUX, REFS1);
bitSet(ADMUX, REFS0); 
```

> [!NOTE]
> Accuracy depends on Vcc stability. Avoid using this mode if Vcc fluctuates due to power supply noise or load changes.

---

### **3. Internal 1.1V Reference**
| REFS1 | REFS0 | Configuration |
|-------|-------|----------------|
| 1     | 1     | Internal 1.1V reference voltage |

- Useful for low-voltage sensors or battery monitoring
- Independent of external Vcc
- Requires calibration for precise measurement

```c
 // Select internal 1.1V reference
bitSet(ADMUX, REFS1);
bitSet(ADMUX, REFS0);
```


> [!TIP]
> Measure actual internal reference using known voltage divider and calibrate in software if needed.


## **Best Practices**

- Always place a capacitor (100nF) between AREF and GND for AVcc or external reference.
- Avoid switching reference sources during active conversion.
- Use internal reference for consistent results in battery-powered systems.
- For external reference, ensure voltage is within ADC input range and stable.

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
