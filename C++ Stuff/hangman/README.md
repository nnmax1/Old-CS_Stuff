<h1>Hangman Game from the command line</h1>

<h1>Files </h1>
<a href="https://github.com/nnmax1/CPPExercises/tree/master/solutions/hangman">hangman files </a>

<h2>The Game: </h2>
<p>A random word is generated from the file words.txt. That word will be the word that the player
has to figure out. The player is given the option to either guess the word entirely or guess a letter that
might be in the word. If the letter is contained in the word, it will be revealed to the player and no body part will be hung. For every missed letter, or word (in the case that the player chooses to guess an entire word instead of a letter), a body part of the man will be hung. When the hangman's head, torso, 2 arms, and 2 legs are all hung, the player loses the game. If the player is able to figure out what the word is before the hangman is hung, then the player wins. </p>
</p>

<h2>*NOTE: Make sure that the file hangman.exe is in the same
directory as the file words.txt before running it</h2>

<h2>Compilation instructions: </h2>
<pre>
user/studyCPP/part6/hangman/src$ make
g++ -c -Wall  word.cpp
g++ -c -Wall  hangman.cpp
g++ -c -Wall main.cpp
g++ word.o main.o hangman.o -o hangman.exe
user/studyCPP/part6/hangman/src$ rm *.o
</pre>

<h2>Sample Run of hangman.exe</h2>
<pre>
GAME OF HANGMAN V.S THE COMPUTER.
The word is 5 letters long.
--------------------------------------
CURRENT HANGMAN:
Nothing hung yet...
--------------------------------------
CURRENT WORD:
__ __ __ __ __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): a
The word does not contain the letter: a
--------------------------------------
CURRENT HANGMAN:
HEAD
--------------------------------------
CURRENT WORD:
__ __ __ __ __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): o
The word does not contain the letter: o
-------------------------------------- 
CURRENT HANGMAN:
HEAD
TORSO
-------------------------------------- 
CURRENT WORD:
__ __ __ __ __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): e
The word does not contain the letter: e
--------------------------------------
CURRENT HANGMAN:
HEAD
TORSO
ARM
--------------------------------------
CURRENT WORD:
__ __ __ __ __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): u
The word contains the letter: u
--------------------------------------
CURRENT HANGMAN:
HEAD
TORSO
ARM
--------------------------------------
CURRENT WORD:
__ __ u __ __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): s
The word contains the letter: s
--------------------------------------
CURRENT HANGMAN:
HEAD
TORSO
ARM
--------------------------------------
CURRENT WORD:
__ __ u s __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): r
The word contains the letter: r
--------------------------------------
CURRENT HANGMAN:
HEAD
TORSO
ARM
--------------------------------------
CURRENT WORD:
__ r u s __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): t
The word does not contain the letter: t
--------------------------------------
CURRENT HANGMAN:
HEAD
TORSO
2 ARMS
--------------------------------------
CURRENT WORD:
__ r u s __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): h
The word contains the letter: h
--------------------------------------
CURRENT HANGMAN:
HEAD
TORSO
2 ARMS
--------------------------------------
CURRENT WORD:
__ r u s h
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): b
The word contains the letter: b
You got the word! You Won!
The word is: brush.
Games won: 1
Do you want to play again?[Y/n]: Y
--------------------------------------
GAME OF HANGMAN V.S THE COMPUTER.
The word is 4 letters long.
--------------------------------------
CURRENT HANGMAN:
Nothing hung yet...
--------------------------------------
CURRENT WORD:
__ __ __ __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 1
Enter the word in all lowercase: a
You did not get the word.
--------------------------------------
CURRENT HANGMAN:
HEAD
--------------------------------------
CURRENT WORD:
__ __ __ __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): e
The word does not contain the letter: e
--------------------------------------
CURRENT HANGMAN:
HEAD
TORSO
--------------------------------------
CURRENT WORD:
__ __ __ __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): i
The word does not contain the letter: i
--------------------------------------
CURRENT HANGMAN:
HEAD
TORSO
ARM
--------------------------------------
CURRENT WORD:
__ __ __ __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): o
The word does not contain the letter: o
--------------------------------------
CURRENT HANGMAN:
HEAD
TORSO
2 ARMS
--------------------------------------
CURRENT WORD:
__ __ __ __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): u
The word contains the letter: u
--------------------------------------
CURRENT HANGMAN:
HEAD
TORSO
2 ARMS
--------------------------------------
CURRENT WORD:
__ u __ __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): n
The word does not contain the letter: n
--------------------------------------
CURRENT HANGMAN:
HEAD
TORSO
2 ARMS
1 LEG
--------------------------------------
CURRENT WORD:
__ u __ __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): r
The word does not contain the letter: r
Your person was hanged! You lost!
The word is: busy.
Games won: 1
Do you want to play again?[Y/n]: y
--------------------------------------
GAME OF HANGMAN V.S THE COMPUTER.
The word is 8 letters long.
--------------------------------------
CURRENT HANGMAN:
Nothing hung yet...
--------------------------------------
CURRENT WORD:
__ __ __ __ __ __ __ __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): a
The word contains the letter: a
--------------------------------------
CURRENT HANGMAN:
Nothing hung yet...
--------------------------------------
CURRENT WORD:
__ __ __ __ __ __ a __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): e
The word does not contain the letter: e
--------------------------------------
CURRENT HANGMAN:
HEAD
--------------------------------------
CURRENT WORD:
__ __ __ __ __ __ a __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): o
The word contains the letter: o
--------------------------------------
CURRENT HANGMAN:
HEAD
--------------------------------------
CURRENT WORD:
__ o __ o __ __ a __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): r
The word does not contain the letter: r
--------------------------------------
CURRENT HANGMAN:
HEAD
TORSO
--------------------------------------
CURRENT WORD:
__ o __ o __ __ a __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): s
The word contains the letter: s
--------------------------------------
CURRENT HANGMAN:
HEAD
TORSO
--------------------------------------
CURRENT WORD:
__ o __ o s s a __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): t
The word does not contain the letter: t
--------------------------------------
CURRENT HANGMAN:
HEAD
TORSO
ARM
--------------------------------------
CURRENT WORD:
__ o __ o s s a __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): b
The word does not contain the letter: b
--------------------------------------
CURRENT HANGMAN:
HEAD
TORSO
2 ARMS
--------------------------------------
CURRENT WORD:
__ o __ o s s a __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): p
The word does not contain the letter: p
--------------------------------------
CURRENT HANGMAN:
HEAD
TORSO
2 ARMS
1 LEG
--------------------------------------
CURRENT WORD:
__ o __ o s s a __
--------------------------------------
Do you want to guess the word (1) or choose a letter(2)?: 2
Enter a letter(A-Z): m
The word does not contain the letter: m
Your person was hanged! You lost!
The word is: colossal.
Games won: 1
Do you want to play again?[Y/n]: n
--------------------------------------
</pre>
