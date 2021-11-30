# The Tortoise Chronicles: Journey to Dragon’s Hollow
The Tortoise Chronicles: Journey to Dragon’s Hollow

COMP 2404 -- Take-home Final Exam
program name: final
Author: Bob Tian  #101083783

The program will simulate a confined area called Dragon’s Hollow, which is basically a flat, sunken area,
surrounded by trees on three sides and a cave on the other. Timmy Tortoise and Harold the Hare will make
their way from the left-hand side of Dragon’s Hollow to the right-hand side, where the Emerald is located
inside the cave. This cave is guarded by a Dragon and a bunch of dorcs, borcs, and porcs.
The goal of the program is for Timmy or Harold to make their way across Dragon’s Hollow (moving from
the left-hand side to the right-hand side), and rescue the Emerald, all without dying.


The program has implemented the following requirements:
1.1. The quest of our heroes (Timmy and Harold), and their battles against the hired fighters (dorcs, borcs,
and porcs) guarding the Dragon’s cave, take place in Dragon’s Hollow. \
1.1.1. Dragon’s Hollow, represented as 25 characters wide (horizontal axis) and 5 characters high (ver-
tical axis); the right-most edge of the Hollow represents a cave entrance in the middle three
characters \
1.1.2. Initially, the following quest players are shown:\
(a) Timmy (represented by his avatar ’T’) and Harold (with avatar ’H’) are situated at the left-
most edge of the Hollow, at different randomly generated vertical positions (you must use a
random number generator function for this; one can be downloaded from here).\
(b) The Dragon (represented by its avatar ’D’) is situated at the right-most edge of the Hollow, at
themidpoint on the vertical axis. TheEmerald is not a quest player, but it can be represented
as an asterisk ’*’.\
1.1.3. Note: The display must be stored as a class template specialization of a 2-dimensional array of
chars. You must implement your own 2-dimensional array collection class template for this. In
your implementation of this class template, the elements must be declared as a double pointer
of type T, where the 2-dimensional array is represented as a dynamically allocated array of dy-
namically allocated arrays.\
1.2. Timmy and Harold each begin with 15 health points. Timmy has a strength of 3 points and an armour
of 3 points, and Harold has a strength of 5 points and an armour of 1 point.\
1.3. Note: You will need a base class for all the different types of quest players. Your program must store
a collection of the quest players that are located in Dragon’s Hollow, and this collection must be a
STL list of base class object pointers.\
1.4. The program iterates until either (1) Timmy or Harold claims the Emerald, which happens when one
of our heroes walks into the cave where the Emerald is located, or (2) both heroes are dead.
1.5. At each iteration, the following occurs:
1.5.1. With a probability of 60%, your program generates a new fighter:
(a) A new fighter has equal probability of being a dorc, a borc, or a porc. Dorcs are represented
by the avatar ’d’, borcs by ’b’, and porcs by ’p’.
(b) Fighters are initially situated on the right-most edge of Dragon’s Hollow, at a randomly gen-
erated vertical position in front of the cave.
(c) Fighters begin with 5 health points, and a randomly generated strength in the following
ranges: dorcs begin with a strength between 6 and 8 points (inclusively), borcs with a strength
between 8 and 11 points, and porcs between 4 and 5 points.
1.5.2. Your program loops over each quest player in the list. For each quest player, your program must
invoke a function that polymorphically computes that player’s next position. Quest players
move according to these rules:
(a) Timmy and Harold move one horizontal position to the right, with a vertical position randomly
generated between the same vertical position, one position up, or one position down.
(b) Fighters move one horizontal position to the left, with a vertical position randomly generated
between the same vertical position, one position up, or one position down.
©2020 Christine Laurendeau COMP 2404 :: Winter 2020 :: Take-home Final Exam 2/6
(c) The Dragon paces up and down in front of the cave entrance, moving up one position until it
reaches the top position of the entrance, then reversing direction, until it reaches the bottom
position of the entrance, then reversing direction, and so on.
(d) If the new position computed for a quest player is out of bounds of the Hollow, the player is
positioned at an adjacent, valid position instead.
(e) If the new position is not occupied, the quest player moves to that position.
(f) If the new position is occupied by another quest player, a collision ensues and is handled
as described below. Both quest players are still moved to that position, although only one
avatar will be displayed.
(g) Any fighters that have reached the left-most edge disappear from the Hollow and from the
quest.
1.5.3. The display is refreshed to show all the quest players, in their updated positions.
1.5.4. Handling collisions:
(a) If Timmy and Harold collide with each other, nothing happens.
(b) If a fighter collides with the Dragon or with another fighter, nothing happens.
(c) If a hero collides with the Dragon, the hero instantly dies.
(d) If a hero and a fighter collide, both quest players take a hit, as follows:
(i) If Timmy or Harold takes a hit, that hero’s health is decreased by the damage inflicted by
the fighter. The damage is equal to the fighter’s strength, minus the hero’s armour. When
a hero’s health reaches zero, he dies.
(ii) If a fighter takes a hit, that fighter’s health is decreased by the damage inflicted by the
hero, which is equal to the hero’s strength. When a fighter’s health reaches zero, it dies.
(e) If Timmy or Harold dies, his position is permanently marked with a ’+’ to indicate his grave.
(f) If a fighter dies, it is removed from the quest.
1.6. Innovative feature: In addition to all requirements stipulated above, you will implement a new,
innovative feature as an add-on to the program. Your new feature must, at minimum, meet the
following criteria:
1.6.1. It must require the implementation of a significant amount of additional code.
1.6.2. It must involve the implementation of several new classes that work together to implement the
new feature.
1.6.3. It must be a useful feature in the context of the program, and not some filler or make-work
feature.
1.6.4. To earn marks, the feature must be thoroughly described in your README file.

Several innovative features beyond requirements:
Add a welcome interface for user selection
Provice interface for adjusting width and height of the Hollow
The QuestPlayer will act acording to the new size and perform correct beheiviour
Add statistics page to log outcomes of all run during the program, and print it for user
classes are involved in providing the functionality:
main
Dragon
Hero
QuestPlayer
View

Background Story:
Trouble is brewing in King Aesop’s peaceful realm. Handsome Prince Harold the Hare has come up with
his most preposterous idea yet. He has decided that, in order to woo the fair Lady Gwendolyn and win her
over, he will be braving theMount of Dooom, on a quest to recover the Emerald of the Isles from the
ferocious Dragon that guards it. He plans to present the Emerald to the fair Lady Gwendolyn in honour
of her birthday. When Prince Harold asks the assembled throngs of citizens for volunteers to escort him
to the Dragon’s lair, he is naturally met with complete silence. He has thus decided to recruit über-geek
Timmy Tortoise, Lady Gwendolyn’s truelove, to accompany him on this hare-brained adventure. Timmy,
not about to be outdone by a Hare, has foolishly agreed to go along. And to think that all Gwendolyn really
wanted for her birthday was a replacement Geek is Beautiful T-shirt.
Of course, Lady Gwendolyn is well aware of the danger involved in this quest. The Emerald is believed
to be hidden in a cave at the far end of Dragon’s Hollow on top of the Mount of Dooom. The Dragon
is known to pace in front of his cave and breathe fire upon and barbecue any intruders. Further, rumour
has it that ever since Timmy Tortoise and Prince Harold attempted their race up the Mount of Dooom
earlier this year, the Dragon has procured some hired muscle to help him protect his loot. Since the Orcs
were already on contract to Middle-earth, the Dragon was forced to hire their smaller cousins the dwarf
Orcs, also known as dorcs, along with their vaguely related and even more vertically challenged kin, the
bear Orcs (borcs) and the pork Orcs (porcs). Aware that the two adventurers are hopelessly outmatched,
Lady Gwendolyn must make sure that they survive their ordeal.
Sadly, Gwendolyn is not a ninja warrior type of heroine. But as an ace programmer in her own right, she
is the brainy type. Before Timmy Tortoise’s arrival in King Aesop’s realm, Gwendolyn was the reigning
five-time undefeated champion of the annual Programming Olympics. But one day, Timmy Tortoise came
plodding into town to enter the competition and tied Gwendolyn for first place and the official title of
Kingdom Geek. Not only was Lady Gwendolyn delighted to finally meet her equal, it was love at first byte.
So to help her misguided friends, Gwendolyn has decided to program a model of Timmy and Harold’s trek
across Dragon’s Hollow, where the cave sheltering the Emerald is located. In executing this randomized
model multiple times to analyze all possible outcome scenarios of the quest, Gwendolyn believes that she
can estimate exactly where and when to send the real ninja warriors that she has hired, so that they can
slay the Dragon and rescue our heroes. Since Timmy Tortoise and Prince Harold have already left on their
quest, packing plenty of carrots and lettuce for sustenance, time is of the essence for the development of
this rescue plan. As a result, Lady Gwendolyn has asked you, Timmy’s close friend and confidant, to help
her with the development of the quest model.

©2020 Christine Laurendeau COMP 2404 :: Winter 2020 :: Take-home Final Exam 
