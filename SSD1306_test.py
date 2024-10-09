#trabajo realizado junto a Yonhatan

# -- coding: utf-8 --
from luma.core.interface.serial import i2c
from luma.oled.device import ssd1306
from PIL import Image, ImageDraw, ImageFont

# Configuración de la pantalla OLED
serial = i2c(port=1, address=0x3C)
device = ssd1306(serial)

# Crear una imagen en blanco
image = Image.new('1', (device.width, device.height))
draw = ImageDraw.Draw(image)

# Definir una fuente
try:
    font = ImageFont.truetype('/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf', 16)
except IOError:
    font = ImageFont.load_default()

# Escribir el texto "Hola" en la imagen
text = "Hola"

# Usar textbbox para obtener las dimensiones del texto
bbox = draw.textbbox((0, 0), text, font=font)
text_width = bbox[2] - bbox[0]
text_height = bbox[3] - bbox[1]

# Calcular la posición para centrar el texto
width, height = device.width, device.height
text_x = (width - text_width) / 2
text_y = (height - text_height) / 2

# Dibujar el texto en la imagen
draw.text((text_x, text_y), text, font=font, fill=255)


# Mostrar la imagen en la pantalla OLED
device.display(image)
