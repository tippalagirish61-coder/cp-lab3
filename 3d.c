#include <stdio.h>
struct Item {
   char code[10];
   char description[30];
   int stock;
};
void updateStock(struct Item items[], int size) {
   for (int i = 0; i < size; i++) {
       items[i].stock += 5; // Increase stock by 5
   }
}
int main() {
   struct Item inventory[2] = {
       {"A101", "Widget", 10},
       {"B202", "Gadget", 20}
   };
   updateStock(inventory, 2);
   for (int i = 0; i < 2; i++) {
       printf("%s - %s: %d\n", inventory[i].code, inventory[i].description, inventory[i].stock);
   }
   return 0;
}