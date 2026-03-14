print("Guess the number!")

import random

print("Welcome to the Guessing Game!")

number = random.randint(1, 10)

guess = int(input("Enter your guess (1-10): "))

if guess == number:
    print("Correct! You win!")
else:
    print("Wrong! The number was:", number)
