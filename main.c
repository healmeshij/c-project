#include <stdio.h>

//角色的数据类型
enum{
	merchant = 1,
	customer,
	//}role;
	};
int main(int argc, const char *argv[]){
	int role;
	while (1){
		printf("|******************************|\n");
		printf("|*     1.商家       2.顾客    *|\n");
		printf("|******************************|\n");
		scanf("%d", &role);
		if (role == merchant){
			printf("it is merchant\n");
		}
		else if (role == customer){
			printf("it is customer\n");
		}
		else {
			printf("your input error\n");
		}
	}
	return 0;
}
