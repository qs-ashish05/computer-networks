


print('Enter The Data (D3 D2 D1 D0): ')

D3 = int(input('Entre D3 : '))
D2 = int(input('Entre D2 : '))
D1 = int(input('Entre D1 : '))
D0 = int(input('Entre D0 : '))
data_list = [D3,D2,D1,D0]

if ( (D3 == 0 or D3 == 1) and (D2 == 0 or D2 == 1) and (D1 == 0 or D1 == 1) and (D0 == 0 or D0 == 1) ):
    print('Valid')
else:
    print('Invalid')
    exit(0)

print('====================')

print('Parity scheme used \n\t1. Even \t 2.Odd')
parity = int(input('Your choice : '))

if (parity == 0 or parity == 1):
    print('Valid')
else:
    print('Invalid')
    exit(0)

print('====================')

# Hardcoded values 
l = 4 
r = 3

# Hence parity bit is R3,R2,R0
# pos_R0 = 1
# pos_R1 = 2
# pos_R2 = 4

# data_to_transmit = [D3,D2,D1,R2,D0,R1,R0]


# Parity logic
 
def even_parity(x,y,z):
    if x == 1 and y ==1 and z == 1 :
        return 1
    if x == 1 and y ==0 and z == 0 :
        return 1
    if x == 0 and y ==1 and z == 0 :
        return 1
    if x == 0 and y ==0 and z == 1 :
        return 1
    else:
        return 0

def odd_parity(x,y,z):
    if x == 1 and y ==1 and z == 1 :
        return 0
    if x == 1 and y ==0 and z == 0 :
        return 0
    if x == 0 and y ==1 and z == 0 :
        return 0
    if x == 0 and y ==0 and z == 1 :
        return 0
    else:
        return 1

if parity == 1:
    R0 = even_parity(D0,D1,D3)
    R1 = even_parity(D0,D2,D3)
    R2 = even_parity(D1,D2,D3)

if parity == 0:
    R0 = odd_parity(D0,D1,D3)
    R1 = odd_parity(D0,D2,D3)
    R2 = odd_parity(D1,D2,D3)

hamming_bits = [R2,R1,R0]
trans_data = [D3,D2,D1,R2,D0,R1,R0]

print('Actual data is (D3 D2 D1 D0): ',data_list)
print('Hamming bits are (R2 R1 R0): ',hamming_bits)
print('Data that has to transmit (D3 D2 D1 R2 D0 R1 R0): ',trans_data)


