#include <stdio.h>

int 
main()
{
	int		num = 0;
	int		one       , two, three, four, five;
	//分别代表个位?63?十位?63?百位?63?千位?63?万位
	printf("please input a number within 5 bits:\n");
	scanf("%d", &num);
	printf("num is %d\n", num);
	if (num <= 99999 && num >= 0) {
                one = num % 10;
		if (num >= 10000) {
                        five = num / 10000;
                        four = num / 1000 % 10;
                        three = num / 100 % 10;
                        two = num / 10 % 10;
                        printf("answer is %d%d%d%d%d\n",one,two,three,four,five);
		}
	} else {
		printf("wrong num!\n");
	}
}
