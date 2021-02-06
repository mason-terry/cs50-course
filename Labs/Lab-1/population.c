#include <stdio.h>

int updatePopulation(int start, int end, int years);

int main(void)
{
  int start;
  do
  {
    printf("Start size: ");
    scanf("%i", &start);
  }
  while (start < 9);

  int end;
  do
  {
    printf("End size: ");
    scanf("%i", &end);
  }
  while (end < start);
  
  int years = updatePopulation(start, end, 0);
  
  printf("Years: %i\n", years);
}

int updatePopulation(int start, int end, int years)
{
  if (end <= start)
  {
    return years;
  }
  else
  {
    int new_start = (start / 3) + start - (start / 4);
    years++;
    return updatePopulation(new_start, end, years);
  }
}
