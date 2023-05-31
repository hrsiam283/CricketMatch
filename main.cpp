
#include <bits/stdc++.h>
using namespace std;

class Player
{
protected:
    string name;
    int runs, balls, wickets, overs;

public:
    Player(string n)
    {
        name = n, runs = 0, balls = 0, wickets = 0, overs = 0;
    }

    virtual string getRole() = 0;
    virtual void updateStats(int r, int w) = 0;
    virtual void printStats() = 0;
    virtual string Name() = 0;

    bool operator>(Player &p)
    {
        return runs > p.runs;
    }
    friend void writeToFile(ofstream &file, Player *p);
    int Run() { return runs; }
};

class Batsman : public Player
{
public:
    Batsman(string n) : Player(n) {}
    string getRole() { return "Batsman"; }
    void updateStats(int r, int w)
    {
        runs += r;
        balls++;
    }
    void printStats()
    {
        cout << name << " (" << getRole() << "): " << runs << " runs in " << balls << " balls\n";
    }
    string Name()
    {
        return name;
    }
};
class Bowler : public Player
{
public:
    Bowler(string n) : Player(n) {}
    string getRole() { return "Bowler"; }
    void updateStats(int r, int w)
    {
        runs += r;
        wickets += w;
        balls++;
        if (balls % 6 == 0)
        {
            overs++;
        }
    }
    void printStats()
    {
        cout << name << " (" << getRole() << "): " << wickets << " wickets in " << overs << "." << balls % 6 << " overs, " << runs << " runs\n";
    }
    string Name()
    {
        return name;
    }
};
void writeToFile(ofstream &file, Player *p)
{
    file << p->Name() << " (" << p->getRole() << "): ";
    if (p->getRole() == "Batsman")
    {
        file << p->runs << " runs in " << p->balls << " balls\n";
    }
    else if (p->getRole() == "Bowler")
    {
        file << p->wickets << " wickets in " << p->overs << "." << p->balls % 6 << " overs, " << p->runs << " runs\n";
    }
}
template <typename T>
void swap(T arr[], int i, int j)
{
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
template <typename T>
void sort(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr, j, j + 1);
            }
        }
    }
}
const int N = 11;
int main()
{
    Player *teamA[N];
    Player *teamB[N];
    teamA[0] = new Batsman("Rohit Sharma");
    teamA[1] = new Batsman("Shikhar Dhawan");
    teamA[2] = new Batsman("Virat Kohli");
    teamA[3] = new Batsman("Suryakumar Yadav");
    teamA[4] = new Batsman("Rishabh Pant");
    teamA[5] = new Batsman("Hardik Pandya");
    teamA[6] = new Bowler("Ravindra Jadeja");
    teamA[7] = new Bowler("Bhuvneshwar Kumar");
    teamA[8] = new Bowler("Mohammed Shami");
    teamA[9] = new Bowler("Jasprit Bumrah");
    teamA[10] = new Bowler("Yuzvendra Chahal");
    teamB[0] = new Batsman("Jason Roy");
    teamB[1] = new Batsman("Jonny Bairstow");
    teamB[2] = new Batsman("Joe Root");
    teamB[3] = new Batsman("Eoin Morgan");
    teamB[4] = new Batsman("Jos Buttler");
    teamB[5] = new Batsman("Ben Stokes");
    teamB[6] = new Bowler("Chris Woakes");
    teamB[7] = new Bowler("Sam Curran");
    teamB[8] = new Bowler("Adil Rashid");
    teamB[9] = new Bowler("Jofra Archer");
    teamB[10] = new Bowler("Mark Wood");
    int scoreA = 0, scoreB = 0, wicketsA = 0, wicketsB = 0, oversA = 0, oversB = 0, strikerA = 0, nonStrikerA = 1, strikerB = 0, nonStrikerB = 1, bowlerB = 6, bowlerA = 6, ballsPerOver = 6, oversPerInnings = 10;
    bool isTeamABattingFirst = true;
    cout << "Tossing a coin...0/1\n";
    int toss = rand() % 2;
    // cin >> toss;
    if (toss == 0)
    {
        cout << "Team A wins the toss and chooses to bat first.\n";
        isTeamABattingFirst = true;
    }
    else
    {
        cout << "Team B wins the toss and chooses to bat first.\n";
        isTeamABattingFirst = false;
    }
    cout << "Starting the first innings...\n";
    if (isTeamABattingFirst)
    {
        while (oversA < oversPerInnings && wicketsA < N - 1)
        {
            cout << "Over " << oversA + 1 << ":\n";
            for (int i = 0; i < ballsPerOver; i++)
            {

                int run = rand() % 7;
                int wicket = rand() % 10;
                // cout<<"Run 0-6"<<endl;
                // cout << "wicket 0-1" << endl;
                // cin>>run;
                // cin>>wicket;

                if (wicket == 0)
                {
                    cout << teamA[strikerA]->Name() << " is out!\n";
                    teamA[strikerA]->updateStats(run, 0);
                    teamB[bowlerB]->updateStats(run, 1);
                    wicketsA++;
                    if (wicketsA == N - 1)
                    {
                        break;
                    }
                    strikerA = wicketsA + 1;
                }
                else
                {
                    cout << teamA[strikerA]->Name() << " scores " << run << " run(s)\n";
                    teamA[strikerA]->updateStats(run, 0);
                    teamB[bowlerB]->updateStats(run, 0);
                    scoreA += run;
                    if (run % 2 == 1)
                    {
                        swap(teamA, strikerA, nonStrikerA);
                    }
                }
            }
            oversA++;
            swap(teamA, strikerA, nonStrikerA);
            bowlerB = (bowlerB + 1) % N;
        }
        cout << "End of first innings. Team A scored " << scoreA << "/" << wicketsA << " in " << oversA << " overs.\n";
    }
    else
    {
        while (oversB < oversPerInnings && wicketsB < N - 1)
        {
            cout << "Over " << oversB + 1 << ":\n";
            for (int i = 0; i < ballsPerOver; i++)
            {
                int run = rand() % 7;
                int wicket = rand() % 10;
                // cout<<"Run 0-6"<<endl;
                // cout << "wicket 0-1" << endl;
                // cin>>run;
                // cin>>wicket;
                if (wicket == 0)
                {
                    cout << teamB[strikerB]->Name() << " is out!\n";
                    teamB[strikerB]->updateStats(run, 0);
                    teamA[bowlerA]->updateStats(run, 1);
                    wicketsB++;
                    if (wicketsB == N - 1)
                    {
                        break;
                    }
                    strikerB = wicketsB + 1;
                }
                else
                {
                    cout << teamB[strikerB]->Name() << " scores " << run << " run(s)\n";
                    teamB[strikerB]->updateStats(run, 0);
                    teamA[bowlerA]->updateStats(run, 0);
                    scoreB += run;
                    if (run % 2 == 1)
                    {
                        swap(teamB, strikerB, nonStrikerB);
                    }
                }
            }
            oversB++;
            swap(teamB, strikerB, nonStrikerB);
            bowlerA = (bowlerA + 1) % N;
        }
        cout << "End of first innings. Team B scored " << scoreB << "/" << wicketsB << " in " << oversB << " overs.\n";
    }
    cout << "Starting the second innings...\n";
    if (isTeamABattingFirst)
    {
        while (oversB < oversPerInnings && wicketsB < N - 1 && scoreB <= scoreA)
        {
            cout << "Over " << oversB + 1 << ":\n";
            for (int i = 0; i < ballsPerOver; i++)
            {
                int run = rand() % 7;
                int wicket = rand() % 10;
                // cout<<"Run 0-6"<<endl;
                // cout << "wicket 0-1" << endl;
                // cin>>run;
                // cin>>wicket;
                if (wicket == 0)
                {
                    cout << teamB[strikerB]->Name() << " is out!\n";
                    teamB[strikerB]->updateStats(run, 0);
                    teamA[bowlerA]->updateStats(run, 1);
                    wicketsB++;
                    if (wicketsB == N - 1)
                    {
                        break;
                    }
                    strikerB = wicketsB + 1;
                }
                else
                {
                    cout << teamB[strikerB]->Name() << " scores " << run << " run(s)\n";
                    teamB[strikerB]->updateStats(run, 0);
                    teamA[bowlerA]->updateStats(run, 0);
                    scoreB += run;
                    if (run % 2 == 1)
                    {
                        swap(teamB, strikerB, nonStrikerB);
                    }
                    if (scoreB > scoreA)
                    {
                        break;
                    }
                }
            }
            oversB++;
            swap(teamB, strikerB, nonStrikerB);
            bowlerA = (bowlerA + 1) % N;
        }
        cout << "End of second innings. Team B scored " << scoreB << "/" << wicketsB << " in " << oversB << " overs.\n";
    }
    else
    {
        while (oversA < oversPerInnings && wicketsA < N - 1 && scoreA <= scoreB)
        {
            cout << "Over " << oversA + 1 << ":\n";
            for (int i = 0; i < ballsPerOver; i++)
            {
                int run = rand() % 7;
                int wicket = rand() % 10;
                // cout<<"Run 0-6"<<endl;
                // cout << "wicket 0-1" << endl;
                // cin>>run;
                // cin>>wicket;
                if (wicket == 0)
                {
                    cout << teamA[strikerA]->Name() << " is out!\n";
                    teamA[strikerA]->updateStats(run, 0);
                    teamB[bowlerB]->updateStats(run, 1);
                    wicketsA++;
                    if (wicketsA == N - 1)
                    {
                        break;
                    }
                    strikerA = wicketsA + 1;
                }
                else
                {
                    cout << teamA[strikerA]->Name() << " scores " << run << " run(s)\n";
                    teamA[strikerA]->updateStats(run, 0);
                    teamB[bowlerB]->updateStats(run, 0);
                    scoreA += run;
                    if (run % 2 == 1)
                    {
                        swap(teamA, strikerA, nonStrikerA);
                    }
                    if (scoreA > scoreB)
                    {
                        break;
                    }
                }
            }
            oversA++;
            swap(teamA, strikerA, nonStrikerA);
            bowlerB = (bowlerB + 1) % N;
        }
        cout << "End of second innings. Team A scored " << scoreA << "/" << wicketsA << " in " << oversA << " overs.\n";
    }

    cout << "Result: ";
    if (scoreA > scoreB)
    {
        cout << "Team A wins by " << N - 1 - wicketsA << " wicket(s)\n";
    }
    else if (scoreB > scoreA)
    {
        cout << "Team B wins by " << N - 1 - wicketsB << " wicket(s)\n";
    }
    else
    {
        cout << "It is a tie\n";
    }
    sort(teamA, N);
    sort(teamB, N);
    cout << "Top scorer from team A: " << teamA[0]->Name() << " with " << teamA[0]->Run() << " runs\n";
    cout << "Top scorer from team B: " << teamB[0]->Name() << " with " << teamB[0]->Run() << " runs\n";
    ofstream file;
    file.open("stats.txt");
    file << "Team A:\n";
    for (int i = 0; i < N; i++)
    {
        writeToFile(file, teamA[i]);
    }
    file << "\nTeam B:\n";
    for (int i = 0; i < N; i++)
    {
        writeToFile(file, teamB[i]);
    }
    file.close();
    return 0;
}