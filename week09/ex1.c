#include <stdio.h>
#include <stdlib.h>

typedef struct frame_s
{
    int     r_bit;
    int     a;
    int     counter;
}               frame;

typedef struct replace_s
{
    int counter;
    int index;
    int p_num;
}               replace;

int main(void)
{
    int     n;
    int     m;
    frame   *frames;
    int     timer;
    int     p_num;
    int     t_clk;
    int     found;
    replace tbr;
    int     *b;
    double  r;
    int     f_r;

    timer = 0;
    scanf("%d %d", &n, &m);
    frames = malloc(n * sizeof(frame));
    b = calloc(m, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        frames[i].a = 0;
        frames[i].r_bit = 0;
        frames[i].counter = 0;
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &t_clk, &p_num);
        if (t_clk > timer)
        {
            if (timer != 0)
                for (int j = 0; j < n; j++)
                {
                    if (frames[j].a > 0)
                        frames[j].counter = (frames[j].counter >> 1) | (frames[j].r_bit << 7);
                    frames[j].r_bit = 0;
                }
            timer = t_clk;
        }
        found = 0;
        tbr.counter = 256;
        tbr.p_num = 10001;
        for (int j = 0; j < n; j++)
        {
            if (frames[j].counter < tbr.counter)
            {
                tbr.p_num = frames[j].a;
                tbr.counter = frames[j].counter;
                tbr.index = j;
            } else if (frames[j].counter == tbr.counter) {
                if (frames[j].a < tbr.p_num)
                {
                    tbr.p_num = frames[j].a;
                    tbr.index = j;
                    tbr.counter = frames[j].counter;
                }
            }
            if (frames[j].a == p_num)
            {
                found = 1;
                frames[j].r_bit = 1;
                b[i] = 1;
                break;
            }
        }
        if (found == 0)
        {
            frames[tbr.index].a = p_num;
            frames[tbr.index].counter = 0;
            frames[tbr.index].r_bit = 1;
        }
    }

    f_r = 0;
    for (int i = 0; i < m; i++)
    {
        f_r += b[i];
        printf("%d\n", b[i]);
    }
    r = (double) f_r/ (double) (m - f_r);
    printf("%f\n", r);

    return (0);
}
