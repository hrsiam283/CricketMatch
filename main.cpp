#include <bits/stdc++.h>
using namespace std;
vector<string> Batsman;
class Team
{
protected:
    int visforthisTeam[11] = {0};
    int overcount[11] = {0};
    int wicketcount[11] = {0};
    string teamName;
    int totalRun = 0;
    int run[11] = {0};
    int ballconsumed[11] = {0};
    string playersName[11];
    int wicket = 0;
    int battingside = -1, otherside = -1;
    int bowler = -1;
    int runOfbowler[11] = {0};

public:
    Team(string name, string s[])
    {
        teamName = name;
        for (int i = 0; i < 11; i++)
        {
            playersName[i] = s[i];
        }
    }
    void display()
    {
        cout << "Name\t"
             << "Status\t" << endl;
        for (int i = 0; i < 11; i++)
        {
            if (i == battingside || i == otherside)
                continue;
            cout << i << '.' << playersName[i] << '\t';

            if (visforthisTeam[i])
                cout << "Out" << endl;
            else
                cout << "Not Out" << endl;
        }
    }
    void display2(Team &b)
    {
        cout << "Name\t"
             << "Over\t"
             << "Wicket\t" << endl;
        for (int i = 0; i < 11; i++)
        {
            if (i == bowler)
                continue;
            cout << i << '.' << b.playersName[i] << '\t' << overcount[i] << '\t' << wicketcount[i] << endl;
        }
    }
    void scoreboard(Team &b, int balls, int battingside, int otherside, int bowler)
    {

        cout << "BATTING\t" << '\t' << "BOLLING" << endl;
        for (int i = 0; i < 3; i++)
            cout << b.teamName[i];
        cout << 'V';
        for (int i = 0; i < 3; i++)
        {
            cout << teamName[i];
        }
        cout << ": " << totalRun << '/' << wicket << '\t';
        cout << "Over: " << balls / 6 << '.' << balls % 6 << endl;
        cout << playersName[battingside] << '*' << run[battingside] << '(' << ballconsumed[battingside] << ')' << '\t';
        cout << b.playersName[bowler] << ' ' << overcount[bowler] << "." << balls % 6 << '/' << runOfbowler[bowler] << '/' << wicketcount[bowler] << endl;

        cout << playersName[otherside] << ' ' << run[otherside] << '(' << ballconsumed[otherside] << ')' << endl;
    }
    void play(Team &b, int over)
    {
        cout << teamName << " will bat" << endl;

        cout << "Who is in the battingside and the otherside batsman?" << endl;
        display();

        cin >> battingside >> otherside;

        int balls = 0;
        while (over--)
        {
            cout << "Who is the bowler?" << endl;
            display2(b);

            cin >> bowler;

            for (int i = 0; i < 6; i++)
            {
                scoreboard(b, balls, battingside, otherside, bowler);
                balls++;
                string s;
                cin >> s;
                if (s == "1")
                {
                    totalRun++;
                    run[battingside]++;
                    ballconsumed[battingside]++;
                    swap(battingside, otherside);
                    runOfbowler[bowler] += 1;
                }
                else if (s == "2")
                {
                    totalRun += 2;
                    run[battingside] += 2;
                    ballconsumed[battingside]++;
                    runOfbowler[bowler] += 2;
                }
                else if (s == "3")
                {
                    totalRun += 3;
                    run[battingside] += 3;
                    swap(battingside, otherside);
                    ballconsumed[battingside]++;
                    runOfbowler[bowler] += 3;
                }
                else if (s == "4")
                {
                    totalRun += 4;
                    run[battingside] += 4;
                    ballconsumed[battingside]++;
                    runOfbowler[bowler] += 4;
                }
                else if (s == "5")
                {
                    totalRun += 5;
                    run[battingside] += 4;
                    ballconsumed[battingside]++;
                    runOfbowler[bowler] += 5;
                }
                else if (s == "6")
                {
                    totalRun += 6;
                    run[battingside] += 6;
                    ballconsumed[battingside]++;
                    runOfbowler[bowler] += 6;
                }
                else if (s == "out")
                {
                    cout << "Who? 0->battingside" << endl;
                    cout << "1->otherside" << endl;
                    bool flag = 0;
                    cin >> flag;
                    if (flag == 0)
                    {
                        cout << playersName[battingside] << endl;
                        cout << "Total Runs of this player" << ' ' << run[battingside] << '(' << ballconsumed[battingside] << ")" << endl;
                        visforthisTeam[battingside] = 1;
                        cout << "Who is new Player\n";
                        display();
                        cin >> battingside;
                        wicket++;
                        wicketcount[bowler]++;
                    }
                    else
                    {
                        cout << playersName[otherside] << endl;
                        cout << "Total Runs of this player" << ' ' << run[otherside] << '(' << ballconsumed[otherside] << ")" << endl;
                        visforthisTeam[otherside] = 1;
                        cout << "Who is new Player\n";
                        display();
                        cin >> otherside;
                        wicket++;
                        wicketcount[bowler]++;
                    }
                }
                else if (s == "no" || s == "wide")
                {
                    totalRun++;
                    runOfbowler[bowler]++;
                    cout << "Any other run? If 'Yes', How much? else '0'" << endl;
                    int x;
                    cin >> x;
                    runOfbowler[bowler] += x;
                    totalRun += x;
                    run[battingside] += x;
                    i--;
                    if (x % 2 == 1)
                        swap(battingside, otherside);
                    balls--;
                }

                if (i == 5)
                {
                    swap(battingside, otherside);
                }
            }
            overcount[bowler]++;
            scoreboard(b, balls, battingside, otherside, bowler);
        }
    }
    void matchsummery(Team &b)
    {
        cout << teamName << ':' << totalRun << '/' << wicket << endl;
        cout << "Name\t"
             << "Run\t"
             << "Balls\t"
             << "Status\t" << endl;

        for (int i = 0; i < 11; i++)
        {
            cout << playersName[i] << '\t' << run[i] << '\t';
            if (visforthisTeam[i])
            {
                cout << ballconsumed[i] << '\t' << "Out" << endl;
            }
            else
                cout << ballconsumed[i] << '\t' << "Not Out" << endl;
        }
        cout << endl
             << endl
             << endl;
        cout << b.teamName << endl;
        cout << "Name\t"
             << "Over\t"
             << "Run\t"
             << "Wicket\t" << endl;

        for (int i = 0; i < 11; i++)
        {
            cout << b.playersName[i] << '\t' << overcount[i] << '\t' << runOfbowler[i] << '\t' << wicketcount[i] << endl;
        }
    }
    void result(Team &b)
    {
        if (totalRun > b.totalRun)
        {
            cout << teamName << " is won! by " << 10 - wicket << " wiket(s)" << endl;
        }
        else if (totalRun < b.totalRun)
        {
            cout << b.teamName << " is won! by " << b.totalRun - totalRun << " run(s)" << endl;
        }
        else
            cout << "The match is draw" << endl;
    }
};

class PlyersProfile : public Team
{
protected:
    string type;
    int totalrun;
    int totalwicket;

public:
    void display(int i)
    {
        cout << "Name : " << playersName[i - 1] << endl;
        cout << "Type : " << type << endl;
        cout << "Total Run : " << totalrun << endl;
        cout << "Totalwicket : " << totalwicket << endl;
    }
};

int main()
{

    // int n;
    // cout << "How many over?" << endl;
    // cin >> n;
    // string t[] = {"Tamim", "Liton", "sakib", "Mush", "Joy", "Musta", "Rubel", "Miraz", "Ebad", "Mash", "Raz"};
    // string u[] = {"Rohit", "Virat", "Surya", "Dhoni", "KL", "Hardik", "Singh", "Shami", "Harb", "Ji", "Acch"};
    // Team a("Bangladesh", t), b("India", u);
    cout << " BANGABANDHU HALL TOURNAMENT 2023 " << endl;
    cout << endl;
    cout << endl;
    cout << "Notice: In this program almost input will be taken by porper direction." << endl;
    cout << "However, may be at some place it is a input section without any direction." << endl;
    cout << "This is this section where you have to give input of runs in a ball. 1,2,3,4,5 or 6 can be an input." << endl;
    cout << "However some situation can be happened like out ball, wide ball, no ball, extra run." << endl;
    cout << "If this is the case, you should give input as 'out', 'no', 'wide'. Further instruction will be given.\n"
         << endl;

    string nameofteam[2];
    cout << "Name of Team I" << endl;
    cin >> nameofteam[0];
    cout << "Name of 11 players in Team " << nameofteam[0] << endl;
    string teamA[11];
    for (int i = 0; i < 11; i++)
    {
        cin >> teamA[i];
    }
    cout << "Name of Team II" << endl;
    cin >> nameofteam[1];
    cout << "Name of 11 players in Team " << nameofteam[1] << endl;
    string teamB[11];
    for (int i = 0; i < 11; i++)
    {
        cin >> teamB[i];
    }
    cout << "Who will play first?" << endl;
    for (int i = 0; i < 2; i++)
        cout << i << ' ' << nameofteam[i] << ' ' << endl;
    int x;
    cin >> x;
    if (x == 0)
    {
        int over;

        cout << "How many Over\n";
        cin >> over;
        Team a(nameofteam[0], teamA), b(nameofteam[1], teamB);
        cout << "At First ";
        a.play(b, over);

        cout << endl
             << endl
             << endl;
        a.matchsummery(b);

        cout << endl
             << endl
             << endl;
        cout << "First Half is over. Now ";
        b.play(a, over);
        cout << endl
             << endl
             << endl;
        b.matchsummery(a);
        a.result(b);
    }
    else
    {
        int over;

        cout << "How many Over\n";
        cin >> over;
        Team a(nameofteam[1], teamB), b(nameofteam[0], teamA);
        cout << "At First ";
        a.play(b, over);

        cout << endl
             << endl
             << endl;
        a.matchsummery(b);

        cout << endl
             << endl
             << endl;
        cout << "First Half is over. Now ";
        b.play(a, over);
        cout << endl
             << endl
             << endl;
        b.matchsummery(a);
        a.result(b);
    }
}