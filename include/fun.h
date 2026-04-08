#ifndef _FUN_H_
#define _FUN_H_
#include <stdio.h>
#include <string.h>

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
//顾客的数据类型
enum 
{
	shopping_cart = 2,
	quit1,
};

//商品的数据类型
struct goods{
	int num;
	char name[64];
	int quantity;
	float price;
};

void menu_merchant();
void menu_customer();
void list_goods();
void modify_goods();
void purchase_goods();
void shopping_goods();
#endif
