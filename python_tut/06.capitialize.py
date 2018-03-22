def capital(str):
    out_str=""
    for word in str.split():
        new_word=word[0].upper()
        new_word+=word[1:len(word)]
        out_str+=new_word+" "
    print(out_str)

capital ("i am attyuttam saha. i study in nit warangal which is situated in warangal, telengana, india")
