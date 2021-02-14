#include <stdio.h>

int get_int(char text[]);
int get_height();
void print_pyramid(int n);
void print_front(int slot, int total);
void print_back(int slot, int total);
void print_spaces(int slot, int total);

int main(void)
{
  print_pyramid(get_height());
}

int get_height()
{
  int height;

  do
  {
    height = get_int("Height: ");
  }
  while (height > 8 || height < 1);

  return height;

}

int get_int(char text[])
{
  int height;
  printf("%s", text);
  scanf("%i", &height);

  return height;
}

void print_pyramid(int n)
{
  for (int i = 1; i <= n; i++)
  {
    print_front(i, n);
    print_back(i, n);
  }
}

void print_front(int slot, int total)
{
  print_spaces(slot, total);
  for (int i = 0; i < slot; i++)
  {
    printf("#");
  }
  printf("  ");
}

void print_back(int slot, int total)
{
  for (int i = 0; i < slot; i++)
  {
    printf("#");
  }
  print_spaces(slot, total);
  printf("\n");
}

void print_spaces(int slot, int total)
{
  for (int i = slot; i < total; i++)
  {
    printf(" ");
  }
}
