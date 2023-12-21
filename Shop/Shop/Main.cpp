#include "Shop.h"

int main() {
	Shop shop;
	for(int i = 0; i < 5; i++)
		shop.push(Computer(1999.99, "Asus ROG Strix", "intel i7", "RTX 3060", "Be-quite 600w", "Adata 16gb"));
	try { shop.save("shop.txt"); }
	catch (exception ex) { cout << ex.what() << endl; }
	shop.DeleteAll();
	try { shop.load("shop.txt"); }
	catch (exception ex) { cout << ex.what() << endl; }
	shop.print();
}