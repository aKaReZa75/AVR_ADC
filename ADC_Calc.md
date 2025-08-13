## **Converting Voltage to ADC Value:**

When we apply an analog voltage to the ADC input, the ADC converts this voltage into a digital value. The ADC resolution (in this case, 10 bits) defines the number of discrete levels the ADC can represent. For a 10-bit ADC, the range of values is from 0 to 1023 (1024 levels). The actual value obtained by the ADC depends on the input voltage relative to the reference voltage.

### **Key Parameters for Conversion:**
1. **ADC Resolution**: **10 bits** (This means the ADC result will range from 0 to 1023, representing 1024 levels of the input voltage.)
2. **Reference Voltage**: The reference voltage used for the conversion (in this case, **AVCC** as selected earlier).
3. **Input Voltage (V_in)**: The actual voltage applied to the ADC input pin.

### **Formula for Conversion (Voltage to ADC Value):**
To convert a given input voltage \( V_{in} \) to the corresponding ADC value:

```c
// To convert the input voltage to ADC value:
ADC_value = (V_in / V_ref) * 1023
```

Where:
- `ADC_value` is the digital value obtained from the ADC conversion (ranges from 0 to 1023).
- `V_in` is the input voltage (voltage applied to the ADC input pin).
- `V_ref` is the reference voltage (e.g., AVCC, typically 5V or 3.3V).

### **Example Calculation (Voltage to ADC Value):**
```c
// Assume:
// Input voltage = 2.5V
// Reference Voltage = 5V

ADC_value = (2.5 / 5) * 1023  // Convert voltage to ADC value
ADC_value = 511.5             // So the corresponding ADC value is approximately 512
```

This means that when a **2.5V** input is applied to the ADC with a **5V reference**, the ADC value will be approximately **512** (rounding to the nearest integer).

### **Conclusion:**

- **Voltage to ADC Value**: You can convert an input voltage to an ADC value using the formula:

  ```c
  ADC_value = (V_in / V_ref) * 1023
  ```

  For example, a **2.5V** input with a **5V reference** results in an ADC value of **512**.

## **Converting ADC Value to Voltage:**

Once the ADC conversion is complete, the result is a digital value that represents the analog input voltage in a certain range based on the reference voltage. To convert the ADC value back to the actual voltage applied to the input pin, use the following method:

### **Formula for Conversion (ADC Value to Voltage):**
To convert the ADC value back to the input voltage \( V_{in} \), the formula is:

```c
// To convert the ADC value to the input voltage:
V_in = (ADC_value / 1023) * V_ref
```

Where:
- `V_in` is the input voltage (voltage applied to the ADC input pin).
- `ADC_value` is the digital value obtained from the ADC conversion (ranges from 0 to 1023).
- `V_ref` is the reference voltage (e.g., AVCC, typically 5V or 3.3V).

### **Example Calculation (ADC Value to Voltage):**
```c
// Assume:
// ADC result = 512
// Reference Voltage = 5V

V_in = (512 / 1023) * 5V   // Convert ADC value to voltage
V_in = 2.5V                // So the corresponding input voltage is 2.5V
```

This means that an ADC value of **512** corresponds to an input voltage of **2.5V** when using a **5V reference**.

### **Conclusion:**

- **ADC Value to Voltage**: You can convert the ADC value back to the input voltage using the formula:

  ```c
  V_in = (ADC_value / 1023) * V_ref
  ```

  For example, an ADC value of **512** with a **5V reference** corresponds to an input voltage of **2.5V**.

## **ADC Conversion Time**

The time it takes for an ADC conversion to complete depends on several factors, such as the ADC resolution, the ADC clock, and the prescaler setting. In the case of the ATMEGA328 microcontroller with a **16 MHz CPU clock**, a **prescaler of 128**, and a **10-bit ADC resolution**, we can calculate the time it takes for one conversion.

### **Key Parameters:**
1. **CPU Frequency**: **16 MHz** (16,000,000 Hz)
2. **ADC Prescaler**: **128** (Set using **ADPS2**, **ADPS1**, and **ADPS0** bits)
3. **ADC Resolution**: **10 bits** (This means the ADC produces a 10-bit result, which requires 1024 discrete levels)
4. **ADC Conversion Clock**: The ADC clock is derived from the CPU clock and is divided by the prescaler.

### **ADC Clock Frequency Calculation:**

The ADC clock frequency is calculated by dividing the CPU clock frequency by the prescaler:

```markdown
ADC Clock = (CPU Frequency / Prescaler) = (16 MHz / 128) = 125 kHz
```

So, the ADC is running at a frequency of **125 kHz**.

### **ADC Conversion Time:**

The ATMEGA328's ADC takes 13 ADC clock cycles to perform a **single 10-bit conversion**. This time includes the steps for sampling and conversion.

```markdown
Conversion Time = 13 ADC Clock Cycles
```

Since the ADC clock frequency is **125 kHz**, the time per ADC clock cycle is the inverse of the clock frequency:

```markdown
ADC Clock Cycle Time = 1 / 125,000 = 8 microseconds
```

Now, multiply the ADC clock cycle time by the number of clock cycles required for a conversion:

```markdown
ADC Conversion Time = 13 * 8 microseconds = 104 microseconds
```

### **Conclusion:**

With a **16 MHz CPU frequency** and an **ADC prescaler of 128**, the time it takes to complete one ADC conversion in 10-bit resolution is approximately **104 microseconds**.



### **Important Notes**

- **Reference Voltage**: The accuracy of the ADC result depends on the reference voltage. If you're using the internal 1.1V reference, be sure to account for the actual voltage value, as it may vary slightly across different microcontroller units.
  
- **Input Impedance**: The ADC requires a low-impedance source to obtain accurate readings. If your input signal has high impedance, consider using a buffer or amplifier to improve the signal quality.
  
- **Overvoltage**: Ensure that the input voltage is within the allowable range for the ADC. Voltages higher than the reference voltage can damage the microcontroller.



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
