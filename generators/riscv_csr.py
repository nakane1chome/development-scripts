csr_width={
    "mxlen" : 32,
    "sxlen" : 32,
    "uxlen" : 32,
}

def csr_bit_to_int(bit):
    if isinstance(bit, int):
        return bit
    if isinstance(bit, str):
        # quick and diry hack
        return eval(bit, {}, csr_width)

def csr_bit_width(field_data):
    if len(field_data["bits"])==1 :
        return 1
    else :
        msb = csr_bit_to_int(field_data["bits"][0])
        lsb = csr_bit_to_int(field_data["bits"][1])
        return (msb - lsb) + 1

def csr_bit_offset(field_data):
    return csr_bit_to_int(field_data["bits"][-1])
