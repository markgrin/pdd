data = open('./1', 'rb').read()
print(data)
output = open('./1.patched', 'wb')
data = bytearray(data)

data[0x12c6] = 0x48
data[0x12c7] = 0x89
data[0x12c8] = 0xcf

output.write(data)

