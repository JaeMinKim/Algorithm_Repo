#include <stdio.h>
#include <string.h>

#define KG_TO_LB  2.2046
#define LB_TO_KG  0.4536
#define L_TO_G    0.2642
#define G_TO_L    3.7854

#define KG_MEASURE "kg"
#define LB_MEASURE "lb"
#define L_MEASURE  "l"
#define G_MEASURE  "g"

void convert(double val, char* measure)
{
	if ( strcmp(measure, KG_MEASURE) == 0 )
		printf("%.4lf %s\n", val * KG_TO_LB, LB_MEASURE);
	else if ( strcmp(measure, LB_MEASURE) == 0 )
		printf("%.4lf %s\n", val * LB_TO_KG, KG_MEASURE);
	else if ( strcmp(measure, L_MEASURE) == 0 )
		printf("%.4lf %s\n", val * L_TO_G, G_MEASURE);
	else if ( strcmp(measure, G_MEASURE) == 0 )
		printf("%.4lf %s\n", val * G_TO_L, L_MEASURE);
}

int main()
{
	int cnt = 0;
	int i = 0;
	double val;
	char measure[3] = {'\0', };

	scanf("%d", &cnt);

	for (i=0; i<cnt; i++)
	{
		scanf("%lf %s", &val, measure);

		printf("%d ", i + 1);
		convert(val, measure);
	}
}
