#include <stdio.h>

//角色的数据类型
enum{
	merchant = 1,
	customer,
	//}role;
	};

//商家数据类型
enum{
	list = 1,
	modify,
	purchase,
	sales,
	quit,
};

void menu_merchant();
int main(int argc, const char *argv[]){/*{{{*/
	int role;
	while (1){
		printf("|******************************|\n");
		printf("|*     1.商家       2.顾客    *|\n");
		printf("|******************************|\n");
		scanf("%d", &role);
		if (role == merchant){
			printf("it is merchant\n");
			menu_merchant();
		}
		else if (role == customer){
			printf("it is customer\n");
		}
		else {
			printf("your input error\n");
		}
	}
	return 0;
}/*}}}*/
void menu_merchant(){
	int m;
MENU_MERCHANT:
	printf("|******************************|\n");
	printf("|*        1.查看库存          *|\n");
	printf("|*        2.修改商品          *|\n");
	printf("|*        3.采购订单          *|\n");
	printf("|*        4.查看销售额        *|\n");
	printf("|*        5.退出              *|\n");
	printf("|******************************|\n");
	scanf("%d", &m);
	if (m == list){
		printf("list\n");
		goto MENU_MERCHANT;
	}
	else if (m == modify)
	{
		printf("modify\n");
		goto MENU_MERCHANT;
	}
	else if (m == purchase)
	{
		printf("purchase\n");
		goto MENU_MERCHANT;
	}
	else if (m == sales)
	{
		printf("sales\n");
		goto MENU_MERCHANT;
	}
	else if (m == quit)
	{
	}
	else 
	{
		printf("your input error\n");
		goto MENU_MERCHANT;
	}

}
