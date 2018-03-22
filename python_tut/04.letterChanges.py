def letterChanges(input_str):
    out_str="";
    for letter in input_str:
        newChar=''
        if letter == 'z':
            newChar='a'
        elif letter == 'Z':
            newChar='A'
        else:
            newChar=chr(ord(letter)+1)
        if newChar in "aeiou":
               newChar=newChar.upper()
        out_str+=newChar
    return out_str
print(letterChanges("zbcde"))
