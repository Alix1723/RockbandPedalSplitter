# RockbandPedalSplitter
A simple arduino/pi2040 based solution to use 2 switch-style pedals as one pedal, for Rock Band drum kit controllers.

![image](https://github.com/Alix1723/RockbandPedalSplitter/assets/3638723/156c9f36-3b1a-43e5-8c31-2e5f678f0f45)

![image](https://github.com/Alix1723/RockbandPedalSplitter/assets/3638723/d54c73e1-95ce-4959-ab15-c8731dc50b03)

I bought a RB Portable Drum kit, only to find it only has one pedal input and doesn't support two pedals like later official RB controllers. And all RB-style pedals are simple on/off switches, if you just connect a standard splitter jack to each of them, they'll 'overlap' and you'll inevitably miss notes when you have one pedal held down slightly too long (especially if you play heel-down).

So this mini-project is here to:
1. Take two (or more?) simple on/off switch style pedals
2. When any of the pedals is pressed, output a 'pressed' signal to the RB controller
3. Release that signal within a small time-frame (15ms default)
4. Allow the other pedal(s) to send a press even if you're already holding one.
5. Play double kick charts!

So far I have successfully tested this with:

**CONTROLLERS**
RB Portable Kit

**PEDALS**
RB Portable Kit Stock Pedal
Alesis ASP-1 Mk1 Sustain Pedal
Alesis RealHat Pedal (DM10/Nitro/etc)

**TODO**
Polish the .ino
Upload 3d print files
Upload wiring diagram
Instructions/real README things
