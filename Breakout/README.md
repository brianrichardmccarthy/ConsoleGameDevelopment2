# Trivial Enhancements

* Multiple balls (done, see explaination in Advanced Enhancements),
* Automatic paddle (done, use 'A' key to switch from automatic to manual and vice vera),
* Fix update of ball with respect to delteTime (done).

# Straightforward Enhancements

* Blocks have multiple lives and health of blocks grows back over time (done, level 3),
* win/lose (done, Player wins if they destroy all the blocks on all the leves, loses if they hit the ground three times in one level),
* score (done, but visual studio didn't want to load the font so it just prints out to the console),
* level with clock (done, level 4 3 minutes to destroy all the blocks, same problems as score with regards displaying text in sfml window and visual stuio loading fonts. )
* Multiple levels - accessed by pressing 1,2,3 (done):
	* Level 1 level taken from lecture notes,
	* Level 2 Extra balls (see Advanced Enhancements),
	* Level 3 Blocks have three lives that regenerate over time and visually show this by changing color,
	* Level 4 3 minutes to beat the level.

# Advanced Enhancements

* Trapped balls that are not activated until released (done, but the blocks where the balls are being spawned are being removed and the balls just move up to op of the screen),
* Variable screen size (but keep aspect fixed) (done),
* Improve the ball-block collision (done but still slightly buggy, a noticable gap sometimes exisit).