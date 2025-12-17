# CLIP Display: Automating A Climate Change Showcase

This embedded systems project entails automatic control over a display showcase. This serves to inspire similar projects as well as provide a deeper understanding of the requirements to create such a system.
Key Tools: Signal Processing, MOSFET, PWM, Arduino

This specific display consists of a model Empire State Building encased in a PDLC Film Glass Chamber. Atop the display is rows of white and orange LED lights. The goal of the control system is to cross-fade the white and orange LED strips whilst simeltaneously increasing the opacity of the film. The increasing opacity acts as a visual representation of pollution surrounding the Empire State Building, while LEDs are used for dramatic effect. Below explains the process of designing this control system.

<h2> PDLC FILM & Signal Processing </h2>
This smart film has the ability to switch between transparent and opaque states with an electrical current. By controlling the voltage, you can adjust the degree of crystal alignment. Notably, PDLC Flm uses a high AC current which cannot be supplied by a microcontroller. Typically, a voltage driver is used to provide AC current which can be manually controlled using a rotary encoder. In place of this rotary encoder, we will use the digital pins of an Arduino to emulate the signal typically provided. 

The code is a working emulator. Rotary encoders convert the angular position or motion of a shaft into a digital or analog signal, but require manual control. Certain heavy duty applications such as this one require rotary encoders over other alternatives like potentiometers, making a different, automatic control system necessary. 

A rotary encoder sends two square waves as signals to a given driver. When rotated by one step, the two pins will connect and disconnect successively, resulting in a phase shift of 90 degrees. The following image depicts what this signal looks like. 
(credit: 
<a href="https://www.youtube.com/watch?v=v4BbSzJ-hz4" target="_blank">How To Mechatronics</a>)

<img width="1946" height="810" alt="image" src="https://github.com/user-attachments/assets/5db21d06-2691-4106-ab4b-0baaaa074d87" />



This code emulates that using two digital pins and changing their states in a similar fashion. Below is the output signal as represented in the Arduino Serial Plotter:
<img width="1534" height="707" alt="image" src="https://github.com/user-attachments/assets/5d6c89ba-1935-4ae8-8c3b-e68e4a12732f" />


An Arduino with this code can replace the position of a rotary encoder, using two digital pins as the two OUT signals. The switch pin does not have to be connected. Delays and increment counts can be adjusted for user needs. 
<img width="960" height="540" alt="image (1)" src="https://github.com/user-attachments/assets/f2279256-f81b-4330-ac79-92ab920a31a9" />


Attached below is a video of the PDLC Film being controlled by our emulated rotary encoder.

https://github.com/user-attachments/assets/639e24a6-889c-4259-ac94-159d52258094

<h2> LED Control: MOSFET & PWM Dimming </h2>

This part of the control system entails cross-fading orange and white LED strips. Because of the required 12V input voltage, controlled dimming has to be done over MOSFETs. An example circuit is shown below:

![image (1)](https://github.com/user-attachments/assets/96d03b23-0db9-43dd-92f4-10b768418a0c)





