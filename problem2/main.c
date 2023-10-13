#include <stdio.h>

int main(int argc, char *argv[])
{
  while (1) {
    int goal;
    scanf("%d", &goal);

    if (goal < 2) {
      break;
    }

    int td_2 = 8;
    int td_fg = 7;
    int td = 6;
    int fg = 3;
    int sf = 2;

    int max_td_2 = goal / td_2;
    for (int i = 0; i <= max_td_2; i++) {
      int remaining = goal - i * td_2;
      int max_td_fg = remaining / td_fg;

      for (int j = 0; j <= max_td_fg; j++) {
        int remaining2 = remaining - j * td_fg;
        int max_td = remaining2 / td;

        for (int k = 0; k <= max_td; k++) {
          int remaining3 = remaining2 - k * td;
          int max_fg = remaining3 / fg;


          for (int l = 0; l <= max_fg; l++) {
            int remaining4 = remaining3 - l * fg;
            int max_sf = remaining4 / sf;
            int remaining5 = remaining4 - max_sf * sf;

            if (remaining5 == 0) {
              printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", i, j, k, l, max_sf);
            }
          }
        }
      }
    }
  }

  return 0;
}
