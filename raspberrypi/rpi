from gpiozero import PWMLED, Button
from signal import pause
red = PWMLED(2)
green = PWMLED(3)
blue = PWMLED(4)
button = Button(17)
def my_pulse():
    red.pulse(n = 1)
    green.pulse(n = 1)
    blue.pulse(n = 1)
button.when_pressed = my_pulse
