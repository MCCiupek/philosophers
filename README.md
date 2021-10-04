# Philosophers

## Skills
* Imperative programming
* Unix
* Rigor

## Description
In this project, you will learn the basics of threading a process. You will
learn how to make threads. You will discover the mutex.

## Dining Philosophers problem
Five silent philosophers sit at a round table with bowls of spaghetti. Forks are placed between each pair of adjacent philosophers.

Each philosopher must alternately think and eat. However, a philosopher can only eat spaghetti when they have both left and right forks. Each fork can be held by only one philosopher at a time and so a philosopher can use the fork only if it is not being used by another philosopher. After an individual philosopher finishes eating, they need to put down both forks so that the forks become available to others. A philosopher can only take the fork on their right or the one on their left as they become available and they cannot start eating before getting both forks.

Eating is not limited by the remaining amounts of spaghetti or stomach space; an infinite supply and an infinite demand are assumed.

The problem is how to design a discipline of behavior (a concurrent algorithm) such that no philosopher will starve; i.e., each can forever continue to alternate between eating and thinking, assuming that no philosopher can know when others may want to eat or think.

## Use
Run ``make`` in ''philo'' to compile executor ``philo``.

``./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]``

## Example
![image](https://user-images.githubusercontent.com/51337012/135823458-eea4de5e-0c52-463b-8458-b25f706cc152.png)

Grade: 100/100
