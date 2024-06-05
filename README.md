# Blackjack-C-
Blackjack for a arduino
Inputs are the left and right buttons on the arduino
outputs are lights and Serial Monitor

The game itself is meant to emulate blackjack, where the goal is to reach 21 and or beat the dealers score.
Player starts with 5 points, represented by the lights on the arduino
then player is dealt two cards(1-11, with 10 being 4 times as common) and dealer is dealt one
then the player decides to hit or stand using the left or right buttons
if the player hits using the right button it will add another card to their score, where it will then prompt them to make the same decision again
if the player stands using the left button they will then get their score compared to the dealers
if during any part of this process the player goes over 21, the player busts, or loses, and proceeds to lose one point, where then the game will start again.
during score comparison, if the player has less than the dealer, the player loses and loses a point.
if the player has more points than the dealer, the player wins and gains a point,
when the player reaches 10 points, they win where a winning message is displayed and a winning lightshow is displayed
if the player loses all their points, the player loses where a losing message is displayed and a losing lightshow is displayed
