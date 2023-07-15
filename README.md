# Midi-Clock-to-Tap-Tempo
Midi sync virtually any effect pedal (or other device) that has tap tempo button or footswitch.
A standard 5v midi "In" circuit is connected to the arduino's serial port Rx. The Arduino output is connected indirectly (optoisolated) to the pedals tap tempo switch.  When the arduino receives midi clock commands,  it it calculates the tempo based on the midi clock ticks and send 3 pulses to the 4n32, which connects and quickly disconnects the pins on the tap tampo switch three time on the quarter note, simulating the standard "3-tap" tempo entry used by most devices.    Afterward, the arduino will only send "taps", if it detects a change in the received midi tempo. 


This layout is for the 5v Arduino ProMicro, 6n138 for the midi in circuit (midi in DIN jack or 3.5 trs to TP8) and 4n32 to provide isolated control over the pedal's tap tempo button pins.  (TP10 -2 pin header wired to tap tempo button)   Additionally, 1x 1n4148 diode, 3x 220ohm and 1x 3300 ohm resistors are used.

The 3 pin header, TP9,is power: GND, VCC(5v), RAW (9v or less! ).  For most uses, connect GND and RAW to the pedal's 9v DC jack and leave 5v disconnected.  


(print at 50%)
![Midi Clock to Tap Tempo](https://github.com/miotislucifugis/Midi-Clock-to-Tap-Tempo/assets/20709580/53b2932d-3ac5-437a-839e-700fc7d83638)
![Midi Clock to Tap Tempo- parts layout](https://github.com/miotislucifugis/Midi-Clock-to-Tap-Tempo/assets/20709580/1b1a45f8-34a6-4116-afd5-918c519aa803)

![Midi Clock to Tap Tempo- parts layout_no traces](https://github.com/miotislucifugis/Midi-Clock-to-Tap-Tempo/assets/20709580/962916bf-6311-47bf-ab63-f7a39d44b39e)

