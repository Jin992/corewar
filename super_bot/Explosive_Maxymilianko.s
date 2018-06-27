.name "Explosive Max"
.comment "
Three witches, casting a spell ...

Round about the cauldron go; 
In the poison'd entrails throw. 
Toad, that under cold stone 
Days and nights hast thirty one 
Swelter'd venom sleeping got, 
Boil thou first i' the charmed pot. 

Double, double toil and trouble; 
Fire burn and cauldron bubble. 

Fillet of a fenny snake, 
In the cauldron boil and bake; 
Eye of newt, and toe of frog, 
Wool of bat, and tongue of dog, 
Adder's fork, and blind-worm's sting, 
Lizard's leg, and howlet's wing, 
For a charm of powerful trouble, 
Like a hell-broth boil and bubble. 

Double, double toil and trouble; 
Fire burn and cauldron bubble. 
William Shakespeare"

start:
	st r1, 6

live_lable:
	live %1
	fork %-10
	live %1
	ldi r2, %-13, r3
	st r3, 25

#comment
