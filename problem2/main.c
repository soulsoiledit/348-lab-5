#include <stdio.h>

int main(int argc, char *argv[])
{
  while (1) {
    int goal;
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &goal);

    if (goal < 2) {
      break;
    }

    int td_2 = 8;
    int td_fg = 7;
    int td = 6;
    int fg = 3;
    int sf = 2;
    printf("possible combinations of scoring plays:\n");
    for (int td_2 = 0; td_2 <= goal; td_2 += 8) {
      int goal2 = goal - td_2;
      for (int td_fg = 0; td_fg <= goal2; td_fg += 7) {
        int goal3 = goal2 - td_fg;
        for (int td = 0; td <= goal3; td += 6) {
          int goal4 = goal3 - td;
          for (int fg = 0; fg <= goal4; fg += 3) {
            int sf = (goal4 - fg) / 2;
            if (td_2 + td_fg + td + fg + sf * 2 == goal) {
              printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2/8, td_fg/7, td/6, fg/3, sf);
            }
          }
        }
      }
    }
  }

  return 0;
}
