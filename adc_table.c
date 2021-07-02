#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int table_orig[] = {
		3924, /* -35 */
		3865, /* -30 */
		3790, /* -25 */
		3696, /* -20 */
		3585, /* -15 */
		3453, /* -10 */
		3297, /* -5 */
		3121, /* 0 */
		2925, /* 5 */
		2715, /* 10 */
		2496, /* 15 */
		2272, /* 20 */
		2048, /* 25 */
		1825, /* 30 */
		1619, /* 35 */
		1427, /* 40 */
		1251, /* 45 */
		1092, /* 50 */
		950,  /* 55 */
		824,  /* 60 */
		715,  /* 65 */
		619,  /* 70 */
		537,  /* 75 */
		466,  /* 80 */
		404,  /* 85 */
		351,  /* 90 */
		306,  /* 95 */
		267,  /* 100 */
		234,  /* 105 */
		204   /* 110 */
};

#define	TABLE_VAL_INVALID	(0xFFFFFFFF)

int adc_table[4095] = {TABLE_VAL_INVALID};

static int thread()
{
    printf("Hello sizeof = \n", sizeof(int));
}

static int add_mid(int mul, int with_break)
{
	int rv = 0;
	size_t n_e1 = 0, n_e2 = 0, mid = 0;

	n_e1 = 68;
	for (int i = 68; i <= 4050; i++)
	{
		if (TABLE_VAL_INVALID != adc_table[i])
		{
			if ((mul - 1) < (i - n_e1)) // between elements must exist available space
			{
				n_e2 = i;

				printf("check by mul %i %i and %i: %i\n", mul, n_e1, n_e2, (n_e2 - n_e1) % mul);
				if (0 == ((n_e2 - n_e1) % mul))
				{
					mid = n_e1 + ((n_e2 - n_e1) / mul);
					if (TABLE_VAL_INVALID == adc_table[mid])
					{
						printf("FOUND! (%i): between adc_table[%i] = %i and adc_table[%i] = %i ",
								mul, n_e1, adc_table[n_e1], n_e2, adc_table[n_e2]);

						adc_table[mid] = (adc_table[n_e1] - ((adc_table[n_e1] - adc_table[n_e2]) / mul));

						printf("insert adc_table[%i] = %i \n", mid, adc_table[mid]);

						rv = 1;

						if (1 == with_break)
						{
							break;
						}
					}
				}
			}

			n_e1 = i;
		}
	}

	return rv;
}

void create_table(void)
{
	size_t w_dog = 0, ins_flag = 1;

	memset(adc_table, TABLE_VAL_INVALID, sizeof(adc_table));

	int simple[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101,
			103,	107,	109,	113,	127,	131,	137,	139,	149,	151,	157,	163,	167,	173,
			179,	181,	191,	193,	197,	199,	211,	223,	227,	229,	233,	239,	241,	251,	257,
			263,	269,	271,	277,	281
	};

	for (int i = 4051; i < 4095; i++)
	{
		adc_table[i] = -5500;
	}
	adc_table[4050] = -5500;
	adc_table[4031] = -5000;
	adc_table[4005] = -4500;
	adc_table[3970] = -4000;
	adc_table[3924] = -3500;
	adc_table[3865] = -3000;
	adc_table[3790] = -2500;
	adc_table[3696] = -2000;
	adc_table[3585] = -1500;
	adc_table[3453] = -1000;
	adc_table[3297] = -500;
	adc_table[3121] = 0;
	adc_table[2925] = 500;
	adc_table[2715] = 1000;
	adc_table[2496] = 1500;
	adc_table[2272] = 2000;
	adc_table[2048] = 2500;
	adc_table[1825] = 3000;
	adc_table[1619] = 3500;
	adc_table[1427] = 4000;
	adc_table[1251] = 4500;
	adc_table[1092] = 5000;
	adc_table[950] = 5500;
	adc_table[824] = 6000;
	adc_table[715] = 6500;
	adc_table[619] = 7000;
	adc_table[537] = 7500;
	adc_table[466] = 8000;
	adc_table[404] = 8500;
	adc_table[351] = 9000;
	adc_table[306] = 9500;
	adc_table[267] = 10000;
	adc_table[234] = 10500;
	adc_table[204] = 11000;
	adc_table[179] = 11500;
	adc_table[157] = 12000;
	adc_table[139] = 12500;
	adc_table[123] = 13000;
	adc_table[108] = 13500;
	adc_table[96] = 14000;
	adc_table[85] = 14500;
	adc_table[76] = 15000;
	adc_table[68] = 15500;


	for (int i = 0; i < 68; i++)
	{
		adc_table[i] = 15500;
	}

	while (memchr(adc_table, TABLE_VAL_INVALID, sizeof(adc_table)))
	{
		if (0 == ins_flag)
		{
			for (int i = 68; i <= 4050; i++)
			{
				if (TABLE_VAL_INVALID != adc_table[i])
				{
					printf("adc_table[%i] = %i; \n", i, adc_table[i]);
				}
			}

			printf("ins_flag!!!!! Not inserted index:\n");

			int newLine = 0;
			for (int i = 68; i <= 4050; i++)
			{
				if (TABLE_VAL_INVALID == adc_table[i])
				{
					newLine++;
					printf("%i, ", i);
					if (0 == (newLine % 10))
					{
						printf("\n");
					}
				}
			}

			break;

		}

		ins_flag = add_mid(2, 0);

		for (int i = 0; i < sizeof(simple)/sizeof(simple[0]); i++)
		{
			if (1 == add_mid(simple[i], 1))
			{
				ins_flag = 1;
				break;
			}
		}
	}
}

void main(int argc, char * argv[])
{
	create_table();

	return;
}
