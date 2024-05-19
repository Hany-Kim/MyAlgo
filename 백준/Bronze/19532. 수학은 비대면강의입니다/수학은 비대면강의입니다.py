str = input()
inputs = str.split(sep=' ')

a = int(inputs[0])
b = int(inputs[1])
c = int(inputs[2])
d = int(inputs[3])
e = int(inputs[4])
f = int(inputs[5])

for x in range(-999, 1000):
    for y in range(-999, 1000):
        if ((a*x)+(b*y)==c) and ((d*x)+(e*y)==f):
            print(f'{x} {y}')