#include "fun.h"

//存储商品的数量，随时维护
int n = 3;

//存储销售额
float Sales = 0;

struct goods goods[64] = {\
	{1, "苹果", 10, 2.5},\
	{2, "香蕉", 20, 3.5},\
	{3, "橘子", 4, 5},\
};
//商家模块{{{
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
		//printf("list\n");
		list_goods();
		goto MENU_MERCHANT;
	}
	else if (m == modify)
	{
		//printf("modify\n");
		modify_goods();
		goto MENU_MERCHANT;
	}
	else if (m == purchase)
	{
		//printf("purchase\n");
		purchase_goods();
		goto MENU_MERCHANT;
	}
	else if (m == sales)
	{
		printf("sales is %.2f\n", Sales);
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

}/*}}}*/
//顾客模块{{{
void menu_customer(){
	int c;
MENU_CUSTOMER:
	printf("|******************************|\n");
	printf("|*        1.商品列表          *|\n");
	printf("|*        2.购物车            *|\n");
	printf("|*        3.退出              *|\n");
	printf("|******************************|\n");
	scanf("%d", &c);
	if (c == list){
		//printf("list\n");
		list_goods();
		goto MENU_CUSTOMER;
	} else if (c == shopping_cart){
		//printf("shopping_cart\n");
		shopping_goods();
		goto MENU_CUSTOMER;
	} else if (c == quit1){

	} else {
		printf("your input error\n");
		goto MENU_CUSTOMER;
	}


}/*}}}*/
//列举出商品信息{{{
void list_goods(){
	int i;
	printf("num\tname\tquantity\tprice\n");
	for (i = 0; i < n; i++){
		printf("%d\t%s\t%d\t\t%.2f\n",\
				goods[i].num, goods[i].name, goods[i].quantity, goods[i].price); 
	}
}/*}}}*/
//修改商品信息实现{{{
void modify_goods(){
	int quantity;
	float price;
	int num;

	list_goods();
	printf("please input goods's num:");
	scanf("%d", &num);
	for (int i = 0; i < n; i++){
		if (goods[i].num == num){
			printf("please input goods's quantity and price:");
			scanf("%d%f", &quantity, &price);
			goods[i].quantity = quantity;
			goods[i].price = price;
			printf("modify goods sucess\n");
		}
	}
}/*}}}*/
//采购订单功能实现{{{
void purchase_goods(){
	char s[16];
	printf("num\tname\tquantity\tprice\n");
	for (int i = 0; i < n; i++){
		if (goods[i].quantity <= 5){
			printf("%d\t%s\t%d\t\t%.2f\n",\
					goods[i].num, goods[i].name, goods[i].quantity, goods[i].price); 
			printf("whether to purchase, please input yes or no:");
			scanf("%s", s);
			if (strncmp(s, "yes", 3) == 0){
				goods[i].quantity += 10;
				printf("purchase goods sucess\n");
			}
		}

	}
}/*}}}*/
//购物车{{{
void shopping_goods(){
	int num, quantity;
	list_goods();
	printf("please input goods's num and quantity, #end\n");
	while(1){
		if (scanf("%d%d", &num, &quantity) == 2){
			for (int i = 0; i < n; i++){
				if (goods[i].num == num){
					Sales += goods[i].price * quantity;
					goods[i].quantity -= quantity;
				}
			}
		} else {
			while(getchar() != '\n');
			break;
		}
	}
}/*}}}*/
