#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct FoodItem{
    char name[99];
    char category[99];
    int calories;
    int protein;
    int carbs;
    int sugar;
};
/*
struct FoodItem list[] = {
    {"Apple", "Fruit", 52, 0.3, 14, 10},
    {"Banana", "Fruit", 89, 1.1, 23, 12},
    {"Orange", "Fruit", 47, 0.9, 12, 9},
    {"Strawberry", "Fruit", 33, 0.7, 8, 4.9},
    {"Blueberry", "Fruit", 57, 0.7, 14, 10},
    {"Grapes", "Fruit", 69, 0.7, 18, 16},
    {"Pineapple", "Fruit", 50, 0.5, 13, 10},
    {"Mango", "Fruit", 60, 0.8, 15, 14},
    {"Watermelon", "Fruit", 30, 0.6, 8, 6},
    {"Kiwi", "Fruit", 61, 1.1, 15, 9},
    
    {"Broccoli", "Vegetable", 55, 3.7, 11, 2.2},
    {"Spinach", "Vegetable", 23, 2.9, 4, 0.4},
    {"Carrot", "Vegetable", 41, 0.9, 10, 4.7},
    {"Tomato", "Vegetable", 18, 0.9, 3.9, 2.6},
    {"Cucumber", "Vegetable", 16, 0.7, 3.6, 1.7},
    {"Bell Pepper", "Vegetable", 31, 1.0, 6, 4.2},
    {"Cauliflower", "Vegetable", 25, 1.9, 5, 1.9},
    {"Onion", "Vegetable", 40, 1.1, 9, 4.2},
    {"Garlic", "Vegetable", 149, 6.4, 33, 1.0},
    {"Potato", "Vegetable", 77, 2.0, 17, 0.8},
    
    {"Chicken Breast", "Meat", 165, 31, 0, 0},
    {"Salmon", "Fish", 208, 20, 0, 0},
    {"Egg", "Protein", 155, 13, 1, 1},
    {"Turkey", "Meat", 189, 29, 0, 0},
    {"Beef", "Meat", 250, 26, 0, 0},
    {"Tuna", "Fish", 132, 28, 0, 0},
    {"Shrimp", "Seafood", 99, 24, 0.2, 0.2},
    {"Cod", "Fish", 82, 18, 0, 0},
    {"Mackerel", "Fish", 205, 19, 13, 0},
    {"Lamb", "Meat", 294, 25, 21, 0},
    
    {"Almonds", "Nuts", 576, 21, 22, 4},
    {"Peanuts", "Nuts", 567, 25, 16, 4},
    {"Cashews", "Nuts", 553, 18, 30, 5},
    {"Walnuts", "Nuts", 654, 15, 14, 2.6},
    {"Oats", "Grain", 389, 17, 66, 1},
    {"Rice (White)", "Grain", 130, 2.7, 28, 0},
    {"Rice (Brown)", "Grain", 123, 2.6, 25.6, 0.5},
    {"Quinoa", "Grain", 120, 4.4, 21.3, 0.9},
    {"Bread (Whole Wheat)", "Grain", 247, 13, 41, 5},
    {"Pasta", "Grain", 131, 5, 25, 1.1},
    
    {"Milk (Whole)", "Dairy", 61, 3.1, 5, 5},
    {"Cheddar Cheese", "Dairy", 403, 25, 1, 0.5},
    {"Yogurt (Plain)", "Dairy", 59, 10, 4, 3},
    {"Cottage Cheese", "Dairy", 98, 11, 3, 2},
    {"Butter", "Dairy", 717, 0.9, 0, 0.1},
    {"Olive Oil", "Fat", 884, 0, 0, 0},
    {"Peanut Butter", "Spread", 588, 25, 20, 9},
    {"Honey", "Spread", 304, 0.3, 82, 82},
    {"Jam", "Spread", 250, 0.4, 60, 50},
    {"Maple Syrup", "Spread", 260, 0, 67, 60}
}; */


//Name, Calories, Carbs, Fat, Sugar, Fiber, Protein
struct FoodNode{
    char name[100];
    int calories;
    float carbs;
    float fats;
    float sugar;
    float fiber;
    float protein;

    struct FoodNode* left;
    struct FoodNode* right;
};

struct FoodNode* create(const char* name, int calories, float carbs, float fats, float sugar, float fiber, float protein){
    struct FoodNode* temp =  (struct FoodNode*)malloc(sizeof(struct FoodNode));
    if(temp==NULL){
        printf("Faced an error while allocating memory!\n");
        return NULL;
    }
    //intitializing all the fields
    strncpy(temp->name, name, sizeof(temp->name)-1);
    temp->name[sizeof(temp->name)-1]='\0';
    
    temp->calories = calories;
    temp->carbs = carbs;
    temp->fats = fats;
    temp->sugar = sugar;
    temp->fiber = fiber;
    temp->protein = protein;
    
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct FoodNode* insertNode(struct FoodNode* root, struct FoodNode* temp){
    if(root==NULL){
        return temp;
    }
    if(temp->calories < root->calories){
        root->left = insertNode(root->left, temp);
    }
    else{
        root->right = insertNode(root->right, temp);
    }
    return root;
}

void displayNode(struct FoodNode* root){
    if(root == NULL){
        return;
    }
    printf("\nName: %s\n", root->name);
    printf("Calories: %d kcal\n", root->calories);
    printf("Carbs: %.1fg\n", root->carbs);
    printf("Fat: %.1fg\n", root->fats);
    printf("Protein: %.1fg\n", root->protein);
    printf("Sugar: %.1fg\n", root->sugar);
    printf("Fiber: %.1fg\n", root->fiber);
}

void inorderDisplay(struct FoodNode* root){
    if(root==NULL) return;
    inorderDisplay(root->left);
    displayNode(root);
    inorderDisplay(root->right);
}

void computeTotals(struct FoodNode* root, int *calSum, float *carbsSum, float *fatsSum, float *proteinSum, float *sugarSum, float *fiberSum){
    if(root==NULL) return;
    computeTotals(root->left, calSum, carbsSum, fatsSum, proteinSum, sugarSum, fiberSum);
    *calSum += root->calories;
    *carbsSum += root->carbs;
    *fatsSum += root->fats;
    *proteinSum += root->protein;
    *sugarSum += root->sugar;
    *fiberSum += root->fiber;
    computeTotals(root->right, calSum, carbsSum, fatsSum, proteinSum, sugarSum, fiberSum);
}

void freeTree(struct FoodNode* root){
    if(root==NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}


void fileInput(int totalCalories, float totalCarbs, float totalFats, float totalProtein, float totalSugar, float totalFiber){
    char filePath[]="C:\\Users\\DELL\\Desktop\\DS PBL\\DailyData.txt";
    FILE *file = fopen(filePath, "a+");
    if (file == NULL) {
        printf("Error opening file '%s' for appending\n", filePath);
        return;
    }
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char date[20];
    strftime(date, sizeof(date), "%d-%m-%Y | %H:%M:%S", t);

    fprintf(file, "%s\n", date);
    fprintf(file, "Calorie Intake: %d kcal\n", totalCalories);
    fprintf(file, "Carbohydrates: %.2fg\n", totalCarbs);
    fprintf(file, "Fats: %.2fg\n", totalFats);
    fprintf(file, "Protein: %.2fg\n", totalProtein);
    fprintf(file, "Sugar: %.2fg\n", totalSugar);
    fprintf(file, "Fiber: %.2fg\n", totalFiber);
    fprintf(file, "------------------------\n");
    fclose(file);
    printf("Daily totals appended to %s\n", filePath);
}

static void readLine(char *buf, size_t size){//helpr fxn
    if(fgets(buf, (int)size, stdin)==NULL){
        buf[0]='\0';
        return;
    }
    size_t len = strlen(buf);
    if(len>0 && buf[len-1]=='\n') buf[len-1]='\0';
}

void printNutrientChart(struct FoodNode* food) {
    if (food == NULL) {
        printf("No data available.\n");
        return;
    }
    char *labels[] = {"Calories", "Carbs", "Fats", "Sugar", "Fiber", "Protein"};
    float values[] = {food->calories, food->carbs, food->fats, food->sugar, food->fiber, food->protein};
    int n = 6;

    float maxvalue = values[0];
    for (int i = 1; i < n; i++) {
        if (values[i] > maxvalue)
            maxvalue = values[i];
    }

    printf("\nNUTRIENT CHART FOR: %s \n\n", food->name);

    for (int i = 0; i < n; i++) {
        int barLength = (int)((values[i] / maxvalue) * 50); 
        printf("%-10s | ", labels[i]);

        for (int j = 0; j < barLength; j++)
            printf("=");

        if (i == 0)
            printf(" %.0f kcal\n", values[i]);
        else
            printf(" %.1fg\n", values[i]);
    }
printf("\n");
}


int main(){
    struct FoodNode* root = NULL;
    char input[128];
    while(1){
        printf("\n=== Food Database Menu ===\n");
        printf("1) Add food item\n");
        printf("2) Display all food items (sorted by calories)\n");
        printf("3) Save daily totals to file\n");
        printf("4) Display Chart \n");
        printf("5) Exit\n");
        printf("Choose an option: ");
        readLine(input, sizeof(input));
        if(strcmp(input, "1")==0){
            char name[100];
            int calories = 0;
            float carbs=0, fats=0, sugar=0, fiber=0, protein=0;
            printf("Enter food name: ");
            readLine(name, sizeof(name));
            while(1){
                printf("Calories (kcal): ");
                readLine(input, sizeof(input));
                if(sscanf(input, "%d", &calories)==1) break;
                printf("Invalid number, try again.\n");
            }
            while(1){
                printf("Carbs (g): ");
                readLine(input, sizeof(input));
                if(sscanf(input, "%f", &carbs)==1) break;
                printf("Invalid number, try again.\n");
            }
            while(1){
                printf("Fats (g): ");
                readLine(input, sizeof(input));
                if(sscanf(input, "%f", &fats)==1) break;
                printf("Invalid number, try again.\n");
            }
            while(1){
                printf("Protein (g): ");
                readLine(input, sizeof(input));
                if(sscanf(input, "%f", &protein)==1) break;
                printf("Invalid number, try again.\n");
            }
            while(1){
                printf("Sugar (g): ");
                readLine(input, sizeof(input));
                if(sscanf(input, "%f", &sugar)==1) break;
                printf("Invalid number, try again.\n");
            }
            while(1){
                printf("Fiber (g): ");
                readLine(input, sizeof(input));
                if(sscanf(input, "%f", &fiber)==1) break;
                printf("Invalid number, try again.\n");
            }
            struct FoodNode* node = create(name, calories, carbs, fats, sugar, fiber, protein);
            if(node!=NULL) root = insertNode(root, node);
            printf("Food item added.\n");
        } else if(strcmp(input, "2")==0){
            if(root==NULL){
                printf("No food items to display.\n");
            } else {
                printf("\n-- Food items (inorder by calories) --\n");
                inorderDisplay(root);
            }
        } else if(strcmp(input, "3")==0){
            int totalCal=0; float totalCarbs=0, totalFats=0, totalProtein=0, totalSugar=0, totalFiber=0;
            computeTotals(root, &totalCal, &totalCarbs, &totalFats, &totalProtein, &totalSugar, &totalFiber);
            fileInput(totalCal, totalCarbs, totalFats, totalProtein, totalSugar, totalFiber);
        } 
        
        else if(strcmp(input, "4")==0){
            printNutrientChart(root);
        } else if(strcmp(input, "5")==0){
            break;
        } else {
            printf("Invalid option, try again.\n");
        }
    }
    freeTree(root);
    printf("Exiting. Goodbye!\n");
    return 0;
}