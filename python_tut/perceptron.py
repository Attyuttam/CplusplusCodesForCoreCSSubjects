import random

weights={}
learning_constant = 0.01

def perceptron(n):
    i = 0
    while i < n :
        weights[i]=random.randint(-2,2)
        i += 1

def activation(n):
    if n>0:
        return 1
    else :
        return -1
    
def feed_forward(inputs):
    sum = 0
    i = 0
    while i < len(weights):
        sum = sum + inputs[i] * weights[i]
        i += 1
    return activation(sum)

def train(inputs,desired):
    guess = feed_forward(inputs)
    error = desired - guess
    i = 0
    while i < len(weights):
        weights[i] = weights[i] + learning_constant * error * inputs[i]
        i += 1
        
perceptron(3)
#points to the right
train([2,1,1],1)
train([2,2,1],1)
train([3,4,1],1)
train([2,5,1],1)
train([4,7,1],1)
train([4,1,1],1)
train([7,1,1],1)
train([5,3,1],1)
train([7,4,1],1)
train([8,9,1],1)

#points to the left
train([-2,1,1],-1)
train([-2,2,1],-1)
train([0.3,4,1],-1)
train([0.2,5,1],-1)
train([-4,7,1],-1)
train([0.4,1,1],-1)
train([0.7,1,1],-1)
train([-5,3,1],-1)
train([0.7,4,1],-1)
train([0.8,9,1],-1)

i=0
while i<3 :
    print(weights[i]," ")
    i+=1
print(feed_forward([-120,100,1]))
