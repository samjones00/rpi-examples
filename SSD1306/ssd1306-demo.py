# Install with:
# sudo apt-get install -y python3-dev python3-pip libfreetype6-dev libjpeg-dev build-essential
# sudo -H pip3 install --upgrade luma.oled
# 
# Run with:
# 

from luma.core.interface.serial import i2c
from luma.core.render import canvas
from luma.oled.device import ssd1306, ssd1325, ssd1331, sh1106
import time
from PIL import ImageFont, ImageDraw

serial = i2c(port=1, address=0x3C)
device = ssd1306(serial, rotate=0)

# Box and text rendered in portrait mode
with canvas(device) as draw:
    draw.rectangle(device.bounding_box, outline="white", fill="black")
    font = ImageFont.load_default()
    draw.text((10, 5), "Example", fill="white", font=font)
    draw.text((15, 25), "Hello", fill="white", font=font)
    font = ImageFont.truetype('./FreePixel.ttf', 20)
    draw.text((15, 35), "World", fill="white", font=font)
input("Press Enter to exit...")
