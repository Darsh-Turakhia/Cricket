/*
This is just a basic version of cricket scorecard it just accepts the runs scored off a ball by batting team and then adds it up to the total in both the innings and declares the winner
The player names are just for fun and is not displayed anywhere
But as you know some bugs are left purposefully
*/
#include "iostream"
#include "cstring"
#include "stdlib.h"
using namespace std;
int main()
{
	//variable declaration
	int tosscall,call,toss,total_runs[2],runs[2],extras[2],wickets[2],nb[2],w[2],lb[2],dots[2],singles[2],doubles[2],threes[2],fours[2],fives[2],sixes[2],balls[2],input,ind_rb;
	string t1[11],t2[11];
	char batfirst[100],batsecond[100],tn1[100],tn2[100];
	//variable initialization
	runs[0] = 0;
	extras[0] = 0;
	wickets[0] = 0;
	nb[0] = 0;
	w[0] = 0;
	lb[0] = 0;
	dots[0] = 0;
	singles[0] = 0;
	doubles[0] = 0;
	threes[0] = 0;
	fours[0] = 0;
	fives[0] = 0;
	sixes[0] = 0;
	balls[0] = 0;
	runs[1] = 0;
	extras[1] = 0;
	wickets[1] = 0;
	nb[1] = 0;
	w[1] = 0;
	lb[1] = 0;
	dots[1] = 0;
	singles[1] = 0;
	doubles[1] = 0;
	threes[1] = 0;
	fours[1] = 0;
	fives[1] = 0;
	sixes[1] = 0;
	balls[1] = 0;
	//fetching team names
	cout<<"\n Enter the first team name : ";
	cin>>tn1;
	cout<<"\n Enter the second team name : ";
	cin>>tn2;
	//performing toss
	cout<<"\n Toss time !!!! ";
	toss = rand()%2;
	cout<<tn1<<", What is your call ?? (0->head & 1->tail)";
	cin>>tosscall;
	//checking who won the toss
	if(tosscall == toss)
	{
		cout<<"\n Congo you won the toss ";
	}
	else
	{
		cout<<"\n Oops you lost the toss ";
	}
	cout<<"\n What is your call ?? (0->bat & 1->bowl) ";
	cin>>call;
	//deciding which team team will bat first and which second
	if(call == 0 && tosscall == toss)
	{
		strcpy(batfirst,tn1);
		strcpy(batsecond,tn2);
	}
	else if(call == 1 && tosscall == toss)
	{
		strcpy(batfirst,tn2);
		strcpy(batsecond,tn1);
	}
	else if(call == 0 && tosscall != toss)
	{
		strcpy(batfirst,tn2);
		strcpy(batsecond,tn1);	
	}
	else
	{
		strcpy(batfirst,tn1);
		strcpy(batsecond,tn2);
	}
	//fetching player names
	cout<<"\n Enter player names for "<<tn1;
	for(int i=0; i<11; i++)
		cin>>t1[i];
	cout<<"\n Enter player names for "<<tn2;
	for(int i=0; i<11; i++)
		cin>>t2[i];
	//displaying scorecard rules
	cout<<"\n Welcome to this match \n Rules for ticking the scorecard are as follows : ";
	cout<<"\n 1) Press the number key for the respective runs scored ny the batsmen.";
	cout<<"\n 2) Press the key 7 for wicket.";
	cout<<"\n 3) Press the key 8 for no ball.";
	cout<<"\n 4) Press the key 9 for wide ball.";
	cout<<"\n 5) Press the key 10 for leg byes.";
	cout<<"\n So Now Let's Start the match !!!!!!!!! ";
	cout<<"\n Here we are with the first ball of this match ";
	//taking input for each ball in first innings
	for(int i=0; i<120; i++)
	{
		cin>>input;
		switch(input)
		{
			case 0:
				dots[0]++;
				balls[0]++;
				break;
			case 1:
				singles[0]++;
				balls[0]++;
				break;
			case 2:
				doubles[0]++;
				balls[0]++;
				break;
			case 3:
				threes[0]++;
				balls[0]++;
				break;
			case 4:
				fours[0]++;
				balls[0]++;
				break;
			case 5:
				fives[0]++;
				balls[0]++;
				break;
			case 6:
				sixes[0]++;
				balls[0]++;
				break;
			case 7:
				wickets[0]++;
				balls[0]++;
				break;
			case 8:
				nb[0]++;
				break;
			case 9:
				w[0]++;
				break;
			case 10:
				lb[0]++;
				balls[0]++;
				break;
			default:
				cout<<"\n Invalid Choice ";
				break;
		}
		//calculating runs
		runs[0] = singles[0] + (doubles[0]*2) + (threes[0]*3) + (fours[0]*4) + (fives[0]*5) + (sixes[0]*6);
		extras[0] = nb[0] + w[0] + lb[0];
		//adding total runs
		total_runs[0] = runs[0] + extras[0];
		//checking for teams wickets
		if(wickets[0] == 10)
			break;
	}
	//end of first innings
	cout<<"\n So This is an end to our first innings ";
	cout<<"\n And the scoreboard is as follows : ";
	cout<<"\n Batting Team : "<<batfirst;
	cout<<"\n Total runs : "<<runs[0];
	cout<<"\n Extras : "<<extras[0];
	cout<<"\n Boundaries : "<<fours[0]<<" fours & "<<sixes[0]<<" sixes ";
	cout<<"\n Wickets : "<<wickets[0];
	cout<<"\n Would you like to go for individual runs breakup ?? (0->no & 1->yes)";
	cin>>ind_rb;
	if(ind_rb == 1)
	{
		cout<<"\n Singles : "<<singles[0];
		cout<<"\n Doubles : "<<(doubles[0]*2);
		cout<<"\n Threes : "<<(threes[0]*3);
		cout<<"\n Fours : "<<(fours[0]*4);
		cout<<"\n Fives : "<<(fives[0]*5);
		cout<<"\n Sixes : "<<(sixes[0]*6);
		cout<<"\n No-Balls : "<<nb[0];
		cout<<"\n Wides : "<<w[0];
		cout<<"\n Leg Byes : "<<lb[0];
	}
	//start of second innings
	cout<<"\n Welcome back guys to the 2nd innings of this match. \n The target has been and if "<<batsecond<<" wants to win this match they need to score "<<(runs[0]+1)<<" in their quota of 120 balls.";
	//taking input for each ball in second innings
	for(int i=0; i<120; i++)
	{
		cin>>input;
		switch(input)
		{
			case 0:
				dots[1]++;
				balls[1]++;
				break;
			case 1:
				singles[1]++;
				balls[1]++;
				break;
			case 2:
				doubles[1]++;
				balls[1]++;
				break;
			case 3:
				threes[1]++;
				balls[1]++;
				break;
			case 4:
				fours[1]++;
				balls[1]++;
				break;
			case 5:
				fives[1]++;
				balls[1]++;
				break;
			case 6:
				sixes[1]++;
				balls[1]++;
				break;
			case 7:
				wickets[1]++;
				balls[1]++;
				break;
			case 8:
				nb[1]++;
				break;
			case 9:
				w[1]++;
				break;
			case 11:
				lb[1]++;
				balls[1]++;
				break;
			default:
				cout<<"\n Invalid Choice ";
				break;
		}
		//calculating runs
		runs[1] = singles[1] + (doubles[1]*2) + (threes[1]*3) + (fours[1]*4) + (fives[1]*5) + (sixes[1]*6);
		extras[1] = nb[1] + w[1] + lb[1];
		//adding up total runs
		total_runs[1] = runs[1] + extras[1];
		//checking if team hasa surpassed the target
		if(runs[0] < runs[1])
			break;
		//checking for teams wickets
		if(wickets[1] == 10)
			break;
	}
	//end of second innings
	cout<<"\n So This is an end to our second innings ";
	cout<<"\n And the scoreboard is as follows : ";
	cout<<"\n Batting Team : "<<batsecond;
	cout<<"\n Total runs : "<<runs[1];
	cout<<"\n Extras : "<<extras[1];
	cout<<"\n Boundaries : "<<fours[1]<<" fours & "<<sixes[1]<<" sixes ";
	cout<<"\n Wickets : "<<wickets[1];
	cout<<"\n Would you like to go for individual runs breakup ?? (0->no & 1->yes)";
	cin>>ind_rb;
	if(ind_rb == 1)
	{
		cout<<"\n Singles : "<<singles[1];
		cout<<"\n Doubles : "<<(doubles[1]*2);
		cout<<"\n Threes : "<<(threes[1]*3);
		cout<<"\n Fours : "<<(fours[1]*4);
		cout<<"\n Fives : "<<(fives[1]*5);
		cout<<"\n Sixes : "<<(sixes[1]*6);
		cout<<"\n No-Balls : "<<nb[1];
		cout<<"\n Wides : "<<w[1];
		cout<<"\n Leg Byes : "<<lb[0];
	}
	//checking result
	if(runs[0] > runs[1])
	{
		cout<<"\n Team "<<batfirst<<" win by "<<(runs[0]-runs[1])<<" runs.";
	}
	else if(runs[0] < runs[1])
	{
		cout<<"\n Team "<<batsecond<<" win by "<<(10-wickets[1])<<" wickets.";
	}
	else
	{
		cout<<"\n So this is a TIE !!!! ";
		cout<<"\n The winning team will be decided on the boundary count ";
		cout<<"\n Team "<<batfirst<<" has scored "<<fours[0]<<" fours and "<<sixes[0]<<" sixes ";
		cout<<"\n So the boundary count is "<<(fours[0]+sixes[0]);
		cout<<"\n Team "<<batsecond<<" has scored "<<fours[1]<<" fours and "<<sixes[1]<<" sixes ";
		cout<<"\n So the boundary count is "<<(fours[1]+sixes[1]);
		if((fours[0]+sixes[0]) > (fours[1]+sixes[1]))
			cout<<"\n Team "<<batfirst<<" win ";
		else if((fours[0]+sixes[0]) < (fours[1]+sixes[1]))
			cout<<"\n Team "<<batsecond<<" win ";
		else
			cout<<"\n STILL A TIE !!!! ";
	}
	cout<<"\n Thanks a lot for using our scorecard services in this match. ";
	cout<<"\n Hope you enjoyed a lot !!!!!!! ";
}
