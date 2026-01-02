# CLIP Display: Automating A Climate Change Showcase

This embedded systems project entails automatic control over a display showcase. This display consists of a model Empire State Building encased in a PDLC Film Glass Chamber. Atop the display is rows of white and orange LED lights. The goal of the control system is to cross-fade the white and orange LED strips whilst simultaneously increasing the opacity of the film. The increasing opacity acts as a visual representation of pollution surrounding the Empire State Building, while LEDs are used for dramatic effect. This display is used to represent CLIP’s goals at various climate conventions. Below explains the process of designing this control system. **Key Tools: Signal Processing, MOSFET, PWM, Arduino**

<h2> PDLC FILM & Signal Processing </h2>
This smart film has the ability to switch between transparent and opaque states with an electrical current. Controlling the current adjusts the degree of crystal alignment, thereby increasing or decreasing the opacity. PDLC Film uses an AC current which cannot be supplied by a microcontroller. Typically, a voltage driver is used to provide current, manually controlled by a rotary encoder. I used the digital pins of an Arduino to emulate the signal otherwise provided by the rotary encoder. 

Rotary encoders convert the angular position or motion of a shaft into a digital or analog signal. A rotary encoder sends two square waves signals to a given driver. When rotated by one step, the two pins will connect and disconnect successively, resulting in a phase shift of 90 degrees. 
(credit: 
<a href="https://www.youtube.com/watch?v=v4BbSzJ-hz4" target="_blank">How To Mechatronics</a>)

<img width="1946" height="810" alt="image" src="https://github.com/user-attachments/assets/5db21d06-2691-4106-ab4b-0baaaa074d87" />



The **rotary_encoder_EM** code emulates that using two digital pins and changing their states in a similar fashion. Below is the output signal as represented in the Arduino Serial Plotter:
<img width="1534" height="707" alt="image" src="https://github.com/user-attachments/assets/5d6c89ba-1935-4ae8-8c3b-e68e4a12732f" />


An Arduino with this code can replace the position of a rotary encoder, using two digital pins as the two OUT signals. The switch pin does not have to be connected. Delays and increment counts can be adjusted for user needs. Attached below is a video of the PDLC Film being controlled by our emulated rotary encoder.

https://github.com/user-attachments/assets/639e24a6-889c-4259-ac94-159d52258094

<h2> LED Control: MOSFET & PWM Dimming </h2>

This part of the control system entails cross-fading orange and white LED strips. Because of the required 12V input voltage, controlled dimming has to be done over MOSFETs. Dimming is achieved using Pulse Width Modulation (PWM), the process of rapidly switches LEDs on and off at a high frequency. A lower duty cycle (ie. 25%) indicates that the LED will be turned on for less time. The high frequency causes the LED to appear as dimmed. An NMOS is used instead of a PMOS because of its higher switching speed, enabling the Arduino's PWM signal to work with the LED over the mosfet. The circuit is shown below: 


<img width="960" height="540" alt="image (3)" src="https://github.com/user-attachments/assets/c909a65b-9b74-4992-874f-0aad23ab3f56" />
*An important note: because the two PWM signals must be in sync, it is important to use PWM digital pins that are assigned to the same clock. Doing otherwise may result in a pulsing/flickering effect. I used pins 3 and 11 as both rely on Timer 2 (internal hardware component) to generate their PWM signals.


Gamma correction is applied in the **light_control** code because while light scales linearly in terms of photon release, eyes perceive it logarithmically. Eyes are incredibly sensitive to changes in low light but much less sensitive to changes in bright light. Attached is a video of what the lights look like with the cross-fading. 

https://github.com/user-attachments/assets/93ae3717-6dae-49f4-912f-ec8ee3ac6f49





