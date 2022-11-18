from PIL import Image

img = Image.open("bean.png")
pixels = img.load()

of = open("img.bin", "wb")

print(type(pixels[0,0]))

for y in range(144):
    for x in range(255):
        of.write(bytes([pixels[x,y][1]]))
