#include <stdio.h>
#include <stdlib.h>

/* input book titles */
int captureBookTitles(char **bookList, int totalBooks) {
    printf("Enter the 9 book titles one to a line");
    
    for (int i = 0; i < totalBooks; i++) {
        bookList[i] = calloc(61, sizeof(char));  /* making space*/
        printf("%d: ", i + 1);
        scanf(" %[^\n]", bookList[i]);  /*scans for next line*/
    }

    return 0;
}

/* to select favorite books */
int selectFavorites(char **favorites, char **bookList, int totalBooks, int favCount) {
    printf("Select the numbers of your favorite books:\n");

    for (int i = 0; i < favCount; i++) {
        int index;
        printf("Favorite %d: ", i + 1);
        scanf("%d", &index);
        favorites[i] = bookList[index - 1];  
    }

    return 0;
}

/* to save book lists to a file */
char *saveBookListsToFile(char **bookList, char **favorites, int totalBooks, int favCount) {
    int choice;
    printf("Would you like to save these lists to a file? (1=yes, 2=no): ");
    scanf("%d", &choice);
    
    if (choice == 2) {
        return NULL;
    }
    
    char *filename = calloc(61, sizeof(char));
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "w");
    
    fputs("List of Books:\n", file);
    for (int i = 0; i < totalBooks; i++) {
        fputs(bookList[i], file);
        fputs("\n", file);
    }

    fputs("\nFavorite Books:\n", file);
    for (int i = 0; i < favCount; i++) {
        fputs(favorites[i], file);
        fputs("\n", file);
    }

    fclose(file);
    return filename;
}

int main() {
    int totalBooks, favCount;
    
    printf("How many book titles would you like to enter? ");
    scanf("%d", &totalBooks);
    
    /*memory for booklist*/
    char **bookList = malloc(totalBooks * sizeof(char *));
    captureBookTitles(bookList, totalBooks);
    

    printf("\nBooks you've entered:\n"); /*displays entered books*/
    for (int i = 0; i < totalBooks; i++) {
        printf("%d. %s\n", i + 1, bookList[i]);
    }
    
    printf("\nHow many books are your favorites? ");
    scanf("%d", &favCount);/*read favorite books*/
    char **favorites = malloc(favCount * sizeof(char *)); /*memory for favorite books*/
    
    selectFavorites(favorites, bookList, totalBooks, favCount); /*select favorite books*/
    
    /*show favorite books*/
    printf("\nYour favorite books:\n");
    for (int i = 0; i < favCount; i++) {
        printf("%d. %s\n", i + 1, favorites[i]);
    }
    
    char *filename = saveBookListsToFile(bookList, favorites, totalBooks, favCount);
    if (filename) {
        printf("Your lists have been saved to %s\n", filename);
        free(filename); /*free mem for filename*/
    } else {
        printf("You chose not to save the lists.\n");
    }
   /*free up memory*/
    for (int i = 0; i < totalBooks; i++) {
        free(bookList[i]);
    }
    free(bookList);
    free(favorites);

    return 0;
}
