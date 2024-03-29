# 🎹(Guitar)-tuner
![image](https://github.com/vacu9708/Guitar-tuner/assets/67142421/af334336-35db-4c46-88f3-4deb13d77ba0)

### 📺Video : https://youtu.be/h5mfWexaDTg
---
## How it works, how to use
* First, you have to set the target note by adjusting the ***adjustable resistance***.
* The target note is shown on the ***7-segments***.
* You can hear the target note by pressing ***Switch1*** and the sound is turned off by pressing it again. You can't tune while hearing it)
* ***Switch0*** starts tuning
* When the ***LED*** on the far right is on, it's in tuning mode.
* If the measured frequency is higher than the target frequency, the ***LED*** on the right is turned on. When it's opposite, the ***LED*** on the left is turned on. When the sound of the instrument and the target sound are almost the same, both ***LEDs*** are turned on which means the tuning has been done well.

## ⚒️Things used
* **Arduino**
* **LEDs** to show the direction to tune, that is, whether to raise or lower the pitch
* **Switches** to change the mode of tuner
* **Adjustable resistance** to change the target note
* **Piezoelectric element** to play the target note to help tuning
* **Bluetooth** to receive the frequency data from a phone
* **7-segments** to show the current target note
* **Frequency measurer.aia (app inventor extension)**

## Difficulties I went through making it
As far as I knew, the piezoelectric element was a bi-directional element where electricity flowing through it makes sound and pressure applied to it makes electricity. But making electricity with sound did not work in this embedded system. I did not know the reason. So I changed the plan to measuring the frequency from a phone and sending it to the tuner via Bluetooth.<br>
Another problem : I did not know arduino(atmega128) could only receive 1 byte at a time. I searched for the problem and found out a way of merging each 1 byte with atoi() and managed to solve it.

## My opinion
I tried to implement measuring the frequency which is the most important part of a guitar tuner on my own. But I realized it was mathematically too complicated, so I used a library for it at first. I would like to write code for measuring the frequency without using the library soon.

---
## February 25, 2022
### [Fundamental working process of measuring frequencies](https://github.com/vacu9708/Signal-processing/tree/main/Fourier%20transform)

## May 2, 2023 Refactoring points
I found out this old code has a bad maintainability.<br>
A better file structure would be:<br>
>Main.ino<br>
>Switch.ino(sets the switch variables to give the modules that need them(Notifier.ino, LED_controller.ino)<br>
>frequency_setting<br>
>ㅡFrequency_setter.ino(imports VR_reader to set the frequency and control piezo buzzer and 7 segments)<br>
>ㅡVR_reader.ino(reads VR value and sets target_freq and freq_name)<br>
>frequency_handling<br>
>ㅡLED_controller.ino(imports Frequency_measurer.ino and controls LEDs according to the measured frequency)<br>
>ㅡFrequency_measurer.ino<br>
