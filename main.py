import random

print("Welcome to the Guessing Game!")

number = random.randint(1, 10)

guess = int(input("Guess a number between 1 and 10: "))

if guess == number:
    print("Correct! You win!")
else:
    print("Wrong! The number was:", number)
