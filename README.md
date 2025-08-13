# ADC (Analog to Digital Converter)
The ADC (Analog-to-Digital Converter) in the ATMEGA328 is used to convert analog signals (voltages) into digital data that can be processed by the microcontroller. The ADC is typically used in applications where the input signal is an analog value, such as reading sensors, measuring voltages, etc. The ATMEGA328 features a 10-bit ADC, which provides a resolution of 1024 distinct values for any input voltage between 0 and the reference voltage.

The ADC on the ATMEGA328 is capable of reading multiple channels (pins) and can be configured for various reference voltages. It is essential to understand the registers controlling the ADC and how to utilize them to get accurate readings.

<table>
  <tr>
  <td valign="top">
  
  > [!TIP]  
  > If you're looking to better understand how to navigate and use my GitHub repositories — including exploring their structure, downloading or cloning projects, submitting issues, and asking questions,  
  > everything you need is clearly explained in this video:  
  > [aKaReZa 95 - Programming, Git - PART B](https://youtu.be/zYiUItVFRqQ)  
  > Make sure to check it out!
  
  </td>
    <td width="360" valign="middle" style="padding: 0;">
      <a href="https://youtu.be/zYiUItVFRqQ">
       <img src="https://img.youtube.com/vi/zYiUItVFRqQ/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 95 - Programming, Git - PART B Thumbnail"/>
      </a>
    </td>

  </td>
  </tr>
  <tr>
  <td colspan="2">

  > [!CAUTION]
  > It is absolutely critical that you carefully read every single word of this document, line by line, to ensure you don't miss any details. Nothing can be overlooked.
      
  </td>
  </tr>  
</table>

# 🔗 Resources
  Here you'll find a collection of useful links and videos related to the topic of AVR microcontrollers.  


## **ADC Overview**

```
ADC Overview
├── Documentation
│   ├─ [ADC Channels]
│   │   ├─ Inputs — ADC0 to ADC7
│   │   ├─ Multiplexer — ADMUX (MUX bits)
│   │   └─ Differential channels & gain
│   │
│   ├─ [ADC Voltage Reference]
│   │   ├─ Registers — ADMUX (REFS bits)
│   │   ├─ Options — AREF pin, AVcc, Internal 1.1V reference
│   │   └─ Considerations — Noise, stability
│   │
│   ├─ [ADC Prescaler]
│   │   ├─ Registers — ADCSRA (ADPS bits)
│   │   ├─ Division factors — 2, 4, 8, 16, 32, 64, 128
│   │   └─ Impact — Sampling rate and accuracy
│   │
│   ├─ [ADC Triggering]
│   │   ├─ Registers — ADCSRA (ADATE), ADCSRB
│   │   ├─ Modes — Free-running, Timer Compare Match, External Interrupt
│   │   └─ Use cases — Periodic sampling
│   │
│   ├─ [ADC Interrupts]
│   │   ├─ Registers — ADCSRA (ADIE), ADIF
│   │   ├─ Operation — ISR trigger when conversion complete
│   │   └─ Clearing flags — Write 1 to ADIF
│   │
│   └─ [ADC Conversion Calculation]
│       └─ Topics — Voltage to ADC Value, ADC Value to Voltage
│
├── [API_Reference]
│    ├─ File — adc.h / adc.c
│    ├─ Functions — Init, internalTemp, Read
│    └─ Purpose — High-level ADC peripheral interface for reading analog inputs and internal temperature sensor
|
└── Registers
    ├─ [ADMUX]   — ADC Multiplexer Selection Register — Channel & reference selection
    ├─ [ADCSRA]  — ADC Control and Status Register A — Enable, start, prescaler, interrupt
    ├─ [ADCSRB]  — ADC Control and Status Register B — Auto trigger sources
    ├─ [ADCL]    — ADC Data Register Low byte
    ├─ [ADCH]    — ADC Data Register High byte
    └─ [DIDR0]   — Digital Input Disable Register 0 — Disable digital buffers on ADC pins
```

- [ADC Channels](./ADC_Channels.md)
  ---
  Describes all ADC input channels, multiplexer usage, and differential measurement options.

- [ADC Voltage Reference](./ADC_VoltageRef.md)
  ---
  Details the available voltage reference sources (AREF, AVcc, Internal 1.1V) and their trade-offs.

- [ADC Prescaler](./ADC_Prescaler.md)
  ---
  Explains how to set the ADC clock using prescaler bits in ADCSRA for optimal accuracy.

- [ADC Triggering](./ADC_Triggering.md)
  ---
  Shows how to use free-running and auto-triggered ADC conversions.

- [ADC Interrupts](./ADC_Interrupts.md)
  ---
  Describes enabling ADC interrupts and writing ISRs for conversion completion.

- [ADC Conversion](./ADC_Calc.md)
  ---
  This section explains how to convert between analog voltages and digital ADC values using the ATmega328's 10-bit ADC. It covers two key operations:
  - **Voltage to ADC Value**:  
    Learn how the ADC translates an input voltage into a 10-bit digital value (0–1023), based on the reference voltage.
  - **ADC Value to Voltage**:  
    Understand how to convert the digital ADC result back into the corresponding analog voltage using a simple formula.

- [API Reference](./API_Reference.md)
  ---
  This section provides detailed descriptions of the functions in the `adc.h` and `adc.c` files for handling ADC operations on the ATmega328 microcontroller. Each function is designed to manage analog-to-digital conversions, read data from specific ADC channels, and interact with the internal temperature sensor. These APIs simplify ADC initialization and data acquisition, making it easier to implement analog input handling in your projects.

## **Videos Overview**
```plaintext
AVR, Analog
  └── [aKaReZa 77 - AVR, Analog - ADC]
       ├─ ADC Basics — Block diagram, control & data registers.
       ├─ Functions — Configuration + raw value reading.
       ├─ Voltage — Measurement via ADC.
       ├─ Channels — Multi-channel measurement.
       ├─ Temperature — External + internal sensor usage.
       └─ Accuracy — Noise canceller feature explained.
```

<table style="border-collapse: collapse;">
  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/SJJGwX5tNis">aKaReZa 77 – AVR, Analog - ADC</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Learn about the features of the Analog-to-Digital Converter (ADC) in AVR microcontrollers, including block diagrams, control and data registers, voltage measurement, multi-channel measurement, analog temperature sensor connection, internal temperature sensor usage, and noise canceler capabilities.
      </p>
    </td>
    <td width="360" valign="middle" style="padding: 0;">
      <a href="https://youtu.be/SJJGwX5tNis">
        <img src="https://img.youtube.com/vi/SJJGwX5tNis/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 77 – AVR, Analog - ADC Thumbnail"/>
      </a>
    </td>
  </tr>
</table>
  
> [!TIP]
> The resources are detailed in the sections below.  
> To access any of them, simply click on the corresponding blue link.

- [AVR Microntroller](https://github.com/aKaReZa75/AVR)
  ---  
    This repository contains comprehensive resources for AVR microcontrollers, including hardware schematics, software libraries, and educational projects.

# 💻 How to Use Git and GitHub
To access the repository files and save them on your computer, there are two methods available:
1. **Using Git Bash and Cloning the Repository**
   - This method is more suitable for advanced users and those familiar with command-line tools.
   - By using this method, you can easily receive updates for the repository.

2. **Downloading the Repository as a ZIP file**
   - This method is simpler and suitable for users who are not comfortable with command-line tools.
   - Note that with this method, you will not automatically receive updates for the repository and will need to manually download any new updates.

## Clone using the URL.
First, open **Git Bash** :
-  Open the folder in **File Explorer** where you want the library to be stored.
-  **Right-click** inside the folder and select the option **"Open Git Bash here"** to open **Git Bash** in that directory.

![open Git Bash](Images/Step0.png)

> [!NOTE] 
> If you do not see the "Open Git Bash here" option, it means that Git is not installed on your system.  
> You can download and install Git from [this link](https://git-scm.com/downloads).  
> For a tutorial on how to install and use Git, check out [this video](https://youtu.be/BsykgHpmUt8).
  
-  Once **Git Bash** is open, run the following command to clone the repository:

 ```bash
git clone https://github.com/aKaReZa75/AVR_ADC.git
```
- You can copy the above command by either:
- Clicking on the **Copy** button on the right of the command.
- Or select the command text manually and press **Ctrl + C** to copy.
- To paste the command into your **Git Bash** terminal, use **Shift + Insert**.

![Clone the Repository](Images/Step1.png)

- Then, press Enter to start the cloning operation and wait for the success message to appear.

![Open the Library File](Images/Step2.png)

> [!IMPORTANT]
> Please keep in mind that the numbers displayed in the image might vary when you perform the same actions.  
> This is because repositories are continuously being updated and expanded. Nevertheless, the overall process remains unchanged.

> [!NOTE]
> Advantage of Cloning the Repository:  
> - **Receiving Updates:** By cloning the repository, you can easily and automatically receive new updates.  
> - **Version Control:** Using Git allows you to track changes and revert to previous versions.  
> - **Team Collaboration:** If you are working on a project with a team, you can easily sync changes from team members and collaborate more efficiently.  

## Download Zip
If you prefer not to use Git Bash or the command line, you can download the repository directly from GitHub as a ZIP file.  
Follow these steps:  
1. Navigate to the GitHub repository page and Locate the Code button:
   - On the main page of the repository, you will see a green Code button near the top right corner.

2. Download the repository:
   - Click the Code button to open a dropdown menu.
   - Select Download ZIP from the menu.

  ![Download Zip](Images/Step7.png)  

3. Save the ZIP file:
   - Choose a location on your computer to save the ZIP file and click Save.

4. Extract the ZIP file:
   - Navigate to the folder where you saved the ZIP file.
   - Right-click on the ZIP file and select Extract All... (Windows) or use your preferred extraction tool.
   - Choose a destination folder and extract the contents.

5. Access the repository:
   - Once extracted, you can access the repository files in the destination folder.

> [!IMPORTANT]
> - No Updates: Keep in mind that downloading the repository as a ZIP file does not allow you to receive updates.    
>   If the repository is updated, you will need to download it again manually.  
> - Ease of Use: This method is simpler and suitable for users who are not comfortable with Git or command-line tools.

# 📝 How to Ask Questions
If you have any questions or issues, you can raise them through the **"Issues"** section of this repository. Here's how you can do it:  

1. Navigate to the **"Issues"** tab at the top of the repository page.  

  ![Issues](Images/Step3.png)

2. Click on the **"New Issue"** button.  
   
  ![New Issue](Images/Step4.png)

3. In the **Title** field, write a short summary of your issue or question.  

4. In the "Description" field, detail your question or issue as thoroughly as possible. You can use text formatting, attach files, and assign the issue to someone if needed. You can also use text formatting (like bullet points or code snippets) for better readability.  

5. Optionally, you can add **labels**, **type**, **projects**, or **milestones** to your issue for better categorization.  

6. Click on the **"Submit new issue"** button to post your question or issue.
   
  ![Submeet New Issue](Images/Step5.png)

I will review and respond to your issue as soon as possible. Your participation helps improve the repository for everyone!  

> [!TIP]
> - Before creating a new issue, please check the **"Closed"** section to see if your question has already been answered.  
>   ![Closed section](Images/Step6.png)  
> - Write your question clearly and respectfully to ensure a faster and better response.  
> - While the examples provided above are in English, feel free to ask your questions in **Persian (فارسی)** as well.  
> - There is no difference in how they will be handled!  

> [!NOTE]
> Pages and interfaces may change over time, but the steps to create an issue generally remain the same.

# 🤝 Contributing to the Repository
To contribute to this repository, please follow these steps:
1. **Fork the Repository**  
2. **Clone the Forked Repository**  
3. **Create a New Branch**  
4. **Make Your Changes**  
5. **Commit Your Changes**  
6. **Push Your Changes to Your Forked Repository**  
7. **Submit a Pull Request (PR)**  

> [!NOTE]
> Please ensure your pull request includes a clear description of the changes you’ve made.
> Once submitted, I will review your contribution and provide feedback if necessary.

# 🌟 Support Me
If you found this repository useful:
- Subscribe to my [YouTube Channel](https://www.youtube.com/@aKaReZa75).
- Share this repository with others.
- Give this repository and my other repositories a star.
- Follow my [GitHub account](https://github.com/aKaReZa75).

# 📜 License
This project is licensed under the GPL-3.0 License. This license grants you the freedom to use, modify, and distribute the project as long as you:
- Credit the original authors: Give proper attribution to the original creators.
- Disclose source code: If you distribute a modified version, you must make the source code available under the same GPL license.
- Maintain the same license: When you distribute derivative works, they must be licensed under the GPL-3.0 too.
- Feel free to use it in your projects, but make sure to comply with the terms of this license.
  
# ✉️ Contact Me
Feel free to reach out to me through any of the following platforms:
- 📧 [Email: aKaReZa75@gmail.com](mailto:aKaReZa75@gmail.com)
- 🎥 [YouTube: @aKaReZa75](https://www.youtube.com/@aKaReZa75)
- 💼 [LinkedIn: @akareza75](https://www.linkedin.com/in/akareza75)
