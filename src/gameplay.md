# Gameplay

1. **Starting the Game:**
    * Player 1 starts by entering `1` to roll the dice. Player 2 starts by entering `9`.
    * A player must roll a `1` to begin their game.

2. **Rolling the Dice:**
    * Each player rolls the dice by entering their respective number (`1` for Player 1 and `9` for Player 2).
    * The dice roll generates a random number between `1` and `6`.

3. **Moving on the Board:**
    * Players move forward by the number shown on the dice.
    * If a player lands exactly on cell `100`, they win the game.
    * If a player's roll takes them beyond cell `100`, they stay in their current position and wait for their next turn.

4. **Snakes and Ladders:**
    * If a player lands on a cell with a snake, they slide down to a lower-numbered cell.
    * If a player lands on a cell with a ladder, they climb up to a higher-numbered cell.
    * Specific cells with snakes:
        * 18 to 6
        * 30 to 9
        * 49 to 26
        * 77 to 60
        * 92 to 71
        * 99 to 75
    * Specific cells with ladders:
        * 19 to 36
        * 26 to 67
        * 40 to 62
        * 46 to 69
        * 65 to 83

5. **Winning the Game:**
    * The first player to reach exactly cell `100` wins the game.

6. **Turns:**
    * Players take turns rolling the dice.
    * If one player rolls a `1` and the other hasn't, the player who rolled `1` starts playing their game while the other continues to try rolling a `1`.

### Facts

1. **Player Initialization:**
    * Player positions start at cell `0`.
    * The game continues to prompt players to roll the dice until they get a `1` to start their game.

2. **Reminder System:**
    * The game provides reminders to players about the locations of snakes and ladders based on their current position.

3. **Game Display:**
    * The current state of the board is displayed after each turn, showing the positions of both players and indicating if they land on the same cell.
