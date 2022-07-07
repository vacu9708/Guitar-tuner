# 🎹(Guitar)-tuner

<img src="https://user-images.githubusercontent.com/67142421/148652185-68497dea-50c6-4090-aba9-56ea0dacf683.jpg" width="400" height="500">

### 📺Video : https://youtu.be/h5mfWexaDTg
---
## How it works, how to use
* First, you have to set the target note by adjusting the ***adjustable resistance***.
* The target note is shown on the ***7-segments***.
* You can hear the target note by pressing ***Switch1*** and the sound is turned off by pressing it again. You can't tune while hearing it)
* ***Switch0*** starts tuning
* When the ***LED*** on the far right is on, it's in tuning mode.
* If the frequency of the instrument measured is higher than the target frequency(that is, when the sound of the instrument is higher than the target sound) the ***LED*** on the right is turned on. When it's opposite, the ***LED*** on the left is turned on. When the sound of the instrument and the target sound are almost the same, both ***LEDs*** are turned on which means the tuning has been done well.

## ⚒️Things used
* **Arduino**
* **LEDs** to show the direction to tune, that is, whether to raise or lower the pitch
* **Switches** to change the mode of tuner
* **Adjustable resistance** to change the target note
* **Piezoelectric element** to play the target note to help tuning
* **Bluetooth** to receive the frequency data from a phone
* **7-segments** to show the current target note
* **Frequency measurer made with MIT app inventor**

## Difficulties I went through making it
As far as I knew, the piezoelectric element was a bi-directional element where electricity flowing through it makes sound and pressure applied to it makes electricity. But making electricity with sound did not work in this embedded system. I did not know the reason. So I changed the plan to measuring the frequency from a phone and sending it to the tuner via Bluetooth.<br>
Another problem : I did not know arduino(atmega128) could only receive 1 byte at a time. I searched for the problem and found out a way of merging each 1 byte with atoi() and managed to solve it.

## My opinion
I tried to implement measuring the frequency, which is the most important part of a tuner. But I realized it was mathematically too complicated, so I used a library for it at first. I would like to write code for measuring the frequency on my own without using the library soon.

---
## February 25, 2022
[Fundamental working process of measuring frequencies](https://github.com/vacu9708/Signal-processing/tree/main/Fourier%20transform)
