# 🎹(Guitar)-tuner

<img src="https://user-images.githubusercontent.com/67142421/148652185-68497dea-50c6-4090-aba9-56ea0dacf683.jpg" width="400" height="500">

### 📺Video(korean without subtitles) : https://youtu.be/h5mfWexaDTg
---
I made a tuner that can tune musical instruments, even voice not only guitar, in order to get used to the basic things of embedded system development.

## How it works, how to use
* First, you have to set the target note by adjusting the ***adjustable resistance***.
* The target note is shown on the ***7-segments***.
* You can hear the target note by pressing ***Switch1*** and the sound is turned off by pressing it again. You can't tune while hearing it)
* ***Switch0*** starts tuning
* When the ***LED*** on the far right is on, it's in tuning mode.
* If the frequency of the instrument measured is higher than the target frequency(that is, when the sound of the instrument is higher than the target sound) the ***LED*** on the right is turned on. When it's opposite, the ***LED*** on the left is turned on. When the sound of the instrument and the target sound are almost the same, both ***LEDs*** are turned on which means the tuning has been done well.

## ⚒️Devices used
* **Arduino**
* **LEDs** to show the direction to tune, that is, whether to raise or lower the pitch
* **Switches** to change the mode of tuner
* **Adjustable resistance** to change the target note
* **Piezoelectric element** to play the target note to help tuning
* **Bluetooth** to receive the frequency data from a phone
* **7-segments** to show the current target note

## Difficulties I went through making it
As far as I knew, the piezoelectric element was a bi-directional element where sound is made when electricity flows through it and electricity is also made by pressure including the pressure by sound. But the effect of the piezoelectric element of making electricity by sound, which is one of the two effects, didn't work. I didn't know the reason. So I changed the plan to measuring the frequency from a phone and sending it to the tuner by Bluetooth.
The most difficult problem that took much time to solve was that arduino(atmega128) could only receive 1 byte at a time. I searched for it and found out a way of merging each 1 byte with atoi() function and managed to solve it.

## My opinion
Measuring frequency with *fourier transform*, which is the most important part of a tuner, was implemented by a library in this work.
I'd like to make a tuner by programming the code for measuring the frequency on my own soon without a library like this one.

