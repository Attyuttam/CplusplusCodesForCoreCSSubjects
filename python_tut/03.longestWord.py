def longestWord(input_str):
    longestWordLength=0;
    longestWord="";
    for word in input_str.split():
        count = 0
        for letter in word:
            if letter.isalpha():
                count+=1
                
        if count>longestWordLength:
    
            longestWordLength=count
            longestWord=word
    
    print(longestWord," and length: ",longestWordLength)
longestWord("babloo goeeeeeeeeees office yo")

