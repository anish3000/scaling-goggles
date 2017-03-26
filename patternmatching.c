#include<stdio.h>
#include<string.h>
#define numberofcharecters 256
 
int getNextState(char *pat, int L, int state, int x)
{
  // If c is same as next character in pattern,
  // then increase
  if (state < L && x == pat[state])
  return state+1;
 
  int nextstate, i; // nextstate stores the result which is next state
 
  // nextstate finally containextstate the longest prefix which is also suffix
  
  // Start from the largest value and stop when you find something with is trailing and also following

  for (nextstate = state; nextstate > 0; nextstate--)
  {
  if(pat[nextstate-1] == x)
  {
  for(i = 0; i < nextstate-1; i++)
  {
  if (pat[i] != pat[state-nextstate+1+i])
  break;
  }
  if (i == nextstate-1)
  return nextstate;
  }
  }
 
  return 0;
}
 
/* This function populates the TF table which represents Finite Automata for a
  given pattern */
void findTF(char *pat, int L, int TF[][numberofcharecters])
{
  int state, x;
  for (state = 0; state <= L; ++state)
  for (x = 0; x < numberofcharecters; ++x)
  TF[state][x] = getNextState(pat, L, state, x);
}
 
/* Prints all occurrences of the pattern in txt */
void search(char *pat, char *txt)
{
  int L = strlen(pat);
  int N = strlen(txt);
 
  int TF[L+1][numberofcharecters];
 
  findTF(pat, L, TF);
 
  int i, state=0;
  for (i = 0; i < N; i++)
  {
  state = TF[state][txt[i]];
  if (state == L)
  {
  printf ("\n match found at index %d", i-L+1);
  }
  }
}
 
// Program to test above function
int main()
{
  char *txt = "AAABACABBAABABA";
  char *pat = "AABA";
  search(pat, txt);
  return 0;
}