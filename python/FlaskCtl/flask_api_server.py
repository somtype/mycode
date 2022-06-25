"""
File: chapter03/flask_api_server.py

A HTTP RESTFul API server to control an LED built using Flask-RESTful.

Dependencies:
  pip3 install gpiozero pigpio flask-restful

Built and tested with Python 3.7 on Raspberry Pi 4 Model B
"""
import logging
from flask import Flask, request, render_template  # (1)
from flask_restful import Resource, Api, reqparse, inputs  # (2)
from gpiozero import Motor, Device  # (3)
from gpiozero.pins.pigpio import PiGPIOFactory

# Initialize Logging
logging.basicConfig(level=logging.WARNING)  # Global logging configuration
logger = logging.getLogger('main')  # Logger for this module
logger.setLevel(logging.INFO)  # Debugging for this file.

# Initialize GPIOZero
Device.pin_factory = PiGPIOFactory()  # set GPIOZero to use PiGPIO by default

# Flask & Flask-RESTful instance variables
app = Flask(__name__)  # Core Flask app.                                              # (4)
api = Api(app)  # Flask-RESTful extension wrapper                                     # (5)

# Global variables
motor_an = 17
motor_ap = 27
motor = None
state = {  # (6)
    'level': 10  # % brightless of LED.
}

"""
GPIO Related Functions
"""


def init_led():
    """Create and initialise an PWMLED Object"""
    global motor
    motor = Motor(motor_ap, motor_ap)
    motor.forward(state['level']/100) # (7)


"""
Flask & Flask-Restful Related Functions
"""


# @app.route applies to the core Flask instance (app).
# Here we are serving a simple web page.
@app.route('/', methods=['GET'])  # (8)
def index():
    """Make sure inde.html is in the templates folder
    relative to this Python file."""
    args = {
        'an': motor_an,
        'ap': motor_ap
    }
    return render_template('index_api_client.html', **args)  # (9)


# Flask-restful resource definitions.
# A 'resource' is modeled as a Python Class.
class MotorControl(Resource):  # (10)

    def __init__(self):
        self.args_parser = reqparse.RequestParser()  # (11)

        self.args_parser.add_argument(
            name='level',  # Name of arguement
            required=True,  # Mandatory arguement
            type=inputs.int_range(0, 100),  # Allowed range 0..100                   # (12)
            help='Set LED brightness level {error_msg}',
            default=None)

    def get(self):
        """ Handles HTTP GET requests to return current LED state."""
        return state  # (13)

    def post(self):
        """Handles HTTP POST requests to set LED brightness level."""
        global state  # (14)

        args = self.args_parser.parse_args()  # (15)

        # Set PWM duty cycle to adjust brightness level.
        state['level'] = args.level  # (16)
        motor.forward(state['level'] / 100)  # (17)
        logger.info("Motor speed is " + str(state['level'] + '%'))

        return state  # (18)


# Initialise Module.
init_led()
# Register Flask-RESTful resource and mount to server end point /led
api.add_resource(MotorControl, '/led')  # (19)

if __name__ == '__main__':
    # If you have debug=True and receive the error "OSError: [Errno 8] Exec format error", then:
    # remove the execuition bit on this file from a Terminal, ie:
    # chmod -x flask_api_server.py
    #
    # Flask GitHub Issue: https://github.com/pallets/flask/issues/3189

    app.run(host="0.0.0.0", debug=True)  # (20)
