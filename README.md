# CricketMatch

This is a simple cricket match simulation using user input. In my hall, there will be a cricket tournament. I've made this project so that I can calculate all the match results and summaries. Further instruction will be provided along with the code.

A sample input is given with this repository. The output is also given in two ways. One is along with input and others are just output.

Here's a brief summary of how it works:

1. The code starts by taking input for the names of two teams and their respective players.

2. The `Team` class is defined, which holds information about a team, such as player names, runs, wickets, and bowling statistics. It also includes methods for displaying player information, keeping score, playing the match, and summarizing the match.

3. The `play` method simulates the batting innings of a team. It asks for the batting and bowling sides, as well as the bowler. It then proceeds to simulate each ball and takes input for the runs scored or other events like getting out, wide balls, or no balls.

4. The score is updated accordingly, and the batting and bowling sides are swapped as necessary. The `scoreboard` method is called to display the current score and player statistics.

5. The match is played over a specified number of overs, and the match summary is displayed at the end, showing the total runs, wickets, and individual player statistics for both teams.

6. Finally, the `result` method determines and displays the result of the match based on the total runs scored by each team.

Note: This code assumes that the user will input the necessary values correctly and follows the specified instructions for inputting runs and other events during the match simulation.
