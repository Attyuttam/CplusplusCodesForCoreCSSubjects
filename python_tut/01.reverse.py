input_str = "Attyuttam Saha"
def FirstReverse(input_str):
    rev_list=reversed(input_str)
    out_str=""

    for letter in rev_list:
        out_str = out_str + letter
    return out_str

print (FirstReverse(input_str))
