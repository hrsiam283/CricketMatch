This code simulates a cricket match between two teams, Team A and Team B. The match consists of two innings, where each team takes turns batting and bowling. The outcome of the match is determined based on the scores and wickets taken by each team.

Here's a summary of how the code works:

1. It defines two classes: `Player`, which is an abstract base class, and two derived classes `Batsman` and `Bowler`. These classes represent players in the cricket match.

2. The `Player` class has common attributes such as name, runs, balls, wickets, and overs. It also defines pure virtual functions for getting the player's role, updating their stats, printing their stats, and getting their name.

3. The `Batsman` and `Bowler` classes inherit from the `Player` class and provide their specific implementations for the virtual functions.

4. The code defines a `writeToFile` function that writes the player's stats to a file.

5. It defines a template `swap` function and a `sort` function to sort an array of players.

6. The main function initializes two arrays, `teamA` and `teamB`, with instances of players. It sets up the initial conditions for the match, such as scores, wickets, overs, and the order of players.

7. The code simulates a toss to decide which team bats first. Then, it starts the first innings.

8. In each innings, the code simulates overs and balls. For each ball, it randomly generates a run and a wicket. If a wicket falls, the corresponding player is updated, and the batting order is adjusted. If a run is scored, the respective player's stats are updated, and the score is increased. The bowler's stats are also updated.

9. After the first innings, the code prints the score and wickets for the batting team.

10. If there is a second innings (when the second team is batting), the code simulates it in a similar manner.

11. Finally, the code determines the result of the match based on the scores. It sorts the players based on their runs and outputs the top scorers from each team. The stats of all players are written to a file.

In summary, this code simulates a cricket match by generating random runs and wickets for each ball. It keeps track of the players' stats and determines the winner based on the scores.
